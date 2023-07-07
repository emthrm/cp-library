---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    document_title: "\u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/math/mod_pow.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n *\n * verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\n */\n\n#include\
    \ <iostream>\n\n#line 1 \"include/emthrm/math/mod_pow.hpp\"\n\n\n\nnamespace emthrm\
    \ {\n\nlong long mod_pow(long long x, long long n, const int m) {\n  if ((x %=\
    \ m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0; n >>= 1) {\n    if (n\
    \ & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n  return res;\n}\n\n}\
    \  // namespace emthrm\n\n\n#line 10 \"test/math/mod_pow.test.cpp\"\n\nint main()\
    \ {\n  int m, n;\n  std::cin >> m >> n;\n  std::cout << emthrm::mod_pow(m, n,\
    \ 1000000007) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\n *\n\
    \ * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/math/mod_pow.hpp\"\n\nint main()\
    \ {\n  int m, n;\n  std::cin >> m >> n;\n  std::cout << emthrm::mod_pow(m, n,\
    \ 1000000007) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/mod_pow.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/mod_pow.test.cpp
layout: document
redirect_from:
- /verify/test/math/mod_pow.test.cpp
- /verify/test/math/mod_pow.test.cpp.html
title: "\u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
---
