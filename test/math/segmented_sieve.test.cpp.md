---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/segmented_sieve.hpp
    title: segmented sieve
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
    document_title: "\u6570\u5B66/segmented sieve"
    links:
    - https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt
  bundledCode: "#line 1 \"test/math/segmented_sieve.test.cpp\"\n/*\r\n * @brief \u6570\
    \u5B66/segmented sieve\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n\r\
    \n#line 3 \"math/segmented_sieve.hpp\"\n#include <cmath>\r\n#include <iterator>\r\
    \n#line 6 \"math/segmented_sieve.hpp\"\n\r\nstd::vector<bool> segmented_sieve(const\
    \ long long low, const long long high) {\r\n  long long root = 1;\r\n  while ((root\
    \ + 1) * (root + 1) < high) ++root;\r\n  std::vector<bool> is_prime(root + 1,\
    \ true);\r\n  is_prime[0] = false;\r\n  is_prime[1] = false;\r\n  std::vector<bool>\
    \ res(high - low, true);\r\n  if (low < 2) std::fill(res.begin(), std::next(res.begin(),\
    \ 2 - low), false);\r\n  for (long long i = 2; i <= root; ++i) {\r\n    if (is_prime[i])\
    \ {\r\n      for (long long j = i * i; j <= root; j += i) {\r\n        is_prime[j]\
    \ = false;\r\n      }\r\n      for (long long j = std::max((low + i - 1) / i,\
    \ 2LL) * i; j < high;\r\n           j += i) {\r\n        res[j - low] = false;\r\
    \n      }\r\n    }\r\n  }\r\n  return res;\r\n}\r\n#line 12 \"test/math/segmented_sieve.test.cpp\"\
    \n\r\nint main() {\r\n  long long l, r;\r\n  std::cin >> l >> r;\r\n  const std::vector<bool>\
    \ is_prime = segmented_sieve(l, r + 1);\r\n  std::cout << std::count(is_prime.begin(),\
    \ is_prime.end(), true) << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/segmented sieve\r\n */\r\n#define IGNORE\r\n\
    #define PROBLEM \"https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n\r\
    \n#include \"../../math/segmented_sieve.hpp\"\r\n\r\nint main() {\r\n  long long\
    \ l, r;\r\n  std::cin >> l >> r;\r\n  const std::vector<bool> is_prime = segmented_sieve(l,\
    \ r + 1);\r\n  std::cout << std::count(is_prime.begin(), is_prime.end(), true)\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/segmented_sieve.hpp
  isVerificationFile: true
  path: test/math/segmented_sieve.test.cpp
  requiredBy: []
  timestamp: '2022-02-24 04:47:48+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/segmented_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/math/segmented_sieve.test.cpp
- /verify/test/math/segmented_sieve.test.cpp.html
title: "\u6570\u5B66/segmented sieve"
---
