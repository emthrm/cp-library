---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/lagrange_interpolation2.hpp
    title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u72482"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/fps/faulhaber_with_lagrange_interpolation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\u30EB\
      \u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\
      \u88DC\u9593\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/fps/faulhaber.md
    document_title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F\
      \ \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/fps/faulhaber_with_lagrange_interpolation.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief \u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\
    \u5F0F \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248\r\n * @docs docs/math/fps/faulhaber.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"../modint.hpp\"\r\
    \n#include \"../lagrange_interpolation2.hpp\"\r\n\r\ntemplate <int T>\r\nMInt<T>\
    \ faulhaber(long long n, int k) {\r\n  using ModInt = MInt<T>;\r\n  if (n < 1)\
    \ return 0;\r\n  std::vector<ModInt> y(k + 2, 0);\r\n  for (int i = 1; i < k +\
    \ 2; ++i) y[i] = y[i - 1] + ModInt(i).pow(k);\r\n  return n - 1 < k + 2 ? y[n\
    \ - 1] : lagrange_interpolation(y, ModInt(n - 1));\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/lagrange_interpolation2.hpp
  isVerificationFile: false
  path: math/fps/faulhaber_with_lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/fps/faulhaber_with_lagrange_interpolation.test.cpp
documentation_of: math/fps/faulhaber_with_lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/math/fps/faulhaber_with_lagrange_interpolation.hpp
- /library/math/fps/faulhaber_with_lagrange_interpolation.hpp.html
title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\
  \u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248"
---
# ファウルハーバーの公式 (Faulhaber's formula)

$$S_k(n) = \sum_{i = 1}^{n - 1} i^k$$

と定義すると

$$S_k(n + 1) = \dfrac{1}{k + 1} \sum_{i = 0}^k \binom{k + 1}{i} B_i n^{k + 1 - i}$$

である．ここで $B$ は[ベルヌーイ数](bernoulli_number)である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|形式的冪級数版|$O(K\log{K})$|
|ラグランジュ補間版|$O(K \log{\max(K, M)})$|


## 使用法

- 形式的冪級数版

||説明|
|:--:|:--:|
|`faulhaber<T>(n, k)`|$S_k(n)$|

- ラグランジュ補間版

||説明|
|:--:|:--:|
|`faulhaber<T>(n, k)`|$S_k(n)$|


## 参考

- https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%82%A6%E3%83%AB%E3%83%8F%E3%83%BC%E3%83%90%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F


## Verified

- [形式的冪級数版](https://yukicoder.me/submissions/431468)
- [ラグランジュ補間版](https://yukicoder.me/submissions/437458)
