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
  for (int j = 0; j < n; ++j) {
    dp[j][j] = 0;
    argmin[j][j] = j;
    for (int i = j - 1; i >= 0; --i) {
      const int right = std::min(j - 1, argmin[i + 1][j]);
      for (int k = argmin[i][j - 1]; k <= right; ++k) {
        const T tmp = dp[i][k] + dp[k + 1][j];
        if (tmp < dp[i][j]) {
          dp[i][j] = tmp;
          argmin[i][j] = k;
        }
      }
      dp[i][j] += w[i][j];
    }
  }
  return dp;
}
