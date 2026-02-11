#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace net_chr_sync {

struct ChrSyncHealthUpdate {
  std::int32_t current_hp;
  std::uint32_t damage_taken;
};

struct ChrSyncUpdateFlags {
  std::uint16_t value;
};

struct NetChrSetSync {
  std::uintptr_t vftable;
  eldenring::cs::ChrSet<eldenring::cs::ChrIns>* chr_set;
  std::uint32_t capacity;
  std::uint32_t _pad14;
  std::uintptr_t unk18_readback_values;
  eldenring::cs::net_chr_sync::ChrSyncPlacementUpdate* placement_readback_values;
  std::uintptr_t unk28_readback_values;
  eldenring::cs::net_chr_sync::ChrSyncHealthUpdate* health_readback_values;
  eldenring::cs::net_chr_sync::ChrSyncUpdateFlags* update_flags;
  std::uintptr_t unk40_readback_values;
  std::uintptr_t unk48_readback_values;
};

struct NetChrSync {
  std::uintptr_t world_info_owner;
  std::uint32_t chr_slot_count;
  std::uint32_t _padc;
  std::array<eldenring::shared::owned_pointer::OwnedPtr<eldenring::cs::net_chr_sync::NetChrSetSync>, 196> net_chr_set_sync;
};

struct ChrSyncPlacementUpdate;

}
}
}
