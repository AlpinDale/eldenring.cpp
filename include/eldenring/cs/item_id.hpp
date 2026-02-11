#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace item_id {

struct OptionalItemId {
  std::uint32_t value;
};

struct ItemId {
  eldenring::cs::item_id::OptionalItemId _0;
};

enum class ItemCategory : std::uint8_t {
  Weapon = 0,
  Protector = 1,
  Accessory = 2,
  Goods = 4,
  Gem = 8,
};

enum class ItemIdError;

}
}
}
