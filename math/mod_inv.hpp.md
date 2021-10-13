---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/chinese_remainder_theorem.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
  - icon: ':heavy_check_mark:'
    path: math/simultaneous_linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/chinese_remainder_theorem.test.cpp
    title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: test/math/simultaneous_linear_congruence.test.cpp
    title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_inv.hpp\"\n#include <algorithm>\r\n#include <utility>\r\
    \n\r\nlong long mod_inv(long long a, int m) {\r\n  if ((a %= m) < 0) a += m;\r\
    \n  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;\r\n  long long\
    \ b = m, x = 1, u = 0;\r\n  while (b > 0) {\r\n    long long q = a / b;\r\n  \
    \  std::swap(a -= q * b, b);\r\n    std::swap(x -= q * u, u);\r\n  }\r\n  x %=\
    \ m;\r\n  return x < 0 ? x + m : x;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n\r\nlong long\
    \ mod_inv(long long a, int m) {\r\n  if ((a %= m) < 0) a += m;\r\n  if (std::__gcd(a,\
    \ static_cast<long long>(m)) != 1) return -1;\r\n  long long b = m, x = 1, u =\
    \ 0;\r\n  while (b > 0) {\r\n    long long q = a / b;\r\n    std::swap(a -= q\
    \ * b, b);\r\n    std::swap(x -= q * u, u);\r\n  }\r\n  x %= m;\r\n  return x\
    \ < 0 ? x + m : x;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_inv.hpp
  requiredBy:
  - math/simultaneous_linear_congruence.hpp
  - math/chinese_remainder_theorem.hpp
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/chinese_remainder_theorem.test.cpp
  - test/math/simultaneous_linear_congruence.test.cpp
documentation_of: math/mod_inv.hpp
layout: document
title: "\u9006\u5143 (inverse element)"
---

$ax \equiv 1 \pmod{m}$ を満たす $x = a^{-1}$．

1. $a^{-1}$ が存在するとき $\exists y \in \mathbb{Z}, a \cdot a^{-1} + my = 1$ が成り立つ．[拡張 Euclid の互除法](ext_gcd.md)を用い，時間計算量 $O(\log{M})$ で $(a^{-1}, y)$ を求められる．
2. Fermat の小定理より，$m \in \mathbb{P}$ かつ $a \perp m$ を満たすとき $a^{-1} \equiv a^{m - 2} \pmod{m}$ が成り立つ．時間計算量 $O(\log{M})$ で求められる．
3. [オイラーの定理](euler_phi/euler_phi.md###オイラーの定理)より，$a \perp m$ を満たすとき $a^{-1} \equiv a^{\varphi(m) - 1} \pmod{m}$ が成り立つ．時間計算量 $O(\sqrt{M})$ で求められる．


## 時間計算量

$O(\log{M})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`mod_inv(a, m)`|$a$ の逆元|存在しない場合は $-1$ となる．|


## 参考

- https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
- https://github.com/kirika-comp/articles/blob/c16612f266202ec6ce0f462601dd4db110add534/pre-seisuuron.pdf
