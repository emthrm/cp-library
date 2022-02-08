/*
 * @brief 文字列/部分列 DP
 */
#define PROBLEM "https://atcoder.jp/contests/arc081/tasks/arc081_e"
// #define PROBLEM "https://atcoder.jp/contests/arc081/tasks/arc081_c"

#include <iostream>
#include <string>
#include <vector>
#include "../../string/subsequence_dp.hpp"

int main() {
  constexpr int SIGMA = 26;
  std::string a;
  std::cin >> a;
  const int n = a.length();
  const std::vector<std::vector<int>> nxt = subsequence_dp(a, 'a', SIGMA);
  std::vector<int> dp(n + 1, n + 1), next_char(n, -1);
  dp[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int c = 0; c < SIGMA; ++c) {
      const int len = (nxt[i][c] == n ? 0 : dp[nxt[i][c] + 1]) + 1;
      if (len < dp[i]) {
        dp[i] = len;
        next_char[i] = c;
      }
    }
  }
  std::string ans = "";
  for (int i = 0; i < n;) {
    ans += 'a' + next_char[i];
    i = nxt[i][next_char[i]] + 1;
  }
  std::cout << ans << '\n';
  return 0;
}
