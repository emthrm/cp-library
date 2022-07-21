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
  bundledCode: "#line 2 \"math/simultaneous_linear_congruence.hpp\"\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\n#line 4 \"math/mod_inv.hpp\"\n\nlong\
    \ long mod_inv(long long a, const int m) {\n  if ((a %= m) < 0) a += m;\n  if\
    \ (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;\n  long long x =\
    \ 1;\n  for (long long b = m, u = 0; b > 0;) {\n    const long long q = a / b;\n\
    \    std::swap(a -= q * b, b);\n    std::swap(x -= q * u, u);\n  }\n  x %= m;\n\
    \  return x < 0 ? x + m : x;\n}\n#line 7 \"math/simultaneous_linear_congruence.hpp\"\
    \n\ntemplate <typename T>\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T>& a,\n                                               const std::vector<T>&\
    \ b,\n                                               const std::vector<T>& m)\
    \ {\n  const int n = a.size();\n  T x = 0, md = 1;\n  for (int i = 0; i < n; ++i)\
    \ {\n    const T p = md * a[i], q = -x * a[i] + b[i], g = std::__gcd(p, m[i]);\n\
    \    if (q % g != 0) return {0, -1};\n    const T m_i = m[i] / g;\n    x += md\
    \ * (q / g * mod_inv(p / g, m_i) % m_i);\n    md *= m_i;\n  }\n  return {x < 0\
    \ ? x + md : x, md};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \n#include \"./mod_inv.hpp\"\n\ntemplate <typename T>\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T>& a,\n                                               const std::vector<T>&\
    \ b,\n                                               const std::vector<T>& m)\
    \ {\n  const int n = a.size();\n  T x = 0, md = 1;\n  for (int i = 0; i < n; ++i)\
    \ {\n    const T p = md * a[i], q = -x * a[i] + b[i], g = std::__gcd(p, m[i]);\n\
    \    if (q % g != 0) return {0, -1};\n    const T m_i = m[i] / g;\n    x += md\
    \ * (q / g * mod_inv(p / g, m_i) % m_i);\n    md *= m_i;\n  }\n  return {x < 0\
    \ ? x + md : x, md};\n}\n"
  dependsOn:
  - math/mod_inv.hpp
  isVerificationFile: false
  path: math/simultaneous_linear_congruence.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/simultaneous_linear_congruence.test.cpp
documentation_of: math/simultaneous_linear_congruence.hpp
layout: document
title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
---

$$
  A_i x \equiv B_i \pmod{M_i}
$$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`simultaneous_linear_congruence(a, b, m)`|$A_i x \equiv B_i \pmod{M_i}$ を満たす $mk + x$ ($k \in \mathbb{Z},\ 0 \leq x < m$)|存在しないときは $(0, -1)$ となる．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.261-262，マイナビ出版（2012）


## Verified

https://yukicoder.me/submissions/701737
