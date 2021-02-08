/**
 * @brief 添え字 xor での畳み込み
 * @docs docs/math/convolution/convolution.md
 */

#pragma once
#include <vector>

template <typename T>
std::vector<T> xor_convolution(const std::vector<T> &a, const std::vector<T> &b, const T UNITY = 0) {
  auto fwht = [&](std::vector<T> v) -> std::vector<T> {
    int n = v.size(), p = 1;
    while ((1 << p) < n) ++p;
    n = 1 << p;
    v.resize(n, UNITY);
    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {
      if ((j & i) == 0) {
        T tmp1 = v[j], tmp2 = v[j | i];
        v[j] = tmp1 + tmp2;
        v[j | i] = tmp1 - tmp2;
      }
    }
    return v;
  };
  std::vector<T> fwht_a = fwht(a), fwht_b = fwht(b);
  int n = fwht_a.size();
  for (int i = 0; i < n; ++i) fwht_a[i] *= fwht_b[i];
  std::vector<T> res = fwht(fwht_a);
  for (int i = 0; i < n; ++i) res[i] /= n;
  return res;
}
