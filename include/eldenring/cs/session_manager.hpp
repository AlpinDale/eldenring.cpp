#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace session_manager {

struct CSSessionManagerP2PInboundQueueStats {
  std::uint32_t pending_packet_count;
  std::uint32_t pending_packet_bytes;
  std::uint32_t unk8;
  std::uint32_t unkc;
};

struct CSSessionManagerP2PSendQueueEntry {
  std::uint64_t recipient;
  std::uint8_t* packet_bytes;
  std::uint32_t packet_length;
  std::uint8_t packet_type;
  std::uint8_t unk15;
  std::uint16_t _pad16;
};

struct StayInMultiplayFadeTrackerEntry {
  std::uint64_t steam_id;
  float fade_time;
  std::array<std::uint8_t, 4> _pad;
};

enum class ProtocolState : std::uint32_t {
  Inactive = 0,
  Unk1 = 1,
  AwaitingWorldData = 2,
  Unk3 = 3,
  Unk4 = 4,
  Unk5 = 5,
  InWorld = 6,
  Unk7 = 7,
};

enum class LobbyState : std::uint32_t {
  None = 0,
  TryToCreateSession = 1,
  FailedToCreateSession = 2,
  Host = 3,
  TryToJoinSession = 4,
  FailedToJoinSesion = 5,
  Client = 6,
  OnLeaveSession = 7,
  FailedToLeaveSession = 8,
};

struct CSSessionManager;

struct SessionManagerPlayerEntryBase;

struct SessionManagerPlayerEntry;

struct CSStayInMultiplayAreaWarpData;

struct CSSessionManagerP2PSendQueue;

struct CSSessionManager0x20;

}
}
}
