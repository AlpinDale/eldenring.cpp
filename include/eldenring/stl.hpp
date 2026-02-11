#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace stl {

struct AllocationHeader {
  eldenring::stl::AllocationHeader* self_ptr;
  std::uintptr_t count;
};

template <typename T>
struct ArrayWithHeader {
  T first_item;
};

template <typename T>
struct CSFixedListEntry {
  T data;
  eldenring::stl::CSFixedListEntry<T>* next;
  eldenring::stl::CSFixedListEntry<T>* previous;
  std::uintptr_t index;
};

template <typename K, typename V>
struct Pair {
  K key;
  V value;
};

template <typename T>
struct ChainingMapBucketEntry {
  T data;
  eldenring::stl::ChainingMapBucketEntry<T>* next;
};

template <typename T>
struct TreeNode {
  eldenring::stl::TreeNode<T>* left;
  eldenring::stl::TreeNode<T>* parent;
  eldenring::stl::TreeNode<T>* right;
  std::uint8_t black_red;
  std::uint8_t is_nil;
  T value;
};

template <typename T>
struct Tree {
  std::uintptr_t allocator;
  eldenring::stl::TreeNode<T>* head;
  std::uintptr_t size;
};

template <typename T>
struct BasicVector {
  T* begin;
  T* end;
  T* capacity;
};

template <typename T>
struct Vector {
  eldenring::dlkr::DLAllocatorBase* allocator;
  eldenring::stl::BasicVector<T> base;
};

template <typename T>
struct DoublyLinkedList {
  std::uintptr_t allocator;
  eldenring::stl::DoublyLinkedListNode<T>* head;
  std::uint64_t count;
};

template <typename T>
struct DoublyLinkedListNode {
  eldenring::stl::DoublyLinkedListNode<T>* next;
  eldenring::stl::DoublyLinkedListNode<T>* previous;
  T value;
};

template <typename K, typename V>
struct ChainingTree;

template <typename T, typename N>
struct CSFixedList;

}
}
