---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/chinese_remainder_theorem.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
  - icon: ':x:'
    path: math/simultaneous_linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/chinese_remainder_theorem.test.cpp
    title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  - icon: ':x:'
    path: test/math/simultaneous_linear_congruence.test.cpp
    title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_inv.hpp\"\n#include <algorithm>\r\n#include <utility>\r\
    \n\r\nlong long mod_inv(long long a, const int m) {\r\n  if ((a %= m) < 0) a +=\
    \ m;\r\n  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;\r\n  long\
    \ long x = 1;\r\n  for (long long b = m, u = 0; b > 0;) {\r\n    const long long\
    \ q = a / b;\r\n    std::swap(a -= q * b, b);\r\n    std::swap(x -= q * u, u);\r\
    \n  }\r\n  x %= m;\r\n  return x < 0 ? x + m : x;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n\r\nlong long\
    \ mod_inv(long long a, const int m) {\r\n  if ((a %= m) < 0) a += m;\r\n  if (std::__gcd(a,\
    \ static_cast<long long>(m)) != 1) return -1;\r\n  long long x = 1;\r\n  for (long\
    \ long b = m, u = 0; b > 0;) {\r\n    const long long q = a / b;\r\n    std::swap(a\
    \ -= q * b, b);\r\n    std::swap(x -= q * u, u);\r\n  }\r\n  x %= m;\r\n  return\
    \ x < 0 ? x + m : x;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_inv.hpp
  requiredBy:
  - math/chinese_remainder_theorem.hpp
  - math/simultaneous_linear_congruence.hpp
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/simultaneous_linear_congruence.test.cpp
  - test/math/chinese_remainder_theorem.test.cpp
documentation_of: math/mod_inv.hpp
layout: document
title: "\u9006\u5143 (inverse element)"
---

$ax \equiv 1 \pmod{m}$ を満たす $x = a^{-1}$ である．
- $a^{-1}$ が存在するとき $a \cdot a^{-1} + my = 1$ を満たす $y \in \mathbb{Z}$ が存在する．[拡張 Euclid の互除法](ext_gcd.md)を用い，時間計算量 $O(\log{M})$ で $(a^{-1}, y)$ を求められる．
- Fermat の小定理より，$m \in \mathbb{P}$ かつ $a \perp m$ を満たすとき $a^{-1} \equiv a^{m - 2} \pmod{m}$ が成り立つ．時間計算量 $O(\log{M})$ で求められる．
- [オイラーの定理](euler_phi/euler_phi.md###オイラーの定理)より，$a \perp m$ を満たすとき $a^{-1} \equiv a^{\varphi(m) - 1} \pmod{m}$ が成り立つ．時間計算量 $O(\sqrt{M})$ で求められる．


## 時間計算量

$O(\log{M})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`mod_inv(a, m)`|$a$ の逆元|存在しないときは $-1$ となる．|


## 参考

- https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
- https://github.com/kirika-comp/articles/blob/c16612f266202ec6ce0f462601dd4db110add534/pre-seisuuron.pdf
