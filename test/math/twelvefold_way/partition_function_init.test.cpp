/*
 * @brief 数学/写像12相/分割数の数表
 */
#define PROBLEM "https://yukicoder.me/problems/no/269"

#include <iostream>
#include "../../../math/modint.hpp"
#include "../../../math/twelvefold_way/partition_function_init.hpp"

int main() {
  using ModInt = MInt<0>;
  ModInt::set_mod(1000000007);
  int n, s, k;
  std::cin >> n >> s >> k;
  for (int i = 1; i < n; ++i) {
    s -= k * i;
  }
  std::cout << (s >= 0 ? partition_function_init<ModInt>(n, s)[n][s] : 0) << '\n';
  return 0;
}
