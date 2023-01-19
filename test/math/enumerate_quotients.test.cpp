/*
 * @brief 数学/商の列挙
 */
#define PROBLEM "https://atcoder.jp/contests/abc230/tasks/abc230_e"

#include <iostream>
#if __cplusplus < 201703L
#include <tuple>
#endif

#include "emthrm/math/enumerate_quotients.hpp"

int main() {
  long long n;
  std::cin >> n;
  long long ans = 0;
#if __cplusplus >= 201703L
  for (const auto& [l, r, q] : emthrm::enumerate_quotients(n)) {
#else
  for (const std::tuple<long long, long long, long long>& lrq
       : emthrm::enumerate_quotients(n)) {
    long long l, r, q;
    std::tie(l, r, q) = lrq;
#endif
    ans += q * (r - l);
  }
  std::cout << ans << '\n';
  return 0;
}
