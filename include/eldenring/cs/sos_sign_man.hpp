#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace sos_sign_man {

struct SteamIdStr {
  std::array<std::uint16_t, 17> _0;
};

enum class SummonJobErrorCode : std::int32_t {
  Default = 0,
  SignDataNotFound = 1,
  InvalidCoordinates = 2,
};

enum class PhantomJoinState : std::uint32_t {
  Waiting = 0,
  Joining = 1,
};

struct DisplayGhostData {
  std::array<std::int32_t, 12> equipment_param_ids;
  std::array<std::int32_t, 5> armor_param_ids;
  std::array<std::uint8_t, 4> unk44;
  std::uint8_t gender;
  std::array<std::uint8_t, 11> unk49;
  eldenring::cs::ChrAsmEquipment asm_equipment;
  eldenring::cs::FaceDataBuffer face_data;
};

struct CSSosSignSfx {
  std::int32_t sign_id;
  std::uintptr_t fxhgsfx;
};

struct CSSosSignMan {
  std::uintptr_t vftable;
  eldenring::Tree<eldenring::cs::sos_sign_man::SignTreeEntry> signs;
  eldenring::Tree<eldenring::cs::sos_sign_man::CSSosSignSfx> sign_sfx;
  eldenring::stl::DoublyLinkedList<std::int32_t> summon_requests;
  eldenring::cs::SummonParamType summon_param_type;
  std::array<std::uint8_t, 4> unk54;
  eldenring::stl::DoublyLinkedList<eldenring::cs::sos_sign_man::PhantomJoinData*> join_data;
  eldenring::stl::DoublyLinkedList<std::array<std::uint8_t, 40>> unk70;
  std::array<std::uint8_t, 8> unk88;
  std::uintptr_t display_ghost;
  eldenring::fd4::FD4Time timer;
  std::uint8_t white_sign_cool_time_param_id;
  std::uint32_t unkac;
  eldenring::Vector<float> signs_cooldown;
  bool override_guardian_of_rosalia_count_enabled;
  std::uint32_t override_guardian_of_rosalia_count;
  bool override_map_guardian_count_enabled;
  std::uint32_t override_map_guardian_count;
  bool override_force_join_black_count_enabled;
  std::uint32_t override_force_join_black_count;
  bool override_sinner_hunter_count_enabled;
  std::uint32_t override_sinner_hunter_count;
  bool override_berserker_white_count_enabled;
  std::uint32_t override_berserker_white_count;
  bool override_sinner_hero_count_enabled;
  std::uint32_t override_sinner_hero_count;
  bool override_cult_white_summon_count_enabled;
  std::uint32_t override_cult_white_summon_count;
  bool override_normal_white_count_enabled;
  std::uint32_t override_normal_white_count;
  bool override_red_summon_type_count_enabled;
  std::uint32_t override_red_summon_type_count;
};

struct SignTreeEntry;

struct SosSignData;

struct ObjectIdentifier;

struct PhantomJoinData;

}
}
}
