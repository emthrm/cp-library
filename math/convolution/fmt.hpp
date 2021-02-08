#pragma once
#include <vector>

template <typename T>
std::vector<T> fmt(std::vector<T> a, bool is_superset, const T UNITY = 0) {
  int n = a.size(), p = 1;
  while ((1 << p) < n) ++p;
  n = 1 << p;
  a.resize(n, UNITY);
  if (is_superset) {
    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {
      if ((j & i) == 0) a[j] -= a[j | i];
    }
  } else {
    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {
      if ((j & i) == 0) a[j | i] -= a[j];
    }
  }
  return a;
}
