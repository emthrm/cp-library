/*
 * @title 数学/離散対数問題
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod
 */

#include <iostream>

#include "emthrm/math/mod_log.hpp"

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int x, y, m;
    std::cin >> x >> y >> m;
    std::cout << emthrm::mod_log(x, y, m) << '\n';
  }
  return 0;
}
