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
  bundledCode: "#line 1 \"test/math/segmented_sieve.test.cpp\"\n/*\n * @brief \u6570\
    \u5B66/segmented sieve\n */\n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 3 \"\
    math/segmented_sieve.hpp\"\n#include <cmath>\n#include <iterator>\n#line 6 \"\
    math/segmented_sieve.hpp\"\n\nstd::vector<bool> segmented_sieve(const long long\
    \ low, const long long high) {\n  long long root = 1;\n  while ((root + 1) * (root\
    \ + 1) < high) ++root;\n  std::vector<bool> is_prime(root + 1, true);\n  is_prime[0]\
    \ = false;\n  is_prime[1] = false;\n  std::vector<bool> res(high - low, true);\n\
    \  if (low < 2) std::fill(res.begin(), std::next(res.begin(), 2 - low), false);\n\
    \  for (long long i = 2; i <= root; ++i) {\n    if (is_prime[i]) {\n      for\
    \ (long long j = i * i; j <= root; j += i) {\n        is_prime[j] = false;\n \
    \     }\n      for (long long j = std::max((low + i - 1) / i, 2LL) * i; j < high;\n\
    \           j += i) {\n        res[j - low] = false;\n      }\n    }\n  }\n  return\
    \ res;\n}\n#line 12 \"test/math/segmented_sieve.test.cpp\"\n\nint main() {\n \
    \ long long l, r;\n  std::cin >> l >> r;\n  const std::vector<bool> is_prime =\
    \ segmented_sieve(l, r + 1);\n  std::cout << std::count(is_prime.begin(), is_prime.end(),\
    \ true) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/segmented sieve\n */\n#define IGNORE\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    ../../math/segmented_sieve.hpp\"\n\nint main() {\n  long long l, r;\n  std::cin\
    \ >> l >> r;\n  const std::vector<bool> is_prime = segmented_sieve(l, r + 1);\n\
    \  std::cout << std::count(is_prime.begin(), is_prime.end(), true) << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - math/segmented_sieve.hpp
  isVerificationFile: true
  path: test/math/segmented_sieve.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/segmented_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/math/segmented_sieve.test.cpp
- /verify/test/math/segmented_sieve.test.cpp.html
title: "\u6570\u5B66/segmented sieve"
---
