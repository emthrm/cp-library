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
    \ T>\r\nstruct FormalPowerSeries {\r\n  using MUL = std::function<std::vector<T>(const\
    \ std::vector<T>&, const std::vector<T>&)>;\r\n  using SQR = std::function<bool(const\
    \ T&, T&)>;\r\n  std::vector<T> co;\r\n  FormalPowerSeries(int deg = 0) : co(deg\
    \ + 1, 0) {}\r\n  FormalPowerSeries(const std::vector<T> &co) : co(co) {}\r\n\
    \  FormalPowerSeries(std::initializer_list<T> init) : co(init.begin(), init.end())\
    \ {}\r\n  template <typename InputIter> FormalPowerSeries(InputIter first, InputIter\
    \ last) : co(first, last) {}\r\n  inline const T &operator[](int term) const {\
    \ return co[term]; }\r\n  inline T &operator[](int term) { return co[term]; }\r\
    \n  static void set_mul(MUL mul) { get_mul() = mul; }\r\n  static void set_sqr(SQR\
    \ sqr) { get_sqr() = sqr; }\r\n  void resize(int deg) { co.resize(deg + 1, 0);\
    \ }\r\n  void shrink() { while (co.size() > 1 && co.back() == 0) co.pop_back();\
    \ }\r\n  int degree() const { return static_cast<int>(co.size()) - 1; }\r\n  FormalPowerSeries\
    \ &operator=(const std::vector<T> &new_co) {\r\n    co.resize(new_co.size());\r\
    \n    std::copy(new_co.begin(), new_co.end(), co.begin());\r\n    return *this;\r\
    \n  }\r\n  FormalPowerSeries &operator=(const FormalPowerSeries &x) {\r\n    co.resize(x.co.size());\r\
    \n    std::copy(x.co.begin(), x.co.end(), co.begin());\r\n    return *this;\r\n\
    \  }\r\n  FormalPowerSeries &operator+=(const FormalPowerSeries &x) {\r\n    int\
    \ n = x.co.size();\r\n    if (n > co.size()) resize(n - 1);\r\n    for (int i\
    \ = 0; i < n; ++i) co[i] += x.co[i];\r\n    return *this;\r\n  }\r\n  FormalPowerSeries\
    \ &operator-=(const FormalPowerSeries &x) {\r\n    int n = x.co.size();\r\n  \
    \  if (n > co.size()) resize(n - 1);\r\n    for (int i = 0; i < n; ++i) co[i]\
    \ -= x.co[i];\r\n    return *this;\r\n  }\r\n  FormalPowerSeries &operator*=(T\
    \ x) {\r\n    for (T &e : co) e *= x;\r\n    return *this;\r\n  }\r\n  FormalPowerSeries\
    \ &operator*=(const FormalPowerSeries &x) { return *this = get_mul()(co, x.co);\
    \ }\r\n  FormalPowerSeries &operator/=(T x) {\r\n    assert(x != 0);\r\n    T\
    \ inv_x = static_cast<T>(1) / x;\r\n    for (T &e : co) e *= inv_x;\r\n    return\
    \ *this;\r\n  }\r\n  FormalPowerSeries &operator/=(const FormalPowerSeries &x)\
    \ {\r\n    int sz = x.co.size();\r\n    if (sz > co.size()) return *this = FormalPowerSeries();\r\
    \n    int n = co.size() - sz + 1;\r\n    FormalPowerSeries a(co.rbegin(), co.rbegin()\
    \ + n), b(x.co.rbegin(), x.co.rbegin() + std::min(sz, n));\r\n    b = b.inv(n\
    \ - 1);\r\n    a *= b;\r\n    return *this = FormalPowerSeries(a.co.rend() - n,\
    \ a.co.rend());\r\n  }\r\n  FormalPowerSeries &operator%=(const FormalPowerSeries\
    \ &x) {\r\n    *this -= *this / x * x;\r\n    co.resize(static_cast<int>(x.co.size())\
    \ - 1);\r\n    if (co.empty()) co = {0};\r\n    return *this;\r\n  }\r\n  FormalPowerSeries\
    \ &operator<<=(int n) {\r\n    co.insert(co.begin(), n, 0);\r\n    return *this;\r\
    \n  }\r\n  FormalPowerSeries &operator>>=(int n) {\r\n    if (co.size() < n) return\
    \ *this = FormalPowerSeries();\r\n    co.erase(co.begin(), co.begin() + n);\r\n\
    \    return *this;\r\n  }\r\n  bool operator==(const FormalPowerSeries &x) const\
    \ {\r\n    FormalPowerSeries a(*this), b(x);\r\n    a.shrink(); b.shrink();\r\n\
    \    int n = a.co.size();\r\n    if (n != b.co.size()) return false;\r\n    for\
    \ (int i = 0; i < n; ++i) if (a.co[i] != b.co[i]) return false;\r\n    return\
    \ true;\r\n  }\r\n  bool operator!=(const FormalPowerSeries &x) const { return\
    \ !(*this == x); }\r\n  FormalPowerSeries operator+() const { return *this; }\r\
    \n  FormalPowerSeries operator-() const {\r\n    FormalPowerSeries res(*this);\r\
    \n    for (T &e : res.co) e = -e;\r\n    return res;\r\n  }\r\n  FormalPowerSeries\
    \ operator+(const FormalPowerSeries &x) const { return FormalPowerSeries(*this)\
    \ += x; }\r\n  FormalPowerSeries operator-(const FormalPowerSeries &x) const {\
    \ return FormalPowerSeries(*this) -= x; }\r\n  FormalPowerSeries operator*(T x)\
    \ const { return FormalPowerSeries(*this) *= x; }\r\n  FormalPowerSeries operator*(const\
    \ FormalPowerSeries &x) const { return FormalPowerSeries(*this) *= x; }\r\n  FormalPowerSeries\
    \ operator/(T x) const { return FormalPowerSeries(*this) /= x; }\r\n  FormalPowerSeries\
    \ operator/(const FormalPowerSeries &x) const { return FormalPowerSeries(*this)\
    \ /= x; }\r\n  FormalPowerSeries operator%(const FormalPowerSeries &x) const {\
    \ return FormalPowerSeries(*this) %= x; }\r\n  FormalPowerSeries operator<<(int\
    \ n) const { return FormalPowerSeries(*this) <<= n; }\r\n  FormalPowerSeries operator>>(int\
    \ n) const { return FormalPowerSeries(*this) >>= n; }\r\n  T horner(T x) const\
    \ {\r\n    T res = 0;\r\n    for (int i = static_cast<int>(co.size()) - 1; i >=\
    \ 0; --i) (res *= x) += co[i];\r\n    return res;\r\n  }\r\n  FormalPowerSeries\
    \ differential() const {\r\n    int n = co.size();\r\n    assert(n >= 1);\r\n\
    \    FormalPowerSeries res(n - 1);\r\n    for (int i = 1; i < n; ++i) res.co[i\
    \ - 1] = co[i] * i;\r\n    return res;\r\n  }\r\n  FormalPowerSeries integral()\
    \ const {\r\n    int n = co.size();\r\n    FormalPowerSeries res(n + 1);\r\n \
    \   for (int i = 0; i < n; ++i) res[i + 1] = co[i] / (i + 1);\r\n    return res;\r\
    \n  }\r\n  FormalPowerSeries exp(int deg = -1) const {\r\n    assert(co[0] ==\
    \ 0);\r\n    int n = co.size();\r\n    if (deg == -1) deg = n - 1;\r\n    FormalPowerSeries\
    \ one{1}, res = one;\r\n    for (int i = 1; i <= deg; i <<= 1) {\r\n      res\
    \ *= FormalPowerSeries(co.begin(), co.begin() + std::min(n, i << 1)) - res.log((i\
    \ << 1) - 1) + one;\r\n      res.co.resize(i << 1);\r\n    }\r\n    res.co.resize(deg\
    \ + 1);\r\n    return res;\r\n  }\r\n  FormalPowerSeries inv(int deg = -1) const\
    \ {\r\n    assert(co[0] != 0);\r\n    int n = co.size();\r\n    if (deg == -1)\
    \ deg = n - 1;\r\n    FormalPowerSeries res{static_cast<T>(1) / co[0]};\r\n  \
    \  for (int i = 1; i <= deg; i <<= 1) {\r\n      res = res + res - res * res *\
    \ FormalPowerSeries(co.begin(), co.begin() + std::min(n, i << 1));\r\n      res.co.resize(i\
    \ << 1);\r\n    }\r\n    res.co.resize(deg + 1);\r\n    return res;\r\n  }\r\n\
    \  FormalPowerSeries log(int deg = -1) const {\r\n    assert(co[0] == 1);\r\n\
    \    if (deg == -1) deg = static_cast<int>(co.size()) - 1;\r\n    FormalPowerSeries\
    \ integrand = differential() * inv(deg - 1);\r\n    integrand.co.resize(deg);\r\
    \n    return integrand.integral();\r\n  }\r\n  FormalPowerSeries pow(long long\
    \ exponent, int deg = -1) const {\r\n    int n = co.size();\r\n    if (deg ==\
    \ -1) deg = n - 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (co[i] !=\
    \ 0) {\r\n        long long shift = exponent * i;\r\n        if (shift > deg)\
    \ break;\r\n        T tmp = 1, base = co[i];\r\n        long long e = exponent;\r\
    \n        while (e > 0) {\r\n          if (e & 1) tmp *= base;\r\n          base\
    \ *= base;\r\n          e >>= 1;\r\n        }\r\n        return ((((*this >> i)\
    \ * (static_cast<T>(1) / co[i])).log(deg - shift)\r\n                * static_cast<T>(exponent)).exp(deg\
    \ - shift) * tmp)\r\n               << shift;\r\n      }\r\n    }\r\n    return\
    \ FormalPowerSeries(deg);\r\n  }\r\n  FormalPowerSeries mod_pow(long long exponent,\
    \ const FormalPowerSeries &md) const {\r\n    FormalPowerSeries inv_rev_md = FormalPowerSeries(md.co.rbegin(),\
    \ md.co.rend()).inv();\r\n    int deg_of_md = md.co.size();\r\n    auto mod_mul\
    \ = [&](FormalPowerSeries &multiplicand, const FormalPowerSeries &multiplier)\
    \ -> void {\r\n      multiplicand *= multiplier;\r\n      if (deg_of_md <= multiplicand.co.size())\
    \ {\r\n        int n = multiplicand.co.size() - deg_of_md + 1;\r\n        FormalPowerSeries\
    \ quotient =\r\n          FormalPowerSeries(multiplicand.co.rbegin(), multiplicand.co.rbegin()\
    \ + n)\r\n          * FormalPowerSeries(inv_rev_md.co.begin(), inv_rev_md.co.begin()\
    \ + std::min(static_cast<int>(inv_rev_md.co.size()), n));\r\n        multiplicand\
    \ -= FormalPowerSeries(quotient.co.rend() - n, quotient.co.rend()) * md;\r\n \
    \     }\r\n      multiplicand.co.resize(deg_of_md - 1);\r\n      if (multiplicand.co.empty())\
    \ multiplicand.co = {0};\r\n    };\r\n    FormalPowerSeries res{1}, base = *this;\r\
    \n    mod_mul(base, res);\r\n    while (exponent > 0) {\r\n      if (exponent\
    \ & 1) mod_mul(res, base);\r\n      mod_mul(base, base);\r\n      exponent >>=\
    \ 1;\r\n    }\r\n    return res;\r\n  }\r\n  FormalPowerSeries sqrt(int deg =\
    \ -1) const {\r\n    int n = co.size();\r\n    if (deg == -1) deg = n - 1;\r\n\
    \    if (co[0] == 0) {\r\n      for (int i = 1; i < n; ++i) {\r\n        if (co[i]\
    \ == 0) continue;\r\n        if (i & 1) return FormalPowerSeries(-1);\r\n    \
    \    int shift = i >> 1;\r\n        if (deg < shift) break;\r\n        FormalPowerSeries\
    \ res = (*this >> i).sqrt(deg - shift);\r\n        if (res.co.empty()) return\
    \ FormalPowerSeries(-1);\r\n        res <<= shift;\r\n        res.resize(deg);\r\
    \n        return res;\r\n      }\r\n      return FormalPowerSeries(deg);\r\n \
    \   }\r\n    T s;\r\n    if (!get_sqr()(co[0], s)) return FormalPowerSeries(-1);\r\
    \n    FormalPowerSeries res{s};\r\n    T half = static_cast<T>(1) / 2;\r\n   \
    \ for (int i = 1; i <= deg; i <<= 1) {\r\n      (res += FormalPowerSeries(co.begin(),\
    \ co.begin() + std::min(n, i << 1)) * res.inv((i << 1) - 1)) *= half;\r\n    }\r\
    \n    res.resize(deg);\r\n    return res;\r\n  }\r\n  FormalPowerSeries translate(T\
    \ c) const {\r\n    int n = co.size();\r\n    std::vector<T> fact(n, 1), inv_fact(n,\
    \ 1);\r\n    for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;\r\n    inv_fact[n\
    \ - 1] = static_cast<T>(1) / fact[n - 1];\r\n    for (int i = n - 1; i > 0; --i)\
    \ inv_fact[i - 1] = inv_fact[i] * i;\r\n    std::vector<T> g(n), ex(n);\r\n  \
    \  for (int i = 0; i < n; ++i) g[n - 1 - i] = co[i] * fact[i];\r\n    T pow_c\
    \ = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      ex[i] = pow_c * inv_fact[i];\r\
    \n      pow_c *= c;\r\n    }\r\n    std::vector<T> conv = get_mul()(g, ex);\r\n\
    \    FormalPowerSeries res(n - 1);\r\n    for (int i = 0; i < n; ++i) res[i] =\
    \ conv[n - 1 - i] * inv_fact[i];\r\n    return res;\r\n  }\r\nprivate:\r\n  static\
    \ MUL &get_mul() {\r\n    static MUL mul = [](const std::vector<T> &a, const std::vector<T>\
    \ &b) -> std::vector<T> {\r\n      int n = a.size(), m = b.size();\r\n      std::vector<T>\
    \ res(n + m - 1, 0);\r\n      for (int i = 0; i < n; ++i) for (int j = 0; j <\
    \ m; ++j) res[i + j] += a[i] * b[j];\r\n      return res;\r\n    };\r\n    return\
    \ mul;\r\n  }\r\n  static SQR &get_sqr() {\r\n    static SQR sqr = [](const T\
    \ &a, T &res) -> bool { return false; };\r\n    return sqr;\r\n  }\r\n};\r\n#line\
    \ 4 \"dynamic_programming/subset_sum_problem.hpp\"\n\r\ntemplate <typename T>\r\
    \nstd::vector<T> subset_sum_problem(const std::vector<int> &a, int d) {\r\n  T\
    \ zero = 1;\r\n  std::vector<int> cnt(d + 1, 0);\r\n  for (int e : a) {\r\n  \
    \  if (e == 0) {\r\n      zero *= 2;\r\n    } else if (e <= d) {\r\n      ++cnt[e];\r\
    \n    }\r\n  }\r\n  FormalPowerSeries<T> fps(d);\r\n  for (int i = 1; i <= d;\
    \ ++i) for (int j = 1; i * j <= d; ++j) {\r\n    fps[i * j] += static_cast<T>(cnt[i])\
    \ / j * (j & 1 ? 1 : -1);\r\n  }\r\n  return (fps.exp(d) * zero).co;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"../math/formal_power_series/formal_power_series.hpp\"\
    \r\n\r\ntemplate <typename T>\r\nstd::vector<T> subset_sum_problem(const std::vector<int>\
    \ &a, int d) {\r\n  T zero = 1;\r\n  std::vector<int> cnt(d + 1, 0);\r\n  for\
    \ (int e : a) {\r\n    if (e == 0) {\r\n      zero *= 2;\r\n    } else if (e <=\
    \ d) {\r\n      ++cnt[e];\r\n    }\r\n  }\r\n  FormalPowerSeries<T> fps(d);\r\n\
    \  for (int i = 1; i <= d; ++i) for (int j = 1; i * j <= d; ++j) {\r\n    fps[i\
    \ * j] += static_cast<T>(cnt[i]) / j * (j & 1 ? 1 : -1);\r\n  }\r\n  return (fps.exp(d)\
    \ * zero).co;\r\n}\r\n"
  dependsOn:
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: dynamic_programming/subset_sum_problem.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/subset_sum_problem.test.cpp
documentation_of: dynamic_programming/subset_sum_problem.hpp
layout: document
title: "\u90E8\u5206\u548C\u554F\u984C (subset sum problem)"
---

$n$ 個の数の選び方の内，要素の和が特定の数となるものの存在性を判定する問題である．

ナップサック問題の部分問題である．

[形式的冪級数](../math/formal_power_series/formal_power_series.md)を用いて場合の数を求めることができる．


## 時間計算量

$O(N + D\log{D})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`subset_sum_problem(a, d)`|集合内の要素の和が $0 \leq i \leq D$ となる $A$ の部分集合の個数|$A_i \geq 0$ でなければならない．|


## 参考

- https://yukicoder.me/wiki/polynomial_techniques


## Verified

https://judge.yosupo.jp/submission/6908
