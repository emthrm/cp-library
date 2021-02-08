#pragma once
// #include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

// template <int MOD>
// struct MInt {
//   unsigned val;
//   MInt(): val(0) {}
//   MInt(long long x) : val(x >= 0 ? x % MOD : x % MOD + MOD) {}
//   static int get_mod() { return MOD; }
//   static void set_mod(int divisor) { assert(divisor == MOD); }
//   MInt pow(long long exponent) const {
//     MInt tmp = *this, res = 1;
//     while (exponent > 0) {
//       if (exponent & 1) res *= tmp;
//       tmp *= tmp;
//       exponent >>= 1;
//     }
//     return res;
//   }
//   MInt &operator+=(const MInt &x) { if((val += x.val) >= MOD) val -= MOD; return *this; }
//   MInt &operator-=(const MInt &x) { if((val += MOD - x.val) >= MOD) val -= MOD; return *this; }
//   MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % MOD; return *this; }
//   MInt &operator/=(const MInt &x) {
//     // assert(std::__gcd(static_cast<int>(x.val), MOD) == 1);
//     unsigned a = x.val, b = MOD; int u = 1, v = 0;
//     while (b) {
//       unsigned tmp = a / b;
//       std::swap(a -= tmp * b, b);
//       std::swap(u -= tmp * v, v);
//     }
//     return *this *= u;
//   }
//   bool operator==(const MInt &x) const { return val == x.val; }
//   bool operator!=(const MInt &x) const { return val != x.val; }
//   bool operator<(const MInt &x) const { return val < x.val; }
//   bool operator<=(const MInt &x) const { return val <= x.val; }
//   bool operator>(const MInt &x) const { return val > x.val; }
//   bool operator>=(const MInt &x) const { return val >= x.val; }
//   MInt &operator++() { if (++val == MOD) val = 0; return *this; }
//   MInt operator++(int) { MInt res = *this; ++*this; return res; }
//   MInt &operator--() { val = (val == 0 ? MOD : val) - 1; return *this; }
//   MInt operator--(int) { MInt res = *this; --*this; return res; }
//   MInt operator+() const { return *this; }
//   MInt operator-() const { return MInt(val ? MOD - val : 0); }
//   MInt operator+(const MInt &x) const { return MInt(*this) += x; }
//   MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
//   MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
//   MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
//   friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
//   friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
// };
// namespace std { template <int MOD> MInt<MOD> abs(const MInt<MOD> &x) { return x; } }
// template <int MOD>
// struct Combinatorics {
//   using ModInt = MInt<MOD>;
//   int val;  // "val!" and "mod" must be disjoint.
//   std::vector<ModInt> fact, fact_inv, inv;
//   Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
//     fact[0] = 1;
//     for (int i = 1; i <= val; ++i) fact[i] = fact[i - 1] * i;
//     fact_inv[val] = ModInt(1) / fact[val];
//     for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
//     for (int i = 1; i <= val; ++i) inv[i] = fact[i - 1] * fact_inv[i];
//   }
//   ModInt nCk(int n, int k) const {
//     if (n < 0 || n < k || k < 0) return 0;
//     assert(n <= val && k <= val);
//     return fact[n] * fact_inv[k] * fact_inv[n - k];
//   }
//   ModInt nPk(int n, int k) const {
//     if (n < 0 || n < k || k < 0) return 0;
//     assert(n <= val);
//     return fact[n] * fact_inv[n - k];
//   }
//   ModInt nHk(int n, int k) const {
//     if (n < 0 || k < 0) return 0;
//     return k == 0 ? 1 : nCk(n + k - 1, k);
//   }
// };

struct ModInt {
  unsigned val;
  ModInt(): val(0) {}
  ModInt(long long x) : val(x >= 0 ? x % mod() : x % mod() + mod()) {}
  static int get_mod() { return mod(); }
  static void set_mod(int divisor) { mod() = divisor; }
  ModInt pow(long long exponent) const {
    ModInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  ModInt &operator+=(const ModInt &x) { if((val += x.val) >= mod()) val -= mod(); return *this; }
  ModInt &operator-=(const ModInt &x) { if((val += mod() - x.val) >= mod()) val -= mod(); return *this; }
  ModInt &operator*=(const ModInt &x) { val = static_cast<unsigned long long>(val) * x.val % mod(); return *this; }
  ModInt &operator/=(const ModInt &x) {
    // assert(std::__gcd(static_cast<int>(x.val), mod()) == 1);
    unsigned a = x.val, b = mod(); int u = 1, v = 0;
    while (b) {
      unsigned tmp = a / b;
      std::swap(a -= tmp * b, b);
      std::swap(u -= tmp * v, v);
    }
    return *this *= u;
  }
  bool operator==(const ModInt &x) const { return val == x.val; }
  bool operator!=(const ModInt &x) const { return val != x.val; }
  bool operator<(const ModInt &x) const { return val < x.val; }
  bool operator<=(const ModInt &x) const { return val <= x.val; }
  bool operator>(const ModInt &x) const { return val > x.val; }
  bool operator>=(const ModInt &x) const { return val >= x.val; }
  ModInt &operator++() { if (++val == mod()) val = 0; return *this; }
  ModInt operator++(int) { ModInt res = *this; ++*this; return res; }
  ModInt &operator--() { val = (val == 0 ? mod() : val) - 1; return *this; }
  ModInt operator--(int) { ModInt res = *this; --*this; return res; }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { return ModInt(val ? mod() - val : 0); }
  ModInt operator+(const ModInt &x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt &x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt &x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt &x) const { return ModInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, ModInt &x) { long long val; is >> val; x = ModInt(val); return is; }
private:
  static int &mod() { static int divisor = 0; return divisor; }
};
namespace std { ModInt abs(const ModInt &x) { return x; } }
struct Combinatorics {
  int val;  // "val!" and "mod" must be disjoint.
  std::vector<ModInt> fact, fact_inv, inv;
  Combinatorics(int val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {
    fact[0] = 1;
    for (int i = 1; i <= val; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[val] = ModInt(1) / fact[val];
    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    for (int i = 1; i <= val; ++i) inv[i] = fact[i - 1] * fact_inv[i];
  }
  ModInt nCk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val && k <= val);
    return fact[n] * fact_inv[k] * fact_inv[n - k];
  }
  ModInt nPk(int n, int k) const {
    if (n < 0 || n < k || k < 0) return 0;
    assert(n <= val);
    return fact[n] * fact_inv[n - k];
  }
  ModInt nHk(int n, int k) const {
    if (n < 0 || k < 0) return 0;
    return k == 0 ? 1 : nCk(n + k - 1, k);
  }
};
