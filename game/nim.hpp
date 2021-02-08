#pragma once
#include <vector>

template <typename T>
bool nim(const std::vector<T> &a) {
  long long x = 0;
  for (T e : a) x ^= e;
  return x != 0;
}
