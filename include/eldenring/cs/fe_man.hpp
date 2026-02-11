#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace fe_man {

struct CSFeSpiritAshDisplay {
  eldenring::cs::FieldInsHandle field_ins_handle;
  std::uint32_t hp;
  std::uint32_t unkc;
  std::uint32_t hp_max_uncapped_difference;
  std::uint32_t hp_max_uncapped;
};

enum class FullScreenMessage : std::int32_t {
  None = 0,
  DemigodFelled = 1,
  LegendFelled = 2,
  GreatEnemyFelled = 3,
  EnemyFelled = 4,
  YouDied = 5,
  HostVanquished = 7,
  BloodFingerVanquished = 8,
  DutyFullFilled = 9,
  LostGraceDiscovered = 11,
  Commence = 13,
  Victory = 14,
  Stalemate = 15,
  Defeat = 16,
  MapFound = 17,
  GreatRuneRestored = 21,
  GodSlain = 22,
  DuelistVanquished = 23,
  RecusantVanquished = 24,
  InvaderVanquished = 25,
  FurledFingerRankAdvanced = 26,
  FurledFingerRankAdvanced2 = 31,
  DuelistRankAdvanced = 32,
  DuelistRankAdvanced2 = 33,
  BloodyFingerRankAdvanced = 34,
  BloodyFingerRankAdvanced2 = 35,
  RecusantRankAdvanced = 36,
  RecusantRankAdvanced2 = 37,
  HunterRankAdvanced = 38,
  HunterRankAdvanced2 = 39,
  HeartStolen = 40,
  MenuText = 41,
  YouDiedWithFade = 42,
};

struct FrontEndView {
  std::array<std::uint8_t, 2609> menu_window;
  std::array<std::uint8_t, 7> unka31;
  std::array<std::uint8_t, 152008> root_scene;
  eldenring::cs::fe_man::FrontEndViewValues* front_end_view_values;
};

struct BossHealthDisplayEntry {
  std::int32_t fmg_id;
  std::array<std::uint8_t, 4> unk4;
  eldenring::cs::FieldInsHandle field_ins_handle;
  std::int32_t damage_taken;
  std::uint32_t unk14;
  std::array<std::uint8_t, 8> unk18;
};

enum class CSFeManHudState : std::uint8_t {
  HideAll = 0,
  ShowAll = 1,
  PopupMenu = 2,
  Default = 3,
};

struct CSFeManImp;

struct SummonMsgQueue;

struct SummonMsgData;

struct FrontEndViewValues;

struct MenuString;

struct TagHudData;

struct ChrFriendTagEntry;

struct ChrEnemyTagEntry;

}
}
}
