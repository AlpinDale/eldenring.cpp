#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace field_ins {

struct FieldInsSelector {
  std::uint32_t value;
};

struct FieldInsHandle {
  eldenring::cs::field_ins::FieldInsSelector selector;
  eldenring::cs::BlockId block_id;
};

enum class FieldInsType : std::uint32_t {
  Hit = 0,
  Chr = 1,
  Obj = 2,
  Bullet = 3,
  Geom = 4,
  ReplayGhost = 5,
  ReplayEnemy = 6,
  Map = 7,
  HitGeom = 8,
};

}
}
}
