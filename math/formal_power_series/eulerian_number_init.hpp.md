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
    document_title: "Eulerian number \u306E\u6570\u8868"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/formal_power_series/eulerian_number_init.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief Eulerian number \u306E\u6570\u8868\r\n * @docs docs/math/formal_power_series/eulerian_number.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\n\
    std::vector<std::vector<T>> eulerian_number_init(int n, int m) {\r\n  std::vector<std::vector<T>>\
    \ a(n + 1, std::vector<T>(m + 1, 0));\r\n  a[0][0] = 1;\r\n  for (int i = 1; i\
    \ <= n; ++i) {\r\n    a[i][0] = 1;\r\n    for (int j = 1; j < i; ++j) a[i][j]\
    \ = a[i - 1][j - 1] * (i - j) + a[i - 1][j] * (j + 1);\r\n  }\r\n  return a;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/formal_power_series/eulerian_number_init.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/formal_power_series/eulerian_number_init.hpp
layout: document
redirect_from:
- /library/math/formal_power_series/eulerian_number_init.hpp
- /library/math/formal_power_series/eulerian_number_init.hpp.html
title: "Eulerian number \u306E\u6570\u8868"
---
# Eulerian number

$$A_n(x) = \sum_{m = 0}^n A(n, m) x^m$$

で定義される $A(n, m)$ である．ただし $A_n(x)$ は

$$\sum_{n = 0}^{\infty} A_n(x) \dfrac{t^n}{t!} = \dfrac{x - 1}{x - e^{(x - 1)t}}$$

で定義される Eulerian polynomials である．

$$A(n, m) = \begin{cases} 1 & (m = 0) \\ 0 & (n = m > 0) \\ (n - m) A(n - 1, m - 1) + (m + 1) A(n - 1, m) & (0 < m < n) \end{cases}$$

なる漸化式より計算ができる．

一般項

$$A(n, m) = \sum_{k = 0}^m (-1)^k \binom{n + 1}{k} (m + 1 - k)^n$$

である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|数表|$O(NM)$|
|数表 形式的冪級数版|$O(N\log{N})$|


## 使用法

- 数表

||説明|
|:--:|:--:|
|`eulerian_number_init(n, m)`|Eulerian number $A(i, j) \ (0 \leq i \leq n,\ 0 \leq j \leq m)$|

- 数表 形式的冪級数版

||説明|
|:--:|:--:|
|`eulerian_number_init_by_fps<T>(n)`|Eulerian number $A(n, j) \ (0 \leq j \leq n)$|


## 参考

- https://en.wikipedia.org/wiki/Eulerian_number
- http://oeis.org/wiki/Eulerian_numbers,_triangle_of
- https://min-25.hatenablog.com/entry/2015/04/07/160154


## Verified

- 数表
- 数表 形式的冪級数版
