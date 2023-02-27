---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/floor_sum.hpp
    title: sum of floor of linear
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    document_title: "\u6570\u5B66/sum of floor of linear"
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/math/floor_sum.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /sum of floor of linear\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/sum_of_floor_of_linear\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/math/floor_sum.hpp\"\n\
    \n\n\n#include <utility>\n\nnamespace emthrm {\n\nlong long floor_sum(long long\
    \ a, long long b, long long m, long long n) {\n  long long res = 0;\n  if (a <\
    \ 0) {\n    long long nxt_a = a % m;\n    if (nxt_a < 0) nxt_a += m;\n    res\
    \ -= n * (n - 1) / 2 * ((nxt_a - a) / m);\n    a = nxt_a;\n  }\n  if (b < 0) {\n\
    \    long long nxt_b = b % m;\n    if (nxt_b < 0) nxt_b += m;\n    res -= n *\
    \ ((nxt_b - b) / m);\n    b = nxt_b;\n  }\n  while (true) {\n    if (a >= m) {\n\
    \      res += n * (n - 1) / 2 * (a / m);\n      a %= m;\n    }\n    if (b >= m)\
    \ {\n      res += n * (b / m);\n      b %= m;\n    }\n    const long long y_max\
    \ = a * n + b;\n    if (y_max < m) break;\n    b = y_max % m;\n    n = y_max /\
    \ m;\n    std::swap(a, m);\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\
    \n#line 10 \"test/math/floor_sum.test.cpp\"\n\nint main() {\n  int t;\n  std::cin\
    \ >> t;\n  while (t--) {\n    int n, m, a, b;\n    std::cin >> n >> m >> a >>\
    \ b;\n    std::cout << emthrm::floor_sum(a, b, m, n) << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/sum of floor of linear\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/sum_of_floor_of_linear\n */\n\n#include\
    \ <iostream>\n\n#include \"emthrm/math/floor_sum.hpp\"\n\nint main() {\n  int\
    \ t;\n  std::cin >> t;\n  while (t--) {\n    int n, m, a, b;\n    std::cin >>\
    \ n >> m >> a >> b;\n    std::cout << emthrm::floor_sum(a, b, m, n) << '\\n';\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/floor_sum.hpp
  isVerificationFile: true
  path: test/math/floor_sum.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/floor_sum.test.cpp
layout: document
redirect_from:
- /verify/test/math/floor_sum.test.cpp
- /verify/test/math/floor_sum.test.cpp.html
title: "\u6570\u5B66/sum of floor of linear"
---