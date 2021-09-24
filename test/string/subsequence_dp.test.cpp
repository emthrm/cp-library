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
  constexpr int C = 26;
  std::string a;
  std::cin >> a;
  const int n = a.length();
  std::vector<std::vector<int>> nx = subsequence_dp(a, 'a', C);
  std::vector<int> dp(n + 1, n + 1);
  dp[n] = 1;
  std::vector<int> next_char(n, -1);
  for (int i = n - 1; i >= 0; --i) {
    for (int c = 0; c < C; ++c) {
      const int len = (nx[i][c] == n ? 0 : dp[nx[i][c] + 1]) + 1;
      if (len < dp[i]) {
        dp[i] = len;
        next_char[i] = c;
      }
    }
  }
  std::string ans = "";
  for (int i = 0; i < n;) {
    ans += 'a' + next_char[i];
    i = nx[i][next_char[i]] + 1;
  }
  std::cout << ans << '\n';
  return 0;
}
