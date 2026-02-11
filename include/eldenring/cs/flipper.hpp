#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace flipper {

struct CSFlipperVsyncHistoryEntry {
  std::uint64_t frame_delta_ticks;
  bool vsync_state;
};

enum class FlipMode : std::uint32_t {
  VsyncOn30Fps = 0,
  Adaptive30Fps = 1,
  Default60Fps = 2,
  ForcedSync30Fps = 3,
  VsyncOff30Fps = 4,
  VsyncOn60Fps = 5,
  NoSync360Fps = 6,
  Adaptive20Fps = 7,
  DynamicAdaptive = 8,
  Default85Fps = 9,
  NoSync85Fps = 10,
  Default120Fps = 11,
  NoSync120Fps = 12,
  PlatformDefault = 13,
};

struct CSFlipper {
  std::uintptr_t vftable;
  eldenring::cs::flipper::FlipMode flip_mode_initial;
  eldenring::cs::flipper::FlipMode flip_mode_current;
  eldenring::cs::flipper::FlipMode flip_mode_platform;
  std::uint8_t unk14;
  bool previous_force_mode;
  bool force_mode_pending;
  std::uint8_t unk17;
  std::uint32_t vsync_interval;
  float fixed_fps;
  std::uintptr_t previous_frame_qpc;
  std::uintptr_t current_frame_qpc;
  std::array<std::uint8_t, 48> unk30;
  std::array<eldenring::cs::flipper::CSFlipperVsyncHistoryEntry, 32> frame_time_history;
  std::uint32_t frame_history_index;
  float last_frame_time;
  float task_delta;
  std::uint32_t foreground_frame_history_count;
  std::uint32_t background_frame_history_count;
  bool enable_frame_sync;
  bool reset_frame_history_count;
  bool force_no_sleep;
  std::uint8_t unk227;
  std::array<float, 16> frame_time_rolling_average;
  float calculated_fps;
  std::int32_t override_foreground_history_count;
  std::int32_t override_background_history_count;
  float dynamic_fps_lock;
  bool use_dynamic_fps_lock;
  bool dynamic_fps_active;
  bool dynamic_fps_transition;
  bool debug_disp_fps;
  float game_speed;
  bool use_special_timing_mode;
  std::array<std::uint8_t, 3> unk2d1;
  float unk2d4;
  float countdown_timer;
  std::array<std::uint8_t, 4> unk2dc;
};

}
}
}
