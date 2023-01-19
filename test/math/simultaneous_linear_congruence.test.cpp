/*
 * @brief 数学/連立線形合同式
 */
#define PROBLEM "https://yukicoder.me/problems/no/186"

#include <iostream>
#if __cplusplus < 201703L
#include <tuple>
#endif
#include <vector>

#include "emthrm/math/simultaneous_linear_congruence.hpp"

int main() {
  constexpr int N = 3;
  std::vector<long long> x(N), y(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> x[i] >> y[i];
  }
#if __cplusplus >= 201703L
  const auto [ans, mod] = emthrm::simultaneous_linear_congruence(
      std::vector<long long>(N, 1), x, y);
#else
  long long ans, mod;
  std::tie(ans, mod) = emthrm::simultaneous_linear_congruence(
      std::vector<long long>(N, 1), x, y);
#endif
  if (mod == 0) {
    std::cout << "-1\n";
  } else {
    std::cout << (ans == 0 ? mod : ans) << '\n';
  }
  return 0;
}
