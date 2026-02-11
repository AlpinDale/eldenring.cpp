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
namespace time_act {

struct CSChrTimeActModuleAnim {
  std::int32_t anim_id;
  float play_time;
  float play_time2;
  float anim_length;
};

struct CSChrTimeActModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  std::uintptr_t hvk_anim;
  std::uintptr_t chr_tae_anim_event;
  std::array<eldenring::cs::chr_ins::module::time_act::CSChrTimeActModuleAnim, 10> anim_queue;
  std::uint32_t write_idx;
  std::uint32_t read_idx;
  std::uint32_t unkc8;
  std::uint32_t unkcc;
  std::uint32_t unkd0;
  std::uint32_t unkd4;
};

}
}
}
}
}
