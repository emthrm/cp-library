---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6570\u5B66/prime sieve"
    links:
    - https://yukicoder.me/problems/no/843
  bundledCode: "#line 1 \"test/math/prime_sieve.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /prime sieve\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/843\"\
    \r\n\r\n#include <iostream>\r\n#include <set>\r\n#include <vector>\r\n#line 2\
    \ \"math/prime_sieve.hpp\"\n#include <numeric>\r\n#line 4 \"math/prime_sieve.hpp\"\
    \n\r\nstd::vector<int> prime_sieve(int n, bool get_only_prime) {\r\n  std::vector<int>\
    \ prime, smallest_prime_factor(n + 1);\r\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\r\n  for (int i = 2; i <= n; ++i) {\r\n   \
    \ if (smallest_prime_factor[i] == i) prime.emplace_back(i);\r\n    for (int p\
    \ : prime) {\r\n      if (i * p > n || p > smallest_prime_factor[i]) break;\r\n\
    \      smallest_prime_factor[i * p] = p;\r\n    }\r\n  }\r\n  return get_only_prime\
    \ ? prime : smallest_prime_factor;\r\n}\r\n#line 10 \"test/math/prime_sieve.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> tmp =\
    \ prime_sieve(n, true);\r\n  std::set<int> prime(tmp.begin(), tmp.end());\r\n\
    \  int ans = 0;\r\n  for (int p : prime) {\r\n    if (p * p - 2 > n) break;\r\n\
    \    if (prime.count(p * p - 2) == 1) ans += (p == 2 ? 1 : 2);\r\n  }\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/prime sieve\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/843\"\
    \r\n\r\n#include <iostream>\r\n#include <set>\r\n#include <vector>\r\n#include\
    \ \"../../math/prime_sieve.hpp\"\r\n\r\nint main() {\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  std::vector<int> tmp = prime_sieve(n, true);\r\n  std::set<int> prime(tmp.begin(),\
    \ tmp.end());\r\n  int ans = 0;\r\n  for (int p : prime) {\r\n    if (p * p -\
    \ 2 > n) break;\r\n    if (prime.count(p * p - 2) == 1) ans += (p == 2 ? 1 : 2);\r\
    \n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: false
  path: test/math/prime_sieve.cpp
  requiredBy: []
  timestamp: '2021-02-27 06:50:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/math/prime_sieve.cpp
layout: document
redirect_from:
- /library/test/math/prime_sieve.cpp
- /library/test/math/prime_sieve.cpp.html
title: "\u6570\u5B66/prime sieve"
---
