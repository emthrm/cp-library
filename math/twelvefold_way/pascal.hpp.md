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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/pascal.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\n * @docs\
    \ docs/math/twelvefold_way/binomial_coefficients.md\n */\n\n#pragma once\n#include\
    \ <vector>\n\ntemplate <typename T>\nstd::vector<std::vector<T>> pascal(const\
    \ int n) {\n  std::vector<std::vector<T>> c(n + 1, std::vector<T>(n + 1, 0));\n\
    \  for (int i = 0; i <= n; ++i) {\n    c[i][0] = 1;\n    for (int j = 1; j <=\
    \ i; ++j) {\n      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];\n    }\n  }\n  return\
    \ c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/twelvefold_way/pascal.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/pascal.test.cpp
documentation_of: math/twelvefold_way/pascal.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/pascal.hpp
- /library/math/twelvefold_way/pascal.hpp.html
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

- [二項係数](../../../math/modint.hpp)

- [二項係数 巨大な $n$ 版](../../../math/modint.hpp)

- 二項係数の数表 巨大な $n$ 版

||説明|
|:--:|:--:|
|`large_nCk_init<T>(n, k)`|$\binom{n}{r}$ ($0 \leq r \leq k$) の数表|


## 参考

http://drken1215.hatenablog.com/entry/2018/06/08/210000


## ToDo

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
