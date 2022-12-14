/*
 * @brief 数学/行列/逆行列
 */
#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include <iostream>

#include "emthrm/math/matrix/inverse_matrix.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  int n;
  std::cin >> n;
  Matrix<ModInt> a(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }
  const Matrix<ModInt> b = inverse_matrix(a, ModInt(0));
  if (b.nrow() == 0) {
    std::cout << "-1\n";
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << b[i][j] << " \n"[j + 1 == n];
      }
    }
  }
  return 0;
}
