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
    _deprecated_at_docs: docs/math/carmichael_function.md
    document_title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/carmichael_function.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\r\n * @docs\
    \ docs/math/carmichael_function.md\r\n */\r\n\r\n#pragma once\r\n#include \"least_common_multiple.hpp\"\
    \r\n\r\nlong long carmichael_function(long long n) {\r\n  long long lambda = 1;\r\
    \n  if (n % 8 == 0) n >>= 1;\r\n  for (long long i = 2; i * i <= n; ++i) {\r\n\
    \    if (n % i == 0) {\r\n      n /= i;\r\n      long long phi = i - 1;\r\n  \
    \    for (; n % i == 0; n /= i) {\r\n        phi *= i;\r\n      }\r\n      lambda\
    \ = __lcm(lambda, phi);\r\n    }\r\n  }\r\n  return n > 1 ? __lcm(lambda, n -\
    \ 1) : lambda;\r\n}\r\n"
  dependsOn:
  - math/least_common_multiple.hpp
  isVerificationFile: false
  path: math/carmichael_function.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/carmichael_function.hpp
layout: document
redirect_from:
- /library/math/carmichael_function.hpp
- /library/math/carmichael_function.hpp.html
title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
---
# カーマイケル関数 (Carmichael function)

$n \in \mathbb{N}^+$ に対して

$$\forall a \in \mathbb{N}^+,\ a \perp n \implies a^x \equiv 1 \pmod{n}$$

を満たす最小の $x \in \mathbb{N}^+$ を $\lambda(n)$ と定義する．

素因数分解 $n = \prod_{i = 1}^k p_i^{e_i}$ に対して

$$\lambda(n) = \begin{cases} 1 & (n = 1, 2), \\ 2 & (n = 4), \\ 2^{e - 2} & (\exists e \geq 3,\ n = 2^e), \\ (p - 1)p^{e - 1} & (\exists p \text{ : 奇素数},\ \exists e \in \mathbb{N}^+,\ n = p^e), \\ \mathrm{lcm} (\lambda(p_1^{e_1}),\ldots, \lambda(p_k^{e_k})) & (\text{otherwise}) \end{cases}$$

が成り立つ．


## 使用法

||説明|
|:--:|:--:|
|`carmichael_function(n)`|カーマイケル関数 $\lambda(n)$|

- 数表

||説明|
|:--:|:--:|
|`carmichael_function_init(low, high)`|カーマイケル関数 $\lambda(n)$ ($\mathrm{low} \leq n \leq \mathrm{high}$) の数表|


## 参考

- http://integers.hatenablog.com/entry/2017/06/08/191649
- https://en.wikipedia.org/wiki/Carmichael_function
- https://github.com/spaghetti-source/algorithm/blob/8af3698b8a7583035857280ab324c8ae75c70374/number_theory/carmichael_lambda.cc


## ToDo

- https://onlinejudge.u-aizu.ac.jp/problems/2720
