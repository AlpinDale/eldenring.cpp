#include "example_util.h"

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <windows.h>

namespace erd_example {

namespace {
char g_log_path[MAX_PATH * 4] = "erd_example.log";
}

ModuleRange get_module_range() {
  HMODULE module = GetModuleHandleA(nullptr);
  if (!module) {
    return {};
  }

  auto* dos = reinterpret_cast<IMAGE_DOS_HEADER*>(module);
  if (dos->e_magic != IMAGE_DOS_SIGNATURE) {
    return {};
  }

  auto* nt =
      reinterpret_cast<IMAGE_NT_HEADERS*>(reinterpret_cast<uint8_t*>(module) + dos->e_lfanew);
  if (nt->Signature != IMAGE_NT_SIGNATURE) {
    return {};
  }

  ModuleRange range;
  range.base = reinterpret_cast<uint8_t*>(module);
  range.size = static_cast<size_t>(nt->OptionalHeader.SizeOfImage);
  return range;
}

bool safe_read(uintptr_t addr, void* out, size_t size) {
  if (!addr || !out || size == 0) {
    return false;
  }
#if defined(_MSC_VER)
  __try {
    std::memcpy(out, reinterpret_cast<void*>(addr), size);
    return true;
  } __except (EXCEPTION_EXECUTE_HANDLER) {
    return false;
  }
#else
  std::memcpy(out, reinterpret_cast<void*>(addr), size);
  return true;
#endif
}

uintptr_t read_ptr(uintptr_t addr) {
  uintptr_t out = 0;
  if (!safe_read(addr, &out, sizeof(out))) {
    return 0;
  }
  return out;
}

float read_f32(uintptr_t addr) {
  float out = 0.0f;
  if (!safe_read(addr, &out, sizeof(out))) {
    return 0.0f;
  }
  return out;
}

bool get_file_version(std::string& out) {
  char path[MAX_PATH * 4] = {};
  if (GetModuleFileNameA(nullptr, path, static_cast<DWORD>(sizeof(path))) == 0) {
    return false;
  }

  DWORD handle = 0;
  DWORD size = GetFileVersionInfoSizeA(path, &handle);
  if (size == 0) {
    return false;
  }

  std::string data;
  data.resize(size);
  if (!GetFileVersionInfoA(path, handle, size, data.data())) {
    return false;
  }

  VS_FIXEDFILEINFO* info = nullptr;
  UINT info_len = 0;
  if (!VerQueryValueA(data.data(), "\\", reinterpret_cast<void**>(&info), &info_len)) {
    return false;
  }
  if (!info || info_len < sizeof(VS_FIXEDFILEINFO)) {
    return false;
  }

  const DWORD ms = info->dwProductVersionMS;
  const DWORD ls = info->dwProductVersionLS;
  const DWORD major = HIWORD(ms);
  const DWORD minor = LOWORD(ms);
  const DWORD patch = HIWORD(ls);
  const DWORD build = LOWORD(ls);

  char buffer[64] = {};
  std::snprintf(buffer, sizeof(buffer), "%lu.%lu.%lu.%lu", static_cast<unsigned long>(major),
                static_cast<unsigned long>(minor), static_cast<unsigned long>(patch),
                static_cast<unsigned long>(build));
  out.assign(buffer);
  return true;
}

void init_log_path(const char* filename) {
  if (!filename || !*filename) {
    return;
  }

  char buf[MAX_PATH * 4] = {};
  DWORD len = GetEnvironmentVariableA("ERD_LAUNCHER_DIR", buf, static_cast<DWORD>(sizeof(buf)));
  if (len > 0 && len < sizeof(buf)) {
    std::snprintf(g_log_path, sizeof(g_log_path), "%s\\%s", buf, filename);
    return;
  }

  char mod_path[MAX_PATH * 4] = {};
  DWORD mod_len = GetModuleFileNameA(reinterpret_cast<HMODULE>(nullptr), mod_path,
                                     static_cast<DWORD>(sizeof(mod_path)));
  if (mod_len == 0 || mod_len >= sizeof(mod_path)) {
    std::snprintf(g_log_path, sizeof(g_log_path), "%s", filename);
    return;
  }
  std::string path(mod_path);
  size_t pos = path.find_last_of("\\/");
  if (pos == std::string::npos) {
    std::snprintf(g_log_path, sizeof(g_log_path), "%s", filename);
    return;
  }
  std::string dir = path.substr(0, pos);
  std::snprintf(g_log_path, sizeof(g_log_path), "%s\\%s", dir.c_str(), filename);
}

void log_line(const char* fmt, ...) {
  FILE* f = std::fopen(g_log_path, "a");
  if (!f) {
    return;
  }
  std::fprintf(f, "[ERD Example] ");
  va_list args;
  va_start(args, fmt);
  std::vfprintf(f, fmt, args);
  va_end(args);
  std::fputc('\n', f);
  std::fclose(f);
}

const char* log_path() {
  return g_log_path;
}

} // namespace erd_example
