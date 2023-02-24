/*
 * @title 数学/ヤコビ記号
 *
 * verification-helper: PROBLEM https://yukicoder.me/problems/no/984
 */

#include <iostream>

#include "emthrm/math/jacobi_symbol.hpp"

int main() {
  int p, n;
  std::cin >> p >> n;
  std::cout << (n > 1 && emthrm::jacobi_symbol(n, p) == -1 ? 1 : 0) << '\n';
  return 0;
}
