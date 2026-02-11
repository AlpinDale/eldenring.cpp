#include <atomic>
#include <cstdint>
#include <windows.h>

#include <eldenring/eldenring.hpp>

#include "example_util.h"
#include "pattern_scan.h"

namespace {

struct Addresses {
  uintptr_t world_ptr_addr = 0;
};

struct RvaBundle {
  uint32_t chr_ins_apply_speffect;
  uint32_t chr_ins_remove_speffect;
};

constexpr RvaBundle kRvaWw261{0x3e8cf0, 0x3ee1b0};
constexpr RvaBundle kRvaJp2611{0x3e8be0, 0x3ee0b0};

constexpr int32_t kSpEffectId = 4330;
constexpr uint32_t kWorldChrManMainPlayerOffset = 0x1E508;

const uint8_t kSigWorldPtr[] = {0x48, 0x8B, 0x05, 0x00, 0x00, 0x00, 0x00, 0x48, 0x85, 0xC0,
                                0x74, 0x00, 0x48, 0x39, 0x88, 0x00, 0x00, 0x00, 0x00, 0x75,
                                0x00, 0x89, 0xB1, 0x6C, 0x03, 0x00, 0x00, 0x0F, 0x28, 0x05,
                                0x00, 0x00, 0x00, 0x00, 0x4C, 0x8D, 0x45, 0xE7};
const char kMaskWorldPtr[] = "xxx????xxxx?xxx????x?xxxxxxxxx????xxxx";

std::atomic<bool> g_stop{false};
Addresses g_addrs;

using ApplySpeffectFn = std::uint64_t (*)(void* chr_ins, std::int32_t speffect, bool dont_sync);
using RemoveSpeffectFn = std::uint64_t (*)(void* chr_ins, std::int32_t speffect);

const RvaBundle* select_rvas() {
  std::string version;
  if (!erd_example::get_file_version(version)) {
    erd_example::log_line("version detect failed");
    return nullptr;
  }

  erd_example::log_line("exe version: %s", version.c_str());
  if (version == "2.6.1.0") {
    return &kRvaWw261;
  }
  if (version == "2.6.1.1") {
    return &kRvaJp2611;
  }

  erd_example::log_line("unsupported version: %s", version.c_str());
  return nullptr;
}

bool scan_addresses() {
  auto range = erd_example::get_module_range();
  if (!range.base || !range.size) {
    erd_example::log_line("module range missing");
    return false;
  }

  auto sig = pattern_scan::find_pattern(range.base, range.size, kSigWorldPtr, kMaskWorldPtr);
  if (!sig) {
    erd_example::log_line("world ptr sig not found");
    return false;
  }

  g_addrs.world_ptr_addr = pattern_scan::resolve_rel32(sig);
  if (!g_addrs.world_ptr_addr) {
    erd_example::log_line("world ptr resolve failed");
    return false;
  }

  erd_example::log_line("world ptr addr: 0x%llx",
                        static_cast<unsigned long long>(g_addrs.world_ptr_addr));
  return true;
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

DWORD WINAPI worker(LPVOID) {
  erd_example::init_log_path("erd_example_apply_speffect.log");
  erd_example::log_line("=== apply-speffect start ===");

  const RvaBundle* rvas = select_rvas();
  if (!rvas) {
    erd_example::log_line("rva selection failed");
    return 0;
  }

  if (!scan_addresses()) {
    erd_example::log_line("pattern scan failed");
    return 0;
  }

  auto base = reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr));
  auto apply_fn = reinterpret_cast<ApplySpeffectFn>(base + rvas->chr_ins_apply_speffect);
  auto remove_fn = reinterpret_cast<RemoveSpeffectFn>(base + rvas->chr_ins_remove_speffect);

  erd_example::log_line("apply fn: 0x%llx remove fn: 0x%llx",
                        static_cast<unsigned long long>(base + rvas->chr_ins_apply_speffect),
                        static_cast<unsigned long long>(base + rvas->chr_ins_remove_speffect));

  while (!g_stop.load()) {
    if (GetAsyncKeyState('O') & 1) {
      uintptr_t player = get_main_player();
      if (player) {
        apply_fn(reinterpret_cast<void*>(player), kSpEffectId, true);
        erd_example::log_line("apply speffect %d to 0x%llx", kSpEffectId,
                              static_cast<unsigned long long>(player));
      } else {
        erd_example::log_line("apply: player missing");
      }
    }

    if (GetAsyncKeyState('P') & 1) {
      uintptr_t player = get_main_player();
      if (player) {
        remove_fn(reinterpret_cast<void*>(player), kSpEffectId);
        erd_example::log_line("remove speffect %d from 0x%llx", kSpEffectId,
                              static_cast<unsigned long long>(player));
      } else {
        erd_example::log_line("remove: player missing");
      }
    }
    Sleep(16);
  }

  erd_example::log_line("=== apply-speffect end ===");
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
