---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi_init.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
  - icon: ':heavy_check_mark:'
    path: test/math/euler_phi_init2.test.cpp
    title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
      \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/euler_phi/euler_phi.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/euler_phi.hpp\"\n/**\n * @brief \u30AA\
    \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\n * @docs docs/math/euler_phi/euler_phi.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n#define EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n\
    \n#include <cassert>\n\nnamespace emthrm {\n\nlong long euler_phi(long long n)\
    \ {\n  assert(n >= 1);\n  long long res = n;\n  for (long long i = 2; i * i <=\
    \ n; ++i) {\n    if (n % i == 0) {\n      res -= res / i;\n      while (n % i\
    \ == 0) n /= i;\n    }\n  }\n  return n > 1 ? res - res / n : res;\n}\n\n}  //\
    \ namespace emthrm\n\n#endif  // EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\n *\
    \ @docs docs/math/euler_phi/euler_phi.md\n */\n\n#ifndef EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n\
    #define EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n\n#include <cassert>\n\nnamespace\
    \ emthrm {\n\nlong long euler_phi(long long n) {\n  assert(n >= 1);\n  long long\
    \ res = n;\n  for (long long i = 2; i * i <= n; ++i) {\n    if (n % i == 0) {\n\
    \      res -= res / i;\n      while (n % i == 0) n /= i;\n    }\n  }\n  return\
    \ n > 1 ? res - res / n : res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_EULER_PHI_EULER_PHI_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/euler_phi.hpp
  requiredBy: []
  timestamp: '2023-02-23 01:08:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/euler_phi_init.test.cpp
  - test/math/euler_phi.test.cpp
  - test/math/euler_phi_init2.test.cpp
documentation_of: include/emthrm/math/euler_phi.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/euler_phi.hpp
- /library/include/emthrm/math/euler_phi.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
---
