---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ lowlink \u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/2-edge-connected_components.md
    document_title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink\
      \ \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/2-edge-connected_components_by_lowlink.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\n * @brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink\
    \ \u7248\n * @docs docs/graph/2-edge-connected_components.md\n */\n\n#pragma once\n\
    // #include <algorithm>\n#include <vector>\n\n#include \"./edge.hpp\"\n#include\
    \ \"./lowlink.hpp\"\n\ntemplate <typename CostType>\nstruct TwoEdgeConnectedComponents\
    \ : Lowlink<CostType> {\n  std::vector<int> id;\n  std::vector<std::vector<int>>\
    \ vertices;\n  std::vector<std::vector<Edge<CostType>>> g;\n\n  explicit TwoEdgeConnectedComponents(\n\
    \      const std::vector<std::vector<Edge<CostType>>>& graph,\n      const bool\
    \ is_full_ver = false)\n      : Lowlink<CostType>(graph), is_full_ver(is_full_ver)\
    \ {\n    const int n = graph.size();\n    id.assign(n, -1);\n    int m = 0;\n\
    \    for (int i = 0; i < n; ++i) {\n      if (id[i] == -1) dfs(-1, i, &m);\n \
    \   }\n    g.resize(m);\n    for (const Edge<CostType>& e : this->bridges) {\n\
    \      const int u = id[e.src], v = id[e.dst];\n      g[u].emplace_back(u, v,\
    \ e.cost);\n      g[v].emplace_back(v, u, e.cost);\n    }\n    // if (is_full_ver)\
    \ {\n    //   for (int i = 0; i < m; ++i) {\n    //     std::sort(vertices[i].begin(),\
    \ vertices[i].end());\n    //   }\n    // }\n  }\n\n private:\n  const bool is_full_ver;\n\
    \n  void dfs(const int par, const int ver, int* m) {\n    if (par != -1 && this->order[par]\
    \ >= this->lowlink[ver]) {\n      id[ver] = id[par];\n    } else {\n      id[ver]\
    \ = (*m)++;\n      if (is_full_ver) vertices.emplace_back();\n    }\n    if (is_full_ver)\
    \ vertices[id[ver]].emplace_back(ver);\n    for (const Edge<CostType>& e : this->graph[ver])\
    \ {\n      if (id[e.dst] == -1) dfs(ver, e.dst, m);\n    }\n  }\n};\n"
  dependsOn:
  - graph/edge.hpp
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/2-edge-connected_components_by_lowlink.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/2-edge-connected_components_by_lowlink.test.cpp
documentation_of: graph/2-edge-connected_components_by_lowlink.hpp
layout: document
redirect_from:
- /library/graph/2-edge-connected_components_by_lowlink.hpp
- /library/graph/2-edge-connected_components_by_lowlink.hpp.html
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink \u7248"
---
# 二重辺連結成分 (2-edge-connected component) 分解

無向グラフを橋の存在しない部分グラフに分解することである．

それぞれの成分には，任意の3点を始点・経由点・終点とする辺素パスが存在し，さらに任意の2点を結ぶ2本以上の辺素パスが存在する．


### bridge-block tree

二重辺連結成分を一つの頂点に縮約することで得られる木である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|[lowlink](lowlink.md) 版|$O(\lvert V \rvert + \lvert E \rvert)$|
|いもす法版|$O(\lvert V \rvert + \lvert E \rvert \log{\lvert E \rvert})$|


## 使用法

- lowlink 版

||説明|備考|
|:--:|:--:|:--:|
|`TwoEdgeConnectedComponents<CostType>(graph, 完全版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重辺連結成分分解を考える．|
|`id[i]`|元のグラフの頂点 $i$ を含む頂点||
|`vertices[i]`|縮約後のグラフの頂点 $i$ に含まれる頂点|完全版のみ|
|`g`|二重辺連結成分を一つの頂点に縮約したグラフ||

- いもす法版

||説明|備考|
|:--:|:--:|:--:|
|`TwoEdgeConnectedComponentsByImos<CostType>(graph, 完全版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重辺連結成分分解を考える．||
|`id[i]`|元のグラフの頂点 $i$ を含む頂点||
|`bridge`|橋||
|`vertices[i]`|縮約後のグラフの頂点 $i$ に含まれる頂点|完全版のみ|
|`g`|二重辺連結成分を一つの頂点に縮約したグラフ||


## 参考

- https://en.wikipedia.org/wiki/Bridge_(graph_theory)
- https://www.slideshare.net/chokudai/arc039

lowlink 版
- https://ei1333.github.io/luzhiled/snippets/graph/two-edge-connected-components.html


## ToDo

- 三重辺連結成分分解
  - https://ja.wikipedia.org/wiki/%E9%80%A3%E7%B5%90%E3%82%B0%E3%83%A9%E3%83%95
  - https://judge.yosupo.jp/problem/three_edge_connected_components


## Verified

- [lowlink 版](https://atcoder.jp/contests/arc039/submissions/9288123)
- [いもす法版](https://judge.yosupo.jp/submission/5729)
