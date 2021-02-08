/**
 * @brief 二項係数
 * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
 */

#pragma once
#include <cassert>
#include <vector>
#include "../../inverse_element/mod_inv_extgcd.hpp"

struct BinomialCoefficients {
  int val, mod;
  std::vector<long long> fact, fact_inv;

  BinomialCoefficients(int mod, int val = 10000000) : mod(mod), val(val), fact(val + 1), fact_inv(val + 1) {
    fact[0] = 1;
    for (int i = 1; i <= val; ++i) fact[i] = fact[i - 1] * i % mod;
    fact_inv[val] = mod_inv_extgcd(fact[val], mod);
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i % mod;
  }

  long long query(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] % mod * fact_inv[n - k] % mod;
  }
};
