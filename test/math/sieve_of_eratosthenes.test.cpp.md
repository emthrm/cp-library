---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/sieve_of_eratosthenes.hpp
    title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9 (sieve of Eratosthenes)"
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
    document_title: "\u6570\u5B66/\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
      \u7BE9"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009
  bundledCode: "#line 1 \"test/math/sieve_of_eratosthenes.test.cpp\"\n/*\r\n * @brief\
    \ \u6570\u5B66/\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\r\n */\r\
    \n#define IGNORE\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n\
    #include <vector>\r\n#line 3 \"math/sieve_of_eratosthenes.hpp\"\n\r\nstd::vector<bool>\
    \ sieve_of_eratosthenes(int n) {\r\n  std::vector<bool> res(n + 1, true);\r\n\
    \  res[0] = false;\r\n  if (n >= 1) res[1] = false;\r\n  for (int i = 2; i * i\
    \ <= n; ++i) {\r\n    if (res[i]) {\r\n      for (int j = i * i; j <= n; j +=\
    \ i) res[j] = false;\r\n    }\r\n  }\r\n  return res;\r\n}\r\n#line 12 \"test/math/sieve_of_eratosthenes.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr int MAX = 999999;\r\n  std::vector<bool> table\
    \ = sieve_of_eratosthenes(MAX);\r\n  std::vector<int> primes;\r\n  for (int i\
    \ = 2; i <= MAX; ++i) {\r\n    if (table[i]) primes.emplace_back(i);\r\n  }\r\n\
    \  int n;\r\n  while (std::cin >> n) {\r\n    std::cout << std::distance(primes.begin(),\
    \ std::upper_bound(primes.begin(), primes.end(), n)) << '\\n';\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n\
    #include <vector>\r\n#include \"../../math/sieve_of_eratosthenes.hpp\"\r\n\r\n\
    int main() {\r\n  constexpr int MAX = 999999;\r\n  std::vector<bool> table = sieve_of_eratosthenes(MAX);\r\
    \n  std::vector<int> primes;\r\n  for (int i = 2; i <= MAX; ++i) {\r\n    if (table[i])\
    \ primes.emplace_back(i);\r\n  }\r\n  int n;\r\n  while (std::cin >> n) {\r\n\
    \    std::cout << std::distance(primes.begin(), std::upper_bound(primes.begin(),\
    \ primes.end(), n)) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/sieve_of_eratosthenes.hpp
  isVerificationFile: true
  path: test/math/sieve_of_eratosthenes.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/sieve_of_eratosthenes.test.cpp
layout: document
redirect_from:
- /verify/test/math/sieve_of_eratosthenes.test.cpp
- /verify/test/math/sieve_of_eratosthenes.test.cpp.html
title: "\u6570\u5B66/\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
