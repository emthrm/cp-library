---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/chinese_remainder_theorem.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
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
  bundledCode: "#line 1 \"test/math/chinese_remainder_theorem.test.cpp\"\n/*\r\n *\
    \ @brief \u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\r\n */\r\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/186\"\r\n\r\n#include <iostream>\r\n#include\
    \ <tuple>\r\n#include <vector>\r\n#line 2 \"math/chinese_remainder_theorem.hpp\"\
    \n#include <algorithm>\r\n#include <utility>\r\n#line 4 \"math/mod_inv.hpp\"\n\
    \r\nlong long mod_inv(long long a, int m) {\r\n  if ((a %= m) < 0) a += m;\r\n\
    \  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;\r\n  long long\
    \ b = m, x = 1, u = 0;\r\n  while (b > 0) {\r\n    long long q = a / b;\r\n  \
    \  std::swap(a -= q * b, b);\r\n    std::swap(x -= q * u, u);\r\n  }\r\n  x %=\
    \ m;\r\n  return x < 0 ? x + m : x;\r\n}\r\n#line 6 \"math/chinese_remainder_theorem.hpp\"\
    \n\r\ntemplate <typename T>\r\nstd::pair<T, T> chinese_remainder_theorem(std::vector<T>\
    \ b, std::vector<T> m) {\r\n  const int n = b.size();\r\n  T x = 0, md = 1;\r\n\
    \  for (int i = 0; i < n; ++i) {\r\n    if ((b[i] %= m[i]) < 0) {\r\n      b[i]\
    \ += m[i];\r\n    }\r\n    if (md < m[i]) {\r\n      std::swap(x, b[i]);\r\n \
    \     std::swap(md, m[i]);\r\n    }\r\n    if (md % m[i] == 0) {\r\n      if (x\
    \ % m[i] != b[i]) return {0, 0};\r\n      continue;\r\n    }\r\n    const T g\
    \ = std::__gcd(md, m[i]);\r\n    if ((b[i] - x) % g != 0) return {0, 0};\r\n \
    \   const T u_i = m[i] / g;\r\n    x += (b[i] - x) / g % u_i * mod_inv(md / g,\
    \ u_i) % u_i * md;\r\n    md *= u_i;\r\n    if (x < 0) {\r\n      x += md;\r\n\
    \    }\r\n  }\r\n  return {x, md};\r\n}\r\n#line 10 \"test/math/chinese_remainder_theorem.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr int N = 3;\r\n  std::vector<long long> x(N),\
    \ y(N);\r\n  for (int i = 0; i < N; ++i) {\r\n    std::cin >> x[i] >> y[i];\r\n\
    \  }\r\n  long long ans, mod;\r\n  std::tie(ans, mod) = chinese_remainder_theorem(x,\
    \ y);\r\n  if (mod == 0) {\r\n    std::cout << \"-1\\n\";\r\n  } else {\r\n  \
    \  std::cout << (ans == 0 ? mod : ans) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\r\n */\r\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/186\"\r\n\r\n#include <iostream>\r\
    \n#include <tuple>\r\n#include <vector>\r\n#include \"../../math/chinese_remainder_theorem.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr int N = 3;\r\n  std::vector<long long> x(N),\
    \ y(N);\r\n  for (int i = 0; i < N; ++i) {\r\n    std::cin >> x[i] >> y[i];\r\n\
    \  }\r\n  long long ans, mod;\r\n  std::tie(ans, mod) = chinese_remainder_theorem(x,\
    \ y);\r\n  if (mod == 0) {\r\n    std::cout << \"-1\\n\";\r\n  } else {\r\n  \
    \  std::cout << (ans == 0 ? mod : ans) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/chinese_remainder_theorem.hpp
  - math/mod_inv.hpp
  isVerificationFile: true
  path: test/math/chinese_remainder_theorem.test.cpp
  requiredBy: []
  timestamp: '2021-09-24 15:41:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/chinese_remainder_theorem.test.cpp
layout: document
redirect_from:
- /verify/test/math/chinese_remainder_theorem.test.cpp
- /verify/test/math/chinese_remainder_theorem.test.cpp.html
title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---
