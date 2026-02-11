#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace world_chr_man {

struct CSBuddyStoneEliminateTargetCalc {
  std::uint64_t vftable;
  eldenring::cs::FieldInsHandle owner_field_ins_handle;
  std::int32_t buddy_stone_param_id;
  std::int32_t target_event_entity_id;
  bool target_in_range;
  std::uint32_t range_check_counter;
};

struct SummonBuddyStoneEliminateTargetEntry {
  eldenring::cs::FieldInsHandle buddy_field_ins_handle;
  eldenring::cs::world_chr_man::CSBuddyStoneEliminateTargetCalc target_calc;
};

struct SummonBuddyGroupEntry {
  eldenring::cs::ChrIns* chr_ins;
  bool unk8;
  bool has_mount;
  std::int32_t buddy_param_id;
  std::int32_t buddy_stone_param_id;
  std::int32_t doping_sp_effect_id;
  std::uint32_t dopping_level_sp_effect_id;
  std::uint32_t spawn_animation;
  bool warp_requested;
  bool disappear_requested;
  float disappear_delay_sec;
  bool has_spawn_point;
  bool disable_pc_target_share;
  std::uint8_t follow_type;
  bool is_remote;
  bool has_mogh_great_rune_buff;
  bool unk2d;
};

struct SummonBuddyGroup {
  std::int32_t owner_event_id;
  eldenring::DoublyLinkedList<eldenring::cs::world_chr_man::SummonBuddyGroupEntry> entries;
};

enum class SummonBuddyWarpStage : std::uint8_t {
  None = 0,
  RequestWarp = 1,
  Warping = 2,
  FadeIn = 3,
};

struct SummonBuddyWarpManager {
  eldenring::Tree<eldenring::cs::world_chr_man::SummonBuddyWarpEntry> entries;
  float trigger_time_ray_block;
  float trigger_dist_to_player;
  float trigger_threshold_time_path_stacked;
  float trigger_threshold_range_path_stacked;
  std::uint32_t unk28;
  std::int32_t unk2c;
  bool unk30;
};

struct OpenFieldChrSetList2Entry {
  std::uint64_t unk0;
  std::uint32_t unk8;
  std::uint32_t unkc;
};

struct OpenFieldChrSetList1Entry {
  std::uint64_t unk0;
  eldenring::cs::ChrIns* chr_ins;
};

enum class ChrUpdateType : std::uint8_t {
  Local = 0,
  Unknown1 = 1,
  Unknown2 = 2,
  Unknown3 = 3,
  Remote = 4,
};

enum class ChrLoadStatus : std::uint8_t {
  Unloaded = 0,
  Initializing = 1,
  Active = 2,
  NetworkInitializing = 3,
  ReadyForActivation = 4,
  Unloading = 5,
};

template <typename T>
struct ChrSetEntry {
  T* chr_ins;
  eldenring::cs::world_chr_man::ChrLoadStatus chr_load_status;
  eldenring::cs::world_chr_man::ChrUpdateType chr_update_type;
  std::uint8_t entry_flags;
  std::array<std::uint8_t, 5> _padb;
};

template <typename T>
struct ChrSetGroupMapping {
  std::uint32_t group_id;
  std::uint32_t _pad4;
  eldenring::cs::world_chr_man::ChrSetEntry<T>* chr_set_entry;
};

template <typename T>
struct ChrSetEntityIdMapping {
  std::uint32_t entity_id;
  std::uint32_t _pad4;
  eldenring::cs::world_chr_man::ChrSetEntry<T>* chr_set_entry;
};

struct WorldAreaChrBase {
  std::uintptr_t vftable;
  std::uintptr_t world_area_info;
};

template <typename T>
struct WorldAreaChr {
  eldenring::cs::world_chr_man::WorldAreaChrBase base;
  std::uintptr_t world_area_info;
  std::uint32_t unk18;
  std::uint32_t unk1c;
  eldenring::cs::world_chr_man::WorldBlockChr<T>* world_block_chr;
};

template <typename T>
struct ChrSetHolder {
  eldenring::cs::world_chr_man::ChrSet<T>* chr_set;
  std::uint32_t chr_set_index;
  std::uint32_t _padc;
  eldenring::cs::world_chr_man::WorldBlockChr<T>* world_block_chr;
};

struct ChrInsDistanceEntry {
  eldenring::cs::ChrIns* chr_ins;
  float distance;
  std::uint32_t _unkc;
};

struct WorldChrMan;

struct ChrDebugSpawnRequest;

struct CSDebugChrCreator;

struct CSDebugChrCreatorInitData;

template <typename T>
struct WorldBlockChr;

template <typename T>
struct ChrSet;

struct OpenFieldChrSet;

struct WorldGridAreaChr;

struct SummonBuddyManager;

struct SummonBuddyWarpEntry;

struct IChrFinder;

struct NearEnemyFinder;

}
}
}
