/*
 * @brief 数学/写像12相/ベル数/ベル数の数表
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G"

#include <iostream>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/bell_number/bell_number_init.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n, k;
  std::cin >> n >> k;
  std::cout << emthrm::bell_number_init<ModInt>(n, k)[n][k] << '\n';
  return 0;
}
