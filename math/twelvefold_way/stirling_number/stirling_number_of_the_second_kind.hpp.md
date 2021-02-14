---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
      \u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.md
    document_title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp:\
    \ line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\r\
    \n * @docs docs/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <cassert>\r\n#include \"../../modint.hpp\"\
    \r\n\r\ntemplate <int T>\r\nMInt<T> stirling_number_of_the_second_kind(int n,\
    \ int k) {\r\n  using ModInt = MInt<T>;\r\n  if (n < k) return 0;\r\n  ModInt::init(k);\r\
    \n  ModInt stirling = 0;\r\n  for (int i = 1; i <= k; ++i) {\r\n    ModInt tmp\
    \ = ModInt::nCk(k, i) * ModInt(i).pow(n);\r\n    if ((k - i) & 1) {\r\n      stirling\
    \ -= tmp;\r\n    } else {\r\n      stirling += tmp;\r\n    }\r\n  }\r\n  return\
    \ stirling * ModInt::fact_inv(k);\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.test.cpp
documentation_of: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp
- /library/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp.html
title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
---
# 第2種スターリング数 (Stirling number of the second kind)

$$x^n = \sum_{k = 0}^n S(n, k) x^{\underline{k}}$$

で定義される $S$ である．

$$\begin{aligned} S(n, k) = \begin{cases} 1 & (n = k) \\ 0 & (n \geq 1,\ k = 0) \\ S(n-1, k-1) + k S(n-1, k) & (1 \leq k < n) \end{cases} \end{aligned}$$

なる漸化式より計算ができる．

一般項は

$$S(n,k) = \dfrac{\sum_{i = 1}^k (-1)^{k - i} \binom{k}{i} i^n}{k!}$$

である．

組合せ数学においては区別された $n$ 個を $k$ グループに分割する個数を意味する．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(K\log{N})$|
|数表|$O(NK)$|
|数表 形式的冪級数版|$O(N\log{N})$|


## 使用法

||説明|
|:--:|:--:|
|`stirling_number_of_the_second_kind<T>(n, k)`|第2種スターリング数 $S(n,k)$|

- 数表

||説明|
|:--:|:--:|
|`stirling_number_of_the_second_kind_init<T>(n, k)`|第2種スターリング数 $S(i, j) \ (0 \leq i \leq n,\ 0 \leq j \leq k)$ の数表|

- 数表 形式的冪級数版

||説明|
|:--:|:--:|
|`stirling_number_of_the_second_kind_init_with_fps<T>(n)`|第2種スターリング数 $S(n, k) \ (0 \leq k \leq n)$ の数表|


## 参考

- https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0
- https://mathtrain.jp/stnum
- https://mathtrain.jp/zensya
- 数表 形式的冪級数版
  - https://min-25.hatenablog.com/entry/2015/04/07/160154


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_I/review/4088846/emthrm/C++14
- [数表](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_I/review/4088857/emthrm/C++14)
- [数表 形式的冪級数版](https://judge.yosupo.jp/submission/4636)