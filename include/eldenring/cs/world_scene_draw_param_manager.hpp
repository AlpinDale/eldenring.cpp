#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace world_scene_draw_param_manager {

struct CSWorldAreaBlockSceneDrawParam {
  std::uintptr_t vftable;
  bool unk8;
  bool is_gparam_ref_settings_for_overworld;
  std::array<std::uint8_t, 6> unka;
  eldenring::cs::BlockId area;
  std::uint32_t unk14;
  std::uint32_t unk18;
  std::uint32_t unk1c;
  std::uint64_t unk20;
  std::uint64_t unk28;
  std::array<std::uint8_t, 216> unk30;
  std::int32_t weather_gparam_1;
  std::int32_t weather_gparam_2;
  std::uint64_t unk110;
  bool transition_to_override;
  std::array<std::uint8_t, 3> unk119;
  std::uint32_t override_gparam;
  std::uint32_t unk120;
  float override_transition_duration;
  std::uint32_t unk128;
  std::uint32_t unk12c;
};

struct CSGparamIdLerper {
  std::uintptr_t vftable;
  std::uint32_t unk8;
  std::uint32_t unkc;
  std::int32_t destination_id;
  std::uint32_t unk14;
  std::int32_t begin_id;
  std::uint32_t unk1c;
  float timer;
  float unk24;
};

struct CSFD4SceneDrawParam {
  std::uintptr_t vftable;
  std::array<eldenring::cs::world_scene_draw_param_manager::CSGparamIdLerper, 15> lerpers;
  eldenring::cs::world_scene_draw_param_manager::CSGparamIdLerper lerper;
};

struct CSWorldSceneDrawParamManager {
  std::uintptr_t vftable;
  eldenring::cs::WorldInfoOwner* world_info_owner;
  std::uint32_t world_block_info_count;
  std::uint32_t _pad14;
  std::uint64_t unk18;
  std::uint64_t unk20;
  eldenring::DoublyLinkedList<eldenring::cs::world_scene_draw_param_manager::CSWorldAreaBlockSceneDrawParam> world_area_blocks;
  eldenring::cs::world_scene_draw_param_manager::CSFD4SceneDrawParam scene_draw_param;
};

}
}
}
