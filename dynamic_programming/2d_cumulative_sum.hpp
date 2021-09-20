#pragma once
#include <cassert>
#include <vector>

template <typename T>
struct CumulativeSum2D {
  CumulativeSum2D(const int h, const int w)
  : CumulativeSum2D(std::vector<std::vector<T>>(h, std::vector<T>(w, 0))) {}

  template <typename U>
  CumulativeSum2D(const std::vector<std::vector<U>> &a) : h(a.size()), w(a.front().size()) {
    dat.assign(h + 1, std::vector<T>(w + 1, 0));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        dat[i + 1][j + 1] = a[i][j];
      }
    }
  }

  void add(const int y, const int x, const T val) {
    assert(!is_built);
    dat[y + 1][x + 1] += val;
  }

  void build() {
    assert(!is_built);
    is_built = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        dat[i + 1][j + 1] += dat[i + 1][j];
      }
    }
    for (int j = 1; j <= w; ++j) {
      for (int i = 1; i < h; ++i) {
        dat[i + 1][j] += dat[i][j];
      }
    }
  }

  T query(const int y1, const int x1, const int y2, const int x2) const {
    assert(is_built);
    return y1 <= y2 && x1 <= x2 ? dat[y2 + 1][x2 + 1] - dat[y2 + 1][x1] - dat[y1][x2 + 1] + dat[y1][x1] : 0;
  }

private:
  bool is_built = false;
  const int h, w;
  std::vector<std::vector<T>> dat;
};
