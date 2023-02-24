/*
 * @title 数学/segmented sieve
 *
 * verification-helper: IGNORE
 * verification-helper: PROBLEM https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt
 */

#include <algorithm>
#include <iostream>

#include "emthrm/math/segmented_sieve.hpp"

int main() {
  long long l, r;
  std::cin >> l >> r;
  std::cout << std::ranges::count(emthrm::segmented_sieve(l, r + 1), true)
            << '\n';
  return 0;
}
