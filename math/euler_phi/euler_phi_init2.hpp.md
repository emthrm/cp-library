---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.hpp
    title: prime sieve
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/euler_phi/euler_phi_init2.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\
    \u6570\u88682\n * @docs docs/math/euler_phi/euler_phi.md\n */\n\n#pragma once\n\
    #include <numeric>\n#include <vector>\n\n#include \"../prime_sieve.hpp\"\n\nstd::vector<long\
    \ long> euler_phi_init2(const long long low,\n                               \
    \        const long long high) {\n  std::vector<long long> phi(high - low), rem(high\
    \ - low);\n  std::iota(phi.begin(), phi.end(), low);\n  std::iota(rem.begin(),\
    \ rem.end(), low);\n  long long root = 1;\n  while ((root + 1) * (root + 1) <\
    \ high) ++root;\n  for (const int p : prime_sieve(root, true)) {\n    for (long\
    \ long i = (low + p - 1) / p * p; i < high; i += p) {\n      phi[i - low] -= phi[i\
    \ - low] / p;\n      while (rem[i - low] % p == 0) rem[i - low] /= p;\n    }\n\
    \  }\n  for (int i = 0; i < high - low; ++i) {\n    if (rem[i] > 1) phi[i] -=\
    \ phi[i] / rem[i];\n  }\n  return phi;\n}\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: false
  path: math/euler_phi/euler_phi_init2.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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

$n \in \mathbb{N}^+$ に対して

$$
  \varphi(n) \mathrel{:=} \# \lbrace k \in \lbrace 1, 2, \ldots, n \rbrace \mid k \perp n \rbrace
$$

と定義される $\varphi(n)$ である．素因数分解 $n = \prod_{i = 1}^k p_i^{e_i}$ に対して

$$
  \varphi(n) = n \prod_{i = 1}^k \left(1 - \frac{1}{p_i}\right)
$$

が成り立つ．


### オイラーの定理

$n \perp a$ を満たす $n, a \in \mathbb{N}^+$ に対して $a^{\varphi(n)} \equiv 1 \pmod{n}$ が成り立つ．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(\sqrt{N})$|
|数表|$O(N\log{\log{N}})$|
|数表2|$O\left(\sqrt{H}\log{\log{H}} + \frac{(H - L)\sqrt{H}}{\log{H}}\right)$ ?|


## 使用法

||説明|
|:--:|:--:|
|`euler_phi(n)`|$\varphi(n)$|

- 数表

||説明|
|:--:|:--:|
|`euler_phi_init(n)`|$\varphi(i)$ ($1 \leq i \leq n$) の数表|

- 数表2

||説明|
|:--:|:--:|
|`euler_phi_init2(low, high)`|$\varphi(i)$ ($\mathrm{low} \leq i < \mathrm{high}$) の数表|


## 参考

- https://ei1333.github.io/algorithm/euler-phi.html

数表2
- https://github.com/spaghetti-source/algorithm/blob/87f5b3e4a3c10d8b85048f4fc4e4842ad11e9670/number_theory/euler_phi.cc


## ToDo

- $\sum_{i = 1}^n \varphi(i)$ を $O(N^{\frac{2}{3}})$ で求める．
  - https://yukicoder.me/wiki/sum_totient
  - https://min-25.hatenablog.com/entry/2018/11/11/172216
  - https://judge.yosupo.jp/problem/sum_of_totient_function


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088206/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088232/emthrm/C++14)
- [数表2](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/4088268/emthrm/C++14)
