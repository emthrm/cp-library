/**
 * @brief 区間加算クエリ対応 Fenwick tree
 * @docs docs/data_structure/fenwick_tree/fenwick_tree.md
 */

#ifndef EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_SUPPORTING_RANGE_ADD_QUERY_HPP_
#define EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_SUPPORTING_RANGE_ADD_QUERY_HPP_

#include <vector>

namespace emthrm {

template <typename Abelian>
struct FenwickTreeSupportingRangeAddQuery {
  explicit FenwickTreeSupportingRangeAddQuery(
      const int n_, const Abelian ID = 0)
      : n(n_ + 1), ID(ID) {
    data_const.assign(n, ID);
    data_linear.assign(n, ID);
  }

  void add(int left, const int right, const Abelian val) {
    if (right < ++left) return;
    for (int i = left; i < n; i += i & -i) {
      data_const[i] -= val * (left - 1);
      data_linear[i] += val;
    }
    for (int i = right + 1; i < n; i += i & -i) {
      data_const[i] += val * right;
      data_linear[i] -= val;
    }
  }

  Abelian sum(const int idx) const {
    Abelian res = ID;
    for (int i = idx; i > 0; i -= i & -i) {
      res += data_linear[i];
    }
    res *= idx;
    for (int i = idx; i > 0; i -= i & -i) {
      res += data_const[i];
    }
    return res;
  }

  Abelian sum(const int left, const int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

 private:
  const int n;
  const Abelian ID;
  std::vector<Abelian> data_const, data_linear;
};

}  // namespace emthrm

#endif  // EMTHRM_DATA_STRUCTURE_FENWICK_TREE_FENWICK_TREE_SUPPORTING_RANGE_ADD_QUERY_HPP_
