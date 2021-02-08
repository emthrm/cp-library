---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/inverse_element/mod_inv_extgcd.hpp
    title: "\u9006\u5143 \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/twelvefold_way/binomial_coefficients/binomial_coefficients.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u4E8C\u9805\
      \u4FC2\u6570"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md
    document_title: "\u4E8C\u9805\u4FC2\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp: line 6:\
    \ #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u4E8C\u9805\u4FC2\u6570\r\n * @docs docs/math/twelvefold_way/binomial_coefficients/binomial_coefficients.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <cassert>\r\n#include <vector>\r\n#include\
    \ \"../../inverse_element/mod_inv_extgcd.hpp\"\r\n\r\nstruct BinomialCoefficients\
    \ {\r\n  int val, mod;\r\n  std::vector<long long> fact, fact_inv;\r\n\r\n  BinomialCoefficients(int\
    \ mod, int val = 10000000) : mod(mod), val(val), fact(val + 1), fact_inv(val +\
    \ 1) {\r\n    fact[0] = 1;\r\n    for (int i = 1; i <= val; ++i) fact[i] = fact[i\
    \ - 1] * i % mod;\r\n    fact_inv[val] = mod_inv_extgcd(fact[val], mod);\r\n \
    \   for (int i = val; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i % mod;\r\n\
    \  }\r\n\r\n  long long query(int n, int k) const {\r\n    if (n < 0 || n < k\
    \ || k < 0) return 0;\r\n    assert(n <= val && k <= val);\r\n    return fact[n]\
    \ * fact_inv[k] % mod * fact_inv[n - k] % mod;\r\n  }\r\n};\r\n"
  dependsOn:
  - math/inverse_element/mod_inv_extgcd.hpp
  isVerificationFile: false
  path: math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/twelvefold_way/binomial_coefficients/binomial_coefficients.test.cpp
documentation_of: math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp
- /library/math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570"
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
|`pascal<T>(val)`|$\mathrm{val}$ 段のパスカルの三角形|

- 二項係数

||説明|備考|
|:--:|:--:|:--:|
|`BinomialCoefficients(mod, val = 10000000)`|二項係数を考える|$a! \perp \mathrm{mod}$|
|`fact[i]`|$i!$|
|`fact_inv[i]`|$\frac{1}{i!}$|
|`query(n, k)`|$\binom{n}{k}$|

e.g. $0 \leq a < \mathrm{mod}$ を満たす素数

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
