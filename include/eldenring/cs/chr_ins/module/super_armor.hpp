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
namespace super_armor {

struct CSChrSuperArmorModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  float sa_durability;
  float sa_durability_max;
  std::uint32_t unk18;
  float recover_time;
  std::uint8_t unk20;
  std::uint8_t unk21;
  bool poise_broken_state;
  std::uint8_t unk23;
  std::uint32_t unk24;
};

}
}
}
}
}
