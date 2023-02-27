---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_inv.hpp
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
  bundledCode: "#line 1 \"include/emthrm/math/simultaneous_linear_congruence.hpp\"\
    \n\n\n\n#include <numeric>\n#include <utility>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/math/mod_inv.hpp\"\n\n\n\n#line 6 \"include/emthrm/math/mod_inv.hpp\"\
    \n\nnamespace emthrm {\n\nlong long mod_inv(long long a, const int m) {\n  if\
    \ ((a %= m) < 0) a += m;\n  if (std::gcd(a, m) != 1) return -1;\n  long long x\
    \ = 1;\n  for (long long b = m, u = 0; b > 0;) {\n    const long long q = a /\
    \ b;\n    std::swap(a -= q * b, b);\n    std::swap(x -= q * u, u);\n  }\n  x %=\
    \ m;\n  return x < 0 ? x + m : x;\n}\n\n}  // namespace emthrm\n\n\n#line 9 \"\
    include/emthrm/math/simultaneous_linear_congruence.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename T>\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T>& a,\n                                               const std::vector<T>&\
    \ b,\n                                               const std::vector<T>& m)\
    \ {\n  const int n = a.size();\n  T x = 0, md = 1;\n  for (int i = 0; i < n; ++i)\
    \ {\n    const T p = md * a[i], q = -x * a[i] + b[i], g = std::gcd(p, m[i]);\n\
    \    if (q % g != 0) return {0, -1};\n    const T m_i = m[i] / g;\n    x += md\
    \ * (q / g * mod_inv(p / g, m_i) % m_i);\n    md *= m_i;\n  }\n  return {x < 0\
    \ ? x + md : x, md};\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_SIMULTANEOUS_LINEAR_CONGRUENCE_HPP_\n#define EMTHRM_MATH_SIMULTANEOUS_LINEAR_CONGRUENCE_HPP_\n\
    \n#include <numeric>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/math/mod_inv.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T>& a,\n                                               const std::vector<T>&\
    \ b,\n                                               const std::vector<T>& m)\
    \ {\n  const int n = a.size();\n  T x = 0, md = 1;\n  for (int i = 0; i < n; ++i)\
    \ {\n    const T p = md * a[i], q = -x * a[i] + b[i], g = std::gcd(p, m[i]);\n\
    \    if (q % g != 0) return {0, -1};\n    const T m_i = m[i] / g;\n    x += md\
    \ * (q / g * mod_inv(p / g, m_i) % m_i);\n    md *= m_i;\n  }\n  return {x < 0\
    \ ? x + md : x, md};\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_SIMULTANEOUS_LINEAR_CONGRUENCE_HPP_\n"
  dependsOn:
  - include/emthrm/math/mod_inv.hpp
  isVerificationFile: false
  path: include/emthrm/math/simultaneous_linear_congruence.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/simultaneous_linear_congruence.test.cpp
documentation_of: include/emthrm/math/simultaneous_linear_congruence.hpp
layout: document
title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
---

$$
  A_i x \equiv B_i \pmod{M_i}
$$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::pair<T, T> simultaneous_linear_congruence(const std::vector<T>& a, const std::vector<T>& b, const std::vector<T>& m);`|$A_i x \equiv B_i \pmod{M_i}$ を満たす $mk + x$ ($k \in \mathbb{Z},\ 0 \leq x < m$)。ただし存在しないときは $(0, -1)$ を返す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.261-262，マイナビ出版（2012）


## Submissons

https://yukicoder.me/submissions/701737
