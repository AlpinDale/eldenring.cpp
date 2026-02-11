#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace event_flag {

struct FlagBlock {
  std::array<std::uint8_t, 125> bytes;
};

struct CSFD4VirtualMemoryFlag {
  std::uintptr_t vftable;
  std::uintptr_t allocator;
  std::uint32_t unk10;
  std::uint32_t unk14;
  std::uint32_t unk18;
  std::uint32_t event_flag_divisor;
  std::uint32_t event_flag_holder_size;
  std::uint32_t event_flag_holder_count;
  eldenring::cs::event_flag::FlagBlock* flag_blocks;
  eldenring::Tree<eldenring::cs::event_flag::FlagBlockDescriptor> flag_block_descriptors;
  std::array<std::uint8_t, 48> unk38;
};

struct CSEventFlagMan {
  eldenring::cs::event_flag::CSFD4VirtualMemoryFlag virtual_memory_flag;
  std::uint32_t world_type;
  std::array<std::uint8_t, 500> unk7c;
};

struct EventFlag {
  std::uint32_t _0;
};

struct FlagBlockDescriptor;

enum class FlagBlockLocation;

}
}
}
