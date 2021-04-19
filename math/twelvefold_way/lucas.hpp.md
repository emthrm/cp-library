---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/twelvefold_way/lucas.test.cpp
    title: test/math/twelvefold_way/lucas.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.hpp\"\n// #include <algorithm>\r\n// #include\
    \ <cassert>\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\n// template <int M>\r\n// struct MInt {\r\n//   unsigned int val;\r\n//\
    \   MInt(): val(0) {}\r\n//   MInt(long long x) : val(x >= 0 ? x % M : x % M +\
    \ M) {}\r\n//   static constexpr int get_mod() { return M; }\r\n//   static void\
    \ set_mod(int divisor) { assert(divisor == M); }\r\n//   static void init(int\
    \ x = 10000000) { inv(x, true); fact(x); fact_inv(x); }\r\n//   static MInt inv(int\
    \ x, bool init = false) {\r\n//     // assert(0 <= x && x < M && std::__gcd(x,\
    \ M) == 1);\r\n//     static std::vector<MInt> inverse{0, 1};\r\n//     int prev\
    \ = inverse.size();\r\n//     if (init && x >= prev) {\r\n//       // \"x!\" and\
    \ \"M\" must be disjoint.\r\n//       inverse.resize(x + 1);\r\n//       for (int\
    \ i = prev; i <= x; ++i) inverse[i] = -inverse[M % i] * (M / i);\r\n//     }\r\
    \n//     if (x < inverse.size()) return inverse[x];\r\n//     unsigned int a =\
    \ x, b = M; int u = 1, v = 0;\r\n//     while (b) {\r\n//       unsigned int q\
    \ = a / b;\r\n//       std::swap(a -= q * b, b);\r\n//       std::swap(u -= q\
    \ * v, v);\r\n//     }\r\n//     return u;\r\n//   }\r\n//   static MInt fact(int\
    \ x) {\r\n//     static std::vector<MInt> f{1};\r\n//     int prev = f.size();\r\
    \n//     if (x >= prev) {\r\n//       f.resize(x + 1);\r\n//       for (int i\
    \ = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n//     }\r\n//     return f[x];\r\
    \n//   }\r\n//   static MInt fact_inv(int x) {\r\n//     static std::vector<MInt>\
    \ finv{1};\r\n//     int prev = finv.size();\r\n//     if (x >= prev) {\r\n//\
    \       finv.resize(x + 1);\r\n//       finv[x] = inv(fact(x).val);\r\n//    \
    \   for (int i = x; i > prev; --i) finv[i - 1] = finv[i] * i;\r\n//     }\r\n\
    //     return finv[x];\r\n//   }\r\n//   static MInt nCk(int n, int k) {\r\n//\
    \     if (n < 0 || n < k || k < 0) return 0;\r\n//     if (n - k > k) k = n -\
    \ k;\r\n//     return fact(n) * fact_inv(k) * fact_inv(n - k);\r\n//   }\r\n//\
    \   static MInt nPk(int n, int k) { return n < 0 || n < k || k < 0 ? 0 : fact(n)\
    \ * fact_inv(n - k); }\r\n//   static MInt nHk(int n, int k) { return n < 0 ||\
    \ k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n//   static MInt large_nCk(long\
    \ long n, int k) {\r\n//     if (n < 0 || n < k || k < 0) return 0;\r\n//    \
    \ inv(k, true);\r\n//     MInt res = 1;\r\n//     for (int i = 1; i <= k; ++i)\
    \ res *= inv(i) * n--;\r\n//     return res;\r\n//   }\r\n//   MInt pow(long long\
    \ exponent) const {\r\n//     MInt tmp = *this, res = 1;\r\n//     while (exponent\
    \ > 0) {\r\n//       if (exponent & 1) res *= tmp;\r\n//       tmp *= tmp;\r\n\
    //       exponent >>= 1;\r\n//     }\r\n//     return res;\r\n//   }\r\n//   MInt\
    \ &operator+=(const MInt &x) { if((val += x.val) >= M) val -= M; return *this;\
    \ }\r\n//   MInt &operator-=(const MInt &x) { if((val += M - x.val) >= M) val\
    \ -= M; return *this; }\r\n//   MInt &operator*=(const MInt &x) { val = static_cast<unsigned\
    \ long long>(val) * x.val % M; return *this; }\r\n//   MInt &operator/=(const\
    \ MInt &x) { return *this *= inv(x.val); }\r\n//   bool operator==(const MInt\
    \ &x) const { return val == x.val; }\r\n//   bool operator!=(const MInt &x) const\
    \ { return val != x.val; }\r\n//   bool operator<(const MInt &x) const { return\
    \ val < x.val; }\r\n//   bool operator<=(const MInt &x) const { return val <=\
    \ x.val; }\r\n//   bool operator>(const MInt &x) const { return val > x.val; }\r\
    \n//   bool operator>=(const MInt &x) const { return val >= x.val; }\r\n//   MInt\
    \ &operator++() { if (++val == M) val = 0; return *this; }\r\n//   MInt operator++(int)\
    \ { MInt res = *this; ++*this; return res; }\r\n//   MInt &operator--() { val\
    \ = (val == 0 ? M : val) - 1; return *this; }\r\n//   MInt operator--(int) { MInt\
    \ res = *this; --*this; return res; }\r\n//   MInt operator+() const { return\
    \ *this; }\r\n//   MInt operator-() const { return MInt(val ? M - val : 0); }\r\
    \n//   MInt operator+(const MInt &x) const { return MInt(*this) += x; }\r\n//\
    \   MInt operator-(const MInt &x) const { return MInt(*this) -= x; }\r\n//   MInt\
    \ operator*(const MInt &x) const { return MInt(*this) *= x; }\r\n//   MInt operator/(const\
    \ MInt &x) const { return MInt(*this) /= x; }\r\n//   friend std::ostream &operator<<(std::ostream\
    \ &os, const MInt &x) { return os << x.val; }\r\n//   friend std::istream &operator>>(std::istream\
    \ &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }\r\n//\
    \ };\r\n// namespace std { template <int M> MInt<M> abs(const MInt<M> &x) { return\
    \ x; } }\r\n\r\ntemplate <int ID>\r\nstruct MInt {\r\n  unsigned int val;\r\n\
    \  MInt(): val(0) {}\r\n  MInt(long long x) : val(x >= 0 ? x % mod() : x % mod()\
    \ + mod()) {}\r\n  static int get_mod() { return mod(); }\r\n  static void set_mod(int\
    \ divisor) { mod() = divisor; }\r\n  static void init(int x = 10000000) { inv(x,\
    \ true); fact(x); fact_inv(x); }\r\n  static MInt inv(int x, bool init = false)\
    \ {\r\n    // assert(0 <= x && x < mod() && std::__gcd(x, mod()) == 1);\r\n  \
    \  static std::vector<MInt> inverse{0, 1};\r\n    int prev = inverse.size();\r\
    \n    if (init && x >= prev) {\r\n      // \"x!\" and \"mod()\" must be disjoint.\r\
    \n      inverse.resize(x + 1);\r\n      for (int i = prev; i <= x; ++i) inverse[i]\
    \ = -inverse[mod() % i] * (mod() / i);\r\n    }\r\n    if (x < inverse.size())\
    \ return inverse[x];\r\n    unsigned int a = x, b = mod(); int u = 1, v = 0;\r\
    \n    while (b) {\r\n      unsigned int q = a / b;\r\n      std::swap(a -= q *\
    \ b, b);\r\n      std::swap(u -= q * v, v);\r\n    }\r\n    return u;\r\n  }\r\
    \n  static MInt fact(int x) {\r\n    static std::vector<MInt> f{1};\r\n    int\
    \ prev = f.size();\r\n    if (x >= prev) {\r\n      f.resize(x + 1);\r\n     \
    \ for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n    }\r\n    return\
    \ f[x];\r\n  }\r\n  static MInt fact_inv(int x) {\r\n    static std::vector<MInt>\
    \ finv{1};\r\n    int prev = finv.size();\r\n    if (x >= prev) {\r\n      finv.resize(x\
    \ + 1);\r\n      finv[x] = inv(fact(x).val);\r\n      for (int i = x; i > prev;\
    \ --i) finv[i - 1] = finv[i] * i;\r\n    }\r\n    return finv[x];\r\n  }\r\n \
    \ static MInt nCk(int n, int k) {\r\n    if (n < 0 || n < k || k < 0) return 0;\r\
    \n    if (n - k > k) k = n - k;\r\n    return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n  }\r\n  static MInt nPk(int n, int k) { return n < 0 || n < k || k\
    \ < 0 ? 0 : fact(n) * fact_inv(n - k); }\r\n  static MInt nHk(int n, int k) {\
    \ return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n  static\
    \ MInt large_nCk(long long n, int k) {\r\n    if (n < 0 || n < k || k < 0) return\
    \ 0;\r\n    inv(k, true);\r\n    MInt res = 1;\r\n    for (int i = 1; i <= k;\
    \ ++i) res *= inv(i) * n--;\r\n    return res;\r\n  }\r\n  MInt pow(long long\
    \ exponent) const {\r\n    MInt tmp = *this, res = 1;\r\n    while (exponent >\
    \ 0) {\r\n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n      exponent\
    \ >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n  MInt &operator+=(const MInt &x)\
    \ { if((val += x.val) >= mod()) val -= mod(); return *this; }\r\n  MInt &operator-=(const\
    \ MInt &x) { if((val += mod() - x.val) >= mod()) val -= mod(); return *this; }\r\
    \n  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val)\
    \ * x.val % mod(); return *this; }\r\n  MInt &operator/=(const MInt &x) { return\
    \ *this *= inv(x.val); }\r\n  bool operator==(const MInt &x) const { return val\
    \ == x.val; }\r\n  bool operator!=(const MInt &x) const { return val != x.val;\
    \ }\r\n  bool operator<(const MInt &x) const { return val < x.val; }\r\n  bool\
    \ operator<=(const MInt &x) const { return val <= x.val; }\r\n  bool operator>(const\
    \ MInt &x) const { return val > x.val; }\r\n  bool operator>=(const MInt &x) const\
    \ { return val >= x.val; }\r\n  MInt &operator++() { if (++val == mod()) val =\
    \ 0; return *this; }\r\n  MInt operator++(int) { MInt res = *this; ++*this; return\
    \ res; }\r\n  MInt &operator--() { val = (val == 0 ? mod() : val) - 1; return\
    \ *this; }\r\n  MInt operator--(int) { MInt res = *this; --*this; return res;\
    \ }\r\n  MInt operator+() const { return *this; }\r\n  MInt operator-() const\
    \ { return MInt(val ? mod() - val : 0); }\r\n  MInt operator+(const MInt &x) const\
    \ { return MInt(*this) += x; }\r\n  MInt operator-(const MInt &x) const { return\
    \ MInt(*this) -= x; }\r\n  MInt operator*(const MInt &x) const { return MInt(*this)\
    \ *= x; }\r\n  MInt operator/(const MInt &x) const { return MInt(*this) /= x;\
    \ }\r\n  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return\
    \ os << x.val; }\r\n  friend std::istream &operator>>(std::istream &is, MInt &x)\
    \ { long long val; is >> val; x = MInt(val); return is; }\r\nprivate:\r\n  static\
    \ int &mod() { static int divisor = 0; return divisor; }\r\n};\r\nnamespace std\
    \ { template <int ID> MInt<ID> abs(const MInt<ID> &x) { return x; } }\r\n#line\
    \ 3 \"math/twelvefold_way/lucas.hpp\"\n\r\ntemplate <int P>\r\nMInt<P> lucas(int\
    \ n, int k) {\r\n  using ModInt = MInt<P>;\r\n  if (n < 0 || n < k || k < 0) return\
    \ 0;\r\n  ModInt::init(P - 1);\r\n  ModInt binom = 1;\r\n  for (; n > 0 || k >\
    \ 0; n /= P, k /= P) binom *= ModInt::nCk(n % P, k % P);\r\n  return binom;\r\n\
    }\r\n"
  code: "#pragma once\r\n#include \"../modint.hpp\"\r\n\r\ntemplate <int P>\r\nMInt<P>\
    \ lucas(int n, int k) {\r\n  using ModInt = MInt<P>;\r\n  if (n < 0 || n < k ||\
    \ k < 0) return 0;\r\n  ModInt::init(P - 1);\r\n  ModInt binom = 1;\r\n  for (;\
    \ n > 0 || k > 0; n /= P, k /= P) binom *= ModInt::nCk(n % P, k % P);\r\n  return\
    \ binom;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/twelvefold_way/lucas.hpp
  requiredBy: []
  timestamp: '2021-04-20 03:00:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/twelvefold_way/lucas.test.cpp
documentation_of: math/twelvefold_way/lucas.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/lucas.hpp
- /library/math/twelvefold_way/lucas.hpp.html
title: math/twelvefold_way/lucas.hpp
---
