---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/partition_function_by_fps.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570 $n = m$ \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/partition_function.md
    document_title: "\u5206\u5272\u6570 $n = m$ \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/partition_function_by_fps.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief \u5206\u5272\u6570 $n = m$ \u7248\r\n * @docs docs/math/twelvefold_way/partition_function.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"../formal_power_series/formal_power_series.hpp\"\
    \r\n\r\ntemplate <typename T>\r\nstd::vector<T> partition_function_by_fps(const\
    \ int n) {\r\n  FormalPowerSeries<T> fps(n);\r\n  fps[0] = 1;\r\n  for (int i\
    \ = 1; i <= n; ++i) {\r\n    long long idx = static_cast<long long>(3 * i + 1)\
    \ * i / 2;\r\n    if (idx <= n) {\r\n      fps[idx] += (i & 1 ? -1 : 1);\r\n \
    \   }\r\n    idx = static_cast<long long>(3 * i - 1) * i / 2;\r\n    if (idx <=\
    \ n) {\r\n      fps[idx] += (i & 1 ? -1 : 1);\r\n    }\r\n  }\r\n  return fps.inv(n).co;\r\
    \n}\r\n"
  dependsOn:
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: math/twelvefold_way/partition_function_by_fps.hpp
  requiredBy: []
  timestamp: '2021-09-24 03:41:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/partition_function_by_fps.test.cpp
documentation_of: math/twelvefold_way/partition_function_by_fps.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/partition_function_by_fps.hpp
- /library/math/twelvefold_way/partition_function_by_fps.hpp.html
title: "\u5206\u5272\u6570 $n = m$ \u7248"
---
# 分割数 (partition function)

自然数 $n$ を $m$ 個以下の正の整数の和で表す方法の総数の内, $n = m$ を満たすもの．

和の順序は問わず，$2 + 1 + 1$ と $1 + 2 + 1$ を区別しない．

分割数 $p(n)$ の母関数は

$$\sum_{n = 0}^\infty p(n) x^n = \prod_{n = 1}^{\infty} \dfrac{1}{1 - x^n}$$

である．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(NM)$|
|$n = m$ 版|$O(N\log{N})$|


## 使用法

||説明|
|:--:|:--:|
|`partition_function<T>(n, m)`|分割数の数表|

- $n = m$ 版

||説明|
|:--:|:--:|
|`partition_function_by_fps<T>(n)`|$n = m$ のときの分割数の数表|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.66-67，マイナビ出版（2012）．
- https://ja.wikipedia.org/wiki/%E5%88%86%E5%89%B2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E3%81%AE%E4%BA%94%E8%A7%92%E6%95%B0%E5%AE%9A%E7%90%86


## ToDo

- $O(N\sqrt{N})$ で求める．
  - http://degwer.hatenablog.com/entries/2017/08/29
  - https://qiita.com/drken/items/f2ea4b58b0d21621bd51
  - https://judge.yosupo.jp/problem/partition_function


## Verified

- https://yukicoder.me/submissions/701499
- [$n = m$ 版](https://judge.yosupo.jp/submission/3791)
