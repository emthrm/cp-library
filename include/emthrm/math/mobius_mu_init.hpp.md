---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/mobius_mu_init.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570\u306E\u6570\u8868"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/mobius_mu_init.hpp\"\n\n\n\n#include\
    \ <vector>\n\nnamespace emthrm {\n\nstd::vector<int> mobius_mu_init(const int\
    \ n) {\n  std::vector<bool> is_prime(n + 1, true);\n  is_prime[0] = false;\n \
    \ if (n >= 1) [[likely]] is_prime[1] = false;\n  std::vector<int> mu(n + 1, 1);\n\
    \  mu[0] = 0;\n  for (int i = 2; i <= n; ++i) {\n    if (is_prime[i]) [[unlikely]]\
    \ {\n      mu[i] = -mu[i];\n      for (int j = i * 2; j <= n; j += i) {\n    \
    \    is_prime[j] = false;\n        mu[j] = ((j / i) % i == 0 ? 0 : -mu[j]);\n\
    \      }\n    }\n  }\n  return mu;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_MOBIUS_MU_INIT_HPP_\n#define EMTHRM_MATH_MOBIUS_MU_INIT_HPP_\n\
    \n#include <vector>\n\nnamespace emthrm {\n\nstd::vector<int> mobius_mu_init(const\
    \ int n) {\n  std::vector<bool> is_prime(n + 1, true);\n  is_prime[0] = false;\n\
    \  if (n >= 1) [[likely]] is_prime[1] = false;\n  std::vector<int> mu(n + 1, 1);\n\
    \  mu[0] = 0;\n  for (int i = 2; i <= n; ++i) {\n    if (is_prime[i]) [[unlikely]]\
    \ {\n      mu[i] = -mu[i];\n      for (int j = i * 2; j <= n; j += i) {\n    \
    \    is_prime[j] = false;\n        mu[j] = ((j / i) % i == 0 ? 0 : -mu[j]);\n\
    \      }\n    }\n  }\n  return mu;\n}\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_MATH_MOBIUS_MU_INIT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/mobius_mu_init.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mobius_mu_init.test.cpp
documentation_of: include/emthrm/math/mobius_mu_init.hpp
layout: document
title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 (M\xF6bius function) \u306E\u6570\u8868"
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
