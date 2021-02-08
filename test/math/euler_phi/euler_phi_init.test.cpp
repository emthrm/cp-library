/*
 * @brief 数学/オイラーの $\varphi$ 関数/オイラーの $\varphi$ 関数の数表
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include <vector>
#include "../../../math/euler_phi/euler_phi_init.hpp"
#include "../../../math/euler_phi/euler_phi.hpp"

int main() {
  constexpr int M = 1000000;
  std::vector<int> ans = euler_phi_init(1000000);
  int n;
  std::cin >> n;
  std::cout << (n <= M ? ans[n] : euler_phi(n)) << '\n';
  return 0;
}
