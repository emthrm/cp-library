/*
 * @brief ゲーム/ニム
 */
#define PROBLEM "https://yukicoder.me/problems/no/2"

#include <iostream>
#include <ranges>
#include <vector>

#include "emthrm/game/nim.hpp"
#include "emthrm/math/prime_factorization.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  const auto ev = emthrm::prime_factorization(n) | std::views::values;
  std::cout << (emthrm::nim(std::vector<int>(ev.begin(), ev.end())) ?
                "Alice\n" : "Bob\n");
  return 0;
}
