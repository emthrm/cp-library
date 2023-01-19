---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/euler_tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC (Euler tour)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/tree/lowest_common_ancestor.md
    document_title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\
      \u30C4\u30A2\u30FC\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp: line 13:\
    \ unable to process #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\
    \u30C4\u30A2\u30FC\u7248\n * @docs docs/graph/tree/lowest_common_ancestor.md\n\
    \ */\n\n#ifndef EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_HPP_\n\
    #define EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_HPP_\n\n#include\
    \ <algorithm>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/data_structure/sparse_table.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/euler_tour.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct LowestCommonAncestor\
    \ : EulerTour<CostType> {\n  explicit LowestCommonAncestor(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n      const int root = 0)\n      : EulerTour<CostType>(graph, root)\
    \ {\n    const int n = this->tour.size();\n    std::vector<std::pair<int, int>>\
    \ nodes(n);\n    for (int i = 0; i < n; ++i) {\n      nodes[i] = {this->depth[i],\
    \ this->tour[i]};\n    }\n    sparse_table.init(\n        nodes,\n        [](const\
    \ std::pair<int, int>& a, const std::pair<int, int>& b)\n            -> std::pair<int,\
    \ int> {\n          return std::min(a, b);\n        });\n  }\n\n  int query(int\
    \ u, int v) const {\n    u = this->left[u];\n    v = this->left[v];\n    if (u\
    \ > v) std::swap(u, v);\n    return sparse_table.query(u, v + 1).second;\n  }\n\
    \n private:\n  SparseTable<std::pair<int, int>> sparse_table;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_HPP_\n"
  dependsOn:
  - include/emthrm/data_structure/sparse_table.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/euler_tour.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
documentation_of: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp
- /library/include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp.html
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
  \u7248"
---
# 最小共通祖先 (lowest common ancestor)

根付き木のある2頂点に対して最も深い共通祖先である。


## 時間計算量

||時間計算量|
|:--|:--|
|ダブリング版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\log{\lvert V \rvert}) \rangle$|
|オイラーツアー版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(1) \rangle$|


## 仕様

### ダブリング版

```cpp
template <typename CostType>
struct LowestCommonAncestorByDoubling;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> depth`|`depth[i]` は頂点 $i$ の深さを表す。|
|`std::vector<CostType> dist`|`dist[i]` は根と頂点 $i$ の間の距離を表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit LowestCommonAncestorByDoubling(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`void build(const int root = 0);`|根を $\mathrm{root}$ として構築する。|
|`int query(int u, int v) const;`|頂点 $u, v$ の最小共通祖先|
|`CostType distance(const int u, const int v) const;`|頂点 $u, v$ 間の距離|


### [オイラーツアー](euler_tour.md)版

```cpp
template <typename CostType>
struct LowestCommonAncestor : EulerTour<CostType>;
```

- `CostType`：辺のコストを表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit LowestCommonAncestor(const std::vector<std::vector<Edge<CostType>>>& graph, const int root = 0);`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`int query(int u, int v) const;`|頂点 $u, v$ の最小共通祖先|


### [HL 分解版](heavy-light_decomposition.md)


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.292-295，マイナビ出版（2012）
- https://yukicoder.me/wiki/lowest_common_ancestor

オイラーツアー版
- https://github.com/drken1215/algorithm/blob/efb8cf052b095e49e70135a6fb628308d06f49b2/DataStructureOnTree/euler_tour_on_nodes.cpp


## TODO

- Tarjan's off-line lowest common ancestors algorithm
  - http://www.prefield.com/algorithm/graph/least_common_ancestor.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/least_common_ancestor_tarjan.cc
  - http://monyone.github.io/teihen_library/#OfflineLCA
- level ancestor problem
  - https://en.wikipedia.org/wiki/Level_ancestor_problem
  - https://www2.compute.dtu.dk/courses/02282/2018/levelancestor/levelancestor1x1.pdf
  - https://37zigen.com/level-ancestor-problem/
  - https://hdbn.hatenadiary.org/entry/20111125/1322194487
  - https://drive.google.com/drive/folders/1atQRO6Y9bHgLDH-YLq3obDwMxIuk7--h
  - https://noshi91.hatenablog.com/entry/2019/09/22/114149
  - https://suisen-kyopro.hatenablog.com/entry/2022/04/04/043452
  - https://twitter.com/GauravML/status/1415073033522319367
  - https://twitter.com/keijak/status/1510953079872663555
  - https://github.com/noshi91/n91lib_rs/blob/master/src/data_structure/level_ancestor.rs
  - https://judge.yosupo.jp/problem/jump_on_tree


## Submissons

- [ダブリング版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4084783/emthrm/C++14)
- [オイラーツアー版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14)
- [HL 分解版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)
