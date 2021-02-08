/**
 * @brief 逆元 オイラーの定理版
 * @docs docs/math/inverse_element/inverse_element.md
 */

#pragma once
#include "../mod_pow.hpp"
#include "../euler_phi/euler_phi.hpp"

long long mod_inv_phi(long long a, int mod) { return mod_pow(a % mod, euler_phi(mod) - 1, mod); }
