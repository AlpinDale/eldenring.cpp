#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace team_relation {

struct TeamRelationTargetInfo {
  bool oppose_target;
  bool friendly_target;
  bool self_target;
};

struct CSTeamTypeBase;

struct CSTeamTypeNeutral;

struct CSTeamTypeFriend;

struct CSTeamTypeEnemy;

struct CSTeamTypeRival;

}
}
}
