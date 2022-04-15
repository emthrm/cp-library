---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/least_common_multiple.hpp
    title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/carmichael_function.md
    document_title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/carmichael_function_init.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\
    \u8868\r\n * @docs docs/math/carmichael_function.md\r\n */\r\n\r\n#pragma once\r\
    \n#include <numeric>\r\n#include <vector>\r\n\r\n#include \"./least_common_multiple.hpp\"\
    \r\n#include \"./prime_sieve.hpp\"\r\n\r\nstd::vector<long long> carmichael_function_init(const\
    \ long long low,\r\n                                                const long\
    \ long high) {\r\n  std::vector<long long> lambda(high - low, 1), tmp(high - low);\r\
    \n  std::iota(tmp.begin(), tmp.end(), low);\r\n  if (low == 0 && high > 0) lambda[0]\
    \ = 0;\r\n  for (long long i = (low + 7) / 8 * 8; i < high; i += 8) {\r\n    tmp[i\
    \ - low] >>= 1;\r\n  }\r\n  long long root = 1;\r\n  while ((root + 1) * (root\
    \ + 1) < high) ++root;\r\n  for (const int p : prime_sieve(root, true)) {\r\n\
    \    for (long long i = (low + p - 1) / p * p; i < high; i += p) {\r\n      if\
    \ (i == 0) continue;\r\n      tmp[i - low] /= p;\r\n      long long phi = p -\
    \ 1;\r\n      for (; tmp[i - low] % p == 0; tmp[i - low] /= p) {\r\n        phi\
    \ *= p;\r\n      }\r\n      lambda[i - low] = __lcm(lambda[i - low], phi);\r\n\
    \    }\r\n  }\r\n  for (int i = 0; i < high - low; ++i) {\r\n    if (tmp[i] >\
    \ 1) lambda[i] = __lcm(lambda[i], tmp[i] - 1);\r\n  }\r\n  return lambda;\r\n\
    }\r\n"
  dependsOn:
  - math/least_common_multiple.hpp
  - math/prime_sieve.hpp
  isVerificationFile: false
  path: math/carmichael_function_init.hpp
  requiredBy: []
  timestamp: '2022-02-24 04:47:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/carmichael_function_init.hpp
layout: document
redirect_from:
- /library/math/carmichael_function_init.hpp
- /library/math/carmichael_function_init.hpp.html
title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
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
