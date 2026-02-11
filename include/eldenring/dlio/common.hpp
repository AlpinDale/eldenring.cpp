#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace dlio {
namespace common {

struct OpenFileMode {
  std::uint32_t _0;
};

enum class DLIOResult : std::int32_t {
  DirNotEmpty = 0,
  OutOfMemory = 1,
  DiskFull = 2,
  NotStreamed = 3,
  AlreadyOpen = 4,
  IsNotOpen = 5,
  NotFound = 6,
  AccessDenied = 7,
  OperationUnsupported = 8,
  Invalid = 9,
  Success = 0,
  NoMoreFiles = 1,
};

enum class DLFileSeekDirection : std::uint32_t {
  Head = 0,
  Current = 1,
  Tail = 2,
};

}
}
}
