---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
    title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217 (linear recurrence sequence) \u306E\
      \u7B2C $N$ \u9805"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/bostan-mori.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013Mori \u306E\
      \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/formal_power_series/bostan-mori.hpp\"\
    \n\n\n\n#include <cassert>\n\n#line 1 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\n\n\n#include <algorithm>\n#line 6 \"include/emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n#include <functional>\n#include <initializer_list>\n#include <iterator>\n#include\
    \ <numeric>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    struct FormalPowerSeries {\n  std::vector<T> coef;\n\n  explicit FormalPowerSeries(const\
    \ int deg = 0) : coef(deg + 1, 0) {}\n  explicit FormalPowerSeries(const std::vector<T>&\
    \ coef) : coef(coef) {}\n  FormalPowerSeries(const std::initializer_list<T> init)\n\
    \      : coef(init.begin(), init.end()) {}\n  template <typename InputIter>\n\
    \  explicit FormalPowerSeries(const InputIter first, const InputIter last)\n \
    \     : coef(first, last) {}\n\n  inline const T& operator[](const int term) const\
    \ { return coef[term]; }\n  inline T& operator[](const int term) { return coef[term];\
    \ }\n\n  using Mult = std::function<std::vector<T>(const std::vector<T>&,\n  \
    \                                          const std::vector<T>&)>;\n  using Sqrt\
    \ = std::function<bool(const T&, T*)>;\n  static void set_mult(const Mult mult)\
    \ { get_mult() = mult; }\n  static void set_sqrt(const Sqrt sqrt) { get_sqrt()\
    \ = sqrt; }\n\n  void resize(const int deg) { coef.resize(deg + 1, 0); }\n  void\
    \ shrink() {\n    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();\n\
    \  }\n  int degree() const { return std::ssize(coef) - 1; }\n\n  FormalPowerSeries&\
    \ operator=(const std::vector<T>& coef_) {\n    coef = coef_;\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator=(const FormalPowerSeries& x) = default;\n\n\
    \  FormalPowerSeries& operator+=(const FormalPowerSeries& x) {\n    const int\
    \ deg_x = x.degree();\n    if (deg_x > degree()) resize(deg_x);\n    for (int\
    \ i = 0; i <= deg_x; ++i) {\n      coef[i] += x[i];\n    }\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator-=(const FormalPowerSeries& x) {\n    const\
    \ int deg_x = x.degree();\n    if (deg_x > degree()) resize(deg_x);\n    for (int\
    \ i = 0; i <= deg_x; ++i) {\n      coef[i] -= x[i];\n    }\n    return *this;\n\
    \  }\n  FormalPowerSeries& operator*=(const T x) {\n    for (T& e : coef) e *=\
    \ x;\n    return *this;\n  }\n  FormalPowerSeries& operator*=(const FormalPowerSeries&\
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
    \ x.coef == y.coef;\n  }\n\n  FormalPowerSeries operator+() const { return *this;\
    \ }\n  FormalPowerSeries operator-() const {\n    FormalPowerSeries res = *this;\n\
    \    for (T& e : res.coef) e = -e;\n    return res;\n  }\n\n  FormalPowerSeries\
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
    \ FormalPowerSeries(*this) >>= n;\n  }\n\n  T horner(const T x) const {\n    return\
    \ std::accumulate(\n        coef.rbegin(), coef.rend(), static_cast<T>(0),\n \
    \       [x](const T l, const T r) -> T { return l * x + r; });\n  }\n\n  FormalPowerSeries\
    \ differential() const {\n    const int deg = degree();\n    assert(deg >= 0);\n\
    \    FormalPowerSeries res(std::max(deg - 1, 0));\n    for (int i = 1; i <= deg;\
    \ ++i) {\n      res[i - 1] = coef[i] * i;\n    }\n    return res;\n  }\n\n  FormalPowerSeries\
    \ exp(const int deg) const {\n    assert(coef[0] == 0);\n    const int n = coef.size();\n\
    \    const FormalPowerSeries one{1};\n    FormalPowerSeries res = one;\n    for\
    \ (int i = 1; i <= deg; i <<= 1) {\n      res *= FormalPowerSeries(coef.begin(),\n\
    \                               std::next(coef.begin(), std::min(n, i << 1)))\n\
    \             - res.log((i << 1) - 1) + one;\n      res.coef.resize(i << 1);\n\
    \    }\n    res.resize(deg);\n    return res;\n  }\n  FormalPowerSeries exp()\
    \ const { return exp(degree()); }\n\n  FormalPowerSeries inv(const int deg) const\
    \ {\n    assert(coef[0] != 0);\n    const int n = coef.size();\n    FormalPowerSeries\
    \ res{static_cast<T>(1) / coef[0]};\n    for (int i = 1; i <= deg; i <<= 1) {\n\
    \      res = res + res - res * res * FormalPowerSeries(\n          coef.begin(),\
    \ std::next(coef.begin(), std::min(n, i << 1)));\n      res.coef.resize(i << 1);\n\
    \    }\n    res.resize(deg);\n    return res;\n  }\n  FormalPowerSeries inv()\
    \ const { return inv(degree()); }\n\n  FormalPowerSeries log(const int deg) const\
    \ {\n    assert(coef[0] == 1);\n    FormalPowerSeries integrand = differential()\
    \ * inv(deg - 1);\n    integrand.resize(deg);\n    for (int i = deg; i > 0; --i)\
    \ {\n      integrand[i] = integrand[i - 1] / i;\n    }\n    integrand[0] = 0;\n\
    \    return integrand;\n  }\n  FormalPowerSeries log() const { return log(degree());\
    \ }\n\n  FormalPowerSeries pow(long long exponent, const int deg) const {\n  \
    \  const int n = coef.size();\n    if (exponent == 0) {\n      FormalPowerSeries\
    \ res(deg);\n      if (deg != -1) [[unlikely]] res[0] = 1;\n      return res;\n\
    \    }\n    assert(deg >= 0);\n    for (int i = 0; i < n; ++i) {\n      if (coef[i]\
    \ == 0) continue;\n      if (i > deg / exponent) break;\n      const long long\
    \ shift = exponent * i;\n      T tmp = 1, base = coef[i];\n      for (long long\
    \ e = exponent; e > 0; e >>= 1) {\n        if (e & 1) tmp *= base;\n        base\
    \ *= base;\n      }\n      const FormalPowerSeries res = ((*this >> i) / coef[i]).log(deg\
    \ - shift);\n      return ((res * exponent).exp(deg - shift) * tmp) << shift;\n\
    \    }\n    return FormalPowerSeries(deg);\n  }\n  FormalPowerSeries pow(const\
    \ long long exponent) const {\n    return pow(exponent, degree());\n  }\n\n  FormalPowerSeries\
    \ mod_pow(long long exponent,\n                            const FormalPowerSeries&\
    \ md) const {\n    const int deg = md.degree() - 1;\n    if (deg < 0) [[unlikely]]\
    \ return FormalPowerSeries(-1);\n    const FormalPowerSeries inv_rev_md =\n  \
    \      FormalPowerSeries(md.coef.rbegin(), md.coef.rend()).inv();\n    const auto\
    \ mod_mult = [&md, &inv_rev_md, deg](\n        FormalPowerSeries* multiplicand,\
    \ const FormalPowerSeries& multiplier)\n        -> void {\n      *multiplicand\
    \ *= multiplier;\n      if (deg < multiplicand->degree()) {\n        const int\
    \ n = multiplicand->degree() - deg;\n        const FormalPowerSeries quotient\
    \ =\n            FormalPowerSeries(multiplicand->coef.rbegin(),\n            \
    \                  std::next(multiplicand->coef.rbegin(), n))\n            * FormalPowerSeries(\n\
    \                  inv_rev_md.coef.begin(),\n                  std::next(inv_rev_md.coef.begin(),\
    \ std::min(deg + 2, n)));\n        *multiplicand -=\n            FormalPowerSeries(std::prev(quotient.coef.rend(),\
    \ n),\n                              quotient.coef.rend()) * md;\n        multiplicand->resize(deg);\n\
    \      }\n      multiplicand->shrink();\n    };\n    FormalPowerSeries res{1},\
    \ base = *this;\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) mod_mult(&res, base);\n      mod_mult(&base, base);\n    }\n    return\
    \ res;\n  }\n\n  FormalPowerSeries sqrt(const int deg) const {\n    const int\
    \ n = coef.size();\n    if (coef[0] == 0) {\n      for (int i = 1; i < n; ++i)\
    \ {\n        if (coef[i] == 0) continue;\n        if (i & 1) return FormalPowerSeries(-1);\n\
    \        const int shift = i >> 1;\n        if (deg < shift) break;\n        FormalPowerSeries\
    \ res = (*this >> i).sqrt(deg - shift);\n        if (res.coef.empty()) return\
    \ FormalPowerSeries(-1);\n        res <<= shift;\n        res.resize(deg);\n \
    \       return res;\n      }\n      return FormalPowerSeries(deg);\n    }\n  \
    \  T s;\n    if (!get_sqrt()(coef.front(), &s)) return FormalPowerSeries(-1);\n\
    \    FormalPowerSeries res{s};\n    const T half = static_cast<T>(1) / 2;\n  \
    \  for (int i = 1; i <= deg; i <<= 1) {\n      res = (FormalPowerSeries(coef.begin(),\n\
    \                               std::next(coef.begin(), std::min(n, i << 1)))\n\
    \             * res.inv((i << 1) - 1) + res) * half;\n    }\n    res.resize(deg);\n\
    \    return res;\n  }\n  FormalPowerSeries sqrt() const { return sqrt(degree());\
    \ }\n\n  FormalPowerSeries translate(const T c) const {\n    const int n = coef.size();\n\
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
    \ Sqrt sqrt = [](const T&, T*) -> bool { return false; };\n    return sqrt;\n\
    \  }\n};\n\n}  // namespace emthrm\n\n\n#line 7 \"include/emthrm/math/formal_power_series/bostan-mori.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nT bostan_mori(FormalPowerSeries<T>\
    \ p, FormalPowerSeries<T> q, long long n) {\n  q.shrink();\n  const int d = q.degree();\n\
    \  assert(d >= 0 && q[0] != 0);\n  T res = 0;\n  p.shrink();\n  if (p.degree()\
    \ >= d) {\n    const FormalPowerSeries<T> quotient = p / q;\n    p -= quotient\
    \ * q;\n    p.shrink();\n    if (n <= quotient.degree()) res += quotient[n];\n\
    \  }\n  if (d == 0 || (p.degree() == 0 && p[0] == 0)) return res;\n  p.resize(d\
    \ - 1);\n  for (; n > 0; n >>= 1) {\n    FormalPowerSeries<T> tmp = q;\n    for\
    \ (int i = 1; i <= d; i += 2) {\n      tmp[i] = -tmp[i];\n    }\n    p *= tmp;\n\
    \    if (n & 1) {\n      for (int i = 0; i < d; ++i) {\n        p[i] = p[(i <<\
    \ 1) + 1];\n      }\n    } else {\n      for (int i = 1; i < d; ++i) {\n     \
    \   p[i] = p[i << 1];\n      }\n    }\n    p.resize(d - 1);\n    q *= tmp;\n \
    \   for (int i = 1; i <= d; ++i) {\n      q[i] = q[i << 1];\n    }\n    q.resize(d);\n\
    \  }\n  return res + p[0] / q[0];\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n#define EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n\
    \n#include <cassert>\n\n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nT bostan_mori(FormalPowerSeries<T>\
    \ p, FormalPowerSeries<T> q, long long n) {\n  q.shrink();\n  const int d = q.degree();\n\
    \  assert(d >= 0 && q[0] != 0);\n  T res = 0;\n  p.shrink();\n  if (p.degree()\
    \ >= d) {\n    const FormalPowerSeries<T> quotient = p / q;\n    p -= quotient\
    \ * q;\n    p.shrink();\n    if (n <= quotient.degree()) res += quotient[n];\n\
    \  }\n  if (d == 0 || (p.degree() == 0 && p[0] == 0)) return res;\n  p.resize(d\
    \ - 1);\n  for (; n > 0; n >>= 1) {\n    FormalPowerSeries<T> tmp = q;\n    for\
    \ (int i = 1; i <= d; i += 2) {\n      tmp[i] = -tmp[i];\n    }\n    p *= tmp;\n\
    \    if (n & 1) {\n      for (int i = 0; i < d; ++i) {\n        p[i] = p[(i <<\
    \ 1) + 1];\n      }\n    } else {\n      for (int i = 1; i < d; ++i) {\n     \
    \   p[i] = p[i << 1];\n      }\n    }\n    p.resize(d - 1);\n    q *= tmp;\n \
    \   for (int i = 1; i <= d; ++i) {\n      q[i] = q[i << 1];\n    }\n    q.resize(d);\n\
    \  }\n  return res + p[0] / q[0];\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/bostan-mori.hpp
  requiredBy:
  - include/emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
  timestamp: '2023-03-11 17:00:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/bostan-mori.test.cpp
documentation_of: include/emthrm/math/formal_power_series/bostan-mori.hpp
layout: document
title: "Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
---

# Bostan–Mori のアルゴリズム

$d$-階線形回帰数列の第 $N$ 項を求めるアルゴリズムである。


## 時間計算量

$d$ 次多項式同士の乗算の算術計算量を $\mathsf{M}(d)$ とおくと $O(\mathsf{M}(d) \log{N})$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename T>`<br>`T bostan_mori(FormalPowerSeries<T> p, FormalPowerSeries<T> q, long long n);`|${\lbrack x^N \rbrack}\frac{P(x)}{Q(x)}$|${\lbrack x^0 \rbrack}Q = Q(0)$ は可逆元 (invertible element) である。|
|`template <typename T>`<br>`T nth_term_of_linear_recurrence_sequence(FormalPowerSeries<T> a, FormalPowerSeries<T> q, const long long n);`|特性多項式 $Q(x)$ をもち、$A(x) = B(x) \bmod{x^{\mathrm{deg}(A) + 1}}$ を満たす線形回帰数列の母関数 $B(x)$ に対して ${\lbrack x^N \rbrack}B$||


## 参考文献

- http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
- https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
- https://nyaannyaan.github.io/library/fps/kitamasa.hpp
- https://tsuchi.hateblo.jp/entry/2021/10/09/124804


## TODO

- $x^N \bmod \Gamma(x)$
  - https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b


## Submissons

https://judge.yosupo.jp/submission/80098
