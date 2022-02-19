---
data:
  _extendedDependsOn:
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    document_title: "\u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/math/mod_pow.test.cpp\"\n/*\r\n * @brief \u6570\u5B66\
    /\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#line 2 \"math/mod_pow.hpp\"\n\r\nlong long\
    \ mod_pow(long long x, long long n, const int m) {\r\n  if ((x %= m) < 0) x +=\
    \ m;\r\n  long long res = 1;\r\n  for (; n > 0; n >>= 1) {\r\n    if (n & 1) res\
    \ = (res * x) % m;\r\n    x = (x * x) % m;\r\n  }\r\n  return res;\r\n}\r\n#line\
    \ 9 \"test/math/mod_pow.test.cpp\"\n\r\nint main() {\r\n  int m, n;\r\n  std::cin\
    \ >> m >> n;\r\n  std::cout << mod_pow(m, n, 1000000007) << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\r\
    \n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../../math/mod_pow.hpp\"\r\n\r\n\
    int main() {\r\n  int m, n;\r\n  std::cin >> m >> n;\r\n  std::cout << mod_pow(m,\
    \ n, 1000000007) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/mod_pow.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/mod_pow.test.cpp
layout: document
redirect_from:
- /verify/test/math/mod_pow.test.cpp
- /verify/test/math/mod_pow.test.cpp.html
title: "\u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
---
