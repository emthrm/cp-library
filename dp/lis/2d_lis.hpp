/**
 * @brief 2次元 LIS
 * @docs docs/dp/lis/lis.md
 */

#pragma once
#include <algorithm>
#include <utility>
#include <vector>

template <typename T>
int lis_2d(const std::vector<std::pair<T, T>> &a, const T TINF) {
  std::vector<std::pair<T, T>> b(a);
  int n = b.size();
  for (int i = 0; i < n; ++i) b[i].second = -b[i].second;
  std::sort(b.begin(), b.end());
  std::vector<T> check(n, TINF);
  for (std::pair<T, T> pr : b) {
    T tmp = -pr.second;
    *std::lower_bound(check.begin(), check.end(), tmp) = tmp;
  }
  return std::lower_bound(check.begin(), check.end(), TINF) - check.begin();
}
