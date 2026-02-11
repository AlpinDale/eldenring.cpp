#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace talk_script {

struct CSTalkIns {
  std::int32_t talk_id;
  std::int32_t unk4;
  std::int32_t unk8;
  std::int32_t unkc;
  std::int32_t unk10;
  std::uint8_t unk14;
  std::int32_t talk_interrupt_reason;
  std::int32_t talk_param_id;
  std::int32_t unk20;
  float unk24;
  std::int32_t unk28;
  bool unk2c;
  bool unk2d;
  bool unk2e;
  bool unk2f;
  bool unk30;
  std::int32_t unk34;
  bool unk38;
  bool unk39;
  bool unk3a;
  bool unk3b;
  eldenring::cs::FieldInsHandle field_ins_handle;
  std::uintptr_t unk48;
  float unk50;
  std::int32_t unk54;
  float unk58;
  std::int32_t event_flag_id;
  std::uint8_t unk60;
  std::int32_t unk64;
  std::uint8_t unk68;
  std::int32_t unk6c;
};

struct OpenMenuJob {
  eldenring::cs::MenuJobBase* finalize_callback_job;
  std::uint64_t input_data_count;
};

struct NpcMenuState {
  eldenring::cs::talk_script::OpenMenuJob open_menu_job;
  eldenring::cs::MenuType current_open_menu;
  eldenring::cs::talk_script::CSNpcTalkIns* owner;
};

struct TalkScriptMachineHolder {
  eldenring::ez_state::EzStateMachineImpl* machine;
  std::uintptr_t unk8;
  std::uintptr_t unk10;
  std::int32_t talk_id;
  eldenring::cs::FieldInsHandle field_ins_handle;
  bool unk24;
  eldenring::cs::talk_script::TalkScript* owner;
};

enum class EzStateInvokeError;

struct TalkScript;

struct CSNpcTalkIns;

}
}
}
