---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_quotients.test.cpp
    title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/enumerate_quotients.hpp\"\n\n\n\n#include\
    \ <tuple>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    std::vector<std::tuple<T, T, T>> enumerate_quotients(const T n) {\n  std::vector<std::tuple<T,\
    \ T, T>> quotients;\n  for (T l = 1; l <= n;) {\n    const T quotient = n / l,\
    \ r = n / quotient + 1;\n    quotients.emplace_back(l, r, quotient);\n    l =\
    \ r;\n  }\n  return quotients;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_ENUMERATE_QUOTIENTS_HPP_\n#define EMTHRM_MATH_ENUMERATE_QUOTIENTS_HPP_\n\
    \n#include <tuple>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T>\nstd::vector<std::tuple<T, T, T>> enumerate_quotients(const T n) {\n  std::vector<std::tuple<T,\
    \ T, T>> quotients;\n  for (T l = 1; l <= n;) {\n    const T quotient = n / l,\
    \ r = n / quotient + 1;\n    quotients.emplace_back(l, r, quotient);\n    l =\
    \ r;\n  }\n  return quotients;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_ENUMERATE_QUOTIENTS_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/enumerate_quotients.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/enumerate_quotients.test.cpp
documentation_of: include/emthrm/math/enumerate_quotients.hpp
layout: document
title: "\u5546\u306E\u5217\u6319"
---


## 時間計算量

$O(\sqrt{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T> std::vector<std::tuple<T, T, T>> enumerate_quotients(const T n);`|$\lbrace (l, r, q) \mid \forall x \in \lbrace l, l + 1, \ldots, r - 1 \rbrace,\ \lfloor \frac{n}{x} \rfloor = q \rbrace$|


## 備考

1. $\left\lfloor \frac{N}{i} \right\rfloor = q$ を満たす $i$ の範囲は $\left(\left\lfloor \frac{N}{q + 1} \right\rfloor, \left\lfloor \frac{N}{q} \right\rfloor \right\rbrack$ を満たす。
2. $N \in \mathbb{N}^+$ に対して商を昇順に並べたものを $Q \mathrel{:=} (q_1, q_2, \ldots, q_k)$ ($k \in \mathbb{N}^+,\ q_1 < q_2 < \cdots < q_k$) とおく。$x \in Q$ に対して
   - $x^2 \leq N$ ならば $x = q_x$ が成り立ち、
   - $x^2 \geq N$ ならば $x = q_{k + 1 - N / x}$ が成り立つ。


## 参考文献

- https://twitter.com/noshi91/status/1278227768333852672

備考1
- https://twitter.com/heno_code/status/1495040694527741954

備考2
- https://twitter.com/maspy_stars/status/1495039893172412421


## Submissons

https://atcoder.jp/contests/abc230/submissions/28839379
