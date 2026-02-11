#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace menu_man {

struct FeSystemAnnounceViewModelMessageQueue {
  std::uintptr_t unk0;
  std::uintptr_t unk8;
  std::uintptr_t elements;
  std::uintptr_t capacity;
  std::uintptr_t unk20;
  std::uintptr_t count;
};

struct FeSystemAnnounceViewModel {
  std::uintptr_t menu_view_model;
  std::uintptr_t view;
  eldenring::cs::menu_man::FeSystemAnnounceViewModelMessageQueue message_queue;
};

struct LoadingScreenData {
  std::uintptr_t vftable;
  std::array<std::uint8_t, 32> unk8;
};

struct BackScreenData {
  std::uintptr_t vftable;
  std::array<std::uint8_t, 8> unk8;
};

struct ChrMenuFlags {
  std::uint32_t value;
};

struct CSChrMenuFlags {
  std::uintptr_t vftable;
  eldenring::cs::menu_man::ChrMenuFlags flags;
};

struct CSPlayerMenuCtrl {
  std::uintptr_t vftable;
  eldenring::cs::OptionalItemId selected_goods_item;
  eldenring::cs::OptionalItemId selected_magic_item;
  std::int32_t unk10;
  std::int32_t unk14;
  eldenring::cs::menu_man::CSChrMenuFlags chr_menu_flags;
  std::array<std::uint8_t, 32> unk28;
};

struct CSPopupMenu {
  std::uintptr_t vftable;
  eldenring::cs::menu_man::CSMenuManImp* menu_man;
  std::uintptr_t unk10;
  std::uintptr_t unk18;
  std::array<std::uint8_t, 144> unk20;
  std::uintptr_t current_top_menu_job;
  std::array<std::uint8_t, 176> unkb8;
  std::uint64_t input_data;
  std::array<std::uint8_t, 288> unk170;
  bool show_failed_to_save;
  std::array<std::uint8_t, 143> unkb91;
};

struct CSMenuGaitemUseState {
  std::uintptr_t vftable;
  std::uint32_t unk8;
  std::uint32_t quick_slot_item_id;
  std::uint32_t unk10;
  std::uint32_t unk14;
};

struct CSMenuData {
  std::uintptr_t vftable;
  std::array<std::uint8_t, 84> unk8;
  bool show_steam_names;
  std::array<std::uint8_t, 19> unk5d;
  eldenring::cs::menu_man::CSMenuGaitemUseState menu_gaitem_use_state;
  bool unk88;
  std::array<std::uint8_t, 103> unk89;
};

struct CSMenuManImp;

}
}
}
