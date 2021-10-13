---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/subset_sum_problem.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/subset_sum_problem.hpp\"\n#include <vector>\r\
    \n#line 2 \"math/formal_power_series/formal_power_series.hpp\"\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <functional>\r\n#include <initializer_list>\r\
    \n#line 7 \"math/formal_power_series/formal_power_series.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nstruct FormalPowerSeries {\r\n  std::vector<T> coef;\r\n\r\n  explicit\
    \ FormalPowerSeries(const int deg = 0) : coef(deg + 1, 0) {}\r\n  explicit FormalPowerSeries(const\
    \ std::vector<T>& coef) : coef(coef) {}\r\n  FormalPowerSeries(std::initializer_list<T>\
    \ init) : coef(init.begin(), init.end()) {}\r\n  template <typename InputIter>\r\
    \n  explicit FormalPowerSeries(InputIter first, InputIter last) : coef(first,\
    \ last) {}\r\n\r\n  inline const T &operator[](const int term) const { return\
    \ coef[term]; }\r\n  inline T &operator[](const int term) { return coef[term];\
    \ }\r\n\r\n  using MUL = std::function<std::vector<T>(const std::vector<T>&, const\
    \ std::vector<T>&)>;\r\n  using SQR = std::function<bool(const T&, T&)>;\r\n \
    \ static void set_mul(const MUL mul) { get_mul() = mul; }\r\n  static void set_sqr(const\
    \ SQR sqr) { get_sqr() = sqr; }\r\n\r\n  void resize(const int deg) { coef.resize(deg\
    \ + 1, 0); }\r\n  void shrink() {\r\n    while (coef.size() > 1 && coef.back()\
    \ == 0) coef.pop_back();\r\n  }\r\n  int degree() const { return static_cast<int>(coef.size())\
    \ - 1; }\r\n\r\n  FormalPowerSeries& operator=(const std::vector<T>& coef_) {\r\
    \n    coef = coef_;\r\n    return *this;\r\n  }\r\n  FormalPowerSeries& operator=(const\
    \ FormalPowerSeries& x) = default;\r\n\r\n  FormalPowerSeries& operator+=(const\
    \ FormalPowerSeries& x) {\r\n    const int deg_x = x.degree();\r\n    if (deg_x\
    \ > degree()) resize(deg_x);\r\n    for (int i = 0; i <= deg_x; ++i) {\r\n   \
    \   coef[i] += x[i];\r\n    }\r\n    return *this;\r\n  }\r\n  FormalPowerSeries&\
    \ operator-=(const FormalPowerSeries& x) {\r\n    const int deg_x = x.degree();\r\
    \n    if (deg_x > degree()) resize(deg_x);\r\n    for (int i = 0; i <= deg_x;\
    \ ++i) {\r\n      coef[i] -= x[i];\r\n    }\r\n    return *this;\r\n  }\r\n  FormalPowerSeries&\
    \ operator*=(const T x) {\r\n    for (T& e : coef) e *= x;\r\n    return *this;\r\
    \n  }\r\n  FormalPowerSeries& operator*=(const FormalPowerSeries& x) {\r\n   \
    \ return *this = get_mul()(coef, x.coef);\r\n  }\r\n  FormalPowerSeries& operator/=(const\
    \ T x) {\r\n    assert(x != 0);\r\n    const T inv_x = static_cast<T>(1) / x;\r\
    \n    for (T& e : coef) e *= inv_x;\r\n    return *this;\r\n  }\r\n  FormalPowerSeries&\
    \ operator/=(const FormalPowerSeries& x) {\r\n    const int x_size = x.coef.size();\r\
    \n    if (x_size > coef.size()) return *this = FormalPowerSeries();\r\n    const\
    \ int n = coef.size() - x_size + 1;\r\n    FormalPowerSeries tmp = FormalPowerSeries(x.coef.rbegin(),\
    \ x.coef.rbegin() + std::min(x_size, n)).inv(n - 1);\r\n    tmp = FormalPowerSeries(coef.rbegin(),\
    \ coef.rbegin() + n) * tmp;\r\n    return *this = FormalPowerSeries(tmp.coef.rend()\
    \ - n, tmp.coef.rend());\r\n  }\r\n  FormalPowerSeries& operator%=(const FormalPowerSeries&\
    \ x) {\r\n    if (x.degree() == 0) return *this = FormalPowerSeries{0};\r\n  \
    \  *this -= *this / x * x;\r\n    resize(x.degree() - 1);\r\n    return *this;\r\
    \n  }\r\n  FormalPowerSeries& operator<<=(const int n) {\r\n    coef.insert(coef.begin(),\
    \ n, 0);\r\n    return *this;\r\n  }\r\n  FormalPowerSeries& operator>>=(const\
    \ int n) {\r\n    if (degree() < n) return *this = FormalPowerSeries();\r\n  \
    \  coef.erase(coef.begin(), coef.begin() + n);\r\n    return *this;\r\n  }\r\n\
    \r\n  bool operator==(const FormalPowerSeries& x) const {\r\n    FormalPowerSeries\
    \ a(*this), b(x);\r\n    a.shrink();\r\n    b.shrink();\r\n    const int deg =\
    \ a.degree();\r\n    if (deg != b.degree()) return false;\r\n    for (int i =\
    \ 0; i <= deg; ++i) {\r\n      if (a[i] != b[i]) return false;\r\n    }\r\n  \
    \  return true;\r\n  }\r\n  bool operator!=(const FormalPowerSeries& x) const\
    \ { return !(*this == x); }\r\n\r\n  FormalPowerSeries operator+() const { return\
    \ *this; }\r\n  FormalPowerSeries operator-() const {\r\n    FormalPowerSeries\
    \ res(*this);\r\n    for (T& e : res.coef) e = -e;\r\n    return res;\r\n  }\r\
    \n\r\n  FormalPowerSeries operator+(const FormalPowerSeries& x) const { return\
    \ FormalPowerSeries(*this) += x; }\r\n  FormalPowerSeries operator-(const FormalPowerSeries&\
    \ x) const { return FormalPowerSeries(*this) -= x; }\r\n  FormalPowerSeries operator*(const\
    \ T x) const { return FormalPowerSeries(*this) *= x; }\r\n  FormalPowerSeries\
    \ operator*(const FormalPowerSeries& x) const { return FormalPowerSeries(*this)\
    \ *= x; }\r\n  FormalPowerSeries operator/(const T x) const { return FormalPowerSeries(*this)\
    \ /= x; }\r\n  FormalPowerSeries operator/(const FormalPowerSeries& x) const {\
    \ return FormalPowerSeries(*this) /= x; }\r\n  FormalPowerSeries operator%(const\
    \ FormalPowerSeries& x) const { return FormalPowerSeries(*this) %= x; }\r\n  FormalPowerSeries\
    \ operator<<(const int n) const { return FormalPowerSeries(*this) <<= n; }\r\n\
    \  FormalPowerSeries operator>>(const int n) const { return FormalPowerSeries(*this)\
    \ >>= n; }\r\n\r\n  T horner(const T x) const {\r\n    T res = 0;\r\n    for (int\
    \ i = degree(); i >= 0; --i) {\r\n      res = res * x + coef[i];\r\n    }\r\n\
    \    return res;\r\n  }\r\n\r\n  FormalPowerSeries differential() const {\r\n\
    \    const int deg = degree();\r\n    assert(deg >= 0);\r\n    FormalPowerSeries\
    \ res(std::max(deg - 1, 0));\r\n    for (int i = 1; i <= deg; ++i) {\r\n     \
    \ res[i - 1] = coef[i] * i;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  FormalPowerSeries\
    \ exp(int deg = -1) const {\r\n    assert(coef[0] == 0);\r\n    const int n =\
    \ coef.size();\r\n    if (deg == -1) deg = n - 1;\r\n    const FormalPowerSeries\
    \ one{1};\r\n    FormalPowerSeries res(one);\r\n    for (int i = 1; i <= deg;\
    \ i <<= 1) {\r\n      res *= FormalPowerSeries(coef.begin(), coef.begin() + std::min(n,\
    \ i << 1)) - res.log((i << 1) - 1) + one;\r\n      res.coef.resize(i << 1);\r\n\
    \    }\r\n    res.resize(deg);\r\n    return res;\r\n  }\r\n\r\n  FormalPowerSeries\
    \ inv(int deg = -1) const {\r\n    assert(coef[0] != 0);\r\n    const int n =\
    \ coef.size();\r\n    if (deg == -1) deg = n - 1;\r\n    FormalPowerSeries res{static_cast<T>(1)\
    \ / coef[0]};\r\n    for (int i = 1; i <= deg; i <<= 1) {\r\n      res = res +\
    \ res - res * res * FormalPowerSeries(coef.begin(), coef.begin() + std::min(n,\
    \ i << 1));\r\n      res.coef.resize(i << 1);\r\n    }\r\n    res.resize(deg);\r\
    \n    return res;\r\n  }\r\n\r\n  FormalPowerSeries log(int deg = -1) const {\r\
    \n    assert(coef[0] == 1);\r\n    if (deg == -1) deg = degree();\r\n    FormalPowerSeries\
    \ integrand = differential() * inv(deg - 1);\r\n    integrand.resize(deg);\r\n\
    \    for (int i = deg; i > 0; --i) {\r\n      integrand[i] = integrand[i - 1]\
    \ / i;\r\n    }\r\n    integrand[0] = 0;\r\n    return integrand;\r\n  }\r\n\r\
    \n  FormalPowerSeries pow(long long exponent, int deg = -1) const {\r\n    const\
    \ int n = coef.size();\r\n    if (deg == -1) deg = n - 1;\r\n    for (int i =\
    \ 0; i < n; ++i) {\r\n      if (coef[i] == 0) continue;\r\n      const long long\
    \ shift = exponent * i;\r\n      if (shift > deg) break;\r\n      T tmp = 1, base\
    \ = coef[i];\r\n      for (long long e = exponent; e > 0; e >>= 1) {\r\n     \
    \   if (e & 1) tmp *= base;\r\n        base *= base;\r\n      }\r\n      const\
    \ FormalPowerSeries res = ((*this >> i) * (static_cast<T>(1) / coef[i])).log(deg\
    \ - shift);\r\n      return ((res * static_cast<T>(exponent)).exp(deg - shift)\
    \ * tmp) << shift;\r\n    }\r\n    return FormalPowerSeries(deg);\r\n  }\r\n\r\
    \n  FormalPowerSeries mod_pow(long long exponent, const FormalPowerSeries& md)\
    \ const {\r\n    const FormalPowerSeries inv_rev_md = FormalPowerSeries(md.coef.rbegin(),\
    \ md.coef.rend()).inv();\r\n    const int inv_rev_md_size = inv_rev_md.coef.size(),\
    \ md_size = md.coef.size();\r\n    auto mod_mul = [&md, &inv_rev_md, inv_rev_md_size,\
    \ md_size](\r\n        FormalPowerSeries& multiplicand,\r\n        const FormalPowerSeries&\
    \ multiplier) -> void {\r\n      multiplicand *= multiplier;\r\n      if (md_size\
    \ <= multiplicand.coef.size()) {\r\n        const int n = multiplicand.coef.size()\
    \ - md_size + 1;\r\n        const FormalPowerSeries quotient =\r\n           \
    \ FormalPowerSeries(multiplicand.coef.rbegin(), multiplicand.coef.rbegin() + n)\
    \ *\r\n            FormalPowerSeries(inv_rev_md.coef.begin(), inv_rev_md.coef.begin()\
    \ + std::min(inv_rev_md_size, n));\r\n        multiplicand -= FormalPowerSeries(quotient.coef.rend()\
    \ - n, quotient.coef.rend()) * md;\r\n      }\r\n      multiplicand.coef.resize(md_size\
    \ - 1);\r\n      if (multiplicand.coef.empty()) multiplicand.coef = {0};\r\n \
    \   };\r\n    FormalPowerSeries res{1}, base = *this;\r\n    mod_mul(base, res);\r\
    \n    for (; exponent > 0; exponent >>= 1) {\r\n      if (exponent & 1) mod_mul(res,\
    \ base);\r\n      mod_mul(base, base);\r\n    }\r\n    return res;\r\n  }\r\n\r\
    \n  FormalPowerSeries sqrt(int deg = -1) const {\r\n    const int n = coef.size();\r\
    \n    if (deg == -1) deg = n - 1;\r\n    if (coef[0] == 0) {\r\n      for (int\
    \ i = 1; i < n; ++i) {\r\n        if (coef[i] == 0) continue;\r\n        if (i\
    \ & 1) return FormalPowerSeries(-1);\r\n        const int shift = i >> 1;\r\n\
    \        if (deg < shift) break;\r\n        FormalPowerSeries res = (*this >>\
    \ i).sqrt(deg - shift);\r\n        if (res.coef.empty()) return FormalPowerSeries(-1);\r\
    \n        res <<= shift;\r\n        res.resize(deg);\r\n        return res;\r\n\
    \      }\r\n      return FormalPowerSeries(deg);\r\n    }\r\n    T s;\r\n    if\
    \ (!get_sqr()(coef[0], s)) return FormalPowerSeries(-1);\r\n    FormalPowerSeries\
    \ res{s};\r\n    const T half = static_cast<T>(1) / 2;\r\n    for (int i = 1;\
    \ i <= deg; i <<= 1) {\r\n      res += FormalPowerSeries(coef.begin(), coef.begin()\
    \ + std::min(n, i << 1)) * res.inv((i << 1) - 1);\r\n      res *= half;\r\n  \
    \  }\r\n    res.resize(deg);\r\n    return res;\r\n  }\r\n\r\n  FormalPowerSeries\
    \ translate(T c) const {\r\n    const int n = coef.size();\r\n    std::vector<T>\
    \ fact(n, 1), inv_fact(n, 1);\r\n    for (int i = 1; i < n; ++i) {\r\n      fact[i]\
    \ = fact[i - 1] * i;\r\n    }\r\n    inv_fact[n - 1] = static_cast<T>(1) / fact[n\
    \ - 1];\r\n    for (int i = n - 1; i > 0; --i) {\r\n      inv_fact[i - 1] = inv_fact[i]\
    \ * i;\r\n    }\r\n    std::vector<T> g(n), ex(n);\r\n    for (int i = 0; i <\
    \ n; ++i) {\r\n      g[n - 1 - i] = coef[i] * fact[i];\r\n    }\r\n    T pow_c\
    \ = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      ex[i] = pow_c * inv_fact[i];\r\
    \n      pow_c *= c;\r\n    }\r\n    const std::vector<T> conv = get_mul()(g, ex);\r\
    \n    FormalPowerSeries res(n - 1);\r\n    for (int i = 0; i < n; ++i) {\r\n \
    \     res[i] = conv[n - 1 - i] * inv_fact[i];\r\n    }\r\n    return res;\r\n\
    \  }\r\n\r\nprivate:\r\n  static MUL& get_mul() {\r\n    static MUL mul = [](const\
    \ std::vector<T>& a, const std::vector<T>& b) -> std::vector<T> {\r\n      const\
    \ int n = a.size(), m = b.size();\r\n      std::vector<T> res(n + m - 1, 0);\r\
    \n      for (int i = 0; i < n; ++i) {\r\n        for (int j = 0; j < m; ++j) {\r\
    \n          res[i + j] += a[i] * b[j];\r\n        }\r\n      }\r\n      return\
    \ res;\r\n    };\r\n    return mul;\r\n  }\r\n  static SQR& get_sqr() {\r\n  \
    \  static SQR sqr = [](const T& a, T& res) -> bool { return false; };\r\n    return\
    \ sqr;\r\n  }\r\n};\r\n#line 4 \"dynamic_programming/subset_sum_problem.hpp\"\n\
    \r\ntemplate <typename T>\r\nstd::vector<T> subset_sum_problem(const std::vector<int>&\
    \ a, const int d) {\r\n  T zero = 1;\r\n  std::vector<int> cnt(d + 1, 0);\r\n\
    \  for (const int e : a) {\r\n    if (e == 0) {\r\n      zero *= 2;\r\n    } else\
    \ if (e <= d) {\r\n      ++cnt[e];\r\n    }\r\n  }\r\n  FormalPowerSeries<T> fps(d);\r\
    \n  for (int i = 1; i <= d; ++i) {\r\n    for (int j = 1; i * j <= d; ++j) {\r\
    \n      fps[i * j] += static_cast<T>(cnt[i]) / j * (j & 1 ? 1 : -1);\r\n    }\r\
    \n  }\r\n  return (fps.exp(d) * zero).coef;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"../math/formal_power_series/formal_power_series.hpp\"\
    \r\n\r\ntemplate <typename T>\r\nstd::vector<T> subset_sum_problem(const std::vector<int>&\
    \ a, const int d) {\r\n  T zero = 1;\r\n  std::vector<int> cnt(d + 1, 0);\r\n\
    \  for (const int e : a) {\r\n    if (e == 0) {\r\n      zero *= 2;\r\n    } else\
    \ if (e <= d) {\r\n      ++cnt[e];\r\n    }\r\n  }\r\n  FormalPowerSeries<T> fps(d);\r\
    \n  for (int i = 1; i <= d; ++i) {\r\n    for (int j = 1; i * j <= d; ++j) {\r\
    \n      fps[i * j] += static_cast<T>(cnt[i]) / j * (j & 1 ? 1 : -1);\r\n    }\r\
    \n  }\r\n  return (fps.exp(d) * zero).coef;\r\n}\r\n"
  dependsOn:
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: dynamic_programming/subset_sum_problem.hpp
  requiredBy: []
  timestamp: '2021-10-13 18:06:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/subset_sum_problem.test.cpp
documentation_of: dynamic_programming/subset_sum_problem.hpp
layout: document
title: "\u90E8\u5206\u548C\u554F\u984C (subset sum problem)"
---

$n$ 個の数の選び方の内，要素の和が特定の数となるものの存在性を判定する問題である．

ナップサック問題の部分問題である．

[形式的冪級数](../math/formal_power_series/formal_power_series.md)を用いて場合の数を求められる．


## 時間計算量

$O(N + D\log{D})$


## 使用法

||説明|条件|
|:--:|:--:|:--:|
|`subset_sum_problem(a, d)`|集合内の要素の和が $d \ (0 \leq d \leq D)$ となる $A$ の部分集合の個数|$A_i \geq 0$|


## 参考

- https://yukicoder.me/wiki/polynomial_techniques


## Verified

https://judge.yosupo.jp/submission/6908
