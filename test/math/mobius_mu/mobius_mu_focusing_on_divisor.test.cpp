/*
 * @brief 数学/メビウス関数/メビウス関数 約数版
 */
#define PROBLEM "https://atcoder.jp/contests/abc162/tasks/abc162_e"

#include <iostream>
#include <map>
#include <utility>
#include "../../../math/modint.hpp"
#include "../../../math/mobius_mu/mobius_mu_focusing_on_divisor.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int n, k;
  std::cin >> n >> k;
  std::map<int, int> mu;
  ModInt ans = 0;
  for (int g = 1; g <= k; ++g) {
    ModInt pat = 0;
    for (int mul = k / g; mul >= 1; --mul) {
      if (mu.count(mul) == 0) {
        for (const std::pair<int, int> &p : mobius_mu_focusing_on_divisor(mul)) {
          mu[p.first] = p.second;
        }
      }
      pat += ModInt(k / (g * mul)).pow(n) * mu[mul];
    }
    ans += pat * g;
  }
  std::cout << ans << '\n';
  return 0;
}
