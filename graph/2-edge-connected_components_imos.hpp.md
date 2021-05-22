---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/detect_bridge.hpp
    title: "\u6A4B\u306E\u691C\u51FA"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/2-edge-connected_components_imos.test.cpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/2-edge-connected_components_imos.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/**\r\n * @brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\
    \u3082\u3059\u6CD5\u7248\r\n * @docs docs/graph/2-edge-connected_components.md\r\
    \n */\r\n\r\n#pragma once\r\n// #include <algorithm>\r\n#include <set>\r\n#include\
    \ <queue>\r\n#include <utility>\r\n#include <vector>\r\n#include \"edge.hpp\"\r\
    \n#include \"detect_bridge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstruct\
    \ TwoEdgeConnectedComponentsImos {\r\n  std::vector<Edge<CostType>> bridge;\r\n\
    \  std::vector<int> id;\r\n  std::vector<std::vector<int>> vertices;\r\n  std::vector<std::vector<Edge<CostType>>>\
    \ comp;\r\n\r\n  TwoEdgeConnectedComponentsImos(const std::vector<std::vector<Edge<CostType>>>\
    \ &graph, bool heavy = false) : bridge(detect_bridge(graph)) {\r\n    int n =\
    \ graph.size();\r\n    id.assign(n, -1);\r\n    std::set<std::pair<int, int>>\
    \ st;\r\n    for (const Edge<CostType> &e : bridge) {\r\n      st.emplace(e.src,\
    \ e.dst);\r\n      st.emplace(e.dst, e.src);\r\n    }\r\n    int now = 0;\r\n\
    \    std::queue<int> que;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (id[i]\
    \ != -1) continue;\r\n      que.emplace(i);\r\n      id[i] = now++;\r\n      if\
    \ (heavy) vertices.emplace_back(std::vector<int>{i});\r\n      while (!que.empty())\
    \ {\r\n        int ver = que.front(); que.pop();\r\n        for (const Edge<CostType>\
    \ &e : graph[ver]) {\r\n          if (id[e.dst] == -1 && st.count({ver, e.dst})\
    \ == 0) {\r\n            id[e.dst] = id[i];\r\n            if (heavy) vertices[id[i]].emplace_back(e.dst);\r\
    \n            que.emplace(e.dst);\r\n          }\r\n        }\r\n      }\r\n \
    \   }\r\n    comp.resize(now);\r\n    for (const Edge<CostType> &e : bridge) {\r\
    \n      int u = id[e.src], v = id[e.dst];\r\n      comp[u].emplace_back(u, v,\
    \ e.cost);\r\n      comp[v].emplace_back(v, u, e.cost);\r\n    }\r\n    // for\
    \ (int i = 0; i < now; ++i) std::sort(vertices[i].begin(), vertices[i].end());\r\
    \n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/detect_bridge.hpp
  isVerificationFile: false
  path: graph/2-edge-connected_components_imos.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/2-edge-connected_components_imos.test.cpp
documentation_of: graph/2-edge-connected_components_imos.hpp
layout: document
redirect_from:
- /library/graph/2-edge-connected_components_imos.hpp
- /library/graph/2-edge-connected_components_imos.hpp.html
title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\u3082\u3059\u6CD5\
  \u7248"
---
# 二重辺連結成分 (2-edge-connected component) 分解

無向グラフを橋の存在しない部分グラフに分解することである．

それぞれの成分には，任意の3点を始点・経由点・終点とする辺素パスが存在し，さらに任意の2点を結ぶ2本以上の辺素パスが存在する．


### bridge-block tree

二重辺連結成分を一つの頂点につぶすことで得られる木である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|lowlink 版|$O(\lvert V \rvert + \lvert E \rvert)$|
|いもす法版|$O(\lvert V \rvert + \lvert E \rvert \log{\lvert E \rvert})$|


## 使用法

- lowlink 版

||説明|備考|
|:--:|:--:|:--:|
|`TwoEdgeConnectedComponents<CostType>(graph, 重量版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重辺連結成分分解を考える．|[lowlink](lowlink.md)|
|`id[i]`|元のグラフの頂点 $i$ を含む頂点||
|`vertices[i]`|縮約後のグラフの頂点 $i$ に含まれる頂点|重量版のみ|
|`comp`|二重辺連結成分を一つの頂点につぶしたグラフ||

- いもす法版

||説明|備考|
|:--:|:--:|:--:|
|`TwoEdgeConnectedComponentsImos<CostType>(graph, 重量版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重辺連結成分分解を考える．||
|`bridge`|橋||
|`id[i]`|元のグラフの頂点 $i$ を含む頂点||
|`vertices[i]`|縮約後のグラフの頂点 $i$ に含まれる頂点|重量版のみ|
|`comp`|二重辺連結成分を一つの頂点につぶしたグラフ||


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