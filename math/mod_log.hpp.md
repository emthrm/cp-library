---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
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
  bundledCode: "#line 2 \"math/mod_log.hpp\"\n#include <cmath>\r\n#include <map>\r\
    \n#line 2 \"math/mod_pow.hpp\"\n\r\nlong long mod_pow(long long base, long long\
    \ exponent, int mod) {\r\n  base %= mod;\r\n  long long res = 1;\r\n  while (exponent\
    \ > 0) {\r\n    if (exponent & 1) (res *= base) %= mod;\r\n    (base *= base)\
    \ %= mod;\r\n    exponent >>= 1;\r\n  }\r\n  return res;\r\n}\r\n#line 5 \"math/mod_log.hpp\"\
    \n\r\nint mod_log(long long g, long long y, int mod) {\r\n  if ((g %= mod) < 0)\
    \ g += mod;\r\n  if ((y %= mod) < 0) y += mod;\r\n  if (mod == 1) return 0;\r\n\
    \  if (g == 0) {\r\n    if (y == 1) {\r\n      return 0;\r\n    } else if (y ==\
    \ 0) {\r\n      return 1;\r\n    } else {\r\n      return -1;\r\n    }\r\n  }\r\
    \n  int root = std::ceil(std::sqrt(mod));\r\n  std::map<long long, int> baby;\r\
    \n  long long p = 1;\r\n  for (int i = 0; i < root; ++i) {\r\n    if (p == y)\
    \ return i;\r\n    baby[p * y % mod] = i;\r\n    (p *= g) %= mod;\r\n  }\r\n \
    \ long long brute_force = p;\r\n  for (int i = root; i < 100; ++i) {\r\n    if\
    \ (i == mod) return -1;\r\n    if (brute_force == y) return i;\r\n    (brute_force\
    \ *= g) %= mod;\r\n  }\r\n  long long giant = p;\r\n  for (int i = 1; i <= root;\
    \ ++i) {\r\n    if (baby.count(giant) == 1) {\r\n      int ans = static_cast<int>(static_cast<long\
    \ long>(i) * root - baby[giant]);\r\n      if (mod_pow(g, ans, mod) == y) return\
    \ ans;\r\n    }\r\n    (giant *= p) %= mod;\r\n  }\r\n  return -1;\r\n}\r\n"
  code: "#pragma once\r\n#include <cmath>\r\n#include <map>\r\n#include \"mod_pow.hpp\"\
    \r\n\r\nint mod_log(long long g, long long y, int mod) {\r\n  if ((g %= mod) <\
    \ 0) g += mod;\r\n  if ((y %= mod) < 0) y += mod;\r\n  if (mod == 1) return 0;\r\
    \n  if (g == 0) {\r\n    if (y == 1) {\r\n      return 0;\r\n    } else if (y\
    \ == 0) {\r\n      return 1;\r\n    } else {\r\n      return -1;\r\n    }\r\n\
    \  }\r\n  int root = std::ceil(std::sqrt(mod));\r\n  std::map<long long, int>\
    \ baby;\r\n  long long p = 1;\r\n  for (int i = 0; i < root; ++i) {\r\n    if\
    \ (p == y) return i;\r\n    baby[p * y % mod] = i;\r\n    (p *= g) %= mod;\r\n\
    \  }\r\n  long long brute_force = p;\r\n  for (int i = root; i < 100; ++i) {\r\
    \n    if (i == mod) return -1;\r\n    if (brute_force == y) return i;\r\n    (brute_force\
    \ *= g) %= mod;\r\n  }\r\n  long long giant = p;\r\n  for (int i = 1; i <= root;\
    \ ++i) {\r\n    if (baby.count(giant) == 1) {\r\n      int ans = static_cast<int>(static_cast<long\
    \ long>(i) * root - baby[giant]);\r\n      if (mod_pow(g, ans, mod) == y) return\
    \ ans;\r\n    }\r\n    (giant *= p) %= mod;\r\n  }\r\n  return -1;\r\n}\r\n"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/mod_log.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mod_log.test.cpp
documentation_of: math/mod_log.hpp
layout: document
title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
---

$g^x \equiv y \pmod{p} \ (g = \text{const.},\ y \in \mathbb{Z},\ p \in \mathbb{P})$ を満たす $x$ を求める問題である．


### baby-step giant-step

離散対数問題の解の内, 最小の非負整数を求めるアルゴリズムである．


## 時間計算量

$O(\sqrt{P} \log{P})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`mod_log(g, y, mod)`|$x \text{ s.t. } g^x \equiv y \pmod{\mathrm{md}}$|存在しない場合は $-1$ となる．|


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
