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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\n// #include <algorithm>\n#include <vector>\n\n#include \"./edge.hpp\"\
    \n\ntemplate <typename CostType>\nstruct StronglyConnectedComponents {\n  std::vector<int>\
    \ id;\n  std::vector<std::vector<int>> vertices;\n  std::vector<std::vector<Edge<CostType>>>\
    \ g;\n\n  explicit StronglyConnectedComponents(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n      const bool is_full_ver = false)\n      : is_full_ver(is_full_ver),\
    \ n(graph.size()), is_used(n, false),\n        graph(graph), rgraph(n) {\n   \
    \ for (int i = 0; i < n; ++i) {\n      if (!is_used[i]) dfs(i);\n    }\n    id.assign(n,\
    \ -1);\n    order.reserve(n);\n    for (int i = 0; i < n; ++i) {\n      for (const\
    \ Edge<CostType>& e : graph[i]) {\n        rgraph[e.dst].emplace_back(e.dst, e.src,\
    \ e.cost);\n      }\n    }\n    int m = 0;\n    for (int i = n - 1; i >= 0; --i)\
    \ {\n      if (id[order[i]] == -1) {\n        if (is_full_ver) vertices.emplace_back();\n\
    \        rdfs(order[i], m++);\n      }\n    }\n    g.resize(m);\n    for (int\
    \ i = 0; i < n; ++i) {\n      for (const Edge<CostType>& e : graph[i]) {\n   \
    \     if (id[i] != id[e.dst]) g[id[i]].emplace_back(id[i], id[e.dst], e.cost);\n\
    \      }\n    }\n    // if (is_full_ver) {\n    //   for (int i = 0; i < m; ++i)\
    \ {\n    //     std::sort(vertices[i].begin(), vertices[i].end());\n    //   }\n\
    \    // }\n  }\n\n private:\n  const bool is_full_ver;\n  const int n;\n  std::vector<bool>\
    \ is_used;\n  std::vector<int> order;\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n  std::vector<std::vector<Edge<CostType>>> rgraph;\n\n  void dfs(const\
    \ int ver) {\n    is_used[ver] = true;\n    for (const Edge<CostType>& e : graph[ver])\
    \ {\n      if (!is_used[e.dst]) dfs(e.dst);\n    }\n    order.emplace_back(ver);\n\
    \  }\n\n  void rdfs(const int ver, const int m) {\n    id[ver] = m;\n    if (is_full_ver)\
    \ vertices.back().emplace_back(ver);\n    for (const Edge<CostType>& e : rgraph[ver])\
    \ {\n      if (id[e.dst] == -1) rdfs(e.dst, m);\n    }\n  }\n};\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/strongly_connected_components.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
