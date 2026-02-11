#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace party_member_info {

enum class CeremonyState : std::uint32_t {
  Inactive = 0,
  Requested = 1,
  Loading = 2,
  Active = 3,
};

enum class PartyMemberEntryState : std::uint32_t {
  HostDefault = 0,
  Unk1 = 1,
  Unk2 = 2,
  Unk3 = 3,
  RemotePlayerDefault = 4,
  Dead = 5,
  DisconnectRequest = 6,
  DisconnectWait = 7,
  Unk8 = 8,
  Unk9 = 9,
};

enum class MemberType : std::uint32_t {
  Host = 0,
  RemotePlayer = 1,
  Npc = 2,
};

struct PartyMemberInfoEntry {
  eldenring::cs::FieldInsHandle field_ins_handle;
  eldenring::cs::party_member_info::MemberType member_type;
  eldenring::cs::party_member_info::PartyMemberEntryState state;
  std::uint32_t npc_invasion_event_flag;
  std::uint32_t npc_return_event_flag_id;
  float disconnect_request_delta_time;
  std::uint8_t unk1c;
  bool apply_multiplayer_rules;
  std::uint8_t unk1e;
  std::uint8_t unk1f;
  eldenring::cs::ChrType npc_chr_type;
  eldenring::cs::MultiplayRole npc_multiplay_role;
  std::uint8_t unk25;
  std::uint8_t unk26;
  std::uint8_t unk27;
  std::uint32_t npc_name_fmg_id;
  std::uint8_t unk2c;
  std::uint8_t unk2d;
  std::uint8_t unk2e;
  std::uint8_t unk2f;
};

struct PartyMemberInfo {
  std::uintptr_t vftable;
  std::int32_t friendly_phantom_count;
  std::int32_t hostile_phantom_count;
  std::int32_t in_world_online_player_count;
  std::int32_t in_world_players_count;
  std::int32_t non_npc_player_count;
  std::int32_t all_players_count;
  std::int32_t session_online_player_count;
  std::uint8_t unk24;
  std::uint8_t unk25;
  std::uint8_t unk26;
  std::uint8_t unk27;
  std::array<eldenring::cs::party_member_info::PartyMemberInfoEntry, 6> party_members;
  std::array<eldenring::cs::FieldInsHandle, 5> npc_host_entities;
  std::uint32_t npc_host_entity_count;
  eldenring::cs::party_member_info::CeremonyState pseudo_mp_ceremony_state;
  std::uint32_t pseudo_mp_host_entity_id;
  std::uint32_t pseudo_mp_event_flag;
  std::int32_t pseudo_mp_event_flag_unk180;
  std::int32_t pseudo_mp_event_text_for_map_id;
  eldenring::cs::SummonParamType summon_param_type;
  std::int8_t pseudo_mp_network_msg_npc_id;
  std::int32_t pseudo_mp_role_param_override;
  std::int32_t pseudo_mp_role_param_override_host;
  std::int32_t pseudo_mp_role_param_override_guest;
  eldenring::cs::MultiplayRole pseudo_mp_role_host;
  eldenring::cs::MultiplayRole pseudo_mp_role_guest;
  std::uint8_t unk19e;
  std::uint8_t unk19f;
  bool needs_update;
  bool npc_leave_requested;
  std::uint8_t unk1a2;
  std::uint8_t unk1a3;
  std::uint8_t unk1a4;
  std::uint8_t unk1a5;
  std::uint8_t unk1a6;
  std::uint8_t unk1a7;
};

}
}
}
