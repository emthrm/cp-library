/*
 * @brief 数学/カタラン数
 */
#define PROBLEM "https://yukicoder.me/problems/no/790"

#include <iostream>
#include "../../math/modint.hpp"
#include "../../math/catalan_number.hpp"

int main() {
  ModInt::set_mod(742909);
  int n;
  std::cin >> n;
  Combinatorics com(n + 1);
  std::cout << catalan_number(n, com)[n] << '\n';
  return 0;
}
