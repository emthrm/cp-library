---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/mod_log.test.cpp
    title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_log.hpp\"\n#include <map>\n\n#line 2 \"math/mod_pow.hpp\"\
    \n\nlong long mod_pow(long long x, long long n, const int m) {\n  if ((x %= m)\
    \ < 0) x += m;\n  long long res = 1;\n  for (; n > 0; n >>= 1) {\n    if (n &\
    \ 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return res;\n}\n#line\
    \ 5 \"math/mod_log.hpp\"\n\nint mod_log(long long g, long long y, const int m)\
    \ {\n  if (m == 1) return 0;\n  if ((g %= m) < 0) g += m;\n  if ((y %= m) < 0)\
    \ y += m;\n  if (g == 0) {\n    if (y == 1) return 0;\n    if (y == 0) return\
    \ 1;\n    return -1;\n  }\n  int root = 1;\n  while (root * root < m) ++root;\n\
    \  std::map<long long, int> baby;\n  long long p = 1;\n  for (int i = 0; i < root;\
    \ ++i) {\n    if (p == y) return i;\n    baby[p * y % m] = i;\n    p = (p * g)\
    \ % m;\n  }\n  long long brute_force = p;\n  for (int i = root; i < 100; ++i)\
    \ {\n    if (i == m) return -1;\n    if (brute_force == y) return i;\n    brute_force\
    \ = (brute_force * g) % m;\n  }\n  long long giant = p;\n  for (int i = 1; i <=\
    \ root; ++i) {\n    if (baby.count(giant) == 1) {\n      const int ans = static_cast<long\
    \ long>(i) * root - baby[giant];\n      if (mod_pow(g, ans, m) == y) return ans;\n\
    \    }\n    giant = (giant * p) % m;\n  }\n  return -1;\n}\n"
  code: "#pragma once\n#include <map>\n\n#include \"./mod_pow.hpp\"\n\nint mod_log(long\
    \ long g, long long y, const int m) {\n  if (m == 1) return 0;\n  if ((g %= m)\
    \ < 0) g += m;\n  if ((y %= m) < 0) y += m;\n  if (g == 0) {\n    if (y == 1)\
    \ return 0;\n    if (y == 0) return 1;\n    return -1;\n  }\n  int root = 1;\n\
    \  while (root * root < m) ++root;\n  std::map<long long, int> baby;\n  long long\
    \ p = 1;\n  for (int i = 0; i < root; ++i) {\n    if (p == y) return i;\n    baby[p\
    \ * y % m] = i;\n    p = (p * g) % m;\n  }\n  long long brute_force = p;\n  for\
    \ (int i = root; i < 100; ++i) {\n    if (i == m) return -1;\n    if (brute_force\
    \ == y) return i;\n    brute_force = (brute_force * g) % m;\n  }\n  long long\
    \ giant = p;\n  for (int i = 1; i <= root; ++i) {\n    if (baby.count(giant) ==\
    \ 1) {\n      const int ans = static_cast<long long>(i) * root - baby[giant];\n\
    \      if (mod_pow(g, ans, m) == y) return ans;\n    }\n    giant = (giant * p)\
    \ % m;\n  }\n  return -1;\n}\n"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/mod_log.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

- Pohlig–Hellman algorithm
  - http://sonickun.hatenablog.com/entry/2016/11/20/192743
  - https://yukicoder.me/problems/no/950
  - https://twitter.com/nuo_chocorusk/status/1205509988912783360
  - https://twitter.com/maspy_stars/status/1205499459993362432


## Verified

https://judge.yosupo.jp/submission/3457
