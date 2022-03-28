#pragma once
#include <cassert>
#include <vector>

template <typename T>
std::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>& grid,
                                   const int angle, const T space = ' ') {
  const int h = grid.size(), w = grid.front().size();
  std::vector<std::vector<T>> rotated_grid;
  if (angle == 45) {
    rotated_grid.assign(h + w - 1, std::vector<T>(h + w - 1, space));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        rotated_grid[i + j][i - j + w - 1] = grid[i][j];
      }
    }
  } else if (angle == 90) {
    rotated_grid.assign(w, std::vector<T>(h));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        rotated_grid[w - 1 - j][i] = grid[i][j];
      }
    }
  } else {
    assert(false);
  }
  return rotated_grid;
}
