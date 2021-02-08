#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

std::vector<bool> segmented_sieve(long long low, long long high) {
  std::vector<bool> is_prime(static_cast<int>(std::ceil(std::sqrt(high))), true), res(high - low, true);
  is_prime[0] = false;
  if (is_prime.size() >= 2) is_prime[1] = false;
  for (long long i = low; i <= 1; ++i) res[i - low] = false;
  for (long long i = 2; i * i < high; ++i) {
    if (is_prime[i]) {
      for (long long j = i * i; j * j < high; j += i) is_prime[j] = false;
      for (long long j = std::max((low + i - 1) / i, 2LL) * i; j < high; j += i) res[j - low] = false;
    }
  }
  return res;
}
