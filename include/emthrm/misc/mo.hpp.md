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
  bundledCode: "#line 1 \"include/emthrm/misc/mo.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cmath>\n#include <numeric>\n#include <vector>\n\nnamespace emthrm {\n\
    \nstruct Mo {\n  explicit Mo(const std::vector<int>& ls, const std::vector<int>&\
    \ rs)\n      : n(ls.size()), ptr(0), nl(0), nr(0), ls(ls), rs(rs) {\n    const\
    \ int width = std::round(std::sqrt(n));\n    order.resize(n);\n    std::iota(order.begin(),\
    \ order.end(), 0);\n    std::sort(order.begin(), order.end(),\n              [&ls,\
    \ &rs, width](const int a, const int b) -> bool {\n                  if (ls[a]\
    \ / width != ls[b] / width) return ls[a] < ls[b];\n                  return (ls[a]\
    \ / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];\n              });\n  }\n\n  int\
    \ process() {\n    if (ptr == n) return -1;\n    const int id = order[ptr++];\n\
    \    while (ls[id] < nl) add(--nl);\n    while (nr < rs[id]) add(nr++);\n    while\
    \ (nl < ls[id]) del(nl++);\n    while (rs[id] < nr) del(--nr);\n    return id;\n\
    \  }\n\n  void add(const int idx) const;\n\n  void del(const int idx) const;\n\
    \n private:\n  const int n;\n  int ptr, nl, nr;\n  std::vector<int> ls, rs, order;\n\
    };\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MISC_MO_HPP_\n#define EMTHRM_MISC_MO_HPP_\n\n#include <algorithm>\n\
    #include <cmath>\n#include <numeric>\n#include <vector>\n\nnamespace emthrm {\n\
    \nstruct Mo {\n  explicit Mo(const std::vector<int>& ls, const std::vector<int>&\
    \ rs)\n      : n(ls.size()), ptr(0), nl(0), nr(0), ls(ls), rs(rs) {\n    const\
    \ int width = std::round(std::sqrt(n));\n    order.resize(n);\n    std::iota(order.begin(),\
    \ order.end(), 0);\n    std::sort(order.begin(), order.end(),\n              [&ls,\
    \ &rs, width](const int a, const int b) -> bool {\n                  if (ls[a]\
    \ / width != ls[b] / width) return ls[a] < ls[b];\n                  return (ls[a]\
    \ / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];\n              });\n  }\n\n  int\
    \ process() {\n    if (ptr == n) return -1;\n    const int id = order[ptr++];\n\
    \    while (ls[id] < nl) add(--nl);\n    while (nr < rs[id]) add(nr++);\n    while\
    \ (nl < ls[id]) del(nl++);\n    while (rs[id] < nr) del(--nr);\n    return id;\n\
    \  }\n\n  void add(const int idx) const;\n\n  void del(const int idx) const;\n\
    \n private:\n  const int n;\n  int ptr, nl, nr;\n  std::vector<int> ls, rs, order;\n\
    };\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MISC_MO_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/misc/mo.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/mo.test.cpp
documentation_of: include/emthrm/misc/mo.hpp
layout: document
title: Mo's algorithm
---

- オフラインである。
- 要素の更新がない。
- $\lbrack L, R \rbrack$ の結果から $\lbrack L - 1, R \rbrack,\ \lbrack L + 1, R \rbrack,\ \lbrack L, R - 1 \rbrack,\ \lbrack L, R + 1 \rbrack$ の結果が容易に得られる。

上記の条件を満たすことによって区間に関するクエリを高速に処理できるアルゴリズムである。


## 時間計算量

一回の伸縮あたり $O(\alpha)$ 時間かかるとおくと $O(Q\log{Q} + \alpha N\sqrt{Q})$


## 仕様

```cpp
struct Mo;
```

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit Mo(const std::vector<int>& ls, const std::vector<int>& rs);`|クエリ集合 $\lbrace \lbrack \mathrm{ls}_i, \mathrm{rs}_i) \rbrace$ のオブジェクトを構築する。||
|`int process();`|現在のクエリのインデックス。ただし存在しないときは $-1$ を返す。|
|`void add(const int idx) const;`|$A_{\mathrm{idx}}$ をクエリの範囲に追加する。|関数プロトタイプ|
|`void del(const int idx) const;`|$A_{\mathrm{idx}}$ をクエリの範囲から削除する。|関数プロトタイプ|


## 参考文献

- https://ei1333.hateblo.jp/entry/2017/09/11/211011
- https://snuke.hatenablog.com/entry/2016/07/01/000000


## TODO

- https://www.hamayanhamayan.com/entry/2017/04/18/012937
- Rollback 平方分割
  - https://snuke.hatenablog.com/entry/2016/07/01/000000
  - https://lumakernel.github.io/ecasdqina/algorithm/MoEx
  - https://github.com/ei1333/library/blob/master/other/mo-rollback.cpp
- 木上の Mo's algorithm、時空間 Mo's algorithm
  - https://ei1333.hateblo.jp/entry/2017/09/11/211011
  - https://ei1333.github.io/algorithm/mo.html
  - ~~https://lumakernel.github.io/ecasdqina/algorithm/Mo~~
  - ~~https://lumakernel.github.io/ecasdqina/algorithm/Mo3D~~
  - https://twitter.com/heno_code/status/1518799816876118016
  - https://codeforces.com/blog/entry/43230
  - https://codeforces.com/blog/entry/55574
  - https://codeforces.com/contest/1476/problem/G
  - https://twitter.com/SSRS_cp/status/1355193120204312576


## Submissons

https://judge.yosupo.jp/submission/17371
