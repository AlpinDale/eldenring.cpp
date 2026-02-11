#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace world_area_time {

enum class AiSightTimeOfDay : std::uint32_t {
  Morning = 0,
  Noon = 1,
  Evening = 2,
  Night = 3,
  Midnight = 4,
};

struct WorldAreaTime {
  eldenring::dlut::DLDateTime clock;
  eldenring::dlut::DLDateTime previous_tick_clock;
  float unk20;
  float unk24;
  std::uint32_t target_hour;
  std::uint32_t target_minute;
  std::uint32_t target_second;
  float unk34;
  float time_passage_multiplier;
  float unk3c;
};

}
}
}
