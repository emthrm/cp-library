#ifndef EMTHRM_MISC_ROTATE_HPP_
#define EMTHRM_MISC_ROTATE_HPP_

#include <cassert>
#include <vector>

namespace emthrm {

template <int ANGLE, typename T>
std::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>& grid,
                                   const T space = ' ') {
  static_assert(ANGLE == 45 || ANGLE == 90);
  const int h = grid.size(), w = grid.front().size();
  std::vector<std::vector<T>> rotated_grid;
  if constexpr (ANGLE == 45) {
    rotated_grid.assign(h + w - 1, std::vector<T>(h + w - 1, space));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        rotated_grid[i + j][i - j + w - 1] = grid[i][j];
      }
    }
  } else {
    rotated_grid.assign(w, std::vector<T>(h));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        rotated_grid[w - 1 - j][i] = grid[i][j];
      }
    }
  }
  return rotated_grid;
}

}  // namespace emthrm

#endif  // EMTHRM_MISC_ROTATE_HPP_
