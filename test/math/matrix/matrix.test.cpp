/*
 * @brief 数学/行列/行列
 */
#define PROBLEM "https://yukicoder.me/problems/no/1050"

#include <iostream>
#include "../../../math/modint.hpp"
#include "../../../math/matrix/matrix.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int m, k;
  std::cin >> m >> k;
  Matrix<ModInt> mat(m, m);
  for (int n = 0; n < m; ++n) for (int i = 0; i < m; ++i) {
    ++mat[n][(n + i) % m];
    ++mat[n][n * i % m];
  }
  std::cout << mat.pow(k)[0][0] << '\n';
  return 0;
}
