#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace event_man {

struct CSEventWorldAreaTimeCtrl {
  std::array<std::uint8_t, 64> base;
  std::array<std::uint8_t, 104> unk40;
  bool unka8;
  std::uint32_t target_hours;
  std::uint32_t target_minutes;
  std::uint32_t target_seconds;
  bool fade_transition;
  float black_screen_time;
  std::uint32_t bonfire_entity_id;
  bool reset_world;
  bool reset_main_character;
  bool reset_magic_charges;
  bool restore_estus;
  bool show_clock;
  float clock_startup_delay_s;
  float clock_move_time_s;
  float clock_finish_delay_s;
  float fade_out_time;
  float fade_in_time;
  bool fade_out_requested;
  float update_elapsed_time;
  float black_screen_elapsed_time;
  bool respawn_wait_flag;
  bool unked;
  bool unkee;
  bool unkef;
  bool unkf0;
  float total_elapsed_time;
  float black_screen_timeout;
};

struct CSEventSosSignCtrl {
  std::uintptr_t vftable;
  std::array<std::uint8_t, 64> unk8;
  eldenring::cs::CSSosSignMan* sos_sign_man;
  std::uint32_t unk50;
  std::uint32_t unk54;
};

struct CSEventManImp;

struct TimeTransitionParams;

}
}
}
