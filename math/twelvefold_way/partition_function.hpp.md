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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/partition_function.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/**\n * @brief \u5206\u5272\u6570\n * @docs docs/math/twelvefold_way/partition_function.md\n\
    \ */\n\n#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstd::vector<std::vector<T>> partition_function(const int n, const int m)\
    \ {\n  std::vector<std::vector<T>> p(n + 1, std::vector<T>(m + 1, 0));\n  p[0][0]\
    \ = 1;\n  for (int i = 1; i <= n; ++i) {\n    std::copy(p[i - 1].begin(), p[i\
    \ - 1].end(), p[i].begin());\n    for (int j = i; j <= m; ++j) {\n      p[i][j]\
    \ += p[i][j - i];\n    }\n  }\n  return p;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/twelvefold_way/partition_function.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/twelvefold_way/partition_function_init.test.cpp
documentation_of: math/twelvefold_way/partition_function.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/partition_function.hpp
- /library/math/twelvefold_way/partition_function.hpp.html
title: "\u5206\u5272\u6570"
---
# 分割数 (partition function)

自然数 $n$ を $m$ 個以下の正の整数の和で表す方法の総数の内，$n = m$ を満たすもの．

和の順序は問わず，$2 + 1 + 1$ と $1 + 2 + 1$ を区別しない．

分割数 $p(n)$ の母関数は

$$
  \sum_{n = 0}^\infty p(n) x^n = \prod_{n = 1}^{\infty} \dfrac{1}{1 - x^n}
$$

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

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.66-67，マイナビ出版（2012）
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
