#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

namespace erd_example {

struct ModuleRange {
  uint8_t* base = nullptr;
  size_t size = 0;
};

ModuleRange get_module_range();
bool safe_read(uintptr_t addr, void* out, size_t size);
uintptr_t read_ptr(uintptr_t addr);
float read_f32(uintptr_t addr);
bool get_file_version(std::string& out);
void init_log_path(const char* filename);
void log_line(const char* fmt, ...);
const char* log_path();

template <typename T> bool safe_read(uintptr_t addr, T& out) {
  return safe_read(addr, &out, sizeof(T));
}

} // namespace erd_example
