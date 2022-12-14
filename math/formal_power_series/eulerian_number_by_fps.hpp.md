---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/formal_power_series/eulerian_number.md
    document_title: "Eulerian number \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/formal_power_series/eulerian_number_by_fps.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\n * @brief Eulerian number \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248\
    \n * @docs docs/math/formal_power_series/eulerian_number.md\n */\n\n#pragma once\n\
    #include <vector>\n\n#include \"../modint.hpp\"\n#include \"./formal_power_series.hpp\"\
    \n\ntemplate <int T>\nstd::vector<MInt<T>> eulerian_number_init_by_fps(const int\
    \ n) {\n  using ModInt = MInt<T>;\n  if (n == 0) return {1};\n  ModInt::init(n\
    \ + 1);\n  const int m = (n + 1) >> 1;\n  FormalPowerSeries<ModInt> a(m - 1),\
    \ b(m - 1);\n  for (int i = 0; i < m; ++i) {\n    a[i] = ModInt(i + 1).pow(n);\n\
    \  }\n  for (int i = 0; i < m; ++i) {\n    b[i] = (i & 1 ? -ModInt::fact_inv(i)\
    \ : ModInt::fact_inv(i))\n           * ModInt::fact_inv(n + 1 - i);\n  }\n  a\
    \ *= b;\n  a.resize(n);\n  for (int i = 0; i < m; ++i) {\n    a[i] *= ModInt::fact(n\
    \ + 1);\n    a[n - 1 - i] = a[i];\n  }\n  return a.coef;\n}\n"
  dependsOn:
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: math/formal_power_series/eulerian_number_by_fps.hpp
  requiredBy: []
  timestamp: '2022-08-08 06:04:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/formal_power_series/eulerian_number_by_fps.hpp
layout: document
redirect_from:
- /library/math/formal_power_series/eulerian_number_by_fps.hpp
- /library/math/formal_power_series/eulerian_number_by_fps.hpp.html
title: "Eulerian number \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
---
# Eulerian number

$$
  A_n(x) = \sum_{m = 0}^n A(n, m) x^m
$$

で定義される $A(n, m)$ である．ただし $A_n(x)$ は

$$
  \sum_{n = 0}^{\infty} A_n(x) \dfrac{t^n}{t!} = \dfrac{x - 1}{x - e^{(x - 1)t}}
$$

で定義される Eulerian polynomials である．

$$
  A(n, m) =
  \begin{cases}
    1 & (m = 0), \\
    0 & (n = m > 0), \\
    (n - m) A(n - 1, m - 1) + (m + 1) A(n - 1, m) & (0 < m < n)
  \end{cases}
$$

という漸化式をもつ．

一般項

$$
  A(n, m) = \sum_{k = 0}^m (-1)^k \binom{n + 1}{k} (m + 1 - k)^n
$$

である．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(NM)$|
|形式的冪級数版|$O(N\log{N})$|


## 使用法

||説明|
|:--:|:--:|
|`eulerian_number(n, m)`|Eulerian number $A(i, j)$ ($0 \leq i \leq n,\ 0 \leq j \leq m$) の数表|

- 形式的冪級数版

||説明|
|:--:|:--:|
|`eulerian_number_by_fps<T>(n)`|Eulerian number $A(n, j)$ ($0 \leq j \leq n$) の数表|


## 参考

- https://en.wikipedia.org/wiki/Eulerian_number
- http://oeis.org/wiki/Eulerian_numbers,_triangle_of
- https://min-25.hatenablog.com/entry/2015/04/07/160154
