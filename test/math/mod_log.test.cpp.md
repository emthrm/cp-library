---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
  - icon: ':x:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    document_title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/math/mod_log.test.cpp\"\n/*\n * @brief \u6570\u5B66\
    /\u96E2\u6563\u5BFE\u6570\u554F\u984C\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <iostream>\n\n#line 2 \"math/mod_log.hpp\"\n#include <map>\n\n#line\
    \ 2 \"math/mod_pow.hpp\"\n\nlong long mod_pow(long long x, long long n, const\
    \ int m) {\n  if ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0;\
    \ n >>= 1) {\n    if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n\
    \  return res;\n}\n#line 5 \"math/mod_log.hpp\"\n\nint mod_log(long long g, long\
    \ long y, const int m) {\n  if (m == 1) return 0;\n  if ((g %= m) < 0) g += m;\n\
    \  if ((y %= m) < 0) y += m;\n  if (g == 0) {\n    if (y == 1) return 0;\n   \
    \ if (y == 0) return 1;\n    return -1;\n  }\n  int root = 1;\n  while (root *\
    \ root < m) ++root;\n  std::map<long long, int> baby;\n  long long p = 1;\n  for\
    \ (int i = 0; i < root; ++i) {\n    if (p == y) return i;\n    baby[p * y % m]\
    \ = i;\n    p = (p * g) % m;\n  }\n  long long brute_force = p;\n  for (int i\
    \ = root; i < 100; ++i) {\n    if (i == m) return -1;\n    if (brute_force ==\
    \ y) return i;\n    brute_force = (brute_force * g) % m;\n  }\n  long long giant\
    \ = p;\n  for (int i = 1; i <= root; ++i) {\n    if (baby.count(giant) == 1) {\n\
    \      const int ans = static_cast<long long>(i) * root - baby[giant];\n     \
    \ if (mod_pow(g, ans, m) == y) return ans;\n    }\n    giant = (giant * p) % m;\n\
    \  }\n  return -1;\n}\n#line 9 \"test/math/mod_log.test.cpp\"\n\nint main() {\n\
    \  int t;\n  std::cin >> t;\n  while (t--) {\n    int x, y, m;\n    std::cin >>\
    \ x >> y >> m;\n    std::cout << mod_log(x, y, m) << '\\n';\n  }\n  return 0;\n\
    }\n"
  code: "/*\n * @brief \u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C\n */\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#include\
    \ <iostream>\n\n#include \"../../math/mod_log.hpp\"\n\nint main() {\n  int t;\n\
    \  std::cin >> t;\n  while (t--) {\n    int x, y, m;\n    std::cin >> x >> y >>\
    \ m;\n    std::cout << mod_log(x, y, m) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/mod_log.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/mod_log.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/mod_log.test.cpp
layout: document
redirect_from:
- /verify/test/math/mod_log.test.cpp
- /verify/test/math/mod_log.test.cpp.html
title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
---
