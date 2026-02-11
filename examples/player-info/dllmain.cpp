#include <atomic>
#include <cstdint>
#include <windows.h>

#include <eldenring/position.hpp>

#include "example_util.h"
#include "pattern_scan.h"

namespace {

struct Addresses {
  uintptr_t world_ptr_addr = 0;
  uintptr_t player_ptr_addr = 0;
};

constexpr uint32_t kActorCtrlOffset = 0x190;
constexpr uint32_t kActorCtrlTransformOffset = 0x68;
constexpr uint32_t kPosXOffset = 0x70;
constexpr uint32_t kPosYOffset = 0x74;
constexpr uint32_t kPosZOffset = 0x78;
constexpr uint32_t kTeamOffset = 0x6C;
constexpr uint32_t kWorldChrManMainPlayerOffset = 0x1E508;

const uint8_t kSigWorldPtr[] = {0x48, 0x8B, 0x05, 0x00, 0x00, 0x00, 0x00, 0x48, 0x85, 0xC0,
                                0x74, 0x00, 0x48, 0x39, 0x88, 0x00, 0x00, 0x00, 0x00, 0x75,
                                0x00, 0x89, 0xB1, 0x6C, 0x03, 0x00, 0x00, 0x0F, 0x28, 0x05,
                                0x00, 0x00, 0x00, 0x00, 0x4C, 0x8D, 0x45, 0xE7};
const char kMaskWorldPtr[] = "xxx????xxxx?xxx????x?xxxxxxxxx????xxxx";

const uint8_t kSigPlayerPtr[] = {0x48, 0x8B, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x89,
                                 0x5C, 0x24, 0x20, 0x48, 0x85, 0xC9, 0x74, 0x12,
                                 0xB8, 0x00, 0x00, 0x00, 0x00, 0x8B, 0xD8};
const char kMaskPlayerPtr[] = "xxx????xxxxxxxxxx????xx";

std::atomic<bool> g_stop{false};
Addresses g_addrs;

bool scan_addresses() {
  auto range = erd_example::get_module_range();
  if (!range.base || !range.size) {
    erd_example::log_line("module range missing");
    return false;
  }

  auto sig_world = pattern_scan::find_pattern(range.base, range.size, kSigWorldPtr, kMaskWorldPtr);
  if (!sig_world) {
    erd_example::log_line("world ptr sig not found");
    return false;
  }
  g_addrs.world_ptr_addr = pattern_scan::resolve_rel32(sig_world);

  auto sig_player =
      pattern_scan::find_pattern(range.base, range.size, kSigPlayerPtr, kMaskPlayerPtr);
  if (!sig_player) {
    erd_example::log_line("player ptr sig not found");
    return false;
  }
  g_addrs.player_ptr_addr = pattern_scan::resolve_rel32(sig_player);

  erd_example::log_line("world ptr addr: 0x%llx",
                        static_cast<unsigned long long>(g_addrs.world_ptr_addr));
  erd_example::log_line("player ptr addr: 0x%llx",
                        static_cast<unsigned long long>(g_addrs.player_ptr_addr));
  return true;
}

uintptr_t get_player_root() {
  if (!g_addrs.player_ptr_addr) {
    return 0;
  }
  return erd_example::read_ptr(g_addrs.player_ptr_addr);
}

uintptr_t get_main_player() {
  if (!g_addrs.world_ptr_addr) {
    return 0;
  }
  uintptr_t world_root = erd_example::read_ptr(g_addrs.world_ptr_addr);
  if (!world_root) {
    return 0;
  }
  return erd_example::read_ptr(world_root + kWorldChrManMainPlayerOffset);
}

bool read_player_position(uintptr_t player_root, eldenring::position::BlockPosition& out) {
  if (!player_root) {
    return false;
  }
  uintptr_t actor_ctrl = erd_example::read_ptr(player_root + kActorCtrlOffset);
  if (!actor_ctrl) {
    return false;
  }
  uintptr_t transform = erd_example::read_ptr(actor_ctrl + kActorCtrlTransformOffset);
  if (!transform) {
    return false;
  }
  out.x = erd_example::read_f32(transform + kPosXOffset);
  out.y = erd_example::read_f32(transform + kPosYOffset);
  out.z = erd_example::read_f32(transform + kPosZOffset);
  out.yaw = 0.0f;
  return true;
}

DWORD WINAPI worker(LPVOID) {
  erd_example::init_log_path("erd_example_player_info.log");
  erd_example::log_line("=== player-info start ===");

  if (!scan_addresses()) {
    erd_example::log_line("pattern scan failed");
    return 0;
  }

  while (!g_stop.load()) {
    if (GetAsyncKeyState(VK_F6) & 1) {
      uintptr_t player_root = get_player_root();
      uintptr_t main_player = get_main_player();

      eldenring::position::BlockPosition pos{};
      bool pos_ok = read_player_position(player_root, pos);

      std::uint8_t team = 0;
      bool team_ok = erd_example::safe_read(player_root + kTeamOffset, team);

      erd_example::log_line("player_root=0x%llx main_player=0x%llx pos=%s (x=%.3f y=%.3f z=%.3f) "
                            "team=%s (%u)",
                            static_cast<unsigned long long>(player_root),
                            static_cast<unsigned long long>(main_player), pos_ok ? "ok" : "fail",
                            pos.x, pos.y, pos.z, team_ok ? "ok" : "fail",
                            static_cast<unsigned>(team));
    }
    Sleep(16);
  }

  erd_example::log_line("=== player-info end ===");
  return 0;
}

} // namespace

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID) {
  if (reason == DLL_PROCESS_ATTACH) {
    DisableThreadLibraryCalls(hModule);
    HANDLE thread = CreateThread(nullptr, 0, worker, nullptr, 0, nullptr);
    if (thread) {
      CloseHandle(thread);
    }
  } else if (reason == DLL_PROCESS_DETACH) {
    g_stop.store(true);
  }
  return TRUE;
}
