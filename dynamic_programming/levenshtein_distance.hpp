#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

template <typename T>
int levenshtein_distance(const T& a, const T& b) {
  const int n = a.size(), m = b.size();
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
  for (int i = n; i >= 1; --i) {
    dp[i][0] = i;
  }
  std::iota(dp[0].begin(), dp[0].end(), 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = std::min({dp[i - 1][j] + 1,
                           dp[i][j - 1] + 1,
                           dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])});
    }
  }
  return dp[n][m];
}
