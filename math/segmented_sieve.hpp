#pragma once
#include <algorithm>
#include <cmath>
#include <iterator>
#include <vector>

std::vector<bool> segmented_sieve(const long long low, const long long high) {
  long long root = 1;
  while ((root + 1) * (root + 1) < high) ++root;
  std::vector<bool> is_prime(root + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  std::vector<bool> res(high - low, true);
  if (low < 2) std::fill(res.begin(), std::next(res.begin(), 2 - low), false);
  for (long long i = 2; i <= root; ++i) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= root; j += i) {
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
