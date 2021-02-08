---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/crt.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
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
    PROBLEM: https://yukicoder.me/problems/no/186
    document_title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
    links:
    - https://yukicoder.me/problems/no/186
  bundledCode: "#line 1 \"test/math/crt.test.cpp\"\n/*\r\n * @brief \u6570\u5B66/\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/186\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n#include <vector>\r\n#line\
    \ 2 \"math/crt.hpp\"\n#include <algorithm>\r\n#include <utility>\r\n#line 4 \"\
    math/ext_gcd.hpp\"\n\r\ntemplate <typename T>\r\nstd::pair<T, T> ext_gcd(T a,\
    \ T b) {\r\n  if (b == 0) return {1, 0};\r\n  T fst, snd; std::tie(fst, snd) =\
    \ ext_gcd(b, a % b);\r\n  return {snd, fst - a / b * snd};\r\n}\r\n#line 6 \"\
    math/crt.hpp\"\n\r\ntemplate <typename T>\r\nstd::pair<T, T> crt(const std::vector<T>\
    \ &b, const std::vector<T> &m) {\r\n  T x = 0, md = 1;\r\n  int n = b.size();\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    T g = std::__gcd(md, m[i]);\r\n    if\
    \ ((b[i] - x) % g != 0) return {0, -1};\r\n    x += md * ((b[i] - x) / g * ext_gcd(md,\
    \ m[i]).first % (m[i] / g));\r\n    md *= m[i] / g;\r\n  }\r\n  return {x < 0\
    \ ? x + md : x, md};\r\n}\r\n#line 10 \"test/math/crt.test.cpp\"\n\r\nint main()\
    \ {\r\n  constexpr int N = 3;\r\n  std::vector<long long> x(N), y(N);\r\n  for\
    \ (int i = 0; i < N; ++i) std::cin >> x[i] >> y[i];\r\n  long long ans, mod; std::tie(ans,\
    \ mod) = crt(x, y);\r\n  if (mod == -1) {\r\n    std::cout << \"-1\\n\";\r\n \
    \ } else {\r\n    std::cout << (ans == 0 ? mod : ans) << '\\n';\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\r\n */\r\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/186\"\r\n\r\n#include <iostream>\r\
    \n#include <tuple>\r\n#include <vector>\r\n#include \"../../math/crt.hpp\"\r\n\
    \r\nint main() {\r\n  constexpr int N = 3;\r\n  std::vector<long long> x(N), y(N);\r\
    \n  for (int i = 0; i < N; ++i) std::cin >> x[i] >> y[i];\r\n  long long ans,\
    \ mod; std::tie(ans, mod) = crt(x, y);\r\n  if (mod == -1) {\r\n    std::cout\
    \ << \"-1\\n\";\r\n  } else {\r\n    std::cout << (ans == 0 ? mod : ans) << '\\\
    n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/crt.hpp
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: test/math/crt.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/crt.test.cpp
layout: document
redirect_from:
- /verify/test/math/crt.test.cpp
- /verify/test/math/crt.test.cpp.html
title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---
