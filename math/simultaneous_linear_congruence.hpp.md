---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/simultaneous_linear_congruence.test.cpp
    title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/simultaneous_linear_congruence.hpp\"\n#include <algorithm>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\n#line 4 \"math/mod_inv.hpp\"\n\
    \r\nlong long mod_inv(long long a, const int m) {\r\n  if ((a %= m) < 0) a +=\
    \ m;\r\n  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;\r\n  long\
    \ long x = 1;\r\n  for (long long b = m, u = 0; b > 0;) {\r\n    const long long\
    \ q = a / b;\r\n    std::swap(a -= q * b, b);\r\n    std::swap(x -= q * u, u);\r\
    \n  }\r\n  x %= m;\r\n  return x < 0 ? x + m : x;\r\n}\r\n#line 7 \"math/simultaneous_linear_congruence.hpp\"\
    \n\r\ntemplate <typename T>\r\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T>& a,\r\n                                               const std::vector<T>&\
    \ b,\r\n                                               const std::vector<T>& m)\
    \ {\r\n  const int n = a.size();\r\n  T x = 0, md = 1;\r\n  for (int i = 0; i\
    \ < n; ++i) {\r\n    const T p = md * a[i], q = -x * a[i] + b[i], g = std::__gcd(p,\
    \ m[i]);\r\n    if (q % g != 0) return {0, -1};\r\n    const T m_i = m[i] / g;\r\
    \n    x += md * (q / g * mod_inv(p / g, m_i) % m_i);\r\n    md *= m_i;\r\n  }\r\
    \n  return {x < 0 ? x + md : x, md};\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\n#include \"mod_inv.hpp\"\r\n\r\ntemplate <typename T>\r\nstd::pair<T, T>\
    \ simultaneous_linear_congruence(const std::vector<T>& a,\r\n                \
    \                               const std::vector<T>& b,\r\n                 \
    \                              const std::vector<T>& m) {\r\n  const int n = a.size();\r\
    \n  T x = 0, md = 1;\r\n  for (int i = 0; i < n; ++i) {\r\n    const T p = md\
    \ * a[i], q = -x * a[i] + b[i], g = std::__gcd(p, m[i]);\r\n    if (q % g != 0)\
    \ return {0, -1};\r\n    const T m_i = m[i] / g;\r\n    x += md * (q / g * mod_inv(p\
    \ / g, m_i) % m_i);\r\n    md *= m_i;\r\n  }\r\n  return {x < 0 ? x + md : x,\
    \ md};\r\n}\r\n"
  dependsOn:
  - math/mod_inv.hpp
  isVerificationFile: false
  path: math/simultaneous_linear_congruence.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/simultaneous_linear_congruence.test.cpp
documentation_of: math/simultaneous_linear_congruence.hpp
layout: document
title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
---

$$A_i x \equiv B_i \pmod{M_i}$$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`simultaneous_linear_congruence(a, b, m)`|$A_i x \equiv B_i \pmod{M_i}$ を満たす $mk + x$ ($k \in \mathbb{Z},\ 0 \leq x < m$)|存在しないときは $(0, -1)$ となる．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.261-262，マイナビ出版（2012）


## Verified

https://yukicoder.me/submissions/701737
