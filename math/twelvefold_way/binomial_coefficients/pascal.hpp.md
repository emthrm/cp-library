---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/binomial_coefficients/pascal.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u30D1\u30B9\
      \u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
    document_title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/binomial_coefficients/pascal.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\r\n * @docs\
    \ docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md\r\n\
    \ */\r\n\r\n#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\n\
    std::vector<std::vector<T>> pascal(int n) {\r\n  std::vector<std::vector<T>> c(n\
    \ + 1, std::vector<T>(n + 1, 0));\r\n  for (int i = 0; i <= n; ++i) {\r\n    c[i][0]\
    \ = 1;\r\n    for (int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];\r\
    \n  }\r\n  return c;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/twelvefold_way/binomial_coefficients/pascal.hpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/binomial_coefficients/pascal.test.cpp
documentation_of: math/twelvefold_way/binomial_coefficients/pascal.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/binomial_coefficients/pascal.hpp
- /library/math/twelvefold_way/binomial_coefficients/pascal.hpp.html
title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
---
# 二項係数 (binomial coefficients)

$$\binom{n}{k} = \binom{n - 1}{r - 1} + \binom{n - 1}{r} = \frac{n!}{k!\,(n - k)!} \text{．}$$


## 時間計算量

||時間計算量|
|:--:|:--:|
|パスカルの三角形|$O(N^2)$|
|二項係数|$\langle O(N + \log{M}), O(1) \rangle$|
|n は巨大|$O(K)$|
|n は巨大な固定値|$O(K)$|


## 使用法

- パスカルの三角形

||説明|
|:--:|:--:|
|`pascal<T>(n)`|$n$ 段のパスカルの三角形|

- 二項係数

||説明|備考|
|:--:|:--:|:--:|
|`BinomialCoefficients(mod, val = 10000000)`|二項係数を考える|$a! \perp \mathrm{mod}$ (e.g. $0 \leq a < \mathrm{mod}$ を満たす素数)|
|`fact[i]`|$i!$|
|`fact_inv[i]`|$\frac{1}{i!}$|
|`query(n, k)`|$\binom{n}{k}$|

- $n$ は巨大

||説明|備考|
|:--:|:--:|:--:|
|`binom_large_n(n, k, Combinatorics)`|$\binom{n}{k}$|`Combinatorics` は $k$ 以上で定義されていなければならない．|

- $n$ は巨大な固定値

||説明|備考|
|:--:|:--:|:--:|
|`binom_large_n_init(n, k, Combinatorics)`|$\binom{n}{r} \ (0 \leq r \leq k)$ の数表|`Combinatorics` は $\min \lbrace n, k \rbrace$ 以上で定義されていなければならない．|


## 参考

http://drken1215.hatenablog.com/entry/2018/06/08/210000


## ToDo

https://w.atwiki.jp/uwicoder/pages/2118.html


## Verified

- [パスカルの三角形](https://atcoder.jp/contests/cpsco2019-s3/submissions/9335288)
- [二項係数](https://yukicoder.me/submissions/414639)
- [$n$ は巨大](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/4092983/emthrm/C++14)
- [$n$ は巨大な固定値](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/4093004/emthrm/C++14)
