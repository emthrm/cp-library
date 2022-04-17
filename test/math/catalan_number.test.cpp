/*
 * @brief 数学/カタラン数
 */
#define PROBLEM "https://yukicoder.me/problems/no/790"

#include <iostream>

#include "../../math/catalan_number.hpp"
#include "../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(742909);
  int n;
  std::cin >> n;
  std::cout << catalan_number<0>(n)[n] << '\n';
  return 0;
}
