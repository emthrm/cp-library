---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/pascal.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\
      \u89D2\u5F62"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/binomial_coefficients.md
    document_title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/twelvefold_way/pascal.hpp\"\n/**\n *\
    \ @brief \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\n * @docs docs/math/twelvefold_way/binomial_coefficients.md\n\
    \ */\n\n#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_\n#define EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_\n\
    \n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>>\
    \ pascal(const int n) {\n  std::vector<std::vector<T>> c(n + 1, std::vector<T>(n\
    \ + 1, 0));\n  for (int i = 0; i <= n; ++i) {\n    c[i][0] = 1;\n    for (int\
    \ j = 1; j <= i; ++j) {\n      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];\n    }\n\
    \  }\n  return c;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_\n"
  code: "/**\n * @brief \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\n * @docs\
    \ docs/math/twelvefold_way/binomial_coefficients.md\n */\n\n#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_\n\
    #define EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_\n\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>> pascal(const\
    \ int n) {\n  std::vector<std::vector<T>> c(n + 1, std::vector<T>(n + 1, 0));\n\
    \  for (int i = 0; i <= n; ++i) {\n    c[i][0] = 1;\n    for (int j = 1; j <=\
    \ i; ++j) {\n      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];\n    }\n  }\n  return\
    \ c;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_PASCAL_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/twelvefold_way/pascal.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/pascal.test.cpp
documentation_of: include/emthrm/math/twelvefold_way/pascal.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/twelvefold_way/pascal.hpp
- /library/include/emthrm/math/twelvefold_way/pascal.hpp.html
title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
---
# 二項係数 (binomial coefficients)

$$
  \binom{n}{k} = \binom{n - 1}{r - 1} + \binom{n - 1}{r} = \frac{n!}{k!\,(n - k)!}
$$


## 時間計算量

||時間計算量|
|:--:|:--:|
|パスカルの三角形|$O(N^2)$|
|二項係数|$\langle O(N + \log{M}), O(1) \rangle$|
|二項係数 巨大な $n$ 版|$O(K + \log{M})$|
|二項係数の数表 巨大な $n$ 版|$O(K)$|


## 使用法

- パスカルの三角形

||説明|
|:--:|:--:|
|`pascal<T>(n)`|$n$ 段のパスカルの三角形|

- [二項係数](../../../include/emthrm/math/modint.hpp)

- [二項係数 巨大な $n$ 版](../../../include/emthrm/math/modint.hpp)

- 二項係数の数表 巨大な $n$ 版

||説明|
|:--:|:--:|
|`large_nCk_init<T>(n, k)`|$\binom{n}{r}$ ($0 \leq r \leq k$) の数表|


## 参考

http://drken1215.hatenablog.com/entry/2018/06/08/210000


## TODO

- https://w.atwiki.jp/uwicoder/pages/2118.html
- https://ferin-tech.hatenablog.com/entry/2018/01/17/010829
- https://judge.yosupo.jp/problem/binomial_coefficient
- $\sum_{i = 0}^M \binom{N}{i}$
  - https://twitter.com/noshi91/status/1349778791262945280
  - https://atcoder.jp/contests/abc235/tasks/abc235_g


## Verified

- [パスカルの三角形](https://atcoder.jp/contests/abc254/submissions/32252670)
- [二項係数](https://yukicoder.me/submissions/625071)
- [二項係数 巨大な $n$ 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/5265683/emthrm/C++17)
- [二項係数の数表 巨大な $n$ 版](https://yukicoder.me/submissions/820076)
