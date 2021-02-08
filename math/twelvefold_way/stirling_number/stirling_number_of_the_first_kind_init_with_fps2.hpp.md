---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/fps/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_with_fps2.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
      \u6570/\u7B2C1\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868\
      \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u72482"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind.md
    document_title: "\u7B2C1\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\
      \u6570\u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u72482"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_with_fps2.hpp:\
    \ line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u7B2C1\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\
    \u6570\u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u72482\r\n * @docs docs/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"../../fps/fps.hpp\"\
    \r\n\r\ntemplate <typename T>\r\nstd::vector<T> stirling_number_of_the_first_kind_init_with_fps2(int\
    \ n) {\r\n  if (n == 0) return {1};\r\n  std::vector<FPS<T>> stirling;\r\n  stirling.reserve(n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    stirling.emplace_back(FPS<T>{-i, 1});\r\
    \n    // stirling.emplace_back(FPS<T>{i, 1});\r\n  }\r\n  while (stirling.size()\
    \ > 1) {\r\n    int sz = stirling.size();\r\n    std::vector<FPS<T>> nx;\r\n \
    \   nx.reserve(sz + (sz & 1));\r\n    for (int i = 0; i + 1 < sz; i += 2) nx.emplace_back(stirling[i]\
    \ * stirling[i + 1]);\r\n    if (sz & 1) nx.emplace_back(stirling.back());\r\n\
    \    stirling.swap(nx);\r\n  }\r\n  return stirling[0].co;\r\n}\r\n"
  dependsOn:
  - math/fps/fps.hpp
  isVerificationFile: false
  path: math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_with_fps2.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_with_fps2.test.cpp
documentation_of: math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_with_fps2.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_with_fps2.hpp
- /library/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_with_fps2.hpp.html
title: "\u7B2C1\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868\
  \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u72482"
---
# 第1種スターリング数 (Stirling number of the first kind)

$$x^{\overline{n}} = \sum_{k = 0}^n s(n, k) x^k$$

で定義される $s$ である．

$$\begin{aligned} s(n, k) = \begin{cases} 1 & (n = k) \\ 0 & (n \geq 1,\ k = 0) \\ s(n - 1, k - 1) + (n - 1)s(n - 1, k) & (1 \leq k < n) \end{cases} \end{aligned}$$

なる漸化式より計算ができる．

組合せ数学においては区別された $n$ 個を $k$ 個の巡回列に分割する個数を意味する．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(NK)$|
|形式的冪級数版|$O(N\log{N})$|
|形式的冪級数版2|$O(N(\log{N})^2)$|


## 使用法

||説明|
|:--:|:--:|
|`stirling_number_of_the_first_kind_init<T>(n, k)`|第1種スターリング数 $s(i, j) \ (0 \leq i \leq n,\ 0 \leq j \leq k)$ の数表|

- 形式的冪級数版

||説明|備考|
|:--:|:--:|:--:|
|`stirling_number_of_the_first_kind_init_with_fps<T>(n)`|第1種スターリング数 $s(n, k) \ (0 \leq k \leq n)$ の数表|$x^{\underline{n}} = \sum_{k = 0}^n s(n, k) x^k$|

- 形式的冪級数版2

||説明|備考|
|:--:|:--:|:--:|
|`stirling_number_of_the_first_kind_init_with_fps2<T>(n)`|第1種スターリング数 $s(n, k) \ (0 \leq k \leq n)$ の数表|$x^{\underline{n}} = \sum_{k = 0}^n s(n, k) x^k$|


## 参考

- https://ja.wikipedia.org/wiki/%E3%82%B9%E3%82%BF%E3%83%BC%E3%83%AA%E3%83%B3%E3%82%B0%E6%95%B0
- 形式的冪級数版
  - https://min-25.hatenablog.com/entry/2015/04/07/160154

## ToDo

- https://github.com/ei1333/library/blob/master/math/fps/formal-power-series-seq.cpp


## Verified

- []()
- [形式的冪級数版](https://judge.yosupo.jp/submission/4637)
- [形式的冪級数版2](https://judge.yosupo.jp/submission/4638)
