#pragma once
#include <algorithm>
#include <bitset>
#include <iterator>
#include <vector>

template <int D>
struct Basis {
  std::vector<std::bitset<D>> v;
  std::vector<int> msb;

  Basis() = default;

  bool add(std::bitset<D> val) {
    const int n = rank();
    if (n == D) return false;
    for (int i = 0; i < n; ++i) {
      if (val[msb[i]]) val ^= v[i];
    }
    if (val.none()) return false;
    int m = D - 1;
    while (!val[m]) --m;
    if (v.empty()) {
      v.emplace_back(val);
      msb.emplace_back(m);
      return true;
    }
    const int idx = std::distance(std::upper_bound(msb.rbegin(), msb.rend(), m),
                                  msb.rend());
    v.emplace(std::next(v.begin(), idx), val);
    msb.emplace(std::next(msb.begin(), idx), m);
    for (int i = idx + 1; i <= n; ++i) {
      if (v[idx][msb[i]]) v[idx] ^= v[i];
    }
    for (int i = idx - 1; i >= 0; --i) {
      if (v[i][m]) v[i] ^= v[idx];
    }
    return true;
  }

  int rank() const { return v.size(); }

  inline bool operator<(const Basis& x) const {
    const int n = v.size();
    if (n != x.rank()) return n < x.rank();
    if (n == D) return false;
    for (int i = 0; i < n; ++i) {
      if (msb[i] != x.msb[i]) return msb[i] < x.msb[i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = msb[i] - 1; ; --j) {
        if (v[i][j] != x.v[i][j]) return x.v[i][j];
      }
    }
    return false;
  }
};
