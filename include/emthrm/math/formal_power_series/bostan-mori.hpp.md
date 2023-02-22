---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
    title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u7B2C $N$ \u9805"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/bostan-mori.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013Mori \u306E\
      \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/formal_power_series/bostan-mori.md
    document_title: "Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/formal_power_series/bostan-mori.hpp\"\
    \n/**\n * @brief Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n\
    \ * @docs docs/math/formal_power_series/bostan-mori.md\n */\n\n#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n\
    #define EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n\n#include <cassert>\n\
    \nnamespace emthrm {\n\ntemplate <template <typename> class C, typename T>\nT\
    \ bostan_mori(C<T> p, C<T> q, long long n) {\n  q.shrink();\n  const int d = q.degree();\n\
    \  assert(d >= 0 && q[0] != 0);\n  T res = 0;\n  p.shrink();\n  if (p.degree()\
    \ >= d) {\n    const C<T> quotient = p / q;\n    p -= quotient * q;\n    p.shrink();\n\
    \    if (n <= quotient.degree()) res += quotient[n];\n  }\n  if (d == 0 || (p.degree()\
    \ == 0 && p[0] == 0)) return res;\n  p.resize(d - 1);\n  for (; n > 0; n >>= 1)\
    \ {\n    C<T> tmp = q;\n    for (int i = 1; i <= d; i += 2) {\n      tmp[i] =\
    \ -tmp[i];\n    }\n    p *= tmp;\n    if (n & 1) {\n      for (int i = 0; i <\
    \ d; ++i) {\n        p[i] = p[(i << 1) + 1];\n      }\n    } else {\n      for\
    \ (int i = 1; i < d; ++i) {\n        p[i] = p[i << 1];\n      }\n    }\n    p.resize(d\
    \ - 1);\n    q *= tmp;\n    for (int i = 1; i <= d; ++i) {\n      q[i] = q[i <<\
    \ 1];\n    }\n    q.resize(d);\n  }\n  return res + p[0] / q[0];\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n"
  code: "/**\n * @brief Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \n * @docs docs/math/formal_power_series/bostan-mori.md\n */\n\n#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n\
    #define EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n\n#include <cassert>\n\
    \nnamespace emthrm {\n\ntemplate <template <typename> class C, typename T>\nT\
    \ bostan_mori(C<T> p, C<T> q, long long n) {\n  q.shrink();\n  const int d = q.degree();\n\
    \  assert(d >= 0 && q[0] != 0);\n  T res = 0;\n  p.shrink();\n  if (p.degree()\
    \ >= d) {\n    const C<T> quotient = p / q;\n    p -= quotient * q;\n    p.shrink();\n\
    \    if (n <= quotient.degree()) res += quotient[n];\n  }\n  if (d == 0 || (p.degree()\
    \ == 0 && p[0] == 0)) return res;\n  p.resize(d - 1);\n  for (; n > 0; n >>= 1)\
    \ {\n    C<T> tmp = q;\n    for (int i = 1; i <= d; i += 2) {\n      tmp[i] =\
    \ -tmp[i];\n    }\n    p *= tmp;\n    if (n & 1) {\n      for (int i = 0; i <\
    \ d; ++i) {\n        p[i] = p[(i << 1) + 1];\n      }\n    } else {\n      for\
    \ (int i = 1; i < d; ++i) {\n        p[i] = p[i << 1];\n      }\n    }\n    p.resize(d\
    \ - 1);\n    q *= tmp;\n    for (int i = 1; i <= d; ++i) {\n      q[i] = q[i <<\
    \ 1];\n    }\n    q.resize(d);\n  }\n  return res + p[0] / q[0];\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_BOSTAN_MORI_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/bostan-mori.hpp
  requiredBy:
  - include/emthrm/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/bostan-mori.test.cpp
documentation_of: include/emthrm/math/formal_power_series/bostan-mori.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/formal_power_series/bostan-mori.hpp
- /library/include/emthrm/math/formal_power_series/bostan-mori.hpp.html
title: "Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
---
# Bostan–Mori のアルゴリズム

$d$-階線形回帰数列の第 $N$ 項を求めるアルゴリズムである。


## 時間計算量

$d$ 次多項式同士の乗算の算術計算量を $\mathsf{M}(d)$ とおくと $O(\mathsf{M}(d) \log{N})$


## 仕様

|名前|戻り値|要件|備考|
|:--|:--|:--|:--|
|`template <template <typename> class C, typename T>`<br>`T bostan_mori(C<T> p, C<T> q, long long n);`|${\lbrack x^N \rbrack}\frac{P(x)}{Q(x)}$|${\lbrack x^0 \rbrack}Q = Q(0)$ は可逆元 (invertible element) である。|`C` は冪級数を表す構造体である。|
|`template <template <typename> class C, typename T>`<br>`T nth_term_of_linear_recurrence_sequence(C<T> a, C<T> q, const long long n);`|特性多項式 $Q(x)$ をもち、$A(x) = B(x) \bmod{x^{\mathrm{deg}(A)}}$ を満たす線形回帰数列の母関数 $B(x)$ に対して ${\lbrack x^N \rbrack}B$||`C` は冪級数を表す構造体である。|


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
