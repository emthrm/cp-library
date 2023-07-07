---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':question:'
    path: include/emthrm/math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59 (quadratic residue)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    document_title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/math/mod_sqrt.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /\u5E73\u65B9\u5270\u4F59\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/sqrt_mod\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/math/mod_sqrt.hpp\"\n\n\
    \n\n#include <random>\n\n#line 1 \"include/emthrm/math/mod_pow.hpp\"\n\n\n\nnamespace\
    \ emthrm {\n\nlong long mod_pow(long long x, long long n, const int m) {\n  if\
    \ ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0; n >>= 1) {\n \
    \   if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return res;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 7 \"include/emthrm/math/mod_sqrt.hpp\"\n\
    \nnamespace emthrm {\n\nlong long mod_sqrt(long long a, const int p) {\n  if ((a\
    \ %= p) < 0) a += p;\n  if (a == 0) [[unlikely]] return 0;\n  if (p == 2) [[unlikely]]\
    \ return 1;\n  if (mod_pow(a, (p - 1) >> 1, p) == p - 1) return -1;\n  if (p %\
    \ 4 == 3) return mod_pow(a, (p + 1) >> 2, p);\n  int s = 1, q = (p - 1) >> 1;\n\
    \  for (; !(q & 1); q >>= 1) {\n    ++s;\n  }\n  static std::mt19937_64 engine(std::random_device\
    \ {} ());\n  std::uniform_int_distribution<> dist(2, p - 1);\n  long long z;\n\
    \  do {\n    z = dist(engine);\n  } while (mod_pow(z, (p - 1) >> 1, p) == 1);\n\
    \  int m = s;\n  long long c = mod_pow(z, q, p), r = mod_pow(a, (q - 1) >> 1,\
    \ p);\n  long long t = a * r % p * r % p;\n  r = (r * a) % p;\n  while (t != 1)\
    \ {\n    long long t2 = t * t % p;\n    for (int i = 1; i < m; ++i) {\n      if\
    \ (t2 == 1) {\n        const long long b = mod_pow(c, 1 << (m - i - 1), p);\n\
    \        m = i;\n        r = (r * b) % p;\n        c = b * b % p;\n        t =\
    \ (t * c) % p;\n        break;\n      }\n      t2 = (t2 * t2) % p;\n    }\n  }\n\
    \  return r;\n}\n\n}  // namespace emthrm\n\n\n#line 10 \"test/math/mod_sqrt.test.cpp\"\
    \n\nint main() {\n  int t;\n  std::cin >> t;\n  while (t--) {\n    int y, p;\n\
    \    std::cin >> y >> p;\n    std::cout << emthrm::mod_sqrt(y, p) << '\\n';\n\
    \  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u5E73\u65B9\u5270\u4F59\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/sqrt_mod\n */\n\n#include <iostream>\n\
    \n#include \"emthrm/math/mod_sqrt.hpp\"\n\nint main() {\n  int t;\n  std::cin\
    \ >> t;\n  while (t--) {\n    int y, p;\n    std::cin >> y >> p;\n    std::cout\
    \ << emthrm::mod_sqrt(y, p) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/mod_sqrt.hpp
  - include/emthrm/math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/mod_sqrt.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/mod_sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/math/mod_sqrt.test.cpp
- /verify/test/math/mod_sqrt.test.cpp.html
title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
---
