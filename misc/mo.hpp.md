---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/misc/mo.test.cpp
    title: "\u305D\u306E\u4ED6/Mo's algorithm"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/mo.hpp\"\n#include <algorithm>\r\n#include <cmath>\r\
    \n#include <numeric>\r\n#include <vector>\r\n\r\nstruct Mo {\r\n  explicit Mo(const\
    \ std::vector<int>& ls, const std::vector<int>& rs)\r\n      : ls(ls), rs(rs),\
    \ n(ls.size()), ptr(0), nl(0), nr(0) {\r\n    const int width = std::round(std::sqrt(n));\r\
    \n    order.resize(n);\r\n    std::iota(order.begin(), order.end(), 0);\r\n  \
    \  std::sort(order.begin(), order.end(),\r\n              [&ls, &rs, width](const\
    \ int a, const int b) -> bool {\r\n                  if (ls[a] / width != ls[b]\
    \ / width) return ls[a] < ls[b];\r\n                  return (ls[a] / width) &\
    \ 1 ? rs[a] < rs[b] : rs[a] > rs[b];\r\n              });\r\n  }\r\n\r\n  int\
    \ process() {\r\n    if (ptr == n) return -1;\r\n    const int id = order[ptr++];\r\
    \n    while (ls[id] < nl) add(--nl);\r\n    while (nr < rs[id]) add(nr++);\r\n\
    \    while (nl < ls[id]) del(nl++);\r\n    while (rs[id] < nr) del(--nr);\r\n\
    \    return id;\r\n  }\r\n\r\n  void add(const int idx) const;\r\n\r\n  void del(const\
    \ int idx) const;\r\n\r\n private:\r\n  const int n;\r\n  int ptr, nl, nr;\r\n\
    \  std::vector<int> ls, rs, order;\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <numeric>\r\
    \n#include <vector>\r\n\r\nstruct Mo {\r\n  explicit Mo(const std::vector<int>&\
    \ ls, const std::vector<int>& rs)\r\n      : ls(ls), rs(rs), n(ls.size()), ptr(0),\
    \ nl(0), nr(0) {\r\n    const int width = std::round(std::sqrt(n));\r\n    order.resize(n);\r\
    \n    std::iota(order.begin(), order.end(), 0);\r\n    std::sort(order.begin(),\
    \ order.end(),\r\n              [&ls, &rs, width](const int a, const int b) ->\
    \ bool {\r\n                  if (ls[a] / width != ls[b] / width) return ls[a]\
    \ < ls[b];\r\n                  return (ls[a] / width) & 1 ? rs[a] < rs[b] : rs[a]\
    \ > rs[b];\r\n              });\r\n  }\r\n\r\n  int process() {\r\n    if (ptr\
    \ == n) return -1;\r\n    const int id = order[ptr++];\r\n    while (ls[id] <\
    \ nl) add(--nl);\r\n    while (nr < rs[id]) add(nr++);\r\n    while (nl < ls[id])\
    \ del(nl++);\r\n    while (rs[id] < nr) del(--nr);\r\n    return id;\r\n  }\r\n\
    \r\n  void add(const int idx) const;\r\n\r\n  void del(const int idx) const;\r\
    \n\r\n private:\r\n  const int n;\r\n  int ptr, nl, nr;\r\n  std::vector<int>\
    \ ls, rs, order;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/misc/mo.test.cpp
documentation_of: misc/mo.hpp
layout: document
title: Mo's algorithm
---

- オフラインである．
- 要素の更新がない．
- $\lbrack L, R \rbrack$ の結果から $\lbrack L - 1, R \rbrack,\ \lbrack L + 1, R \rbrack,\ \lbrack L, R - 1 \rbrack,\ \lbrack L, R + 1 \rbrack$ の結果が容易に得られる．

上記の条件を満たすことによって区間に関するクエリを高速に処理できるアルゴリズムである．


## 時間計算量

一回の伸縮あたり $O(\alpha)$ 時間かかるとおくと $O(Q\log{Q} + \alpha N\sqrt{Q})$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Mo(ls, rs)`|クエリ $\lbrace \lbrack \mathrm{ls}, \mathrm{rs}) \rbrace$ の Mo's algorithm を考える．||
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
