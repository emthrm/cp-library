---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  - icon: ':heavy_check_mark:'
    path: math/simultaneous_linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/186
    document_title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
    links:
    - https://yukicoder.me/problems/no/186
  bundledCode: "#line 1 \"test/math/simultaneous_linear_congruence.test.cpp\"\n/*\r\
    \n * @brief \u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F\r\n */\r\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/186\"\r\n\r\n#include <iostream>\r\
    \n#include <tuple>\r\n#include <vector>\r\n#line 2 \"math/simultaneous_linear_congruence.hpp\"\
    \n#include <algorithm>\r\n#include <utility>\r\n#line 4 \"math/mod_inv.hpp\"\n\
    \r\nlong long mod_inv(long long a, int m) {\r\n  if ((a %= m) < 0) a += m;\r\n\
    \  if (std::__gcd(a, static_cast<long long>(m)) != 1) return -1;\r\n  long long\
    \ b = m, x = 1, u = 0;\r\n  while (b > 0) {\r\n    long long q = a / b;\r\n  \
    \  std::swap(a -= q * b, b);\r\n    std::swap(x -= q * u, u);\r\n  }\r\n  x %=\
    \ m;\r\n  return x < 0 ? x + m : x;\r\n}\r\n#line 6 \"math/simultaneous_linear_congruence.hpp\"\
    \n\r\ntemplate <typename T>\r\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T> &a, const std::vector<T> &b, const std::vector<T> &m) {\r\n \
    \ const int n = a.size();\r\n  T x = 0, md = 1;\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    const T l = md * a[i], r = -x * a[i] + b[i], g = std::__gcd(l, m[i]);\r\
    \n    if (r % g != 0) return {0, -1};\r\n    x += md * (r / g * mod_inv(l / g,\
    \ m[i] / g) % (m[i] / g));\r\n    md *= m[i] / g;\r\n  }\r\n  return {x < 0 ?\
    \ x + md : x, md};\r\n}\r\n#line 10 \"test/math/simultaneous_linear_congruence.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr int N = 3;\r\n  std::vector<long long> x(N),\
    \ y(N);\r\n  for (int i = 0; i < N; ++i) {\r\n    std::cin >> x[i] >> y[i];\r\n\
    \  }\r\n  long long ans, mod;\r\n  std::tie(ans, mod) = simultaneous_linear_congruence(std::vector<long\
    \ long>(N, 1), x, y);\r\n  if (mod == 0) {\r\n    std::cout << \"-1\\n\";\r\n\
    \  } else {\r\n    std::cout << (ans == 0 ? mod : ans) << '\\n';\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F\r\
    \n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/186\"\r\n\r\n#include\
    \ <iostream>\r\n#include <tuple>\r\n#include <vector>\r\n#include \"../../math/simultaneous_linear_congruence.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr int N = 3;\r\n  std::vector<long long> x(N),\
    \ y(N);\r\n  for (int i = 0; i < N; ++i) {\r\n    std::cin >> x[i] >> y[i];\r\n\
    \  }\r\n  long long ans, mod;\r\n  std::tie(ans, mod) = simultaneous_linear_congruence(std::vector<long\
    \ long>(N, 1), x, y);\r\n  if (mod == 0) {\r\n    std::cout << \"-1\\n\";\r\n\
    \  } else {\r\n    std::cout << (ans == 0 ? mod : ans) << '\\n';\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - math/simultaneous_linear_congruence.hpp
  - math/mod_inv.hpp
  isVerificationFile: true
  path: test/math/simultaneous_linear_congruence.test.cpp
  requiredBy: []
  timestamp: '2021-09-24 15:41:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/simultaneous_linear_congruence.test.cpp
layout: document
redirect_from:
- /verify/test/math/simultaneous_linear_congruence.test.cpp
- /verify/test/math/simultaneous_linear_congruence.test.cpp.html
title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
---
