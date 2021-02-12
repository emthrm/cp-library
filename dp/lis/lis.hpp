/**
 * @brief 最長増加部分列
 * @docs docs/dp/lis/lis.md
 */

#pragma once
#include <algorithm>
#include <iterator>
#include <limits>
#include <vector>

template <typename T>
std::vector<T> lis(const std::vector<T> &a, bool is_strict = true) {
  const T inf = std::numeric_limits<T>::max();
  int n = a.size();
  std::vector<T> check(n, inf);
  std::vector<int> idx(n);
  for (int i = 0; i < n; ++i) {
    if (is_strict) {
      idx[i] = std::distance(check.begin(), std::lower_bound(check.begin(), check.end(), a[i]));
    } else {
      idx[i] = std::distance(check.begin(), std::upper_bound(check.begin(), check.end(), a[i]));
    }
    check[idx[i]] = a[i];
  }
  int res_sz = std::distance(check.begin(), std::lower_bound(check.begin(), check.end(), inf));
  std::vector<T> res(res_sz--);
  for (int i = n - 1; res_sz >= 0 && i >= 0; --i) {
    if (idx[i] == res_sz) res[res_sz--] = a[i];
  }
  return res;
}
