/*
 * @title 数学/写像12相/二項係数 巨大な $n$ 版
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3071
 */

#include <iostream>
#include "emthrm/math/modint.hpp"

int main() {
  using ModInt = emthrm::MInt<998244353>;
  long long m, n;
  int k;
  std::cin >> m >> n >> k;
  ModInt::init(k);
  ModInt ans = ModInt(m).pow(n);
  for (int i = 1; i < k; ++i) {
    ModInt tmp = 0;
    for (int j = 1; j <= i; ++j) {
      tmp += ModInt::nCk(i, j)
             * ((i - j) & 1 ? -ModInt(j).pow(n) : ModInt(j).pow(n));
    }
    ans -= tmp * ModInt::large_nCk(m, i);
  }
  std::cout << ans << '\n';
  return 0;
}
