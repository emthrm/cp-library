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
    \n// #include <cassert>\r\n#line 5 \"math/modint.hpp\"\n#include <utility>\r\n\
    #include <vector>\r\n\r\n// template <int M>\r\n// struct MInt {\r\n//   unsigned\
    \ int val;\r\n//   MInt(): val(0) {}\r\n//   MInt(long long x) : val(x >= 0 ?\
    \ x % M : x % M + M) {}\r\n//   static constexpr int get_mod() { return M; }\r\
    \n//   static void set_mod(int divisor) { assert(divisor == M); }\r\n//   static\
    \ void init(int x = 10000000) { inv(x, true); fact(x); fact_inv(x); }\r\n//  \
    \ static MInt inv(int x, bool init = false) {\r\n//     // assert(0 <= x && x\
    \ < M && std::__gcd(x, M) == 1);\r\n//     static std::vector<MInt> inverse{0,\
    \ 1};\r\n//     int prev = inverse.size();\r\n//     if (init && x >= prev) {\r\
    \n//       // \"x!\" and \"M\" must be disjoint.\r\n//       inverse.resize(x\
    \ + 1);\r\n//       for (int i = prev; i <= x; ++i) inverse[i] = -inverse[M %\
    \ i] * (M / i);\r\n//     }\r\n//     if (x < inverse.size()) return inverse[x];\r\
    \n//     unsigned int a = x, b = M; int u = 1, v = 0;\r\n//     while (b) {\r\n\
    //       unsigned int q = a / b;\r\n//       std::swap(a -= q * b, b);\r\n// \
    \      std::swap(u -= q * v, v);\r\n//     }\r\n//     return u;\r\n//   }\r\n\
    //   static MInt fact(int x) {\r\n//     static std::vector<MInt> f{1};\r\n//\
    \     int prev = f.size();\r\n//     if (x >= prev) {\r\n//       f.resize(x +\
    \ 1);\r\n//       for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;\r\n// \
    \    }\r\n//     return f[x];\r\n//   }\r\n//   static MInt fact_inv(int x) {\r\
    \n//     static std::vector<MInt> finv{1};\r\n//     int prev = finv.size();\r\
    \n//     if (x >= prev) {\r\n//       finv.resize(x + 1);\r\n//       finv[x]\
    \ = inv(fact(x).val);\r\n//       for (int i = x; i > prev; --i) finv[i - 1] =\
    \ finv[i] * i;\r\n//     }\r\n//     return finv[x];\r\n//   }\r\n//   static\
    \ MInt nCk(int n, int k) {\r\n//     if (n < 0 || n < k || k < 0) return 0;\r\n\
    //     if (n - k > k) k = n - k;\r\n//     return fact(n) * fact_inv(k) * fact_inv(n\
    \ - k);\r\n//   }\r\n//   static MInt nPk(int n, int k) { return n < 0 || n <\
    \ k || k < 0 ? 0 : fact(n) * fact_inv(n - k); }\r\n//   static MInt nHk(int n,\
    \ int k) { return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }\r\n\
    //   static MInt large_nCk(long long n, int k) {\r\n//     if (n < 0 || n < k\
    \ || k < 0) return 0;\r\n//     inv(k, true);\r\n//     MInt res = 1;\r\n//  \
    \   for (int i = 1; i <= k; ++i) res *= inv(i) * n--;\r\n//     return res;\r\n\
    //   }\r\n//   MInt pow(long long exponent) const {\r\n//     MInt tmp = *this,\
    \ res = 1;\r\n//     while (exponent > 0) {\r\n//       if (exponent & 1) res\
    \ *= tmp;\r\n//       tmp *= tmp;\r\n//       exponent >>= 1;\r\n//     }\r\n\
    //     return res;\r\n//   }\r\n//   MInt &operator+=(const MInt &x) { if((val\
    \ += x.val) >= M) val -= M; return *this; }\r\n//   MInt &operator-=(const MInt\
    \ &x) { if((val += M - x.val) >= M) val -= M; return *this; }\r\n//   MInt &operator*=(const\
    \ MInt &x) { val = static_cast<unsigned long long>(val) * x.val % M; return *this;\
    \ }\r\n//   MInt &operator/=(const MInt &x) { return *this *= inv(x.val); }\r\n\
    //   bool operator==(const MInt &x) const { return val == x.val; }\r\n//   bool\
    \ operator!=(const MInt &x) const { return val != x.val; }\r\n//   bool operator<(const\
    \ MInt &x) const { return val < x.val; }\r\n//   bool operator<=(const MInt &x)\
    \ const { return val <= x.val; }\r\n//   bool operator>(const MInt &x) const {\
    \ return val > x.val; }\r\n//   bool operator>=(const MInt &x) const { return\
    \ val >= x.val; }\r\n//   MInt &operator++() { if (++val == M) val = 0; return\
    \ *this; }\r\n//   MInt operator++(int) { MInt res = *this; ++*this; return res;\
    \ }\r\n//   MInt &operator--() { val = (val == 0 ? M : val) - 1; return *this;\
    \ }\r\n//   MInt operator--(int) { MInt res = *this; --*this; return res; }\r\n\
    //   MInt operator+() const { return *this; }\r\n//   MInt operator-() const {\
    \ return MInt(val ? M - val : 0); }\r\n//   MInt operator+(const MInt &x) const\
    \ { return MInt(*this) += x; }\r\n//   MInt operator-(const MInt &x) const { return\
    \ MInt(*this) -= x; }\r\n//   MInt operator*(const MInt &x) const { return MInt(*this)\
    \ *= x; }\r\n//   MInt operator/(const MInt &x) const { return MInt(*this) /=\
    \ x; }\r\n//   friend std::ostream &operator<<(std::ostream &os, const MInt &x)\
    \ { return os << x.val; }\r\n//   friend std::istream &operator>>(std::istream\
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
    \ 4 \"math/catalan_number.hpp\"\n\r\ntemplate <int T>\r\nstd::vector<MInt<T>>\
    \ catalan_number(int n) {\r\n  using ModInt = MInt<T>;\r\n  ModInt::inv(n + 1,\
    \ true);\r\n  std::vector<ModInt> catalan(n + 1);\r\n  catalan[0] = 1;\r\n  for\
    \ (int i = 0; i < n; ++i) catalan[i + 1] = catalan[i] * ModInt::inv(i + 2) * 2\
    \ * (2 * i + 1);\r\n  return catalan;\r\n}\r\n#line 9 \"test/math/catalan_number.test.cpp\"\
    \n\r\nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(742909);\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::cout << catalan_number<0>(n)[n] << '\\\
    n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570\r\n */\r\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/790\"\r\n\r\n#include <iostream>\r\
    \n#include \"../../math/modint.hpp\"\r\n#include \"../../math/catalan_number.hpp\"\
    \r\n\r\nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(742909);\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::cout << catalan_number<0>(n)[n] << '\\\
    n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/catalan_number.hpp
  isVerificationFile: true
  path: test/math/catalan_number.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/catalan_number.test.cpp
layout: document
redirect_from:
- /verify/test/math/catalan_number.test.cpp
- /verify/test/math/catalan_number.test.cpp.html
title: "\u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570"
---
