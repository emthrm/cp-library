---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/least_common_multiple.hpp
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
  bundledCode: "#line 1 \"test/math/least_common_multiple.test.cpp\"\n/*\r\n * @brief\
    \ \u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n\r\n#line 3 \"math/least_common_multiple.hpp\"\
    \n\r\nlong long __lcm(const long long a, const long long b) {\r\n  return a /\
    \ std::__gcd(a, b) * b;\r\n}\r\n#line 10 \"test/math/least_common_multiple.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  int ans = 1;\r\n  while\
    \ (n--) {\r\n    int a;\r\n    std::cin >> a;\r\n    ans = __lcm(ans, a);\r\n\
    \  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n\r\n#include \"../../math/least_common_multiple.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  int ans = 1;\r\n  while\
    \ (n--) {\r\n    int a;\r\n    std::cin >> a;\r\n    ans = __lcm(ans, a);\r\n\
    \  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/least_common_multiple.hpp
  isVerificationFile: true
  path: test/math/least_common_multiple.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/least_common_multiple.test.cpp
layout: document
redirect_from:
- /verify/test/math/least_common_multiple.test.cpp
- /verify/test/math/least_common_multiple.test.cpp.html
title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
---
