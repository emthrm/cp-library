#pragma once
#include <vector>

template <typename T>
T tsp(const std::vector<std::vector<T>> &graph, T TINF) {
  int n = graph.size();
  if (n == 1) return 0;
  std::vector<std::vector<T>> dp(1 << n, std::vector<T>(n, TINF));
  dp[1][0] = 0;
  for (int i = 1; i < (1 << n); ++i) for (int j = 0; j < n; ++j) {
    if (dp[i][j] == TINF) continue;
    for (int k = 0; k < n; ++k) {
      if (!(i >> k & 1) && dp[i][j] + graph[j][k] < dp[i | (1 << k)][k]) {
        dp[i | (1 << k)][k] = dp[i][j] + graph[j][k];
      }
    }
  }
  T res = TINF;
  for (int j = 1; j < n; ++j) {
    if (dp[(1 << n) - 1][j] + graph[j][0] < res) res = dp[(1 << n) - 1][j] + graph[j][0];
  }
  return res;
}
