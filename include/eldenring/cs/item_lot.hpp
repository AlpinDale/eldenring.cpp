#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace item_lot {

struct ItemLotUtil {
  std::uint32_t item_lot;
  bool is_map_item_lot;
  std::array<std::uint8_t, 3> unk5;
  std::uint32_t unk8;
  std::uint32_t unkc;
  std::uint32_t unk10;
  std::uint32_t unk14;
  std::uintptr_t unk18;
};

}
}
}
