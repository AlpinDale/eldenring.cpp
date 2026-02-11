#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace character_type_properties {

struct CharacterTypePropertiesEntry {
  bool include_in_ai_target_search;
  bool disable_behavior;
  bool can_use_item_lots;
  bool use_chr_based_sound_location;
  std::uint8_t unk4;
  std::uint8_t unk5;
  std::uint8_t unk6;
  bool is_host_like;
  bool can_receive_message_rate_buff;
  bool is_friendly_phantom;
  bool is_hostile_phantom;
  std::uint8_t unkb;
  eldenring::cs::ChrType post_revival_character_type;
  std::int32_t unk10;
};

struct CharacterTypePropertiesTable {
  std::array<eldenring::cs::character_type_properties::CharacterTypePropertiesEntry, 22> entries;
  eldenring::cs::character_type_properties::CharacterTypePropertiesEntry kw_default;
};

}
}
}
