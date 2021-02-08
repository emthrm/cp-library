---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/lcm.hpp
    title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
    document_title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
  bundledCode: "#line 1 \"test/math/lcm.test.cpp\"\n/*\r\n * @brief \u6570\u5B66/\u6700\
    \u5C0F\u516C\u500D\u6570\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#line 3 \"math/lcm.hpp\"\
    \n\r\nlong long __lcm(long long a, long long b) { return a / std::__gcd(a, b)\
    \ * b; }\r\n#line 9 \"test/math/lcm.test.cpp\"\n\r\nint main() {\r\n  int n;\r\
    \n  std::cin >> n;\r\n  int ans = 1;\r\n  while (n--) {\r\n    int a;\r\n    std::cin\
    \ >> a;\r\n    ans = __lcm(ans, a);\r\n  }\r\n  std::cout << ans << '\\n';\r\n\
    \  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include \"../../math/lcm.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  int ans = 1;\r\n  while\
    \ (n--) {\r\n    int a;\r\n    std::cin >> a;\r\n    ans = __lcm(ans, a);\r\n\
    \  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/lcm.hpp
  isVerificationFile: true
  path: test/math/lcm.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/lcm.test.cpp
layout: document
redirect_from:
- /verify/test/math/lcm.test.cpp
- /verify/test/math/lcm.test.cpp.html
title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
---
