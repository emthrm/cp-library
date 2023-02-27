---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/ext_gcd.hpp
    title: "\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5 (extended Euclidean algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    document_title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/math/ext_gcd.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\n *\n * verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\n */\n\n#include\
    \ <iostream>\n\n#line 1 \"include/emthrm/math/ext_gcd.hpp\"\n\n\n\n#include <tuple>\n\
    #include <utility>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::pair<T,\
    \ T> ext_gcd(T a, T b) {\n  T x = 1, y = 0;\n  for (T u = 0, v = 1; b;) {\n  \
    \  const T q = a / b;\n    std::swap(a -= q * b, b);\n    std::swap(x -= q * u,\
    \ u);\n    std::swap(y -= q * v, v);\n  }\n  return a < 0 ? std::make_pair(-x,\
    \ -y) : std::make_pair(x, y);\n}\n\n}  // namespace emthrm\n\n\n#line 10 \"test/math/ext_gcd.test.cpp\"\
    \n\nint main() {\n  int a, b;\n  std::cin >> a >> b;\n  const auto [x, y] = emthrm::ext_gcd(a,\
    \ b);\n  std::cout << x << ' ' << y << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\n\
    \ *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/math/ext_gcd.hpp\"\n\nint main()\
    \ {\n  int a, b;\n  std::cin >> a >> b;\n  const auto [x, y] = emthrm::ext_gcd(a,\
    \ b);\n  std::cout << x << ' ' << y << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/ext_gcd.hpp
  isVerificationFile: true
  path: test/math/ext_gcd.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/ext_gcd.test.cpp
layout: document
redirect_from:
- /verify/test/math/ext_gcd.test.cpp
- /verify/test/math/ext_gcd.test.cpp.html
title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
---
