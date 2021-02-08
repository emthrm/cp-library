---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/lcm.hpp
    title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
  - icon: ':question:'
    path: math/sieve_of_eratosthenes.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9 (sieve of Eratosthenes)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/carmichal_function.md
    document_title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/carmichal_function_init.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\
    \u8868\r\n * @docs docs/math/carmichal_function.md\r\n */\r\n\r\n#pragma once\r\
    \n#include <cmath>\r\n#include <numeric>\r\n#include <vector>\r\n#include \"sieve_of_eratosthenes.hpp\"\
    \r\n#include \"lcm.hpp\"\r\n\r\nstd::vector<long long> carmichal_function_init(long\
    \ long low, long long high) {\r\n  int sqrt_high = std::ceil(std::sqrt(high));\r\
    \n  std::vector<bool> is_prime = sieve_of_eratosthenes(sqrt_high);\r\n  std::vector<long\
    \ long> res(high - low, 1), tmp(high - low);\r\n  std::iota(tmp.begin(), tmp.end(),\
    \ low);\r\n  if (low == 0 && high > 0) res[0] = 0;\r\n  for (long long i = (low\
    \ + 7) / 8 * 8; i < high; i += 8) tmp[i - low] >>= 1;\r\n  for (int p = 2; p <=\
    \ sqrt_high; ++p) {\r\n    if (is_prime[p]) {\r\n      for (long long i = (low\
    \ + (p - 1)) / p * p; i < high; i += p) {\r\n        if (i == 0) continue;\r\n\
    \        tmp[i - low] /= p;\r\n        long long phi = p - 1;\r\n        while\
    \ (tmp[i - low] % p == 0) {\r\n          tmp[i - low] /= p;\r\n          phi *=\
    \ p;\r\n        }\r\n        res[i - low] = __lcm(res[i - low], phi);\r\n    \
    \  }\r\n    }\r\n  }\r\n  for (int i = 0; i < high - low; ++i) {\r\n    if (tmp[i]\
    \ > 1) res[i] = __lcm(res[i], tmp[i] - 1);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - math/sieve_of_eratosthenes.hpp
  - math/lcm.hpp
  isVerificationFile: false
  path: math/carmichal_function_init.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/carmichal_function_init.hpp
layout: document
redirect_from:
- /library/math/carmichal_function_init.hpp
- /library/math/carmichal_function_init.hpp.html
title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
---
# カーマイケル関数 (Carmichael function)

$n = \prod_{i = 1}^k p_i^{e_i}$ と素因数分解されるとすると

$$\lambda(n) = \begin{cases} 1 & (n = 1, 2) \\ 2 & (n = 4) \\ 2^{e - 2} & (\exists e \geq 3 \text{ s.t. } n = 2^e) \\ (p - 1)p^{e - 1} & (\exists p \text{ : 奇素数},\ e \in \mathbb{N} \text{ s.t. } n = p^e) \\ \mathrm{lcm} (\lambda(p_1^{e_1}),\ldots, \lambda(p_k^{e_k})) & (\text{otherwise}) \text{．} \end{cases}$$


### カーマイケルの定理 (Carmichael's theorem)

$n$ を $2$ 以上の任意の自然数とする．

$n$ と互いに素な任意の底 $a \ (1 \leq a \leq n)$ に対して

$$a^{\lambda(n)} \equiv 1 \pmod{n}$$

が成り立つ．


## 使用法

||説明|
|:--:|:--:|
|`carmichal_function(val)`|$\lambda(\mathrm{val})$|

- 数表

||説明|
|:--:|:--:|
|`carmichal_function(low, high)`|カーマイケル関数 $\lambda(n) \ (\mathrm{low} \leq n \leq \mathrm{high})$ の数表|


## 参考

- http://integers.hatenablog.com/entry/2017/06/08/191649
- https://en.wikipedia.org/wiki/Carmichael_function
- https://github.com/spaghetti-source/algorithm/blob/master/number_theory/carmichael_lambda.cc


## ToDo

- https://onlinejudge.u-aizu.ac.jp/problems/2720


## Verified
