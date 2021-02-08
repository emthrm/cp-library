/*
 * @brief 数学/行列/バイナリ行列/逆行列 バイナリ行列版
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624"

#include <bitset>
#include <iostream>
#include "../../../../math/matrix/binary_matrix/binary_matrix.hpp"
#include "../../../../math/matrix/binary_matrix/inverse_matrix.hpp"
#include "../../../../math/matrix/binary_matrix/gauss_jordan.hpp"

int main() {
  constexpr int N = 600;
  using binary_matrix = BinaryMatrix<N>;
  int n;
  std::cin >> n;
  binary_matrix a(n, n), v(n, 1), inv(n, n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    int aij;
    std::cin >> aij;
    a[i][j] = aij;
  }
  for (int i = 0; i < n; ++i) {
    int vi;
    std::cin >> vi;
    v[i][0] = vi;
  }
  int t;
  std::cin >> t;
  if (inverse(a, inv)) {
    (inv = inv.pow(t)) *= v;
    for (int i = 0; i < n; ++i) std::cout << inv[i][0] << " \n"[i + 1 == n];
  } else {
    a = a.pow(t);
    binary_matrix av(n, n + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) av[i][j] = a[i][j];
      av[i][n] = v[i][0];
    }
    int rank = gauss_jordan(a), rank_av = gauss_jordan(av);
    std::cout << (rank == rank_av ? "ambiguous\n" : "none\n");
  }
  return 0;
}
