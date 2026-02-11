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
namespace toughness {

struct CSChrToughnessModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  float toughness;
  float toughness_unk;
  float toughness_max;
  float recover_time;
  std::array<std::uint8_t, 13> unk20;
  bool trigger_max_toughness_update;
  std::array<std::uint8_t, 250> unk2e;
};

}
}
}
}
}
