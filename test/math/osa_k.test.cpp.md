---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/osa_k.hpp
    title: "osa_k \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/osa_k \u6CD5"
    links:
    - https://atcoder.jp/contests/abc052/tasks/arc067_a
  bundledCode: "#line 1 \"test/math/osa_k.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /osa_k \u6CD5\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/abc052/tasks/arc067_a\"\
    \r\n\r\n#include <iostream>\r\n#include <map>\r\n#include <utility>\r\n#line 2\
    \ \"math/modint.hpp\"\n// #include <algorithm>\r\n// #include <cassert>\r\n#line\
    \ 6 \"math/modint.hpp\"\n#include <vector>\r\n\r\n// template <int MOD>\r\n//\
    \ struct MInt {\r\n//   unsigned int val;\r\n//   MInt(): val(0) {}\r\n//   MInt(long\
    \ long x) : val(x >= 0 ? x % MOD : x % MOD + MOD) {}\r\n//   static constexpr\
    \ int get_mod() { return MOD; }\r\n//   static void set_mod(int divisor) { assert(divisor\
    \ == MOD); }\r\n//   static void init(int x = 10000000) { inv(x, true); fact(x);\
    \ fact_inv(x); }\r\n//   static MInt inv(int x, bool init = false) {\r\n//   \
    \  // assert(0 <= x && x < MOD && std::__gcd(x, MOD) == 1);\r\n//     static std::vector<MInt>\
    \ inverse{0, 1};\r\n//     int prev = inverse.size();\r\n//     if (init && x\
    \ >= prev) {\r\n//       // \"x!\" and \"MOD\" must be disjoint.\r\n//       inverse.resize(x\
    \ + 1);\r\n//       for (int i = prev; i <= x; ++i) inverse[i] = -inverse[MOD\
    \ % i] * (MOD / i);\r\n//     }\r\n//     if (x < inverse.size()) return inverse[x];\r\
    \n//     unsigned int a = x, b = MOD; int u = 1, v = 0;\r\n//     while (b) {\r\
    \n//       unsigned int tmp = a / b;\r\n//       std::swap(a -= tmp * b, b);\r\
    \n//       std::swap(u -= tmp * v, v);\r\n//     }\r\n//     return u;\r\n// \
    \  }\r\n//   static MInt fact(int x) {\r\n//     static std::vector<MInt> f{1};\r\
    \n//     int prev = f.size();\r\n//     if (x >= prev) {\r\n//       f.resize(x\
    \ + 1);\r\n//       for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n//\
    \     }\r\n//     return f[x];\r\n//   }\r\n//   static MInt fact_inv(int x) {\r\
    \n//     static std::vector<MInt> finv{1};\r\n//     int prev = finv.size();\r\
    \n//     if (x >= prev) {\r\n//       finv.resize(x + 1);\r\n//       finv[x]\
    \ = inv(fact(x).val);\r\n//       for (int i = x; i > prev; --i) finv[i - 1] =\
    \ finv[i] * i;\r\n//     }\r\n//     return finv[x];\r\n//   }\r\n//   static\
    \ MInt nCk(int n, int k) {\r\n//     if (n < 0 || n < k || k < 0) return 0;\r\n\
    //     if (n - k > k) k = n - k;\r\n//     return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n//   }\r\n//   static MInt nPk(int n, int k) { return n < 0 || n <\
    \ k || k < 0 ? 0 : fact(n) * fact_inv(n - k); }\r\n//   static MInt nHk(int n,\
    \ int k) { return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n\
    //   MInt pow(long long exponent) const {\r\n//     MInt tmp = *this, res = 1;\r\
    \n//     while (exponent > 0) {\r\n//       if (exponent & 1) res *= tmp;\r\n\
    //       tmp *= tmp;\r\n//       exponent >>= 1;\r\n//     }\r\n//     return\
    \ res;\r\n//   }\r\n//   MInt &operator+=(const MInt &x) { if((val += x.val) >=\
    \ MOD) val -= MOD; return *this; }\r\n//   MInt &operator-=(const MInt &x) { if((val\
    \ += MOD - x.val) >= MOD) val -= MOD; return *this; }\r\n//   MInt &operator*=(const\
    \ MInt &x) { val = static_cast<unsigned long long>(val) * x.val % MOD; return\
    \ *this; }\r\n//   MInt &operator/=(const MInt &x) { return *this *= inv(x.val);\
    \ }\r\n//   bool operator==(const MInt &x) const { return val == x.val; }\r\n\
    //   bool operator!=(const MInt &x) const { return val != x.val; }\r\n//   bool\
    \ operator<(const MInt &x) const { return val < x.val; }\r\n//   bool operator<=(const\
    \ MInt &x) const { return val <= x.val; }\r\n//   bool operator>(const MInt &x)\
    \ const { return val > x.val; }\r\n//   bool operator>=(const MInt &x) const {\
    \ return val >= x.val; }\r\n//   MInt &operator++() { if (++val == MOD) val =\
    \ 0; return *this; }\r\n//   MInt operator++(int) { MInt res = *this; ++*this;\
    \ return res; }\r\n//   MInt &operator--() { val = (val == 0 ? MOD : val) - 1;\
    \ return *this; }\r\n//   MInt operator--(int) { MInt res = *this; --*this; return\
    \ res; }\r\n//   MInt operator+() const { return *this; }\r\n//   MInt operator-()\
    \ const { return MInt(val ? MOD - val : 0); }\r\n//   MInt operator+(const MInt\
    \ &x) const { return MInt(*this) += x; }\r\n//   MInt operator-(const MInt &x)\
    \ const { return MInt(*this) -= x; }\r\n//   MInt operator*(const MInt &x) const\
    \ { return MInt(*this) *= x; }\r\n//   MInt operator/(const MInt &x) const { return\
    \ MInt(*this) /= x; }\r\n//   friend std::ostream &operator<<(std::ostream &os,\
    \ const MInt &x) { return os << x.val; }\r\n//   friend std::istream &operator>>(std::istream\
    \ &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }\r\n//\
    \ };\r\n// namespace std { template <int MOD> MInt<MOD> abs(const MInt<MOD> &x)\
    \ { return x; } }\r\n\r\ntemplate <int ID>\r\nstruct MInt {\r\n  unsigned int\
    \ val;\r\n  MInt(): val(0) {}\r\n  MInt(long long x) : val(x >= 0 ? x % mod()\
    \ : x % mod() + mod()) {}\r\n  static int get_mod() { return mod(); }\r\n  static\
    \ void set_mod(int divisor) { mod() = divisor; }\r\n  static void init(int x =\
    \ 10000000) { inv(x, true); fact(x); fact_inv(x); }\r\n  static MInt inv(int x,\
    \ bool init = false) {\r\n    // assert(0 <= x && x < mod() && std::__gcd(x, mod())\
    \ == 1);\r\n    static std::vector<MInt> inverse{0, 1};\r\n    int prev = inverse.size();\r\
    \n    if (init && x >= prev) {\r\n      // \"x!\" and \"mod()\" must be disjoint.\r\
    \n      inverse.resize(x + 1);\r\n      for (int i = prev; i <= x; ++i) inverse[i]\
    \ = -inverse[mod() % i] * (mod() / i);\r\n    }\r\n    if (x < inverse.size())\
    \ return inverse[x];\r\n    unsigned int a = x, b = mod(); int u = 1, v = 0;\r\
    \n    while (b) {\r\n      unsigned int tmp = a / b;\r\n      std::swap(a -= tmp\
    \ * b, b);\r\n      std::swap(u -= tmp * v, v);\r\n    }\r\n    return u;\r\n\
    \  }\r\n  static MInt fact(int x) {\r\n    static std::vector<MInt> f{1};\r\n\
    \    int prev = f.size();\r\n    if (x >= prev) {\r\n      f.resize(x + 1);\r\n\
    \      for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n    }\r\n    return\
    \ f[x];\r\n  }\r\n  static MInt fact_inv(int x) {\r\n    static std::vector<MInt>\
    \ finv{1};\r\n    int prev = finv.size();\r\n    if (x >= prev) {\r\n      finv.resize(x\
    \ + 1);\r\n      finv[x] = inv(fact(x).val);\r\n      for (int i = x; i > prev;\
    \ --i) finv[i - 1] = finv[i] * i;\r\n    }\r\n    return finv[x];\r\n  }\r\n \
    \ static MInt nCk(int n, int k) {\r\n    if (n < 0 || n < k || k < 0) return 0;\r\
    \n    if (n - k > k) k = n - k;\r\n    return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n  }\r\n  static MInt nPk(int n, int k) { return n < 0 || n < k || k\
    \ < 0 ? 0 : fact(n) * fact_inv(n - k); }\r\n  static MInt nHk(int n, int k) {\
    \ return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n  MInt pow(long\
    \ long exponent) const {\r\n    MInt tmp = *this, res = 1;\r\n    while (exponent\
    \ > 0) {\r\n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n     \
    \ exponent >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n  MInt &operator+=(const\
    \ MInt &x) { if((val += x.val) >= mod()) val -= mod(); return *this; }\r\n  MInt\
    \ &operator-=(const MInt &x) { if((val += mod() - x.val) >= mod()) val -= mod();\
    \ return *this; }\r\n  MInt &operator*=(const MInt &x) { val = static_cast<unsigned\
    \ long long>(val) * x.val % mod(); return *this; }\r\n  MInt &operator/=(const\
    \ MInt &x) { return *this *= inv(x.val); }\r\n  bool operator==(const MInt &x)\
    \ const { return val == x.val; }\r\n  bool operator!=(const MInt &x) const { return\
    \ val != x.val; }\r\n  bool operator<(const MInt &x) const { return val < x.val;\
    \ }\r\n  bool operator<=(const MInt &x) const { return val <= x.val; }\r\n  bool\
    \ operator>(const MInt &x) const { return val > x.val; }\r\n  bool operator>=(const\
    \ MInt &x) const { return val >= x.val; }\r\n  MInt &operator++() { if (++val\
    \ == mod()) val = 0; return *this; }\r\n  MInt operator++(int) { MInt res = *this;\
    \ ++*this; return res; }\r\n  MInt &operator--() { val = (val == 0 ? mod() : val)\
    \ - 1; return *this; }\r\n  MInt operator--(int) { MInt res = *this; --*this;\
    \ return res; }\r\n  MInt operator+() const { return *this; }\r\n  MInt operator-()\
    \ const { return MInt(val ? mod() - val : 0); }\r\n  MInt operator+(const MInt\
    \ &x) const { return MInt(*this) += x; }\r\n  MInt operator-(const MInt &x) const\
    \ { return MInt(*this) -= x; }\r\n  MInt operator*(const MInt &x) const { return\
    \ MInt(*this) *= x; }\r\n  MInt operator/(const MInt &x) const { return MInt(*this)\
    \ /= x; }\r\n  friend std::ostream &operator<<(std::ostream &os, const MInt &x)\
    \ { return os << x.val; }\r\n  friend std::istream &operator>>(std::istream &is,\
    \ MInt &x) { long long val; is >> val; x = MInt(val); return is; }\r\nprivate:\r\
    \n  static int &mod() { static int divisor = 0; return divisor; }\r\n};\r\nnamespace\
    \ std { template <int ID> MInt<ID> abs(const MInt<ID> &x) { return x; } }\r\n\
    #line 4 \"math/osa_k.hpp\"\n\r\nstruct osa_k {\r\n  osa_k(int n = 10000000) :\
    \ least_prime_factor(n + 1, -1) {\r\n    least_prime_factor[0] = 0;\r\n    if\
    \ (n >= 1) least_prime_factor[1] = 1;\r\n    for (int i = 2; i <= n; ++i) {\r\n\
    \      if (least_prime_factor[i] == -1) {\r\n        least_prime_factor[i] = i;\r\
    \n        for (long long j = static_cast<long long>(i) * i; j <= n; j += i) {\r\
    \n          if (least_prime_factor[j] == -1) least_prime_factor[j] = i;\r\n  \
    \      }\r\n      }\r\n    }\r\n  }\r\n\r\n  std::vector<std::pair<int, int>>\
    \ query(int n) const {\r\n    std::vector<std::pair<int, int>> res;\r\n    while\
    \ (n > 1) {\r\n      int prime = least_prime_factor[n], exponent = 0;\r\n    \
    \  while (least_prime_factor[n] == prime) {\r\n        ++exponent;\r\n       \
    \ n /= prime;\r\n      }\r\n      res.emplace_back(prime, exponent);\r\n    }\r\
    \n    return res;\r\n  }\r\n\r\nprivate:\r\n  std::vector<int> least_prime_factor;\r\
    \n};\r\n#line 12 \"test/math/osa_k.test.cpp\"\n\r\nint main() {\r\n  using ModInt\
    \ = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\n  int n;\r\n  std::cin >> n;\r\
    \n  osa_k osa(n);\r\n  std::map<int, int> mp;\r\n  for (int i = 2; i <= n; ++i)\
    \ {\r\n    for (const std::pair<int, int> &pr : osa.query(i)) mp[pr.first] +=\
    \ pr.second;\r\n  }\r\n  ModInt ans = 1;\r\n  for (const std::pair<int, int> &pr\
    \ : mp) ans *= pr.second + 1;\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/osa_k \u6CD5\r\n */\r\n#define IGNORE\r\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc052/tasks/arc067_a\"\r\n\r\n#include\
    \ <iostream>\r\n#include <map>\r\n#include <utility>\r\n#include \"../../math/modint.hpp\"\
    \r\n#include \"../../math/osa_k.hpp\"\r\n\r\nint main() {\r\n  using ModInt =\
    \ MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\n  int n;\r\n  std::cin >> n;\r\
    \n  osa_k osa(n);\r\n  std::map<int, int> mp;\r\n  for (int i = 2; i <= n; ++i)\
    \ {\r\n    for (const std::pair<int, int> &pr : osa.query(i)) mp[pr.first] +=\
    \ pr.second;\r\n  }\r\n  ModInt ans = 1;\r\n  for (const std::pair<int, int> &pr\
    \ : mp) ans *= pr.second + 1;\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/osa_k.hpp
  isVerificationFile: true
  path: test/math/osa_k.test.cpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/osa_k.test.cpp
layout: document
redirect_from:
- /verify/test/math/osa_k.test.cpp
- /verify/test/math/osa_k.test.cpp.html
title: "\u6570\u5B66/osa_k \u6CD5"
---
