---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570 (Euler's totient\
      \ function)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    document_title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
      \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/math/euler_phi.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\u30A4\u30E9\u30FC\
    \u306E $\\varphi$ \u95A2\u6570\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/math/euler_phi.hpp\"\n\
    \n\n\n#include <cassert>\n\nnamespace emthrm {\n\nlong long euler_phi(long long\
    \ n) {\n  assert(n >= 1);\n  long long res = n;\n  for (long long i = 2; i * i\
    \ <= n; ++i) {\n    if (n % i == 0) [[unlikely]] {\n      res -= res / i;\n  \
    \    while (n % i == 0) n /= i;\n    }\n  }\n  return n > 1 ? res - res / n :\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n#line 10 \"test/math/euler_phi.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::cout << emthrm::euler_phi(n)\
    \ << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
    \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\n */\n\
    \n#include <iostream>\n\n#include \"emthrm/math/euler_phi.hpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::cout << emthrm::euler_phi(n) << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/euler_phi.hpp
  isVerificationFile: true
  path: test/math/euler_phi.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/euler_phi.test.cpp
layout: document
redirect_from:
- /verify/test/math/euler_phi.test.cpp
- /verify/test/math/euler_phi.test.cpp.html
title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
  \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
---
