#pragma once
#include <algorithm>
#include <vector>
#include "nim.hpp"

template <typename T>
bool misere_nim(const std::vector<T> &a) {
  return *std::max_element(a.begin(), a.end()) <= 1 ? a.size() % 2 == 0 : nim(a);
}
