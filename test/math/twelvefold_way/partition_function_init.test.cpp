/*
 * @title 数学/写像12相/分割数
 *
 * verification-helper: PROBLEM https://yukicoder.me/problems/no/269
 */

#include <iostream>

#include "emthrm/math/modint.hpp"
#include "emthrm/math/twelvefold_way/partition_function.hpp"

int main() {
  using ModInt = emthrm::MInt<1000000007>;
  int n, s, k;
  std::cin >> n >> s >> k;
  for (int i = 1; i < n; ++i) {
    s -= k * i;
  }
  std::cout << (s >= 0 ? emthrm::partition_function<ModInt>(n, s)[n][s] : 0)
            << '\n';
  return 0;
}
