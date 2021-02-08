#pragma once
#include <vector>
#include "../math/fps/fps.hpp"

template <typename T>
std::vector<T> subset_sum_problem(const std::vector<int> &a, int d) {
  T zero = 1;
  std::vector<int> cnt(d + 1, 0);
  for (int e : a) {
    if (e == 0) {
      zero *= 2;
    } else if (e <= d) {
      ++cnt[e];
    }
  }
  FPS<T> fps(d);
  for (int i = 1; i <= d; ++i) for (int j = 1; i * j <= d; ++j) {
    fps[i * j] += static_cast<T>(cnt[i]) / j * (j & 1 ? 1 : -1);
  }
  return (fps.exp(d) * zero).co;
}
