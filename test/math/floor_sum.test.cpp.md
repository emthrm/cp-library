---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/floor_sum.hpp
    title: sum of floor of linear
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    document_title: "\u6570\u5B66/sum of floor of linear"
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/math/floor_sum.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /sum of floor of linear\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"math/floor_sum.hpp\"\n#include <utility>\r\
    \n\r\nlong long floor_sum(long long a, long long b, long long m, long long n)\
    \ {\r\n  long long res = 0;\r\n  if (a < 0) {\r\n    long long nxt_a = a % m;\r\
    \n    if (nxt_a < 0) nxt_a += m;\r\n    res -= n * (n - 1) / 2 * ((nxt_a - a)\
    \ / m);\r\n    a = nxt_a;\r\n  }\r\n  if (b < 0) {\r\n    long long nxt_b = b\
    \ % m;\r\n    if (nxt_b < 0) nxt_b += m;\r\n    res -= n * ((nxt_b - b) / m);\r\
    \n    b = nxt_b;\r\n  }\r\n  while (true) {\r\n    if (a >= m) {\r\n      res\
    \ += n * (n - 1) / 2 * (a / m);\r\n      a %= m;\r\n    }\r\n    if (b >= m) {\r\
    \n      res += n * (b / m);\r\n      b %= m;\r\n    }\r\n    const long long y_max\
    \ = a * n + b;\r\n    if (y_max < m) break;\r\n    b = y_max % m;\r\n    n = y_max\
    \ / m;\r\n    std::swap(a, m);\r\n  }\r\n  return res;\r\n}\r\n#line 9 \"test/math/floor_sum.test.cpp\"\
    \n\r\nint main() {\r\n  int t;\r\n  std::cin >> t;\r\n  while (t--) {\r\n    int\
    \ n, m, a, b;\r\n    std::cin >> n >> m >> a >> b;\r\n    std::cout << floor_sum(a,\
    \ b, m, n) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/sum of floor of linear\r\n */\r\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\n\r\n#include <iostream>\r\
    \n\r\n#include \"../../math/floor_sum.hpp\"\r\n\r\nint main() {\r\n  int t;\r\n\
    \  std::cin >> t;\r\n  while (t--) {\r\n    int n, m, a, b;\r\n    std::cin >>\
    \ n >> m >> a >> b;\r\n    std::cout << floor_sum(a, b, m, n) << '\\n';\r\n  }\r\
    \n  return 0;\r\n}\r\n"
  dependsOn:
  - math/floor_sum.hpp
  isVerificationFile: true
  path: test/math/floor_sum.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/floor_sum.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor_sum.test.cpp
- /verify/test/math/floor_sum.test.cpp.html
title: "\u6570\u5B66/sum of floor of linear"
---
