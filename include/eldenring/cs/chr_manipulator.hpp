#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace chr_manipulator {

enum class ManipulatorType : std::uint32_t {
  Default = 0,
  Pad = 1,
  Network = 2,
  Replay = 3,
  NetAi = 4,
  Com = 5,
  Ride = 6,
  Follow = 7,
};

struct ChrManipulator;

}
}
}
