#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace world_sfx_man {

struct WorldBlockSfx {
  std::uintptr_t vftable;
  std::uintptr_t world_block_info;
  eldenring::cs::world_sfx_man::WorldAreaSfx* world_area_sfx;
  eldenring::cs::BlockId block_id;
  std::array<std::uint8_t, 64> unk1c;
  std::uint32_t total_sfx_count;
  std::uintptr_t unk60;
  std::uint32_t unk68;
  std::uint32_t unk6c;
  std::uintptr_t unk70;
};

struct WorldAreaSfxBase {
  std::uintptr_t vftable;
  std::uintptr_t world_area_info;
  std::uint64_t unk10;
};

struct WorldAreaSfx {
  eldenring::cs::world_sfx_man::WorldAreaSfxBase base;
  std::uintptr_t world_area_info;
  std::uint32_t world_block_sfx_count;
  std::uint32_t _pad24;
  eldenring::cs::world_sfx_man::WorldBlockSfx* world_block_sfx;
};

struct WorldSfxMan {
  std::uintptr_t vftable;
  std::uintptr_t unk8;
  eldenring::cs::WorldInfoOwner* world_info_owner;
  std::uint32_t world_area_sfx_count;
  std::uint32_t _pad1c;
  eldenring::cs::world_sfx_man::WorldAreaSfx* world_area_sfx_list;
  std::uint32_t world_block_sfx_count;
  std::uint32_t _pad2c;
  eldenring::cs::world_sfx_man::WorldBlockSfx* world_block_sfx_list;
  std::uint32_t world_grid_area_sfx_count;
  std::uint32_t _pad3c;
  eldenring::cs::world_sfx_man::WorldGridAreaSfx* world_grid_area_sfx_list;
  std::uint64_t _pad48;
  std::array<eldenring::cs::world_sfx_man::WorldAreaSfx, 28> world_area_sfx;
  std::array<eldenring::cs::world_sfx_man::WorldBlockSfx, 192> world_block_sfx;
  std::array<eldenring::cs::world_sfx_man::WorldAreaSfx, 6> world_grid_area_sfx;
  std::array<std::uint8_t, 384> unk6110;
};

struct WorldGridAreaSfx;

}
}
}
