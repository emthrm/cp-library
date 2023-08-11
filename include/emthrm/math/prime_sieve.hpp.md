---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/emthrm/math/carmichael_function_init.hpp
    title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570 (Carmichael function)\
      \ \u306E\u6570\u8868"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/enumerate_k-th_power.hpp
    title: $i^k \bmod m$ ($0 \leq i \leq n$)
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/euler_phi_init2.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570 (Euler's totient\
      \ function) \u306E\u6570\u88682"
  - icon: ':question:'
    path: include/emthrm/math/mobius_mu_init2.hpp
    title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 (M\xF6bius function) \u306E\u6570\
      \u88682"
  - icon: ':question:'
    path: include/emthrm/math/osa_k.hpp
    title: "osa_k \u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/enumerate_k-th_power.test.cpp
    title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi_init2.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
  - icon: ':warning:'
    path: test/math/mobius_mu_init2.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570\u306E\u6570\u88682"
  - icon: ':warning:'
    path: test/math/osa_k.test.cpp
    title: "\u6570\u5B66/osa_k \u6CD5"
  - icon: ':heavy_check_mark:'
    path: test/math/prime_sieve.test.cpp
    title: "\u6570\u5B66/prime sieve"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/prime_sieve.hpp\"\n\n\n\n#include <numeric>\n\
    #include <vector>\n\nnamespace emthrm {\n\ntemplate <bool GETS_ONLY_PRIME>\nstd::vector<int>\
    \ prime_sieve(const int n) {\n  std::vector<int> smallest_prime_factor(n + 1),\
    \ prime;\n  std::iota(smallest_prime_factor.begin(), smallest_prime_factor.end(),\
    \ 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i] == i)\
    \ [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n     \
    \ if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_PRIME_SIEVE_HPP_\n#define EMTHRM_MATH_PRIME_SIEVE_HPP_\n\
    \n#include <numeric>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <bool\
    \ GETS_ONLY_PRIME>\nstd::vector<int> prime_sieve(const int n) {\n  std::vector<int>\
    \ smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n\
    \      if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_PRIME_SIEVE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/prime_sieve.hpp
  requiredBy:
  - include/emthrm/math/enumerate_k-th_power.hpp
  - include/emthrm/math/euler_phi_init2.hpp
  - include/emthrm/math/carmichael_function_init.hpp
  - include/emthrm/math/osa_k.hpp
  - include/emthrm/math/mobius_mu_init2.hpp
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/math/osa_k.test.cpp
  - test/math/euler_phi_init2.test.cpp
  - test/math/enumerate_k-th_power.test.cpp
  - test/math/prime_sieve.test.cpp
  - test/math/mobius_mu_init2.test.cpp
documentation_of: include/emthrm/math/prime_sieve.hpp
layout: document
title: prime sieve
---


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <bool GETS_ONLY_PRIME> std::vector<int> prime_sieve(const int n);`|$n$ 以下の素数または $i$ ($i \leq n$) の最小素因数|


## 参考文献

- https://37zigen.com/linear-sieve/
- https://imulan.hatenablog.jp/entry/2019/09/29/212808


## TODO

- $n$ 以下の素数の個数
  - ~~http://sugarknri.hatenablog.com/entry/2019/07/31/102422~~
  - https://rsk0315.hatenablog.com/entry/2021/05/18/015511
  - https://rsk0315.github.io/slides/prime-counting.pdf
  - https://suu-0313.hatenablog.com/entry/2021/09/14/225759
  - https://sotanishy.github.io/cp-library-cpp/math/prime_count.hpp
  - https://judge.yosupo.jp/problem/counting_primes


## Submissons

https://yukicoder.me/submissions/623330
