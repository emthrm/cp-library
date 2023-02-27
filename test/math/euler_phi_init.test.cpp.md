---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570 (Euler's totient\
      \ function)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/euler_phi_init.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570 (Euler's totient\
      \ function) \u306E\u6570\u8868"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    document_title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
      \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/math/euler_phi_init.test.cpp\"\n/*\n * @title \u6570\
    \u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\u30A4\u30E9\
    \u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/math/euler_phi.hpp\"\
    \n\n\n\n#include <cassert>\n\nnamespace emthrm {\n\nlong long euler_phi(long long\
    \ n) {\n  assert(n >= 1);\n  long long res = n;\n  for (long long i = 2; i * i\
    \ <= n; ++i) {\n    if (n % i == 0) [[unlikely]] {\n      res -= res / i;\n  \
    \    while (n % i == 0) n /= i;\n    }\n  }\n  return n > 1 ? res - res / n :\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/euler_phi_init.hpp\"\
    \n\n\n\n#include <numeric>\n#line 6 \"include/emthrm/math/euler_phi_init.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<int> euler_phi_init(const int n) {\n  std::vector<int>\
    \ phi(n + 1);\n  std::iota(phi.begin(), phi.end(), 0);\n  for (int i = 2; i <=\
    \ n; ++i) {\n    if (phi[i] == i) [[unlikely]] {\n      for (int j = i; j <= n;\
    \ j += i) {\n        phi[j] -= phi[j] / i;\n      }\n    }\n  }\n  return phi;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 12 \"test/math/euler_phi_init.test.cpp\"\
    \n\nint main() {\n  constexpr int M = 1000000;\n  const std::vector<int> ans =\
    \ emthrm::euler_phi_init(M);\n  int n;\n  std::cin >> n;\n  std::cout << (n <=\
    \ M ? ans[n] : emthrm::euler_phi(n)) << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
    \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\
    \n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/euler_phi.hpp\"\
    \n#include \"emthrm/math/euler_phi_init.hpp\"\n\nint main() {\n  constexpr int\
    \ M = 1000000;\n  const std::vector<int> ans = emthrm::euler_phi_init(M);\n  int\
    \ n;\n  std::cin >> n;\n  std::cout << (n <= M ? ans[n] : emthrm::euler_phi(n))\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/euler_phi.hpp
  - include/emthrm/math/euler_phi_init.hpp
  isVerificationFile: true
  path: test/math/euler_phi_init.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/euler_phi_init.test.cpp
layout: document
redirect_from:
- /verify/test/math/euler_phi_init.test.cpp
- /verify/test/math/euler_phi_init.test.cpp.html
title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
  \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
---
