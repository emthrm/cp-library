/*
 * @title 数学/写像12相/スターリング数/第2種スターリング数の数表
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I
 */

#include <iostream>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n, k;
  std::cin >> n >> k;
  const ModInt ans =
      emthrm::stirling_number_of_the_second_kind_init<ModInt>(n, k)[n][k];
  std::cout << ans << '\n';
  return 0;
}
