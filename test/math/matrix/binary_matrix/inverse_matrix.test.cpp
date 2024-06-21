/*
 * @title 数学/行列/バイナリ行列/逆行列 バイナリ行列版
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/inverse_matrix_mod_2
 */

#include <iostream>
#include <string>

#include "emthrm/math/matrix/binary_matrix/binary_matrix.hpp"
#include "emthrm/math/matrix/binary_matrix/inverse_matrix.hpp"

int main() {
  constexpr int kMaxN = (1 << 12) * 2;
  int n;
  std::cin >> n;
  emthrm::BinaryMatrix<kMaxN> a(n, n);
  for (int i = 0; i < n; ++i) {
    std::string a_i;
    std::cin >> a_i;
    for (int j = 0; j < n; ++j) {
      if (a_i[j] == '1') a[i].set(j);
    }
  }
  a = inverse_matrix(a);
  if (a.nrow() == 0) {
    std::cout << "-1\n";
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << a[i][j];
      }
      std::cout << '\n';
    }
  }
  return 0;
}
