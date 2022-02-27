---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/berlekamp-massey.hpp
    title: "Berlekamp\u2013Massey algorithm"
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
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    document_title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Berlekamp\u2013\
      Massey algorithm"
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/math/formal_power_series/berlekamp-massey.test.cpp\"\
    \n/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Berlekamp\u2013\
    Massey algorithm\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 3 \"math/formal_power_series/berlekamp-massey.hpp\"\
    \n\r\ntemplate <typename T>\r\nstd::vector<T> berlekamp_massey(const std::vector<T>&\
    \ s) {\r\n  const int n = s.size();\r\n  std::vector<T> b{1}, c{1};\r\n  b.reserve(n);\r\
    \n  c.reserve(n + 1);\r\n  int m = b.size(), l = c.size(), f = -1;\r\n  T prv_delta\
    \ = 1;\r\n  for (int i = 0; i < n; ++i) {\r\n    T delta = s[i];\r\n    for (int\
    \ j = 1; j < l; ++j) {\r\n      delta += c[j] * s[i - j];\r\n    }\r\n    if (delta\
    \ == 0) continue;\r\n    const T mul = -delta / prv_delta;\r\n    const int shift\
    \ = i - f;\r\n    if (m + shift > l) {\r\n      l = m + shift;\r\n      const\
    \ std::vector<T> nxt_b = c;\r\n      c.resize(l, 0);\r\n      for (int j = 0;\
    \ j < m; ++j) {\r\n        c[l - 1 - j] += mul * b[m - 1 - j];\r\n      }\r\n\
    \      b = nxt_b;\r\n      m = b.size();\r\n      f = i;\r\n      prv_delta =\
    \ delta;\r\n    } else {\r\n      for (int j = 0; j < m; ++j) {\r\n        c[shift\
    \ + j] += mul * b[j];\r\n      }\r\n    }\r\n  }\r\n  return c;\r\n}\r\n#line\
    \ 2 \"math/modint.hpp\"\n// #include <algorithm>\r\n// #include <cassert>\r\n\
    #line 5 \"math/modint.hpp\"\n#include <utility>\r\n#line 7 \"math/modint.hpp\"\
    \n\r\n// template <int M>\r\n// struct MInt {\r\n//   unsigned int v;\r\n//  \
    \ MInt() : v(0) {}\r\n//   MInt(const long long x) : v(x >= 0 ? x % M : x % M\
    \ + M) {}\r\n//   static constexpr int get_mod() { return M; }\r\n//   static\
    \ void set_mod(const int divisor) { assert(divisor == M); }\r\n//   static void\
    \ init(const int x = 10000000) {\r\n//     inv(x, true);\r\n//     fact(x);\r\n\
    //     fact_inv(x);\r\n//   }\r\n//   static MInt inv(const int n, const bool\
    \ init = false) {\r\n//     // assert(0 <= n && n < M && std::__gcd(n, M) == 1);\r\
    \n//     static std::vector<MInt> inverse{0, 1};\r\n//     const int prev = inverse.size();\r\
    \n//     if (n < prev) {\r\n//       return inverse[n];\r\n//     } else if (init)\
    \ {\r\n//       // \"n!\" and \"M\" must be disjoint.\r\n//       inverse.resize(n\
    \ + 1);\r\n//       for (int i = prev; i <= n; ++i) {\r\n//         inverse[i]\
    \ = -inverse[M % i] * (M / i);\r\n//       }\r\n//       return inverse[n];\r\n\
    //     }\r\n//     int u = 1, v = 0;\r\n//     for (unsigned int a = n, b = M;\
    \ b;) {\r\n//       const unsigned int q = a / b;\r\n//       std::swap(a -= q\
    \ * b, b);\r\n//       std::swap(u -= q * v, v);\r\n//     }\r\n//     return\
    \ u;\r\n//   }\r\n//   static MInt fact(const int n) {\r\n//     static std::vector<MInt>\
    \ factorial{1};\r\n//     const int prev = factorial.size();\r\n//     if (n >=\
    \ prev) {\r\n//       factorial.resize(n + 1);\r\n//       for (int i = prev;\
    \ i <= n; ++i) {\r\n//         factorial[i] = factorial[i - 1] * i;\r\n//    \
    \   }\r\n//     }\r\n//     return factorial[n];\r\n//   }\r\n//   static MInt\
    \ fact_inv(const int n) {\r\n//     static std::vector<MInt> f_inv{1};\r\n// \
    \    const int prev = f_inv.size();\r\n//     if (n >= prev) {\r\n//       f_inv.resize(n\
    \ + 1);\r\n//       f_inv[n] = inv(fact(n).v);\r\n//       for (int i = n; i >\
    \ prev; --i) {\r\n//         f_inv[i - 1] = f_inv[i] * i;\r\n//       }\r\n//\
    \     }\r\n//     return f_inv[n];\r\n//   }\r\n//   static MInt nCk(const int\
    \ n, const int k) {\r\n//     if (n < 0 || n < k || k < 0) return 0;\r\n//   \
    \  return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\r\n//       \
    \                            fact_inv(n - k) * fact_inv(k));\r\n//   }\r\n// \
    \  static MInt nPk(const int n, const int k) {\r\n//     return n < 0 || n < k\
    \ || k < 0 ? 0 : fact(n) * fact_inv(n - k);\r\n//   }\r\n//   static MInt nHk(const\
    \ int n, const int k) {\r\n//     return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n\
    \ + k - 1, k));\r\n//   }\r\n//   static MInt large_nCk(long long n, const int\
    \ k) {\r\n//     if (n < 0 || n < k || k < 0) return 0;\r\n//     inv(k, true);\r\
    \n//     MInt res = 1;\r\n//     for (int i = 1; i <= k; ++i) {\r\n//       res\
    \ *= inv(i) * n--;\r\n//     }\r\n//     return res;\r\n//   }\r\n//   MInt pow(long\
    \ long exponent) const {\r\n//     MInt res = 1, tmp = *this;\r\n//     for (;\
    \ exponent > 0; exponent >>= 1) {\r\n//       if (exponent & 1) res *= tmp;\r\n\
    //       tmp *= tmp;\r\n//     }\r\n//     return res;\r\n//   }\r\n//   MInt&\
    \ operator+=(const MInt& x) {\r\n//     if ((v += x.v) >= M) v -= M;\r\n//   \
    \  return *this;\r\n//   }\r\n//   MInt& operator-=(const MInt& x) {\r\n//   \
    \  if ((v += M - x.v) >= M) v -= M;\r\n//     return *this;\r\n//   }\r\n//  \
    \ MInt& operator*=(const MInt& x) {\r\n//     v = static_cast<unsigned long long>(v)\
    \ * x.v % M;\r\n//     return *this;\r\n//   }\r\n//   MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\r\n//   bool operator==(const MInt& x)\
    \ const { return v == x.v; }\r\n//   bool operator!=(const MInt& x) const { return\
    \ v != x.v; }\r\n//   bool operator<(const MInt& x) const { return v < x.v; }\r\
    \n//   bool operator<=(const MInt& x) const { return v <= x.v; }\r\n//   bool\
    \ operator>(const MInt& x) const { return v > x.v; }\r\n//   bool operator>=(const\
    \ MInt& x) const { return v >= x.v; }\r\n//   MInt& operator++() {\r\n//     if\
    \ (++v == M) v = 0;\r\n//     return *this;\r\n//   }\r\n//   MInt operator++(int)\
    \ {\r\n//     const MInt res = *this;\r\n//     ++*this;\r\n//     return res;\r\
    \n//   }\r\n//   MInt& operator--() {\r\n//     v = (v == 0 ? M - 1 : v - 1);\r\
    \n//     return *this;\r\n//   }\r\n//   MInt operator--(int) {\r\n//     const\
    \ MInt res = *this;\r\n//     --*this;\r\n//     return res;\r\n//   }\r\n// \
    \  MInt operator+() const { return *this; }\r\n//   MInt operator-() const { return\
    \ MInt(v ? M - v : 0); }\r\n//   MInt operator+(const MInt& x) const { return\
    \ MInt(*this) += x; }\r\n//   MInt operator-(const MInt& x) const { return MInt(*this)\
    \ -= x; }\r\n//   MInt operator*(const MInt& x) const { return MInt(*this) *=\
    \ x; }\r\n//   MInt operator/(const MInt& x) const { return MInt(*this) /= x;\
    \ }\r\n//   friend std::ostream& operator<<(std::ostream& os, const MInt& x) {\r\
    \n//     return os << x.v;\r\n//   }\r\n//   friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\r\n//     long long v;\r\n//     is >> v;\r\n//     x = MInt(v);\r\
    \n//     return is;\r\n//   }\r\n// };\r\n\r\ntemplate <int ID>\r\nstruct MInt\
    \ {\r\n  unsigned int v;\r\n  MInt() : v(0) {}\r\n  MInt(const long long x) :\
    \ v(x >= 0 ? x % mod() : x % mod() + mod()) {}\r\n  static int get_mod() { return\
    \ mod(); }\r\n  static void set_mod(const int divisor) { mod() = divisor; }\r\n\
    \  static void init(const int x = 10000000) {\r\n    inv(x, true);\r\n    fact(x);\r\
    \n    fact_inv(x);\r\n  }\r\n  static MInt inv(const int n, const bool init =\
    \ false) {\r\n    // assert(0 <= n && n < mod() && std::__gcd(x, mod()) == 1);\r\
    \n    static std::vector<MInt> inverse{0, 1};\r\n    const int prev = inverse.size();\r\
    \n    if (n < prev) {\r\n      return inverse[n];\r\n    } else if (init) {\r\n\
    \      // \"n!\" and \"mod()\" must be disjoint.\r\n      inverse.resize(n + 1);\r\
    \n      for (int i = prev; i <= n; ++i) {\r\n        inverse[i] = -inverse[mod()\
    \ % i] * (mod() / i);\r\n      }\r\n      return inverse[n];\r\n    }\r\n    int\
    \ u = 1, v = 0;\r\n    for (unsigned int a = n, b = mod(); b;) {\r\n      const\
    \ unsigned int q = a / b;\r\n      std::swap(a -= q * b, b);\r\n      std::swap(u\
    \ -= q * v, v);\r\n    }\r\n    return u;\r\n  }\r\n  static MInt fact(const int\
    \ n) {\r\n    static std::vector<MInt> factorial{1};\r\n    const int prev = factorial.size();\r\
    \n    if (n >= prev) {\r\n      factorial.resize(n + 1);\r\n      for (int i =\
    \ prev; i <= n; ++i) {\r\n        factorial[i] = factorial[i - 1] * i;\r\n   \
    \   }\r\n    }\r\n    return factorial[n];\r\n  }\r\n  static MInt fact_inv(const\
    \ int n) {\r\n    static std::vector<MInt> f_inv{1};\r\n    const int prev = f_inv.size();\r\
    \n    if (n >= prev) {\r\n      f_inv.resize(n + 1);\r\n      f_inv[n] = inv(fact(n).v);\r\
    \n      for (int i = n; i > prev; --i) {\r\n        f_inv[i - 1] = f_inv[i] *\
    \ i;\r\n      }\r\n    }\r\n    return f_inv[n];\r\n  }\r\n  static MInt nCk(const\
    \ int n, const int k) {\r\n    if (n < 0 || n < k || k < 0) return 0;\r\n    return\
    \ fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\r\n                 \
    \                 fact_inv(n - k) * fact_inv(k));\r\n  }\r\n  static MInt nPk(const\
    \ int n, const int k) {\r\n    return n < 0 || n < k || k < 0 ? 0 : fact(n) *\
    \ fact_inv(n - k);\r\n  }\r\n  static MInt nHk(const int n, const int k) {\r\n\
    \    return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));\r\n  }\r\n\
    \  static MInt large_nCk(long long n, const int k) {\r\n    if (n < 0 || n < k\
    \ || k < 0) return 0;\r\n    inv(k, true);\r\n    MInt res = 1;\r\n    for (int\
    \ i = 1; i <= k; ++i) {\r\n      res *= inv(i) * n--;\r\n    }\r\n    return res;\r\
    \n  }\r\n  MInt pow(long long exponent) const {\r\n    MInt res = 1, tmp = *this;\r\
    \n    for (; exponent > 0; exponent >>= 1) {\r\n      if (exponent & 1) res *=\
    \ tmp;\r\n      tmp *= tmp;\r\n    }\r\n    return res;\r\n  }\r\n  MInt& operator+=(const\
    \ MInt& x) {\r\n    if ((v += x.v) >= mod()) v -= mod();\r\n    return *this;\r\
    \n  }\r\n  MInt& operator-=(const MInt& x) {\r\n    if ((v += mod() - x.v) >=\
    \ mod()) v -= mod();\r\n    return *this;\r\n  }\r\n  MInt& operator*=(const MInt&\
    \ x) {\r\n    v = static_cast<unsigned long long>(v) * x.v % mod();\r\n    return\
    \ *this;\r\n    }\r\n  MInt& operator/=(const MInt& x) { return *this *= inv(x.v);\
    \ }\r\n  bool operator==(const MInt& x) const { return v == x.v; }\r\n  bool operator!=(const\
    \ MInt& x) const { return v != x.v; }\r\n  bool operator<(const MInt& x) const\
    \ { return v < x.v; }\r\n  bool operator<=(const MInt& x) const { return v <=\
    \ x.v; }\r\n  bool operator>(const MInt& x) const { return v > x.v; }\r\n  bool\
    \ operator>=(const MInt& x) const { return v >= x.v; }\r\n  MInt& operator++()\
    \ {\r\n    if (++v == mod()) v = 0;\r\n    return *this;\r\n  }\r\n  MInt operator++(int)\
    \ {\r\n    const MInt res = *this;\r\n    ++*this;\r\n    return res;\r\n  }\r\
    \n  MInt& operator--() {\r\n    v = (v == 0 ? mod() - 1 : v - 1);\r\n    return\
    \ *this;\r\n  }\r\n  MInt operator--(int) {\r\n    const MInt res = *this;\r\n\
    \    --*this;\r\n    return res;\r\n  }\r\n  MInt operator+() const { return *this;\
    \ }\r\n  MInt operator-() const { return MInt(v ? mod() - v : 0); }\r\n  MInt\
    \ operator+(const MInt& x) const { return MInt(*this) += x; }\r\n  MInt operator-(const\
    \ MInt& x) const { return MInt(*this) -= x; }\r\n  MInt operator*(const MInt&\
    \ x) const { return MInt(*this) *= x; }\r\n  MInt operator/(const MInt& x) const\
    \ { return MInt(*this) /= x; }\r\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\r\n    return os << x.v;\r\n  }\r\n  friend std::istream&\
    \ operator>>(std::istream& is, MInt& x) {\r\n    long long v;\r\n    is >> v;\r\
    \n    x = MInt(v);\r\n    return is;\r\n  }\r\n private:\r\n  static int& mod()\
    \ {\r\n    static int divisor = 0;\r\n    return divisor;\r\n  }\r\n};\r\n#line\
    \ 11 \"test/math/formal_power_series/berlekamp-massey.test.cpp\"\n\r\nint main()\
    \ {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  int n;\r\
    \n  std::cin >> n;\r\n  std::vector<ModInt> a(n);\r\n  for (int i = 0; i < n;\
    \ ++i) {\r\n    std::cin >> a[i];\r\n  }\r\n  const std::vector<ModInt> c = berlekamp_massey(a);\r\
    \n  const int d = c.size() - 1;\r\n  std::cout << d << '\\n';\r\n  for (int i\
    \ = 0; i < d; ++i) {\r\n    std::cout << -c[i + 1];\r\n    if (i + 1 < d) std::cout\
    \ << ' ';\r\n  }\r\n  std::cout << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Berlekamp\u2013\
    Massey algorithm\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../../math/formal_power_series/berlekamp-massey.hpp\"\
    \r\n#include \"../../../math/modint.hpp\"\r\n\r\nint main() {\r\n  using ModInt\
    \ = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\n  int n;\r\n  std::cin >> n;\r\
    \n  std::vector<ModInt> a(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin\
    \ >> a[i];\r\n  }\r\n  const std::vector<ModInt> c = berlekamp_massey(a);\r\n\
    \  const int d = c.size() - 1;\r\n  std::cout << d << '\\n';\r\n  for (int i =\
    \ 0; i < d; ++i) {\r\n    std::cout << -c[i + 1];\r\n    if (i + 1 < d) std::cout\
    \ << ' ';\r\n  }\r\n  std::cout << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/formal_power_series/berlekamp-massey.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/math/formal_power_series/berlekamp-massey.test.cpp
  requiredBy: []
  timestamp: '2022-02-28 01:01:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/formal_power_series/berlekamp-massey.test.cpp
layout: document
redirect_from:
- /verify/test/math/formal_power_series/berlekamp-massey.test.cpp
- /verify/test/math/formal_power_series/berlekamp-massey.test.cpp.html
title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Berlekamp\u2013Massey algorithm"
---
