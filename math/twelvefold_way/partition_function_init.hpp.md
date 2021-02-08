---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/twelvefold_way/partition_function_init.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/partition_function.md
    document_title: "\u5206\u5272\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/partition_function_init.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief \u5206\u5272\u6570\r\n * @docs docs/math/twelvefold_way/partition_function.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\n\
    std::vector<std::vector<T>> partition_function_init(int group, int sum) {\r\n\
    \  std::vector<std::vector<T>> pf(group + 1, std::vector<T>(sum + 1, 0));\r\n\
    \  pf[0][0] = 1;\r\n  for (int i = 1; i <= group; ++i) for (int j = 0; j <= sum;\
    \ ++j) {\r\n    pf[i][j] = j - i >= 0 ? pf[i][j - i] + pf[i - 1][j] : pf[i - 1][j];\r\
    \n  }\r\n  return pf;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/twelvefold_way/partition_function_init.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/twelvefold_way/partition_function_init.test.cpp
documentation_of: math/twelvefold_way/partition_function_init.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/partition_function_init.hpp
- /library/math/twelvefold_way/partition_function_init.hpp.html
title: "\u5206\u5272\u6570"
---
# 分割数 (partition function)

$n$ を $m$ 個以下に分割する方法の総数の内, $n = m$ を満たすもの．

$m$ 個の区別はないため $(4, 1, 1)$ と $(1, 4, 1)$ は同じ分け方となる．

母関数は

$$P(x) = \prod_{n = 1}^{\infty} \dfrac{1}{1 - x^n}$$

である．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(NM)$|
|$n = m$ 版|$O(N\log{N})$|


## 使用法

||説明|
|:--:|:--:|
|`partition_function_init<T>(group, sum)`|分割数の数表|

- $n = m$ 版

||説明|
|:--:|:--:|
|`partition_function_init_with_fps<T>(val)`|$n = m$ のときの分割数の数表|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.66-67
- https://ja.wikipedia.org/wiki/%E5%88%86%E5%89%B2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E3%81%AE%E4%BA%94%E8%A7%92%E6%95%B0%E5%AE%9A%E7%90%86


## ToDo

- $n = m$ の場合のみを $O(N\sqrt{N})$ で求める．
  - http://degwer.hatenablog.com/entries/2017/08/29
  - https://qiita.com/drken/items/f2ea4b58b0d21621bd51
  - https://judge.yosupo.jp/problem/partition_function


## Verified

- https://atcoder.jp/contests/dwacon2018-prelims/submissions/9309239
- [$n = m$ 版](https://judge.yosupo.jp/submission/3791)
