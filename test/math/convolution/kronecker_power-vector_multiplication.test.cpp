/*
 * @title 数学/畳み込み/クロネッカー冪とベクトルの積
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc288/tasks/abc288_g"

#include <cmath>
#include <iostream>
#include <vector>

#include "emthrm/math/convolution/kronecker_power-vector_multiplication.hpp"
#include "emthrm/math/matrix/matrix.hpp"

int main() {
  int n;
  std::cin >> n;
  const int m = std::llround(std::pow(3, n));
  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> a[i];
  }
  emthrm::Matrix<int> inv(3, 3);
  inv[0][1] = inv[1][0] = inv[1][2] = inv[2][1] = 1;
  inv[0][2] = inv[1][1] = inv[2][0] = -1;
  const std::vector<int> b =
      emthrm::kronecker_power_vector_multiplication(inv, a);
  for (int i = 0; i < m; ++i) {
    std::cout << b[i] << " \n"[i + 1 == m];
  }
  return 0;
}
