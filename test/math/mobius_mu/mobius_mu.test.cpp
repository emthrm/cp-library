/*
 * @brief 数学/メビウス関数/メビウス関数
 */
#define PROBLEM "https://atcoder.jp/contests/abc162/tasks/abc162_e"

#include <iostream>
#include "../../../math/modint.hpp"
#include "../../../math/mobius_mu/mobius_mu.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int n, k;
  std::cin >> n >> k;
  ModInt ans = 0;
  for (int g = 1; g <= k; ++g) {
    ModInt pat = 0;
    for (int mul = 1; g * mul <= k; ++mul) {
      pat += ModInt(k / (g * mul)).pow(n) * mobius_mu(mul);
    }
    ans += pat * g;
  }
  std::cout << ans << '\n';
  return 0;
}
