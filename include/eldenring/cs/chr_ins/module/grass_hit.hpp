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
namespace grass_hit {

struct CSChrGrassHitModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  std::uint8_t grass_hit_param_id;
  std::uint8_t last_update_grass_hit_param_id;
  eldenring::fd4::FD4Time state_decay_timer;
  float default_decay_time;
  std::array<std::uint8_t, 20> unk2c;
};

}
}
}
}
}
