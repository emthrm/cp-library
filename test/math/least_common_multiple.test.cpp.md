---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/least_common_multiple.hpp
    title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
    document_title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
  bundledCode: "#line 1 \"test/math/least_common_multiple.test.cpp\"\n/*\n * @brief\
    \ \u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#line 3 \"math/least_common_multiple.hpp\"\
    \n\nlong long __lcm(const long long a, const long long b) {\n  return a / std::__gcd(a,\
    \ b) * b;\n}\n#line 10 \"test/math/least_common_multiple.test.cpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  int ans = 1;\n  while (n--) {\n    int a;\n\
    \    std::cin >> a;\n    ans = __lcm(ans, a);\n  }\n  std::cout << ans << '\\\
    n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n\n#include \"../../math/least_common_multiple.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  int ans = 1;\n  while (n--) {\n\
    \    int a;\n    std::cin >> a;\n    ans = __lcm(ans, a);\n  }\n  std::cout <<\
    \ ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/least_common_multiple.hpp
  isVerificationFile: true
  path: test/math/least_common_multiple.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/least_common_multiple.test.cpp
layout: document
redirect_from:
- /verify/test/math/least_common_multiple.test.cpp
- /verify/test/math/least_common_multiple.test.cpp.html
title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
---
