/*
 * @brief 数学/形式的冪級数/Berlekamp-Massey algorithm
 */
#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include <iostream>
#include <vector>

#include "../../../math/formal_power_series/berlekamp-massey.hpp"
#include "../../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  int n;
  std::cin >> n;
  std::vector<ModInt> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  const std::vector<ModInt> c = berlekamp_massey(a);
  const int d = c.size() - 1;
  std::cout << d << '\n';
  for (int i = 0; i < d; ++i) {
    std::cout << -c[i + 1];
    if (i + 1 < d) std::cout << ' ';
  }
  std::cout << '\n';
  return 0;
}
