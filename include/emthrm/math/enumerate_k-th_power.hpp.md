---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':question:'
    path: include/emthrm/math/prime_sieve.hpp
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
  bundledCode: "#line 1 \"include/emthrm/math/enumerate_k-th_power.hpp\"\n\n\n\n#include\
    \ <vector>\n\n#line 1 \"include/emthrm/math/mod_pow.hpp\"\n\n\n\nnamespace emthrm\
    \ {\n\nlong long mod_pow(long long x, long long n, const int m) {\n  if ((x %=\
    \ m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0; n >>= 1) {\n    if (n\
    \ & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return res;\n}\n\n}\
    \  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/prime_sieve.hpp\"\n\n\
    \n\n#include <numeric>\n#line 6 \"include/emthrm/math/prime_sieve.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <bool GETS_ONLY_PRIME>\nstd::vector<int> prime_sieve(const\
    \ int n) {\n  std::vector<int> smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n\
    \      if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 8 \"include/emthrm/math/enumerate_k-th_power.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<int> enumerate_kth_power(const int n, const\
    \ int k, const int m) {\n  const std::vector<int> smallest_prime_factor = prime_sieve<false>(n);\n\
    \  std::vector<int> res(n + 1, 0);\n  for (int i = 1; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] {\n      res[i] = mod_pow(i, k, m);\n    } else {\n     \
    \ res[i] = static_cast<long long>(res[smallest_prime_factor[i]])\n           \
    \    * res[i / smallest_prime_factor[i]] % m;\n    }\n  }\n  return res;\n}\n\n\
    }  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_\n#define EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/math/mod_pow.hpp\"\n#include \"emthrm/math/prime_sieve.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<int> enumerate_kth_power(const int n, const\
    \ int k, const int m) {\n  const std::vector<int> smallest_prime_factor = prime_sieve<false>(n);\n\
    \  std::vector<int> res(n + 1, 0);\n  for (int i = 1; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] {\n      res[i] = mod_pow(i, k, m);\n    } else {\n     \
    \ res[i] = static_cast<long long>(res[smallest_prime_factor[i]])\n           \
    \    * res[i / smallest_prime_factor[i]] % m;\n    }\n  }\n  return res;\n}\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_MATH_ENUMERATE_K_TH_POWER_HPP_\n"
  dependsOn:
  - include/emthrm/math/mod_pow.hpp
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: false
  path: include/emthrm/math/enumerate_k-th_power.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/enumerate_k-th_power.test.cpp
documentation_of: include/emthrm/math/enumerate_k-th_power.hpp
layout: document
title: $i^k \bmod m$ ($0 \leq i \leq n$)
---


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`std::vector<int> enumerate_kth_power(const int n, const int k, const int m);`|$i^k \bmod m$ ($0 \leq i \leq n$)|


## 参考文献

- https://37zigen.com/linear-sieve/


## Submissons

https://yukicoder.me/submissions/623345
