---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/catalan_number.hpp
    title: "\u30AB\u30BF\u30E9\u30F3\u6570 (Catalan number)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/790
    document_title: "\u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570"
    links:
    - https://yukicoder.me/problems/no/790
  bundledCode: "#line 1 \"test/math/catalan_number.test.cpp\"\n/*\r\n * @brief \u6570\
    \u5B66/\u30AB\u30BF\u30E9\u30F3\u6570\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/790\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"math/modint.hpp\"\n// #include <algorithm>\r\
    \n#include <cassert>\r\n#line 5 \"math/modint.hpp\"\n#include <utility>\r\n#include\
    \ <vector>\r\n\r\n// template <int MOD>\r\n// struct MInt {\r\n//   unsigned val;\r\
    \n//   MInt(): val(0) {}\r\n//   MInt(long long x) : val(x >= 0 ? x % MOD : x\
    \ % MOD + MOD) {}\r\n//   static int get_mod() { return MOD; }\r\n//   static\
    \ void set_mod(int divisor) { assert(divisor == MOD); }\r\n//   MInt pow(long\
    \ long exponent) const {\r\n//     MInt tmp = *this, res = 1;\r\n//     while\
    \ (exponent > 0) {\r\n//       if (exponent & 1) res *= tmp;\r\n//       tmp *=\
    \ tmp;\r\n//       exponent >>= 1;\r\n//     }\r\n//     return res;\r\n//   }\r\
    \n//   MInt &operator+=(const MInt &x) { if((val += x.val) >= MOD) val -= MOD;\
    \ return *this; }\r\n//   MInt &operator-=(const MInt &x) { if((val += MOD - x.val)\
    \ >= MOD) val -= MOD; return *this; }\r\n//   MInt &operator*=(const MInt &x)\
    \ { val = static_cast<unsigned long long>(val) * x.val % MOD; return *this; }\r\
    \n//   MInt &operator/=(const MInt &x) {\r\n//     // assert(std::__gcd(static_cast<int>(x.val),\
    \ MOD) == 1);\r\n//     unsigned a = x.val, b = MOD; int u = 1, v = 0;\r\n// \
    \    while (b) {\r\n//       unsigned tmp = a / b;\r\n//       std::swap(a -=\
    \ tmp * b, b);\r\n//       std::swap(u -= tmp * v, v);\r\n//     }\r\n//     return\
    \ *this *= u;\r\n//   }\r\n//   bool operator==(const MInt &x) const { return\
    \ val == x.val; }\r\n//   bool operator!=(const MInt &x) const { return val !=\
    \ x.val; }\r\n//   bool operator<(const MInt &x) const { return val < x.val; }\r\
    \n//   bool operator<=(const MInt &x) const { return val <= x.val; }\r\n//   bool\
    \ operator>(const MInt &x) const { return val > x.val; }\r\n//   bool operator>=(const\
    \ MInt &x) const { return val >= x.val; }\r\n//   MInt &operator++() { if (++val\
    \ == MOD) val = 0; return *this; }\r\n//   MInt operator++(int) { MInt res = *this;\
    \ ++*this; return res; }\r\n//   MInt &operator--() { val = (val == 0 ? MOD :\
    \ val) - 1; return *this; }\r\n//   MInt operator--(int) { MInt res = *this; --*this;\
    \ return res; }\r\n//   MInt operator+() const { return *this; }\r\n//   MInt\
    \ operator-() const { return MInt(val ? MOD - val : 0); }\r\n//   MInt operator+(const\
    \ MInt &x) const { return MInt(*this) += x; }\r\n//   MInt operator-(const MInt\
    \ &x) const { return MInt(*this) -= x; }\r\n//   MInt operator*(const MInt &x)\
    \ const { return MInt(*this) *= x; }\r\n//   MInt operator/(const MInt &x) const\
    \ { return MInt(*this) /= x; }\r\n//   friend std::ostream &operator<<(std::ostream\
    \ &os, const MInt &x) { return os << x.val; }\r\n//   friend std::istream &operator>>(std::istream\
    \ &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }\r\n//\
    \ };\r\n// namespace std { template <int MOD> MInt<MOD> abs(const MInt<MOD> &x)\
    \ { return x; } }\r\n// template <int MOD>\r\n// struct Combinatorics {\r\n//\
    \   using ModInt = MInt<MOD>;\r\n//   int val;  // \"val!\" and \"mod\" must be\
    \ disjoint.\r\n//   std::vector<ModInt> fact, fact_inv, inv;\r\n//   Combinatorics(int\
    \ val = 10000000) : val(val), fact(val + 1), fact_inv(val + 1), inv(val + 1) {\r\
    \n//     fact[0] = 1;\r\n//     for (int i = 1; i <= val; ++i) fact[i] = fact[i\
    \ - 1] * i;\r\n//     fact_inv[val] = ModInt(1) / fact[val];\r\n//     for (int\
    \ i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\r\n//     for (int i\
    \ = 1; i <= val; ++i) inv[i] = fact[i - 1] * fact_inv[i];\r\n//   }\r\n//   ModInt\
    \ nCk(int n, int k) const {\r\n//     if (n < 0 || n < k || k < 0) return 0;\r\
    \n//     assert(n <= val && k <= val);\r\n//     return fact[n] * fact_inv[k]\
    \ * fact_inv[n - k];\r\n//   }\r\n//   ModInt nPk(int n, int k) const {\r\n//\
    \     if (n < 0 || n < k || k < 0) return 0;\r\n//     assert(n <= val);\r\n//\
    \     return fact[n] * fact_inv[n - k];\r\n//   }\r\n//   ModInt nHk(int n, int\
    \ k) const {\r\n//     if (n < 0 || k < 0) return 0;\r\n//     return k == 0 ?\
    \ 1 : nCk(n + k - 1, k);\r\n//   }\r\n// };\r\n\r\nstruct ModInt {\r\n  unsigned\
    \ val;\r\n  ModInt(): val(0) {}\r\n  ModInt(long long x) : val(x >= 0 ? x % mod()\
    \ : x % mod() + mod()) {}\r\n  static int get_mod() { return mod(); }\r\n  static\
    \ void set_mod(int divisor) { mod() = divisor; }\r\n  ModInt pow(long long exponent)\
    \ const {\r\n    ModInt tmp = *this, res = 1;\r\n    while (exponent > 0) {\r\n\
    \      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n      exponent >>=\
    \ 1;\r\n    }\r\n    return res;\r\n  }\r\n  ModInt &operator+=(const ModInt &x)\
    \ { if((val += x.val) >= mod()) val -= mod(); return *this; }\r\n  ModInt &operator-=(const\
    \ ModInt &x) { if((val += mod() - x.val) >= mod()) val -= mod(); return *this;\
    \ }\r\n  ModInt &operator*=(const ModInt &x) { val = static_cast<unsigned long\
    \ long>(val) * x.val % mod(); return *this; }\r\n  ModInt &operator/=(const ModInt\
    \ &x) {\r\n    // assert(std::__gcd(static_cast<int>(x.val), mod()) == 1);\r\n\
    \    unsigned a = x.val, b = mod(); int u = 1, v = 0;\r\n    while (b) {\r\n \
    \     unsigned tmp = a / b;\r\n      std::swap(a -= tmp * b, b);\r\n      std::swap(u\
    \ -= tmp * v, v);\r\n    }\r\n    return *this *= u;\r\n  }\r\n  bool operator==(const\
    \ ModInt &x) const { return val == x.val; }\r\n  bool operator!=(const ModInt\
    \ &x) const { return val != x.val; }\r\n  bool operator<(const ModInt &x) const\
    \ { return val < x.val; }\r\n  bool operator<=(const ModInt &x) const { return\
    \ val <= x.val; }\r\n  bool operator>(const ModInt &x) const { return val > x.val;\
    \ }\r\n  bool operator>=(const ModInt &x) const { return val >= x.val; }\r\n \
    \ ModInt &operator++() { if (++val == mod()) val = 0; return *this; }\r\n  ModInt\
    \ operator++(int) { ModInt res = *this; ++*this; return res; }\r\n  ModInt &operator--()\
    \ { val = (val == 0 ? mod() : val) - 1; return *this; }\r\n  ModInt operator--(int)\
    \ { ModInt res = *this; --*this; return res; }\r\n  ModInt operator+() const {\
    \ return *this; }\r\n  ModInt operator-() const { return ModInt(val ? mod() -\
    \ val : 0); }\r\n  ModInt operator+(const ModInt &x) const { return ModInt(*this)\
    \ += x; }\r\n  ModInt operator-(const ModInt &x) const { return ModInt(*this)\
    \ -= x; }\r\n  ModInt operator*(const ModInt &x) const { return ModInt(*this)\
    \ *= x; }\r\n  ModInt operator/(const ModInt &x) const { return ModInt(*this)\
    \ /= x; }\r\n  friend std::ostream &operator<<(std::ostream &os, const ModInt\
    \ &x) { return os << x.val; }\r\n  friend std::istream &operator>>(std::istream\
    \ &is, ModInt &x) { long long val; is >> val; x = ModInt(val); return is; }\r\n\
    private:\r\n  static int &mod() { static int divisor = 0; return divisor; }\r\n\
    };\r\nnamespace std { ModInt abs(const ModInt &x) { return x; } }\r\nstruct Combinatorics\
    \ {\r\n  int val;  // \"val!\" and \"mod\" must be disjoint.\r\n  std::vector<ModInt>\
    \ fact, fact_inv, inv;\r\n  Combinatorics(int val = 10000000) : val(val), fact(val\
    \ + 1), fact_inv(val + 1), inv(val + 1) {\r\n    fact[0] = 1;\r\n    for (int\
    \ i = 1; i <= val; ++i) fact[i] = fact[i - 1] * i;\r\n    fact_inv[val] = ModInt(1)\
    \ / fact[val];\r\n    for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i]\
    \ * i;\r\n    for (int i = 1; i <= val; ++i) inv[i] = fact[i - 1] * fact_inv[i];\r\
    \n  }\r\n  ModInt nCk(int n, int k) const {\r\n    if (n < 0 || n < k || k < 0)\
    \ return 0;\r\n    assert(n <= val && k <= val);\r\n    return fact[n] * fact_inv[k]\
    \ * fact_inv[n - k];\r\n  }\r\n  ModInt nPk(int n, int k) const {\r\n    if (n\
    \ < 0 || n < k || k < 0) return 0;\r\n    assert(n <= val);\r\n    return fact[n]\
    \ * fact_inv[n - k];\r\n  }\r\n  ModInt nHk(int n, int k) const {\r\n    if (n\
    \ < 0 || k < 0) return 0;\r\n    return k == 0 ? 1 : nCk(n + k - 1, k);\r\n  }\r\
    \n};\r\n#line 5 \"math/catalan_number.hpp\"\n\r\nstd::vector<ModInt> catalan_number(int\
    \ n, const Combinatorics &com) {\r\n  assert(n + 1 <= com.val);\r\n  std::vector<ModInt>\
    \ catalan(n + 1);\r\n  catalan[0] = 1;\r\n  for (int i = 0; i < n; ++i) catalan[i\
    \ + 1] = catalan[i] * com.inv[i + 2] * 2 * (2 * i + 1);\r\n  return catalan;\r\
    \n}\r\n#line 9 \"test/math/catalan_number.test.cpp\"\n\r\nint main() {\r\n  ModInt::set_mod(742909);\r\
    \n  int n;\r\n  std::cin >> n;\r\n  Combinatorics com(n + 1);\r\n  std::cout <<\
    \ catalan_number(n, com)[n] << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570\r\n */\r\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/790\"\r\n\r\n#include <iostream>\r\
    \n#include \"../../math/modint.hpp\"\r\n#include \"../../math/catalan_number.hpp\"\
    \r\n\r\nint main() {\r\n  ModInt::set_mod(742909);\r\n  int n;\r\n  std::cin >>\
    \ n;\r\n  Combinatorics com(n + 1);\r\n  std::cout << catalan_number(n, com)[n]\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/catalan_number.hpp
  isVerificationFile: true
  path: test/math/catalan_number.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/catalan_number.test.cpp
layout: document
redirect_from:
- /verify/test/math/catalan_number.test.cpp
- /verify/test/math/catalan_number.test.cpp.html
title: "\u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570"
---
