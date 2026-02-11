#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace dlio {
namespace file_device {

struct DLFileOperatorIOState {
  std::uint32_t _0;
};

enum class DLFileDeviceDriveType : std::uint32_t {
  Unknown = 0,
  CdRom = 1,
  Default = 2,
};

struct DLFileDeviceBase;

struct DLFileEnumeratorSPIBase;

template <typename T>
struct DLFileOperatorBase;

struct DLFileDeviceImageSPIBase;

struct BndEntry;

struct DLFileOperatorContainer;

struct DLFileDeviceManager;

template <typename R>
struct AdapterFileOperator;

}
}
}
