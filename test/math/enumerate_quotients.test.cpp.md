---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/enumerate_quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc230/tasks/abc230_e
    document_title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
    links:
    - https://atcoder.jp/contests/abc230/tasks/abc230_e
  bundledCode: "#line 1 \"test/math/enumerate_quotients.test.cpp\"\n/*\r\n * @brief\
    \ \u6570\u5B66/\u5546\u306E\u5217\u6319\r\n */\r\n#define PROBLEM \"https://atcoder.jp/contests/abc230/tasks/abc230_e\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n\r\n#line 3 \"math/enumerate_quotients.hpp\"\
    \n#include <vector>\r\n\r\ntemplate <typename T>\r\nstd::vector<std::tuple<T,\
    \ T, T>> enumerate_quotients(const T n) {\r\n  std::vector<std::tuple<T, T, T>>\
    \ quotients;\r\n  for (T l = 1; l <= n;) {\r\n    const T quotient = n / l, r\
    \ = n / quotient + 1;\r\n    quotients.emplace_back(l, r, quotient);\r\n    l\
    \ = r;\r\n  }\r\n  return quotients;\r\n}\r\n#line 10 \"test/math/enumerate_quotients.test.cpp\"\
    \n\r\nint main() {\r\n  long long n;\r\n  std::cin >> n;\r\n  long long ans =\
    \ 0;\r\n  for (const std::tuple<long long, long long, long long>& lrq\r\n    \
    \   : enumerate_quotients(n)) {\r\n    long long l, r, q;\r\n    std::tie(l, r,\
    \ q) = lrq;\r\n    ans += q * (r - l);\r\n  }\r\n  std::cout << ans << '\\n';\r\
    \n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5546\u306E\u5217\u6319\r\n */\r\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc230/tasks/abc230_e\"\r\n\r\n#include <iostream>\r\
    \n#include <tuple>\r\n\r\n#include \"../../math/enumerate_quotients.hpp\"\r\n\r\
    \nint main() {\r\n  long long n;\r\n  std::cin >> n;\r\n  long long ans = 0;\r\
    \n  for (const std::tuple<long long, long long, long long>& lrq\r\n       : enumerate_quotients(n))\
    \ {\r\n    long long l, r, q;\r\n    std::tie(l, r, q) = lrq;\r\n    ans += q\
    \ * (r - l);\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/enumerate_quotients.hpp
  isVerificationFile: true
  path: test/math/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_quotients.test.cpp
- /verify/test/math/enumerate_quotients.test.cpp.html
title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
---
