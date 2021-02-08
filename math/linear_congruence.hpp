#pragma once
#include <algorithm>
#include <utility>
#include <vector>
#include "inverse_element/mod_inv_fermat.hpp"

template <typename T>
std::pair<long long, long long> linear_congruence(const std::vector<T> &a, const std::vector<T> &b, const std::vector<T> &m) {
  long long x = 0, mod = 1;
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    long long l = mod * a[i], r = -x * a[i] + b[i], g = std::__gcd(l, static_cast<long long>(m[i]));
    if (r % g != 0) return {0, -1};
    x += mod * (r / g * mod_inv_fermat(l / g, m[i] / g) % (m[i] / g));
    mod *= m[i] / g;
  }
  return {x < 0 ? x + mod : x, mod};
}
