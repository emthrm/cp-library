/**
 * @brief オイラーの $\varphi$ 関数の数表2
 * @docs docs/math/euler_phi/euler_phi.md
 */

#pragma once
#include <cmath>
#include <numeric>
#include <vector>
#include "../sieve_of_eratosthenes.hpp"

std::vector<long long> euler_phi_init2(long long low, long long high) {
  int sqrt_high = std::ceil(std::sqrt(high));
  std::vector<bool> primes = sieve_of_eratosthenes(sqrt_high);
  std::vector<long long> phi(high - low), rem(high - low);
  std::iota(phi.begin(), phi.end(), low);
  std::iota(rem.begin(), rem.end(), low);
  for (int prime = 2; prime <= sqrt_high; ++prime) {
    if (primes[prime]) {
      for (long long i = (low + (prime - 1)) / prime * prime; i < high; i += prime) {
        phi[i - low] -= phi[i - low] / prime;
        while (rem[i - low] % prime == 0) rem[i - low] /= prime;
      }
    }
  }
  for (int i = 0; i < high - low; ++i) {
    if (rem[i] > 1) phi[i] -= phi[i] / rem[i];
  }
  return phi;
}
