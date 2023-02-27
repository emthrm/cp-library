---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/117
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570"
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/math/twelvefold_way/binomial_coefficients.test.cpp\"\
    \n/*\n * @title \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\n *\n\
    \ * verification-helper: PROBLEM https://yukicoder.me/problems/no/117\n */\n\n\
    #include <algorithm>\n#include <iostream>\n#include <iterator>\n#include <string>\n\
    \n#line 1 \"include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n\
    # include <cassert>\n#endif\n#include <compare>\n#line 9 \"include/emthrm/math/modint.hpp\"\
    \n// #include <numeric>\n#include <utility>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\n#ifndef ARBITRARY_MODINT\ntemplate <int M>\nstruct MInt {\n  unsigned int\
    \ v;\n\n  MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % M : x %\
    \ M + M) {}\n\n  static constexpr int get_mod() { return M; }\n  static void set_mod(const\
    \ int divisor) { assert(divisor == M); }\n\n  static void init(const int x) {\n\
    \    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\n  template <bool MEMOIZES\
    \ = false>\n  static MInt inv(const int n) {\n    // assert(0 <= n && n < M &&\
    \ std::gcd(n, M) == 1);\n    static std::vector<MInt> inverse{0, 1};\n    const\
    \ int prev = inverse.size();\n    if (n < prev) return inverse[n];\n    if constexpr\
    \ (MEMOIZES) {\n      // \"n!\" and \"M\" must be disjoint.\n      inverse.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        inverse[i] = -inverse[M\
    \ % i] * (M / i);\n      }\n      return inverse[n];\n    }\n    int u = 1, v\
    \ = 0;\n    for (unsigned int a = n, b = M; b;) {\n      const unsigned int q\
    \ = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u -= q * v, v);\n\
    \    }\n    return u;\n  }\n\n  static MInt fact(const int n) {\n    static std::vector<MInt>\
    \ factorial{1};\n    const int prev = factorial.size();\n    if (n >= prev) {\n\
    \      factorial.resize(n + 1);\n      for (int i = prev; i <= n; ++i) {\n   \
    \     factorial[i] = factorial[i - 1] * i;\n      }\n    }\n    return factorial[n];\n\
    \  }\n\n  static MInt fact_inv(const int n) {\n    static std::vector<MInt> f_inv{1};\n\
    \    const int prev = f_inv.size();\n    if (n >= prev) {\n      f_inv.resize(n\
    \ + 1);\n      f_inv[n] = inv(fact(n).v);\n      for (int i = n; i > prev; --i)\
    \ {\n        f_inv[i - 1] = f_inv[i] * i;\n      }\n    }\n    return f_inv[n];\n\
    \  }\n\n  static MInt nCk(const int n, const int k) {\n    if (n < 0 || n < k\
    \ || k < 0) return 0;\n    return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n\
    \ - k) :\n                                  fact_inv(n - k) * fact_inv(k));\n\
    \  }\n  static MInt nPk(const int n, const int k) {\n    return n < 0 || n < k\
    \ || k < 0 ? 0 : fact(n) * fact_inv(n - k);\n  }\n  static MInt nHk(const int\
    \ n, const int k) {\n    return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k -\
    \ 1, k));\n  }\n\n  static MInt large_nCk(long long n, const int k) {\n    if\
    \ (n < 0 || n < k || k < 0) return 0;\n    inv<true>(k);\n    MInt res = 1;\n\
    \    for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  MInt pow(long long exponent) const {\n    MInt res = 1, tmp =\
    \ *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1)\
    \ res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  MInt& operator+=(const\
    \ MInt& x) {\n    if (std::cmp_greater_equal(v += x.v, M)) v -= M;\n    return\
    \ *this;\n  }\n  MInt& operator-=(const MInt& x) {\n    if (std::cmp_greater_equal(v\
    \ += M - x.v, M)) v -= M;\n    return *this;\n  }\n  MInt& operator*=(const MInt&\
    \ x) {\n    v = static_cast<unsigned long long>(v) * x.v % M;\n    return *this;\n\
    \  }\n  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }\n\n  auto\
    \ operator<=>(const MInt& x) const = default;\n\n  MInt& operator++() {\n    if\
    \ (std::cmp_equal(++v, M)) v = 0;\n    return *this;\n  }\n  MInt operator++(int)\
    \ {\n    const MInt res = *this;\n    ++*this;\n    return res;\n  }\n  MInt&\
    \ operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n    return *this;\n  }\n\
    \  MInt operator--(int) {\n    const MInt res = *this;\n    --*this;\n    return\
    \ res;\n  }\n\n  MInt operator+() const { return *this; }\n  MInt operator-()\
    \ const { return MInt(v ? M - v : 0); }\n\n  MInt operator+(const MInt& x) const\
    \ { return MInt(*this) += x; }\n  MInt operator-(const MInt& x) const { return\
    \ MInt(*this) -= x; }\n  MInt operator*(const MInt& x) const { return MInt(*this)\
    \ *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }\n\
    \n  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {\n    return\
    \ os << x.v;\n  }\n  friend std::istream& operator>>(std::istream& is, MInt& x)\
    \ {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return is;\n  }\n};\n\
    #else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n  unsigned int v;\n\
    \n  MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % mod() : x % mod()\
    \ + mod()) {}\n\n  static int get_mod() { return mod(); }\n  static void set_mod(const\
    \ int divisor) { mod() = divisor; }\n\n  static void init(const int x) {\n   \
    \ inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\n  template <bool MEMOIZES\
    \ = false>\n  static MInt inv(const int n) {\n    // assert(0 <= n && n < mod()\
    \ && std::gcd(x, mod()) == 1);\n    static std::vector<MInt> inverse{0, 1};\n\
    \    const int prev = inverse.size();\n    if (n < prev) return inverse[n];\n\
    \    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be disjoint.\n\
    \      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i) {\n     \
    \   inverse[i] = -inverse[mod() % i] * (mod() / i);\n      }\n      return inverse[n];\n\
    \    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b = mod(); b;) {\n\
    \      const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u\
    \ -= q * v, v);\n    }\n    return u;\n  }\n\n  static MInt fact(const int n)\
    \ {\n    static std::vector<MInt> factorial{1};\n    const int prev = factorial.size();\n\
    \    if (n >= prev) {\n      factorial.resize(n + 1);\n      for (int i = prev;\
    \ i <= n; ++i) {\n        factorial[i] = factorial[i - 1] * i;\n      }\n    }\n\
    \    return factorial[n];\n  }\n\n  static MInt fact_inv(const int n) {\n    static\
    \ std::vector<MInt> f_inv{1};\n    const int prev = f_inv.size();\n    if (n >=\
    \ prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n    \
    \  for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n  \
    \    }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return fact(n) * (n\
    \ - k < k ? fact_inv(k) * fact_inv(n - k) :\n                                \
    \  fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const int n, const\
    \ int k) {\n    return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k);\n\
    \  }\n  static MInt nHk(const int n, const int k) {\n    return n < 0 || k < 0\
    \ ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n  static MInt large_nCk(long\
    \ long n, const int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    inv<true>(k);\n\
    \    MInt res = 1;\n    for (int i = 1; i <= k; ++i) {\n      res *= inv(i) *\
    \ n--;\n    }\n    return res;\n  }\n\n  MInt pow(long long exponent) const {\n\
    \    MInt res = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n\
    \      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n\
    \  }\n\n  MInt& operator+=(const MInt& x) {\n    if (std::cmp_greater_equal(v\
    \ += x.v, mod())) v -= mod();\n    return *this;\n  }\n  MInt& operator-=(const\
    \ MInt& x) {\n    if (std::cmp_greater_equal(v += mod() - x.v, mod())) v -= mod();\n\
    \    return *this;\n  }\n  MInt& operator*=(const MInt& x) {\n    v = static_cast<unsigned\
    \ long long>(v) * x.v % mod();\n    return *this;\n    }\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x)\
    \ const = default;\n\n  MInt& operator++() {\n    if (std::cmp_equal(++v, mod()))\
    \ v = 0;\n    return *this;\n  }\n  MInt operator++(int) {\n    const MInt res\
    \ = *this;\n    ++*this;\n    return res;\n  }\n  MInt& operator--() {\n    v\
    \ = (v == 0 ? mod() - 1 : v - 1);\n    return *this;\n  }\n  MInt operator--(int)\
    \ {\n    const MInt res = *this;\n    --*this;\n    return res;\n  }\n\n  MInt\
    \ operator+() const { return *this; }\n  MInt operator-() const { return MInt(v\
    \ ? mod() - v : 0); }\n\n  MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }\n\
    \  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }\n  MInt operator/(const\
    \ MInt& x) const { return MInt(*this) /= x; }\n\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n\n private:\n  static int& mod() {\n    static int divisor = 0;\n\
    \    return divisor;\n  }\n};\n#endif  // ARBITRARY_MODINT\n\n}  // namespace\
    \ emthrm\n\n\n#line 13 \"test/math/twelvefold_way/binomial_coefficients.test.cpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n  int t;\n  std::cin\
    \ >> t;\n  while (t--) {\n    std::string s;\n    std::cin >> s;\n    const auto\
    \ it = std::find(s.begin(), s.end(), ',');\n    const int n = std::stoi(std::string(std::next(s.begin(),\
    \ 2), it));\n    const int k = std::stoi(std::string(std::next(it), std::prev(s.end())));\n\
    \    if (s.front() == 'C') {\n      std::cout << ModInt::nCk(n, k) << '\\n';\n\
    \    } else if (s.front() == 'P') {\n      std::cout << ModInt::nPk(n, k) << '\\\
    n';\n    } else if (s.front() == 'H') {\n      std::cout << ModInt::nHk(n, k)\
    \ << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\n\
    \ *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/117\n */\n\
    \n#include <algorithm>\n#include <iostream>\n#include <iterator>\n#include <string>\n\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n\
    \  int t;\n  std::cin >> t;\n  while (t--) {\n    std::string s;\n    std::cin\
    \ >> s;\n    const auto it = std::find(s.begin(), s.end(), ',');\n    const int\
    \ n = std::stoi(std::string(std::next(s.begin(), 2), it));\n    const int k =\
    \ std::stoi(std::string(std::next(it), std::prev(s.end())));\n    if (s.front()\
    \ == 'C') {\n      std::cout << ModInt::nCk(n, k) << '\\n';\n    } else if (s.front()\
    \ == 'P') {\n      std::cout << ModInt::nPk(n, k) << '\\n';\n    } else if (s.front()\
    \ == 'H') {\n      std::cout << ModInt::nHk(n, k) << '\\n';\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/binomial_coefficients.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/twelvefold_way/binomial_coefficients.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/binomial_coefficients.test.cpp
- /verify/test/math/twelvefold_way/binomial_coefficients.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570"
---