#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace dlut {

struct PackedDate {
  std::uint64_t value;
};

struct DLDateTime {
  std::uint64_t time64;
  eldenring::dlut::PackedDate date;
};

struct DLReferenceCountObjectBase;

template <typename T, typename C>
struct DLFixedVector;

}
}
