---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/eulerian_trail_in_undirected_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\
      \u30D5\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/eulerian_trail.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\
      \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/eulerian_trail_in_undirected_graph.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\r\n * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\
    \u7248\r\n * @docs docs/graph/eulerian_trail.md\r\n */\r\n\r\n#pragma once\r\n\
    #include <algorithm>\r\n#include <cassert>\r\n#include <vector>\r\n\r\nstruct\
    \ EulerianTrailInUndirectedGraph {\r\n  std::vector<int> trail;\r\n\r\n  explicit\
    \ EulerianTrailInUndirectedGraph(const int n)\r\n      : n(n), is_visited(n),\
    \ graph(n) {}\r\n\r\n  void add_edge(const int u, const int v) {\r\n    graph[u].emplace_back(v,\
    \ graph[v].size());\r\n    graph[v].emplace_back(u, graph[u].size() - 1);\r\n\
    \  }\r\n\r\n  bool build(int s = -1) {\r\n    trail.clear();\r\n    int odd_deg\
    \ = 0, edge_num = 0;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (graph[i].size()\
    \ & 1) {\r\n        ++odd_deg;\r\n        if (s == -1) s = i;\r\n      }\r\n \
    \     edge_num += graph[i].size();\r\n    }\r\n    edge_num >>= 1;\r\n    if (edge_num\
    \ == 0) {\r\n      trail = {s == -1 ? 0 : s};\r\n      return true;\r\n    }\r\
    \n    if (odd_deg == 0) {\r\n      if (s == -1) {\r\n        for (int i = 0; i\
    \ < n; ++i) {\r\n          if (!graph[i].empty()) {\r\n            s = i;\r\n\
    \            break;\r\n          }\r\n        }\r\n      }\r\n    } else if (odd_deg\
    \ != 2) {\r\n      return false;\r\n    }\r\n    for (int i = 0; i < n; ++i) {\r\
    \n      is_visited[i].assign(graph[i].size(), false);\r\n    }\r\n    dfs(s);\r\
    \n    if (trail.size() == edge_num + 1) {\r\n      std::reverse(trail.begin(),\
    \ trail.end());\r\n      return true;\r\n    }\r\n    trail.clear();\r\n    return\
    \ false;\r\n  }\r\n\r\n private:\r\n  struct Edge {\r\n    int dst, rev;\r\n \
    \   explicit Edge(const int dst, const int rev) : dst(dst), rev(rev) {}\r\n  };\r\
    \n\r\n  const int n;\r\n  std::vector<std::vector<bool>> is_visited;\r\n  std::vector<std::vector<Edge>>\
    \ graph;\r\n\r\n  void dfs(const int ver) {\r\n    const int deg = graph[ver].size();\r\
    \n    for (int i = 0; i < deg; ++i) {\r\n      if (!is_visited[ver][i]) {\r\n\
    \        const int dst = graph[ver][i].dst;\r\n        is_visited[ver][i] = true;\r\
    \n        is_visited[dst][graph[ver][i].rev] = true;\r\n        dfs(dst);\r\n\
    \      }\r\n    }\r\n    trail.emplace_back(ver);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulerian_trail_in_undirected_graph.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

連結グラフ $G$ が準オイラーグラフである必要十分条件は
- $G$ が無向グラフのとき，奇数次数の頂点がちょうど $2$ 個存在することであり，
- $G$ が有向グラフのとき，相対出次数 $1$，相対入次数 $1$ の頂点が一つずつ存在し，他の頂点の相対次数が $0$ であることである．


## オイラーグラフ (Eulerian graph)

オイラー閉路 (Euler circuit) が存在するグラフである．

連結グラフ $G$ がオイラーグラフである必要十分条件は
- $G$ が無向グラフのとき，任意の頂点の次数が偶数であることであり，
- $G$ が有向グラフのとき，任意の頂点の相対次数が $0$ であることである．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- オイラー路 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`eulerian_trail_in_directed_graph(graph, s = -1)`|有向グラフ $\mathrm{graph}$ における始点 $s$ のオイラー路|存在しないときは空配列となる．|

- オイラー路 無向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`EulerianTrailInUndirectedGraph(n)`|頂点数 $N$ の無向グラフにおけるオイラー路を考える．||
|`trail`|オイラー路|存在しないときは空配列となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を加える．||
|`build(s = -1)`|始点 $s$ のオイラー路を構築できたか．||


## 参考

- https://kokiymgch.hatenablog.com/entry/2017/12/07/193238

オイラー路 有向グラフ版
- http://www.prefield.com/algorithm/graph/directed_euler_path.html

オイラー路 無向グラフ版
- https://github.com/spaghetti-source/algorithm/blob/2c70d7af4d132513fa699a5de5b2aaf21aaf7890/graph/eulerian_path_undirected.cc


## Verified

- [オイラー路 有向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0225/review/4082901/emthrm/C++14)
- [オイラー路 無向グラフ版](https://yukicoder.me/submissions/701541)
