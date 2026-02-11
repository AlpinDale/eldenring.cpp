#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace gaitem {

struct CSGaitemGameDataEntry {
  eldenring::cs::OptionalItemId item_id;
  bool already_acquired;
};

enum class GaitemCategory : std::uint8_t {
  Weapon = 0,
  Protector = 1,
  Accessory = 2,
  Goods = 3,
  Gem = 4,
};

struct GaitemHandle {
  std::uint32_t value;
};

struct CSGemSlot {
  std::uintptr_t vtable;
  eldenring::cs::gaitem::GaitemHandle gaitem_handle;
};

struct CSGemSlotTable {
  std::uintptr_t vtable;
  std::array<eldenring::cs::gaitem::CSGemSlot, 1> gem_slots;
};

struct CSGaitemIns {
  std::uintptr_t vftable;
  eldenring::cs::gaitem::GaitemHandle gaitem_handle;
  eldenring::cs::OptionalItemId item_id;
};

struct CSGemGaitemIns {
  eldenring::cs::gaitem::CSGaitemIns gaitem_ins;
  eldenring::cs::gaitem::GaitemHandle weapon_handle;
};

struct CSWepGaitemIns {
  eldenring::cs::gaitem::CSGaitemIns gaitem_ins;
  std::uint32_t durability;
  std::uint32_t reinforcement_param_id;
  eldenring::cs::gaitem::CSGemSlotTable gem_slot_table;
};

struct CSGaitemImpEntry {
  std::uint32_t unindexed_gaitem_handle;
  std::uint32_t ref_count;
};

struct CSGaitemImp;

enum class GaitemHandleError;

struct CSGaitemGameData;

}
}
}
