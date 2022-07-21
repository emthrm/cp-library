---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/formal_power_series/bostan-mori.hpp
    title: "Bostan\u2013Mori \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/formal_power_series/bostan-mori.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/Bostan\u2013Mori \u306E\
      \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/formal_power_series/bostan-mori.md
    document_title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u7B2C $N$ \u9805"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp: line 6:\
    \ #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u7B2C $N$ \u9805\
    \n * @docs docs/math/formal_power_series/bostan-mori.md\n */\n\n#pragma once\n\
    #include <cassert>\n\n#include \"./bostan-mori.hpp\"\n\ntemplate <template <typename>\
    \ class C, typename T>\nT nth_term_of_linear_recurrence_sequence(C<T> a, C<T>\
    \ q, const long long n) {\n  q.shrink();\n  const int d = q.degree();\n  assert(d\
    \ >= 0 && q[0] != 0);\n  if (a.degree() >= n) return a[n];\n  assert(a.degree()\
    \ >= d - 1);\n  a.resize(d - 1);\n  a *= q;\n  a.resize(d - 1);\n  return bostan_mori(a,\
    \ q, n);\n}\n"
  dependsOn:
  - math/formal_power_series/bostan-mori.hpp
  isVerificationFile: false
  path: math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/formal_power_series/bostan-mori.test.cpp
documentation_of: math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
layout: document
redirect_from:
- /library/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp
- /library/math/formal_power_series/nth_term_of_linear_recurrence_sequence.hpp.html
title: "\u7DDA\u5F62\u56DE\u5E30\u6570\u5217\u306E\u7B2C $N$ \u9805"
---
# Bostan–Mori のアルゴリズム

$d$-階線形回帰数列の第 $N$ 項を求めるアルゴリズムである．


## 時間計算量

$d$ 次多項式同士の乗算の算術計算量を $\mathsf{M}(d)$ とおくと $O(\mathsf{M}(d) \log{N})$．


## 使用法

||説明|条件|
|:--:|:--:|:--:|
|`bostan_mori<多項式, T>(p, q, n)`|${\lbrack x^N \rbrack}\frac{P(x)}{Q(x)}$|${\lbrack x^0 \rbrack}Q = Q(0)$ は可逆元 (invertible element) である．|
|`nth_term_of_linear_recurrence_sequence(a, q, n)`|特性多項式 $Q(x)$ をもち，$A(x) = B(x) \bmod{x^{\mathrm{deg}(A)}}$ を満たす線形回帰数列の母関数 $B(x)$ に対して ${\lbrack x^N \rbrack}B$||


## 参考

- http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
- https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
- https://nyaannyaan.github.io/library/fps/kitamasa.hpp
- https://tsuchi.hateblo.jp/entry/2021/10/09/124804


## ToDo

- $x^N \bmod \Gamma(x)$
  - https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b


## Verified

https://judge.yosupo.jp/submission/80098
