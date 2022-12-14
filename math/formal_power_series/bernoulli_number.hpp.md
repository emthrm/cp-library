---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/faulhaber_by_fps.hpp
    title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\
      \u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/bernoulli_number.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D9\u30EB\u30CC\u30FC\
      \u30A4\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/formal_power_series/bernoulli_number.hpp\"\n#include\
    \ <vector>\n\n#line 2 \"math/formal_power_series/formal_power_series.hpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <initializer_list>\n\
    #include <iterator>\n#line 8 \"math/formal_power_series/formal_power_series.hpp\"\
    \n\ntemplate <typename T>\nstruct FormalPowerSeries {\n  std::vector<T> coef;\n\
    \n  explicit FormalPowerSeries(const int deg = 0) : coef(deg + 1, 0) {}\n  explicit\
    \ FormalPowerSeries(const std::vector<T>& coef) : coef(coef) {}\n  FormalPowerSeries(const\
    \ std::initializer_list<T> init)\n      : coef(init.begin(), init.end()) {}\n\
    \  template <typename InputIter>\n  explicit FormalPowerSeries(const InputIter\
    \ first, const InputIter last)\n      : coef(first, last) {}\n\n  inline const\
    \ T& operator[](const int term) const { return coef[term]; }\n  inline T& operator[](const\
    \ int term) { return coef[term]; }\n\n  using Mult = std::function<std::vector<T>(const\
    \ std::vector<T>&,\n                                            const std::vector<T>&)>;\n\
    \  using Sqrt = std::function<bool(const T&, T*)>;\n  static void set_mult(const\
    \ Mult mult) { get_mult() = mult; }\n  static void set_sqrt(const Sqrt sqrt) {\
    \ get_sqrt() = sqrt; }\n\n  void resize(const int deg) { coef.resize(deg + 1,\
    \ 0); }\n  void shrink() {\n    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();\n\
    \  }\n  int degree() const { return static_cast<int>(coef.size()) - 1; }\n\n \
    \ FormalPowerSeries& operator=(const std::vector<T>& coef_) {\n    coef = coef_;\n\
    \    return *this;\n  }\n  FormalPowerSeries& operator=(const FormalPowerSeries&\
    \ x) = default;\n\n  FormalPowerSeries& operator+=(const FormalPowerSeries& x)\
    \ {\n    const int deg_x = x.degree();\n    if (deg_x > degree()) resize(deg_x);\n\
    \    for (int i = 0; i <= deg_x; ++i) {\n      coef[i] += x[i];\n    }\n    return\
    \ *this;\n  }\n  FormalPowerSeries& operator-=(const FormalPowerSeries& x) {\n\
    \    const int deg_x = x.degree();\n    if (deg_x > degree()) resize(deg_x);\n\
    \    for (int i = 0; i <= deg_x; ++i) {\n      coef[i] -= x[i];\n    }\n    return\
    \ *this;\n  }\n  FormalPowerSeries& operator*=(const T x) {\n    for (T& e : coef)\
    \ e *= x;\n    return *this;\n  }\n  FormalPowerSeries& operator*=(const FormalPowerSeries&\
    \ x) {\n    return *this = get_mult()(coef, x.coef);\n  }\n  FormalPowerSeries&\
    \ operator/=(const T x) {\n    assert(x != 0);\n    return *this *= static_cast<T>(1)\
    \ / x;\n  }\n  FormalPowerSeries& operator/=(const FormalPowerSeries& x) {\n \
    \   const int n = degree() - x.degree() + 1;\n    if (n <= 0) return *this = FormalPowerSeries();\n\
    \    const std::vector<T> tmp = get_mult()(\n        std::vector<T>(coef.rbegin(),\
    \ std::next(coef.rbegin(), n)),\n        FormalPowerSeries(\n            x.coef.rbegin(),\n\
    \            std::next(x.coef.rbegin(), std::min(x.degree() + 1, n)))\n      \
    \  .inv(n - 1).coef);\n    return *this = FormalPowerSeries(std::prev(tmp.rend(),\
    \ n), tmp.rend());\n  }\n  FormalPowerSeries& operator%=(const FormalPowerSeries&\
    \ x) {\n    if (x.degree() == 0) return *this = FormalPowerSeries{0};\n    *this\
    \ -= *this / x * x;\n    resize(x.degree() - 1);\n    return *this;\n  }\n  FormalPowerSeries&\
    \ operator<<=(const int n) {\n    coef.insert(coef.begin(), n, 0);\n    return\
    \ *this;\n  }\n  FormalPowerSeries& operator>>=(const int n) {\n    if (degree()\
    \ < n) return *this = FormalPowerSeries();\n    coef.erase(coef.begin(), coef.begin()\
    \ + n);\n    return *this;\n  }\n\n  bool operator==(FormalPowerSeries x) const\
    \ {\n    x.shrink();\n    FormalPowerSeries y = *this;\n    y.shrink();\n    return\
    \ x.coef == y.coef;\n  }\n  bool operator!=(const FormalPowerSeries& x) const\
    \ { return !(*this == x); }\n\n  FormalPowerSeries operator+() const { return\
    \ *this; }\n  FormalPowerSeries operator-() const {\n    FormalPowerSeries res\
    \ = *this;\n    for (T& e : res.coef) e = -e;\n    return res;\n  }\n\n  FormalPowerSeries\
    \ operator+(const FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this)\
    \ += x;\n  }\n  FormalPowerSeries operator-(const FormalPowerSeries& x) const\
    \ {\n    return FormalPowerSeries(*this) -= x;\n  }\n  FormalPowerSeries operator*(const\
    \ T x) const {\n    return FormalPowerSeries(*this) *= x;\n  }\n  FormalPowerSeries\
    \ operator*(const FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this)\
    \ *= x;\n  }\n  FormalPowerSeries operator/(const T x) const {\n    return FormalPowerSeries(*this)\
    \ /= x;\n  }\n  FormalPowerSeries operator/(const FormalPowerSeries& x) const\
    \ {\n    return FormalPowerSeries(*this) /= x;\n  }\n  FormalPowerSeries operator%(const\
    \ FormalPowerSeries& x) const {\n    return FormalPowerSeries(*this) %= x;\n \
    \ }\n  FormalPowerSeries operator<<(const int n) const {\n    return FormalPowerSeries(*this)\
    \ <<= n;\n  }\n  FormalPowerSeries operator>>(const int n) const {\n    return\
    \ FormalPowerSeries(*this) >>= n;\n  }\n\n  T horner(const T x) const {\n    T\
    \ res = 0;\n    for (int i = degree(); i >= 0; --i) {\n      res = res * x + coef[i];\n\
    \    }\n    return res;\n  }\n\n  FormalPowerSeries differential() const {\n \
    \   const int deg = degree();\n    assert(deg >= 0);\n    FormalPowerSeries res(std::max(deg\
    \ - 1, 0));\n    for (int i = 1; i <= deg; ++i) {\n      res[i - 1] = coef[i]\
    \ * i;\n    }\n    return res;\n  }\n\n  FormalPowerSeries exp(int deg = -1) const\
    \ {\n    assert(coef[0] == 0);\n    const int n = coef.size();\n    if (deg ==\
    \ -1) deg = n - 1;\n    const FormalPowerSeries one{1};\n    FormalPowerSeries\
    \ res = one;\n    for (int i = 1; i <= deg; i <<= 1) {\n      res *= FormalPowerSeries(coef.begin(),\n\
    \                               std::next(coef.begin(), std::min(n, i << 1)))\n\
    \             - res.log((i << 1) - 1) + one;\n      res.coef.resize(i << 1);\n\
    \    }\n    res.resize(deg);\n    return res;\n  }\n\n  FormalPowerSeries inv(int\
    \ deg = -1) const {\n    assert(coef[0] != 0);\n    const int n = coef.size();\n\
    \    if (deg == -1) deg = n - 1;\n    FormalPowerSeries res{static_cast<T>(1)\
    \ / coef[0]};\n    for (int i = 1; i <= deg; i <<= 1) {\n      res = res + res\
    \ - res * res * FormalPowerSeries(\n          coef.begin(), std::next(coef.begin(),\
    \ std::min(n, i << 1)));\n      res.coef.resize(i << 1);\n    }\n    res.resize(deg);\n\
    \    return res;\n  }\n\n  FormalPowerSeries log(int deg = -1) const {\n    assert(coef[0]\
    \ == 1);\n    if (deg == -1) deg = degree();\n    FormalPowerSeries integrand\
    \ = differential() * inv(deg - 1);\n    integrand.resize(deg);\n    for (int i\
    \ = deg; i > 0; --i) {\n      integrand[i] = integrand[i - 1] / i;\n    }\n  \
    \  integrand[0] = 0;\n    return integrand;\n  }\n\n  FormalPowerSeries pow(long\
    \ long exponent, int deg = -1) const {\n    const int n = coef.size();\n    if\
    \ (deg == -1) deg = n - 1;\n    if (exponent == 0) {\n      FormalPowerSeries\
    \ res(deg);\n      if (deg != -1) res[0] = 1;\n      return res;\n    }\n    assert(deg\
    \ >= 0);\n    for (int i = 0; i < n; ++i) {\n      if (coef[i] == 0) continue;\n\
    \      if (i > deg / exponent) break;\n      const long long shift = exponent\
    \ * i;\n      T tmp = 1, base = coef[i];\n      for (long long e = exponent; e\
    \ > 0; e >>= 1) {\n        if (e & 1) tmp *= base;\n        base *= base;\n  \
    \    }\n      const FormalPowerSeries res = ((*this >> i) / coef[i]).log(deg -\
    \ shift);\n      return ((res * exponent).exp(deg - shift) * tmp) << shift;\n\
    \    }\n    return FormalPowerSeries(deg);\n  }\n\n  FormalPowerSeries mod_pow(long\
    \ long exponent,\n                            const FormalPowerSeries& md) const\
    \ {\n    const int deg = md.degree() - 1;\n    if (deg < 0) return FormalPowerSeries(-1);\n\
    \    const FormalPowerSeries inv_rev_md =\n        FormalPowerSeries(md.coef.rbegin(),\
    \ md.coef.rend()).inv();\n    const auto mod_mult = [&md, &inv_rev_md, deg](\n\
    \        FormalPowerSeries* multiplicand, const FormalPowerSeries& multiplier)\n\
    \        -> void {\n      *multiplicand *= multiplier;\n      if (deg < multiplicand->degree())\
    \ {\n        const int n = multiplicand->degree() - deg;\n        const FormalPowerSeries\
    \ quotient =\n            FormalPowerSeries(multiplicand->coef.rbegin(),\n   \
    \                           std::next(multiplicand->coef.rbegin(), n))\n     \
    \       * FormalPowerSeries(\n                  inv_rev_md.coef.begin(),\n   \
    \               std::next(inv_rev_md.coef.begin(), std::min(deg + 2, n)));\n \
    \       *multiplicand -=\n            FormalPowerSeries(std::prev(quotient.coef.rend(),\
    \ n),\n                              quotient.coef.rend()) * md;\n        multiplicand->resize(deg);\n\
    \      }\n      multiplicand->shrink();\n    };\n    FormalPowerSeries res{1},\
    \ base = *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) mod_mult(&res, base);\n      mod_mult(&base, base);\n    }\n    return\
    \ res;\n  }\n\n  FormalPowerSeries sqrt(int deg = -1) const {\n    const int n\
    \ = coef.size();\n    if (deg == -1) deg = n - 1;\n    if (coef[0] == 0) {\n \
    \     for (int i = 1; i < n; ++i) {\n        if (coef[i] == 0) continue;\n   \
    \     if (i & 1) return FormalPowerSeries(-1);\n        const int shift = i >>\
    \ 1;\n        if (deg < shift) break;\n        FormalPowerSeries res = (*this\
    \ >> i).sqrt(deg - shift);\n        if (res.coef.empty()) return FormalPowerSeries(-1);\n\
    \        res <<= shift;\n        res.resize(deg);\n        return res;\n     \
    \ }\n      return FormalPowerSeries(deg);\n    }\n    T s;\n    if (!get_sqrt()(coef.front(),\
    \ &s)) return FormalPowerSeries(-1);\n    FormalPowerSeries res{s};\n    const\
    \ T half = static_cast<T>(1) / 2;\n    for (int i = 1; i <= deg; i <<= 1) {\n\
    \      res = (FormalPowerSeries(coef.begin(),\n                              \
    \ std::next(coef.begin(), std::min(n, i << 1)))\n             * res.inv((i <<\
    \ 1) - 1) + res) * half;\n    }\n    res.resize(deg);\n    return res;\n  }\n\n\
    \  FormalPowerSeries translate(const T c) const {\n    const int n = coef.size();\n\
    \    std::vector<T> fact(n, 1), inv_fact(n, 1);\n    for (int i = 1; i < n; ++i)\
    \ {\n      fact[i] = fact[i - 1] * i;\n    }\n    inv_fact[n - 1] = static_cast<T>(1)\
    \ / fact[n - 1];\n    for (int i = n - 1; i > 0; --i) {\n      inv_fact[i - 1]\
    \ = inv_fact[i] * i;\n    }\n    std::vector<T> g(n), ex(n);\n    for (int i =\
    \ 0; i < n; ++i) {\n      g[i] = coef[i] * fact[i];\n    }\n    std::reverse(g.begin(),\
    \ g.end());\n    T pow_c = 1;\n    for (int i = 0; i < n; ++i) {\n      ex[i]\
    \ = pow_c * inv_fact[i];\n      pow_c *= c;\n    }\n    const std::vector<T> conv\
    \ = get_mult()(g, ex);\n    FormalPowerSeries res(n - 1);\n    for (int i = 0;\
    \ i < n; ++i) {\n      res[i] = conv[n - 1 - i] * inv_fact[i];\n    }\n    return\
    \ res;\n  }\n\n private:\n  static Mult& get_mult() {\n    static Mult mult =\
    \ [](const std::vector<T>& a, const std::vector<T>& b)\n        -> std::vector<T>\
    \ {\n      const int n = a.size(), m = b.size();\n      std::vector<T> res(n +\
    \ m - 1, 0);\n      for (int i = 0; i < n; ++i) {\n        for (int j = 0; j <\
    \ m; ++j) {\n          res[i + j] += a[i] * b[j];\n        }\n      }\n      return\
    \ res;\n    };\n    return mult;\n  }\n  static Sqrt& get_sqrt() {\n    static\
    \ Sqrt sqrt = [](const T& a, T* res) -> bool { return false; };\n    return sqrt;\n\
    \  }\n};\n#line 5 \"math/formal_power_series/bernoulli_number.hpp\"\n\ntemplate\
    \ <typename T>\nstd::vector<T> bernoulli_number(const int n) {\n  FormalPowerSeries<T>\
    \ bernoulli(n);\n  bernoulli[0] = 1;\n  for (int i = 1; i <= n; ++i) {\n    bernoulli[i]\
    \ = bernoulli[i - 1] / (i + 1);\n  }\n  bernoulli = bernoulli.inv(n);\n  T fact\
    \ = 1;\n  for (int i = 0; i <= n; ++i) {\n    bernoulli[i] *= fact;\n    fact\
    \ *= i + 1;\n  }\n  return bernoulli.coef;\n}\n"
  code: "#pragma once\n#include <vector>\n\n#include \"./formal_power_series.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<T> bernoulli_number(const int n) {\n  FormalPowerSeries<T>\
    \ bernoulli(n);\n  bernoulli[0] = 1;\n  for (int i = 1; i <= n; ++i) {\n    bernoulli[i]\
    \ = bernoulli[i - 1] / (i + 1);\n  }\n  bernoulli = bernoulli.inv(n);\n  T fact\
    \ = 1;\n  for (int i = 0; i <= n; ++i) {\n    bernoulli[i] *= fact;\n    fact\
    \ *= i + 1;\n  }\n  return bernoulli.coef;\n}\n"
  dependsOn:
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: math/formal_power_series/bernoulli_number.hpp
  requiredBy:
  - math/formal_power_series/faulhaber_by_fps.hpp
  timestamp: '2022-08-08 06:04:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/bernoulli_number.test.cpp
  - test/math/formal_power_series/faulhaber_by_fps.test.cpp
documentation_of: math/formal_power_series/bernoulli_number.hpp
layout: document
title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
---

$$
  \dfrac{x}{e^x - 1} = \sum_{n = 0}^{\infty} B_n \frac{x^n}{n!}
$$

で定義される $B_n$ である．

$$
  \begin{cases}
    B_0 = 1, \\
    B_n = -\dfrac{1}{n + 1} \sum_{k = 0}^{n - 1} \binom{n + 1}{k} B_k
  \end{cases}
$$

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
