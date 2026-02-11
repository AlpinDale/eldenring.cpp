#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace dlcr {

struct CryptoSPIRegistry {
  eldenring::Vector<eldenring::dlcr::DLKeyGeneratorSPI*> key_generators;
  eldenring::Vector<eldenring::dlcr::DLCipherSPI*> cipher_spis;
};

struct OpenSslAesCipher {
  eldenring::dlcr::DLCipherKey* cipher_key;
  std::uint32_t cipher_mode;
  std::uint32_t padding_mode;
  std::uint32_t key_usage;
  eldenring::dlkr::DLAllocatorBase* allocator;
  std::uintptr_t evp_cipher;
  std::uintptr_t evp_cipher_ctx;
  bool requires_iv;
  bool padding_enabled;
};

enum class KeyType : std::uint16_t {
  Common = 0,
  Public = 1,
  Private = 2,
};

enum class KeyUsageType : std::uint16_t {
  Null = 0,
  Default = 1,
};

enum class CipherPaddingMode : std::uint16_t {
  None = 0,
  Pkcs5 = 1,
};

enum class CipherType : std::uint16_t {
  Null = 0,
  Aes = 1,
  OpenSslAES = 2,
  OpenSslRsa = 3,
};

enum class CipherMode : std::uint16_t {
  Null = 0,
  Cbc = 1,
  Ecb = 2,
  Cfb = 3,
  Ofb = 4,
  CtrNw = 5,
};

struct CipherInitParams {
  std::array<std::uint8_t, 4> magic;
  std::uint32_t version;
  std::uint32_t mode;
  eldenring::dlcr::CipherType cipher_type;
  eldenring::dlcr::CipherMode cipher_mode;
  eldenring::dlcr::CipherPaddingMode padding_mode;
  eldenring::dlcr::KeyUsageType key_usage;
  eldenring::dlcr::KeyType key_type;
  std::uint16_t reserved;
  std::uint64_t reserved2;
};

enum class CryptoKeyType : std::uint16_t {
  Null = 0,
  Cerial = 1,
};

struct CryptoKeyParams {
  std::array<std::uint8_t, 4> magic;
  std::uint32_t version;
  eldenring::dlcr::CryptoKeyType key_type;
};

struct DLRijndaelAlgorithm {
  std::uintptr_t vftable;
};

struct DLCipherKey;

struct DLSerialCipherKey;

struct AESEncrypter;

struct AESDecrypter;

struct DLDecrypter;

struct OpenSslAesDecrypter;

struct OpenSslRsaCipher;

struct OpenSslRsaDecrypter;

struct DLCipherSPI;

struct DLKeyGeneratorSPI;

}
}
