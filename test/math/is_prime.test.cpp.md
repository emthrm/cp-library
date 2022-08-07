---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A (primality test)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    document_title: "\u6570\u5B66/\u7D20\u6570\u5224\u5B9A"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/math/is_prime.test.cpp\"\n/*\n * @brief \u6570\u5B66\
    /\u7D20\u6570\u5224\u5B9A\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <iostream>\n\n#line 2 \"math/is_prime.hpp\"\n\nbool is_prime(const\
    \ long long n) {\n  if (n <= 1) return false;\n  for (long long i = 2; i * i <=\
    \ n; ++i) {\n    if (n % i == 0) return false;\n  }\n  return true;\n}\n#line\
    \ 9 \"test/math/is_prime.test.cpp\"\n\nint main() {\n  int n;\n  std::cin >> n;\n\
    \  int ans = 0;\n  for (int i = 0; i < n; ++i) {\n    int num;\n    std::cin >>\
    \ num;\n    if (is_prime(num)) ++ans;\n  }\n  std::cout << ans << '\\n';\n  return\
    \ 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u7D20\u6570\u5224\u5B9A\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n\n#include\
    \ <iostream>\n\n#include \"../../math/is_prime.hpp\"\n\nint main() {\n  int n;\n\
    \  std::cin >> n;\n  int ans = 0;\n  for (int i = 0; i < n; ++i) {\n    int num;\n\
    \    std::cin >> num;\n    if (is_prime(num)) ++ans;\n  }\n  std::cout << ans\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/is_prime.hpp
  isVerificationFile: true
  path: test/math/is_prime.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/is_prime.test.cpp
layout: document
redirect_from:
- /verify/test/math/is_prime.test.cpp
- /verify/test/math/is_prime.test.cpp.html
title: "\u6570\u5B66/\u7D20\u6570\u5224\u5B9A"
---
