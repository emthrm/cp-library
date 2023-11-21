---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/exp_of_set_power_series.hpp
    title: "\u96C6\u5408\u51AA\u7D1A\u6570 (set power series) \u306E\u6307\u6570"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/subset_convolution.hpp
    title: subset convolution
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_set_power_series
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u96C6\u5408\u51AA\u7D1A\
      \u6570\u306E\u6307\u6570"
    links:
    - https://judge.yosupo.jp/problem/exp_of_set_power_series
  bundledCode: "#line 1 \"test/math/convolution/exp_of_set_power_series.test.cpp\"\
    \n/*\n * @title \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u96C6\u5408\u51AA\u7D1A\
    \u6570\u306E\u6307\u6570\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/exp_of_set_power_series\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/math/convolution/exp_of_set_power_series.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <iterator>\n\
    #line 9 \"include/emthrm/math/convolution/exp_of_set_power_series.hpp\"\n\n#line\
    \ 1 \"include/emthrm/math/convolution/subset_convolution.hpp\"\n\n\n\n#include\
    \ <array>\n#line 7 \"include/emthrm/math/convolution/subset_convolution.hpp\"\n\
    #include <utility>\n#line 9 \"include/emthrm/math/convolution/subset_convolution.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int MaxN, typename T>\nstd::vector<T> subset_convolution(\n\
    \    const std::vector<T>& f, const std::vector<T>& g) {\n  using Polynomial =\
    \ std::array<T, MaxN + 1>;\n  assert(std::has_single_bit(f.size()) && f.size()\
    \ == g.size());\n  const int n = std::countr_zero(f.size());\n  assert(n <= MaxN);\n\
    \  const int domain_size = 1 << n;\n  const auto ranked_zeta_transform =\n   \
    \   [n, domain_size](const std::vector<T>& f) -> std::vector<Polynomial> {\n \
    \   std::vector a(domain_size, Polynomial{});\n    for (int i = 0; i < domain_size;\
    \ ++i) {\n      a[i][std::popcount(static_cast<unsigned int>(i))] = f[i];\n  \
    \  }\n    for (int bit = 1; bit < domain_size; bit <<= 1) {\n      for (int i\
    \ = 0; i < domain_size; ++i) {\n        if ((i & bit) == 0) {\n          for (int\
    \ degree = 0; degree <= n; ++degree) {\n            a[i | bit][degree] += a[i][degree];\n\
    \          }\n        }\n      }\n    }\n    return a;\n  };\n  std::vector<Polynomial>\
    \ a = ranked_zeta_transform(f);\n  const std::vector<Polynomial> b = ranked_zeta_transform(g);\n\
    \  for (int i = 0; i < domain_size; ++i) {\n    // Hadamard product\n    for (int\
    \ degree_of_a = n; degree_of_a >= 0; --degree_of_a) {\n      const T tmp = std::exchange(a[i][degree_of_a],\
    \ T{});\n      for (int degree_of_b = 0; degree_of_a + degree_of_b <= n; ++degree_of_b)\
    \ {\n        a[i][degree_of_a + degree_of_b] += tmp * b[i][degree_of_b];\n   \
    \   }\n    }\n  }\n  for (int bit = 1; bit < domain_size; bit <<= 1) {\n    for\
    \ (int i = 0; i < domain_size; ++i) {\n      if ((i & bit) == 0) {\n        for\
    \ (int degree = 0; degree <= n; ++degree) {\n          a[i | bit][degree] -= a[i][degree];\n\
    \        }\n      }\n    }\n  }\n  std::vector<T> c(domain_size);\n  for (int\
    \ i = 0; i < domain_size; ++i) {\n    c[i] = a[i][std::popcount(static_cast<unsigned\
    \ int>(i))];\n  }\n  return c;\n}\n\n}  // namespace emthrm\n\n\n#line 11 \"include/emthrm/math/convolution/exp_of_set_power_series.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int MaxN, typename T>\nstd::vector<T> exp_of_set_power_series(const\
    \ std::vector<T>& f) {\n  assert(std::has_single_bit(f.size()) && f[0] == 0);\n\
    \  const int n = std::countr_zero(f.size());\n  assert(n <= MaxN);\n  std::vector<T>\
    \ exponential{1};\n  exponential.reserve(1 << n);\n  for (int i = 0; i < n; ++i)\
    \ {\n    std::ranges::copy(subset_convolution<MaxN>(\n                       \
    \   exponential,\n                          std::vector(std::next(f.begin(), 1\
    \ << i),\n                                      std::next(f.begin(), 1 << (i +\
    \ 1)))),\n                      std::back_inserter(exponential));\n  }\n  return\
    \ exponential;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/modint.hpp\"\
    \n\n\n\n#ifndef ARBITRARY_MODINT\n#line 6 \"include/emthrm/math/modint.hpp\"\n\
    #endif\n#include <compare>\n#line 9 \"include/emthrm/math/modint.hpp\"\n// #include\
    \ <numeric>\n#line 12 \"include/emthrm/math/modint.hpp\"\n\nnamespace emthrm {\n\
    \n#ifndef ARBITRARY_MODINT\ntemplate <unsigned int M>\nstruct MInt {\n  unsigned\
    \ int v;\n\n  constexpr MInt() : v(0) {}\n  constexpr MInt(const long long x)\
    \ : v(x >= 0 ? x % M : x % M + M) {}\n  static constexpr MInt raw(const int x)\
    \ {\n    MInt x_;\n    x_.v = x;\n    return x_;\n  }\n\n  static constexpr int\
    \ get_mod() { return M; }\n  static constexpr void set_mod(const int divisor)\
    \ {\n    assert(std::cmp_equal(divisor, M));\n  }\n\n  static void init(const\
    \ int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n  }\n\n  template\
    \ <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n    // assert(0 <=\
    \ n && n < M && std::gcd(n, M) == 1);\n    static std::vector<MInt> inverse{0,\
    \ 1};\n    const int prev = inverse.size();\n    if (n < prev) return inverse[n];\n\
    \    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be disjoint.\n\
    \      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i) {\n     \
    \   inverse[i] = -inverse[M % i] * raw(M / i);\n      }\n      return inverse[n];\n\
    \    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b = M; b;) {\n   \
    \   const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u\
    \ -= q * v, v);\n    }\n    return u;\n  }\n\n  static MInt fact(const int n)\
    \ {\n    static std::vector<MInt> factorial{1};\n    if (const int prev = factorial.size();\
    \ n >= prev) {\n      factorial.resize(n + 1);\n      for (int i = prev; i <=\
    \ n; ++i) {\n        factorial[i] = factorial[i - 1] * i;\n      }\n    }\n  \
    \  return factorial[n];\n  }\n\n  static MInt fact_inv(const int n) {\n    static\
    \ std::vector<MInt> f_inv{1};\n    if (const int prev = f_inv.size(); n >= prev)\
    \ {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n      for (int\
    \ i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n      }\n   \
    \ }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const int k)\
    \ {\n    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();\n    return\
    \ fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\n                   \
    \               fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const\
    \ int n, const int k) {\n    return n < 0 || n < k || k < 0 ? MInt() : fact(n)\
    \ * fact_inv(n - k);\n  }\n  static MInt nHk(const int n, const int k) {\n   \
    \ return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n\
    \  static MInt large_nCk(long long n, const int k) {\n    if (n < 0 || n < k ||\
    \ k < 0) [[unlikely]] return MInt();\n    inv<true>(k);\n    MInt res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  constexpr MInt pow(long long exponent) const {\n    MInt res\
    \ = 1, tmp = *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  constexpr\
    \ MInt& operator+=(const MInt& x) {\n    if ((v += x.v) >= M) v -= M;\n    return\
    \ *this;\n  }\n  constexpr MInt& operator-=(const MInt& x) {\n    if ((v += M\
    \ - x.v) >= M) v -= M;\n    return *this;\n  }\n  constexpr MInt& operator*=(const\
    \ MInt& x) {\n    v = (unsigned long long){v} * x.v % M;\n    return *this;\n\
    \  }\n  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }\n\n  constexpr\
    \ auto operator<=>(const MInt& x) const = default;\n\n  constexpr MInt& operator++()\
    \ {\n    if (++v == M) [[unlikely]] v = 0;\n    return *this;\n  }\n  constexpr\
    \ MInt operator++(int) {\n    const MInt res = *this;\n    ++*this;\n    return\
    \ res;\n  }\n  constexpr MInt& operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n\
    \    return *this;\n  }\n  constexpr MInt operator--(int) {\n    const MInt res\
    \ = *this;\n    --*this;\n    return res;\n  }\n\n  constexpr MInt operator+()\
    \ const { return *this; }\n  constexpr MInt operator-() const { return raw(v ?\
    \ M - v : 0); }\n\n  constexpr MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  constexpr MInt operator-(const MInt& x) const { return MInt(*this)\
    \ -= x; }\n  constexpr MInt operator*(const MInt& x) const { return MInt(*this)\
    \ *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }\n\
    \n  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {\n    return\
    \ os << x.v;\n  }\n  friend std::istream& operator>>(std::istream& is, MInt& x)\
    \ {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return is;\n  }\n};\n\
    #else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n  unsigned int v;\n\
    \n  constexpr MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0 ? x % mod()\
    \ : x % mod() + mod()) {}\n  static constexpr MInt raw(const int x) {\n    MInt\
    \ x_;\n    x_.v = x;\n    return x_;\n  }\n\n  static int get_mod() { return mod();\
    \ }\n  static void set_mod(const unsigned int divisor) { mod() = divisor; }\n\n\
    \  static void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < mod() && std::gcd(x, mod()) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[mod() % i] * raw(mod() / i);\n      }\n   \
    \   return inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned int a\
    \ = n, b = mod(); b;) {\n      const unsigned int q = a / b;\n      std::swap(a\
    \ -= q * b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n\
    \  static MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n\
    \    if (const int prev = factorial.size(); n >= prev) {\n      factorial.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i\
    \ - 1] * i;\n      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
    \ int n) {\n    static std::vector<MInt> f_inv{1};\n    if (const int prev = f_inv.size();\
    \ n >= prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n\
    \      for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n\
    \      }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
    \ int k) {\n    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();\n   \
    \ return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :\n            \
    \                      fact_inv(n - k) * fact_inv(k));\n  }\n  static MInt nPk(const\
    \ int n, const int k) {\n    return n < 0 || n < k || k < 0 ? MInt() : fact(n)\
    \ * fact_inv(n - k);\n  }\n  static MInt nHk(const int n, const int k) {\n   \
    \ return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));\n  }\n\n\
    \  static MInt large_nCk(long long n, const int k) {\n    if (n < 0 || n < k ||\
    \ k < 0) [[unlikely]] return MInt();\n    inv<true>(k);\n    MInt res = 1;\n \
    \   for (int i = 1; i <= k; ++i) {\n      res *= inv(i) * n--;\n    }\n    return\
    \ res;\n  }\n\n  MInt pow(long long exponent) const {\n    MInt res = 1, tmp =\
    \ *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1)\
    \ res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  MInt& operator+=(const\
    \ MInt& x) {\n    if ((v += x.v) >= mod()) v -= mod();\n    return *this;\n  }\n\
    \  MInt& operator-=(const MInt& x) {\n    if ((v += mod() - x.v) >= mod()) v -=\
    \ mod();\n    return *this;\n  }\n  MInt& operator*=(const MInt& x) {\n    v =\
    \ (unsigned long long){v} * x.v % mod();\n    return *this;\n    }\n  MInt& operator/=(const\
    \ MInt& x) { return *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x)\
    \ const = default;\n\n  MInt& operator++() {\n    if (++v == mod()) [[unlikely]]\
    \ v = 0;\n    return *this;\n  }\n  MInt operator++(int) {\n    const MInt res\
    \ = *this;\n    ++*this;\n    return res;\n  }\n  MInt& operator--() {\n    v\
    \ = (v == 0 ? mod() - 1 : v - 1);\n    return *this;\n  }\n  MInt operator--(int)\
    \ {\n    const MInt res = *this;\n    --*this;\n    return res;\n  }\n\n  MInt\
    \ operator+() const { return *this; }\n  MInt operator-() const { return raw(v\
    \ ? mod() - v : 0); }\n\n  MInt operator+(const MInt& x) const { return MInt(*this)\
    \ += x; }\n  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }\n\
    \  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }\n  MInt operator/(const\
    \ MInt& x) const { return MInt(*this) /= x; }\n\n  friend std::ostream& operator<<(std::ostream&\
    \ os, const MInt& x) {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n\n private:\n  static unsigned int& mod() {\n    static unsigned int\
    \ divisor = 0;\n    return divisor;\n  }\n};\n#endif  // ARBITRARY_MODINT\n\n\
    }  // namespace emthrm\n\n\n#line 12 \"test/math/convolution/exp_of_set_power_series.test.cpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n  constexpr int kMaxN\
    \ = 20;\n  int n;\n  std::cin >> n;\n  std::vector<ModInt> b(1 << n);\n  for (int\
    \ i = 0; i < (1 << n); ++i) {\n    std::cin >> b[i];\n  }\n  const std::vector<ModInt>\
    \ c = emthrm::exp_of_set_power_series<kMaxN>(b);\n  for (int i = 0; i < (1 <<\
    \ n); ++i) {\n    std::cout << c[i] << \" \\n\"[i + 1 == (1 << n)];\n  }\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u96C6\u5408\u51AA\u7D1A\
    \u6570\u306E\u6307\u6570\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/exp_of_set_power_series\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/convolution/exp_of_set_power_series.hpp\"\
    \n#include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n\
    \  constexpr int kMaxN = 20;\n  int n;\n  std::cin >> n;\n  std::vector<ModInt>\
    \ b(1 << n);\n  for (int i = 0; i < (1 << n); ++i) {\n    std::cin >> b[i];\n\
    \  }\n  const std::vector<ModInt> c = emthrm::exp_of_set_power_series<kMaxN>(b);\n\
    \  for (int i = 0; i < (1 << n); ++i) {\n    std::cout << c[i] << \" \\n\"[i +\
    \ 1 == (1 << n)];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/exp_of_set_power_series.hpp
  - include/emthrm/math/convolution/subset_convolution.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/convolution/exp_of_set_power_series.test.cpp
  requiredBy: []
  timestamp: '2023-08-15 15:09:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/convolution/exp_of_set_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/exp_of_set_power_series.test.cpp
- /verify/test/math/convolution/exp_of_set_power_series.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u96C6\u5408\u51AA\u7D1A\u6570\u306E\
  \u6307\u6570"
---
