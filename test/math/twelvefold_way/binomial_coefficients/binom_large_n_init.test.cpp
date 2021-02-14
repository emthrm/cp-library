/*
 * @brief 数学/写像12相/二項係数/二項係数 $n$ は巨大な固定値
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071"

#include <iostream>
#include <vector>
#include "../../../../math/modint.hpp"
#include "../../../../math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  long long m, n;
  int k;
  std::cin >> m >> n >> k;
  ModInt ans = ModInt(m).pow(n);
  if (k > 1) {
    std::vector<ModInt> c = binom_large_n_init<0>(m, k - 1);
    for (int i = 1; i < k; ++i) {
      ModInt tmp = 0;
      for (int j = i; j >= 1; --j) tmp += ModInt::nCk(i, j) * ModInt(j).pow(n) * ((i - j) & 1 ? -1 : 1);
      ans -= tmp * c[i];
    }
  }
  std::cout << ans << '\n';
  return 0;
}
