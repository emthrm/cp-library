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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/formal_power_series/eulerian_number_by_fps.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief Eulerian number \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248\
    \r\n * @docs docs/math/formal_power_series/eulerian_number.md\r\n */\r\n\r\n#pragma\
    \ once\r\n#include <vector>\r\n\r\n#include \"../modint.hpp\"\r\n#include \"./formal_power_series.hpp\"\
    \r\n\r\ntemplate <int T>\r\nstd::vector<MInt<T>> eulerian_number_init_by_fps(const\
    \ int n) {\r\n  using ModInt = MInt<T>;\r\n  if (n == 0) return {1};\r\n  ModInt::init(n\
    \ + 1);\r\n  const int m = (n + 1) >> 1;\r\n  FormalPowerSeries<ModInt> a(m -\
    \ 1), b(m - 1);\r\n  for (int i = 0; i < m; ++i) {\r\n    a[i] = ModInt(i + 1).pow(n);\r\
    \n  }\r\n  for (int i = 0; i < m; ++i) {\r\n    b[i] = (i & 1 ? -ModInt::fact_inv(i)\
    \ : ModInt::fact_inv(i))\r\n           * ModInt::fact_inv(n + 1 - i);\r\n  }\r\
    \n  a *= b;\r\n  a.resize(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    a[i] *=\
    \ ModInt::fact(n + 1);\r\n    a[n - 1 - i] = a[i];\r\n  }\r\n  return a.coef;\r\
    \n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: math/formal_power_series/eulerian_number_by_fps.hpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
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

$$A_n(x) = \sum_{m = 0}^n A(n, m) x^m$$

で定義される $A(n, m)$ である．ただし $A_n(x)$ は

$$\sum_{n = 0}^{\infty} A_n(x) \dfrac{t^n}{t!} = \dfrac{x - 1}{x - e^{(x - 1)t}}$$

で定義される Eulerian polynomials である．

$$A(n, m) = \begin{cases} 1 & (m = 0), \\ 0 & (n = m > 0), \\ (n - m) A(n - 1, m - 1) + (m + 1) A(n - 1, m) & (0 < m < n) \end{cases}$$

という漸化式をもつ．

一般項

$$A(n, m) = \sum_{k = 0}^m (-1)^k \binom{n + 1}{k} (m + 1 - k)^n$$

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
