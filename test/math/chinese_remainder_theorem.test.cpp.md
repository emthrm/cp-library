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
  bundledCode: "#line 1 \"test/math/chinese_remainder_theorem.test.cpp\"\n/*\n * @brief\
    \ \u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/186\"\
    \n\n#include <iostream>\n#include <tuple>\n#include <vector>\n\n#line 2 \"math/chinese_remainder_theorem.hpp\"\
    \n#include <algorithm>\n#include <utility>\n#line 5 \"math/chinese_remainder_theorem.hpp\"\
    \n\n#line 4 \"math/mod_inv.hpp\"\n\nlong long mod_inv(long long a, const int m)\
    \ {\n  if ((a %= m) < 0) a += m;\n  if (std::__gcd(a, static_cast<long long>(m))\
    \ != 1) return -1;\n  long long x = 1;\n  for (long long b = m, u = 0; b > 0;)\
    \ {\n    const long long q = a / b;\n    std::swap(a -= q * b, b);\n    std::swap(x\
    \ -= q * u, u);\n  }\n  x %= m;\n  return x < 0 ? x + m : x;\n}\n#line 7 \"math/chinese_remainder_theorem.hpp\"\
    \n\ntemplate <typename T>\nstd::pair<T, T> chinese_remainder_theorem(std::vector<T>\
    \ b, std::vector<T> m) {\n  const int n = b.size();\n  T x = 0, md = 1;\n  for\
    \ (int i = 0; i < n; ++i) {\n    if ((b[i] %= m[i]) < 0) b[i] += m[i];\n    if\
    \ (md < m[i]) {\n      std::swap(x, b[i]);\n      std::swap(md, m[i]);\n    }\n\
    \    if (md % m[i] == 0) {\n      if (x % m[i] != b[i]) return {0, 0};\n     \
    \ continue;\n    }\n    const T g = std::__gcd(md, m[i]);\n    if ((b[i] - x)\
    \ % g != 0) return {0, 0};\n    const T u_i = m[i] / g;\n    x += (b[i] - x) /\
    \ g % u_i * mod_inv(md / g, u_i) % u_i * md;\n    md *= u_i;\n    if (x < 0) x\
    \ += md;\n  }\n  return {x, md};\n}\n#line 11 \"test/math/chinese_remainder_theorem.test.cpp\"\
    \n\nint main() {\n  constexpr int N = 3;\n  std::vector<long long> x(N), y(N);\n\
    \  for (int i = 0; i < N; ++i) {\n    std::cin >> x[i] >> y[i];\n  }\n  long long\
    \ ans, mod;\n  std::tie(ans, mod) = chinese_remainder_theorem(x, y);\n  if (mod\
    \ == 0) {\n    std::cout << \"-1\\n\";\n  } else {\n    std::cout << (ans == 0\
    \ ? mod : ans) << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\n */\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/186\"\n\n#include <iostream>\n#include\
    \ <tuple>\n#include <vector>\n\n#include \"../../math/chinese_remainder_theorem.hpp\"\
    \n\nint main() {\n  constexpr int N = 3;\n  std::vector<long long> x(N), y(N);\n\
    \  for (int i = 0; i < N; ++i) {\n    std::cin >> x[i] >> y[i];\n  }\n  long long\
    \ ans, mod;\n  std::tie(ans, mod) = chinese_remainder_theorem(x, y);\n  if (mod\
    \ == 0) {\n    std::cout << \"-1\\n\";\n  } else {\n    std::cout << (ans == 0\
    \ ? mod : ans) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/chinese_remainder_theorem.hpp
  - math/mod_inv.hpp
  isVerificationFile: true
  path: test/math/chinese_remainder_theorem.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/chinese_remainder_theorem.test.cpp
layout: document
redirect_from:
- /verify/test/math/chinese_remainder_theorem.test.cpp
- /verify/test/math/chinese_remainder_theorem.test.cpp.html
title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---
