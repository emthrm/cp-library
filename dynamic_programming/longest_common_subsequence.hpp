#pragma once
#include <algorithm>
#include <vector>

template <typename T>
T longest_common_subsequence(const T &a, const T &b) {
  int a_size = a.size(), b_size = b.size();
  std::vector<std::vector<int>> dp(a_size + 1, std::vector<int>(b_size + 1, 0));
  for (int i = 0; i < a_size; ++i) {
    for (int j = 0; j < b_size; ++j) {
      dp[i + 1][j + 1] = (a[i] == b[j] ? dp[i][j] + 1 : std::max(dp[i][j + 1], dp[i + 1][j]));
    }
  }
  T res;
  while (a_size > 0 && b_size > 0) {
    if (dp[a_size][b_size] == dp[a_size - 1][b_size]) {
      --a_size;
    } else if (dp[a_size][b_size] == dp[a_size][b_size - 1]) {
      --b_size;
    } else {
      res.push_back(a[--a_size]);
      --b_size;
    }
  }
  std::reverse(res.begin(), res.end());
  return res;
}
