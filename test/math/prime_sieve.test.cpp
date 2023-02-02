/*
 * @brief 数学/prime sieve
 */
#define PROBLEM "https://yukicoder.me/problems/no/843"

#include <iostream>
#include <set>
#include <vector>

#include "emthrm/math/prime_sieve.hpp"

int main() {
  int n;
  std::cin >> n;
  const std::vector<int> tmp = emthrm::prime_sieve(n, true);
  const std::set<int> prime(tmp.begin(), tmp.end());
  int ans = 0;
  for (const int p : prime) {
    if (p * p - 2 > n) break;
    if (prime.contains(p * p - 2)) ans += (p == 2 ? 1 : 2);
  }
  std::cout << ans << '\n';
  return 0;
}
