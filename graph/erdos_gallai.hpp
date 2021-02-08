#pragma once
#include <algorithm>
#include <functional>
#include <vector>

template <typename T>
bool erdos_gallai(const std::vector<T> &degree) {
  int n = degree.size();
  std::vector<T> deg(degree);
  std::sort(deg.begin(), deg.end(), std::greater<T>());
  deg.insert(deg.begin(), 0);
  std::vector<long long> sum(n + 1, 0);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + deg[i];
  if (sum[n] & 1) return false;
  int right = n;
  for (int i = 1; i <= n; ++i) {
    if (right < i) right = i;
    while (right > i && deg[right] < i) --right;
    if (sum[i] > static_cast<long long>(i) * (i - 1) + static_cast<long long>(i) * (right - i) + sum[n] - sum[right]) return false;
  }
  return true;
}
