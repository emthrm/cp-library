#ifndef EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_
#define EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_

#include <algorithm>
#include <bit>
#include <cassert>
#include <functional>
#include <vector>

namespace emthrm {

template <typename Band>
struct SparseTable {
  using Fn = std::function<Band(Band, Band)>;

  SparseTable() = default;

  explicit SparseTable(const std::vector<Band>& a, const Fn fn) { init(a, fn); }

  void init(const std::vector<Band>& a, const Fn fn_) {
    fn = fn_;
    const int n = a.size();
    assert(n > 0);
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i >> 1] + 1;
    }
    const int table_h = std::countr_zero(std::bit_floor(a.size())) + 1;
    data.assign(table_h, std::vector<Band>(n));
    std::copy(a.begin(), a.end(), data.front().begin());
    for (int i = 1; i < table_h; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        data[i][j] = fn(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  Band query(const int left, const int right) const {
    assert(left < right);
    const int h = lg[right - left];
    return fn(data[h][left], data[h][right - (1 << h)]);
  }

 private:
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Band>> data;
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_
