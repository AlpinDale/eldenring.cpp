#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace player_game_data {

enum class EquipmentDurabilityStatus : std::uint8_t {
  Ok = 0,
  AtRisk = 1,
  Broken = 2,
};

enum class ChrAsmArmStyle : std::uint32_t {
  EmptyHanded = 0,
  OneHanded = 1,
  LeftBothHands = 2,
  RightBothHands = 3,
};

struct ChrAsmEquipmentSlots {
  std::uint32_t left_weapon_slot;
  std::uint32_t right_weapon_slot;
  std::uint32_t left_arrow_slot;
  std::uint32_t right_arrow_slot;
  std::uint32_t left_bolt_slot;
  std::uint32_t right_bolt_slot;
};

struct ChrAsmEquipment {
  eldenring::cs::player_game_data::ChrAsmArmStyle arm_style;
  eldenring::cs::player_game_data::ChrAsmEquipmentSlots selected_slots;
};

struct ChrAsm {
  std::int32_t unk0;
  std::int32_t unk4;
  eldenring::cs::player_game_data::ChrAsmEquipment equipment;
  std::array<eldenring::cs::GaitemHandle, 22> gaitem_handles;
  std::array<std::int32_t, 22> equipment_param_ids;
  std::uint32_t unkd4;
  std::uint32_t unkd8;
  std::array<std::uint8_t, 12> _paddc;
};

enum class ChrAsmSlot : std::uint32_t {
  WeaponLeft1 = 0,
  WeaponRight1 = 1,
  WeaponLeft2 = 2,
  WeaponRight2 = 3,
  WeaponLeft3 = 4,
  WeaponRight3 = 5,
  Arrow1 = 6,
  Bolt1 = 7,
  Arrow2 = 8,
  Bolt2 = 9,
  Arrow3 = 10,
  Bolt3 = 11,
  ProtectorHead = 12,
  ProtectorChest = 13,
  ProtectorHands = 14,
  ProtectorLegs = 15,
  Unused16 = 16,
  Accessory1 = 17,
  Accessory2 = 18,
  Accessory3 = 19,
  Accessory4 = 20,
  AccessoryCovenant = 21,
};

struct EquipDataItem {
  eldenring::cs::GaitemHandle gaitem_handle;
  std::int32_t index;
};

struct EquipMagicItem {
  std::int32_t param_id;
  std::int32_t charges;
};

struct EquipMagicData {
  std::uintptr_t vftable;
  eldenring::cs::player_game_data::EquipGameData* equip_game_data;
  std::array<eldenring::cs::player_game_data::EquipMagicItem, 14> entries;
  std::int32_t selected_slot;
  std::uint32_t unk84;
};

struct EquipInventoryDataListEntry {
  eldenring::cs::GaitemHandle gaitem_handle;
  eldenring::cs::ItemId item_id;
  std::uint32_t quantity;
  std::uint32_t sort_id;
  bool is_new;
  std::int32_t pot_group;
};

struct InventoryItemListAccessor {
  eldenring::shared::MaybeEmpty<eldenring::cs::player_game_data::EquipInventoryDataListEntry>* head;
  std::uint32_t* length;
};

struct BrokenEquipmentSlots {
  std::uint32_t value;
};

enum class LastAddItemResult : std::uint32_t {
  Success = 0,
  UniqueItemDuplicate = 2,
  InventoryFull = 4,
};

struct ChrAsmEquipEntries {
  eldenring::cs::ItemId weapon_primary_left;
  eldenring::cs::ItemId weapon_primary_right;
  eldenring::cs::ItemId weapon_secondary_left;
  eldenring::cs::ItemId weapon_secondary_right;
  eldenring::cs::ItemId weapon_tertiary_left;
  eldenring::cs::ItemId weapon_tertiary_right;
  eldenring::cs::OptionalItemId arrow_primary;
  eldenring::cs::OptionalItemId bolt_primary;
  eldenring::cs::OptionalItemId arrow_secondary;
  eldenring::cs::OptionalItemId bolt_secondary;
  eldenring::cs::OptionalItemId arrow_tertiary;
  eldenring::cs::OptionalItemId bolt_tertiary;
  eldenring::cs::ItemId protector_head;
  eldenring::cs::ItemId protector_chest;
  eldenring::cs::ItemId protector_hands;
  eldenring::cs::ItemId protector_legs;
  eldenring::cs::OptionalItemId unused40;
  std::array<eldenring::cs::OptionalItemId, 4> accessories;
  eldenring::cs::OptionalItemId covenant;
  std::array<eldenring::cs::OptionalItemId, 10> quick_tems;
  std::array<eldenring::cs::OptionalItemId, 6> pouch;
};

struct QMItemBackupVectorItem {
  eldenring::cs::OptionalItemId item_id;
  std::uint32_t quantity;
};

struct ItemReplenishStateEntryUnk {
  eldenring::cs::OptionalItemId item_id;
  bool auto_replenish;
};

struct ItemReplenishStateEntry {
  eldenring::cs::OptionalItemId item_id;
  bool auto_replenish;
};

struct ItemReplenishStateTracker {
  std::array<eldenring::cs::player_game_data::ItemReplenishStateEntry, 2048> entries;
  std::uint32_t unk4000;
  std::uint32_t unk4004;
  std::uint64_t count;
  std::array<eldenring::cs::player_game_data::ItemReplenishStateEntryUnk, 256> unk4010;
};

struct PlayerGameDataSpEffect {
  std::uint32_t sp_effect_id;
  float duration;
  std::uint32_t unk8;
  std::uint32_t unkc;
};

struct FaceDataBuffer {
  std::array<std::uint8_t, 4> magic;
  std::uint32_t version;
  std::uint32_t buffer_size;
  std::array<std::uint8_t, 276> buffer;
};

struct FaceData {
  std::uintptr_t vftable;
  eldenring::cs::player_game_data::FaceDataBuffer face_data_buffer;
  std::uintptr_t unk128;
  std::array<float, 7> unk130;
  std::array<std::uint8_t, 36> unk14c;
};

struct PlayerDataAttackRating {
  std::int32_t left_armament_primary;
  std::int32_t right_armament_primary;
  std::int32_t left_armament_secondary;
  std::int32_t right_armament_secondary;
  std::int32_t left_armament_tertiary;
  std::int32_t right_armament_tertiary;
};

enum class PlayerDataInvasionItemType : std::uint8_t {
  BloodyFinger = 0,
  FesteringBloodyFinger = 1,
  RecusantFinger = 2,
};

struct PlayerGameDataFrontendFlags {
  std::uint8_t value;
};

enum class SellRegion : std::uint8_t {
  None = 0,
  Japan = 1,
  NorthAmerica = 2,
  Europe = 3,
  Asia = 4,
  Global = 5,
};

struct PlayerGameData;

struct EquipGameData;

struct InventoryItemsData;

struct EquipInventoryData;

struct ItemIdMapping;

struct EquipItemData;

enum class ChrAsmSlotError;

}
}
}
