---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/least_common_multiple.hpp
    title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/carmichal_function.md
    document_title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/carmichal_function.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\r\n * @docs\
    \ docs/math/carmichal_function.md\r\n */\r\n\r\n#pragma once\r\n#include \"least_common_multiple.hpp\"\
    \r\n\r\nlong long carmichal_function(long long n) {\r\n  long long res = 1;\r\n\
    \  if (n % 8 == 0) n >>= 1;\r\n  for (long long i = 2; i * i <= n; ++i) {\r\n\
    \    if (n % i == 0) {\r\n      n /= i;\r\n      long long phi = i - 1;\r\n  \
    \    while (n % i == 0) {\r\n        n /= i;\r\n        phi *= i;\r\n      }\r\
    \n      res = __lcm(res, phi);\r\n    }\r\n  }\r\n  if (n > 1) res = __lcm(res,\
    \ n - 1);\r\n  return res;\r\n}\r\n"
  dependsOn:
  - math/least_common_multiple.hpp
  isVerificationFile: false
  path: math/carmichal_function.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/carmichal_function.hpp
layout: document
redirect_from:
- /library/math/carmichal_function.hpp
- /library/math/carmichal_function.hpp.html
title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
---
# カーマイケル関数 (Carmichael function)

$n = \prod_{i = 1}^k p_i^{e_i}$ と素因数分解されるとすると

$$\lambda(n) = \begin{cases} 1 & (n = 1, 2) \\ 2 & (n = 4) \\ 2^{e - 2} & (\exists e \geq 3 \text{ s.t. } n = 2^e) \\ (p - 1)p^{e - 1} & (\exists p \text{ : 奇素数},\ e \in \mathbb{N} \text{ s.t. } n = p^e) \\ \mathrm{lcm} (\lambda(p_1^{e_1}),\ldots, \lambda(p_k^{e_k})) & (\text{otherwise}) \end{cases}$$

で定義される $\lambda$ である．


### カーマイケルの定理 (Carmichael's theorem)

$n$ を $2$ 以上の任意の自然数とする．

$n$ と互いに素な任意の底 $a \ (1 \leq a \leq n)$ に対して

$$a^{\lambda(n)} \equiv 1 \pmod{n}$$

が成り立つ．


## 使用法

||説明|
|:--:|:--:|
|`carmichal_function(n)`|$\lambda(n)$|

- 数表

||説明|
|:--:|:--:|
|`carmichal_function(low, high)`|カーマイケル関数 $\lambda(n) \ (\mathrm{low} \leq n \leq \mathrm{high})$ の数表|


## 参考

- http://integers.hatenablog.com/entry/2017/06/08/191649
- https://en.wikipedia.org/wiki/Carmichael_function
- https://github.com/spaghetti-source/algorithm/blob/8af3698b8a7583035857280ab324c8ae75c70374/number_theory/carmichael_lambda.cc


## ToDo

- https://onlinejudge.u-aizu.ac.jp/problems/2720


## Verified

-
- 数表
