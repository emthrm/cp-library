/*
 * @brief 動的計画法/convex full trick (monotonically_decreasing_query(x))
 */
#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_z"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../dynamic_programming/convex_hull_trick.hpp"

int main() {
  int n;
  long long c;
  std::cin >> n >> c;
  std::vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> h[i];
  }
  std::reverse(h.begin(), h.end());
  ConvexHullTrick<long long> convex_hull_trick;
  convex_hull_trick.add(-2 * h.front(),
                        static_cast<long long>(h.front()) * h.front());
  for (int i = 1; i < n; ++i) {
    const long long dp =
        convex_hull_trick.monotonically_decreasing_query(h[i])
        + static_cast<long long>(h[i]) * h[i] + c;
    if (i + 1 == n) {
      std::cout << dp << '\n';
    } else {
      convex_hull_trick.add(-2 * h[i],
                            dp + static_cast<long long>(h[i]) * h[i]);
    }
  }
  return 0;
}
