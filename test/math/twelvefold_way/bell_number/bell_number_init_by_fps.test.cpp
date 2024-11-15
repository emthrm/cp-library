/*
 * @title 数学/写像12相/ベル数/ベル数 (Bell number) の数表 $n = k$ 版
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/bell_number
 */

#include <iostream>
#include <ranges>
#include <vector>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/bell_number/bell_number_init_by_fps.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n;
  std::cin >> n;
  const std::vector<ModInt> b = emthrm::bell_number_init_by_fps<ModInt>(n);
  for (const int i : std::views::iota(0, n + 1)) {
    std::cout << b[i] << " \n"[i == n];
  }
  return 0;
}
