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
namespace module {
namespace action_flag {

enum class WeaponModelChangeType : std::int8_t {
  MoveToDefaultLocation = 0,
  MoveTo1HRightWeaponLocation = 0,
  MoveTo1HLeftWeaponLocation = 1,
  MoveTo2HRightWeaponLocation = 2,
  MoveToSheathedLocation = 3,
  MaintainPreviousChange = 4,
  WeaponIdHardcoded = 5,
  Unknown6 = 6,
};

struct ChrActionModifiersFlags {
  std::uint64_t value;
};

struct ChrActionAnimationFlags {
  std::uint32_t value;
};

enum class SpEffectWetConditionDepth : std::uint8_t {
  Default = 0,
  LowerBody = 1,
  FullBody = 2,
};

struct CSChrActionFlagModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  eldenring::cs::chr_ins::module::action_flag::ChrActionAnimationFlags animation_action_flags;
  std::uint32_t unk14;
  std::uint32_t unk18_flags;
  std::uint8_t damage_level;
  std::uint32_t guard_level;
  std::array<std::uint8_t, 16> unk24;
  std::uint32_t received_damage_type;
  std::array<std::uint8_t, 8> unk38;
  eldenring::cs::chr_ins::module::action_flag::ChrActionModifiersFlags action_modifiers_flags;
  std::uint64_t unk48;
  std::uint64_t unk50;
  std::array<std::uint8_t, 16> unk58;
  std::uint8_t lh_model0_absorp_pos_param_condition;
  eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType lh_model0_change_type;
  std::uint8_t lh_model1_absorp_pos_param_condition;
  eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType lh_model1_change_type;
  std::uint8_t lh_model2_absorp_pos_param_condition;
  eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType lh_model2_change_type;
  std::uint8_t lh_model3_absorp_pos_param_condition;
  eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType lh_model3_change_type;
  std::uint8_t rh_model0_absorp_pos_param_condition;
  eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType rh_model0_change_type;
  std::uint8_t rh_model1_absorp_pos_param_condition;
  eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType rh_model1_change_type;
  std::uint8_t rh_model2_absorp_pos_param_condition;
  eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType rh_model2_change_type;
  std::uint8_t rh_model3_absorp_pos_param_condition;
  eldenring::cs::chr_ins::module::action_flag::WeaponModelChangeType rh_model3_change_type;
  bool weapon_model_location_overridden;
  std::array<std::uint8_t, 11> unk79;
  float turn_speed;
  float lock_on_turn_speed;
  float joint_turn_speed;
  std::int8_t global_turn_speed_priority;
  std::int8_t turn_speed_priority;
  std::int8_t lock_on_turn_speed_priority;
  std::int8_t joint_turn_speed_priority;
  float speed_default;
  float speed_extra;
  float speed_boost;
  float unka0;
  float unka4;
  float facing_angle_correction_rad;
  float root_motion_div;
  float root_motion_mult_min_dist;
  float root_motion_mult_max_dist;
  float root_motion_mult_angle_from_target;
  float root_motion_mult_target_radius;
  std::array<std::uint8_t, 272> unkc0;
  std::uint8_t unused_parry_window_arg;
  std::array<std::uint8_t, 15> unk1d1;
  float disable_lock_on_angle;
  std::int32_t camera_lock_on_param_id;
  std::array<std::uint8_t, 16> unk1e8;
  float mov_dist_multiplier;
  float cam_turn_dist_multiplier;
  float ladder_dist_multiplier;
  std::uint32_t guard_behavior_judge_id;
  float sa_durability_multiplier;
  eldenring::cs::chr_ins::module::action_flag::SpEffectWetConditionDepth sp_effect_wet_condition_depth;
  std::array<std::uint8_t, 7> unk20d;
  std::uint32_t unk214;
  float knockback_value;
  std::uint32_t action_flags;
  std::array<std::uint8_t, 24> unk220;
  std::int16_t bullet_aim_angle_up_limit;
  std::int16_t bullet_aim_angle_down_limit;
  std::int16_t bullet_aim_angle_right_limit;
  std::int16_t bullet_aim_angle_left_limit;
  std::int16_t bullet_aim_angle_up_dead_zone;
  std::int16_t bullet_aim_angle_down_dead_zone;
  std::int16_t bullet_aim_angle_right_dead_zone;
  std::int16_t bullet_aim_angle_left_dead_zone;
  std::array<std::uint8_t, 16> unk248;
};

}
}
}
}
}
