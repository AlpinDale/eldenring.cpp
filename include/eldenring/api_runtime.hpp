#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstdio>
#include <string>
#include <type_traits>

#if defined(_WIN32)
#include <windows.h>
#endif

#ifdef _MSC_VER
#pragma comment(lib, "version.lib")
#endif

namespace eldenring { namespace api { namespace runtime {
inline std::uintptr_t module_base() {
#if defined(_WIN32)
  return reinterpret_cast<std::uintptr_t>(GetModuleHandleA(nullptr));
#else
  return 0;
#endif
}

inline std::uintptr_t rva_to_va_base(std::uint32_t rva) {
  return module_base() + static_cast<std::uintptr_t>(rva);
}

template <typename T>
inline T rva_to_va(std::uint32_t rva) {
  auto va = rva_to_va_base(rva);
  if constexpr (std::is_pointer_v<T>) {
    return reinterpret_cast<T>(va);
  } else {
    return static_cast<T>(va);
  }
}

template <typename Ret, typename... Args>
inline Ret call_rva(std::uint32_t rva, Args... args) {
  auto fn = reinterpret_cast<Ret(*)(Args...)>(rva_to_va_base(rva));
  if constexpr (std::is_void_v<Ret>) {
    fn(args...);
  } else {
    return fn(args...);
  }
}

template <typename T>
inline T load_static_direct(std::uint32_t rva) {
  return rva_to_va<T>(rva);
}

template <typename T>
inline T load_static_indirect(std::uint32_t rva) {
  auto addr = rva_to_va<std::uintptr_t*>(rva);
  if (!addr) {
    return T{};
  }
  return reinterpret_cast<T>(*addr);
}

inline bool get_file_version(std::string& out) {
#if defined(_WIN32)
  char path[MAX_PATH * 4] = {};
  if (GetModuleFileNameA(nullptr, path, static_cast<DWORD>(sizeof(path))) == 0) {
    return false;
  }

  DWORD handle = 0;
  DWORD size = GetFileVersionInfoSizeA(path, &handle);
  if (size == 0) {
    return false;
  }

  std::string data;
  data.resize(size);
  if (!GetFileVersionInfoA(path, handle, size, data.data())) {
    return false;
  }

  VS_FIXEDFILEINFO* info = nullptr;
  UINT info_len = 0;
  if (!VerQueryValueA(data.data(), "\\", reinterpret_cast<void**>(&info), &info_len)) {
    return false;
  }
  if (!info || info_len < sizeof(VS_FIXEDFILEINFO)) {
    return false;
  }

  const DWORD ms = info->dwProductVersionMS;
  const DWORD ls = info->dwProductVersionLS;
  const DWORD major = HIWORD(ms);
  const DWORD minor = LOWORD(ms);
  const DWORD patch = HIWORD(ls);
  const DWORD build = LOWORD(ls);

  char buffer[64] = {};
  std::snprintf(buffer, sizeof(buffer), "%lu.%lu.%lu.%lu",
                static_cast<unsigned long>(major),
                static_cast<unsigned long>(minor),
                static_cast<unsigned long>(patch),
                static_cast<unsigned long>(build));
  out.assign(buffer);
  return true;
#else
  (void)out;
  return false;
#endif
}
}}} // namespace eldenring::api::runtime

namespace eldenring { namespace api { namespace rva {
struct RvaBundle {
  std::uint32_t character_type_properties;
  std::uint32_t chr_cam_vmt;
  std::uint32_t chr_ins_apply_speffect;
  std::uint32_t chr_ins_remove_speffect;
  std::uint32_t chr_ins_vmt;
  std::uint32_t chr_set_vmt;
  std::uint32_t crypto_spi_registry;
  std::uint32_t cs_action_button_man_execute_action_button;
  std::uint32_t cs_bullet_manager_spawn_bullet;
  std::uint32_t cs_ez_draw_draw_capsule;
  std::uint32_t cs_ez_draw_draw_dodecadron;
  std::uint32_t cs_ez_draw_draw_line;
  std::uint32_t cs_ez_draw_draw_sphere;
  std::uint32_t cs_ez_draw_draw_triangle;
  std::uint32_t cs_ez_draw_draw_wedge;
  std::uint32_t cs_ez_state_talk_env_vmt;
  std::uint32_t cs_ez_state_talk_event_vmt;
  std::uint32_t cs_menu_man_imp_display_status_message;
  std::uint32_t cs_phys_world_cast_ray;
  std::uint32_t csbullet_explosion_state_vmt;
  std::uint32_t csbullet_fly_state_vmt;
  std::uint32_t csbullet_nullstate_vmt;
  std::uint32_t csbullet_state_vmt;
  std::uint32_t csbullet_wait_state_vmt;
  std::uint32_t cscam_vmt;
  std::uint32_t cschr_model_ins_vmt;
  std::uint32_t csez_rabbit_no_update_task_vmt;
  std::uint32_t csez_rabbit_task_base_vmt;
  std::uint32_t csez_rabbit_task_vmt;
  std::uint32_t csez_task_proxy_vmt;
  std::uint32_t csez_task_vmt;
  std::uint32_t csfile_repository_vmt;
  std::uint32_t csgaitem_ins_vmt;
  std::uint32_t csgem_gaitem_ins_vmt;
  std::uint32_t csmodel_ins_vmt;
  std::uint32_t csmsb_parts_ene_vmt;
  std::uint32_t csmsb_parts_geom_vmt;
  std::uint32_t csmsb_parts_vmt;
  std::uint32_t cspair_anim_node_vmt;
  std::uint32_t csrand_sfmt_vmt;
  std::uint32_t csrand_vmt;
  std::uint32_t csrand_xorshift_vmt;
  std::uint32_t csride_node_vmt;
  std::uint32_t cstask_base_vmt;
  std::uint32_t cstask_group_ins_vmt;
  std::uint32_t cstask_vmt;
  std::uint32_t csteam_type_base_vmt;
  std::uint32_t csteam_type_enemy_vmt;
  std::uint32_t csteam_type_friend_vmt;
  std::uint32_t csteam_type_neutral_vmt;
  std::uint32_t csteam_type_rival_vmt;
  std::uint32_t csthrow_node_vmt;
  std::uint32_t cstime_line_task_group_ins_vmt;
  std::uint32_t cswep_gaitem_ins_vmt;
  std::uint32_t dlbuffered_input_stream_vmt;
  std::uint32_t dlpseudo_async_input_stream_vmt;
  std::uint32_t enemy_ins_vmt;
  std::uint32_t ez_state_detail_external_event_temp_vmt;
  std::uint32_t ez_state_environment_query_impl_vmt;
  std::uint32_t fd4file_cap_vmt;
  std::uint32_t fd4param_repository_vmt;
  std::uint32_t fd4param_res_cap_vmt;
  std::uint32_t fd4res_cap_vmt;
  std::uint32_t fd4res_rep_vmt;
  std::uint32_t fd4task_base_vmt;
  std::uint32_t game_data_man;
  std::uint32_t game_man;
  std::uint32_t global_hinstance;
  std::uint32_t ichr_finder_vmt;
  std::uint32_t initialize_spawn_geometry_request;
  std::uint32_t msb_file_cap_vmt;
  std::uint32_t msb_repository_vmt;
  std::uint32_t multiplay_properties;
  std::uint32_t near_enemy_finder_vmt;
  std::uint32_t open_field_chr_set_vmt;
  std::uint32_t player_ins_vmt;
  std::uint32_t register_task;
  std::uint32_t spawn_geometry;
  std::uint32_t world_area_chr_base_vmt;
  std::uint32_t world_area_chr_vmt;
  std::uint32_t world_area_info_base_vmt;
  std::uint32_t world_area_info_vmt;
  std::uint32_t world_grid_area_chr_vmt;
  std::uint32_t world_grid_area_info_vmt;
};

inline const RvaBundle& get() {
  static const RvaBundle kRvaWw261{
    0x3b17c00,
    0x2a279f8,
    0x3e8cf0,
    0x3ee1b0,
    0x2a2e0b8,
    0x2a3e318,
    0x4843038,
    0xa62ff0,
    0x3a2dd0,
    0x2c0ca0,
    0x2dd000,
    0x264fdb0,
    0x1d26b0,
    0x264fb00,
    0x264f6b0,
    0x2bffc08,
    0x2bffcb8,
    0x766460,
    0xc707b0,
    0x2a25460,
    0x2a25520,
    0x2a27340,
    0x2a25408,
    0x2a274a0,
    0x2a9d998,
    0x2b32be8,
    0x2c017e8,
    0x2c01778,
    0x2c017b0,
    0x2c01898,
    0x2c01740,
    0x29d19e0,
    0x2a7e580,
    0x2a7e6a8,
    0x2b32fb0,
    0x2a3e390,
    0x2ba6738,
    0x2ba6418,
    0x2a48b70,
    0x2a7f038,
    0x2a25040,
    0x29cae60,
    0x2a3a428,
    0x329a158,
    0x2c05b98,
    0x3299830,
    0x2a4c7e8,
    0x2a4c808,
    0x2a4c7f8,
    0x2a4c7e8,
    0x2a4c818,
    0x2a3b7e8,
    0x2c05f20,
    0x2a7eb48,
    0x30be570,
    0x30bcb60,
    0x2a44010,
    0x30eac20,
    0x2bffd80,
    0x3293fd8,
    0x3295448,
    0x3297e88,
    0x32936b8,
    0x3295e70,
    0x3293a68,
    0x3d5df38,
    0x3d69918,
    0x3d85688,
    0x29cdd98,
    0x1db670,
    0x29da500,
    0x2ba7250,
    0x3b11230,
    0x2a252c0,
    0x2a485a0,
    0x2a7cb40,
    0xeb2000,
    0x6a5150,
    0x2a4c1a0,
    0x2a4c0f0,
    0x2a76ba8,
    0x2a79588,
    0x2a4c730,
    0x2a79ed8,
  };
  static const RvaBundle kRvaJp2611{
    0x3b17c00,
    0x2a279f8,
    0x3e8be0,
    0x3ee0b0,
    0x2a2e0b8,
    0x2a3e318,
    0x4843038,
    0xa62ee0,
    0x3a2ca0,
    0x2c0b90,
    0x2dcef0,
    0x264fcf0,
    0x1d2630,
    0x264fa40,
    0x264f5f0,
    0x2bffbf8,
    0x2bffca8,
    0x766370,
    0xc706c0,
    0x2a25460,
    0x2a25520,
    0x2a27340,
    0x2a25408,
    0x2a274a0,
    0x2a9d998,
    0x2b32be8,
    0x2c017d8,
    0x2c01768,
    0x2c017a0,
    0x2c01888,
    0x2c01730,
    0x29d19e0,
    0x2a7e580,
    0x2a7e6a8,
    0x2b32fb0,
    0x2a3e390,
    0x2ba6738,
    0x2ba6418,
    0x2a48b70,
    0x2a7f038,
    0x2a25040,
    0x29cae60,
    0x2a3a428,
    0x329a118,
    0x2c05b88,
    0x32997f0,
    0x2a4c7e8,
    0x2a4c808,
    0x2a4c7f8,
    0x2a4c7e8,
    0x2a4c818,
    0x2a3b7e8,
    0x2c05f10,
    0x2a7eb48,
    0x30be530,
    0x30bcb20,
    0x2a44010,
    0x30eabe0,
    0x2bffd70,
    0x3293f98,
    0x3295408,
    0x3297e48,
    0x3293678,
    0x3295e30,
    0x0,
    0x3d5df38,
    0x3d69918,
    0x3d85688,
    0x29cdd98,
    0x1db5f0,
    0x29da500,
    0x2ba7250,
    0x3b11230,
    0x2a252c0,
    0x2a485a0,
    0x2a7cb40,
    0xeb1f40,
    0x6a5080,
    0x2a4c1a0,
    0x2a4c0f0,
    0x2a76ba8,
    0x2a79588,
    0x2a4c730,
    0x2a79ed8,
  };
  static const RvaBundle* selected = nullptr;
  if (!selected) {
    std::string version;
    if (runtime::get_file_version(version)) {
      if (version == "2.6.1.0") {
        selected = &kRvaWw261;
      } else if (version == "2.6.1.1") {
        selected = &kRvaJp2611;
      }
    }
    if (!selected) {
      selected = &kRvaWw261;
    }
  }
  return *selected;
}
}}} // namespace eldenring::api::rva
