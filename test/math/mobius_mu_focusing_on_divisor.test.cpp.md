---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mobius_mu_focusing_on_divisor.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 (M\xF6bius function) \u7D04\u6570\
      \u7248"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc162/tasks/abc162_e
    document_title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
      \u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
    links:
    - https://atcoder.jp/contests/abc162/tasks/abc162_e
  bundledCode: "#line 1 \"test/math/mobius_mu_focusing_on_divisor.test.cpp\"\n/*\n\
    \ * @title \u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\
    \u30B9\u95A2\u6570 \u7D04\u6570\u7248\n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc162/tasks/abc162_e\n\
    \ */\n\n#include <iostream>\n#include <map>\n\n#line 1 \"include/emthrm/math/mobius_mu_focusing_on_divisor.hpp\"\
    \n\n\n\n#include <bit>\n#line 6 \"include/emthrm/math/mobius_mu_focusing_on_divisor.hpp\"\
    \n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::map<T,\
    \ int> mobius_mu_focusing_on_divisor(T n) {\n  std::vector<T> primes;\n  for (T\
    \ i = 2; i * i <= n; ++i) {\n    if (n % i == 0) [[unlikely]] {\n      primes.emplace_back(i);\n\
    \      while (n % i == 0) n /= i;\n    }\n  }\n  if (n > 1) primes.emplace_back(n);\n\
    \  const int p = primes.size();\n  std::map<T, int> mu;\n  for (unsigned int i\
    \ = 0; i < (1 << p); ++i) {\n    T d = 1;\n    for (int j = 0; j < p; ++j) {\n\
    \      if (i >> j & 1) d *= primes[j];\n    }\n    mu[d] = (std::popcount(i) &\
    \ 1 ? -1 : 1);\n  }\n  return mu;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"\
    include/emthrm/math/modint.hpp\"\n\n\n\n#ifndef ARBITRARY_MODINT\n# include <cassert>\n\
    #endif\n#include <compare>\n#line 9 \"include/emthrm/math/modint.hpp\"\n// #include\
    \ <numeric>\n#include <utility>\n#line 12 \"include/emthrm/math/modint.hpp\"\n\
    \nnamespace emthrm {\n\n#ifndef ARBITRARY_MODINT\ntemplate <int M>\nstruct MInt\
    \ {\n  unsigned int v;\n\n  MInt() : v(0) {}\n  MInt(const long long x) : v(x\
    \ >= 0 ? x % M : x % M + M) {}\n\n  static constexpr int get_mod() { return M;\
    \ }\n  static void set_mod(const int divisor) { assert(divisor == M); }\n\n  static\
    \ void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < M && std::gcd(n, M) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[M % i] * (M / i);\n      }\n      return inverse[n];\n\
    \    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b = M; b;) {\n   \
    \   const unsigned int q = a / b;\n      std::swap(a -= q * b, b);\n      std::swap(u\
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
    \ += x.v, M)) v -= M;\n    return *this;\n  }\n  MInt& operator-=(const MInt&\
    \ x) {\n    if (std::cmp_greater_equal(v += M - x.v, M)) v -= M;\n    return *this;\n\
    \  }\n  MInt& operator*=(const MInt& x) {\n    v = static_cast<unsigned long long>(v)\
    \ * x.v % M;\n    return *this;\n  }\n  MInt& operator/=(const MInt& x) { return\
    \ *this *= inv(x.v); }\n\n  auto operator<=>(const MInt& x) const = default;\n\
    \n  MInt& operator++() {\n    if (std::cmp_equal(++v, M)) v = 0;\n    return *this;\n\
    \  }\n  MInt operator++(int) {\n    const MInt res = *this;\n    ++*this;\n  \
    \  return res;\n  }\n  MInt& operator--() {\n    v = (v == 0 ? M - 1 : v - 1);\n\
    \    return *this;\n  }\n  MInt operator--(int) {\n    const MInt res = *this;\n\
    \    --*this;\n    return res;\n  }\n\n  MInt operator+() const { return *this;\
    \ }\n  MInt operator-() const { return MInt(v ? M - v : 0); }\n\n  MInt operator+(const\
    \ MInt& x) const { return MInt(*this) += x; }\n  MInt operator-(const MInt& x)\
    \ const { return MInt(*this) -= x; }\n  MInt operator*(const MInt& x) const {\
    \ return MInt(*this) *= x; }\n  MInt operator/(const MInt& x) const { return MInt(*this)\
    \ /= x; }\n\n  friend std::ostream& operator<<(std::ostream& os, const MInt& x)\
    \ {\n    return os << x.v;\n  }\n  friend std::istream& operator>>(std::istream&\
    \ is, MInt& x) {\n    long long v;\n    is >> v;\n    x = MInt(v);\n    return\
    \ is;\n  }\n};\n#else  // ARBITRARY_MODINT\ntemplate <int ID>\nstruct MInt {\n\
    \  unsigned int v;\n\n  MInt() : v(0) {}\n  MInt(const long long x) : v(x >= 0\
    \ ? x % mod() : x % mod() + mod()) {}\n\n  static int get_mod() { return mod();\
    \ }\n  static void set_mod(const int divisor) { mod() = divisor; }\n\n  static\
    \ void init(const int x) {\n    inv<true>(x);\n    fact(x);\n    fact_inv(x);\n\
    \  }\n\n  template <bool MEMOIZES = false>\n  static MInt inv(const int n) {\n\
    \    // assert(0 <= n && n < mod() && std::gcd(x, mod()) == 1);\n    static std::vector<MInt>\
    \ inverse{0, 1};\n    const int prev = inverse.size();\n    if (n < prev) return\
    \ inverse[n];\n    if constexpr (MEMOIZES) {\n      // \"n!\" and \"M\" must be\
    \ disjoint.\n      inverse.resize(n + 1);\n      for (int i = prev; i <= n; ++i)\
    \ {\n        inverse[i] = -inverse[mod() % i] * (mod() / i);\n      }\n      return\
    \ inverse[n];\n    }\n    int u = 1, v = 0;\n    for (unsigned int a = n, b =\
    \ mod(); b;) {\n      const unsigned int q = a / b;\n      std::swap(a -= q *\
    \ b, b);\n      std::swap(u -= q * v, v);\n    }\n    return u;\n  }\n\n  static\
    \ MInt fact(const int n) {\n    static std::vector<MInt> factorial{1};\n    const\
    \ int prev = factorial.size();\n    if (n >= prev) {\n      factorial.resize(n\
    \ + 1);\n      for (int i = prev; i <= n; ++i) {\n        factorial[i] = factorial[i\
    \ - 1] * i;\n      }\n    }\n    return factorial[n];\n  }\n\n  static MInt fact_inv(const\
    \ int n) {\n    static std::vector<MInt> f_inv{1};\n    const int prev = f_inv.size();\n\
    \    if (n >= prev) {\n      f_inv.resize(n + 1);\n      f_inv[n] = inv(fact(n).v);\n\
    \      for (int i = n; i > prev; --i) {\n        f_inv[i - 1] = f_inv[i] * i;\n\
    \      }\n    }\n    return f_inv[n];\n  }\n\n  static MInt nCk(const int n, const\
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
    \ emthrm\n\n\n#line 12 \"test/math/mobius_mu_focusing_on_divisor.test.cpp\"\n\n\
    int main() {\n  using ModInt = emthrm::MInt<1000000007>;\n  int n, k;\n  std::cin\
    \ >> n >> k;\n  std::map<int, int> mu;\n  ModInt ans = 0;\n  for (int g = 1; g\
    \ <= k; ++g) {\n    ModInt ways = 0;\n    for (int m = k / g; m >= 1; --m) {\n\
    \      if (!mu.contains(m)) {\n        for (const auto& [d, mu_d] : emthrm::mobius_mu_focusing_on_divisor(m))\
    \ {\n          mu[d] = mu_d;\n        }\n      }\n      ways += ModInt(k / (g\
    \ * m)).pow(n) * mu[m];\n    }\n    ans += ways * g;\n  }\n  std::cout << ans\
    \ << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\
    \u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248\n *\n * verification-helper: PROBLEM\
    \ https://atcoder.jp/contests/abc162/tasks/abc162_e\n */\n\n#include <iostream>\n\
    #include <map>\n\n#include \"emthrm/math/mobius_mu_focusing_on_divisor.hpp\"\n\
    #include \"emthrm/math/modint.hpp\"\n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n\
    \  int n, k;\n  std::cin >> n >> k;\n  std::map<int, int> mu;\n  ModInt ans =\
    \ 0;\n  for (int g = 1; g <= k; ++g) {\n    ModInt ways = 0;\n    for (int m =\
    \ k / g; m >= 1; --m) {\n      if (!mu.contains(m)) {\n        for (const auto&\
    \ [d, mu_d] : emthrm::mobius_mu_focusing_on_divisor(m)) {\n          mu[d] = mu_d;\n\
    \        }\n      }\n      ways += ModInt(k / (g * m)).pow(n) * mu[m];\n    }\n\
    \    ans += ways * g;\n  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/mobius_mu_focusing_on_divisor.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/mobius_mu_focusing_on_divisor.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/mobius_mu_focusing_on_divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/mobius_mu_focusing_on_divisor.test.cpp
- /verify/test/math/mobius_mu_focusing_on_divisor.test.cpp.html
title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
  \u95A2\u6570 \u7D04\u6570\u7248"
---