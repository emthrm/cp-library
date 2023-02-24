/*
 * @title 数学/平方剰余
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/sqrt_mod
 */

#include <iostream>

#include "emthrm/math/mod_sqrt.hpp"

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int y, p;
    std::cin >> y >> p;
    std::cout << emthrm::mod_sqrt(y, p) << '\n';
  }
  return 0;
}
