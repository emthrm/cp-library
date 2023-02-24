/*
 * @title 動的計画法/convex full trick (query(x))
 *
 * verification-helper: PROBLEM https://atcoder.jp/contests/dp/tasks/dp_z
 */

#include <iostream>

#include "emthrm/dynamic_programming/convex_hull_trick.hpp"

int main() {
  int n;
  long long c;
  std::cin >> n >> c;
  emthrm::ConvexHullTrick<long long> convex_hull_trick;
  for (int i = 0; i < n; ++i) {
    int h;
    std::cin >> h;
    if (i == 0) [[unlikely]] {
      convex_hull_trick.add(-2 * h, static_cast<long long>(h) * h);
    } else {
      const long long dp =
          convex_hull_trick.query(h) + static_cast<long long>(h) * h + c;
      if (i + 1 == n) [[unlikely]] {
        std::cout << dp << '\n';
      } else {
        convex_hull_trick.add(-2 * h, dp + static_cast<long long>(h) * h);
      }
    }
  }
  return 0;
}
