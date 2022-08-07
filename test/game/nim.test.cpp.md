---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: game/nim.hpp
    title: "\u30CB\u30E0 (nim)"
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/game/nim.test.cpp\"\n/*\n * @brief \u30B2\u30FC\u30E0\
    /\u30CB\u30E0\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/2\"\n\n\
    #include <iostream>\n#include <utility>\n#include <vector>\n\n#line 3 \"game/nim.hpp\"\
    \n\ntemplate <typename T>\nbool nim(const std::vector<T>& a) {\n  long long x\
    \ = 0;\n  for (const T e : a) x ^= e;\n  return x != 0;\n}\n#line 4 \"math/prime_factorization.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> prime_factorization(T\
    \ n) {\n  std::vector<std::pair<T, int>> res;\n  for (T i = 2; i * i <= n; ++i)\
    \ {\n    if (n % i == 0) {\n      int exponent = 0;\n      for (; n % i == 0;\
    \ n /= i) {\n        ++exponent;\n      }\n      res.emplace_back(i, exponent);\n\
    \    }\n  }\n  if (n > 1) res.emplace_back(n, 1);\n  return res;\n}\n#line 12\
    \ \"test/game/nim.test.cpp\"\n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int>\
    \ a;\n  for (const std::pair<int, int>& p : prime_factorization(n)) {\n    a.emplace_back(p.second);\n\
    \  }\n  std::cout << (nim(a) ? \"Alice\\n\" : \"Bob\\n\");\n  return 0;\n}\n"
  code: "/*\n * @brief \u30B2\u30FC\u30E0/\u30CB\u30E0\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/2\"\
    \n\n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"\
    ../../game/nim.hpp\"\n#include \"../../math/prime_factorization.hpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::vector<int> a;\n  for (const std::pair<int,\
    \ int>& p : prime_factorization(n)) {\n    a.emplace_back(p.second);\n  }\n  std::cout\
    \ << (nim(a) ? \"Alice\\n\" : \"Bob\\n\");\n  return 0;\n}\n"
  dependsOn:
  - game/nim.hpp
  - math/prime_factorization.hpp
  isVerificationFile: true
  path: test/game/nim.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/game/nim.test.cpp
layout: document
redirect_from:
- /verify/test/game/nim.test.cpp
- /verify/test/game/nim.test.cpp.html
title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
---
