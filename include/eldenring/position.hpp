#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace position {

struct DirectionalVector {
  float _0;
  float _1;
  float _2;
  float _3;
};

struct PositionDelta {
  float _0;
  float _1;
  float _2;
};

struct HavokPosition {
  float _0;
  float _1;
  float _2;
  float _3;
};

struct BlockPosition {
  float x;
  float y;
  float z;
  float yaw;
};

}
}
