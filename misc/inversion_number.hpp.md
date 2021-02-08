---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/bit/bit.hpp
    title: binary indexed tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/misc/inversion_number.test.cpp
    title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/bit/bit.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n#include \"\
    ../data_structure/bit/bit.hpp\"\r\n\r\ntemplate <typename T>\r\nlong long inversion_number(const\
    \ std::vector<T> &a) {\r\n  int n = a.size();\r\n  std::vector<T> comp(a);\r\n\
    \  std::sort(comp.begin(), comp.end());\r\n  comp.erase(std::unique(comp.begin(),\
    \ comp.end()), comp.end());\r\n  BIT<int> bit(comp.size());\r\n  long long res\
    \ = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    int idx = std::lower_bound(comp.begin(),\
    \ comp.end(), a[i]) - comp.begin();\r\n    res += i - bit.sum(idx + 1);\r\n  \
    \  bit.add(idx, 1);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - data_structure/bit/bit.hpp
  isVerificationFile: false
  path: misc/inversion_number.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/misc/inversion_number.test.cpp
documentation_of: misc/inversion_number.hpp
layout: document
title: "\u8EE2\u5012\u6570 (\u53CD\u8EE2\u6570 / inversion number)"
---

数列 $A$ について $A_i > A_j \ (i < j)$ を満たす $(i, j)$ の個数である．

バブルソートに必要な交換回数に等しい．


### バブルソート (bubble sort)

隣接二要素の順序関係が正しくない場合に交換することでソートを行うアルゴリズムである．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`inversion_number(a)`|$A$ の転倒数|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.162-163


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_5_D/review/4087800/emthrm/C++14
