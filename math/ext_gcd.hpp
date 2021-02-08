#pragma once
#include <tuple>
#include <utility>

template <typename T>
std::pair<T, T> ext_gcd(T a, T b) {
  if (b == 0) return {1, 0};
  T fst, snd; std::tie(fst, snd) = ext_gcd(b, a % b);
  return {snd, fst - a / b * snd};
}
