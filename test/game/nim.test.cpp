/*
 * @brief ゲーム/ニム
 */
#define PROBLEM "https://yukicoder.me/problems/no/2"

#include <iostream>
#if __cplusplus < 201703L
# include <utility>
#endif  // __cplusplus < 201703L
#include <vector>

#include "emthrm/game/nim.hpp"
#include "emthrm/math/prime_factorization.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a;
#if __cplusplus >= 201703L
  for (const auto& [_, exponent] : emthrm::prime_factorization(n)) {
    a.emplace_back(exponent);
  }
#else
  for (const std::pair<int, int>& p : emthrm::prime_factorization(n)) {
    a.emplace_back(p.second);
  }
#endif  // __cplusplus >= 201703L
  std::cout << (emthrm::nim(a) ? "Alice\n" : "Bob\n");
  return 0;
}
