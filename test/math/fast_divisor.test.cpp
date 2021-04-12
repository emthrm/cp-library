/*
 * @brief 数学/約数列挙
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/contest/1512/problem/G"

#include <iostream>
#include <vector>
#include "../../math/fast_divisor.hpp"

int main() {
  constexpr int N = 10000000;
  Divisor divisor(N);
  std::vector<int> ans(N + 1, -1);
  for (int i = N; i >= 1; --i) {
    int d = 0;
    for (int di : divisor.query(i)) d += di;
    if (d <= N) ans[d] = i;
  }
  int t;
  std::cin >> t;
  while (t--) {
    int c;
    std::cin >> c;
    std::cout << ans[c] << '\n';
  }
  return 0;
}
