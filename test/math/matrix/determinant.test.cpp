/*
 * @title 数学/行列/行列式
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_det
 */

#include <iostream>

#include "emthrm/math/matrix/determinant.hpp"
#include "emthrm/math/matrix/matrix.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n;
  std::cin >> n;
  emthrm::Matrix<int> a(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }
  std::cout << emthrm::det(a, ModInt(0)) << '\n';
  return 0;
}
