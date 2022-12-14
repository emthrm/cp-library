/*
 * @brief 数学/拡張 Euclid の互除法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <iostream>
#include <tuple>

#include "emthrm/math/ext_gcd.hpp"

int main() {
  int a, b;
  std::cin >> a >> b;
  int x, y;
  std::tie(x, y) = ext_gcd(a, b);
  std::cout << x << ' ' << y << '\n';
  return 0;
}
