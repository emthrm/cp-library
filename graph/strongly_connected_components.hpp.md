---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/strongly_connected_components.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n// #include <algorithm>\r\n#include <vector>\r\n\r\n#include\
    \ \"./edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstruct StronglyConnectedComponents\
    \ {\r\n  std::vector<int> id;\r\n  std::vector<std::vector<int>> vertices;\r\n\
    \  std::vector<std::vector<Edge<CostType>>> g;\r\n\r\n  explicit StronglyConnectedComponents(\r\
    \n      const std::vector<std::vector<Edge<CostType>>>& graph,\r\n      const\
    \ bool is_full_ver = false)\r\n      : is_full_ver(is_full_ver), n(graph.size()),\
    \ is_used(n, false),\r\n        graph(graph), rgraph(n) {\r\n    for (int i =\
    \ 0; i < n; ++i) {\r\n      if (!is_used[i]) dfs(i);\r\n    }\r\n    id.assign(n,\
    \ -1);\r\n    order.reserve(n);\r\n    for (int i = 0; i < n; ++i) {\r\n     \
    \ for (const Edge<CostType>& e : graph[i]) {\r\n        rgraph[e.dst].emplace_back(e.dst,\
    \ e.src, e.cost);\r\n      }\r\n    }\r\n    int m = 0;\r\n    for (int i = n\
    \ - 1; i >= 0; --i) {\r\n      if (id[order[i]] == -1) {\r\n        if (is_full_ver)\
    \ vertices.emplace_back();\r\n        rdfs(order[i], m++);\r\n      }\r\n    }\r\
    \n    g.resize(m);\r\n    for (int i = 0; i < n; ++i) {\r\n      for (const Edge<CostType>&\
    \ e : graph[i]) {\r\n        if (id[i] != id[e.dst]) g[id[i]].emplace_back(id[i],\
    \ id[e.dst], e.cost);\r\n      }\r\n    }\r\n    // if (is_full_ver) {\r\n   \
    \ //   for (int i = 0; i < m; ++i) {\r\n    //     std::sort(vertices[i].begin(),\
    \ vertices[i].end());\r\n    //   }\r\n    // }\r\n  }\r\n\r\n private:\r\n  const\
    \ bool is_full_ver;\r\n  const int n;\r\n  std::vector<bool> is_used;\r\n  std::vector<int>\
    \ order;\r\n  const std::vector<std::vector<Edge<CostType>>> graph;\r\n  std::vector<std::vector<Edge<CostType>>>\
    \ rgraph;\r\n\r\n  void dfs(const int ver) {\r\n    is_used[ver] = true;\r\n \
    \   for (const Edge<CostType>& e : graph[ver]) {\r\n      if (!is_used[e.dst])\
    \ dfs(e.dst);\r\n    }\r\n    order.emplace_back(ver);\r\n  }\r\n\r\n  void rdfs(const\
    \ int ver, const int m) {\r\n    id[ver] = m;\r\n    if (is_full_ver) vertices.back().emplace_back(ver);\r\
    \n    for (const Edge<CostType>& e : rgraph[ver]) {\r\n      if (id[e.dst] ==\
    \ -1) rdfs(e.dst, m);\r\n    }\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/strongly_connected_components.test.cpp
documentation_of: graph/strongly_connected_components.hpp
layout: document
title: "\u5F37\u9023\u7D50\u6210\u5206 (strongly connected components) \u5206\u89E3"
---

有向グラフを共通部分の存在しない強連結成分に分解することである．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- Kosaraju's algorithm

||説明|備考|
|:--:|:--:|:--:|
|`SCC<CostType>(graph, 完全版であるか = false)`|有向グラフ $\mathrm{graph}$ の強連結成分分解を考える．||
|`id[i]`|元のグラフの頂点 $i$ を含む頂点||
|`vertices[i]`|縮約後のグラフの頂点 $i$ に含まれる頂点|完全版のみ|
|`g`|強連結成分を一つの頂点に縮約したグラフ||


## 備考

無向グラフの辺に向きをつけることで強連結成分分解できる $\Leftrightarrow$ グラフが2辺連結である

構築方法としては深さ優先探索木で後退辺を逆辺とすればよい．


## 参考

Kosaraju's algorithm
- https://github.com/beet-aizu/library/blob/346558ee0881bd18b10c0d32d7678b033d6b0326/graph/stronglyconnectedcomponent.cpp

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

- [Kosaraju's algorithm](https://judge.yosupo.jp/submission/4441)
