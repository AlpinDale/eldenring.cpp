#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace bullet_ins {

struct BulletPhysics {
  eldenring::position::HavokPosition position;
  eldenring::rotation::Quaternion orientation;
  eldenring::position::DirectionalVector velocity;
  eldenring::position::DirectionalVector velocity2;
};

struct BulletParamLookupResult {
  eldenring::param::BULLET_PARAM_ST* param_row;
  std::int32_t param_id;
  std::uint8_t version;
  std::array<std::uint8_t, 3> _padd;
};

struct CSBulletIns;

struct CSBulletState;

struct CSBulletWaitState;

struct CSBulletFlyState;

struct CSBulletExplosionState;

struct CSBulletNULLState;

}
}
}
