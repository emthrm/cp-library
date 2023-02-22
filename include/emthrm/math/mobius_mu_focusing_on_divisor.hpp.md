---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/mobius_mu_focusing_on_divisor.test.cpp
    title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\u30B9\
      \u95A2\u6570 \u7D04\u6570\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/mobius_mu/mobius_mu.md
    document_title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/mobius_mu_focusing_on_divisor.hpp\"\n\
    /**\n * @brief \u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248\n * @docs\
    \ docs/math/mobius_mu/mobius_mu.md\n */\n\n#ifndef EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_FOCUSING_ON_DIVISOR_HPP_\n\
    #define EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_FOCUSING_ON_DIVISOR_HPP_\n\n#include <map>\n\
    #include <vector>\n\n#if !defined(__GNUC__) && \\\n    (!defined(__has_builtin)\
    \ || !__has_builtin(__builtin_popcount))\n# error \"__builtin_popcount is required.\"\
    \n#endif\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::map<T, int> mobius_mu_focusing_on_divisor(T\
    \ n) {\n  std::vector<T> primes;\n  for (T i = 2; i * i <= n; ++i) {\n    if (n\
    \ % i == 0) {\n      primes.emplace_back(i);\n      while (n % i == 0) n /= i;\n\
    \    }\n  }\n  if (n > 1) primes.emplace_back(n);\n  const int p = primes.size();\n\
    \  std::map<T, int> mu;\n  for (int i = 0; i < (1 << p); ++i) {\n    T d = 1;\n\
    \    for (int j = 0; j < p; ++j) {\n      if (i >> j & 1) d *= primes[j];\n  \
    \  }\n    mu[d] = (__builtin_popcount(i) & 1 ? -1 : 1);\n  }\n  return mu;\n}\n\
    \n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_FOCUSING_ON_DIVISOR_HPP_\n"
  code: "/**\n * @brief \u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248\n\
    \ * @docs docs/math/mobius_mu/mobius_mu.md\n */\n\n#ifndef EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_FOCUSING_ON_DIVISOR_HPP_\n\
    #define EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_FOCUSING_ON_DIVISOR_HPP_\n\n#include <map>\n\
    #include <vector>\n\n#if !defined(__GNUC__) && \\\n    (!defined(__has_builtin)\
    \ || !__has_builtin(__builtin_popcount))\n# error \"__builtin_popcount is required.\"\
    \n#endif\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::map<T, int> mobius_mu_focusing_on_divisor(T\
    \ n) {\n  std::vector<T> primes;\n  for (T i = 2; i * i <= n; ++i) {\n    if (n\
    \ % i == 0) {\n      primes.emplace_back(i);\n      while (n % i == 0) n /= i;\n\
    \    }\n  }\n  if (n > 1) primes.emplace_back(n);\n  const int p = primes.size();\n\
    \  std::map<T, int> mu;\n  for (int i = 0; i < (1 << p); ++i) {\n    T d = 1;\n\
    \    for (int j = 0; j < p; ++j) {\n      if (i >> j & 1) d *= primes[j];\n  \
    \  }\n    mu[d] = (__builtin_popcount(i) & 1 ? -1 : 1);\n  }\n  return mu;\n}\n\
    \n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_MOBIUS_MU_MOBIUS_MU_FOCUSING_ON_DIVISOR_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/mobius_mu_focusing_on_divisor.hpp
  requiredBy: []
  timestamp: '2023-02-23 01:08:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/mobius_mu_focusing_on_divisor.test.cpp
documentation_of: include/emthrm/math/mobius_mu_focusing_on_divisor.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/mobius_mu_focusing_on_divisor.hpp
- /library/include/emthrm/math/mobius_mu_focusing_on_divisor.hpp.html
title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
---
