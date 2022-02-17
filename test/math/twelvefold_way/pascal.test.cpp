/*
 * @brief 数学/写像12相/パスカルの三角形
 */
#define PROBLEM "https://yukicoder.me/problems/no/420"

#include <iostream>
#include <vector>

#include "../../../math/bigint.hpp"
#include "../../../math/twelvefold_way/pascal.hpp"

int main() {
  using bigint = BigInt<>;
  constexpr int B = 31;
  const std::vector<std::vector<bigint>> c = pascal<bigint>(B);
  int x;
  std::cin >> x;
  if (x == 0) {
    std::cout << 1 << ' ' << 0 << '\n';
  } else if (x > B) {
    std::cout << 0 << ' ' << 0 << '\n';
  } else {
    std::cout << c[B][x] << ' ';
    bigint ans = 0;
    for (int b = 0; b < B; ++b) {
      ans += c[B - 1][x - 1] * (1 << b);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
