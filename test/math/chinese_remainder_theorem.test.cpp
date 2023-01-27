/*
 * @brief 数学/中国剰余定理
 */
#define PROBLEM "https://yukicoder.me/problems/no/186"

#include <iostream>
#if __cplusplus < 201703L
# include <tuple>
#endif  // __cplusplus < 201703L
#include <vector>

#include "emthrm/math/chinese_remainder_theorem.hpp"

int main() {
  constexpr int N = 3;
  std::vector<long long> x(N), y(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> x[i] >> y[i];
  }
#if __cplusplus >= 201703L
  const auto [ans, mod] = emthrm::chinese_remainder_theorem(x, y);
#else
  long long ans, mod;
  std::tie(ans, mod) = emthrm::chinese_remainder_theorem(x, y);
#endif  // __cplusplus >= 201703L
  if (mod == 0) {
    std::cout << "-1\n";
  } else {
    std::cout << (ans == 0 ? mod : ans) << '\n';
  }
  return 0;
}
