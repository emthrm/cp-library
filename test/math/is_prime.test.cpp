/*
 * @brief 数学/素数判定
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <iostream>
#include "../../math/is_prime.hpp"

int main() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int query;
    std::cin >> query;
    if (is_prime(query)) ++ans;
  }
  std::cout << ans << '\n';
  return 0;
}
