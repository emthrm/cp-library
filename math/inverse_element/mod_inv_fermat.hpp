/**
 * @brief 逆元 Fermat の小定理版
 * @docs docs/math/inverse_element/inverse_element.md
 */

#pragma once
#include "../mod_pow.hpp"

long long mod_inv_fermat(long long a, int mod) { return mod_pow(a % mod, mod - 2, mod); }
