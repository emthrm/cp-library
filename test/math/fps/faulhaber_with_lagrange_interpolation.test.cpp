/*
 * @brief 数学/形式的冪級数/ファウルハーバーの公式 ラグランジュ補間版
 */
#define PROBLEM "https://yukicoder.me/problems/no/665"

#include <iostream>
#include "../../../math/fps/faulhaber_with_lagrange_interpolation.hpp"

int main() {
  ModInt::set_mod(1000000007);
  long long n;
  int k;
  std::cin >> n >> k;
  std::cout << faulhaber(n + 1, k) << '\n';
  return 0;
}
