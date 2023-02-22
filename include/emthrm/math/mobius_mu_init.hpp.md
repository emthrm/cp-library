---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/mobius_mu_init.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570\u306E\u6570\u8868"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/mobius_mu/mobius_mu.md
    document_title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u8868"
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/mobius_mu_init.hpp\"\n/**\n * @brief\
    \ \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u8868\n * @docs docs/math/mobius_mu/mobius_mu.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_\n#define EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_\n\
    \n#include <vector>\n\nnamespace emthrm {\n\nstd::vector<int> mobius_mu_init(const\
    \ int n) {\n  std::vector<bool> is_prime(n + 1, true);\n  is_prime[0] = false;\n\
    \  if (n >= 1) is_prime[1] = false;\n  std::vector<int> mu(n + 1, 1);\n  mu[0]\
    \ = 0;\n  for (int i = 2; i <= n; ++i) {\n    if (is_prime[i]) {\n      mu[i]\
    \ = -mu[i];\n      for (int j = i * 2; j <= n; j += i) {\n        is_prime[j]\
    \ = false;\n        mu[j] = ((j / i) % i == 0 ? 0 : -mu[j]);\n      }\n    }\n\
    \  }\n  return mu;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_\n"
  code: "/**\n * @brief \u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u8868\n *\
    \ @docs docs/math/mobius_mu/mobius_mu.md\n */\n\n#ifndef EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_\n\
    #define EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_\n\n#include <vector>\n\nnamespace\
    \ emthrm {\n\nstd::vector<int> mobius_mu_init(const int n) {\n  std::vector<bool>\
    \ is_prime(n + 1, true);\n  is_prime[0] = false;\n  if (n >= 1) is_prime[1] =\
    \ false;\n  std::vector<int> mu(n + 1, 1);\n  mu[0] = 0;\n  for (int i = 2; i\
    \ <= n; ++i) {\n    if (is_prime[i]) {\n      mu[i] = -mu[i];\n      for (int\
    \ j = i * 2; j <= n; j += i) {\n        is_prime[j] = false;\n        mu[j] =\
    \ ((j / i) % i == 0 ? 0 : -mu[j]);\n      }\n    }\n  }\n  return mu;\n}\n\n}\
    \  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_INIT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/mobius_mu_init.hpp
  requiredBy: []
  timestamp: '2023-02-23 01:08:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mobius_mu_init.test.cpp
documentation_of: include/emthrm/math/mobius_mu_init.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/mobius_mu_init.hpp
- /library/include/emthrm/math/mobius_mu_init.hpp.html
title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u8868"
---
