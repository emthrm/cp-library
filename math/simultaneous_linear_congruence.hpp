#pragma once
#include <algorithm>
#include <utility>
#include <vector>

#include "./mod_inv.hpp"

template <typename T>
std::pair<T, T> simultaneous_linear_congruence(const std::vector<T>& a,
                                               const std::vector<T>& b,
                                               const std::vector<T>& m) {
  const int n = a.size();
  T x = 0, md = 1;
  for (int i = 0; i < n; ++i) {
    const T p = md * a[i], q = -x * a[i] + b[i], g = std::__gcd(p, m[i]);
    if (q % g != 0) return {0, -1};
    const T m_i = m[i] / g;
    x += md * (q / g * mod_inv(p / g, m_i) % m_i);
    md *= m_i;
  }
  return {x < 0 ? x + md : x, md};
}
