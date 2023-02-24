/*
 * @title 数学/行列/バイナリ行列/逆行列 バイナリ行列版
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624
 */

#include <bitset>
#include <iostream>

#include "emthrm/math/matrix/binary_matrix/binary_matrix.hpp"
#include "emthrm/math/matrix/binary_matrix/gauss_jordan.hpp"
#include "emthrm/math/matrix/binary_matrix/inverse_matrix.hpp"

int main() {
  constexpr int N = 600;
  using binary_matrix = emthrm::BinaryMatrix<N>;
  int n;
  std::cin >> n;
  binary_matrix a(n, n), v(n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int a_ij;
      std::cin >> a_ij;
      a[i][j] = a_ij;
    }
  }
  for (int i = 0; i < n; ++i) {
    int v_i;
    std::cin >> v_i;
    v[i][0] = v_i;
  }
  int t;
  std::cin >> t;
  binary_matrix inv = emthrm::inverse_matrix(a);
  if (inv.nrow() == 0) {
    a = a.pow(t);
    binary_matrix av(n, n + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        av[i][j] = a[i][j];
      }
      av[i][n] = v[i][0];
    }
    std::cout << (emthrm::gauss_jordan(&a) == emthrm::gauss_jordan(&av) ?
                  "ambiguous\n" : "none\n");
  } else {
    inv = inv.pow(t) * v;
    for (int i = 0; i < n; ++i) {
      std::cout << inv[i][0] << " \n"[i + 1 == n];
    }
  }
  return 0;
}
