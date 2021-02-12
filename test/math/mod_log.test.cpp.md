---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    document_title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/math/mod_log.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u96E2\u6563\u5BFE\u6570\u554F\u984C\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \r\n\r\n#include <iostream>\r\n#line 2 \"math/mod_log.hpp\"\n#include <cmath>\r\
    \n#include <map>\r\n#line 2 \"math/mod_pow.hpp\"\n\r\nlong long mod_pow(long long\
    \ base, long long exponent, int mod) {\r\n  base %= mod;\r\n  long long res =\
    \ 1;\r\n  while (exponent > 0) {\r\n    if (exponent & 1) (res *= base) %= mod;\r\
    \n    (base *= base) %= mod;\r\n    exponent >>= 1;\r\n  }\r\n  return res;\r\n\
    }\r\n#line 5 \"math/mod_log.hpp\"\n\r\nint mod_log(long long g, long long y, int\
    \ mod) {\r\n  if ((g %= mod) < 0) g += mod;\r\n  if ((y %= mod) < 0) y += mod;\r\
    \n  if (mod == 1) return 0;\r\n  if (g == 0) {\r\n    if (y == 1) {\r\n      return\
    \ 0;\r\n    } else if (y == 0) {\r\n      return 1;\r\n    } else {\r\n      return\
    \ -1;\r\n    }\r\n  }\r\n  int root = std::ceil(std::sqrt(mod));\r\n  std::map<long\
    \ long, int> baby;\r\n  long long p = 1;\r\n  for (int i = 0; i < root; ++i) {\r\
    \n    if (p == y) return i;\r\n    baby[p * y % mod] = i;\r\n    (p *= g) %= mod;\r\
    \n  }\r\n  long long brute_force = p;\r\n  for (int i = root; i < 100; ++i) {\r\
    \n    if (i == mod) return -1;\r\n    if (brute_force == y) return i;\r\n    (brute_force\
    \ *= g) %= mod;\r\n  }\r\n  long long giant = p;\r\n  for (int i = 1; i <= root;\
    \ ++i) {\r\n    if (baby.count(giant) == 1) {\r\n      int ans = static_cast<int>(static_cast<long\
    \ long>(i) * root - baby[giant]);\r\n      if (mod_pow(g, ans, mod) == y) return\
    \ ans;\r\n    }\r\n    (giant *= p) %= mod;\r\n  }\r\n  return -1;\r\n}\r\n#line\
    \ 8 \"test/math/mod_log.test.cpp\"\n\r\nint main() {\r\n  int t;\r\n  std::cin\
    \ >> t;\r\n  while (t--) {\r\n    int x, y, m;\r\n    std::cin >> x >> y >> m;\r\
    \n    std::cout << mod_log(x, y, m) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C\r\n */\r\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\r\
    \n\r\n#include <iostream>\r\n#include \"../../math/mod_log.hpp\"\r\n\r\nint main()\
    \ {\r\n  int t;\r\n  std::cin >> t;\r\n  while (t--) {\r\n    int x, y, m;\r\n\
    \    std::cin >> x >> y >> m;\r\n    std::cout << mod_log(x, y, m) << '\\n';\r\
    \n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/mod_log.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/mod_log.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/mod_log.test.cpp
layout: document
redirect_from:
- /verify/test/math/mod_log.test.cpp
- /verify/test/math/mod_log.test.cpp.html
title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
---
