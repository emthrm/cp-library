---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/mo.test.cpp
    title: "\u305D\u306E\u4ED6/Mo's algorithm"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/mo.hpp\"\n#include <algorithm>\r\n#include <cmath>\r\
    \n#include <numeric>\r\n#include <vector>\r\n\r\nstruct Mo {\r\n  Mo(const std::vector<int>\
    \ &left, const std::vector<int> &right) : left(left), right(right) {\r\n    n\
    \ = left.size();\r\n    int width = std::sqrt(n);\r\n    order.resize(n);\r\n\
    \    std::iota(order.begin(), order.end(), 0);\r\n    std::sort(order.begin(),\
    \ order.end(), [&](int a, int b) -> bool {\r\n      return left[a] / width !=\
    \ left[b] / width ? left[a] < left[b] : ((left[a] / width) & 1 ? right[a] < right[b]\
    \ : right[a] > right[b]);\r\n    });\r\n  }\r\n\r\n  int process() {\r\n    if\
    \ (ptr == n) return -1;\r\n    int idx = order[ptr++];\r\n    while (left[idx]\
    \ < nl) add(--nl);\r\n    while (nr < right[idx]) add(nr++);\r\n    while (nl\
    \ < left[idx]) del(nl++);\r\n    while (right[idx] < nr) del(--nr);\r\n    return\
    \ idx;\r\n  }\r\n\r\n  void add(int idx) const;\r\n\r\n  void del(int idx) const;\r\
    \n\r\nprivate:\r\n  std::vector<int> left, right, order;\r\n  int n, ptr = 0,\
    \ nl = 0, nr = 0;\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <numeric>\r\
    \n#include <vector>\r\n\r\nstruct Mo {\r\n  Mo(const std::vector<int> &left, const\
    \ std::vector<int> &right) : left(left), right(right) {\r\n    n = left.size();\r\
    \n    int width = std::sqrt(n);\r\n    order.resize(n);\r\n    std::iota(order.begin(),\
    \ order.end(), 0);\r\n    std::sort(order.begin(), order.end(), [&](int a, int\
    \ b) -> bool {\r\n      return left[a] / width != left[b] / width ? left[a] <\
    \ left[b] : ((left[a] / width) & 1 ? right[a] < right[b] : right[a] > right[b]);\r\
    \n    });\r\n  }\r\n\r\n  int process() {\r\n    if (ptr == n) return -1;\r\n\
    \    int idx = order[ptr++];\r\n    while (left[idx] < nl) add(--nl);\r\n    while\
    \ (nr < right[idx]) add(nr++);\r\n    while (nl < left[idx]) del(nl++);\r\n  \
    \  while (right[idx] < nr) del(--nr);\r\n    return idx;\r\n  }\r\n\r\n  void\
    \ add(int idx) const;\r\n\r\n  void del(int idx) const;\r\n\r\nprivate:\r\n  std::vector<int>\
    \ left, right, order;\r\n  int n, ptr = 0, nl = 0, nr = 0;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/mo.test.cpp
documentation_of: misc/mo.hpp
layout: document
title: Mo's algorithm
---

- オフラインである．
- 要素の更新がない．
- $[L, R]$ の結果から $[L - 1, R],\ [L + 1, R],\ [L, R - 1],\ [L, R + 1]$ の結果が容易に得られる．

上記の条件を満たすことによって区間に関するクエリを高速に処理することができるアルゴリズムである．


## 時間計算量

$1$回あたりの伸縮に $O(\alpha)$ かかるとおくと $O(Q\log{Q} + \alpha N\sqrt{Q})$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Mo(left, right)`|クエリ $\lbrace [\mathrm{left}, \mathrm{right}) \rbrace$ の Mo's algorithm を考える．||
|`process()`|現在のクエリのインデックス|存在しない場合は $-1$ となる．|
|`add(idx)`|$A_{\mathrm{idx}}$ をクエリの範囲に追加する．|関数プロトタイプ|
|`del(idx)`|$A_{\mathrm{idx}}$ をクエリの範囲から削除する．|関数プロトタイプ|


## 参考

- https://ei1333.hateblo.jp/entry/2017/09/11/211011
- https://snuke.hatenablog.com/entry/2016/07/01/000000


## ToDo

- https://www.hamayanhamayan.com/entry/2017/04/18/012937
- Rollback 平方分割
  - https://snuke.hatenablog.com/entry/2016/07/01/000000
  - https://lumakernel.github.io/ecasdqina/algorithm/MoEx
  - https://github.com/ei1333/library/blob/master/other/mo-rollback.cpp
- 木上の Mo's algorithm，時空間 Mo's algorithm
  - https://ei1333.hateblo.jp/entry/2017/09/11/211011
  - https://ei1333.github.io/algorithm/mo.html
  - https://lumakernel.github.io/ecasdqina/algorithm/Mo
  - https://lumakernel.github.io/ecasdqina/algorithm/Mo3D
  - https://codeforces.com/blog/entry/43230
  - https://codeforces.com/blog/entry/55574
  - https://codeforces.com/contest/1476/problem/G
  - https://twitter.com/SSRS_cp/status/1355193120204312576


## Verified

https://judge.yosupo.jp/submission/17371