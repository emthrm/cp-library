/*
 * @brief 数学/メビウス関数/メビウス関数 約数版
 */
#define PROBLEM "https://atcoder.jp/contests/abc162/tasks/abc162_e"

#include <iostream>
#include <map>
#include <utility>

#include "../../../math/mobius_mu/mobius_mu_focusing_on_divisor.hpp"
#include "../../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int n, k;
  std::cin >> n >> k;
  std::map<int, int> mu;
  ModInt ans = 0;
  for (int g = 1; g <= k; ++g) {
    ModInt ways = 0;
    for (int m = k / g; m >= 1; --m) {
      if (mu.count(m) == 0) {
        for (const std::pair<int, int>& p : mobius_mu_focusing_on_divisor(m)) {
          mu[p.first] = p.second;
        }
      }
      ways += ModInt(k / (g * m)).pow(n) * mu[m];
    }
    ans += ways * g;
  }
  std::cout << ans << '\n';
  return 0;
}
