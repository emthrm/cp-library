#pragma once
#include <algorithm>
#include <cassert>
#include <iterator>
#include <vector>

template <typename T>
struct CumulativeSum2D {
  explicit CumulativeSum2D(const int h, const int w)
      : CumulativeSum2D(std::vector<std::vector<T>>(h, std::vector<T>(w, 0))) {}

  template <typename U>
  explicit CumulativeSum2D(const std::vector<std::vector<U>>& a)
      : is_built(false), h(a.size()), w(a.front().size()),
        data(h + 1, std::vector<T>(w + 1, 0)) {
    for (int i = 0; i < h; ++i) {
      std::copy(a[i].begin(), a[i].end(), std::next(data[i + 1].begin()));
    }
  }

  void add(const int y, const int x, const T val) {
    assert(!is_built);
    data[y + 1][x + 1] += val;
  }

  void build() {
    assert(!is_built);
    is_built = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        data[i + 1][j + 1] += data[i + 1][j];
      }
    }
    for (int j = 1; j <= w; ++j) {
      for (int i = 1; i < h; ++i) {
        data[i + 1][j] += data[i][j];
      }
    }
  }

  T query(const int y1, const int x1, const int y2, const int x2) const {
    assert(is_built);
    return y1 <= y2 && x1 <= x2 ? data[y2 + 1][x2 + 1] - data[y2 + 1][x1] - data[y1][x2 + 1] + data[y1][x1] : 0;
  }

private:
  bool is_built;
  const int h, w;
  std::vector<std::vector<T>> data;
};
