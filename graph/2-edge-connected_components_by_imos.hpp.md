---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/enumerate_bridges.hpp
    title: "\u6A4B\u306E\u691C\u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/2-edge-connected_components_by_imos.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ \u3044\u3082\u3059\u6CD5\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/2-edge-connected_components.md
    document_title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\
      \u3082\u3059\u6CD5\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/2-edge-connected_components_by_imos.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\n * @brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\
    \u3082\u3059\u6CD5\u7248\n * @docs docs/graph/2-edge-connected_components.md\n\
    \ */\n\n#pragma once\n#include <algorithm>\n#include <set>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\n#include \"./edge.hpp\"\n#include \"\
    ./enumerate_bridges.hpp\"\n\ntemplate <typename CostType>\nstruct TwoEdgeConnectedComponentsByImos\
    \ {\n  std::vector<int> id;\n  std::vector<Edge<CostType>> bridge;\n  std::vector<std::vector<int>>\
    \ vertices;\n  std::vector<std::vector<Edge<CostType>>> g;\n\n  explicit TwoEdgeConnectedComponentsByImos(\n\
    \      const std::vector<std::vector<Edge<CostType>>>& graph,\n      const bool\
    \ is_full_ver = false)\n      : bridge(enumerate_bridges(graph)) {\n    const\
    \ int n = graph.size();\n    id.assign(n, -1);\n    std::set<std::pair<int, int>>\
    \ st;\n    for (const Edge<CostType>& e : bridge) st.emplace(e.src, e.dst);\n\
    \    int m = 0;\n    std::queue<int> que;\n    for (int i = 0; i < n; ++i) {\n\
    \      if (id[i] != -1) continue;\n      que.emplace(i);\n      id[i] = m++;\n\
    \      if (is_full_ver) vertices.emplace_back(std::vector<int>{i});\n      while\
    \ (!que.empty()) {\n        const int ver = que.front();\n        que.pop();\n\
    \        for (const Edge<CostType>& e : graph[ver]) {\n          if (id[e.dst]\
    \ == -1 && !st.count(std::minmax(ver, e.dst))) {\n            id[e.dst] = id[i];\n\
    \            if (is_full_ver) vertices.back().emplace_back(e.dst);\n         \
    \   que.emplace(e.dst);\n          }\n        }\n      }\n    }\n    g.resize(m);\n\
    \    for (const Edge<CostType>& e : bridge) {\n      const int u = id[e.src],\
    \ v = id[e.dst];\n      g[u].emplace_back(u, v, e.cost);\n      g[v].emplace_back(v,\
    \ u, e.cost);\n    }\n    if (is_full_ver) {\n      for (int i = 0; i < m; ++i)\
    \ {\n        std::sort(vertices[i].begin(), vertices[i].end());\n      }\n   \
    \ }\n  }\n};\n"
  dependsOn:
  - graph/edge.hpp
  - graph/enumerate_bridges.hpp
  isVerificationFile: false
  path: graph/2-edge-connected_components_by_imos.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/2-edge-connected_components_by_imos.test.cpp
documentation_of: graph/2-edge-connected_components_by_imos.hpp
layout: document
redirect_from:
- /library/graph/2-edge-connected_components_by_imos.hpp
- /library/graph/2-edge-connected_components_by_imos.hpp.html
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\u3082\u3059\u6CD5\
  \u7248"
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
