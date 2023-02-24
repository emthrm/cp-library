/*
 * @title 数学/行列/行列
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_product
 */

#include <iostream>

#include "emthrm/math/matrix/matrix.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n, m, k;
  std::cin >> n >> m >> k;
  emthrm::Matrix<ModInt> a(n, m), b(m, k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      std::cin >> b[i][j];
    }
  }
  const emthrm::Matrix<ModInt> c = a * b;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      std::cout << c[i][j] << " \n"[j + 1 == k];
    }
  }
  return 0;
}
