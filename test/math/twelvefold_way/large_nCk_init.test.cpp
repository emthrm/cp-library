/*
 * @brief 数学/写像12相/二項係数の数表 巨大な $n$ 版
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071"

#include <iostream>
#include <vector>

#include "../../../math/modint.hpp"
#include "../../../math/twelvefold_way/large_nCk_init.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(998244353);
  long long m, n;
  int k;
  std::cin >> m >> n >> k;
  ModInt ans = ModInt(m).pow(n);
  std::vector<ModInt> c = large_nCk_init<0>(m, k - 1);
  for (int i = 1; i < k; ++i) {
    ModInt tmp = 0;
    for (int j = 1; j <= i; ++j) {
      tmp += ModInt::nCk(i, j)
             * ((i - j) & 1 ? -ModInt(j).pow(n) : ModInt(j).pow(n));
    }
    ans -= tmp * c[i];
  }
  std::cout << ans << '\n';
  return 0;
}
