---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/twelvefold_way/lucas.hpp
    title: "Lucas \u306E\u5B9A\u7406 (Lucas's theorem)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc117/tasks/arc117_c
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406"
    links:
    - https://atcoder.jp/contests/arc117/tasks/arc117_c
  bundledCode: "#line 1 \"test/math/twelvefold_way/lucas.test.cpp\"\n/*\r\n * @brief\
    \ \u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406\r\n */\r\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/arc117/tasks/arc117_c\"\r\n\r\n#include\
    \ <iostream>\r\n#include <map>\r\n#include <string>\r\n\r\n#line 2 \"math/modint.hpp\"\
    \n// #include <algorithm>\r\n// #include <cassert>\r\n#line 5 \"math/modint.hpp\"\
    \n#include <utility>\r\n#include <vector>\r\n\r\n// template <int M>\r\n// struct\
    \ MInt {\r\n//   unsigned int v;\r\n//   MInt() : v(0) {}\r\n//   MInt(const long\
    \ long x) : v(x >= 0 ? x % M : x % M + M) {}\r\n//   static constexpr int get_mod()\
    \ { return M; }\r\n//   static void set_mod(const int divisor) { assert(divisor\
    \ == M); }\r\n//   static void init(const int x = 10000000) {\r\n//     inv(x,\
    \ true);\r\n//     fact(x);\r\n//     fact_inv(x);\r\n//   }\r\n//   static MInt\
    \ inv(const int n, const bool init = false) {\r\n//     // assert(0 <= n && n\
    \ < M && std::__gcd(n, M) == 1);\r\n//     static std::vector<MInt> inverse{0,\
    \ 1};\r\n//     const int prev = inverse.size();\r\n//     if (n < prev) {\r\n\
    //       return inverse[n];\r\n//     } else if (init) {\r\n//       // \"n!\"\
    \ and \"M\" must be disjoint.\r\n//       inverse.resize(n + 1);\r\n//       for\
    \ (int i = prev; i <= n; ++i) {\r\n//         inverse[i] = -inverse[M % i] * (M\
    \ / i);\r\n//       }\r\n//       return inverse[n];\r\n//     }\r\n//     int\
    \ u = 1, v = 0;\r\n//     for (unsigned int a = n, b = M; b;) {\r\n//       const\
    \ unsigned int q = a / b;\r\n//       std::swap(a -= q * b, b);\r\n//       std::swap(u\
    \ -= q * v, v);\r\n//     }\r\n//     return u;\r\n//   }\r\n//   static MInt\
    \ fact(const int n) {\r\n//     static std::vector<MInt> factorial{1};\r\n// \
    \    const int prev = factorial.size();\r\n//     if (n >= prev) {\r\n//     \
    \  factorial.resize(n + 1);\r\n//       for (int i = prev; i <= n; ++i) {\r\n\
    //         factorial[i] = factorial[i - 1] * i;\r\n//       }\r\n//     }\r\n\
    //     return factorial[n];\r\n//   }\r\n//   static MInt fact_inv(const int n)\
    \ {\r\n//     static std::vector<MInt> f_inv{1};\r\n//     const int prev = f_inv.size();\r\
    \n//     if (n >= prev) {\r\n//       f_inv.resize(n + 1);\r\n//       f_inv[n]\
    \ = inv(fact(n).v);\r\n//       for (int i = n; i > prev; --i) {\r\n//       \
    \  f_inv[i - 1] = f_inv[i] * i;\r\n//       }\r\n//     }\r\n//     return f_inv[n];\r\
    \n//   }\r\n//   static MInt nCk(const int n, const int k) {\r\n//     if (n <\
    \ 0 || n < k || k < 0) return 0;\r\n//     return fact(n) * (n - k < k ? fact_inv(k)\
    \ * fact_inv(n - k) :\r\n//                                   fact_inv(n - k)\
    \ * fact_inv(k));\r\n//   }\r\n//   static MInt nPk(const int n, const int k)\
    \ {\r\n//     return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\r\
    \n//   }\r\n//   static MInt nHk(const int n, const int k) {\r\n//     return\
    \ n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));\r\n//   }\r\n//   static\
    \ MInt large_nCk(long long n, const int k) {\r\n//     if (n < 0 || n < k || k\
    \ < 0) return 0;\r\n//     inv(k, true);\r\n//     MInt res = 1;\r\n//     for\
    \ (int i = 1; i <= k; ++i) {\r\n//       res *= inv(i) * n--;\r\n//     }\r\n\
    //     return res;\r\n//   }\r\n//   MInt pow(long long exponent) const {\r\n\
    //     MInt res = 1, tmp = *this;\r\n//     for (; exponent > 0; exponent >>=\
    \ 1) {\r\n//       if (exponent & 1) res *= tmp;\r\n//       tmp *= tmp;\r\n//\
    \     }\r\n//     return res;\r\n//   }\r\n//   MInt& operator+=(const MInt& x)\
    \ {\r\n//     if ((v += x.v) >= M) v -= M;\r\n//     return *this;\r\n//   }\r\
    \n//   MInt& operator-=(const MInt& x) {\r\n//     if ((v += M - x.v) >= M) v\
    \ -= M;\r\n//     return *this;\r\n//   }\r\n//   MInt& operator*=(const MInt&\
    \ x) {\r\n//     v = static_cast<unsigned long long>(v) * x.v % M;\r\n//     return\
    \ *this;\r\n//   }\r\n//   MInt& operator/=(const MInt& x) { return *this *= inv(x.v);\
    \ }\r\n//   bool operator==(const MInt& x) const { return v == x.v; }\r\n//  \
    \ bool operator!=(const MInt& x) const { return v != x.v; }\r\n//   bool operator<(const\
    \ MInt& x) const { return v < x.v; }\r\n//   bool operator<=(const MInt& x) const\
    \ { return v <= x.v; }\r\n//   bool operator>(const MInt& x) const { return v\
    \ > x.v; }\r\n//   bool operator>=(const MInt& x) const { return v >= x.v; }\r\
    \n//   MInt& operator++() {\r\n//     if (++v == M) v = 0;\r\n//     return *this;\r\
    \n//   }\r\n//   MInt operator++(int) {\r\n//     const MInt res = *this;\r\n\
    //     ++*this;\r\n//     return res;\r\n//   }\r\n//   MInt& operator--() {\r\
    \n//     v = (v == 0 ? M - 1 : v - 1);\r\n//     return *this;\r\n//   }\r\n//\
    \   MInt operator--(int) {\r\n//     const MInt res = *this;\r\n//     --*this;\r\
    \n//     return res;\r\n//   }\r\n//   MInt operator+() const { return *this;\
    \ }\r\n//   MInt operator-() const { return MInt(v ? M - v : 0); }\r\n//   MInt\
    \ operator+(const MInt& x) const { return MInt(*this) += x; }\r\n//   MInt operator-(const\
    \ MInt& x) const { return MInt(*this) -= x; }\r\n//   MInt operator*(const MInt&\
    \ x) const { return MInt(*this) *= x; }\r\n//   MInt operator/(const MInt& x)\
    \ const { return MInt(*this) /= x; }\r\n//   friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\r\n//     return os << x.v;\r\n//   }\r\n//   friend std::istream&\
    \ operator>>(std::istream& is, MInt& x) {\r\n//     long long v;\r\n//     is\
    \ >> v;\r\n//     x = MInt(v);\r\n//     return is;\r\n//   }\r\n// };\r\n\r\n\
    template <int ID>\r\nstruct MInt {\r\n  unsigned int v;\r\n  MInt() : v(0) {}\r\
    \n  MInt(const long long x) : v(x >= 0 ? x % mod() : x % mod() + mod()) {}\r\n\
    \  static int get_mod() { return mod(); }\r\n  static void set_mod(const int divisor)\
    \ { mod() = divisor; }\r\n  static void init(const int x = 10000000) {\r\n   \
    \ inv(x, true);\r\n    fact(x);\r\n    fact_inv(x);\r\n  }\r\n  static MInt inv(const\
    \ int n, const bool init = false) {\r\n    // assert(0 <= n && n < mod() && std::__gcd(x,\
    \ mod()) == 1);\r\n    static std::vector<MInt> inverse{0, 1};\r\n    const int\
    \ prev = inverse.size();\r\n    if (n < prev) {\r\n      return inverse[n];\r\n\
    \    } else if (init) {\r\n      // \"n!\" and \"mod()\" must be disjoint.\r\n\
    \      inverse.resize(n + 1);\r\n      for (int i = prev; i <= n; ++i) {\r\n \
    \       inverse[i] = -inverse[mod() % i] * (mod() / i);\r\n      }\r\n      return\
    \ inverse[n];\r\n    }\r\n    int u = 1, v = 0;\r\n    for (unsigned int a = n,\
    \ b = mod(); b;) {\r\n      const unsigned int q = a / b;\r\n      std::swap(a\
    \ -= q * b, b);\r\n      std::swap(u -= q * v, v);\r\n    }\r\n    return u;\r\
    \n  }\r\n  static MInt fact(const int n) {\r\n    static std::vector<MInt> factorial{1};\r\
    \n    const int prev = factorial.size();\r\n    if (n >= prev) {\r\n      factorial.resize(n\
    \ + 1);\r\n      for (int i = prev; i <= n; ++i) {\r\n        factorial[i] = factorial[i\
    \ - 1] * i;\r\n      }\r\n    }\r\n    return factorial[n];\r\n  }\r\n  static\
    \ MInt fact_inv(const int n) {\r\n    static std::vector<MInt> f_inv{1};\r\n \
    \   const int prev = f_inv.size();\r\n    if (n >= prev) {\r\n      f_inv.resize(n\
    \ + 1);\r\n      f_inv[n] = inv(fact(n).v);\r\n      for (int i = n; i > prev;\
    \ --i) {\r\n        f_inv[i - 1] = f_inv[i] * i;\r\n      }\r\n    }\r\n    return\
    \ f_inv[n];\r\n  }\r\n  static MInt nCk(const int n, const int k) {\r\n    if\
    \ (n < 0 || n < k || k < 0) return 0;\r\n    return fact(n) * (n - k < k ? fact_inv(k)\
    \ * fact_inv(n - k) :\r\n                                  fact_inv(n - k) * fact_inv(k));\r\
    \n  }\r\n  static MInt nPk(const int n, const int k) {\r\n    return n < 0 ||\
    \ n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\r\n  }\r\n  static MInt nHk(const\
    \ int n, const int k) {\r\n    return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n\
    \ + k - 1, k));\r\n  }\r\n  static MInt large_nCk(long long n, const int k) {\r\
    \n    if (n < 0 || n < k || k < 0) return 0;\r\n    inv(k, true);\r\n    MInt\
    \ res = 1;\r\n    for (int i = 1; i <= k; ++i) {\r\n      res *= inv(i) * n--;\r\
    \n    }\r\n    return res;\r\n  }\r\n  MInt pow(long long exponent) const {\r\n\
    \    MInt res = 1, tmp = *this;\r\n    for (; exponent > 0; exponent >>= 1) {\r\
    \n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n    }\r\n    return\
    \ res;\r\n  }\r\n  MInt& operator+=(const MInt& x) {\r\n    if ((v += x.v) >=\
    \ mod()) v -= mod();\r\n    return *this;\r\n  }\r\n  MInt& operator-=(const MInt&\
    \ x) {\r\n    if ((v += mod() - x.v) >= mod()) v -= mod();\r\n    return *this;\r\
    \n  }\r\n  MInt& operator*=(const MInt& x) {\r\n    v = static_cast<unsigned long\
    \ long>(v) * x.v % mod();\r\n    return *this;\r\n    }\r\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\r\n  bool operator==(const MInt& x) const\
    \ { return v == x.v; }\r\n  bool operator!=(const MInt& x) const { return v !=\
    \ x.v; }\r\n  bool operator<(const MInt& x) const { return v < x.v; }\r\n  bool\
    \ operator<=(const MInt& x) const { return v <= x.v; }\r\n  bool operator>(const\
    \ MInt& x) const { return v > x.v; }\r\n  bool operator>=(const MInt& x) const\
    \ { return v >= x.v; }\r\n  MInt& operator++() {\r\n    if (++v == mod()) v =\
    \ 0;\r\n    return *this;\r\n  }\r\n  MInt operator++(int) {\r\n    const MInt\
    \ res = *this;\r\n    ++*this;\r\n    return res;\r\n  }\r\n  MInt& operator--()\
    \ {\r\n    v = (v == 0 ? mod() - 1 : v - 1);\r\n    return *this;\r\n  }\r\n \
    \ MInt operator--(int) {\r\n    const MInt res = *this;\r\n    --*this;\r\n  \
    \  return res;\r\n  }\r\n  MInt operator+() const { return *this; }\r\n  MInt\
    \ operator-() const { return MInt(v ? mod() - v : 0); }\r\n  MInt operator+(const\
    \ MInt& x) const { return MInt(*this) += x; }\r\n  MInt operator-(const MInt&\
    \ x) const { return MInt(*this) -= x; }\r\n  MInt operator*(const MInt& x) const\
    \ { return MInt(*this) *= x; }\r\n  MInt operator/(const MInt& x) const { return\
    \ MInt(*this) /= x; }\r\n  friend std::ostream& operator<<(std::ostream& os, const\
    \ MInt& x) {\r\n    return os << x.v;\r\n  }\r\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\r\n    long long v;\r\n    is >> v;\r\n    x = MInt(v);\r\n \
    \   return is;\r\n  }\r\n private:\r\n  static int& mod() {\r\n    static int\
    \ divisor = 0;\r\n    return divisor;\r\n  }\r\n};\r\n#line 3 \"math/twelvefold_way/lucas.hpp\"\
    \n\r\ntemplate <int P>\r\nMInt<P> lucas(int n, int k) {\r\n  using ModInt = MInt<P>;\r\
    \n  if (n < 0 || n < k || k < 0) return 0;\r\n  ModInt::init(P - 1);\r\n  ModInt\
    \ binom = 1;\r\n  for (; n > 0 || k > 0; n /= P, k /= P) {\r\n    binom *= ModInt::nCk(n\
    \ % P, k % P);\r\n  }\r\n  return binom;\r\n}\r\n#line 12 \"test/math/twelvefold_way/lucas.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr int C = 3;\r\n  using ModInt = MInt<C>;\r\n\
    \  ModInt::set_mod(C);\r\n  const std::string color = \"BWR\";\r\n  std::map<char,\
    \ int> mp;\r\n  for (int i = 0; i < C; ++i) {\r\n    mp[color[i]] = i;\r\n  }\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::string c;\r\n  std::cin >> c;\r\n  ModInt\
    \ ans = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    ans += lucas<C>(n - 1, i)\
    \ * mp[c[i]];\r\n  }\r\n  if (n % 2 == 0) ans = -ans;\r\n  std::cout << color[ans.v]\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406\
    \r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/arc117/tasks/arc117_c\"\
    \r\n\r\n#include <iostream>\r\n#include <map>\r\n#include <string>\r\n\r\n#include\
    \ \"../../../math/modint.hpp\"\r\n#include \"../../../math/twelvefold_way/lucas.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr int C = 3;\r\n  using ModInt = MInt<C>;\r\n\
    \  ModInt::set_mod(C);\r\n  const std::string color = \"BWR\";\r\n  std::map<char,\
    \ int> mp;\r\n  for (int i = 0; i < C; ++i) {\r\n    mp[color[i]] = i;\r\n  }\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::string c;\r\n  std::cin >> c;\r\n  ModInt\
    \ ans = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    ans += lucas<C>(n - 1, i)\
    \ * mp[c[i]];\r\n  }\r\n  if (n % 2 == 0) ans = -ans;\r\n  std::cout << color[ans.v]\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/twelvefold_way/lucas.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/lucas.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/twelvefold_way/lucas.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/lucas.test.cpp
- /verify/test/math/twelvefold_way/lucas.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406"
---
