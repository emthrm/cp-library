/*
 * @title 数学/行列/行列の累乗
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/pow_of_matrix
 */

#include <iostream>

#include "emthrm/math/matrix/matrix.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  int n;
  long long k;
  std::cin >> n >> k;
  emthrm::Matrix<ModInt> a(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
    }
  }
  a = a.pow(k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << a[i][j] << " \n"[j + 1 == n];
    }
  }
  return 0;
}
