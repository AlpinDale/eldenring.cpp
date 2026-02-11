#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace multiplay_type {

struct MultiplayPropertyEntryFlags {
  std::uint32_t value;
};

enum class MatchingCooldownType : std::int32_t {
  None = 0,
  Invasion = 0,
  ForestMapInvasion = 1,
  AnorMapInvasion = 2,
  BlueHunter = 3,
};

enum class JoinType : std::uint32_t {
  FriendlySign = 0,
  HostileSign = 1,
  ForceJoin = 3,
};

enum class SummonParamType : std::int32_t {
  NpcPseudoInvasionSessionGuest = 0,
  NpcPseudoInvasionSessionHost = 1,
  RedHunt2 = 2,
  NpcPseudoPhantasmEvent = 3,
  NpcPseudoInvasionB = 4,
  NpcPseudoInvasionA = 5,
  NpcPseudoWhiteSpirit = 6,
  RedInvasionCNpc = 7,
  RedInvasionBNpc = 8,
  RedInvasionANpc = 9,
  WhiteSummonNpc = 10,
  BerserkerSpiritInvasion = 11,
  SunSpiritInvasion = 12,
  BerserkerSpiritRedSign = 13,
  SunSpiritRedSign = 14,
  SunSpiritWhiteSign = 15,
  BattleRoyale = 16,
  AvatarBattle = 17,
  AnorMapGuardian = 18,
  ForestMapGuardian = 19,
  RosariaGuardian = 20,
  RedHunt = 21,
  SinnerHunt = 22,
  BerserkerWhite = 23,
  RedInvasionB = 24,
  RedInvasionALimited = 25,
  RedInvasionA = 26,
  RedSummon = 27,
  Summon = 28,
  Host = 0,
};

enum class MultiplayRole : std::uint8_t {
  Host = 0,
  WhiteSummon = 1,
  RedSummon = 2,
  RedInvasionA = 3,
  RedInvasionALimited = 4,
  RedInvasionB = 5,
  BerserkerWhite = 6,
  RedHunt = 7,
  SinnerHeroWhite = 8,
  SinnerHunt = 9,
  RosariaGuardian = 10,
  ForestMapGuardian = 11,
  AnorMapGuardian = 12,
  AvatarBattle = 13,
  BattleRoyale = 14,
  RitualSummon = 15,
  SunSpiritWhiteSign = 16,
  SunSpiritRedSign = 17,
  BerserkerSpiritRedSign = 18,
  SunSpiritInvasion = 19,
  BerserkerSpiritInvasion = 20,
  WhiteSummonNpc = 21,
  RedInvasionANpc = 22,
  RedInvasionBNpc = 23,
  RedInvasionCNpc = 24,
  NpcPseudoWhiteSpirit = 25,
  NpcPseudoInvasionA = 26,
  NpcPseudoInvasionB = 27,
  NpcPseudoPhantasmEvent = 28,
  RedHunt2 = 29,
  NpcPseudoInvasionSessionHost = 30,
  NpcPseudoInvasionSessionGuest = 31,
};

struct MultiplayPropertyEntry {
  std::int32_t unk0;
  eldenring::cs::multiplay_type::SummonParamType summon_param_type;
  eldenring::cs::ChrType chr_type;
  eldenring::cs::multiplay_type::MultiplayRole multiplay_role;
  eldenring::cs::multiplay_type::JoinType join_type;
  std::int32_t unk14;
  std::int32_t unk18;
  std::int32_t unk1c;
  std::int32_t unk20;
  eldenring::cs::multiplay_type::MatchingCooldownType matching_cooldown_type;
  std::int32_t other_sign_interaction_fmg_id;
  std::int32_t self_sign_interaction_fmg_id;
  eldenring::cs::FullScreenMessage kill_full_screen_message;
  eldenring::cs::multiplay_type::MultiplayPropertyEntryFlags flags;
  const std::uint16_t* debug_name;
};

struct MultiplayProperties {
  std::array<eldenring::cs::multiplay_type::MultiplayPropertyEntry, 31> entries;
};

enum class MultiplayType : std::uint8_t {
  WhiteSummon = 0,
  RedInvasionA = 1,
  RedSummon = 2,
  RedInvasionALimited = 3,
  RedInvasionB = 4,
  BerserkerWhite = 5,
  SinnerHeroWhite = 6,
  SinnerHunt = 7,
  RedHunt = 8,
  RosariaGuardian = 9,
  ForestMapGuardian = 10,
  AnorMapGuardian = 11,
  AvatarBattle = 12,
  BattleRoyale = 13,
  RitualSummon = 14,
  SunSpiritWhiteSign = 15,
  SunSpiritRedSign = 16,
  BerserkerSpiritRedSign = 17,
  SunSpiritInvasion = 18,
  BerserkerSpiritInvasion = 19,
  WhiteSummonNpc = 20,
  RedInvasionANpc = 21,
  RedInvasionBNpc = 22,
  RedInvasionCNpc = 23,
  NpcPseudoWhiteSpirit = 24,
  NpcPseudoInvasionA = 25,
  NpcPseudoInvasionB = 26,
  NpcPseudoPhantasmEvent = 27,
  RedHunt2 = 28,
  NpcPseudoInvasionSessionHost = 29,
  NpcPseudoInvasionSessionGuest = 30,
  None = 31,
};

}
}
}
