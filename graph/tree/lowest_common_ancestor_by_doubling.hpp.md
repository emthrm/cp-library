---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ lowlink \u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\
      \u30EA\u30F3\u30B0\u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/graph/tree/lowest_common_ancestor.md
    document_title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\
      \u30B0\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/tree/lowest_common_ancestor_by_doubling.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u7248\n * @docs docs/graph/tree/lowest_common_ancestor.md\n */\n\n#pragma\
    \ once\n#include <cassert>\n#include <utility>\n#include <vector>\n\n#include\
    \ \"../edge.hpp\"\n\ntemplate <typename CostType>\nstruct LowestCommonAncestorByDoubling\
    \ {\n  std::vector<int> depth;\n  std::vector<CostType> dist;\n\n  explicit LowestCommonAncestorByDoubling(\n\
    \      const std::vector<std::vector<Edge<CostType>>>& graph)\n      : is_built(false),\
    \ n(graph.size()), table_h(1), graph(graph) {\n    depth.resize(n);\n    dist.resize(n);\n\
    \    while ((1 << table_h) <= n) ++table_h;\n    parent.resize(table_h, std::vector<int>(n));\n\
    \  }\n\n  void build(const int root = 0) {\n    is_built = true;\n    dfs(-1,\
    \ root, 0, 0);\n    for (int i = 0; i + 1 < table_h; ++i) {\n      for (int ver\
    \ = 0; ver < n; ++ver) {\n        parent[i + 1][ver] =\n            (parent[i][ver]\
    \ == -1 ? -1 : parent[i][parent[i][ver]]);\n      }\n    }\n  }\n\n  int query(int\
    \ u, int v) const {\n    assert(is_built);\n    if (depth[u] > depth[v]) std::swap(u,\
    \ v);\n    for (int i = 0; i < table_h; ++i) {\n      if ((depth[v] - depth[u])\
    \ >> i & 1) v = parent[i][v];\n    }\n    if (u == v) return u;\n    for (int\
    \ i = table_h - 1; i >= 0; --i) {\n      if (parent[i][u] != parent[i][v]) {\n\
    \        u = parent[i][u];\n        v = parent[i][v];\n      }\n    }\n    return\
    \ parent.front()[u];\n  }\n\n  CostType distance(const int u, const int v) const\
    \ {\n    assert(is_built);\n    return dist[u] + dist[v] - dist[query(u, v)] *\
    \ 2;\n  }\n\n private:\n  bool is_built;\n  const int n;\n  int table_h;\n  std::vector<std::vector<int>>\
    \ parent;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  void dfs(const\
    \ int par, const int ver, const int cur_depth,\n           const CostType cur_dist)\
    \ {\n    depth[ver] = cur_depth;\n    dist[ver] = cur_dist;\n    parent.front()[ver]\
    \ = par;\n    for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst !=\
    \ par) dfs(ver, e.dst, cur_depth + 1, cur_dist + e.cost);\n    }\n  }\n};\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/lowest_common_ancestor_by_doubling.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
  - test/graph/2-edge-connected_components_by_lowlink.test.cpp
documentation_of: graph/tree/lowest_common_ancestor_by_doubling.hpp
layout: document
redirect_from:
- /library/graph/tree/lowest_common_ancestor_by_doubling.hpp
- /library/graph/tree/lowest_common_ancestor_by_doubling.hpp.html
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\u30B0\u7248"
---
# 最小共通祖先 (lowest common ancestor)

根付き木のある2頂点に対して最も深い共通祖先である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|ダブリング版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\log{\lvert V \rvert}) \rangle$|
|オイラーツアー版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(1) \rangle$|


## 使用法

- ダブリング版

||説明|
|:--:|:--:|
|`LowestCommonAncestorByDoubling<CostType>(graph)`|木 $\mathrm{graph}$ の最小共通祖先を考える．|
|`depth[i]`|頂点 $i$ の深さ|
|`dist[i]`|根と頂点 $i$ の間の距離|
|`build(root = 0)`|根を $\mathrm{root}$ として構築する．|
|`query(u, v)`|頂点 $u, v$ の最小共通祖先|
|`distance(u, v)`|頂点 $u, v$ 間の距離|

- [オイラーツアー](euler_tour.md)版

||説明|
|:--:|:--:|
|`LowestCommonAncestor<CostType>(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ の最小共通祖先を構築する．|
|`query(u, v)`|頂点 $u, v$ の最小共通祖先|

- [HL 分解版](heavy-light_decomposition.md)


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.292-295，マイナビ出版（2012）
- https://yukicoder.me/wiki/lowest_common_ancestor

オイラーツアー版
- https://github.com/drken1215/algorithm/blob/efb8cf052b095e49e70135a6fb628308d06f49b2/DataStructureOnTree/euler_tour_on_nodes.cpp


## ToDo

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


## Verified

- [ダブリング版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4084783/emthrm/C++14)
- [オイラーツアー版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14)
- [HL 分解版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)
