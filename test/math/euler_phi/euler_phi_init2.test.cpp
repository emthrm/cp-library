/*
 * @brief 数学/オイラーの $\varphi$ 関数/オイラーの $\varphi$ 関数の数表2
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include <vector>
#include "../../../math/euler_phi/euler_phi_init2.hpp"
#include "../../../math/euler_phi/euler_phi.hpp"

int main() {
  constexpr int M = 999000000;
  std::vector<long long> ans = euler_phi_init2(999000000, 1000000001);
  int n;
  std::cin >> n;
  std::cout << (n >= M ? ans[n - M] : euler_phi(n)) << '\n';
  return 0;
}
