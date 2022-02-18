/*
 * @brief 数学/繰り返し二乗法
 */
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include <iostream>

#include "../../math/mod_pow.hpp"

int main() {
  int m, n;
  std::cin >> m >> n;
  std::cout << mod_pow(m, n, 1000000007) << '\n';
  return 0;
}
