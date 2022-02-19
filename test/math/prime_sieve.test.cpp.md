---
data:
  _extendedDependsOn:
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
    PROBLEM: https://yukicoder.me/problems/no/843
    document_title: "\u6570\u5B66/prime sieve"
    links:
    - https://yukicoder.me/problems/no/843
  bundledCode: "#line 1 \"test/math/prime_sieve.test.cpp\"\n/*\r\n * @brief \u6570\
    \u5B66/prime sieve\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/843\"\
    \r\n\r\n#include <iostream>\r\n#include <set>\r\n#include <vector>\r\n\r\n#line\
    \ 2 \"math/prime_sieve.hpp\"\n#include <numeric>\r\n#line 4 \"math/prime_sieve.hpp\"\
    \n\r\nstd::vector<int> prime_sieve(const int n, const bool get_only_prime) {\r\
    \n  std::vector<int> smallest_prime_factor(n + 1), prime;\r\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\r\n  for (int i = 2; i <= n; ++i) {\r\n   \
    \ if (smallest_prime_factor[i] == i) prime.emplace_back(i);\r\n    for (const\
    \ int p : prime) {\r\n      if (i * p > n || p > smallest_prime_factor[i]) break;\r\
    \n      smallest_prime_factor[i * p] = p;\r\n    }\r\n  }\r\n  return get_only_prime\
    \ ? prime : smallest_prime_factor;\r\n}\r\n#line 11 \"test/math/prime_sieve.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  const std::vector<int>\
    \ tmp = prime_sieve(n, true);\r\n  const std::set<int> prime(tmp.begin(), tmp.end());\r\
    \n  int ans = 0;\r\n  for (const int p : prime) {\r\n    if (p * p - 2 > n) break;\r\
    \n    if (prime.count(p * p - 2) == 1) ans += (p == 2 ? 1 : 2);\r\n  }\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/prime sieve\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/843\"\
    \r\n\r\n#include <iostream>\r\n#include <set>\r\n#include <vector>\r\n\r\n#include\
    \ \"../../math/prime_sieve.hpp\"\r\n\r\nint main() {\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  const std::vector<int> tmp = prime_sieve(n, true);\r\n  const std::set<int>\
    \ prime(tmp.begin(), tmp.end());\r\n  int ans = 0;\r\n  for (const int p : prime)\
    \ {\r\n    if (p * p - 2 > n) break;\r\n    if (prime.count(p * p - 2) == 1) ans\
    \ += (p == 2 ? 1 : 2);\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/prime_sieve.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/prime_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime_sieve.test.cpp
- /verify/test/math/prime_sieve.test.cpp.html
title: "\u6570\u5B66/prime sieve"
---
