#ifndef EMTHRM_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP_
#define EMTHRM_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP_

#include <algorithm>
#include <cassert>
#include <vector>

namespace emthrm {

template <typename Semigroup, typename Fn>
struct DisjointSparseTable {
  explicit DisjointSparseTable(const std::vector<Semigroup>& a, const Fn fn)
      : fn(fn) {
    const int n = a.size();
    int table_h = 1;
    while ((1 << table_h) < n) ++table_h;
    lg.assign(1 << table_h, 0);
    for (int i = 2; i < (1 << table_h); ++i) {
      lg[i] = lg[i >> 1] + 1;
    }
    data.assign(table_h, std::vector<Semigroup>(n));
    std::copy(a.begin(), a.end(), data.front().begin());
    for (int i = 1; i < table_h; ++i) {
      const int shift = 1 << i;
      for (int left = 0; left < n; left += shift << 1) {
        const int mid = std::min(left + shift, n);
        data[i][mid - 1] = a[mid - 1];
        for (int j = mid - 2; j >= left; --j) {
          data[i][j] = fn(a[j], data[i][j + 1]);
        }
        if (n <= mid) break;
        const int right = std::min(mid + shift, n);
        data[i][mid] = a[mid];
        for (int j = mid + 1; j < right; ++j) {
          data[i][j] = fn(data[i][j - 1], a[j]);
        }
      }
    }
  }

  Semigroup query(const int left, int right) const {
    assert(left < right);
    if (left == --right) return data[0][left];
    const int h = lg[left ^ right];
    return fn(data[h][left], data[h][right]);
  }

 private:
  const Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Semigroup>> data;
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP_
