/*
 * @brief 数学/形式的冪級数/ファウルハーバーの公式 ラグランジュ補間版
 */
#define PROBLEM "https://yukicoder.me/problems/no/665"

#include <iostream>

#include "emthrm/math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  constexpr int MOD = 1000000007;
  long long n;
  int k;
  std::cin >> n >> k;
  std::cout << emthrm::faulhaber_by_lagrange_interpolation<MOD>(n + 1, k)
            << '\n';
  return 0;
}
