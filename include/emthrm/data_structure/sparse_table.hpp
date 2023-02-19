#ifndef EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_
#define EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

namespace emthrm {

template <typename Band>
struct SparseTable {
  using BinOp = std::function<Band(Band, Band)>;

  SparseTable() = default;

  explicit SparseTable(const std::vector<Band>& a, const BinOp bin_op) {
    init(a, bin_op);
  }

  void init(const std::vector<Band>& a, const BinOp bin_op_) {
    bin_op = bin_op_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i >> 1] + 1;
    }
    while ((1 << table_h) <= n) ++table_h;
    data.assign(table_h, std::vector<Band>(n));
    std::copy(a.begin(), a.end(), data.front().begin());
    for (int i = 1; i < table_h; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        data[i][j] = bin_op(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  Band query(const int left, const int right) const {
    assert(left < right);
    const int h = lg[right - left];
    return bin_op(data[h][left], data[h][right - (1 << h)]);
  }

 private:
  BinOp bin_op;
  std::vector<int> lg;
  std::vector<std::vector<Band>> data;
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_
