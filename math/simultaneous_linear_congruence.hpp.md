---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/simultaneous_linear_congruence.test.cpp
    title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/simultaneous_linear_congruence.hpp\"\n#include <algorithm>\r\
    \n#include <utility>\r\n#include <vector>\r\n#line 4 \"math/mod_inv.hpp\"\n\r\n\
    long long mod_inv(long long a, int m) {\r\n  if ((a %= m) < 0) a += m;\r\n  if\
    \ (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;\r\n  long long b\
    \ = m, x = 1, u = 0;\r\n  while (b > 0) {\r\n    long long q = a / b;\r\n    std::swap(a\
    \ -= q * b, b);\r\n    std::swap(x -= q * u, u);\r\n  }\r\n  x %= m;\r\n  return\
    \ x < 0 ? x + m : x;\r\n}\r\n#line 6 \"math/simultaneous_linear_congruence.hpp\"\
    \n\r\ntemplate <typename T>\r\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T> &a, const std::vector<T> &b, const std::vector<T> &m) {\r\n \
    \ const int n = a.size();\r\n  T x = 0, md = 1;\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    const T l = md * a[i], r = -x * a[i] + b[i], g = std::__gcd(l, m[i]);\r\
    \n    if (r % g != 0) return {0, -1};\r\n    x += md * (r / g * mod_inv(l / g,\
    \ m[i] / g) % (m[i] / g));\r\n    md *= m[i] / g;\r\n  }\r\n  return {x < 0 ?\
    \ x + md : x, md};\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"mod_inv.hpp\"\r\n\r\ntemplate <typename T>\r\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T> &a, const std::vector<T> &b, const std::vector<T> &m) {\r\n \
    \ const int n = a.size();\r\n  T x = 0, md = 1;\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    const T l = md * a[i], r = -x * a[i] + b[i], g = std::__gcd(l, m[i]);\r\
    \n    if (r % g != 0) return {0, -1};\r\n    x += md * (r / g * mod_inv(l / g,\
    \ m[i] / g) % (m[i] / g));\r\n    md *= m[i] / g;\r\n  }\r\n  return {x < 0 ?\
    \ x + md : x, md};\r\n}\r\n"
  dependsOn:
  - math/mod_inv.hpp
  isVerificationFile: false
  path: math/simultaneous_linear_congruence.hpp
  requiredBy: []
  timestamp: '2021-09-24 15:41:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/simultaneous_linear_congruence.test.cpp
documentation_of: math/simultaneous_linear_congruence.hpp
layout: document
title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
---

$$A_i x \equiv B_i \pmod{M_i} \ (i = 1, 2,\ldots, N) \text{．}$$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`simultaneous_linear_congruence(a, b, m)`|$mk + x \ (k \in \mathbb{Z},\ 0 \leq x < m) \text{ s.t. } A_i x \equiv B_i \pmod{M_i}$|存在しない場合は $(0, -1)$ となる．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.261-262，マイナビ出版（2012）．


## Verified

https://yukicoder.me/submissions/701737
