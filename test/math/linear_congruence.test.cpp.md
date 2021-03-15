---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (linear congruence)"
  - icon: ':question:'
    path: math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
    links:
    - https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d
  bundledCode: "#line 1 \"test/math/linear_congruence.test.cpp\"\n/*\r\n * @brief\
    \ \u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F\r\n */\r\n#define IGNORE\r\
    \n#define PROBLEM \"https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n#include <vector>\r\n#line\
    \ 2 \"math/linear_congruence.hpp\"\n#include <algorithm>\r\n#include <utility>\r\
    \n#line 4 \"math/mod_inv.hpp\"\n\r\nlong long mod_inv(long long a, int m) {\r\n\
    \  if ((a %= m) < 0) a += m;\r\n  if (std::__gcd(a, static_cast<long long>(m))\
    \ != 1) return -1;\r\n  long long b = m, x = 1, u = 0;\r\n  while (b > 0) {\r\n\
    \    long long q = a / b;\r\n    std::swap(a -= q * b, b);\r\n    std::swap(x\
    \ -= q * u, u);\r\n  }\r\n  x %= m;\r\n  return x < 0 ? x + m : x;\r\n}\r\n#line\
    \ 6 \"math/linear_congruence.hpp\"\n\r\ntemplate <typename T>\r\nstd::pair<long\
    \ long, long long> linear_congruence(const std::vector<T> &a, const std::vector<T>\
    \ &b, const std::vector<T> &m) {\r\n  long long x = 0, mod = 1;\r\n  int n = a.size();\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    long long l = mod * a[i], r = -x * a[i]\
    \ + b[i], g = std::__gcd(l, static_cast<long long>(m[i]));\r\n    if (r % g !=\
    \ 0) return {0, -1};\r\n    x += mod * (r / g * mod_inv(l / g, m[i] / g) % (m[i]\
    \ / g));\r\n    mod *= m[i] / g;\r\n  }\r\n  return {x < 0 ? x + mod : x, mod};\r\
    \n}\r\n#line 11 \"test/math/linear_congruence.test.cpp\"\n\r\nint main() {\r\n\
    \  constexpr int N = 29;\r\n  std::vector<long long> a(N), m(N);\r\n  for (int\
    \ i = 0; i < N; ++i) {\r\n    std::cin >> a[i];\r\n    m[i] = i + 1;\r\n  }\r\n\
    \  long long ans, mod; std::tie(ans, mod) = linear_congruence(std::vector<long\
    \ long>(N, 1), a, m);\r\n  if (mod == -1 || ans > 1000000000000) {\r\n    std::cout\
    \ << \"invalid\\n\";\r\n    return 0;\r\n  }\r\n  for (int i = 0; i < N; ++i)\
    \ {\r\n    int cnt = 0;\r\n    long long tmp = ans;\r\n    while (tmp > 0) {\r\
    \n      cnt += tmp % (i + 2);\r\n      tmp /= i + 2;\r\n    }\r\n    if (cnt !=\
    \ a[i]) {\r\n      std::cout << \"invalid\\n\";\r\n      return 0;\r\n    }\r\n\
    \  }\r\n  std::cout << ans << \"\\n\";\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F\r\
    \n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_d\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n#include <vector>\r\n#include\
    \ \"../../math/linear_congruence.hpp\"\r\n\r\nint main() {\r\n  constexpr int\
    \ N = 29;\r\n  std::vector<long long> a(N), m(N);\r\n  for (int i = 0; i < N;\
    \ ++i) {\r\n    std::cin >> a[i];\r\n    m[i] = i + 1;\r\n  }\r\n  long long ans,\
    \ mod; std::tie(ans, mod) = linear_congruence(std::vector<long long>(N, 1), a,\
    \ m);\r\n  if (mod == -1 || ans > 1000000000000) {\r\n    std::cout << \"invalid\\\
    n\";\r\n    return 0;\r\n  }\r\n  for (int i = 0; i < N; ++i) {\r\n    int cnt\
    \ = 0;\r\n    long long tmp = ans;\r\n    while (tmp > 0) {\r\n      cnt += tmp\
    \ % (i + 2);\r\n      tmp /= i + 2;\r\n    }\r\n    if (cnt != a[i]) {\r\n   \
    \   std::cout << \"invalid\\n\";\r\n      return 0;\r\n    }\r\n  }\r\n  std::cout\
    \ << ans << \"\\n\";\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/linear_congruence.hpp
  - math/mod_inv.hpp
  isVerificationFile: true
  path: test/math/linear_congruence.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/linear_congruence.test.cpp
layout: document
redirect_from:
- /verify/test/math/linear_congruence.test.cpp
- /verify/test/math/linear_congruence.test.cpp.html
title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
---
