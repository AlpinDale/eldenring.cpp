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
namespace behavior_data {

struct EnableTwistModifierArgs {
  float up_limit_angle;
  float down_limit_angle;
  float right_limit_angle;
  float left_limit_angle;
  std::uint32_t modifier_id;
  std::uint8_t target_type;
  std::uint8_t rank;
  float up_minimum_angle;
  float down_minimum_angle;
  float right_minimum_angle;
  float left_minimum_angle;
};

struct TwistModifierBehaviorData {
  float up_limit_angle;
  float down_limit_angle;
  float right_limit_angle;
  float left_limit_angle;
  float up_minimum_angle;
  float down_minimum_angle;
  float right_minimum_angle;
  float left_minimum_angle;
  std::int32_t modifier_id;
  std::int32_t target_type;
  std::uint8_t rank;
  eldenring::cs::chr_ins::module::behavior_data::EnableTwistModifierArgs* tae_event;
};

struct CSChrBehaviorDataModule;

}
}
}
}
}
