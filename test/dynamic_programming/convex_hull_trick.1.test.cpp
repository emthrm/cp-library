/*
 * @brief 動的計画法/convex full trick (query(x))
 */
#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_z"

#include <iostream>
#include "../../dynamic_programming/convex_hull_trick.hpp"

int main() {
  int n;
  long long c;
  std::cin >> n >> c;
  ConvexHullTrick<long long> cht;
  for (int i = 0; i < n; ++i) {
    int h;
    std::cin >> h;
    if (i == 0) {
      cht.add(-2 * h, static_cast<long long>(h) * h);
    } else {
      const long long dp = cht.query(h) + static_cast<long long>(h) * h + c;
      if (i + 1 == n) {
        std::cout << dp << '\n';
      } else {
        cht.add(-2 * h, dp + static_cast<long long>(h) * h);
      }
    }
  }
  return 0;
}
