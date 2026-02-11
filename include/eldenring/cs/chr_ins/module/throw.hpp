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
namespace kw_throw {

struct ThrowModuleFlags {
  std::uint32_t value;
};

enum class ThrowNodeState : std::uint32_t {
  Unk1 = 1,
  Unk2 = 2,
  InThrowAttacker = 3,
  InThrowTarget = 4,
  DeathAttacker = 5,
  DeathTarget = 6,
  Unk7 = 7,
  Unk8 = 8,
};

struct CSThrowNode;

struct CSChrThrowModule;

}
}
}
}
}
