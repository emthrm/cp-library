/*
 * @brief 数学/写像12相/二項係数/パスカルの三角形
 */
#define PROBLEM "https://yukicoder.me/problems/no/420"

#include <iostream>
#include <vector>
#include "../../../../math/bigint.hpp"
#include "../../../../math/twelvefold_way/binomial_coefficients/pascal.hpp"

int main() {
  using bigint = BigInt<>;
  constexpr int N = 31;
  std::vector<std::vector<bigint>> c = pascal<bigint>(N);
  int x;
  std::cin >> x;
  if (x > N) {
    std::cout << 0 << ' ' << 0 << '\n';
    return 0;
  }
  std::cout << c[N][x] << ' ';
  bigint ans = 0;
  if (x > 0) {
    for (int bit = 0; bit < N; ++bit) ans += c[N - 1][x - 1] * (1 << bit);
  }
  std::cout << ans << '\n';
  return 0;
}
