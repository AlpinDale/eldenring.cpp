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
namespace material {

struct CSChrMaterialModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  std::int16_t material_param_id;
  std::array<std::int16_t, 4> unk12;
  std::uint8_t unk1a;
  bool disable_fall_damage;
  std::array<std::uint8_t, 4> unk1c;
};

}
}
}
}
}
