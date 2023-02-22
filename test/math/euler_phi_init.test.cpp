/*
 * @brief 数学/オイラーの $\varphi$ 関数/オイラーの $\varphi$ 関数の数表
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include <vector>

#include "emthrm/math/euler_phi.hpp"
#include "emthrm/math/euler_phi_init.hpp"

int main() {
  constexpr int M = 1000000;
  const std::vector<int> ans = emthrm::euler_phi_init(M);
  int n;
  std::cin >> n;
  std::cout << (n <= M ? ans[n] : emthrm::euler_phi(n)) << '\n';
  return 0;
}
