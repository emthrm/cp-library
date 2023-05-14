/*
 * @title 数学/メビウス関数/メビウス関数 約数版
 *
 * verification-helper: PROBLEM https://atcoder.jp/contests/abc162/tasks/abc162_e
 */

#include <iostream>
#include <map>

#include "emthrm/math/mobius_mu_focusing_on_divisor.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n, k;
  std::cin >> n >> k;
  std::map<int, int> mu;
  ModInt ans = 0;
  for (int g = 1; g <= k; ++g) {
    ModInt ways = 0;
    for (int m = k / g; m >= 1; --m) {
      if (!mu.contains(m)) {
        for (const auto& [d, mu_d] : emthrm::mobius_mu_focusing_on_divisor(m)) {
          mu[d] = mu_d;
        }
      }
      ways += ModInt(k / (g * m)).pow(n) * mu[m];
    }
    ans += ways * g;
  }
  std::cout << ans << '\n';
  return 0;
}
