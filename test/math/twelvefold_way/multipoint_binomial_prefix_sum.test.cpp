/*
 * @title 数学/写像12相/二項係数の prefix sum の多点評価
 *
 * verification-helper: PROBLEM https://yukicoder.me/problems/no/2206
 */

#include <iostream>
#include <vector>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp"

int main() {
  constexpr int MOD = 998244353;
  using ModInt = emthrm::MInt<MOD>;
  int t;
  std::cin >> t;
  std::vector<int> n(t), m(t);
  for (int i = 0; i < t; ++i) {
    std::cin >> n[i] >> m[i];
    --n[i];
    --m[i];
  }
  const std::vector<ModInt> sums =
      emthrm::multipoint_binomial_prefix_sum<MOD>(n, m);
  for (int i = 0; i < t; ++i) {
    std::cout << (ModInt::raw(2).pow(n[i] + 1) - 1) * sums[i] << '\n';
  }
  return 0;
}
