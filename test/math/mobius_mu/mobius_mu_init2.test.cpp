/*
 * @brief 数学/メビウス関数/メビウス関数の数表2
 */
#define PROBLEM "https://atcoder.jp/contests/abc162/tasks/abc162_e"

#include <iostream>
#include <vector>

#include "emthrm/math/mobius_mu/mobius_mu_init2.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n, k;
  std::cin >> n >> k;
  const std::vector<int> mu = emthrm::mobius_mu_init2(1, k + 1);
  ModInt ans = 0;
  for (int g = 1; g <= k; ++g) {
    ModInt ways = 0;
    for (int mul = 1; g * mul <= k; ++mul) {
      ways += ModInt(k / (g * mul)).pow(n) * mu[mul - 1];
    }
    ans += ways * g;
  }
  std::cout << ans << '\n';
  return 0;
}
