/*
 * @title 数学/多倍長整数（大小比較）
 *
 * verification-helper: PROBLEM https://atcoder.jp/contests/arc072/tasks/abc059_b
 * Link: "https://atcoder.jp/contests/abc059/tasks/abc059_b"
 */

#include <iostream>

#include "emthrm/math/bigint.hpp"

int main() {
  emthrm::BigInt<> a, b;
  std::cin >> a >> b;
  if (a > b) {
    std::cout << "GREATER\n";
  } else if (a < b) {
    std::cout << "LESS\n";
  } else if (a == b) {
    std::cout << "EQUAL\n";
  }
  return 0;
}
