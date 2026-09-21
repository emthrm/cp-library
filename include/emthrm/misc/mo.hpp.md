---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306E prefix sum \u306E\u591A\u70B9\u8A55\u4FA1"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/multipoint_binomial_prefix_sum.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E prefix\
      \ sum \u306E\u591A\u70B9\u8A55\u4FA1"
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
    \ntemplate <typename AddLeft, typename AddRight,\n          typename DelLeft,\
    \ typename DelRight>\nstruct Mo {\n  explicit Mo(const std::vector<int>& ls, const\
    \ std::vector<int>& rs,\n              const AddLeft& add_left, const AddRight&\
    \ add_right,\n              const DelLeft& del_left, const DelRight& del_right)\n\
    \      : n(ls.size()), ptr(0), nl(0), nr(0), ls(ls), rs(rs),\n        add_left(add_left),\
    \ add_right(add_right),\n        del_left(del_left), del_right(del_right) {\n\
    \    const int width = (\n        n == 0 ? 1\n               : std::max(std::llround(std::ranges::max(rs)\
    \ / std::sqrt(n)),\n                          1LL));\n    order.resize(n);\n \
    \   std::iota(order.begin(), order.end(), 0);\n    std::sort(order.begin(), order.end(),\n\
    \              [&ls, &rs, width](const int a, const int b) -> bool {\n       \
    \           if (ls[a] / width != ls[b] / width) return ls[a] < ls[b];\n      \
    \            return (ls[a] / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];\n   \
    \           });\n  }\n\n  int process() {\n    if (ptr == n) [[unlikely]] return\
    \ -1;\n    const int id = order[ptr++];\n    while (ls[id] < nl) {\n      const\
    \ int idx = --nl;\n      add_left(idx, nl, nr);\n    }\n    while (nr < rs[id])\
    \ {\n      const int idx = nr++;\n      add_right(idx, nl, nr);\n    }\n    while\
    \ (nl < ls[id]) {\n      const int idx = nl++;\n      del_left(idx, nl, nr);\n\
    \    }\n    while (rs[id] < nr) {\n      const int idx = --nr;\n      del_right(idx,\
    \ nl, nr);\n    }\n    return id;\n  }\n\n private:\n  const int n;\n  int ptr,\
    \ nl, nr;\n  std::vector<int> ls, rs, order;\n  AddLeft add_left;\n  AddRight\
    \ add_right;\n  DelLeft del_left;\n  DelRight del_right;\n};\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_MISC_MO_HPP_\n#define EMTHRM_MISC_MO_HPP_\n\n#include <algorithm>\n\
    #include <cmath>\n#include <numeric>\n#include <vector>\n\nnamespace emthrm {\n\
    \ntemplate <typename AddLeft, typename AddRight,\n          typename DelLeft,\
    \ typename DelRight>\nstruct Mo {\n  explicit Mo(const std::vector<int>& ls, const\
    \ std::vector<int>& rs,\n              const AddLeft& add_left, const AddRight&\
    \ add_right,\n              const DelLeft& del_left, const DelRight& del_right)\n\
    \      : n(ls.size()), ptr(0), nl(0), nr(0), ls(ls), rs(rs),\n        add_left(add_left),\
    \ add_right(add_right),\n        del_left(del_left), del_right(del_right) {\n\
    \    const int width = (\n        n == 0 ? 1\n               : std::max(std::llround(std::ranges::max(rs)\
    \ / std::sqrt(n)),\n                          1LL));\n    order.resize(n);\n \
    \   std::iota(order.begin(), order.end(), 0);\n    std::sort(order.begin(), order.end(),\n\
    \              [&ls, &rs, width](const int a, const int b) -> bool {\n       \
    \           if (ls[a] / width != ls[b] / width) return ls[a] < ls[b];\n      \
    \            return (ls[a] / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];\n   \
    \           });\n  }\n\n  int process() {\n    if (ptr == n) [[unlikely]] return\
    \ -1;\n    const int id = order[ptr++];\n    while (ls[id] < nl) {\n      const\
    \ int idx = --nl;\n      add_left(idx, nl, nr);\n    }\n    while (nr < rs[id])\
    \ {\n      const int idx = nr++;\n      add_right(idx, nl, nr);\n    }\n    while\
    \ (nl < ls[id]) {\n      const int idx = nl++;\n      del_left(idx, nl, nr);\n\
    \    }\n    while (rs[id] < nr) {\n      const int idx = --nr;\n      del_right(idx,\
    \ nl, nr);\n    }\n    return id;\n  }\n\n private:\n  const int n;\n  int ptr,\
    \ nl, nr;\n  std::vector<int> ls, rs, order;\n  AddLeft add_left;\n  AddRight\
    \ add_right;\n  DelLeft del_left;\n  DelRight del_right;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_MISC_MO_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/misc/mo.hpp
  requiredBy:
  - include/emthrm/math/twelvefold_way/multipoint_binomial_prefix_sum.hpp
  timestamp: '2026-09-21 19:26:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/multipoint_binomial_prefix_sum.test.cpp
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
template <typename AddLeft, typename AddRight,
          typename DelLeft, typename DelRight>
struct Mo;
```

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit Mo(const std::vector<int>& ls, const std::vector<int>& rs, const AddLeft& add_left, const AddRight& add_right, const DelLeft& del_left, const DelRight& del_right);`|クエリ集合 $\lbrace \lbrack \mathrm{ls}_i, \mathrm{rs}_i) \rbrace$ と、区間の左端・右端に対する追加・削除をそれぞれ指定してオブジェクトを構築する。||
|`int process();`|次のクエリを処理し、そのインデックスを返す。ただし存在しないときは $-1$ を返す。||


## 参考文献

- https://codeforces.com/blog/entry/81716
- https://ei1333.hateblo.jp/entry/2017/09/11/211011
- https://snuke.hatenablog.com/entry/2016/07/01/000000


## TODO

- https://www.hamayanhamayan.com/entry/2017/04/18/012937
- Rollback 平方分割
  - https://snuke.hatenablog.com/entry/2016/07/01/000000
  - ~~https://lumakernel.github.io/ecasdqina/algorithm/MoEx~~
  - https://github.com/ei1333/library/blob/master/other/mo-rollback.hpp
- 木上の Mo's algorithm、時空間 Mo's algorithm
  - https://ei1333.hateblo.jp/entry/2017/09/11/211011
  - https://ei1333.github.io/algorithm/mo.html
  - ~~https://lumakernel.github.io/ecasdqina/algorithm/Mo~~
  - ~~https://lumakernel.github.io/ecasdqina/algorithm/Mo3D~~
  - https://twitter.com/heno_code/status/1518799816876118016
  - https://twitter.com/noya2ruler/status/1733116450586648702
  - https://codeforces.com/blog/entry/43230
  - https://codeforces.com/blog/entry/55574
  - 問題例 "[Minimum Difference](https://codeforces.com/contest/1476/problem/G)"
    - https://twitter.com/SSRS_cp/status/1355193120204312576


## Submissons

https://judge.yosupo.jp/submission/404491
