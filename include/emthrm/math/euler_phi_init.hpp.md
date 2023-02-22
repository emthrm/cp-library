---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi_init.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/euler_phi/euler_phi.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\
      \u8868"
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/euler_phi_init.hpp\"\n/**\n * @brief\
    \ \u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\n *\
    \ @docs docs/math/euler_phi/euler_phi.md\n */\n\n#ifndef EMTHRM_MATH_EULER_PHI_EULER_PHI_INIT_HPP_\n\
    #define EMTHRM_MATH_EULER_PHI_EULER_PHI_INIT_HPP_\n\n#include <numeric>\n#include\
    \ <vector>\n\nnamespace emthrm {\n\nstd::vector<int> euler_phi_init(const int\
    \ n) {\n  std::vector<int> phi(n + 1);\n  std::iota(phi.begin(), phi.end(), 0);\n\
    \  for (int i = 2; i <= n; ++i) {\n    if (phi[i] == i) {\n      for (int j =\
    \ i; j <= n; j += i) {\n        phi[j] -= phi[j] / i;\n      }\n    }\n  }\n \
    \ return phi;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_EULER_PHI_EULER_PHI_INIT_HPP_\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\
    \u6570\u8868\n * @docs docs/math/euler_phi/euler_phi.md\n */\n\n#ifndef EMTHRM_MATH_EULER_PHI_EULER_PHI_INIT_HPP_\n\
    #define EMTHRM_MATH_EULER_PHI_EULER_PHI_INIT_HPP_\n\n#include <numeric>\n#include\
    \ <vector>\n\nnamespace emthrm {\n\nstd::vector<int> euler_phi_init(const int\
    \ n) {\n  std::vector<int> phi(n + 1);\n  std::iota(phi.begin(), phi.end(), 0);\n\
    \  for (int i = 2; i <= n; ++i) {\n    if (phi[i] == i) {\n      for (int j =\
    \ i; j <= n; j += i) {\n        phi[j] -= phi[j] / i;\n      }\n    }\n  }\n \
    \ return phi;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_EULER_PHI_EULER_PHI_INIT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/euler_phi_init.hpp
  requiredBy: []
  timestamp: '2023-02-23 01:08:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/euler_phi_init.test.cpp
documentation_of: include/emthrm/math/euler_phi_init.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/euler_phi_init.hpp
- /library/include/emthrm/math/euler_phi_init.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
---
