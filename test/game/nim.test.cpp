/*
 * @title ゲーム/ニム
 */
#define PROBLEM "https://yukicoder.me/problems/no/2"

#include <iostream>
#include <ranges>
#include <utility>
#include <vector>

#include "emthrm/game/nim.hpp"
#include "emthrm/math/prime_factorization.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  // GCC 12 adopted P2415.
  const std::vector<std::pair<int, int>> pf = emthrm::prime_factorization(n);
  const auto ev = pf | std::views::values;
  // const auto ev = emthrm::prime_factorization(n) | std::views::values;
  std::cout << (emthrm::nim(std::vector<int>(ev.begin(), ev.end())) ?
                "Alice\n" : "Bob\n");
  return 0;
}
