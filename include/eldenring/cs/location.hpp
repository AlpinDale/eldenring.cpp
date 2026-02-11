#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace location {

struct CSFD4LocationNode {
  eldenring::cs::location::CSFD4LocationPose* owner;
  eldenring::cs::location::CSFD4LocationNode* prev;
  eldenring::cs::location::CSFD4LocationNode* next;
  eldenring::cs::location::CSFD4LocationNode* unk18;
};

struct CSFD4LocationPose;

}
}
}
