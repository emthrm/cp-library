#pragma once
#include <tuple>
#include <utility>

template <typename T>
std::pair<T, T> ext_gcd(T a, T b) {
  T x = 1, y = 0, u = 0, v = 1;
  while (b) {
    T q = a / b;
    std::swap(a -= q * b, b);
    std::swap(x -= q * u, u);
    std::swap(y -= q * v, v);
  }
  if (a < 0) {
    x = -x;
    y = -y;
  }
  return {x, y};
}
