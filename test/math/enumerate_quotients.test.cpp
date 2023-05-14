/*
 * @title 数学/商の列挙
 *
 * verification-helper: PROBLEM https://judge.yosupo.jp/problem/enumerate_quotients
 */

#include <iostream>
#include <tuple>
#include <ranges>

#include "emthrm/math/enumerate_quotients.hpp"

int main() {
  long long n;
  std::cin >> n;
  // GCC 12 adopted P2415.
  const std::vector<std::tuple<long long, long long, long long>> quotients =
      emthrm::enumerate_quotients(n);
  const auto a = quotients | std::views::elements<2> | std::views::reverse;
  // const auto a = emthrm::enumerate_quotients(n)
  //              | std::views::elements<2>
  //              | std::views::reverse;
  const int k = a.size();
  std::cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    std::cout << a[i] << " \n"[i + 1 == k];
  }
  return 0;
}
