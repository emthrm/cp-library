/*
 * @title 数学/写像12相/スターリング数/第2種スターリング数
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I
 */

#include <iostream>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp"

int main() {
  constexpr int MOD = 1000000007;
  using ModInt = emthrm::MInt<MOD>;
  int n, k;
  std::cin >> n >> k;
  std::cout << emthrm::stirling_number_of_the_second_kind<MOD>(n, k) << '\n';
  return 0;
}
