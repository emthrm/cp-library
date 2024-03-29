/*
 * @title 数学/行列/バイナリ行列/ガウス・ジョルダンの消去法 バイナリ行列版
 *
 * verification-helper: PROBLEM https://yukicoder.me/problems/no/184
 */

#include <bitset>
#include <iostream>

#include "emthrm/math/matrix/binary_matrix/binary_matrix.hpp"
#include "emthrm/math/matrix/binary_matrix/gauss_jordan.hpp"

int main() {
  constexpr int B = 61;
  int n;
  std::cin >> n;
  emthrm::BinaryMatrix<B> matrix(n);
  for (int i = 0; i < n; ++i) {
    long long a;
    std::cin >> a;
    matrix[i] = std::bitset<B>(a);
  }
  std::cout << (1LL << emthrm::gauss_jordan(&matrix)) << '\n';
  return 0;
}
