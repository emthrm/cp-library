/*
 * @brief 数学/カタラン数
 */
#define PROBLEM "https://yukicoder.me/problems/no/790"

#include <iostream>

#include "emthrm/math/catalan_number.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  constexpr int MOD = 742909;
  using ModInt = emthrm::MInt<MOD>;
  int n;
  std::cin >> n;
  std::cout << emthrm::catalan_number<MOD>(n)[n] << '\n';
  return 0;
}
