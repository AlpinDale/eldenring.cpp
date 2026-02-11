#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace world_chr_man_dbg {

struct WorldChrManDbgFlags {
  bool player_no_dead;
  bool player_horse_no_dead;
  bool player_exterminate;
  bool player_no_goods_consume;
  bool all_no_stamina_consume;
  bool all_no_mp_consume;
  bool all_no_arrow_consume;
  bool all_no_magic_qty_consume;
  bool unk8;
  bool unk9;
  bool all_no_dead;
  bool all_no_damage;
  bool all_no_hit;
  bool all_no_attack;
  bool all_no_move;
  std::uint8_t unkf;
  bool is_dbg_not_durability_loss_weapon_protector;
  bool is_no_arts_point_consume;
  bool enemy_no_goods_consume;
  bool auto_parry;
  bool enemy_no_draw;
  bool no_fp_aow;
  bool unk16;
  bool unk17;
  bool unk18;
  bool unk19;
  std::int32_t unk1c;
  std::int32_t unk20;
  std::uint8_t unk24;
  std::uint8_t unk25;
  std::uint8_t unk26;
  std::uint8_t unk27;
  bool unk28;
  bool unk29;
  bool unk2a;
  bool is_ignore_chr_disable_backread;
  std::uint8_t unk2c;
  bool tae_debug_enable_behavior_flag;
  bool tae_debug_enable_anime_play_spped;
  bool tae_debug_enable_test_param;
  bool tae_debug_enable_movement_adjustment;
  bool tae_debug_player_enable_behavior_flag;
  bool tae_debug_player_enable_anime_play_spped;
  bool tae_debug_player_enable_test_param;
  bool tae_debug_player_enable_movement_adjustment;
  std::uint8_t unk35;
  bool unk36;
  std::uint8_t unk37;
  std::uint8_t unk38;
  std::uint8_t unk39;
  std::int32_t unk3c;
  std::int32_t unk40;
};

enum class OmissionUpdateNumType : std::int32_t {
  None = 0,
  Normal = 0,
  Overload = 1,
  Emergency = 2,
};

struct OmissionUpdateNum {
  std::int32_t normal;
  std::int32_t overload;
  std::int32_t emergency;
};

struct WorldChrManDbg {
  std::uintptr_t vftable;
  std::uint8_t unk8;
  bool lod_level_debug_view;
  std::array<std::uint8_t, 18> unka;
  eldenring::cs::world_chr_man_dbg::OmissionUpdateNumType omission_update_num_type;
  eldenring::cs::world_chr_man_dbg::OmissionUpdateNumType omission_update_num_type_override;
  eldenring::cs::world_chr_man_dbg::OmissionUpdateNum omission_update_num_near;
  eldenring::cs::world_chr_man_dbg::OmissionUpdateNum omission_update_num_far;
  float close_omission_threshold;
  float offscreen_omission_distance;
  float omission_level_transition_distance;
  float update_priority_modifier_onscreen_recent;
  float update_priority_modifier_onscreen;
  float update_priority_modifier_npc;
  float update_priority_modifier_lower_body_turn_requested;
  float update_priority_default_modifier;
  float update_priority_modifier_is_moving;
  bool chr_update_state_reason_debug_view;
  std::array<std::uint8_t, 4> unk61;
  bool chr_dbg_draw_enable;
  std::uint8_t unk66;
  std::uint8_t unk67;
  bool toughness_debug_view;
  bool poise_debug_view;
  std::uint8_t unk6a;
  std::uint8_t unk6b;
  float unk6c;
  float unk70;
  float unk74;
  float unk78;
  float unk7c;
  float unk80;
  float unk84;
  float unk88;
  float unk8c;
  std::uint32_t unk90;
  float unk94;
  float unk98;
  float unk9c;
  float unka0;
  std::uint32_t unka4;
  std::uintptr_t debug_manipulator;
  eldenring::cs::PlayerSessionHolder* player_session_holder;
  eldenring::cs::ChrIns* cam_override_chr_ins;
  std::array<std::uint8_t, 20> unkc0;
  bool is_enable_default_bonfire_menu;
  std::array<std::uint8_t, 27> unkd5;
  std::uint32_t unkf0;
  std::array<std::uint8_t, 8> unkf4;
  std::uint32_t unkfc;
  bool chr_load_state_debug_view;
  float chr_activate_threshold_modifier_out_of_range;
  float chr_activate_threshold_modifier_visible_tag;
  std::array<std::uint8_t, 28> unk10c;
};

}
}
}
