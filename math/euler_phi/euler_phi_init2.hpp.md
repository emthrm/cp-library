---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/sieve_of_eratosthenes.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9 (sieve of Eratosthenes)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi_init2.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/euler_phi/euler_phi.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\
      \u88682"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/euler_phi/euler_phi_init2.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\
    \u6570\u88682\r\n * @docs docs/math/euler_phi/euler_phi.md\r\n */\r\n\r\n#pragma\
    \ once\r\n#include <cmath>\r\n#include <numeric>\r\n#include <vector>\r\n#include\
    \ \"../sieve_of_eratosthenes.hpp\"\r\n\r\nstd::vector<long long> euler_phi_init2(long\
    \ long low, long long high) {\r\n  int sqrt_high = std::ceil(std::sqrt(high));\r\
    \n  std::vector<bool> primes = sieve_of_eratosthenes(sqrt_high);\r\n  std::vector<long\
    \ long> phi(high - low), rem(high - low);\r\n  std::iota(phi.begin(), phi.end(),\
    \ low);\r\n  std::iota(rem.begin(), rem.end(), low);\r\n  for (int prime = 2;\
    \ prime <= sqrt_high; ++prime) {\r\n    if (primes[prime]) {\r\n      for (long\
    \ long i = (low + (prime - 1)) / prime * prime; i < high; i += prime) {\r\n  \
    \      phi[i - low] -= phi[i - low] / prime;\r\n        while (rem[i - low] %\
    \ prime == 0) rem[i - low] /= prime;\r\n      }\r\n    }\r\n  }\r\n  for (int\
    \ i = 0; i < high - low; ++i) {\r\n    if (rem[i] > 1) phi[i] -= phi[i] / rem[i];\r\
    \n  }\r\n  return phi;\r\n}\r\n"
  dependsOn:
  - math/sieve_of_eratosthenes.hpp
  isVerificationFile: false
  path: math/euler_phi/euler_phi_init2.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/euler_phi/euler_phi_init2.test.cpp
documentation_of: math/euler_phi/euler_phi_init2.hpp
layout: document
redirect_from:
- /library/math/euler_phi/euler_phi_init2.hpp
- /library/math/euler_phi/euler_phi_init2.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
---
# オイラーの $\varphi$ 関数 (Euler's totient function)

$$\begin{aligned} \varphi(n) &= \# \lbrace \,k \in \mathbb{N} \mid k \perp n,\ k \leq n \rbrace \\ &= n \prod_i(1 - \frac{1}{p_i}) \ (p_i \text{ : } n \text{ の素因数}) \text{．} \end{aligned}$$


### オイラーの定理

$$a^{\varphi(n)} \equiv 1 \pmod{n} \text{．}$$


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(\sqrt{N})$|
|数表|$O(N\log{\log{N}})$|
|数表2|$O(\sqrt{H}\log{\log{\sqrt{H}}} + \frac{(H - L)\sqrt{H}}{\log{H}})$ ?|


## 使用法

||説明|
|:--:|:--:|
|`phi(val)`|$\varphi(\mathrm{val})$|

- 数表

||説明|
|:--:|:--:|
|`phi_init(val)`|$\varphi(n) \ (1 \leq n \leq \mathrm{val})$ の数表|

- 数表2

||説明|
|:--:|:--:|
|`phi_init2(low, high)`|$\varphi(n) \ (\mathrm{low} \leq n \leq \mathrm{high})$ の数表|


## 参考

- https://ei1333.github.io/algorithm/euler-phi.html

数表2

- https://github.com/spaghetti-source/algorithm/blob/master/number_theory/euler_phi.cc


## ToDo

- $\sum_{i = 1}^n \varphi(i)$ を $O(N^{\frac{2}{3}})$ で求める．
  - https://yukicoder.me/wiki/sum_totient
  - https://min-25.hatenablog.com/entry/2018/11/11/172216
  - https://judge.yosupo.jp/problem/sum_of_totient_function


## Verified

* https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088206/emthrm/C++14
* [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088232/emthrm/C++14)
* [数表2](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088268/emthrm/C++14)
