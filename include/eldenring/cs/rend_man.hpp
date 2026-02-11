#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace rend_man {

struct EzDrawFlags {
  std::uint32_t value;
};

enum class EzDrawTextCoordMode : std::uint32_t {
  ScreenSpace0 = 0,
  ScreenSpace1 = 1,
  HavokPosition2 = 2,
  HavokPosition3 = 3,
  Normalized1080p = 4,
  Normalized4k = 5,
};

enum class EzDrawFillMode : std::uint32_t {
  Fill = 0,
  Wireframe = 1,
};

struct DlColor32 {
  std::uint32_t value;
};

struct FD4HkEzDrawContext {
  std::uintptr_t vftable;
  std::uintptr_t unk8;
  std::uintptr_t unk10;
  eldenring::cs::rend_man::FD4HkEzDrawState* ez_draw_state;
  std::uintptr_t unk20;
  bool unk28;
  std::uint32_t unk2c;
  eldenring::dlkr::DLAllocatorBase* unk30;
};

struct RendMan;

struct CSEzDraw;

struct FD4HkEzDrawCommandBuffer;

struct FD4EzDrawState;

struct FD4HkEzDrawState;

}
}
}
