/*
 * @title 数学/多倍長整数（減算）
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_B
 */

#include <iostream>

#include "emthrm/math/bigint.hpp"

int main() {
  emthrm::BigInt<> a, b;
  std::cin >> a >> b;
  std::cout << a - b << '\n';
  return 0;
}
