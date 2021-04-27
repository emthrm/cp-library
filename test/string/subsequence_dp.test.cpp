/*
 * @brief 文字列/部分列 DP
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemset/problem/1149/B"

#include <iostream>
#include <string>
#include <vector>
#include "../../string/subsequence_dp.hpp"

int main() {
  constexpr int D = 250;
  int n, q;
  std::string s;
  std::cin >> n >> q >> s;
  std::vector<std::vector<int>> nx = subsequence_dp(s);
  std::vector<std::vector<std::vector<int>>> dp(D + 1, std::vector<std::vector<int>>(D + 1, std::vector<int>(D + 1, n)));
  dp[0][0][0] = -1;
  std::vector<int> len(3, 0);
  std::vector<std::vector<char>> str(3);
  while (q--) {
    char ope;
    int i;
    std::cin >> ope >> i;
    --i;
    if (ope == '+') {
      char c;
      std::cin >> c;
      ++len[i];
      str[i].emplace_back(c);
      if (i == 0) {
        for (int y = 0; y <= len[1]; ++y) for (int z = 0; z <= len[2]; ++z) {
          int &now = dp[len[0]][y][z];
          now = n;
          if (len[0] > 0 && dp[len[0] - 1][y][z] + 1 < n && nx[dp[len[0] - 1][y][z] + 1][str[0][len[0] - 1] - 'a'] < now) {
            now = nx[dp[len[0] - 1][y][z] + 1][str[0][len[0] - 1] - 'a'];
          }
          if (y > 0 && dp[len[0]][y - 1][z] + 1 < n && nx[dp[len[0]][y - 1][z] + 1][str[1][y - 1] - 'a'] < now) {
            now = nx[dp[len[0]][y - 1][z] + 1][str[1][y - 1] - 'a'];
          }
          if (z > 0 && dp[len[0]][y][z - 1] + 1 < n && nx[dp[len[0]][y][z - 1] + 1][str[2][z - 1] - 'a'] < now) {
            now = nx[dp[len[0]][y][z - 1] + 1][str[2][z - 1] - 'a'];
          }
        }
      } else if (i == 1) {
        for (int x = 0; x <= len[0]; ++x) for (int z = 0; z <= len[2]; ++z) {
          int &now = dp[x][len[1]][z];
          now = n;
          if (x > 0 && dp[x - 1][len[1]][z] + 1 < n && nx[dp[x - 1][len[1]][z] + 1][str[0][x - 1] - 'a'] < now) {
            now = nx[dp[x - 1][len[1]][z] + 1][str[0][x - 1] - 'a'];
          }
          if (len[1] > 0 && dp[x][len[1] - 1][z] + 1 < n && nx[dp[x][len[1] - 1][z] + 1][str[1][len[1] - 1] - 'a'] < now) {
            now = nx[dp[x][len[1] - 1][z] + 1][str[1][len[1] - 1] - 'a'];
          }
          if (z > 0 && dp[x][len[1]][z - 1] + 1 < n && nx[dp[x][len[1]][z - 1] + 1][str[2][z - 1] - 'a'] < now) {
            now = nx[dp[x][len[1]][z - 1] + 1][str[2][z - 1] - 'a'];
          }
        }
      } else if (i == 2) {
        for (int x = 0; x <= len[0]; ++x) for (int y = 0; y <= len[1]; ++y) {
          int &now = dp[x][y][len[2]];
          now = n;
          if (x > 0 && dp[x - 1][y][len[2]] + 1 < n && nx[dp[x - 1][y][len[2]] + 1][str[0][x - 1] - 'a'] < now) {
            now = nx[dp[x - 1][y][len[2]] + 1][str[0][x - 1] - 'a'];
          }
          if (y > 0 && dp[x][y - 1][len[2]] + 1 < n && nx[dp[x][y - 1][len[2]] + 1][str[1][y - 1] - 'a'] < now) {
            now = nx[dp[x][y - 1][len[2]] + 1][str[1][y - 1] - 'a'];
          }
          if (len[2] > 0 && dp[x][y][len[2] - 1] + 1 < n && nx[dp[x][y][len[2] - 1] + 1][str[2][len[2] - 1] - 'a'] < now) {
            now = nx[dp[x][y][len[2] - 1] + 1][str[2][len[2] - 1] - 'a'];
          }
        }
      }
    } else if (ope == '-') {
      --len[i];
      str[i].pop_back();
    }
    std::cout << (dp[len[0]][len[1]][len[2]] < n ? "YES\n" : "NO\n");
  }
  return 0;
}
