#pragma once
#include <vector>
#include "fps.hpp"

template <typename T>
std::vector<T> bernoulli_number(int n) {
  FPS<T> bernoulli(n);
  bernoulli[0] = 1;
  for (int i = 1; i <= n; ++i) bernoulli[i] = bernoulli[i - 1] / (i + 1);
  bernoulli = bernoulli.inv(n);
  T fact = 1;
  for (int i = 0; i <= n; ++i) {
    bernoulli[i] *= fact;
    fact *= i + 1;
  }
  return bernoulli.co;
}
