/*
 * @brief 数学/多倍長整数 (減算)
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B"

#include <iostream>
#include "../../math/bigint.hpp"

int main() {
  BigInt<> a, b;
  std::cin >> a >> b;
  std::cout << a - b << '\n';
  return 0;
}
