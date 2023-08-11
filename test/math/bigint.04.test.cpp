/*
 * @title 数学/多倍長整数（乗算）
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/multiplication_of_big_integers
 */

#include <iostream>

#include "emthrm/math/bigint.hpp"

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    emthrm::BigInt<> a, b;
    std::cin >> a >> b;
    std::cout << a * b << '\n';
  }
  return 0;
}
