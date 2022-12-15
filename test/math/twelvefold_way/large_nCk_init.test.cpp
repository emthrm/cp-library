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
  using ModInt = emthrm::MInt<0>;
  ModInt::set_mod(998244353);
  long long n;
  int m;
  std::cin >> n >> m;
  const std::vector<ModInt> c = emthrm::large_nCk_init<0>(n, m - 1);
  std::cout << ModInt(2).pow(n) - std::accumulate(c.begin(), c.end(), ModInt(0))
            << '\n';
  return 0;
}
