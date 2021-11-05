---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/carmichal_function_init.hpp
    title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
  - icon: ':heavy_check_mark:'
    path: math/enumerate_k-th_power.hpp
    title: $i^k \bmod m \ (0 \leq i \leq n)$
  - icon: ':heavy_check_mark:'
    path: math/euler_phi/euler_phi_init2.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\
      2"
  - icon: ':heavy_check_mark:'
    path: math/mobius_mu/mobius_mu_init2.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
  - icon: ':heavy_check_mark:'
    path: math/osa_k.hpp
    title: "osa_k \u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_k-th_power.test.cpp
    title: "\u6570\u5B66/$i^k \\bmod m \\ (0 \\leq i \\leq n)$"
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi_init2.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
  - icon: ':heavy_check_mark:'
    path: test/math/fast_divisor.test.cpp
    title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: test/math/mobius_mu/mobius_mu_init2.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570\u306E\u6570\u88682"
  - icon: ':heavy_check_mark:'
    path: test/math/osa_k.test.cpp
    title: "\u6570\u5B66/osa_k \u6CD5"
  - icon: ':heavy_check_mark:'
    path: test/math/prime_sieve.test.cpp
    title: "\u6570\u5B66/prime sieve"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime_sieve.hpp\"\n#include <numeric>\r\n#include <vector>\r\
    \n\r\nstd::vector<int> prime_sieve(int n, bool get_only_prime) {\r\n  std::vector<int>\
    \ prime, smallest_prime_factor(n + 1);\r\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\r\n  for (int i = 2; i <= n; ++i) {\r\n   \
    \ if (smallest_prime_factor[i] == i) prime.emplace_back(i);\r\n    for (int p\
    \ : prime) {\r\n      if (i * p > n || p > smallest_prime_factor[i]) break;\r\n\
    \      smallest_prime_factor[i * p] = p;\r\n    }\r\n  }\r\n  return get_only_prime\
    \ ? prime : smallest_prime_factor;\r\n}\r\n"
  code: "#pragma once\r\n#include <numeric>\r\n#include <vector>\r\n\r\nstd::vector<int>\
    \ prime_sieve(int n, bool get_only_prime) {\r\n  std::vector<int> prime, smallest_prime_factor(n\
    \ + 1);\r\n  std::iota(smallest_prime_factor.begin(), smallest_prime_factor.end(),\
    \ 0);\r\n  for (int i = 2; i <= n; ++i) {\r\n    if (smallest_prime_factor[i]\
    \ == i) prime.emplace_back(i);\r\n    for (int p : prime) {\r\n      if (i * p\
    \ > n || p > smallest_prime_factor[i]) break;\r\n      smallest_prime_factor[i\
    \ * p] = p;\r\n    }\r\n  }\r\n  return get_only_prime ? prime : smallest_prime_factor;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_sieve.hpp
  requiredBy:
  - math/euler_phi/euler_phi_init2.hpp
  - math/mobius_mu/mobius_mu_init2.hpp
  - math/carmichal_function_init.hpp
  - math/enumerate_k-th_power.hpp
  - math/osa_k.hpp
  timestamp: '2021-02-27 06:50:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/enumerate_k-th_power.test.cpp
  - test/math/euler_phi/euler_phi_init2.test.cpp
  - test/math/mobius_mu/mobius_mu_init2.test.cpp
  - test/math/prime_sieve.test.cpp
  - test/math/fast_divisor.test.cpp
  - test/math/osa_k.test.cpp
documentation_of: math/prime_sieve.hpp
layout: document
title: prime sieve
---


## 時間計算量

$O(N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`prime_sieve(n, 素数のみ取得するか?)`|$n$ 以下の素数または $i \ (i \leq n)$ の最小素因数||


## 参考

- https://37zigen.com/linear-sieve/
- https://imulan.hatenablog.jp/entry/2019/09/29/212808


## ToDo

- $n$ 以下の素数の個数
  - ~~http://sugarknri.hatenablog.com/entry/2019/07/31/102422~~
  - https://rsk0315.hatenablog.com/entry/2021/05/18/015511
  - https://suu-0313.hatenablog.com/entry/2021/09/14/225759
  - https://judge.yosupo.jp/problem/counting_primes


## Verified

https://yukicoder.me/submissions/623330
