#pragma once

#include "Vec3.h"
#include <limits>

class BlockPos {
public:
  int x = 0, y = 0, z = 0;
  // For ABI
  inline ~BlockPos() {}

  static BlockPos MIN;
  static BlockPos MAX;

  BlockPos operator+(BlockPos const &rhs) const noexcept { return {x + rhs.x, y + rhs.y, z + rhs.z}; }
  constexpr bool operator==(BlockPos const &rhs) const noexcept { return x == rhs.x && y == rhs.y && z == rhs.z; }
  constexpr bool operator!=(BlockPos const &rhs) const noexcept { return !(*this == rhs); }
  operator Vec3() { return {(float) x, (float) y, (float) z}; }
};

inline BlockPos BlockPos::MIN = {
    std::numeric_limits<int>::min(), std::numeric_limits<int>::min(), std::numeric_limits<int>::min()};
inline BlockPos BlockPos::MAX = {
    std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};