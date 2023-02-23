/*
 * @brief 数学/商の列挙
 */
#define PROBLEM "https://atcoder.jp/contests/abc230/tasks/abc230_e"

#include <iostream>

#include "emthrm/math/enumerate_quotients.hpp"

int main() {
  long long n;
  std::cin >> n;
  long long ans = 0;
  for (const auto& [l, r, q] : emthrm::enumerate_quotients(n)) {
    ans += q * (r - l);
  }
  std::cout << ans << '\n';
  return 0;
}
