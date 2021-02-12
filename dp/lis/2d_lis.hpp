/**
 * @brief 2次元 LIS
 * @docs docs/dp/lis/lis.md
 */

#pragma once
#include <algorithm>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>

template <typename T>
int lis_2d(std::vector<std::pair<T, T>> a) {
  const T inf = std::numeric_limits<T>::max();
  int n = a.size();
  for (int i = 0; i < n; ++i) a[i].second = -a[i].second;
  std::sort(a.begin(), a.end());
  std::vector<T> check(n, inf);
  for (const std::pair<T, T> &pr : a) {
    T tmp = -pr.second;
    *std::lower_bound(check.begin(), check.end(), tmp) = tmp;
  }
  return std::distance(check.begin(), std::lower_bound(check.begin(), check.end(), inf));
}
