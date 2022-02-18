#pragma once
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

std::vector<bool> segmented_sieve(const long long low, const long long high) {
  std::vector<bool> is_prime(static_cast<int>(std::ceil(std::sqrt(high))),
                             true);
  is_prime[0] = false;
  if (is_prime.size() >= 2) is_prime[1] = false;
  std::vector<bool> res(high - low, true);
  if (low < 2) std::fill(res.begin(), std::next(res.begin(), 2 - low), false);
  for (long long i = 2; i * i < high; ++i) {
    if (is_prime[i]) {
      for (long long j = i * i; j * j < high; j += i) {
        is_prime[j] = false;
      }
      for (long long j = std::max((low + i - 1) / i, 2LL) * i; j < high;
           j += i) {
        res[j - low] = false;
      }
    }
  }
  return res;
}
