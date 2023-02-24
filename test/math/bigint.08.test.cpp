/*
 * @title 数学/多倍長整数 (冪演算)
 */
#define IGNORE
#define PROBLEM "https://codeforces.com/problemsets/acmsguru/problem/99999/112"

#include <iostream>

#include "emthrm/math/bigint.hpp"

int main() {
  emthrm::BigInt<> a, b;
  std::cin >> a >> b;
  std::cout << a.pow(b) - b.pow(a) << '\n';
  return 0;
}
