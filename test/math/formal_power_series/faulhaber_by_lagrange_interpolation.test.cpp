/*
 * @brief 数学/形式的冪級数/ファウルハーバーの公式 ラグランジュ補間版
 */
#define PROBLEM "https://yukicoder.me/problems/no/665"

#include <iostream>

#include "../../../math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp"
#include "../../../math/modint.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  long long n;
  int k;
  std::cin >> n >> k;
  std::cout << faulhaber_by_lagrange_interpolation<0>(n + 1, k) << '\n';
  return 0;
}
