#pragma once

// THIS FILE IS AUTO-GENERATED. DO NOT EDIT OR FORMAT.

#include <cstdint>
#include <cstddef>
#include <array>
#include "eldenring/support.hpp"
#include "eldenring/fwd.hpp"

namespace eldenring {
namespace shared {
namespace dl_math {
namespace linear {

struct Triangle3 {
  eldenring::shared::dl_math::F32Vector3 origin;
  eldenring::shared::dl_math::F32Vector3 edge1;
  eldenring::shared::dl_math::F32Vector3 edge2;
};

struct Triangle {
  eldenring::shared::dl_math::F32Vector4 origin;
  eldenring::shared::dl_math::F32Vector4 edge1;
  eldenring::shared::dl_math::F32Vector4 edge2;
};

struct Obb {
  eldenring::shared::dl_math::F32Vector4 extents;
  eldenring::shared::dl_math::F32Matrix4x4 xform;
};

struct Aabb {
  eldenring::shared::dl_math::F32Vector4 min;
  eldenring::shared::dl_math::F32Vector4 max;
};

struct Sphere {
  eldenring::shared::dl_math::F32Vector4 sphere;
};

struct Plane {
  eldenring::shared::dl_math::F32Vector4 plane;
};

struct Frustum {
  std::array<eldenring::shared::dl_math::linear::Plane, 6> planes;
};

struct Rectangle {
  eldenring::shared::dl_math::F32Vector4 edge1;
  eldenring::shared::dl_math::F32Vector4 edge2;
  eldenring::shared::dl_math::F32Vector4 origin;
};

struct Rss {
  eldenring::shared::dl_math::linear::Rectangle rectangle;
  float radius;
};

struct Line {
  eldenring::shared::dl_math::F32Vector4 origin;
  eldenring::shared::dl_math::F32Vector4 dir;
};

struct Ray {
  eldenring::shared::dl_math::F32Vector4 origin;
  eldenring::shared::dl_math::F32Vector4 dir;
};

struct Segment {
  eldenring::shared::dl_math::F32Vector4 origin;
  eldenring::shared::dl_math::F32Vector4 dir;
};

struct Lss {
  eldenring::shared::dl_math::linear::Segment segment;
  float radius;
};

}
}
}
}
