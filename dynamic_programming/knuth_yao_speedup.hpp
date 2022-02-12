#pragma once
#include <algorithm>
#include <vector>

template <typename T>
std::vector<std::vector<T>> knuth_yao_speedup(
    const std::vector<std::vector<T>>& w, const T inf) {
  const int n = w.size();
  std::vector<std::vector<T>> dp(n, std::vector<T>(n, inf));
  if (n == 0) return dp;
  std::vector<std::vector<int>> argmin(n, std::vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
    argmin[i][i] = i;
  }
  for (int width = 2; width <= n; ++width) {
    for (int i = 0; ; ++i) {
      const int j = i + width - 1;
      if (j >= n) break;
      const int right = std::min(j - 1, argmin[i + 1][j]);
      for (int k = argmin[i][j - 1]; k <= right; ++k) {
        const T tmp = dp[i][k] + dp[k + 1][j] + w[i][j];
        if (tmp < dp[i][j]) {
          dp[i][j] = tmp;
          argmin[i][j] = k;
        }
      }
    }
  }
  return dp;
}
