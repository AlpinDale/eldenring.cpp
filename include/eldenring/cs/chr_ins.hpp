#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace chr_ins {

enum class ChrType : std::int32_t {
  None = 0,
  Local = 0,
  WhitePhantom = 1,
  Duelist = 2,
  Ghost = 3,
  Ghost1 = 4,
  Npc = 5,
  Unk6 = 6,
  Unk7 = 7,
  GrayPhantom = 8,
  Unk9 = 9,
  BloodstainGhost = 10,
  BonfireGhost = 11,
  Unk12 = 12,
  Arena = 13,
  MessageGhost = 14,
  BloodyFinger = 15,
  Recusant = 16,
  BluePhantom = 17,
  FesteringBloodyFinger = 18,
  WhiteSummonNpc = 19,
  BloodyFingerNpc = 20,
  RecusantNpc = 21,
  Unk22 = 22,
};

enum class HandIndex : std::uint32_t {
  Left = 0,
  Right = 1,
};

struct ChrCtrlChrProxyFlags {
  std::uint32_t value;
};

struct ChrCtrlFlags {
  std::uint32_t value;
};

struct ChrCtrlModifierHksFlags {
  std::uint32_t value;
};

struct ChrCtrlModifierActionFlags {
  std::uint32_t value;
};

enum class ChrMovementLimit : std::uint32_t {
  NoLimit = 0,
  LimitToDash = 1,
  LimitToWalking = 2,
  DisableAll = 3,
};

struct ChrCtrlModifierData {
  float unk0;
  std::int32_t unk4;
  std::int32_t unk8;
  std::uint8_t sp_regen_rate_percent;
  std::uint8_t fp_regen_rate_percent;
  eldenring::cs::chr_ins::ChrCtrlModifierActionFlags action_flags;
  eldenring::cs::chr_ins::ChrCtrlModifierHksFlags hks_flags;
  std::uint8_t unk18;
  std::uint8_t unk19;
  std::uint32_t unk1cflags;
  std::array<std::uint8_t, 4> unk20;
  float root_motion_reduction;
  std::array<std::uint8_t, 8> unk28;
  eldenring::cs::chr_ins::ChrMovementLimit movement_limit;
  std::array<std::uint8_t, 4> unk34;
};

struct ChrCtrlModifier {
  eldenring::cs::chr_ins::ChrCtrl* owner;
  eldenring::cs::chr_ins::ChrCtrlModifierData data;
};

struct ChrDebugFlags {
  std::uint32_t value;
};

struct ChrInsActivationFlags {
  std::uint32_t value;
};

struct ChrInsFlags1ca {
  std::uint8_t value;
};

struct NetChrSyncFlags {
  std::uint8_t value;
};

struct ChrInsFlags1c8 {
  std::uint8_t value;
};

struct ChrInsFlags1c7 {
  std::uint8_t value;
};

struct ChrInsFlags1c6 {
  std::uint8_t value;
};

struct ChrInsFlags1c5 {
  std::uint8_t value;
};

struct ChrInsFlags1c4 {
  std::uint8_t value;
};

enum class OmissionMode : std::int32_t {
  NoUpdate = 0,
  Normal = 0,
  OneFps = 1,
  FiveFps = 5,
  TwentyFps = 20,
  ThirtyFps = 30,
};

struct AtkParamLookupResult {
  std::int32_t behavior_param_id;
  std::uint32_t unk_param_def_meta;
  bool is_player_atk_param;
  std::array<std::uint8_t, 7> _pad9;
  eldenring::param::ATK_PARAM_ST* param_row;
};

struct P2PEntitySelector {
  std::uint32_t value;
};

struct P2PEntityHandle {
  eldenring::cs::BlockId block_id;
  eldenring::cs::chr_ins::P2PEntitySelector chr_selector;
};

struct ChrIns;

struct ChrCtrl;

struct CSModelIns;

struct CSFD4ModelItem;

struct CSFD4LocationGxModelMatricesAndAabbExporter;

struct CSChrModelIns;

struct PlayerIns;

struct ReplayRecorder;

struct EnemyIns;

struct PlayerSessionHolder;

}
}
}
