/*
 * @brief 数学/行列/バイナリ行列/ガウス・ジョルダンの消去法 バイナリ行列版
 */
#define PROBLEM "https://yukicoder.me/problems/no/184"

#include <bitset>
#include <iostream>
#include "../../../../math/matrix/binary_matrix/binary_matrix.hpp"
#include "../../../../math/matrix/binary_matrix/gauss_jordan.hpp"

int main() {
  constexpr int N = 61;
  int n;
  std::cin >> n;
  BinaryMatrix<N> mat(n);
  for (int i = 0; i < n; ++i) {
    long long a;
    std::cin >> a;
    mat[i] = std::bitset<N>(a);
  }
  int rank = gauss_jordan(mat);
  long long ans = 1LL << rank;
  std::cout << ans << '\n';
  return 0;
}
