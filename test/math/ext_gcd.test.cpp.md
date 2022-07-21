---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/ext_gcd.hpp
    title: "\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5 (extended Euclidean algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    document_title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/math/ext_gcd.test.cpp\"\n/*\n * @brief \u6570\u5B66\
    /\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n#include <tuple>\n\n#line 3 \"math/ext_gcd.hpp\"\n#include\
    \ <utility>\n\ntemplate <typename T>\nstd::pair<T, T> ext_gcd(T a, T b) {\n  T\
    \ x = 1, y = 0;\n  for (T u = 0, v = 1; b;) {\n    const T q = a / b;\n    std::swap(a\
    \ -= q * b, b);\n    std::swap(x -= q * u, u);\n    std::swap(y -= q * v, v);\n\
    \  }\n  return a < 0 ? std::make_pair(-x, -y) : std::make_pair(x, y);\n}\n#line\
    \ 10 \"test/math/ext_gcd.test.cpp\"\n\nint main() {\n  int a, b;\n  std::cin >>\
    \ a >> b;\n  int x, y;\n  std::tie(x, y) = ext_gcd(a, b);\n  std::cout << x <<\
    \ ' ' << y << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\n\
    \ */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n#include <tuple>\n\n#include \"../../math/ext_gcd.hpp\"\
    \n\nint main() {\n  int a, b;\n  std::cin >> a >> b;\n  int x, y;\n  std::tie(x,\
    \ y) = ext_gcd(a, b);\n  std::cout << x << ' ' << y << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: test/math/ext_gcd.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/ext_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/math/ext_gcd.test.cpp
- /verify/test/math/ext_gcd.test.cpp.html
title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
---
