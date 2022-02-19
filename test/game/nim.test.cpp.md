---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: game/nim.hpp
    title: "\u30CB\u30E0 (nim)"
  - icon: ':question:'
    path: math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2
    document_title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
    links:
    - https://yukicoder.me/problems/no/2
  bundledCode: "#line 1 \"test/game/nim.test.cpp\"\n/*\r\n * @brief \u30B2\u30FC\u30E0\
    /\u30CB\u30E0\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/2\"\
    \r\n\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n\r\n\
    #line 3 \"game/nim.hpp\"\n\r\ntemplate <typename T>\r\nbool nim(const std::vector<T>&\
    \ a) {\r\n  long long x = 0;\r\n  for (const T e : a) x ^= e;\r\n  return x !=\
    \ 0;\r\n}\r\n#line 4 \"math/prime_factorization.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nstd::vector<std::pair<T, int>> prime_factorization(T n) {\r\n  std::vector<std::pair<T,\
    \ int>> res;\r\n  for (T i = 2; i * i <= n; ++i) {\r\n    if (n % i == 0) {\r\n\
    \      int exponent = 0;\r\n      for (; n % i == 0; n /= i) {\r\n        ++exponent;\r\
    \n      }\r\n      res.emplace_back(i, exponent);\r\n    }\r\n  }\r\n  if (n >\
    \ 1) res.emplace_back(n, 1);\r\n  return res;\r\n}\r\n#line 12 \"test/game/nim.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a;\r\n\
    \  for (const std::pair<int, int>& p : prime_factorization(n)) {\r\n    a.emplace_back(p.second);\r\
    \n  }\r\n  std::cout << (nim(a) ? \"Alice\\n\" : \"Bob\\n\");\r\n  return 0;\r\
    \n}\r\n"
  code: "/*\r\n * @brief \u30B2\u30FC\u30E0/\u30CB\u30E0\r\n */\r\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/2\"\r\n\r\n#include <iostream>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n\r\n#include \"../../game/nim.hpp\"\r\n#include\
    \ \"../../math/prime_factorization.hpp\"\r\n\r\nint main() {\r\n  int n;\r\n \
    \ std::cin >> n;\r\n  std::vector<int> a;\r\n  for (const std::pair<int, int>&\
    \ p : prime_factorization(n)) {\r\n    a.emplace_back(p.second);\r\n  }\r\n  std::cout\
    \ << (nim(a) ? \"Alice\\n\" : \"Bob\\n\");\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - game/nim.hpp
  - math/prime_factorization.hpp
  isVerificationFile: true
  path: test/game/nim.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/game/nim.test.cpp
layout: document
redirect_from:
- /verify/test/game/nim.test.cpp
- /verify/test/game/nim.test.cpp.html
title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
---
