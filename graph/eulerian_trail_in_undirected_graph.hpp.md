---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/eulerian_trail_in_undirected_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\
      \u30D5\u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/eulerian_trail.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\
      \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/eulerian_trail_in_undirected_graph.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\r\n * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\
    \u7248\r\n * @docs docs/graph/eulerian_trail.md\r\n */\r\n\r\n#pragma once\r\n\
    #include <algorithm>\r\n#include <cassert>\r\n#include <vector>\r\n\r\nstruct\
    \ EulerianTrailInUndirectedGraph {\r\n  std::vector<int> trail;\r\n\r\n  EulerianTrailInUndirectedGraph(int\
    \ n) : n(n), graph(n), visited(n) {}\r\n\r\n  void add_edge(int u, int v) {\r\n\
    \    graph[u].emplace_back(v, graph[v].size());\r\n    graph[v].emplace_back(u,\
    \ graph[u].size() - 1);\r\n  }\r\n\r\n  bool build(int s = -1) {\r\n    trail.clear();\r\
    \n    int odd = 0, edges = 0;\r\n    for (int i = 0; i < n; ++i) {\r\n      if\
    \ (graph[i].size() & 1) {\r\n        ++odd;\r\n        if (s == -1) s = i;\r\n\
    \      }\r\n      edges += graph[i].size();\r\n    }\r\n    if (s == -1) {\r\n\
    \      for (int i = 0; i < n; ++i) {\r\n        if (!graph[i].empty()) {\r\n \
    \         s = i;\r\n          break;\r\n        }\r\n      }\r\n      if (s ==\
    \ -1) {\r\n        assert(edges == 0);\r\n        trail.emplace_back(0);\r\n \
    \       return true;\r\n      }\r\n    }\r\n    for (int i = 0; i < n; ++i) visited[i].assign(graph[i].size(),\
    \ false);\r\n    if (odd == 0 || (odd == 2 && (graph[s].size() & 1))) {\r\n  \
    \    dfs(s);\r\n      if (trail.size() == (edges >> 1) + 1) {\r\n        std::reverse(trail.begin(),\
    \ trail.end());\r\n        return true;\r\n      }\r\n      trail.clear();\r\n\
    \    }\r\n    return false;\r\n  }\r\n\r\nprivate:\r\n  struct Edge {\r\n    int\
    \ dst, rev;\r\n    Edge(int dst, int rev) : dst(dst), rev(rev) {}\r\n  };\r\n\r\
    \n  int n;\r\n  std::vector<std::vector<Edge>> graph;\r\n  std::vector<std::vector<bool>>\
    \ visited;\r\n\r\n  void dfs(int ver) {\r\n    int sz = graph[ver].size();\r\n\
    \    for (int i = 0; i < sz; ++i) {\r\n      if (!visited[ver][i]) {\r\n     \
    \   int nx = graph[ver][i].dst;\r\n        visited[ver][i] = visited[nx][graph[ver][i].rev]\
    \ = true;\r\n        dfs(nx);\r\n      }\r\n    }\r\n    trail.emplace_back(ver);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulerian_trail_in_undirected_graph.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/eulerian_trail_in_undirected_graph.test.cpp
documentation_of: graph/eulerian_trail_in_undirected_graph.hpp
layout: document
redirect_from:
- /library/graph/eulerian_trail_in_undirected_graph.hpp
- /library/graph/eulerian_trail_in_undirected_graph.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\u7248"
---
## オイラー路 (Eulerian trail)

グラフのすべての辺を一度だけ通る路である．


## 準オイラーグラフ (semi-Eulerian graph)

閉路でないオイラー路が存在するグラフである．

$$\text{準オイラーグラフ} \Leftrightarrow \begin{cases} \text{次数奇数の頂点がちょうど 2 個存在} & (\text{無向グラフ}) \\ \text{始点の相対出次数が 1, 終点の相対入次数が 1, 他の頂点の相対次数が 0} & (\text{有向グラフ}) \text{．} \end{cases}$$


## オイラーグラフ (Eulerian graph)

オイラー閉路 (Euler circuit) が存在するグラフである．

$$\text{オイラーグラフ} \Leftrightarrow \begin{cases} \text{任意の頂点の次数が偶数} & (\text{無向グラフ}) \\ \text{任意の頂点の相対次数が 0} & (\text{有向グラフ}) \text{．} \end{cases}$$


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- オイラー路 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`eulerian_trail_in_directed_graph(graph, s = -1)`|有向グラフ $\mathrm{graph}$，始点 $s$ のオイラー路|存在しない場合は空配列となる．|

- オイラー路 無向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`EulerianTrailInUndirectedGraph(n)`|頂点数 $N$ の無向グラフにおけるオイラー路||
|`trail`|オイラー路|存在しない場合は空配列となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を追加する．||
|`build(s = -1)`|始点 $s$ のオイラー路を構築できたか．|一度のみ．|


## 参考

- https://www.learning-algorithms.com/entry/2017/12/07/193238

オイラー路 有向グラフ版
- http://www.prefield.com/algorithm/graph/directed_euler_path.html

オイラー路 無向グラフ版
- https://github.com/spaghetti-source/algorithm/blob/2c70d7af4d132513fa699a5de5b2aaf21aaf7890/graph/eulerian_path_undirected.cc


## Verified

- [オイラー路 有向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0225/review/4082901/emthrm/C++14)
- [オイラー路 無向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0086/review/4579202/emthrm/C++14)
