---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570 \u7D04\u6570\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/mobius_mu/mobius_mu.md
    document_title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/mobius_mu/mobius_mu_focusing_on_divisor.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief \u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248\r\
    \n * @docs docs/math/mobius_mu/mobius_mu.md\r\n */\r\n\r\n#pragma once\r\n#include\
    \ <map>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::map<T, int>\
    \ mobius_mu_focusing_on_divisor(T n) {\r\n  std::vector<T> primes;\r\n  for (T\
    \ i = 2; i * i <= n; ++i) {\r\n    if (n % i == 0) {\r\n      primes.emplace_back(i);\r\
    \n      while (n % i == 0) {\r\n        n /= i;\r\n      }\r\n    }\r\n  }\r\n\
    \  if (n > 1) {\r\n    primes.emplace_back(n);\r\n  }\r\n  const int p = primes.size();\r\
    \n  std::map<T, int> mu;\r\n  for (int i = 0; i < (1 << p); ++i) {\r\n    T d\
    \ = 1;\r\n    for (int j = 0; j < p; ++j) {\r\n      if (i >> j & 1) {\r\n   \
    \     d *= primes[j];\r\n      }\r\n    }\r\n    mu[d] = (__builtin_popcount(i)\
    \ & 1 ? -1 : 1);\r\n  }\r\n  return mu;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mobius_mu/mobius_mu_focusing_on_divisor.hpp
  requiredBy: []
  timestamp: '2021-09-23 22:47:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
documentation_of: math/mobius_mu/mobius_mu_focusing_on_divisor.hpp
layout: document
redirect_from:
- /library/math/mobius_mu/mobius_mu_focusing_on_divisor.hpp
- /library/math/mobius_mu/mobius_mu_focusing_on_divisor.hpp.html
title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
---
# メビウス関数 (Möbius function)

$n \in \mathbb{N}^+$ に対して

$$\mu(n) = \begin{cases} 0 & (\exists p \in \mathbb{P} \text{ s.t. } n \equiv 0 \pmod{p^2}) \\ (-1)^{\# \lbrace \text{相異なる素因数} \rbrace} & (\text{otherwise}) \end{cases}$$

で定義される $\mu$ である．

- 自然数 $\forall n \geq 2$ に対して

  $$\sum_{d \mid n} \mu(d) = 0 \text{，}$$，

- $$\mu(mn) = \begin{cases} \mu(m) \mu(n) & (m \perp n), \\ 0 & (\text{otherwise}) \end{cases}$$

という性質をもつ．


### メビウスの反転公式 (Möbius inversion formula)

$$f(n) = \sum_{d \mid n} g(d) \implies g(n) = \sum_{d \mid n} \mu \left(\frac{n}{d} \right) f(d) = \sum_{d \mid n} \mu(d) f \left(\frac{n}{d} \right) \text{．}$$


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(\sqrt{N})$|
|約数版||
|数表|$O(N\log{\log{N}})$|
|数表2|$O(\sqrt{H}\log{\log{\sqrt{H}}} + \frac{(H - L)\sqrt{H}}{\log{H}})$ ?|


## 使用法

||説明|
|:--:|:--:|
|`mobius_mu(n)`|$\mu(n)$|

- 約数版

||説明|備考|
|:--:|:--:|:--:|
|`mobius_mu_focusing_on_divisor(n)`|$\lbrace n \text{ の約数 } d, \mu(d)) \rbrace$|キーとして存在しない場合は $n$ の約数でないか値 $0$ である．|

- 数表

||説明|
|:--:|:--:|
|`mobius_mu_init(n)`|メビウス関数 $\mu(i) \ (1 \leq i \leq n)$ の数表|

- 数表

||説明|
|:--:|:--:|
|`mobius_mu_init2(low, high)`|メビウス関数 $\mu(i) \ (\mathrm{low} \leq i < \mathrm{high})$ の数表|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.265-268，マイナビ出版（2012）．
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E3%81%AE%E5%8F%8D%E8%BB%A2%E5%85%AC%E5%BC%8F
- https://github.com/spaghetti-source/algorithm/blob/e8fde0fea20e323f42e263376302494cda1ae7f7/number_theory/mobius_mu.cc


## ToDo

- https://drive.google.com/drive/folders/1z4kUGi0ObnWPQwdzmH-IHG6oV-XCRYnL


## Verified

- https://atcoder.jp/contests/abc162/submissions/26045975
- [約数版](https://atcoder.jp/contests/abc162/submissions/26046320)
- [数表](https://atcoder.jp/contests/abc162/submissions/26046042)
- [数表2](https://atcoder.jp/contests/abc162/submissions/26046148)
