---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: "\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5 (extended Euclidean algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    document_title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/math/ext_gcd.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n#line 3 \"math/ext_gcd.hpp\"\
    \n#include <utility>\r\n\r\ntemplate <typename T>\r\nstd::pair<T, T> ext_gcd(T\
    \ a, T b) {\r\n  if (b == 0) return {1, 0};\r\n  T fst, snd; std::tie(fst, snd)\
    \ = ext_gcd(b, a % b);\r\n  return {snd, fst - a / b * snd};\r\n}\r\n#line 9 \"\
    test/math/ext_gcd.test.cpp\"\n\r\nint main() {\r\n  int a, b;\r\n  std::cin >>\
    \ a >> b;\r\n  int x, y; std::tie(x, y) = ext_gcd(a, b);\r\n  std::cout << x <<\
    \ ' ' << y << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\
    \r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n#include \"../../math/ext_gcd.hpp\"\
    \r\n\r\nint main() {\r\n  int a, b;\r\n  std::cin >> a >> b;\r\n  int x, y; std::tie(x,\
    \ y) = ext_gcd(a, b);\r\n  std::cout << x << ' ' << y << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: test/math/ext_gcd.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/ext_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/math/ext_gcd.test.cpp
- /verify/test/math/ext_gcd.test.cpp.html
title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
---
