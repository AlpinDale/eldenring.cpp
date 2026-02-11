#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace dltx {

enum class DLCharacterSet : std::uint8_t {
  UTF8 = 0,
  UTF16 = 1,
  Iso8859_1 = 2,
  ShiftJis = 3,
  EucJp = 4,
  UTF32 = 5,
};

template <typename T>
struct DLRawString {
  std::uintptr_t vftable;
  typename T::CharType* backing_string;
  std::uintptr_t length;
  std::uint32_t unk18;
  std::uint16_t char_size;
  eldenring::dltx::DLCharacterSet encoding;
  std::uint8_t flags;
};

enum class DLStringEncodingError;

struct DLUTF8StringKind;

struct DLISO8859_1StringKind;

struct DLShiftJisStringKind;

struct DLEucJpStringKind;

struct DLUTF16StringKind;

struct DLUTF32StringKind;

template <typename T>
struct DLString;

template <typename T, typename N>
struct DLInplaceStr;

}
}
