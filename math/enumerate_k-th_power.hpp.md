---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_k-th_power.test.cpp
    title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/enumerate_k-th_power.hpp\"\n#include <vector>\n\n#line\
    \ 2 \"math/mod_pow.hpp\"\n\nlong long mod_pow(long long x, long long n, const\
    \ int m) {\n  if ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0;\
    \ n >>= 1) {\n    if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n\
    \  return res;\n}\n#line 2 \"math/prime_sieve.hpp\"\n#include <numeric>\n#line\
    \ 4 \"math/prime_sieve.hpp\"\n\nstd::vector<int> prime_sieve(const int n, const\
    \ bool get_only_prime) {\n  std::vector<int> smallest_prime_factor(n + 1), prime;\n\
    \  std::iota(smallest_prime_factor.begin(), smallest_prime_factor.end(), 0);\n\
    \  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i] == i) prime.emplace_back(i);\n\
    \    for (const int p : prime) {\n      if (i * p > n || p > smallest_prime_factor[i])\
    \ break;\n      smallest_prime_factor[i * p] = p;\n    }\n  }\n  return get_only_prime\
    \ ? prime : smallest_prime_factor;\n}\n#line 6 \"math/enumerate_k-th_power.hpp\"\
    \n\nstd::vector<int> enumerate_kth_power(const int n, const int k, const int m)\
    \ {\n  const std::vector<int> smallest_prime_factor = prime_sieve(n, false);\n\
    \  std::vector<int> res(n + 1, 0);\n  for (int i = 1; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) {\n      res[i] = mod_pow(i, k, m);\n    } else {\n      res[i] = static_cast<long\
    \ long>(res[smallest_prime_factor[i]])\n               * res[i / smallest_prime_factor[i]]\
    \ % m;\n    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n#include <vector>\n\n#include \"./mod_pow.hpp\"\n#include \"\
    ./prime_sieve.hpp\"\n\nstd::vector<int> enumerate_kth_power(const int n, const\
    \ int k, const int m) {\n  const std::vector<int> smallest_prime_factor = prime_sieve(n,\
    \ false);\n  std::vector<int> res(n + 1, 0);\n  for (int i = 1; i <= n; ++i) {\n\
    \    if (smallest_prime_factor[i] == i) {\n      res[i] = mod_pow(i, k, m);\n\
    \    } else {\n      res[i] = static_cast<long long>(res[smallest_prime_factor[i]])\n\
    \               * res[i / smallest_prime_factor[i]] % m;\n    }\n  }\n  return\
    \ res;\n}\n"
  dependsOn:
  - math/mod_pow.hpp
  - math/prime_sieve.hpp
  isVerificationFile: false
  path: math/enumerate_k-th_power.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/enumerate_k-th_power.test.cpp
documentation_of: math/enumerate_k-th_power.hpp
layout: document
title: $i^k \bmod m$ ($0 \leq i \leq n$)
---


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`enumerate_kth_power(n, k, m)`|$i^k \bmod m$ ($0 \leq i \leq n$)|


## 参考

- https://37zigen.com/linear-sieve/


## Verified

https://yukicoder.me/submissions/623345
