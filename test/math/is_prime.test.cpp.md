---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/is_prime.hpp
    title: "\u7D20\u6570\u5224\u5B9A (primality test)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    document_title: "\u6570\u5B66/\u7D20\u6570\u5224\u5B9A"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/math/is_prime.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u7D20\u6570\u5224\u5B9A\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"math/is_prime.hpp\"\n\r\nbool is_prime(long\
    \ long val) {\r\n  if (val <= 1) return false;\r\n  for (long long i = 2; i *\
    \ i <= val; ++i) {\r\n    if (val % i == 0) return false;\r\n  }\r\n  return true;\r\
    \n}\r\n#line 8 \"test/math/is_prime.test.cpp\"\n\r\nint main() {\r\n  int n;\r\
    \n  std::cin >> n;\r\n  int ans = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n  \
    \  int query;\r\n    std::cin >> query;\r\n    if (is_prime(query)) ++ans;\r\n\
    \  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7D20\u6570\u5224\u5B9A\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\r\n\r\
    \n#include <iostream>\r\n#include \"../../math/is_prime.hpp\"\r\n\r\nint main()\
    \ {\r\n  int n;\r\n  std::cin >> n;\r\n  int ans = 0;\r\n  for (int i = 0; i <\
    \ n; ++i) {\r\n    int query;\r\n    std::cin >> query;\r\n    if (is_prime(query))\
    \ ++ans;\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/is_prime.hpp
  isVerificationFile: true
  path: test/math/is_prime.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/is_prime.test.cpp
layout: document
redirect_from:
- /verify/test/math/is_prime.test.cpp
- /verify/test/math/is_prime.test.cpp.html
title: "\u6570\u5B66/\u7D20\u6570\u5224\u5B9A"
---
