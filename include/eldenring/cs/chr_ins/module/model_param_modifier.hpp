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
namespace model_param_modifier {

struct CSChrModelParamModifierModuleEntryValue {
  std::uint32_t unk0;
  float value1;
  float value2;
  float value3;
  float value4;
  std::uint32_t unk14;
};

struct CSChrModelParamModifierModule {
  std::uintptr_t vftable;
  eldenring::cs::ChrIns* owner;
  eldenring::Vector<eldenring::cs::chr_ins::module::model_param_modifier::CSChrModelParamModifierModuleEntry> modifiers;
};

struct CSChrModelParamModifierModuleEntry;

}
}
}
}
}
