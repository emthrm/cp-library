#pragma once
#include <vector>

template <typename T>
std::vector<T> montmort_number(int val) {
  std::vector<T> montmort(val + 1, 0);
  if (val >= 0) montmort[0] = 1;
  for (int i = 2; i <= val; ++i) montmort[i] = (montmort[i - 1] + montmort[i - 2]) * (i - 1);
  return montmort;
}
