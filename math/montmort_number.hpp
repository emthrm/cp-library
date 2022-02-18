#pragma once
#include <vector>

template <typename T>
std::vector<T> montmort_number(const int n) {
  std::vector<T> montmort(n + 1, 0);
  montmort[0] = 1;
  for (int i = 2; i <= n; ++i) {
    montmort[i] = (montmort[i - 1] + montmort[i - 2]) * (i - 1);
  }
  return montmort;
}
