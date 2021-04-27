---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/mobius_mu/mobius_mu_init.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570\u306E\u6570\u8868"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/mobius_mu/mobius_mu.md
    document_title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u8868"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/mobius_mu/mobius_mu_init.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u8868\r\
    \n * @docs docs/math/mobius_mu/mobius_mu.md\r\n */\r\n\r\n#pragma once\r\n#include\
    \ <vector>\r\n\r\nstd::vector<int> mobius_mu_init(int n) {\r\n  std::vector<bool>\
    \ is_prime(n + 1, true);\r\n  is_prime[0] = false;\r\n  if (n >= 1) is_prime[1]\
    \ = false;\r\n  std::vector<int> mu(n + 1, 1);\r\n  mu[0] = 0;\r\n  for (int i\
    \ = 2; i <= n; ++i) {\r\n    if (is_prime[i]) {\r\n      mu[i] = -mu[i];\r\n \
    \     for (int j = i * 2; j <= n; j += i) {\r\n        is_prime[j] = false;\r\n\
    \        mu[j] = (j / i) % i == 0 ? 0 : -mu[j];\r\n      }\r\n    }\r\n  }\r\n\
    \  return mu;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mobius_mu/mobius_mu_init.hpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/mobius_mu/mobius_mu_init.test.cpp
documentation_of: math/mobius_mu/mobius_mu_init.hpp
layout: document
redirect_from:
- /library/math/mobius_mu/mobius_mu_init.hpp
- /library/math/mobius_mu/mobius_mu_init.hpp.html
title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u8868"
---
# メビウス関数 (Möbius function)

自然数 $n \geq 1$ に対して

$$\mu(n) = \begin{cases} 0 & (\exists p \in \mathbb{P} \text{ s.t. } n \equiv 0 \pmod{p^2}) \\ (-1)^{\# \lbrace \text{相異なる素因数} \rbrace} & (\text{otherwise}) \end{cases}$$

で定義される $\mu$ である．

- 自然数 $\forall n \geq 2$ に対して

  $$\sum_{d \mid n} \mu(d) = 0 \text{，}$$，

- $$\mu(mn) = \begin{cases} \mu(m) \mu(n) & (m \perp n) \\ 0 & (\text{otherwise}) \end{cases}$$

という性質をもつ．


### メビウスの反転公式 (Möbius inversion formula)

$$f(n) = \sum_{d \mid n} g(d) \Leftrightarrow g(n) = \sum_{d \mid n} \mu \left(\frac{n}{d} \right) f(d) = \sum_{d \mid n} \mu(d) f \left(\frac{n}{d} \right) \text{．}$$


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(\sqrt N)$|
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

- プログラミングコンテストチャレンジブック \[第2版\] pp.265-268
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E3%81%AE%E5%8F%8D%E8%BB%A2%E5%85%AC%E5%BC%8F
- https://github.com/spaghetti-source/algorithm/blob/e8fde0fea20e323f42e263376302494cda1ae7f7/number_theory/mobius_mu.cc


## ToDo

- https://drive.google.com/drive/folders/1z4kUGi0ObnWPQwdzmH-IHG6oV-XCRYnL


## Verified

- https://codeforces.com/contest/1139/submission/68227663
- [約数版](https://codeforces.com/contest/1139/submission/68228222)
- [数表](https://codeforces.com/contest/1139/submission/68229217)
- [数表2](https://codeforces.com/contest/1139/submission/68229567)
