#pragma once
#include <algorithm>
#include <utility>
#include <vector>
#include "mod_inv.hpp"

template <typename T>
std::pair<T, T> simultaneous_linear_congruence(const std::vector<T> &a, const std::vector<T> &b, const std::vector<T> &m) {
  const int n = a.size();
  T x = 0, md = 1;
  for (int i = 0; i < n; ++i) {
    const T l = md * a[i], r = -x * a[i] + b[i], g = std::__gcd(l, m[i]);
    if (r % g != 0) return {0, -1};
    x += md * (r / g * mod_inv(l / g, m[i] / g) % (m[i] / g));
    md *= m[i] / g;
  }
  return {x < 0 ? x + md : x, md};
}
