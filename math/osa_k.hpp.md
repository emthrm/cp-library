---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/osa_k.test.cpp
    title: "\u6570\u5B66/osa_k \u6CD5"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/osa_k.hpp\"\n#include <utility>\r\n#include <vector>\r\
    \n\r\nstruct osa_k {\r\n  osa_k(int val = 10000000) : least_prime_factor(val +\
    \ 1, -1) {\r\n    least_prime_factor[0] = 0;\r\n    if (val >= 1) least_prime_factor[1]\
    \ = 1;\r\n    for (int i = 2; i <= val; ++i) {\r\n      if (least_prime_factor[i]\
    \ == -1) {\r\n        least_prime_factor[i] = i;\r\n        for (long long j =\
    \ static_cast<long long>(i) * i; j <= val; j += i) {\r\n          if (least_prime_factor[j]\
    \ == -1) least_prime_factor[j] = i;\r\n        }\r\n      }\r\n    }\r\n  }\r\n\
    \r\n  std::vector<std::pair<int, int>> query(int val) const {\r\n    std::vector<std::pair<int,\
    \ int>> res;\r\n    while (val > 1) {\r\n      int prime = least_prime_factor[val],\
    \ exponent = 0;\r\n      while (least_prime_factor[val] == prime) {\r\n      \
    \  ++exponent;\r\n        val /= prime;\r\n      }\r\n      res.emplace_back(prime,\
    \ exponent);\r\n    }\r\n    return res;\r\n  }\r\n\r\nprivate:\r\n  std::vector<int>\
    \ least_prime_factor;\r\n};\r\n"
  code: "#pragma once\r\n#include <utility>\r\n#include <vector>\r\n\r\nstruct osa_k\
    \ {\r\n  osa_k(int val = 10000000) : least_prime_factor(val + 1, -1) {\r\n   \
    \ least_prime_factor[0] = 0;\r\n    if (val >= 1) least_prime_factor[1] = 1;\r\
    \n    for (int i = 2; i <= val; ++i) {\r\n      if (least_prime_factor[i] == -1)\
    \ {\r\n        least_prime_factor[i] = i;\r\n        for (long long j = static_cast<long\
    \ long>(i) * i; j <= val; j += i) {\r\n          if (least_prime_factor[j] ==\
    \ -1) least_prime_factor[j] = i;\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\
    \n  std::vector<std::pair<int, int>> query(int val) const {\r\n    std::vector<std::pair<int,\
    \ int>> res;\r\n    while (val > 1) {\r\n      int prime = least_prime_factor[val],\
    \ exponent = 0;\r\n      while (least_prime_factor[val] == prime) {\r\n      \
    \  ++exponent;\r\n        val /= prime;\r\n      }\r\n      res.emplace_back(prime,\
    \ exponent);\r\n    }\r\n    return res;\r\n  }\r\n\r\nprivate:\r\n  std::vector<int>\
    \ least_prime_factor;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/osa_k.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/osa_k.test.cpp
documentation_of: math/osa_k.hpp
layout: document
title: "osa_k \u6CD5"
---

[エラトステネスの篩](sieve_of_eratosthenes.md)を用いた[素因数分解](prime_factorization.md)


## 時間計算量

$\langle O(N\log{\log{N}}), O(\log{N}) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`osa_k(val = 10000000)`|$\mathrm{val}$ 以下における osa_k 法 を考える．|
|`query(val)`|$\mathrm{val}$ の素因数分解|


## 参考

- http://www.osak.jp/diary/diary_201310.html#20131017


## Verified

https://atcoder.jp/contests/abc052/submissions/9301834
