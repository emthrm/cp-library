#pragma once
#include <algorithm>
#include <vector>

template <typename Fn, typename T>
T mongedp(int n, Fn cost, const T inf) {
  if (n == 0) return 0;
  std::vector<std::vector<T>> dp(n, std::vector<T>(n, inf));
  std::vector<std::vector<int>> argmin(n, std::vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;
    argmin[i][i] = i;
  }
  for (int width = 1; width < n; ++width) {
    for (int i = 0; i + width < n; ++i) {
      int j = i + width, right = std::min(j - 1, argmin[i + 1][j]);
      for (int k = argmin[i][j - 1]; k <= right; ++k) {
        T tmp = dp[i][k] + dp[k + 1][j] + cost(i, k, j);
        if (dp[i][j] > tmp) {
          dp[i][j] = tmp;
          argmin[i][j] = k;
        }
      }
    }
  }
  return dp[0][n - 1];
}
