---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/mobius_mu_init2.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570\u306E\u6570\u88682"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/mobius_mu_init2.hpp\"\n\n\n\n#include\
    \ <numeric>\n#include <vector>\n\n#line 1 \"include/emthrm/math/prime_sieve.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/prime_sieve.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <bool GETS_ONLY_PRIME>\nstd::vector<int> prime_sieve(const int n) {\n\
    \  std::vector<int> smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n\
    \      if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 8 \"include/emthrm/math/mobius_mu_init2.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<int> mobius_mu_init2(const long long low,\
    \ const long long high) {\n  std::vector<int> mu(high - low, 1);\n  std::vector<long\
    \ long> tmp(high - low);\n  std::iota(tmp.begin(), tmp.end(), low);\n  if (low\
    \ == 0 && high > 0) mu[0] = 0;\n  long long root = 1;\n  while ((root + 1) * (root\
    \ + 1) < high) ++root;\n  for (const int p : prime_sieve<true>(root)) {\n    for\
    \ (long long i = (low + p - 1) / p * p; i < high; i += p) {\n      if ((i / p)\
    \ % p == 0) {\n        mu[i - low] = tmp[i - low] = 0;\n      } else {\n     \
    \   mu[i - low] = -mu[i - low];\n        tmp[i - low] /= p;\n      }\n    }\n\
    \  }\n  for (int i = 0; i < high - low; ++i) {\n    if (tmp[i] > 1) mu[i] = -mu[i];\n\
    \  }\n  return mu;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_\n#define EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_\n\
    \n#include <numeric>\n#include <vector>\n\n#include \"emthrm/math/prime_sieve.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<int> mobius_mu_init2(const long long low,\
    \ const long long high) {\n  std::vector<int> mu(high - low, 1);\n  std::vector<long\
    \ long> tmp(high - low);\n  std::iota(tmp.begin(), tmp.end(), low);\n  if (low\
    \ == 0 && high > 0) mu[0] = 0;\n  long long root = 1;\n  while ((root + 1) * (root\
    \ + 1) < high) ++root;\n  for (const int p : prime_sieve<true>(root)) {\n    for\
    \ (long long i = (low + p - 1) / p * p; i < high; i += p) {\n      if ((i / p)\
    \ % p == 0) {\n        mu[i - low] = tmp[i - low] = 0;\n      } else {\n     \
    \   mu[i - low] = -mu[i - low];\n        tmp[i - low] /= p;\n      }\n    }\n\
    \  }\n  for (int i = 0; i < high - low; ++i) {\n    if (tmp[i] > 1) mu[i] = -mu[i];\n\
    \  }\n  return mu;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOBIUS_MU_INIT2_HPP_\n"
  dependsOn:
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: false
  path: include/emthrm/math/mobius_mu_init2.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mobius_mu_init2.test.cpp
documentation_of: include/emthrm/math/mobius_mu_init2.hpp
layout: document
title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 (M\xF6bius function) \u306E\u6570\u8868\
  2"
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

- A.F. Möbius: Über eine besondere Art von Umkehrung der Reihen, *誌名*, Vol. 9, pp. 105–123 (1832). https://doi.org/10.1515/crll.1832.9.105
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.265-268，マイナビ出版（2012）
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E3%81%AE%E5%8F%8D%E8%BB%A2%E5%85%AC%E5%BC%8F
- https://qiita.com/drken/items/3beb679e54266f20ab63#7-2-%E7%B4%84%E6%95%B0%E7%B3%BB%E5%8C%85%E9%99%A4%E5%8E%9F%E7%90%86
- https://github.com/spaghetti-source/algorithm/blob/e8fde0fea20e323f42e263376302494cda1ae7f7/number_theory/mobius_mu.cc


## TODO

- https://drive.google.com/drive/folders/1z4kUGi0ObnWPQwdzmH-IHG6oV-XCRYnL


## Submissons

- https://atcoder.jp/contests/abc162/submissions/26045975
- [約数版](https://atcoder.jp/contests/abc162/submissions/26046320)
- [数表](https://atcoder.jp/contests/abc162/submissions/26046042)
- [数表2](https://atcoder.jp/contests/abc162/submissions/26046148)
