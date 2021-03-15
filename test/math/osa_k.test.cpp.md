---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/osa_k.hpp
    title: "osa_k \u6CD5"
  - icon: ':question:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/osa_k \u6CD5"
    links:
    - https://atcoder.jp/contests/abc177/tasks/abc177_e
  bundledCode: "#line 1 \"test/math/osa_k.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /osa_k \u6CD5\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_e\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <utility>\r\n\
    #include <vector>\r\n#line 2 \"math/prime_sieve.hpp\"\n#include <numeric>\r\n\
    #line 4 \"math/prime_sieve.hpp\"\n\r\nstd::vector<int> prime_sieve(int n, bool\
    \ get_only_prime) {\r\n  std::vector<int> prime, smallest_prime_factor(n + 1);\r\
    \n  std::iota(smallest_prime_factor.begin(), smallest_prime_factor.end(), 0);\r\
    \n  for (int i = 2; i <= n; ++i) {\r\n    if (smallest_prime_factor[i] == i) prime.emplace_back(i);\r\
    \n    for (int p : prime) {\r\n      if (i * p > n || p > smallest_prime_factor[i])\
    \ break;\r\n      smallest_prime_factor[i * p] = p;\r\n    }\r\n  }\r\n  return\
    \ get_only_prime ? prime : smallest_prime_factor;\r\n}\r\n#line 5 \"math/osa_k.hpp\"\
    \n\r\nstruct osa_k {\r\n  std::vector<int> smallest_prime_factor;\r\n\r\n  osa_k(int\
    \ n = 10000000) : smallest_prime_factor(prime_sieve(n, false)) {}\r\n\r\n  std::vector<std::pair<int,\
    \ int>> query(int n) const {\r\n    std::vector<std::pair<int, int>> res;\r\n\
    \    while (n > 1) {\r\n      int prime = smallest_prime_factor[n], exponent =\
    \ 0;\r\n      while (smallest_prime_factor[n] == prime) {\r\n        ++exponent;\r\
    \n        n /= prime;\r\n      }\r\n      res.emplace_back(prime, exponent);\r\
    \n    }\r\n    return res;\r\n  }\r\n};\r\n#line 12 \"test/math/osa_k.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr int A = 1000000;\r\n  osa_k osa(A);\r\n  int\
    \ n;\r\n  std::cin >> n;\r\n  std::vector<int> prime_factor(A + 1, 0);\r\n  for\
    \ (int i = 0; i < n; ++i) {\r\n    int a;\r\n    std::cin >> a;\r\n    for (const\
    \ std::pair<int, int> &pr : osa.query(a)) ++prime_factor[pr.first];\r\n  }\r\n\
    \  int mx = *std::max_element(prime_factor.begin(), prime_factor.end());\r\n \
    \ if (mx <= 1) {\r\n    std::cout << \"pairwise coprime\\n\";\r\n  } else if (mx\
    \ == n) {\r\n    std::cout << \"not coprime\\n\";\r\n  } else {\r\n    std::cout\
    \ << \"setwise coprime\\n\";\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/osa_k \u6CD5\r\n */\r\n#define IGNORE\r\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_e\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"../../math/osa_k.hpp\"\r\n\r\nint main() {\r\n  constexpr int A =\
    \ 1000000;\r\n  osa_k osa(A);\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int>\
    \ prime_factor(A + 1, 0);\r\n  for (int i = 0; i < n; ++i) {\r\n    int a;\r\n\
    \    std::cin >> a;\r\n    for (const std::pair<int, int> &pr : osa.query(a))\
    \ ++prime_factor[pr.first];\r\n  }\r\n  int mx = *std::max_element(prime_factor.begin(),\
    \ prime_factor.end());\r\n  if (mx <= 1) {\r\n    std::cout << \"pairwise coprime\\\
    n\";\r\n  } else if (mx == n) {\r\n    std::cout << \"not coprime\\n\";\r\n  }\
    \ else {\r\n    std::cout << \"setwise coprime\\n\";\r\n  }\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - math/osa_k.hpp
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/osa_k.test.cpp
  requiredBy: []
  timestamp: '2021-02-27 06:50:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/osa_k.test.cpp
layout: document
redirect_from:
- /verify/test/math/osa_k.test.cpp
- /verify/test/math/osa_k.test.cpp.html
title: "\u6570\u5B66/osa_k \u6CD5"
---
