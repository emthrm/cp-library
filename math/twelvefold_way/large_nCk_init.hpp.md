---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/large_nCk_init.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\u6570\
      \u8868 \u5DE8\u5927\u306A $n$ \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/binomial_coefficients.md
    document_title: "\u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868 \u5DE8\u5927\u306A\
      \ $n$ \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/large_nCk_init.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868 \u5DE8\u5927\u306A\
    \ $n$ \u7248\r\n * @docs docs/math/twelvefold_way/binomial_coefficients.md\r\n\
    \ */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n\r\n\
    #include \"../modint.hpp\"\r\n\r\ntemplate <int T>\r\nstd::vector<MInt<T>> large_nCk_init(long\
    \ long n, const int k) {\r\n  using ModInt = MInt<T>;\r\n  const int tmp = std::min(n,\
    \ static_cast<long long>(k));\r\n  ModInt::inv(tmp, true);\r\n  std::vector<ModInt>\
    \ c(k + 1, 0);\r\n  c.front() = 1;\r\n  for (int i = 1; i <= tmp; ++i) {\r\n \
    \   c[i] = c[i - 1] * n-- * ModInt::inv(i);\r\n  }\r\n  return c;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/twelvefold_way/large_nCk_init.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/large_nCk_init.test.cpp
documentation_of: math/twelvefold_way/large_nCk_init.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/large_nCk_init.hpp
- /library/math/twelvefold_way/large_nCk_init.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868 \u5DE8\u5927\u306A $n$ \u7248"
---
# 二項係数 (binomial coefficients)

$$\binom{n}{k} = \binom{n - 1}{r - 1} + \binom{n - 1}{r} = \frac{n!}{k!\,(n - k)!}$$


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

- [パスカルの三角形](https://yukicoder.me/submissions/625063)
- [二項係数](https://yukicoder.me/submissions/625071)
- [二項係数 巨大な $n$ 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/5265683/emthrm/C++17)
- [二項係数の数表 巨大な $n$ 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/5265694/emthrm/C++17)
