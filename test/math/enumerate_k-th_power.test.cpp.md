---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_k-th_power.hpp
    title: $i^k \bmod m$ ($0 \leq i \leq n$)
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1409
    document_title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
    links:
    - https://yukicoder.me/problems/no/1409
  bundledCode: "#line 1 \"test/math/enumerate_k-th_power.test.cpp\"\n/*\n * @brief\
    \ \u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/1409\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 3 \"math/enumerate_k-th_power.hpp\"\
    \n\n#line 2 \"math/mod_pow.hpp\"\n\nlong long mod_pow(long long x, long long n,\
    \ const int m) {\n  if ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (;\
    \ n > 0; n >>= 1) {\n    if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n\
    \  }\n  return res;\n}\n#line 2 \"math/prime_sieve.hpp\"\n#include <numeric>\n\
    #line 4 \"math/prime_sieve.hpp\"\n\nstd::vector<int> prime_sieve(const int n,\
    \ const bool get_only_prime) {\n  std::vector<int> smallest_prime_factor(n + 1),\
    \ prime;\n  std::iota(smallest_prime_factor.begin(), smallest_prime_factor.end(),\
    \ 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i] == i)\
    \ prime.emplace_back(i);\n    for (const int p : prime) {\n      if (i * p > n\
    \ || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i * p]\
    \ = p;\n    }\n  }\n  return get_only_prime ? prime : smallest_prime_factor;\n\
    }\n#line 6 \"math/enumerate_k-th_power.hpp\"\n\nstd::vector<int> enumerate_kth_power(const\
    \ int n, const int k, const int m) {\n  const std::vector<int> smallest_prime_factor\
    \ = prime_sieve(n, false);\n  std::vector<int> res(n + 1, 0);\n  for (int i =\
    \ 1; i <= n; ++i) {\n    if (smallest_prime_factor[i] == i) {\n      res[i] =\
    \ mod_pow(i, k, m);\n    } else {\n      res[i] = static_cast<long long>(res[smallest_prime_factor[i]])\n\
    \               * res[i / smallest_prime_factor[i]] % m;\n    }\n  }\n  return\
    \ res;\n}\n#line 10 \"test/math/enumerate_k-th_power.test.cpp\"\n\nint main()\
    \ {\n  int t;\n  std::cin >> t;\n  while (t--) {\n    int v, x;\n    std::cin\
    \ >> v >> x;\n    const int p = x * v + 1;\n    const std::vector<int> ps = enumerate_kth_power(p\
    \ - 1, x, p);\n    std::vector<int> a;\n    a.reserve(x);\n    for (int i = 1;\
    \ i < p; ++i) {\n      if (ps[i] == 1) a.emplace_back(i);\n    }\n    for (int\
    \ i = 0; i < x; ++i) {\n      std::cout << a[i] << \" \\n\"[i + 1 == x];\n   \
    \ }\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)\n */\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1409\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#include \"../../math/enumerate_k-th_power.hpp\"\n\nint main() {\n\
    \  int t;\n  std::cin >> t;\n  while (t--) {\n    int v, x;\n    std::cin >> v\
    \ >> x;\n    const int p = x * v + 1;\n    const std::vector<int> ps = enumerate_kth_power(p\
    \ - 1, x, p);\n    std::vector<int> a;\n    a.reserve(x);\n    for (int i = 1;\
    \ i < p; ++i) {\n      if (ps[i] == 1) a.emplace_back(i);\n    }\n    for (int\
    \ i = 0; i < x; ++i) {\n      std::cout << a[i] << \" \\n\"[i + 1 == x];\n   \
    \ }\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/enumerate_k-th_power.hpp
  - math/mod_pow.hpp
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/enumerate_k-th_power.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerate_k-th_power.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_k-th_power.test.cpp
- /verify/test/math/enumerate_k-th_power.test.cpp.html
title: "\u6570\u5B66/$i^k \\bmod m$ ($0 \\leq i \\leq n$)"
---
