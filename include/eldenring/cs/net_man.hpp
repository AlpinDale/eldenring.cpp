#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace net_man {

enum class QuickMatchArena : std::uint32_t {
  Invalid = 0,
  RoyalColosseum = 4500000,
  LimgraveColosseum = 4502000,
  CaelidColosseum = 4501000,
};

enum class QuickMatchVenue : std::uint32_t {
  Invalid = 0,
  RoyalColosseum = 1,
  LimgraveColosseum = 2,
  CaelidColosseum = 3,
};

struct QuickmatchParticipant {
};

struct QuickmatchSpawnData {
  eldenring::cs::BlockId block_id;
  eldenring::position::BlockPosition block_position;
  std::uint32_t role;
};

enum class QuickMatchSettings : std::uint32_t {
  Duel = 0,
  Brawl1v1 = 1,
  Brawl2v2 = 2,
  Brawl3v3 = 3,
  Team1v1 = 4,
  Team2v2 = 5,
  Team3v3 = 6,
  AlliesPasswordTeam1v1 = 7,
  AlliesPasswordTeam2v2 = 8,
  AlliesPasswordTeam3v3 = 9,
  SpiritAshesDuel = 10,
  SpiritAshesBrawl1v1 = 11,
  SpiritAshesBrawl2v2 = 12,
  SpiritAshesBrawl3v3 = 13,
  SpiritAshesTeam1v1 = 14,
  SpiritAshesTeam2v2 = 15,
  SpiritAshesTeam3v3 = 16,
  SpiritAshesAlliesPasswordTeam1v1 = 17,
  SpiritAshesAlliesPasswordTeam2v2 = 18,
  SpiritAshesAlliesPasswordTeam3v3 = 19,
};

struct CSQuickMatchContext {
  std::uintptr_t vtable;
  eldenring::cs::net_man::QuickMatchSettings match_settings;
  eldenring::cs::net_man::QuickMatchArena match_map;
  eldenring::cs::net_man::QuickmatchSpawnData spawn_data;
  eldenring::BasicVector<eldenring::cs::net_man::QuickMatchArena> arena_list;
  eldenring::Vector<std::uintptr_t> unk40;
  eldenring::Vector<std::uintptr_t> unk60;
  eldenring::stl::DoublyLinkedList<eldenring::cs::net_man::QuickmatchParticipant> participants;
  std::uint8_t unk98;
  std::uint8_t error_state;
  std::uint8_t unk9a;
  std::uint8_t unk9b;
  eldenring::cs::net_man::QuickMatchVenue venue;
  std::uint32_t unka0;
  std::uint32_t unka4;
  std::uint32_t unka8;
  std::uint32_t unkac;
};

enum class CSQuickMatchingCtrlState : std::uint32_t {
  None = 0,
  SearchRegister = 1,
  SearchRegisterWait = 2,
  GuestInviteWait = 3,
  GuestWaitSession = 4,
  GuestReadyWait = 5,
  GuestMoveMap = 6,
  GuestInGame = 7,
  HostWaitSession = 8,
  HostInvite = 9,
  HostReadyWait = 10,
  HostReadyWaitBlockList = 11,
  HostMoveMap = 12,
  HostInGame = 13,
  Unregister = 14,
};

struct CSNetBloodMessageDbItem {
  std::uintptr_t vftable;
  std::uint32_t unk8;
  std::uint32_t unkc;
  std::uint32_t unk10;
  eldenring::cs::BlockId block_id;
  std::uint32_t unk18;
  float position_x;
  float position_y;
  float position_z;
  float angle;
  std::uint16_t template1;
  std::uint16_t gesture_param;
  std::uint16_t part1;
  std::uint16_t infix;
  std::uint16_t template2;
  std::uint16_t part2;
  std::uint16_t unk38;
  std::uint16_t unk3a;
  std::uint16_t unk3c;
  std::uint16_t unk3e;
  std::uint64_t message_id;
  std::uint32_t unk48;
};

struct CSNetBloodMessageDb {
  std::uintptr_t vftable;
  eldenring::stl::DoublyLinkedList<eldenring::shared::owned_pointer::OwnedPtr<eldenring::cs::net_man::CSNetBloodMessageDbItem>> entries;
  std::uintptr_t unk20;
  eldenring::stl::DoublyLinkedList<std::uintptr_t> created_data;
  eldenring::stl::DoublyLinkedList<std::uintptr_t> unk40;
  std::uintptr_t unk58;
  std::uintptr_t blood_message_ins_man_1;
  std::uintptr_t blood_message_ins_man_2;
  eldenring::stl::DoublyLinkedList<eldenring::shared::owned_pointer::OwnedPtr<eldenring::shared::owned_pointer::OwnedPtr<eldenring::cs::net_man::CSNetBloodMessageDbItem>>> discovered_messages;
  std::array<std::uint8_t, 208> unk88;
  std::uintptr_t evaluate_job;
  std::uintptr_t unk160;
};

struct CSNetMan;

struct QuickmatchManager;

struct CSQuickMatchingCtrl;

struct CSBattleRoyalContext;

}
}
}
