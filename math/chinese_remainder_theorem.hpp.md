---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/chinese_remainder_theorem.test.cpp
    title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/chinese_remainder_theorem.hpp\"\n#include <algorithm>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\n#line 4 \"math/mod_inv.hpp\"\n\
    \r\nlong long mod_inv(long long a, const int m) {\r\n  if ((a %= m) < 0) a +=\
    \ m;\r\n  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;\r\n  long\
    \ long x = 1;\r\n  for (long long b = m, u = 0; b > 0;) {\r\n    const long long\
    \ q = a / b;\r\n    std::swap(a -= q * b, b);\r\n    std::swap(x -= q * u, u);\r\
    \n  }\r\n  x %= m;\r\n  return x < 0 ? x + m : x;\r\n}\r\n#line 7 \"math/chinese_remainder_theorem.hpp\"\
    \n\r\ntemplate <typename T>\r\nstd::pair<T, T> chinese_remainder_theorem(std::vector<T>\
    \ b, std::vector<T> m) {\r\n  const int n = b.size();\r\n  T x = 0, md = 1;\r\n\
    \  for (int i = 0; i < n; ++i) {\r\n    if ((b[i] %= m[i]) < 0) b[i] += m[i];\r\
    \n    if (md < m[i]) {\r\n      std::swap(x, b[i]);\r\n      std::swap(md, m[i]);\r\
    \n    }\r\n    if (md % m[i] == 0) {\r\n      if (x % m[i] != b[i]) return {0,\
    \ 0};\r\n      continue;\r\n    }\r\n    const T g = std::__gcd(md, m[i]);\r\n\
    \    if ((b[i] - x) % g != 0) return {0, 0};\r\n    const T u_i = m[i] / g;\r\n\
    \    x += (b[i] - x) / g % u_i * mod_inv(md / g, u_i) % u_i * md;\r\n    md *=\
    \ u_i;\r\n    if (x < 0) x += md;\r\n  }\r\n  return {x, md};\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\n#include \"mod_inv.hpp\"\r\n\r\ntemplate <typename T>\r\nstd::pair<T, T>\
    \ chinese_remainder_theorem(std::vector<T> b, std::vector<T> m) {\r\n  const int\
    \ n = b.size();\r\n  T x = 0, md = 1;\r\n  for (int i = 0; i < n; ++i) {\r\n \
    \   if ((b[i] %= m[i]) < 0) b[i] += m[i];\r\n    if (md < m[i]) {\r\n      std::swap(x,\
    \ b[i]);\r\n      std::swap(md, m[i]);\r\n    }\r\n    if (md % m[i] == 0) {\r\
    \n      if (x % m[i] != b[i]) return {0, 0};\r\n      continue;\r\n    }\r\n \
    \   const T g = std::__gcd(md, m[i]);\r\n    if ((b[i] - x) % g != 0) return {0,\
    \ 0};\r\n    const T u_i = m[i] / g;\r\n    x += (b[i] - x) / g % u_i * mod_inv(md\
    \ / g, u_i) % u_i * md;\r\n    md *= u_i;\r\n    if (x < 0) x += md;\r\n  }\r\n\
    \  return {x, md};\r\n}\r\n"
  dependsOn:
  - math/mod_inv.hpp
  isVerificationFile: false
  path: math/chinese_remainder_theorem.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/chinese_remainder_theorem.test.cpp
documentation_of: math/chinese_remainder_theorem.hpp
layout: document
title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
---

連立合同式 $x \equiv b_i \pmod{m_i}$ ($i = 1, 2,\ldots, n$) が与えられる．

任意の $i, j \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $m_i \perp m_j$ が成り立つならば，連立合同式を満たす $x \bmod{\prod_{i = 1}^n m_i}$ が一意に存在する．

これを任意の $i, j \in \lbrace 1, 2, \ldots, n \rbrace$ に対して $b_i \equiv b_j \pmod{\gcd(m_i, m_j)}$ が成り立つときに拡張すると，連立合同式を満たす $x \bmod{\mathrm{lcm}(m_1, m_2,..., m_n)}$ が一意に存在する．


## 時間計算量

$O(N \log{\mathrm{lcm}(m_1, m_2, \ldots, m_N)})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`chinese_remainder_theorem(b, m)`|$x \equiv b_i \pmod{m_i}$ を満たす $x$ と $\mathrm{lcm}(m_1, m_2,..., m_n)$ の組|$0 \leq x < \mathrm{lcm}(m_1, m_2,..., m_n)$<br>存在しないときは $(0, 0)$ となる．|


## 参考

- https://rsk0315.hatenablog.com/entry/2021/01/18/065720#crt
- https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp#L33-L80
- https://qiita.com/drken/items/ae02240cd1f8edfc86fd
- https://mathtrain.jp/remainder


## ToDo

- Garner のアルゴリズム
  - https://qiita.com/drken/items/ae02240cd1f8edfc86fd
  - https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/garner.cpp
  - https://www.creativ.xyz/ect-gcd-crt-garner-927/
  - http://kirika-comp.hatenablog.com/entry/2017/12/18/143923
  - ~~http://sugarknri.hatenablog.com/entry/2018/06/28/144407~~
  - ~~https://lumakernel.github.io/ecasdqina/math/number-theory/Garner~~
  - https://cp-algorithms.com/algebra/chinese-remainder-theorem.html
  - http://flex.phys.tohoku.ac.jp/~maru/implementations/garner.php


## Verified

https://yukicoder.me/submissions/630411
