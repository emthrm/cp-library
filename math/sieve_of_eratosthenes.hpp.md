---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/carmichal_function_init.hpp
    title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
  - icon: ':heavy_check_mark:'
    path: math/euler_phi/euler_phi_init2.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\
      2"
  - icon: ':x:'
    path: math/mobius_mu/mobius_mu_init2.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi/euler_phi_init2.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
  - icon: ':x:'
    path: test/math/mobius_mu/mobius_mu_init2.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570\u306E\u6570\u88682"
  - icon: ':x:'
    path: test/math/sieve_of_eratosthenes.test.cpp
    title: "\u6570\u5B66/\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/sieve_of_eratosthenes.hpp\"\n#include <vector>\r\n\r\
    \nstd::vector<bool> sieve_of_eratosthenes(int n) {\r\n  std::vector<bool> res(n\
    \ + 1, true);\r\n  res[0] = false;\r\n  if (n >= 1) res[1] = false;\r\n  for (int\
    \ i = 2; i * i <= n; ++i) {\r\n    if (res[i]) {\r\n      for (int j = i * i;\
    \ j <= n; j += i) res[j] = false;\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\nstd::vector<bool> sieve_of_eratosthenes(int\
    \ n) {\r\n  std::vector<bool> res(n + 1, true);\r\n  res[0] = false;\r\n  if (n\
    \ >= 1) res[1] = false;\r\n  for (int i = 2; i * i <= n; ++i) {\r\n    if (res[i])\
    \ {\r\n      for (int j = i * i; j <= n; j += i) res[j] = false;\r\n    }\r\n\
    \  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sieve_of_eratosthenes.hpp
  requiredBy:
  - math/carmichal_function_init.hpp
  - math/euler_phi/euler_phi_init2.hpp
  - math/mobius_mu/mobius_mu_init2.hpp
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/sieve_of_eratosthenes.test.cpp
  - test/math/euler_phi/euler_phi_init2.test.cpp
  - test/math/mobius_mu/mobius_mu_init2.test.cpp
documentation_of: math/sieve_of_eratosthenes.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9 (sieve of Eratosthenes)"
---

素数を列挙するアルゴリズムである．


## 時間計算量

$O(N\log{\log{N}})$


## 使用法

||説明|
|:--:|:--:|
|`sieve_of_eratosthenes(n)`|$i \ (0 \leq i \leq \mathrm{n})$ が素数であるか．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.111-112


## ToDo

- $O(N)$ に高速化する．
  - https://37zigen.com/linear-sieve/
  - https://codeforces.com/blog/entry/66586
  - https://imulan.hatenablog.jp/entry/2019/09/29/212808
  - https://judge.yosupo.jp/problem/enumerate_primes
- $n$ 以下の素数の個数
  - http://sugarknri.hatenablog.com/entry/2019/07/31/102422
  - https://judge.yosupo.jp/problem/counting_primes


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0009/review/4088022/emthrm/C++14
