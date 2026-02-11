#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace fd4 {
namespace task {

struct FD4TaskRequestEntry {
  eldenring::fd4::task::FD4TaskBase* task;
};

struct FD4TaskGroup {
  std::uintptr_t vftable;
};

struct FD4TaskQueue {
  std::uintptr_t vftable;
  std::uintptr_t allocator;
  eldenring::Tree<eldenring::fd4::task::FD4TaskGroup> entries_tree;
  eldenring::Vector<eldenring::fd4::task::FD4TaskGroup> entries_vector;
};

struct FD4TaskData {
  eldenring::fd4::FD4Time delta_time;
  std::uint32_t task_group_id;
  std::int32_t seed;
};

struct FD4TaskBase;

}
}
}
