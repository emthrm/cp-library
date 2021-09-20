/**
 * @brief 最長増加部分列
 * @docs docs/dynamic_programming/longest_increasing_subsequence.md
 */

#pragma once
#include <algorithm>
#include <iterator>
#include <limits>
#include <vector>

template <typename T>
std::vector<T> longest_increasing_subsequence(const std::vector<T> &a, bool is_strict = true) {
  const T inf = std::numeric_limits<T>::max();
  const int n = a.size();
  std::vector<int> idx(n);
  std::vector<T> tmp(n, inf);
  for (int i = 0; i < n; ++i) {
    if (is_strict) {
      idx[i] = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), a[i]));
    } else {
      idx[i] = std::distance(tmp.begin(), std::upper_bound(tmp.begin(), tmp.end(), a[i]));
    }
    tmp[idx[i]] = a[i];
  }
  int res_size = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), inf));
  std::vector<T> res(res_size--);
  for (int i = n - 1; res_size >= 0 && i >= 0; --i) {
    if (idx[i] == res_size) {
      res[res_size--] = a[i];
    }
  }
  return res;
}
