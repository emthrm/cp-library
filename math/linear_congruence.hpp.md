---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/linear_congruence.test.cpp
    title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/linear_congruence.hpp\"\n#include <algorithm>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n#line 4 \"math/mod_inv.hpp\"\n\r\nlong long\
    \ mod_inv(long long a, int m) {\r\n  if ((a %= m) < 0) a += m;\r\n  if (std::__gcd(a,\
    \ static_cast<long long>(m)) != 1) return -1;\r\n  long long b = m, x = 1, u =\
    \ 0;\r\n  while (b > 0) {\r\n    long long q = a / b;\r\n    std::swap(a -= q\
    \ * b, b);\r\n    std::swap(x -= q * u, u);\r\n  }\r\n  x %= m;\r\n  return x\
    \ < 0 ? x + m : x;\r\n}\r\n#line 6 \"math/linear_congruence.hpp\"\n\r\ntemplate\
    \ <typename T>\r\nstd::pair<long long, long long> linear_congruence(const std::vector<T>\
    \ &a, const std::vector<T> &b, const std::vector<T> &m) {\r\n  long long x = 0,\
    \ mod = 1;\r\n  int n = a.size();\r\n  for (int i = 0; i < n; ++i) {\r\n    long\
    \ long l = mod * a[i], r = -x * a[i] + b[i], g = std::__gcd(l, static_cast<long\
    \ long>(m[i]));\r\n    if (r % g != 0) return {0, -1};\r\n    x += mod * (r /\
    \ g * mod_inv(l / g, m[i] / g) % (m[i] / g));\r\n    mod *= m[i] / g;\r\n  }\r\
    \n  return {x < 0 ? x + mod : x, mod};\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"mod_inv.hpp\"\r\n\r\ntemplate <typename T>\r\nstd::pair<long long,\
    \ long long> linear_congruence(const std::vector<T> &a, const std::vector<T> &b,\
    \ const std::vector<T> &m) {\r\n  long long x = 0, mod = 1;\r\n  int n = a.size();\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    long long l = mod * a[i], r = -x * a[i]\
    \ + b[i], g = std::__gcd(l, static_cast<long long>(m[i]));\r\n    if (r % g !=\
    \ 0) return {0, -1};\r\n    x += mod * (r / g * mod_inv(l / g, m[i] / g) % (m[i]\
    \ / g));\r\n    mod *= m[i] / g;\r\n  }\r\n  return {x < 0 ? x + mod : x, mod};\r\
    \n}\r\n"
  dependsOn:
  - math/mod_inv.hpp
  isVerificationFile: false
  path: math/linear_congruence.hpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/linear_congruence.test.cpp
documentation_of: math/linear_congruence.hpp
layout: document
title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (linear congruence)"
---

$$A_i x \equiv B_i \pmod{M_i} \ (i = 1, 2,\ldots, N) \text{．}$$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`linear_congruence(a, b, m)`|$mk + x \ (k \in \mathbb{Z}) \text{ s.t. } A_i x \equiv B_i \pmod{M_i}$|存在しない場合は $(0, -1)$ となる．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.261-262


## Verified

https://atcoder.jp/contests/ddcc2019-qual/submissions/9318157
