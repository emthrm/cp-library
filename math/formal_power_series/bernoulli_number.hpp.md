---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/formal_power_series/faulhaber_by_fps.hpp
    title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\
      \u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/formal_power_series/bernoulli_number.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D9\u30EB\u30CC\u30FC\
      \u30A4\u6570"
  - icon: ':x:'
    path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/formal_power_series/bernoulli_number.hpp\"\n#include\
    \ <vector>\r\n\r\n#line 2 \"math/formal_power_series/formal_power_series.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <functional>\r\n#include\
    \ <initializer_list>\r\n#include <iterator>\r\n#line 8 \"math/formal_power_series/formal_power_series.hpp\"\
    \n\r\ntemplate <typename T>\r\nstruct FormalPowerSeries {\r\n  std::vector<T>\
    \ coef;\r\n\r\n  explicit FormalPowerSeries(const int deg = 0) : coef(deg + 1,\
    \ 0) {}\r\n  explicit FormalPowerSeries(const std::vector<T>& coef) : coef(coef)\
    \ {}\r\n  FormalPowerSeries(const std::initializer_list<T> init)\r\n      : coef(init.begin(),\
    \ init.end()) {}\r\n  template <typename InputIter>\r\n  explicit FormalPowerSeries(const\
    \ InputIter first, const InputIter last)\r\n      : coef(first, last) {}\r\n\r\
    \n  inline const T& operator[](const int term) const { return coef[term]; }\r\n\
    \  inline T& operator[](const int term) { return coef[term]; }\r\n\r\n  using\
    \ MULT = std::function<std::vector<T>(const std::vector<T>&,\r\n             \
    \                               const std::vector<T>&)>;\r\n  using SQRT = std::function<bool(const\
    \ T&, T*)>;\r\n  static void set_mult(const MULT mult) { get_mult() = mult; }\r\
    \n  static void set_sqrt(const SQRT sqrt) { get_sqrt() = sqrt; }\r\n\r\n  void\
    \ resize(const int deg) { coef.resize(deg + 1, 0); }\r\n  void shrink() {\r\n\
    \    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();\r\n  }\r\n \
    \ int degree() const { return static_cast<int>(coef.size()) - 1; }\r\n\r\n  FormalPowerSeries&\
    \ operator=(const std::vector<T>& coef_) {\r\n    coef = coef_;\r\n    return\
    \ *this;\r\n  }\r\n  FormalPowerSeries& operator=(const FormalPowerSeries& x)\
    \ = default;\r\n\r\n  FormalPowerSeries& operator+=(const FormalPowerSeries& x)\
    \ {\r\n    const int deg_x = x.degree();\r\n    if (deg_x > degree()) resize(deg_x);\r\
    \n    for (int i = 0; i <= deg_x; ++i) {\r\n      coef[i] += x[i];\r\n    }\r\n\
    \    return *this;\r\n  }\r\n  FormalPowerSeries& operator-=(const FormalPowerSeries&\
    \ x) {\r\n    const int deg_x = x.degree();\r\n    if (deg_x > degree()) resize(deg_x);\r\
    \n    for (int i = 0; i <= deg_x; ++i) {\r\n      coef[i] -= x[i];\r\n    }\r\n\
    \    return *this;\r\n  }\r\n  FormalPowerSeries& operator*=(const T x) {\r\n\
    \    for (T& e : coef) e *= x;\r\n    return *this;\r\n  }\r\n  FormalPowerSeries&\
    \ operator*=(const FormalPowerSeries& x) {\r\n    return *this = get_mult()(coef,\
    \ x.coef);\r\n  }\r\n  FormalPowerSeries& operator/=(const T x) {\r\n    assert(x\
    \ != 0);\r\n    return *this *= static_cast<T>(1) / x;\r\n  }\r\n  FormalPowerSeries&\
    \ operator/=(const FormalPowerSeries& x) {\r\n    const int n = degree() - x.degree()\
    \ + 1;\r\n    if (n <= 0) return *this = FormalPowerSeries();\r\n    const std::vector<T>\
    \ tmp = get_mult()(\r\n        std::vector<T>(coef.rbegin(), std::next(coef.rbegin(),\
    \ n)),\r\n        FormalPowerSeries(\r\n            x.coef.rbegin(),\r\n     \
    \       std::next(x.coef.rbegin(), std::min(x.degree() + 1, n)))\r\n        .inv(n\
    \ - 1).coef);\r\n    return *this = FormalPowerSeries(std::prev(tmp.rend(), n),\
    \ tmp.rend());\r\n  }\r\n  FormalPowerSeries& operator%=(const FormalPowerSeries&\
    \ x) {\r\n    if (x.degree() == 0) return *this = FormalPowerSeries{0};\r\n  \
    \  *this -= *this / x * x;\r\n    resize(x.degree() - 1);\r\n    return *this;\r\
    \n  }\r\n  FormalPowerSeries& operator<<=(const int n) {\r\n    coef.insert(coef.begin(),\
    \ n, 0);\r\n    return *this;\r\n  }\r\n  FormalPowerSeries& operator>>=(const\
    \ int n) {\r\n    if (degree() < n) return *this = FormalPowerSeries();\r\n  \
    \  coef.erase(coef.begin(), coef.begin() + n);\r\n    return *this;\r\n  }\r\n\
    \r\n  bool operator==(FormalPowerSeries x) const {\r\n    x.shrink();\r\n    FormalPowerSeries\
    \ y = *this;\r\n    y.shrink();\r\n    return x.coef == y.coef;\r\n  }\r\n  bool\
    \ operator!=(const FormalPowerSeries& x) const { return !(*this == x); }\r\n\r\
    \n  FormalPowerSeries operator+() const { return *this; }\r\n  FormalPowerSeries\
    \ operator-() const {\r\n    FormalPowerSeries res = *this;\r\n    for (T& e :\
    \ res.coef) e = -e;\r\n    return res;\r\n  }\r\n\r\n  FormalPowerSeries operator+(const\
    \ FormalPowerSeries& x) const {\r\n    return FormalPowerSeries(*this) += x;\r\
    \n  }\r\n  FormalPowerSeries operator-(const FormalPowerSeries& x) const {\r\n\
    \    return FormalPowerSeries(*this) -= x;\r\n  }\r\n  FormalPowerSeries operator*(const\
    \ T x) const {\r\n    return FormalPowerSeries(*this) *= x;\r\n  }\r\n  FormalPowerSeries\
    \ operator*(const FormalPowerSeries& x) const {\r\n    return FormalPowerSeries(*this)\
    \ *= x;\r\n  }\r\n  FormalPowerSeries operator/(const T x) const {\r\n    return\
    \ FormalPowerSeries(*this) /= x;\r\n  }\r\n  FormalPowerSeries operator/(const\
    \ FormalPowerSeries& x) const {\r\n    return FormalPowerSeries(*this) /= x;\r\
    \n  }\r\n  FormalPowerSeries operator%(const FormalPowerSeries& x) const {\r\n\
    \    return FormalPowerSeries(*this) %= x;\r\n  }\r\n  FormalPowerSeries operator<<(const\
    \ int n) const {\r\n    return FormalPowerSeries(*this) <<= n;\r\n  }\r\n  FormalPowerSeries\
    \ operator>>(const int n) const {\r\n    return FormalPowerSeries(*this) >>= n;\r\
    \n  }\r\n\r\n  T horner(const T x) const {\r\n    T res = 0;\r\n    for (int i\
    \ = degree(); i >= 0; --i) {\r\n      res = res * x + coef[i];\r\n    }\r\n  \
    \  return res;\r\n  }\r\n\r\n  FormalPowerSeries differential() const {\r\n  \
    \  const int deg = degree();\r\n    assert(deg >= 0);\r\n    FormalPowerSeries\
    \ res(std::max(deg - 1, 0));\r\n    for (int i = 1; i <= deg; ++i) {\r\n     \
    \ res[i - 1] = coef[i] * i;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  FormalPowerSeries\
    \ exp(int deg = -1) const {\r\n    assert(coef[0] == 0);\r\n    const int n =\
    \ coef.size();\r\n    if (deg == -1) deg = n - 1;\r\n    const FormalPowerSeries\
    \ one{1};\r\n    FormalPowerSeries res = one;\r\n    for (int i = 1; i <= deg;\
    \ i <<= 1) {\r\n      res *= FormalPowerSeries(coef.begin(),\r\n             \
    \                  std::next(coef.begin(), std::min(n, i << 1)))\r\n         \
    \    - res.log((i << 1) - 1) + one;\r\n      res.coef.resize(i << 1);\r\n    }\r\
    \n    res.resize(deg);\r\n    return res;\r\n  }\r\n\r\n  FormalPowerSeries inv(int\
    \ deg = -1) const {\r\n    assert(coef[0] != 0);\r\n    const int n = coef.size();\r\
    \n    if (deg == -1) deg = n - 1;\r\n    FormalPowerSeries res{static_cast<T>(1)\
    \ / coef[0]};\r\n    for (int i = 1; i <= deg; i <<= 1) {\r\n      res = res +\
    \ res - res * res * FormalPowerSeries(\r\n          coef.begin(), std::next(coef.begin(),\
    \ std::min(n, i << 1)));\r\n      res.coef.resize(i << 1);\r\n    }\r\n    res.resize(deg);\r\
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
    \ FormalPowerSeries res = ((*this >> i) / coef[i]).log(deg - shift);\r\n     \
    \ return ((res * exponent).exp(deg - shift) * tmp) << shift;\r\n    }\r\n    return\
    \ FormalPowerSeries(deg);\r\n  }\r\n\r\n  FormalPowerSeries mod_pow(long long\
    \ exponent,\r\n                            const FormalPowerSeries& md) const\
    \ {\r\n    const int deg = md.degree() - 1;\r\n    if (deg < 0) return FormalPowerSeries(-1);\r\
    \n    const FormalPowerSeries inv_rev_md =\r\n        FormalPowerSeries(md.coef.rbegin(),\
    \ md.coef.rend()).inv();\r\n    const auto mod_mult = [&md, &inv_rev_md, deg](\r\
    \n        FormalPowerSeries* multiplicand, const FormalPowerSeries& multiplier)\r\
    \n        -> void {\r\n      *multiplicand *= multiplier;\r\n      if (deg < multiplicand->degree())\
    \ {\r\n        const int n = multiplicand->degree() - deg;\r\n        const FormalPowerSeries\
    \ quotient =\r\n            FormalPowerSeries(multiplicand->coef.rbegin(),\r\n\
    \                              std::next(multiplicand->coef.rbegin(), n))\r\n\
    \            * FormalPowerSeries(\r\n                  inv_rev_md.coef.begin(),\r\
    \n                  std::next(inv_rev_md.coef.begin(), std::min(deg + 2, n)));\r\
    \n        *multiplicand -=\r\n            FormalPowerSeries(std::prev(quotient.coef.rend(),\
    \ n),\r\n                              quotient.coef.rend()) * md;\r\n       \
    \ multiplicand->resize(deg);\r\n      }\r\n      multiplicand->shrink();\r\n \
    \   };\r\n    FormalPowerSeries res{1}, base = *this;\r\n    for (; exponent >\
    \ 0; exponent >>= 1) {\r\n      if (exponent & 1) mod_mult(&res, base);\r\n  \
    \    mod_mult(&base, base);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  FormalPowerSeries\
    \ sqrt(int deg = -1) const {\r\n    const int n = coef.size();\r\n    if (deg\
    \ == -1) deg = n - 1;\r\n    if (coef[0] == 0) {\r\n      for (int i = 1; i <\
    \ n; ++i) {\r\n        if (coef[i] == 0) continue;\r\n        if (i & 1) return\
    \ FormalPowerSeries(-1);\r\n        const int shift = i >> 1;\r\n        if (deg\
    \ < shift) break;\r\n        FormalPowerSeries res = (*this >> i).sqrt(deg - shift);\r\
    \n        if (res.coef.empty()) return FormalPowerSeries(-1);\r\n        res <<=\
    \ shift;\r\n        res.resize(deg);\r\n        return res;\r\n      }\r\n   \
    \   return FormalPowerSeries(deg);\r\n    }\r\n    T s;\r\n    if (!get_sqrt()(coef.front(),\
    \ &s)) return FormalPowerSeries(-1);\r\n    FormalPowerSeries res{s};\r\n    const\
    \ T half = static_cast<T>(1) / 2;\r\n    for (int i = 1; i <= deg; i <<= 1) {\r\
    \n      res = (FormalPowerSeries(coef.begin(),\r\n                           \
    \    std::next(coef.begin(), std::min(n, i << 1)))\r\n             * res.inv((i\
    \ << 1) - 1) + res) * half;\r\n    }\r\n    res.resize(deg);\r\n    return res;\r\
    \n  }\r\n\r\n  FormalPowerSeries translate(const T c) const {\r\n    const int\
    \ n = coef.size();\r\n    std::vector<T> fact(n, 1), inv_fact(n, 1);\r\n    for\
    \ (int i = 1; i < n; ++i) {\r\n      fact[i] = fact[i - 1] * i;\r\n    }\r\n \
    \   inv_fact[n - 1] = static_cast<T>(1) / fact[n - 1];\r\n    for (int i = n -\
    \ 1; i > 0; --i) {\r\n      inv_fact[i - 1] = inv_fact[i] * i;\r\n    }\r\n  \
    \  std::vector<T> g(n), ex(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      g[i]\
    \ = coef[i] * fact[i];\r\n    }\r\n    std::reverse(g.begin(), g.end());\r\n \
    \   T pow_c = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      ex[i] = pow_c *\
    \ inv_fact[i];\r\n      pow_c *= c;\r\n    }\r\n    const std::vector<T> conv\
    \ = get_mult()(g, ex);\r\n    FormalPowerSeries res(n - 1);\r\n    for (int i\
    \ = 0; i < n; ++i) {\r\n      res[i] = conv[n - 1 - i] * inv_fact[i];\r\n    }\r\
    \n    return res;\r\n  }\r\n\r\n private:\r\n  static MULT& get_mult() {\r\n \
    \   static MULT mult = [](const std::vector<T>& a, const std::vector<T>& b)\r\n\
    \        -> std::vector<T> {\r\n      const int n = a.size(), m = b.size();\r\n\
    \      std::vector<T> res(n + m - 1, 0);\r\n      for (int i = 0; i < n; ++i)\
    \ {\r\n        for (int j = 0; j < m; ++j) {\r\n          res[i + j] += a[i] *\
    \ b[j];\r\n        }\r\n      }\r\n      return res;\r\n    };\r\n    return mult;\r\
    \n  }\r\n  static SQRT& get_sqrt() {\r\n    static SQRT sqrt = [](const T& a,\
    \ T* res) -> bool { return false; };\r\n    return sqrt;\r\n  }\r\n};\r\n#line\
    \ 5 \"math/formal_power_series/bernoulli_number.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<T> bernoulli_number(const int n) {\r\n  FormalPowerSeries<T>\
    \ bernoulli(n);\r\n  bernoulli[0] = 1;\r\n  for (int i = 1; i <= n; ++i) {\r\n\
    \    bernoulli[i] = bernoulli[i - 1] / (i + 1);\r\n  }\r\n  bernoulli = bernoulli.inv(n);\r\
    \n  T fact = 1;\r\n  for (int i = 0; i <= n; ++i) {\r\n    bernoulli[i] *= fact;\r\
    \n    fact *= i + 1;\r\n  }\r\n  return bernoulli.coef;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\n#include \"formal_power_series.hpp\"\
    \r\n\r\ntemplate <typename T>\r\nstd::vector<T> bernoulli_number(const int n)\
    \ {\r\n  FormalPowerSeries<T> bernoulli(n);\r\n  bernoulli[0] = 1;\r\n  for (int\
    \ i = 1; i <= n; ++i) {\r\n    bernoulli[i] = bernoulli[i - 1] / (i + 1);\r\n\
    \  }\r\n  bernoulli = bernoulli.inv(n);\r\n  T fact = 1;\r\n  for (int i = 0;\
    \ i <= n; ++i) {\r\n    bernoulli[i] *= fact;\r\n    fact *= i + 1;\r\n  }\r\n\
    \  return bernoulli.coef;\r\n}\r\n"
  dependsOn:
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: math/formal_power_series/bernoulli_number.hpp
  requiredBy:
  - math/formal_power_series/faulhaber_by_fps.hpp
  timestamp: '2022-02-17 13:43:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/formal_power_series/bernoulli_number.test.cpp
  - test/math/formal_power_series/faulhaber_by_fps.test.cpp
documentation_of: math/formal_power_series/bernoulli_number.hpp
layout: document
title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
---

$$\dfrac{x}{e^x - 1} = \sum_{n = 0}^{\infty} B_n \frac{x^n}{n!}$$

で定義される $B_n$ である．

$$\begin{cases} B_0 = 1 \text{，} \\ B_n = -\dfrac{1}{n + 1} \sum_{k = 0}^{n - 1} \binom{n + 1}{k} B_k \end{cases}$$

という漸化式をもつ．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`bernoulli_number<T>(n)`|ベルヌーイ数 $B_i$ ($0 \leq i \leq n$) の数表|


## 参考

- https://ja.wikipedia.org/wiki/%E3%83%99%E3%83%AB%E3%83%8C%E3%83%BC%E3%82%A4%E6%95%B0


## Verified

https://judge.yosupo.jp/submission/3792
