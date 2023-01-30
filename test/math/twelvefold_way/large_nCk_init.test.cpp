/*
 * @brief 数学/写像12相/二項係数の数表 巨大な $n$ 版
 */
#define PROBLEM "https://yukicoder.me/problems/no/2130"

#include <iostream>
#include <numeric>
#include <vector>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/large_nCk_init.hpp"

int main() {
  constexpr int MOD = 998244353;
  using ModInt = emthrm::MInt<MOD>;
  long long n;
  int m;
  std::cin >> n >> m;
  const std::vector<ModInt> c = emthrm::large_nCk_init<MOD>(n, m - 1);
  std::cout << ModInt(2).pow(n) - std::accumulate(c.begin(), c.end(), ModInt(0))
            << '\n';
  return 0;
}
