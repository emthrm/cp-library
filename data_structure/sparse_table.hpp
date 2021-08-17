#pragma once
#include <cassert>
#include <functional>
#include <vector>

template <typename Band>
struct SparseTable {
  using Fn = std::function<Band(Band, Band)>;

  SparseTable() {}

  SparseTable(const std::vector<Band> &a, Fn fn) { init(a, fn); }

  void init(const std::vector<Band> &a, Fn fn_) {
    is_built = true;
    fn = fn_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    while ((1 << table_h) <= n) ++table_h;
    dat.assign(table_h, std::vector<Band>(n));
    for (int j = 0; j < n; ++j) dat[0][j] = a[j];
    for (int i = 1; i < table_h; ++i) for (int j = 0; j + (1 << i) <= n; ++j) {
      dat[i][j] = fn(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
    }
  }

  Band query(int left, int right) const {
    assert(is_built && left < right);
    int h = lg[right - left];
    return fn(dat[h][left], dat[h][right - (1 << h)]);
  }

private:
  bool is_built = false;
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Band>> dat;
};
