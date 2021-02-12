---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/scc.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n// #include <algorithm>\r\n#include <vector>\r\n#include\
    \ \"edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstruct SCC {\r\n  std::vector<int>\
    \ id;\r\n  std::vector<std::vector<int>> vertices;\r\n  std::vector<std::vector<Edge<CostType>>>\
    \ comp;\r\n\r\n  SCC(const std::vector<std::vector<Edge<CostType>>> &graph, bool\
    \ heavy = false) : graph(graph), heavy(heavy) {\r\n    n = graph.size();\r\n \
    \   rev_graph.resize(n);\r\n    for (int i = 0; i < n; ++i) for (const Edge<CostType>\
    \ &e : graph[i]) {\r\n      rev_graph[e.dst].emplace_back(e.dst, e.src, e.cost);\r\
    \n    }\r\n    used.assign(n, false);\r\n    id.assign(n, -1);\r\n    for (int\
    \ i = 0; i < n; ++i) {\r\n      if (!used[i]) dfs(i);\r\n    }\r\n    int now\
    \ = 0;\r\n    for (int i = n - 1; i >= 0; --i) {\r\n      if (id[order[i]] ==\
    \ -1) {\r\n        if (heavy) vertices.emplace_back();\r\n        rev_dfs(order[i],\
    \ now++);\r\n      }\r\n    }\r\n    comp.resize(now);\r\n    for (int i = 0;\
    \ i < n; ++i) for (const Edge<CostType> &e : graph[i]) {\r\n      if (id[i] !=\
    \ id[e.dst]) comp[id[i]].emplace_back(id[i], id[e.dst], e.cost);\r\n    }\r\n\
    \    // if (heavy) {\r\n    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(),\
    \ vertices[i].end());\r\n    // }\r\n  }\r\n\r\nprivate:\r\n  bool heavy;\r\n\
    \  int n;\r\n  std::vector<std::vector<Edge<CostType>>> graph, rev_graph;\r\n\
    \  std::vector<bool> used;\r\n  std::vector<int> order;\r\n\r\n  void dfs(int\
    \ ver) {\r\n    used[ver] = true;\r\n    for (const Edge<CostType> &e : graph[ver])\
    \ {\r\n      if (!used[e.dst]) dfs(e.dst);\r\n    }\r\n    order.emplace_back(ver);\r\
    \n  }\r\n\r\n  void rev_dfs(int ver, int now) {\r\n    id[ver] = now;\r\n    if\
    \ (heavy) vertices[now].emplace_back(ver);\r\n    for (const Edge<CostType> &e\
    \ : rev_graph[ver]) {\r\n      if (id[e.dst] == -1) rev_dfs(e.dst, now);\r\n \
    \   }\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/scc.test.cpp
documentation_of: graph/scc.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (strongly connected components)"
---

有向グラフを共通部分のない強連結成分に分解することである．

- Kosaraju's algorithm


### 強連結成分

任意の2頂点について互いに到達可能である強連結な集合の内, 他の任意の頂点集合と和を取っても強連結成分にならないものである．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`SCC<CostType>(graph, 重量版であるか = false)`|有向グラフ $\mathrm{graph}$ の強連結成分分解を考える．||
|`id[i]`|元のグラフの頂点 $i$ を含む頂点||
|`vertices[i]`|縮約後のグラフの頂点 $i$ に含まれる頂点|重量版のみ|
|`comp`|強連結成分を一つの頂点につぶしたグラフ||


## 備考

無向グラフの辺に向きをつけることで強連結成分分解可能 $\Leftrightarrow$ グラフが2辺連結．

構築方法としては深さ優先探索木において後退辺を逆辺とすればよい．


## 参考

- https://github.com/beet-aizu/library/blob/master/graph/stronglyconnectedcomponent.cpp

備考
- https://twitter.com/noshi91/status/1172798654450520064


## ToDo

- Tarjan's algorithm
  - http://www.prefield.com/algorithm/graph/strongly_connected_components.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/strongly_connected_component_tarjan.cc
  - https://tubo28.me/compprog/algorithm/tarjan-scc/
- Gabow's algorithm
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/strongly_connected_component_gabow.cc


## Verified

https://judge.yosupo.jp/submission/4441
