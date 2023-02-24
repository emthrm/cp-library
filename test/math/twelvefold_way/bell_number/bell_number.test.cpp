/*
 * @title 数学/写像12相/ベル数/ベル数
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
 */

#include <iostream>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/bell_number/bell_number.hpp"

int main() {
  int n, k;
  std::cin >> n >> k;
  std::cout << emthrm::bell_number<1000000007>(n, k) << '\n';
  return 0;
}
