---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/formal_power_series/eulerian_number.md
    document_title: Eulerian number
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/formal_power_series/eulerian_number.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\n * @brief Eulerian number\n * @docs docs/math/formal_power_series/eulerian_number.md\n\
    \ */\n\n#pragma once\n#include <vector>\n\ntemplate <typename T>\nstd::vector<std::vector<T>>\
    \ eulerian_number(const int n, const int m) {\n  std::vector<std::vector<T>> a(n\
    \ + 1, std::vector<T>(m + 1, 0));\n  a[0][0] = 1;\n  for (int i = 1; i <= n; ++i)\
    \ {\n    a[i][0] = 1;\n    for (int j = 1; j < i; ++j) {\n      a[i][j] = a[i\
    \ - 1][j - 1] * (i - j) + a[i - 1][j] * (j + 1);\n    }\n  }\n  return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/formal_power_series/eulerian_number.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/formal_power_series/eulerian_number.hpp
layout: document
redirect_from:
- /library/math/formal_power_series/eulerian_number.hpp
- /library/math/formal_power_series/eulerian_number.hpp.html
title: Eulerian number
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
