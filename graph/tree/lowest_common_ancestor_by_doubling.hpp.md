---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/2-edge-connected_components_lowlink.test.cpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/tree/lowest_common_ancestor_by_doubling.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u7248\r\n * @docs docs/graph/tree/lowest_common_ancestor.md\r\n */\r\n\r\
    \n#pragma once\r\n#include <cassert>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"../edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstruct LowestCommonAncestorByDoubling\
    \ {\r\n  std::vector<int> depth;\r\n  std::vector<CostType> dist;\r\n\r\n  LowestCommonAncestorByDoubling(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph) : graph(graph) {\r\n    n =\
    \ graph.size();\r\n    depth.resize(n);\r\n    dist.resize(n);\r\n    while ((1\
    \ << table_h) <= n) ++table_h;\r\n    parent.resize(table_h, std::vector<int>(n));\r\
    \n  }\r\n\r\n  void build(int root = 0) {\r\n    is_built = true;\r\n    dfs(-1,\
    \ root, 0, 0);\r\n    for (int i = 0; i + 1 < table_h; ++i) for (int ver = 0;\
    \ ver < n; ++ver) {\r\n      parent[i + 1][ver] = parent[i][ver] == -1 ? -1 :\
    \ parent[i][parent[i][ver]];\r\n    }\r\n  }\r\n\r\n  int query(int u, int v)\
    \ const {\r\n    assert(is_built);\r\n    if (depth[u] > depth[v]) std::swap(u,\
    \ v);\r\n    for (int i = 0; i < table_h; ++i) {\r\n      if ((depth[v] - depth[u])\
    \ >> i & 1) v = parent[i][v];\r\n    }\r\n    if (u == v) return u;\r\n    for\
    \ (int i = table_h - 1; i >= 0; --i) {\r\n      if (parent[i][u] != parent[i][v])\
    \ {\r\n        u = parent[i][u];\r\n        v = parent[i][v];\r\n      }\r\n \
    \   }\r\n    return parent[0][u];\r\n  }\r\n\r\n  CostType distance(int u, int\
    \ v) const {\r\n    assert(is_built);\r\n    return dist[u] + dist[v] - dist[query(u,\
    \ v)] * 2;\r\n  }\r\n\r\nprivate:\r\n  bool is_built = false;\r\n  int n, table_h\
    \ = 1;\r\n  std::vector<std::vector<Edge<CostType>>> graph;\r\n  std::vector<std::vector<int>>\
    \ parent;\r\n\r\n  void dfs(int par, int ver, int now_depth, CostType now_dist)\
    \ {\r\n    depth[ver] = now_depth;\r\n    dist[ver] = now_dist;\r\n    parent[0][ver]\
    \ = par;\r\n    for (const Edge<CostType> &e : graph[ver]) {\r\n      if (e.dst\
    \ != par) dfs(ver, e.dst, now_depth + 1, now_dist + e.cost);\r\n    }\r\n  }\r\
    \n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/lowest_common_ancestor_by_doubling.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/2-edge-connected_components_lowlink.test.cpp
  - test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
documentation_of: graph/tree/lowest_common_ancestor_by_doubling.hpp
layout: document
redirect_from:
- /library/graph/tree/lowest_common_ancestor_by_doubling.hpp
- /library/graph/tree/lowest_common_ancestor_by_doubling.hpp.html
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\u30B0\u7248"
---
# 最小共通祖先 (lowest common ancestor)

根付き木のある2頂点において最も深い共通祖先である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|ダブリング版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\log{\lvert V \rvert}) \rangle$|
|オイラーツアー版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(1) \rangle$|


## 使用法

- ダブリング版

||説明|
|:--:|:--:|
|`LowestCommonAncestorByDoubling<CostType>(graph)`|木 $\mathrm{graph}$ の最小共通祖先を考える|
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

- プログラミングコンテストチャレンジブック \[第2版\] pp.292-295
- https://yukicoder.me/wiki/lowest_common_ancestor

オイラーツアー
- https://github.com/drken1215/algorithm/blob/efb8cf052b095e49e70135a6fb628308d06f49b2/DataStructureOnTree/euler_tour_on_nodes.cpp


## ToDo

- Tarjan's off-line lowest common ancestors algorithm
  - http://www.prefield.com/algorithm/graph/least_common_ancestor.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/least_common_ancestor_tarjan.cc
  - http://monyone.github.io/teihen_library/#OfflineLCA
- level ancestor problem
  - https://en.wikipedia.org/wiki/Level_ancestor_problem
  - https://37zigen.com/level-ancestor-problem/
  - https://drive.google.com/drive/folders/1atQRO6Y9bHgLDH-YLq3obDwMxIuk7--h
  - https://noshi91.hatenablog.com/entry/2019/09/22/114149


## Verified

- [ダブリング版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4084783/emthrm/C++14)
- [オイラーツアー版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14)
- [HL 分解版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)
