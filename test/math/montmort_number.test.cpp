/*
 * @title 数学/モンモール数
 */
#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"

#include <iostream>
#include <vector>

#define ARBITRARY_MODINT
#include "emthrm/math/modint.hpp"
#include "emthrm/math/montmort_number.hpp"

int main() {
  using ModInt = emthrm::MInt<0>;
  int n, m;
  std::cin >> n >> m;
  ModInt::set_mod(m);
  const std::vector<ModInt> b = emthrm::montmort_number<ModInt>(n);
  for (int i = 1; i <= n; ++i) {
    std::cout << b[i] << " \n"[i == n];
  }
  return 0;
}
