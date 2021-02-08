#pragma once
#include <algorithm>
#include <vector>

template <typename T>
T lcs(const T &a, const T &b) {
  int a_sz = a.size(), b_sz = b.size();
  std::vector<std::vector<int>> dp(a_sz + 1, std::vector<int>(b_sz + 1, 0));
  for (int i = 0; i < a_sz; ++i) for (int j = 0; j < b_sz; ++j) {
    dp[i + 1][j + 1] = a[i] == b[j] ? dp[i][j] + 1 : std::max(dp[i][j + 1], dp[i + 1][j]);
  }
  T res;
  while (a_sz > 0 && b_sz > 0) {
    if (dp[a_sz][b_sz] == dp[a_sz - 1][b_sz]) {
      --a_sz;
    } else if (dp[a_sz][b_sz] == dp[a_sz][b_sz - 1]) {
      --b_sz;
    } else {
      res.push_back(a[a_sz - 1]);
      --a_sz; --b_sz;
    }
  }
  std::reverse(res.begin(), res.end());
  return res;
}
