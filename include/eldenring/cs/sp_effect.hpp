#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace sp_effect {

struct SpEffectEquipCtrl {
  std::uintptr_t vfptr;
  eldenring::cs::ChrIns* owner;
  eldenring::cs::sp_effect::SpecialEffect* sp_effect;
};

struct NpcSpEffectEquipCtrl {
  eldenring::cs::sp_effect::SpEffectEquipCtrl sp_effect_equip_ctrl;
};

struct SpecialEffectEntryAccumulatorInfo {
  std::uintptr_t unk0;
  std::int32_t upper_trigger_count;
  std::int32_t effect_on_upper_or_higher;
  std::int32_t lower_trigger_count;
  std::int32_t effect_on_lower_or_below;
  std::int32_t unk18;
  std::uint32_t unk1c;
};

struct SpecialEffectEntry {
  eldenring::param::SP_EFFECT_PARAM_ST* param_data;
  std::int32_t param_id;
  std::uint32_t _padc;
  eldenring::cs::sp_effect::SpecialEffectEntryAccumulatorInfo accumulator_info;
  eldenring::cs::sp_effect::SpecialEffectEntry* next;
  eldenring::cs::sp_effect::SpecialEffectEntry* previous;
  float removal_timer;
  float unk_removal_timer;
  float duration;
  float interval_timer;
  std::array<std::uint8_t, 40> unk50;
};

struct SpecialEffect {
  std::uintptr_t vftable;
  eldenring::shared::owned_pointer::OwnedPtr<eldenring::cs::sp_effect::SpecialEffectEntry> head;
  eldenring::cs::ChrIns* owner;
  std::uintptr_t unk18;
  std::array<std::uint8_t, 280> unk20;
};

}
}
}
