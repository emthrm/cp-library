---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/inverse_element/mod_inv_phi.hpp
    title: "\u9006\u5143 \u30AA\u30A4\u30E9\u30FC\u306E\u5B9A\u7406\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi_init.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi_init2.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/euler_phi/euler_phi.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/euler_phi/euler_phi.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\r\
    \n * @docs docs/math/euler_phi/euler_phi.md\r\n */\r\n\r\n#pragma once\r\n#include\
    \ <cassert>\r\n\r\nlong long euler_phi(long long n) {\r\n  assert(n >= 1);\r\n\
    \  long long res = n;\r\n  for (long long i = 2; i * i <= n; ++i) {\r\n    if\
    \ (n % i == 0) {\r\n      res -= res / i;\r\n      while (n % i == 0) n /= i;\r\
    \n    }\r\n  }\r\n  if (n > 1) res -= res / n;\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_phi/euler_phi.hpp
  requiredBy:
  - math/inverse_element/mod_inv_phi.hpp
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/euler_phi/euler_phi.test.cpp
  - test/math/euler_phi/euler_phi_init2.test.cpp
  - test/math/euler_phi/euler_phi_init.test.cpp
documentation_of: math/euler_phi/euler_phi.hpp
layout: document
redirect_from:
- /library/math/euler_phi/euler_phi.hpp
- /library/math/euler_phi/euler_phi.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
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
|`euler_phi(n)`|$\varphi(n)$|

- 数表

||説明|
|:--:|:--:|
|`euler_phi_init(n)`|$\varphi(i) \ (1 \leq i \leq \mathrm{n})$ の数表|

- 数表2

||説明|
|:--:|:--:|
|`euler_phi_init2(low, high)`|$\varphi(i) \ (\mathrm{low} \leq i \leq \mathrm{high})$ の数表|


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
