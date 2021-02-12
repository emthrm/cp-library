/**
 * @brief binary indexed tree 区間加算版
 * @docs docs/data_structure/bit/bit.md
 */

#pragma once
#include <vector>

template <typename Abelian>
struct BITRangeAdd {
  BITRangeAdd(int n_, const Abelian ID = 0) : n(n_), ID(ID) {
    ++n;
    dat_const.assign(n, ID);
    dat_linear.assign(n, ID);
  }

  void add(int left, int right, Abelian val) {
    if (right < ++left) return;
    for (int i = left; i < n; i += i & -i) {
      dat_const[i] -= val * (left - 1);
      dat_linear[i] += val;
    }
    for (int i = right + 1; i < n; i += i & -i) {
      dat_const[i] += val * right;
      dat_linear[i] -= val;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    for (int i = idx; i > 0; i -= i & -i) res += dat_linear[i];
    res *= idx;
    for (int i = idx; i > 0; i -= i & -i) res += dat_const[i];
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat_const, dat_linear;
};
