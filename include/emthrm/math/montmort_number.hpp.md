---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/montmort_number.test.cpp
    title: "\u6570\u5B66/\u30E2\u30F3\u30E2\u30FC\u30EB\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/montmort_number.hpp\"\n\n\n\n#include\
    \ <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> montmort_number(const\
    \ int n) {\n  std::vector<T> montmort(n + 1, 0);\n  montmort[0] = 1;\n  for (int\
    \ i = 2; i <= n; ++i) {\n    montmort[i] = (montmort[i - 1] + montmort[i - 2])\
    \ * (i - 1);\n  }\n  return montmort;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_MONTMORT_NUMBER_HPP_\n#define EMTHRM_MATH_MONTMORT_NUMBER_HPP_\n\
    \n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T>\
    \ montmort_number(const int n) {\n  std::vector<T> montmort(n + 1, 0);\n  montmort[0]\
    \ = 1;\n  for (int i = 2; i <= n; ++i) {\n    montmort[i] = (montmort[i - 1] +\
    \ montmort[i - 2]) * (i - 1);\n  }\n  return montmort;\n}\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_MATH_MONTMORT_NUMBER_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/montmort_number.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/montmort_number.test.cpp
documentation_of: include/emthrm/math/montmort_number.hpp
layout: document
title: "\u30E2\u30F3\u30E2\u30FC\u30EB\u6570 (Montmort number)"
---

$$
  !n =
  \begin{cases}
    1 & (n = 0), \\
    0 & (n = 1), \\
    (n - 1)(!(n - 1) + !(n - 2)) & (n \geq 2)
  \end{cases}
$$

という漸化式をもつ、完全順列の個数 $!n$ である。これを解くと

$$
  !n = n! \sum_{k = 0}^n \dfrac{(-1)^k}{k!}
$$

という一般項が得られる。

指数型母関数は

$$
  \sum_{n = 0}^\infty !n \frac{x^n}{n!} = \dfrac{e^{-x}}{1 - x}
$$

である。


### 完全順列 (complete permutation) / 攪乱順列 (derangement)

大きさ $N$ の順列 $P$ の内、任意の $i \in \lbrace 1, 2, \ldots, N \rbrace$ に対して $P_i \neq i$ を満たすものである。


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T> std::vector<T> montmort_number(const int n);`|モンモール数 $!i$ ($1 \leq i \leq n$) の数表|


## 参考文献

- https://mathtrain.jp/montmort
- http://kyuridenamida.hatenablog.com/entry/2016/04/27/015414
- https://en.wikipedia.org/wiki/Derangement


## Submissons

https://judge.yosupo.jp/submission/2731
