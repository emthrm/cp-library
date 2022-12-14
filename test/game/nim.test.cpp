/*
 * @brief ゲーム/ニム
 */
#define PROBLEM "https://yukicoder.me/problems/no/2"

#include <iostream>
#include <utility>
#include <vector>

#include "emthrm/game/nim.hpp"
#include "emthrm/math/prime_factorization.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  for (const std::pair<int, int>& p : prime_factorization(n)) {
    a.emplace_back(p.second);
  }
  std::cout << (nim(a) ? "Alice\n" : "Bob\n");
  return 0;
}
