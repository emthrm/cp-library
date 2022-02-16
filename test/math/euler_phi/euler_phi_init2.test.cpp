/*
 * @brief 数学/オイラーの $\varphi$ 関数/オイラーの $\varphi$ 関数の数表2
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include <iostream>
#include <vector>

#include "../../../math/euler_phi/euler_phi.hpp"
#include "../../../math/euler_phi/euler_phi_init2.hpp"

int main() {
  constexpr int L = 999000000, H = 1000000000;
  const std::vector<long long> ans = euler_phi_init2(L, H + 1);
  int n;
  std::cin >> n;
  std::cout << (n >= L ? ans[n - L] : euler_phi(n)) << '\n';
  return 0;
}
