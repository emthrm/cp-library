---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/osa_k.hpp
    title: "osa_k \u6CD5"
  - icon: ':x:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc177/tasks/abc177_e
    document_title: "\u6570\u5B66/osa_k \u6CD5"
    links:
    - https://atcoder.jp/contests/abc177/tasks/abc177_e
  bundledCode: "#line 1 \"test/math/osa_k.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /osa_k \u6CD5\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_e\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <utility>\r\n\
    #include <vector>\r\n\r\n#line 4 \"math/osa_k.hpp\"\n\r\n#line 2 \"math/prime_sieve.hpp\"\
    \n#include <numeric>\r\n#line 4 \"math/prime_sieve.hpp\"\n\r\nstd::vector<int>\
    \ prime_sieve(const int n, const bool get_only_prime) {\r\n  std::vector<int>\
    \ smallest_prime_factor(n + 1), prime;\r\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\r\n  for (int i = 2; i <= n; ++i) {\r\n   \
    \ if (smallest_prime_factor[i] == i) prime.emplace_back(i);\r\n    for (const\
    \ int p : prime) {\r\n      if (i * p > n || p > smallest_prime_factor[i]) break;\r\
    \n      smallest_prime_factor[i * p] = p;\r\n    }\r\n  }\r\n  return get_only_prime\
    \ ? prime : smallest_prime_factor;\r\n}\r\n#line 6 \"math/osa_k.hpp\"\n\r\nstruct\
    \ OsaK {\r\n  const std::vector<int> smallest_prime_factor;\r\n\r\n  explicit\
    \ OsaK(const int n) : smallest_prime_factor(prime_sieve(n, false)) {}\r\n\r\n\
    \  std::vector<std::pair<int, int>> query(int n) const {\r\n    std::vector<std::pair<int,\
    \ int>> res;\r\n    while (n > 1) {\r\n      const int prime = smallest_prime_factor[n];\r\
    \n      int exponent = 0;\r\n      for (; smallest_prime_factor[n] == prime; n\
    \ /= prime) {\r\n        ++exponent;\r\n      }\r\n      res.emplace_back(prime,\
    \ exponent);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n#line 12 \"test/math/osa_k.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> a[i];\r\n  }\r\n  const int\
    \ max_a = *std::max_element(a.begin(), a.end());\r\n  const OsaK osa_k(max_a);\r\
    \n  std::vector<int> prime_factor(max_a + 1, 0);\r\n  for (const int a_i : a)\
    \ {\r\n    for (const std::pair<int, int>& pr : osa_k.query(a_i)) {\r\n      ++prime_factor[pr.first];\r\
    \n    }\r\n  }\r\n  const int maximum =\r\n      *std::max_element(prime_factor.begin(),\
    \ prime_factor.end());\r\n  if (maximum <= 1) {\r\n    std::cout << \"pairwise\
    \ coprime\\n\";\r\n  } else if (maximum == n) {\r\n    std::cout << \"not coprime\\\
    n\";\r\n  } else {\r\n    std::cout << \"setwise coprime\\n\";\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/osa_k \u6CD5\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_e\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <utility>\r\n\
    #include <vector>\r\n\r\n#include \"../../math/osa_k.hpp\"\r\n\r\nint main() {\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n);\r\n  for (int i = 0;\
    \ i < n; ++i) {\r\n    std::cin >> a[i];\r\n  }\r\n  const int max_a = *std::max_element(a.begin(),\
    \ a.end());\r\n  const OsaK osa_k(max_a);\r\n  std::vector<int> prime_factor(max_a\
    \ + 1, 0);\r\n  for (const int a_i : a) {\r\n    for (const std::pair<int, int>&\
    \ pr : osa_k.query(a_i)) {\r\n      ++prime_factor[pr.first];\r\n    }\r\n  }\r\
    \n  const int maximum =\r\n      *std::max_element(prime_factor.begin(), prime_factor.end());\r\
    \n  if (maximum <= 1) {\r\n    std::cout << \"pairwise coprime\\n\";\r\n  } else\
    \ if (maximum == n) {\r\n    std::cout << \"not coprime\\n\";\r\n  } else {\r\n\
    \    std::cout << \"setwise coprime\\n\";\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/osa_k.hpp
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/osa_k.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/osa_k.test.cpp
layout: document
redirect_from:
- /verify/test/math/osa_k.test.cpp
- /verify/test/math/osa_k.test.cpp.html
title: "\u6570\u5B66/osa_k \u6CD5"
---
