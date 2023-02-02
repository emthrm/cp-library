/*
 * @brief ゲーム/ニム
 */
#define PROBLEM "https://yukicoder.me/problems/no/2"

#include <iostream>
#include <vector>

#include "emthrm/game/nim.hpp"
#include "emthrm/math/prime_factorization.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  for (const auto& [_, exponent] : emthrm::prime_factorization(n)) {
    a.emplace_back(exponent);
  }
  std::cout << (emthrm::nim(a) ? "Alice\n" : "Bob\n");
  return 0;
}
