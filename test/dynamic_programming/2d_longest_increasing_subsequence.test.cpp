/*
 * @brief 動的計画法/2次元最長増加部分列
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc038/tasks/abc038_d"

#include <iostream>
#include <utility>
#include <vector>
#include "../../dynamic_programming/2d_longest_increasing_subsequence.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> wh(n);
  for (int i = 0; i < n; ++i) std::cin >> wh[i].first >> wh[i].second;
  std::cout << longest_increasing_subsequence_2d(wh) << '\n';
  return 0;
}
