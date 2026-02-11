#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace game_data_man {

enum class HudType : std::uint8_t {
  Off = 0,
  On = 1,
  Auto = 2,
};

enum class PerformanceSetting : std::uint8_t {
  PrioritizeQuality = 0,
  PrioritizeFramerate = 1,
};

enum class DisplayBlood : std::uint8_t {
  Off = 0,
  On = 1,
  Mild = 2,
};

struct GameSettings {
  std::uint8_t camera_speed;
  std::uint8_t controller_rumble_strength;
  std::uint8_t brightness;
  std::uint8_t sound_type;
  std::uint8_t music_volume;
  std::uint8_t sfx_volume;
  std::uint8_t voice_volume;
  eldenring::cs::game_data_man::DisplayBlood display_blood;
  bool show_subtitles;
  eldenring::cs::game_data_man::HudType hud_type;
  bool reverse_camera_xaxis;
  bool reverse_camera_yaxis;
  bool auto_lock_on;
  bool camera_auto_wall_recovery;
  std::uint8_t unke;
  bool jump_button_l3;
  bool reset_camera_yaxis;
  bool cinematic_effects;
  std::uint8_t unk12;
  bool enable_cross_region_play;
  bool voice_chat;
  bool show_gamer_tags;
  bool manual_attack_aiming;
  bool auto_target;
  bool start_offline;
  bool send_summon_signs;
  bool unused_gr_system_103000;
  std::uint8_t unk1b;
  std::uint8_t hdr_brightness;
  std::uint8_t hdr_max_brightness;
  std::uint8_t hdr_contrast;
  eldenring::cs::game_data_man::PerformanceSetting performance_setting;
  std::uint8_t master_volume;
  bool enable_ray_tracing;
  bool mark_new_items;
  bool show_recent_items;
  std::array<std::uint8_t, 10> unka4;
  bool show_tutorials;
  bool camera_auto_rotation;
  std::array<std::uint8_t, 272> unused_space;
};

struct GameVersionData {
  std::uint32_t game_data_version;
  std::uint32_t last_saved_game_data_version;
  bool saved_game_data_version_is_the_latest;
  std::uint32_t unused;
};

enum class DeathState : std::int32_t {
  None = 0,
  Normal = 0,
  MagicResurrection = 1,
  RingNormalResurrection = 2,
  RingCurseResurrection = 3,
};

enum class RemotePlayerDataSlotState : std::uint8_t {
  Free = 0,
  Occupied = 1,
  BaseData = 2,
  Equipment = 3,
  Type = 4,
  FullySynced = 15,
};

struct GameDataMan;

}
}
}
