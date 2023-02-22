---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/mobius_mu.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/mobius_mu/mobius_mu.md
    document_title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570"
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/mobius_mu.hpp\"\n/**\n * @brief \u30E1\
    \u30D3\u30A6\u30B9\u95A2\u6570\n * @docs docs/math/mobius_mu/mobius_mu.md\n */\n\
    \n#ifndef EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_HPP_\n#define EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_HPP_\n\
    \nnamespace emthrm {\n\nint mobius_mu(long long n) {\n  int num = 0;\n  for (long\
    \ long i = 2; i * i <= n; ++i) {\n    if (n % i == 0) {\n      n /= i;\n     \
    \ if (n % i == 0) return 0;\n      num ^= 1;\n    }\n  }\n  if (n > 1) num ^=\
    \ 1;\n  return num ? -1 : 1;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_HPP_\n"
  code: "/**\n * @brief \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\n * @docs docs/math/mobius_mu/mobius_mu.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_HPP_\n#define EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_HPP_\n\
    \nnamespace emthrm {\n\nint mobius_mu(long long n) {\n  int num = 0;\n  for (long\
    \ long i = 2; i * i <= n; ++i) {\n    if (n % i == 0) {\n      n /= i;\n     \
    \ if (n % i == 0) return 0;\n      num ^= 1;\n    }\n  }\n  if (n > 1) num ^=\
    \ 1;\n  return num ? -1 : 1;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/mobius_mu.hpp
  requiredBy: []
  timestamp: '2023-02-23 01:08:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mobius_mu.test.cpp
documentation_of: include/emthrm/math/mobius_mu.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/mobius_mu.hpp
- /library/include/emthrm/math/mobius_mu.hpp.html
title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570"
---
