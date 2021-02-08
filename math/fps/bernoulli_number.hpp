#pragma once
#include <vector>
#include "fps.hpp"

template <typename T>
std::vector<T> bernoulli_number(int val) {
  FPS<T> bernoulli(val);
  bernoulli[0] = 1;
  for (int i = 1; i <= val; ++i) bernoulli[i] = bernoulli[i - 1] / (i + 1);
  bernoulli = bernoulli.inv(val);
  T fact = 1;
  for (int i = 0; i <= val; ++i) {
    bernoulli[i] *= fact;
    fact *= i + 1;
  }
  return bernoulli.co;
}
