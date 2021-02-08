/*
 * @brief 数学/写像12相/スターリング数/第2種スターリング数
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I"

#include <iostream>
#include "../../../../math/modint.hpp"
#include "../../../../math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp"

int main() {
  ModInt::set_mod(1000000007);
  int n, k;
  std::cin >> n >> k;
  Combinatorics com(k);
  std::cout << stirling_number_of_the_second_kind(n, k, com) << '\n';
  return 0;
}
