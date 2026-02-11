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
namespace event {

struct CSChrEventModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  std::array<std::uint8_t, 8> unk10;
  std::int32_t request_animation_id;
  std::int32_t idle_anim_id;
  std::int32_t unk20;
  std::uint32_t unk24;
  std::int32_t ez_state_request_ladder;
  std::array<std::uint8_t, 11> unk2c;
  std::int32_t msg_map_list_call;
  std::uint32_t unk3c;
  std::uint8_t flags;
  std::array<std::uint8_t, 10> unk41;
  std::int32_t ez_state_request_ladder_output;
  std::array<std::uint8_t, 39> unk50;
};

}
}
}
}
}
