#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_BERLEKAMP_MASSEY_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_BERLEKAMP_MASSEY_HPP_

#include <vector>

namespace emthrm {

template <typename T>
std::vector<T> berlekamp_massey(const std::vector<T>& s) {
  const int n = s.size();
  std::vector<T> b{1}, c{1};
  b.reserve(n);
  c.reserve(n + 1);
  int m = b.size(), l = c.size(), f = -1;
  T prv_delta = 1;
  for (int i = 0; i < n; ++i) {
    T delta = s[i];
    for (int j = 1; j < l; ++j) {
      delta += c[j] * s[i - j];
    }
    if (delta == 0) continue;
    const T mul = -delta / prv_delta;
    const int shift = i - f;
    if (m + shift > l) {
      l = m + shift;
      const std::vector<T> nxt_b = c;
      c.resize(l, 0);
      for (int j = 0; j < m; ++j) {
        c[l - 1 - j] += mul * b[m - 1 - j];
      }
      b = nxt_b;
      m = b.size();
      f = i;
      prv_delta = delta;
    } else {
      for (int j = 0; j < m; ++j) {
        c[shift + j] += mul * b[j];
      }
    }
  }
  return c;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_BERLEKAMP_MASSEY_HPP_
