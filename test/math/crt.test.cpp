/*
 * @brief 数学/中国剰余定理
 */
#define PROBLEM "https://yukicoder.me/problems/no/186"

#include <iostream>
#include <tuple>
#include <vector>
#include "../../math/crt.hpp"

int main() {
  constexpr int N = 3;
  std::vector<long long> x(N), y(N);
  for (int i = 0; i < N; ++i) std::cin >> x[i] >> y[i];
  long long ans, mod; std::tie(ans, mod) = crt(x, y);
  if (mod == -1) {
    std::cout << "-1\n";
  } else {
    std::cout << (ans == 0 ? mod : ans) << '\n';
  }
  return 0;
}
