#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace game_man {

enum class ForceCamRotationMethod : std::uint32_t {
  Default = 0,
  Closest = 1,
  CounterClockwise = 2,
  Clockwise = 3,
};

enum class EventWorldType : std::uint8_t {
  Local = 0,
  Remote = 1,
};

struct GameMan;

}
}
}
