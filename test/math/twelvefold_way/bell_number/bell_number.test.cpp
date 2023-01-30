/*
 * @brief 数学/写像12相/ベル数/ベル数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"

#include <iostream>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/bell_number/bell_number.hpp"

int main() {
  constexpr int MOD = 998244353;
  using ModInt = emthrm::MInt<MOD>;
  int n, k;
  std::cin >> n >> k;
  std::cout << emthrm::bell_number<MOD>(n, k) << '\n';
  return 0;
}
