/*
 * @brief 数学/写像12相/二項係数/二項係数 $n$ は巨大
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071"

#include <iostream>
#include "../../../../math/modint.hpp"
#include "../../../../math/twelvefold_way/binomial_coefficients/binom_large_n.hpp"

int main() {
  ModInt::set_mod(998244353);
  long long m, n;
  int k;
  std::cin >> m >> n >> k;
  Combinatorics com(k);
  ModInt ans = ModInt(m).pow(n);
  if (k > 1) {
    for (int i = 1; i < k; ++i) {
      ModInt tmp = 0;
      for (int j = i; j >= 1; --j) tmp += com.nCk(i, j) * ModInt(j).pow(n) * ((i - j) & 1 ? -1 : 1);
      ans -= tmp * binom_large_n(m, i, com);
    }
  }
  std::cout << ans << '\n';
  return 0;
}
