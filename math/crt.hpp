#pragma once
#include <algorithm>
#include <utility>
#include <vector>
#include "ext_gcd.hpp"

template <typename T>
std::pair<T, T> crt(const std::vector<T> &b, const std::vector<T> &m) {
  T x = 0, md = 1;
  int n = b.size();
  for (int i = 0; i < n; ++i) {
    T g = std::__gcd(md, m[i]);
    if ((b[i] - x) % g != 0) return {0, -1};
    x += md * ((b[i] - x) / g * ext_gcd(md, m[i]).first % (m[i] / g));
    md *= m[i] / g;
  }
  return {x < 0 ? x + md : x, md};
}
