---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/twelvefold_way/large_nCk_init.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\u6570\
      \u8868 \u5DE8\u5927\u306A $n$ \u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/binomial_coefficients.md
    document_title: "\u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868 \u5DE8\u5927\u306A\
      \ $n$ \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/math/twelvefold_way/large_nCk_init.hpp: line 12: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868 \u5DE8\u5927\u306A\
    \ $n$ \u7248\n * @docs docs/math/twelvefold_way/binomial_coefficients.md\n */\n\
    \n#ifndef EMTHRM_MATH_TWELVEFOLD_WAY_LARGE_NCK_INIT_HPP_\n#define EMTHRM_MATH_TWELVEFOLD_WAY_LARGE_NCK_INIT_HPP_\n\
    \n#include <algorithm>\n#include <vector>\n\n#include \"emthrm/math/modint.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int T>\nstd::vector<MInt<T>> large_nCk_init(long\
    \ long n, const int k) {\n  using ModInt = MInt<T>;\n  const int tmp = std::min(n,\
    \ static_cast<long long>(k));\n  ModInt::inv(tmp, true);\n  std::vector<ModInt>\
    \ c(k + 1, 0);\n  c.front() = 1;\n  for (int i = 1; i <= tmp; ++i) {\n    c[i]\
    \ = c[i - 1] * n-- * ModInt::inv(i);\n  }\n  return c;\n}\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_MATH_TWELVEFOLD_WAY_LARGE_NCK_INIT_HPP_\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  isVerificationFile: false
  path: include/emthrm/math/twelvefold_way/large_nCk_init.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/twelvefold_way/large_nCk_init.test.cpp
documentation_of: include/emthrm/math/twelvefold_way/large_nCk_init.hpp
layout: document
redirect_from:
- /library/include/emthrm/math/twelvefold_way/large_nCk_init.hpp
- /library/include/emthrm/math/twelvefold_way/large_nCk_init.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868 \u5DE8\u5927\u306A $n$ \u7248"
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
