---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/mod_log.test.cpp
    title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_log.hpp\"\n#include <cmath>\r\n#include <map>\r\
    \n\r\n#line 2 \"math/mod_pow.hpp\"\n\r\nlong long mod_pow(long long x, long long\
    \ n, const int m) {\r\n  if ((x %= m) < 0) x += m;\r\n  long long res = 1;\r\n\
    \  for (; n > 0; n >>= 1) {\r\n    if (n & 1) res = (res * x) % m;\r\n    x =\
    \ (x * x) % m;\r\n  }\r\n  return res;\r\n}\r\n#line 6 \"math/mod_log.hpp\"\n\r\
    \nint mod_log(long long g, long long y, const int m) {\r\n  if (m == 1) return\
    \ 0;\r\n  if ((g %= m) < 0) g += m;\r\n  if ((y %= m) < 0) y += m;\r\n  if (g\
    \ == 0) {\r\n    if (y == 1) return 0;\r\n    if (y == 0) return 1;\r\n    return\
    \ -1;\r\n  }\r\n  const int root = std::ceil(std::sqrt(m));\r\n  std::map<long\
    \ long, int> baby;\r\n  long long p = 1;\r\n  for (int i = 0; i < root; ++i) {\r\
    \n    if (p == y) return i;\r\n    baby[p * y % m] = i;\r\n    p = (p * g) % m;\r\
    \n  }\r\n  long long brute_force = p;\r\n  for (int i = root; i < 100; ++i) {\r\
    \n    if (i == m) return -1;\r\n    if (brute_force == y) return i;\r\n    brute_force\
    \ = (brute_force * g) % m;\r\n  }\r\n  long long giant = p;\r\n  for (int i =\
    \ 1; i <= root; ++i) {\r\n    if (baby.count(giant) == 1) {\r\n      const int\
    \ ans = static_cast<long long>(i) * root - baby[giant];\r\n      if (mod_pow(g,\
    \ ans, m) == y) return ans;\r\n    }\r\n    giant = (giant * p) % m;\r\n  }\r\n\
    \  return -1;\r\n}\r\n"
  code: "#pragma once\r\n#include <cmath>\r\n#include <map>\r\n\r\n#include \"mod_pow.hpp\"\
    \r\n\r\nint mod_log(long long g, long long y, const int m) {\r\n  if (m == 1)\
    \ return 0;\r\n  if ((g %= m) < 0) g += m;\r\n  if ((y %= m) < 0) y += m;\r\n\
    \  if (g == 0) {\r\n    if (y == 1) return 0;\r\n    if (y == 0) return 1;\r\n\
    \    return -1;\r\n  }\r\n  const int root = std::ceil(std::sqrt(m));\r\n  std::map<long\
    \ long, int> baby;\r\n  long long p = 1;\r\n  for (int i = 0; i < root; ++i) {\r\
    \n    if (p == y) return i;\r\n    baby[p * y % m] = i;\r\n    p = (p * g) % m;\r\
    \n  }\r\n  long long brute_force = p;\r\n  for (int i = root; i < 100; ++i) {\r\
    \n    if (i == m) return -1;\r\n    if (brute_force == y) return i;\r\n    brute_force\
    \ = (brute_force * g) % m;\r\n  }\r\n  long long giant = p;\r\n  for (int i =\
    \ 1; i <= root; ++i) {\r\n    if (baby.count(giant) == 1) {\r\n      const int\
    \ ans = static_cast<long long>(i) * root - baby[giant];\r\n      if (mod_pow(g,\
    \ ans, m) == y) return ans;\r\n    }\r\n    giant = (giant * p) % m;\r\n  }\r\n\
    \  return -1;\r\n}\r\n"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/mod_log.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/mod_log.test.cpp
documentation_of: math/mod_log.hpp
layout: document
title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
---

$g^x \equiv y \pmod{p}$ ($g = \text{const.},\ y \in \mathbb{Z},\ p \in \mathbb{P}$) を満たす $x$ を求める問題である．


## 時間計算量

$O(\sqrt{P} \log{P})$


## 使用法

- baby-step giant-step

||説明|備考|
|:--:|:--:|:--:|
|`mod_log(g, y, m)`|$g^x \equiv y \pmod{m}$ を満たす最小の非負整数 $x$|存在しないときは $-1$ となる．|


## 参考

- http://sonickun.hatenablog.com/entry/2016/11/20/192743


## ToDo

- Pohlig-Hellman algorithm
  - http://sonickun.hatenablog.com/entry/2016/11/20/192743
  - https://yukicoder.me/problems/no/950
  - https://twitter.com/nuo_chocorusk/status/1205509988912783360
  - https://twitter.com/maspy_stars/status/1205499459993362432


## Verified

https://judge.yosupo.jp/submission/3457
