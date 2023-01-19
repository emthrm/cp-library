---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/floor_sum.test.cpp
    title: "\u6570\u5B66/sum of floor of linear"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/floor_sum.hpp\"\n\n\n\n#include <utility>\n\
    \nnamespace emthrm {\n\nlong long floor_sum(long long a, long long b, long long\
    \ m, long long n) {\n  long long res = 0;\n  if (a < 0) {\n    long long nxt_a\
    \ = a % m;\n    if (nxt_a < 0) nxt_a += m;\n    res -= n * (n - 1) / 2 * ((nxt_a\
    \ - a) / m);\n    a = nxt_a;\n  }\n  if (b < 0) {\n    long long nxt_b = b % m;\n\
    \    if (nxt_b < 0) nxt_b += m;\n    res -= n * ((nxt_b - b) / m);\n    b = nxt_b;\n\
    \  }\n  while (true) {\n    if (a >= m) {\n      res += n * (n - 1) / 2 * (a /\
    \ m);\n      a %= m;\n    }\n    if (b >= m) {\n      res += n * (b / m);\n  \
    \    b %= m;\n    }\n    const long long y_max = a * n + b;\n    if (y_max < m)\
    \ break;\n    b = y_max % m;\n    n = y_max / m;\n    std::swap(a, m);\n  }\n\
    \  return res;\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_FLOOR_SUM_HPP_\n#define EMTHRM_MATH_FLOOR_SUM_HPP_\n\n\
    #include <utility>\n\nnamespace emthrm {\n\nlong long floor_sum(long long a, long\
    \ long b, long long m, long long n) {\n  long long res = 0;\n  if (a < 0) {\n\
    \    long long nxt_a = a % m;\n    if (nxt_a < 0) nxt_a += m;\n    res -= n *\
    \ (n - 1) / 2 * ((nxt_a - a) / m);\n    a = nxt_a;\n  }\n  if (b < 0) {\n    long\
    \ long nxt_b = b % m;\n    if (nxt_b < 0) nxt_b += m;\n    res -= n * ((nxt_b\
    \ - b) / m);\n    b = nxt_b;\n  }\n  while (true) {\n    if (a >= m) {\n     \
    \ res += n * (n - 1) / 2 * (a / m);\n      a %= m;\n    }\n    if (b >= m) {\n\
    \      res += n * (b / m);\n      b %= m;\n    }\n    const long long y_max =\
    \ a * n + b;\n    if (y_max < m) break;\n    b = y_max % m;\n    n = y_max / m;\n\
    \    std::swap(a, m);\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_MATH_FLOOR_SUM_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/floor_sum.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/floor_sum.test.cpp
documentation_of: include/emthrm/math/floor_sum.hpp
layout: document
title: sum of floor of linear
---

$$
  \sum_{i = 0}^{N - 1} \left\lfloor \frac{Ai + B}{M} \right\rfloor
$$


## 時間計算量

$O(\log{M})$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`long long floor_sum(long long a, long long b, long long m, long long n);`|$\sum_{i = 0}^{N - 1} \left\lfloor \frac{Ai + B}{M} \right\rfloor$|$M \in \mathbb{N}^+$|


## 参考文献

- https://rsk0315.hatenablog.com/entry/2020/12/13/231307
- https://qiita.com/R_olldIce/items/3e2c80baa6d5e6f3abe9#4-floor_sum
- https://github.com/atcoder/ac-library/blob/c8e527063415e2f9aaf87cf80f2c59730a46ed98/atcoder/math.hpp#L82-L97
- https://github.com/atcoder/ac-library/blob/6c88a70c8f95fef575af354900d107fbd0db1a12/atcoder/internal_math.hpp#L180-L207


## Submissons

https://judge.yosupo.jp/submission/39036
