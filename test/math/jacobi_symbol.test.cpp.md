---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/jacobi_symbol.hpp
    title: "\u30E4\u30B3\u30D3\u8A18\u53F7 (Jacobi symbol)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/984
    document_title: "\u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7"
    links:
    - https://yukicoder.me/problems/no/984
  bundledCode: "#line 1 \"test/math/jacobi_symbol.test.cpp\"\n/*\n * @title \u6570\
    \u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/984\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/math/jacobi_symbol.hpp\"\
    \n\n\n\n#include <bit>\n#include <cassert>\n#include <utility>\n\nnamespace emthrm\
    \ {\n\nint jacobi_symbol(long long a, long long p) {\n  assert(p > 0 && p & 1);\n\
    \  if (p == 1) [[unlikely]] return 1;\n  if ((a %= p) < 0) a += p;\n  if (a ==\
    \ 0) [[unlikely]] return 0;\n  int res = 1;\n  while (a > 0) {\n    const int\
    \ p2 = std::countr_zero(static_cast<unsigned long long>(a));\n    if ((p2 & 1)\
    \ && ((p + 2) & 4)) res = -res;\n    a >>= p2;\n    if (a & p & 2) res = -res;\n\
    \    std::swap(a, p);\n    a %= p;\n  }\n  return p == 1 ? res : 0;\n}\n\n}  //\
    \ namespace emthrm\n\n\n#line 10 \"test/math/jacobi_symbol.test.cpp\"\n\nint main()\
    \ {\n  int p, n;\n  std::cin >> p >> n;\n  std::cout << (n > 1 && emthrm::jacobi_symbol(n,\
    \ p) == -1 ? 1 : 0) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/984\n */\n\n#include <iostream>\n\n\
    #include \"emthrm/math/jacobi_symbol.hpp\"\n\nint main() {\n  int p, n;\n  std::cin\
    \ >> p >> n;\n  std::cout << (n > 1 && emthrm::jacobi_symbol(n, p) == -1 ? 1 :\
    \ 0) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/jacobi_symbol.hpp
  isVerificationFile: true
  path: test/math/jacobi_symbol.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/jacobi_symbol.test.cpp
layout: document
redirect_from:
- /verify/test/math/jacobi_symbol.test.cpp
- /verify/test/math/jacobi_symbol.test.cpp.html
title: "\u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7"
---
