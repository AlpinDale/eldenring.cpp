#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace cs_rand {

struct DLRandomGeneratorXorshift {
  std::array<std::uint32_t, 4> state;
};

struct CSRand;

struct CSRandXorshift;

struct CSRandSFMT;

struct DLRandomGeneratorSFMT;

}
}
}
