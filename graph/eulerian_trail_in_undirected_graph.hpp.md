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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/eulerian_trail_in_undirected_graph.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\
    \u7248\n * @docs docs/graph/eulerian_trail.md\n */\n\n#pragma once\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nstruct EulerianTrailInUndirectedGraph\
    \ {\n  std::vector<int> trail;\n\n  explicit EulerianTrailInUndirectedGraph(const\
    \ int n)\n      : n(n), is_visited(n), graph(n) {}\n\n  void add_edge(const int\
    \ u, const int v) {\n    graph[u].emplace_back(v, graph[v].size());\n    graph[v].emplace_back(u,\
    \ graph[u].size() - 1);\n  }\n\n  bool build(int s = -1) {\n    trail.clear();\n\
    \    int odd_deg = 0, edge_num = 0;\n    for (int i = 0; i < n; ++i) {\n     \
    \ if (graph[i].size() & 1) {\n        ++odd_deg;\n        if (s == -1) s = i;\n\
    \      }\n      edge_num += graph[i].size();\n    }\n    edge_num >>= 1;\n   \
    \ if (edge_num == 0) {\n      trail = {s == -1 ? 0 : s};\n      return true;\n\
    \    }\n    if (odd_deg == 0) {\n      if (s == -1) {\n        for (int i = 0;\
    \ i < n; ++i) {\n          if (!graph[i].empty()) {\n            s = i;\n    \
    \        break;\n          }\n        }\n      }\n    } else if (odd_deg != 2)\
    \ {\n      return false;\n    }\n    for (int i = 0; i < n; ++i) {\n      is_visited[i].assign(graph[i].size(),\
    \ false);\n    }\n    dfs(s);\n    if (trail.size() == edge_num + 1) {\n     \
    \ std::reverse(trail.begin(), trail.end());\n      return true;\n    }\n    trail.clear();\n\
    \    return false;\n  }\n\n private:\n  struct Edge {\n    int dst, rev;\n   \
    \ explicit Edge(const int dst, const int rev) : dst(dst), rev(rev) {}\n  };\n\n\
    \  const int n;\n  std::vector<std::vector<bool>> is_visited;\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  void dfs(const int ver) {\n    const int deg = graph[ver].size();\n\
    \    for (int i = 0; i < deg; ++i) {\n      if (!is_visited[ver][i]) {\n     \
    \   const int dst = graph[ver][i].dst;\n        is_visited[ver][i] = true;\n \
    \       is_visited[dst][graph[ver][i].rev] = true;\n        dfs(dst);\n      }\n\
    \    }\n    trail.emplace_back(ver);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulerian_trail_in_undirected_graph.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
