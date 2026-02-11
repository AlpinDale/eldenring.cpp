#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace fade {

struct CSFD4FadePlateColor {
  float r;
  float g;
  float b;
  float a;
};

struct CSFD4FadePlate {
  std::uintptr_t vftable;
  std::uint32_t reference_count;
  std::uint32_t _padc;
  eldenring::cs::fade::CSFD4FadePlateColor current_color;
  eldenring::cs::fade::CSFD4FadePlateColor start_color;
  eldenring::cs::fade::CSFD4FadePlateColor end_color;
  eldenring::fd4::FD4Time fade_timer;
  eldenring::fd4::FD4Time fade_duration;
  std::uint8_t unk60;
  std::array<std::uint8_t, 7> _pad64;
  std::uintptr_t allocator;
  std::array<std::uint16_t, 8> title;
  std::uint64_t unk80;
  std::uint64_t unk88;
  std::uint64_t unk90;
  std::uint64_t unk98;
  std::uint64_t unka0;
  eldenring::fd4::FD4Time unka8;
  std::uint64_t unkb8;
};

struct CSFD4FadeSystem {
  std::uintptr_t vftable;
};

struct CSFade;

}
}
}
