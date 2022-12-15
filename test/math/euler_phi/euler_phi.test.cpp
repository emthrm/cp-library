/*
 * @brief 数学/オイラーの $\varphi$ 関数/オイラーの $\varphi$ 関数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include "emthrm/math/euler_phi/euler_phi.hpp"

int main() {
  int n;
  std::cin >> n;
  std::cout << emthrm::euler_phi(n) << '\n';
  return 0;
}
