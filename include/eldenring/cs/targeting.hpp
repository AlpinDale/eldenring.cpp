#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace targeting {

struct CSTargetSearchSys {
  std::uintptr_t vftable;
  eldenring::cs::targeting::CSTargetingSystemOwner* system_owner;
  std::array<std::uintptr_t, 14> search_slots;
  std::uint16_t unk80;
  std::array<std::uint8_t, 6> _pad82;
  std::uintptr_t unk88;
  std::int32_t latest_ai_sound_id;
  std::int8_t latest_sound_rank;
  std::array<std::uint8_t, 11> unk95;
};

struct CSTargetingSystemBase {
  std::uintptr_t vftable;
  eldenring::cs::targeting::CSTargetingSystemOwner* system_owner;
  eldenring::cs::targeting::CSTargetSearchSys search_sys;
  std::array<std::uint8_t, 288> unk8;
};

struct NpcThinkParamLookupResult {
  std::uint32_t row_id;
  std::uintptr_t param_row;
  std::int32_t battle_goal_id;
  std::int32_t logic_id;
};

struct CSTargetingSystemOwner;

struct CSBulletTargetingSystemOwner;

struct CSAiTargetingSystemOwner;

}
}
}
