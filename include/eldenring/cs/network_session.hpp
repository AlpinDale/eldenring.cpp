#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace network_session {

struct ReceivedPacketReader {
  std::uint8_t* buffer;
  std::uintptr_t allocation_size;
  std::uintptr_t received_size;
};

struct ReceivePacketAllocation {
  std::uint8_t* buffer;
  std::uintptr_t size;
};

struct PlayerSession;

struct PlayerNetworkSession;

}
}
}
