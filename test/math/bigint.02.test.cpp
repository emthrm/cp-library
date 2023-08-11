/*
 * @title 数学/多倍長整数（加算）
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/addition_of_big_integers
 */

#include <iostream>

#include "emthrm/math/bigint.hpp"

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    emthrm::BigInt<> a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
  }
  return 0;
}
