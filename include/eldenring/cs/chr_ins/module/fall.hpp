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
namespace fall {

struct CSChrFallModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  std::int64_t unk10;
  float fall_timer;
  bool hamari_fall_death_checked;
  bool force_max_fall_height;
  bool disable_fall_motion;
};

}
}
}
}
}
