---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/mobius_mu_init2.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570\u306E\u6570\u88682"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/mobius_mu.md
    document_title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/mobius_mu_init2.hpp: line 12: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682\n\
    \ * @docs docs/math/mobius_mu.md\n */\n\n#ifndef EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_\n\
    #define EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_\n\n#include <numeric>\n#include <vector>\n\
    \n#include \"emthrm/math/prime_sieve.hpp\"\n\nnamespace emthrm {\n\nstd::vector<int>\
    \ mobius_mu_init2(const long long low, const long long high) {\n  std::vector<int>\
    \ mu(high - low, 1);\n  std::vector<long long> tmp(high - low);\n  std::iota(tmp.begin(),\
    \ tmp.end(), low);\n  if (low == 0 && high > 0) mu[0] = 0;\n  long long root =\
    \ 1;\n  while ((root + 1) * (root + 1) < high) ++root;\n  for (const int p : prime_sieve<true>(root))\
    \ {\n    for (long long i = (low + p - 1) / p * p; i < high; i += p) {\n     \
    \ if ((i / p) % p == 0) {\n        mu[i - low] = tmp[i - low] = 0;\n      } else\
    \ {\n        mu[i - low] = -mu[i - low];\n        tmp[i - low] /= p;\n      }\n\
    \    }\n  }\n  for (int i = 0; i < high - low; ++i) {\n    if (tmp[i] > 1) mu[i]\
    \ = -mu[i];\n  }\n  return mu;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_\n"
  dependsOn:
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: false
  path: include/emthrm/math/mobius_mu_init2.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/mobius_mu_init2.test.cpp
documentation_of: include/emthrm/math/mobius_mu_init2.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/mobius_mu_init2.hpp
- /library/include/emthrm/math/mobius_mu_init2.hpp.html
title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
---
# メビウス関数 (Möbius function)

$n \in \mathbb{N}^+$ に対して

$$
  \mu(n) \mathrel{:=}
  \begin{cases}
    0 & (\exists p \in \mathbb{P},\ n \equiv 0 \pmod{p^2}), \\
    (-1)^{\# \lbrace \text{相異なる素因数} \rbrace} & (\text{otherwise})
  \end{cases}
$$

で定義される $\mu(n)$ である。

- $$
    \forall n \in \mathbb{N}^+ \setminus \lbrace 1 \rbrace,\ \sum_{d \mid n} \mu(d) = 0,
  $$

- $$
    \mu(mn) =
    \begin{cases}
      \mu(m) \mu(n) & (m \perp n), \\
      0 & (\text{otherwise})
    \end{cases}
  $$

が成り立つ。


### メビウスの反転公式 (Möbius inversion formula)

$$
  f(n) = \sum_{d \mid n} g(d) \implies g(n) = \sum_{d \mid n} \mu \left(\frac{n}{d} \right) f(d) = \sum_{d \mid n} \mu(d) f \left(\frac{n}{d} \right)
$$


## 時間計算量

||時間計算量|
|:--|:--|
||$O(\sqrt{N})$|
|約数版||
|数表|$O(N\log{\log{N}})$|
|数表2|$O\left(\sqrt{H}\log{\log{H}} + \frac{(H - L)\sqrt{H}}{\log{H}}\right)$ ?|


## 仕様

|名前|戻り値|
|:--|:--|
|`int mobius_mu(long long n);`|$\mu(n)$|


### 約数版

|名前|戻り値|備考|
|:--|:--|:--|
|`template <typename T>`<br>`std::map<T, int> mobius_mu_focusing_on_divisor(T n);`|$\lbrace n \text{ の約数 } d, \mu(d) \rbrace$|キーとして存在しないときは値 $0$ である。|


### 数表

|名前|戻り値|
|:--|:--|
|`std::vector<int> mobius_mu_init(const int n);`|メビウス関数 $\mu(i)$ ($1 \leq i \leq n$) の数表|
|`std::vector<int> mobius_mu_init2(const long long low, const long long high);`|メビウス関数 $\mu(i)$ ($\mathrm{low} \leq i < \mathrm{high}$) の数表|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.265-268，マイナビ出版（2012）
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E3%81%AE%E5%8F%8D%E8%BB%A2%E5%85%AC%E5%BC%8F
- https://github.com/spaghetti-source/algorithm/blob/e8fde0fea20e323f42e263376302494cda1ae7f7/number_theory/mobius_mu.cc


## TODO

- https://drive.google.com/drive/folders/1z4kUGi0ObnWPQwdzmH-IHG6oV-XCRYnL


## Submissons

- https://atcoder.jp/contests/abc162/submissions/26045975
- [約数版](https://atcoder.jp/contests/abc162/submissions/26046320)
- [数表](https://atcoder.jp/contests/abc162/submissions/26046042)
- [数表2](https://atcoder.jp/contests/abc162/submissions/26046148)
