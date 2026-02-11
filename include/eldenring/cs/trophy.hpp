#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace trophy {

struct CSTrophyPlatformImp_forSteamAchievementItem {
  bool unlocked;
  std::array<std::uint16_t, 128> title;
};

struct CSTrophy;

struct CSTrophyPlatformImp;

struct CSTrophyTitleInfo;

struct CSTrophyPlatformImp_forSteam;

}
}
}
