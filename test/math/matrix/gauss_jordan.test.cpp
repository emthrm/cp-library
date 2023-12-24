/*
 * @title 数学/行列/ガウス・ジョルダンの消去法
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_rank
 */

#include <iostream>
#include <ranges>

#include "emthrm/math/matrix/gauss_jordan.hpp"
#include "emthrm/math/matrix/matrix.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n, m;
  std::cin >> n >> m;
  emthrm::Matrix<ModInt> a(n, m);
  for (const int i : std::views::iota(0, n)) {
    for (ModInt& a_ij : a[i]) std::cin >> a_ij;
  }
  std::cout << emthrm::gauss_jordan(&a) << '\n';
  return 0;
}
