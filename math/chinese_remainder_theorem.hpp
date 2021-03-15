#pragma once
#include <algorithm>
#include <utility>
#include <vector>
#include "mod_inv.hpp"

template <typename T>
std::pair<T, T> chinese_remainder_theorem(std::vector<T> b, std::vector<T> m) {
  T x = 0, md = 1;
  int n = b.size();
  for (int i = 0; i < n; ++i) {
    if ((b[i] %= m[i]) < 0) b[i] += m[i];
    if (md < m[i]) {
      std::swap(x, b[i]);
      std::swap(md, m[i]);
    }
    if (md % m[i] == 0) {
      if (x % m[i] != b[i]) return {0, 0};
      continue;
    }
    T g = std::__gcd(md, m[i]);
    if ((b[i] - x) % g != 0) return {0, 0};
    T ui = m[i] / g;
    x += (b[i] - x) / g % ui * mod_inv(md / g, ui) % ui * md;
    md *= ui;
    if (x < 0) x += md;
  }
  return {x, md};
}
