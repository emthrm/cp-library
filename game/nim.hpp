#pragma once
#include <vector>

template <typename T>
bool nim(const std::vector<T>& a) {
  long long x = 0;
  for (const T e : a) x ^= e;
  return x != 0;
}
