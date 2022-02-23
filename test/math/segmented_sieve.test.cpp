/*
 * @brief 数学/segmented sieve
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../../math/segmented_sieve.hpp"

int main() {
  long long l, r;
  std::cin >> l >> r;
  const std::vector<bool> is_prime = segmented_sieve(l, r + 1);
  std::cout << std::count(is_prime.begin(), is_prime.end(), true) << '\n';
  return 0;
}
