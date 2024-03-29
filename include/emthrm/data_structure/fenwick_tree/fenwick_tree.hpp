#ifndef EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_HPP_
#define EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_HPP_

#include <bit>
#include <vector>

namespace emthrm {

template <typename Abelian>
struct FenwickTree {
  explicit FenwickTree(const int n, const Abelian ID = 0)
      : n(n), ID(ID), data(n, ID) {}

  void add(int idx, const Abelian val) {
    for (; idx < n; idx |= idx + 1) {
      data[idx] += val;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    for (--idx; idx >= 0; idx = (idx & (idx + 1)) - 1) {
      res += data[idx];
    }
    return res;
  }

  Abelian sum(const int left, const int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) [[unlikely]] return 0;
    int res = 0;
    for (int mask = std::bit_ceil(static_cast<unsigned int>(n + 1)) >> 1;
         mask > 0; mask >>= 1) {
      const int idx = res + mask - 1;
      if (idx < n && data[idx] < val) {
        val -= data[idx];
        res += mask;
      }
    }
    return res;
  }

 private:
  const int n;
  const Abelian ID;
  std::vector<Abelian> data;
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_HPP_
