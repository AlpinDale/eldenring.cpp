#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace gxffx {

struct GXFfxSceneCtrl {
  std::uint64_t vftable;
  std::uint64_t sg_entity;
  std::uint64_t allocator;
  std::uint64_t ffx_manager;
  std::uint64_t unk;
  eldenring::gxffx::GXFfxGraphicsResourceManager* graphics_resource_manager;
};

struct FxrResourceContainer {
  std::uint64_t allocator1;
  eldenring::shared::owned_pointer::OwnedPtr<eldenring::gxffx::GXFfxSceneCtrl>* scene_ctrl;
  std::uint64_t unk10;
  eldenring::DoublyLinkedList<eldenring::gxffx::FxrListNode> fxr_definitions;
};

struct FxrWrapper {
  std::uintptr_t fxr;
  std::uint64_t unk;
};

struct FxrListNode;

struct GXFfxGraphicsResourceManager;

}
}
