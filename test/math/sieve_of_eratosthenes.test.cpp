/*
 * @brief 数学/エラトステネスの篩
 */
#define IGNORE
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009"

#include <algorithm>
#include <iostream>
#include <vector>
#include "../../math/sieve_of_eratosthenes.hpp"

int main() {
  constexpr int MAX = 999999;
  std::vector<bool> table = sieve_of_eratosthenes(MAX);
  std::vector<int> primes;
  for (int i = 2; i <= MAX; ++i) {
    if (table[i]) primes.emplace_back(i);
  }
  int n;
  while (std::cin >> n) std::cout << std::upper_bound(primes.begin(), primes.end(), n) - primes.begin() << '\n';
  return 0;
}
