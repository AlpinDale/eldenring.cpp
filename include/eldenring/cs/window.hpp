#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace cs {
namespace window {

enum class GrassQuality : std::uint32_t {
  Medium = 2,
  High = 3,
  Maximum = 4,
};

enum class QualitySetting : std::uint32_t {
  Low = 1,
  Medium = 2,
  High = 3,
  Maximum = 4,
  Custom = 5,
};

enum class FpsTarget : std::uint32_t {
  FPS30 = 0,
  FPS60 = 1,
  FPS85 = 2,
  FPS120 = 3,
};

enum class OnOffSetting : std::uint32_t {
  Off = 0,
  On = 1,
};

enum class ToggleableGraphicsQuality : std::uint32_t {
  Off = 0,
  Low = 1,
  Medium = 2,
  High = 3,
  Maximum = 4,
};

enum class QualityLevelSetting : std::uint32_t {
  Low = 0,
  Medium = 1,
  High = 2,
  Maximum = 3,
};

enum class CSWindowType : std::uint32_t {
  Windowed = 0,
  Fullscreen = 1,
  Borderless = 2,
};

struct CSWindowScreenConfig {
  std::int32_t windowed_screen_width;
  std::int32_t windowed_screen_height;
  std::int32_t fullscreen_width;
  std::int32_t fullscreen_height;
  std::int32_t borderless_screen_width;
  std::int32_t borderless_screen_height;
  eldenring::cs::window::CSWindowType window_type;
  eldenring::cs::window::OnOffSetting auto_detect_best_setting;
  eldenring::cs::window::FpsTarget fps_target;
  eldenring::cs::window::QualitySetting quality_setting;
  eldenring::cs::window::QualityLevelSetting texture_quality;
  eldenring::cs::window::ToggleableGraphicsQuality antialiasing_quality;
  eldenring::cs::window::ToggleableGraphicsQuality ssao;
  eldenring::cs::window::ToggleableGraphicsQuality dof;
  eldenring::cs::window::ToggleableGraphicsQuality motion_blur;
  eldenring::cs::window::QualityLevelSetting shadow_quality;
  eldenring::cs::window::QualityLevelSetting lighting_quality;
  eldenring::cs::window::QualityLevelSetting effects_quality;
  eldenring::cs::window::QualityLevelSetting reflection_quality;
  eldenring::cs::window::QualityLevelSetting water_surface_quality;
  eldenring::cs::window::QualityLevelSetting shader_quality;
  eldenring::cs::window::QualityLevelSetting volumetric_quality;
  eldenring::cs::window::ToggleableGraphicsQuality ray_tracing_quality;
  eldenring::cs::window::QualityLevelSetting gi_quality;
  eldenring::cs::window::GrassQuality grass_quality;
};

struct CSWindowImp;

}
}
}
