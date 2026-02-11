#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace world_geom_man {

struct GeometrySpawnRequest {
  std::array<std::uint16_t, 32> asset_string;
  std::uint32_t unk40;
  std::uint32_t unk44;
  std::uint64_t asset_string_ptr;
  std::uint32_t unk50;
  std::uint32_t unk54;
  std::uint32_t unk58;
  std::uint32_t unk5c;
  std::uint32_t unk60;
  std::uint32_t unk64;
  std::uint32_t unk68;
  std::uint32_t unk6c;
  float pos_x;
  float pos_y;
  float pos_z;
  float rot_x;
  float rot_y;
  float rot_z;
  float scale_x;
  float scale_y;
  float scale_z;
  std::array<std::uint8_t, 108> unk94;
};

struct CSWorldGeomInfoUnk {
  std::uint32_t unk0;
  std::uint32_t unk4;
  std::uint32_t unk8;
  std::uint32_t unkc;
  std::uint32_t unk10;
  std::uint32_t unk14;
  std::uint32_t unk18;
  std::uint32_t unk1c;
  std::uintptr_t unk20;
  std::array<std::uint8_t, 56> unk28;
  std::uintptr_t unk60;
};

struct CSWorldGeomMan;

struct CSWorldGeomManBlocksEntry;

struct CSWorldGeomManBlockData;

struct GeometrySpawnParameters;

struct CSWorldGeomIns;

struct CSWorldGeomInfo;

struct CSMsbPartsGeom;

struct CSMsbParts;

struct CSMsbPartsEne;

struct MsbPart;

}
}
}
