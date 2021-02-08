/*
 * @brief 動的計画法/convex full trick (query(x))
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c"

#include <iostream>
#include "../../dp/cht.hpp"

int main() {
  int n;
  std::cin >> n;
  CHT<long long> cht(false);
  for (int j = 1; j <= n; ++j) {
    long long a;
    std::cin >> a;
    cht.add(2 * j, -(a + static_cast<long long>(j) * j));
  }
  for (int i = 1; i <= n; ++i) std::cout << -cht.query(i) + static_cast<long long>(i) * i << '\n';
  return 0;
}
