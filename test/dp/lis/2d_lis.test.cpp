/*
 * @brief 動的計画法/LIS/2次元 LIS
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc038/tasks/abc038_d"

#include <iostream>
#include <utility>
#include <vector>
#include "../../../dp/lis/2d_lis.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> wh(n);
  for (int i = 0; i < n; ++i) std::cin >> wh[i].first >> wh[i].second;
  std::cout << lis_2d(wh) << '\n';
  return 0;
}
