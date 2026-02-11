#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace chr_ins {
namespace module {
namespace action_request {

struct AiActionCancels {
  std::uint32_t value;
};

struct ActionTimers {
  float r1;
  float r2;
  float l1;
  float l2;
  float action;
  float roll;
  float jump;
  float use_item;
  float switch_spell;
  float change_weapon_r;
  float change_weapon_l;
  float change_item;
  float r3;
  float l3;
  float touch_r;
  float touch_l;
};

struct ChrActions {
  std::uint64_t value;
};

struct CSChrActionRequestModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  eldenring::cs::chr_ins::module::action_request::ChrActions action_requests;
  std::array<std::uint8_t, 8> unk18;
  std::uint64_t unk20;
  std::array<std::uint8_t, 8> unk28;
  std::uint64_t unk30;
  std::array<std::uint8_t, 8> unk38;
  eldenring::cs::chr_ins::module::action_request::ChrActions disabled_action_inputs;
  std::array<std::uint8_t, 72> unk48;
  std::uint32_t unk90;
  std::array<std::uint8_t, 4> unk94;
  eldenring::cs::chr_ins::module::action_request::ChrActions possible_action_inputs;
  eldenring::cs::chr_ins::module::action_request::ChrActions possible_action_cancels;
  std::array<std::uint8_t, 8> unka8;
  eldenring::cs::chr_ins::module::action_request::ActionTimers action_timers;
  float movement_request_duration;
  std::array<std::uint8_t, 4> unkf4;
  std::int32_t requested_gesture;
  std::array<std::uint8_t, 4> unkfc;
  eldenring::cs::chr_ins::module::action_request::AiActionCancels ai_cancels;
  std::array<std::uint8_t, 60> unk104;
};

}
}
}
}
}
