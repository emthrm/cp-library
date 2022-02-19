---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    document_title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/math/prime_factorization.test.cpp\"\n/*\r\n * @brief\
    \ \u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \r\n\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n\r\n\
    #line 4 \"math/prime_factorization.hpp\"\n\r\ntemplate <typename T>\r\nstd::vector<std::pair<T,\
    \ int>> prime_factorization(T n) {\r\n  std::vector<std::pair<T, int>> res;\r\n\
    \  for (T i = 2; i * i <= n; ++i) {\r\n    if (n % i == 0) {\r\n      int exponent\
    \ = 0;\r\n      for (; n % i == 0; n /= i) {\r\n        ++exponent;\r\n      }\r\
    \n      res.emplace_back(i, exponent);\r\n    }\r\n  }\r\n  if (n > 1) res.emplace_back(n,\
    \ 1);\r\n  return res;\r\n}\r\n#line 11 \"test/math/prime_factorization.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  const std::vector<std::pair<int,\
    \ int>> ans = prime_factorization(n);\r\n  std::cout << n << \": \";\r\n  for\
    \ (int i = 0; i < ans.size(); ++i) {\r\n    for (int j = 0; j < ans[i].second;\
    \ ++j) {\r\n      std::cout << ans[i].first\r\n                << \" \\n\"[i +\
    \ 1 == ans.size() && j + 1 == ans[i].second];\r\n    }\r\n  }\r\n  return 0;\r\
    \n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \r\n\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n\r\n\
    #include \"../../math/prime_factorization.hpp\"\r\n\r\nint main() {\r\n  int n;\r\
    \n  std::cin >> n;\r\n  const std::vector<std::pair<int, int>> ans = prime_factorization(n);\r\
    \n  std::cout << n << \": \";\r\n  for (int i = 0; i < ans.size(); ++i) {\r\n\
    \    for (int j = 0; j < ans[i].second; ++j) {\r\n      std::cout << ans[i].first\r\
    \n                << \" \\n\"[i + 1 == ans.size() && j + 1 == ans[i].second];\r\
    \n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/prime_factorization.hpp
  isVerificationFile: true
  path: test/math/prime_factorization.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/prime_factorization.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime_factorization.test.cpp
- /verify/test/math/prime_factorization.test.cpp.html
title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
---
