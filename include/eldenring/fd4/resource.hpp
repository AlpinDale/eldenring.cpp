#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace fd4 {
namespace resource {

struct FD4FileCapUnk8AProperties {
  std::uint16_t value;
};

struct FD4FileCapUnk89Properties {
  std::uint8_t value;
};

enum class FD4FileCapState : std::uint8_t {
  Initial = 0,
  Queued = 1,
  Processing = 2,
  Unknown = 3,
  Ready = 4,
};

template <typename T>
struct FD4ResCapHolder {
  std::uintptr_t vftable;
  std::uintptr_t allocator;
  eldenring::fd4::resource::FD4ResCapHolder<eldenring::fd4::resource::FD4ResCap>* owning_repository;
  std::uint32_t unk18;
  std::uint32_t bucket_count;
  T** buckets;
};

struct FD4ResCap;

template <typename T>
struct FD4ResRep;

struct FD4FileCap;

}
}
}
