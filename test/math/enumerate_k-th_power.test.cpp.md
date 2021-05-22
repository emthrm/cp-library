---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/enumerate_k-th_power.hpp
    title: $i^k \bmod m \ (0 \leq i \leq n)$
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':question:'
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
    document_title: "\u6570\u5B66/$i^k \\bmod m \\ (0 \\leq i \\leq n)$"
    links:
    - https://yukicoder.me/problems/no/1409
  bundledCode: "#line 1 \"test/math/enumerate_k-th_power.test.cpp\"\n/*\r\n * @brief\
    \ \u6570\u5B66/$i^k \\bmod m \\ (0 \\leq i \\leq n)$\r\n */\r\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1409\"\r\n\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#line 2 \"math/prime_sieve.hpp\"\n#include <numeric>\r\n#line 4\
    \ \"math/prime_sieve.hpp\"\n\r\nstd::vector<int> prime_sieve(int n, bool get_only_prime)\
    \ {\r\n  std::vector<int> prime, smallest_prime_factor(n + 1);\r\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\r\n  for (int i = 2; i <= n; ++i) {\r\n   \
    \ if (smallest_prime_factor[i] == i) prime.emplace_back(i);\r\n    for (int p\
    \ : prime) {\r\n      if (i * p > n || p > smallest_prime_factor[i]) break;\r\n\
    \      smallest_prime_factor[i * p] = p;\r\n    }\r\n  }\r\n  return get_only_prime\
    \ ? prime : smallest_prime_factor;\r\n}\r\n#line 2 \"math/mod_pow.hpp\"\n\r\n\
    long long mod_pow(long long base, long long exponent, int mod) {\r\n  base %=\
    \ mod;\r\n  long long res = 1;\r\n  while (exponent > 0) {\r\n    if (exponent\
    \ & 1) (res *= base) %= mod;\r\n    (base *= base) %= mod;\r\n    exponent >>=\
    \ 1;\r\n  }\r\n  return res;\r\n}\r\n#line 5 \"math/enumerate_k-th_power.hpp\"\
    \n\r\nstd::vector<int> enumerate_kth_power(int n, int k, int m) {\r\n  std::vector<int>\
    \ res(n + 1, 0);\r\n  std::vector<int> smallest_prime_factor = prime_sieve(n,\
    \ false);\r\n  for (int i = 1; i <= n; ++i) {\r\n    if (smallest_prime_factor[i]\
    \ == i) {\r\n      res[i] = mod_pow(i, k, m);\r\n    } else {\r\n      res[i]\
    \ = static_cast<long long>(res[smallest_prime_factor[i]]) * res[i / smallest_prime_factor[i]]\
    \ % m;\r\n    }\r\n  }\r\n  return res;\r\n}\r\n#line 9 \"test/math/enumerate_k-th_power.test.cpp\"\
    \n\r\nint main() {\r\n  int t;\r\n  std::cin >> t;\r\n  while (t--) {\r\n    int\
    \ v, x;\r\n    std::cin >> v >> x;\r\n    int p = x * v + 1;\r\n    std::vector<int>\
    \ pw = enumerate_kth_power(p - 1, x, p);\r\n    std::vector<int> a;\r\n    a.reserve(x);\r\
    \n    for (int i = 1; i < p; ++i) {\r\n      if (pw[i] == 1) a.emplace_back(i);\r\
    \n    }\r\n    for (int i = 0; i < x; ++i) std::cout << a[i] << \" \\n\"[i + 1\
    \ == x];\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/$i^k \\bmod m \\ (0 \\leq i \\leq n)$\r\n */\r\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/1409\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include \"../../math/enumerate_k-th_power.hpp\"\r\n\r\n\
    int main() {\r\n  int t;\r\n  std::cin >> t;\r\n  while (t--) {\r\n    int v,\
    \ x;\r\n    std::cin >> v >> x;\r\n    int p = x * v + 1;\r\n    std::vector<int>\
    \ pw = enumerate_kth_power(p - 1, x, p);\r\n    std::vector<int> a;\r\n    a.reserve(x);\r\
    \n    for (int i = 1; i < p; ++i) {\r\n      if (pw[i] == 1) a.emplace_back(i);\r\
    \n    }\r\n    for (int i = 0; i < x; ++i) std::cout << a[i] << \" \\n\"[i + 1\
    \ == x];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/enumerate_k-th_power.hpp
  - math/prime_sieve.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/enumerate_k-th_power.test.cpp
  requiredBy: []
  timestamp: '2021-03-15 23:21:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerate_k-th_power.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_k-th_power.test.cpp
- /verify/test/math/enumerate_k-th_power.test.cpp.html
title: "\u6570\u5B66/$i^k \\bmod m \\ (0 \\leq i \\leq n)$"
---