---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/binomial_coefficients/binom_large_n_init.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u4E8C\u9805\
      \u4FC2\u6570 $n$ \u306F\u5DE8\u5927\u306A\u56FA\u5B9A\u5024"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
    document_title: "\u4E8C\u9805\u4FC2\u6570 $n$ \u306F\u5DE8\u5927\u306A\u56FA\u5B9A\
      \u5024"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp: line 6: #pragma\
    \ once found in a non-first line\n"
  code: "/**\r\n * @brief \u4E8C\u9805\u4FC2\u6570 $n$ \u306F\u5DE8\u5927\u306A\u56FA\
    \u5B9A\u5024\r\n * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n#include\
    \ \"../../modint.hpp\"\r\n\r\ntemplate <int T>\r\nstd::vector<MInt<T>> binom_large_n_init(long\
    \ long n, int k) {\r\n  using ModInt = MInt<T>;\r\n  int tmp = std::min(n, static_cast<long\
    \ long>(k));\r\n  ModInt::inv(tmp, true);\r\n  std::vector<ModInt> c(k + 1, 0);\r\
    \n  c[0] = 1;\r\n  for (int i = 1; i <= tmp; ++i) c[i] = c[i - 1] * n-- * ModInt::inv(i);\r\
    \n  return c;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/binomial_coefficients/binom_large_n_init.test.cpp
documentation_of: math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp
- /library/math/twelvefold_way/binomial_coefficients/binom_large_n_init.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570 $n$ \u306F\u5DE8\u5927\u306A\u56FA\u5B9A\u5024"
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

||説明|
|:--:|:--:|
|`binom_large_n<T>(n, k)`|$\binom{n}{k}$|

- $n$ は巨大な固定値

||説明|
|:--:|:--:|
|`binom_large_n_init<T>(n, k)`|$\binom{n}{r} \ (0 \leq r \leq k)$ の数表|


## 参考

http://drken1215.hatenablog.com/entry/2018/06/08/210000


## ToDo

https://w.atwiki.jp/uwicoder/pages/2118.html


## Verified

- [パスカルの三角形](https://atcoder.jp/contests/cpsco2019-s3/submissions/9335288)
- [二項係数](https://yukicoder.me/submissions/414639)
- [$n$ は巨大](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/4092983/emthrm/C++14)
- [$n$ は巨大な固定値](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/4093004/emthrm/C++14)
