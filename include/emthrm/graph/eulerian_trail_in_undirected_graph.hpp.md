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
  bundledCode: "#line 1 \"include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp\"\
    \n/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\
    \u7248\n * @docs docs/graph/eulerian_trail.md\n */\n\n#ifndef EMTHRM_GRAPH_EULERIAN_TRAIL_IN_UNDIRECTED_GRAPH_HPP_\n\
    #define EMTHRM_GRAPH_EULERIAN_TRAIL_IN_UNDIRECTED_GRAPH_HPP_\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iterator>\n#include <utility>\n#include <vector>\n\
    \nnamespace emthrm {\n\nstruct EulerianTrailInUndirectedGraph {\n  std::vector<int>\
    \ trail;\n\n  explicit EulerianTrailInUndirectedGraph(const int n)\n      : n(n),\
    \ is_visited(n), graph(n) {}\n\n  void add_edge(const int u, const int v) {\n\
    \    graph[u].emplace_back(v, graph[v].size());\n    graph[v].emplace_back(u,\
    \ graph[u].size() - 1);\n  }\n\n  bool build(int s = -1) {\n    trail.clear();\n\
    \    int odd_deg = 0, edge_num = 0;\n    for (int i = 0; i < n; ++i) {\n     \
    \ if (graph[i].size() & 1) {\n        ++odd_deg;\n        if (s == -1) s = i;\n\
    \      }\n      edge_num += graph[i].size();\n    }\n    edge_num >>= 1;\n   \
    \ if (edge_num == 0) {\n      trail = {s == -1 ? 0 : s};\n      return true;\n\
    \    }\n    if (odd_deg == 0) {\n      if (s == -1) {\n        s = std::distance(\n\
    \            graph.begin(),\n            std::find_if_not(graph.begin(), graph.end(),\n\
    \                             [](const std::vector<Edge>& edges) -> bool {\n \
    \                              return edges.empty();\n                       \
    \      }));\n      }\n    } else if (odd_deg != 2) {\n      return false;\n  \
    \  }\n    for (int i = 0; i < n; ++i) {\n      is_visited[i].assign(graph[i].size(),\
    \ false);\n    }\n    dfs(s);\n    if (std::cmp_equal(trail.size(), edge_num +\
    \ 1)) {\n      std::reverse(trail.begin(), trail.end());\n      return true;\n\
    \    }\n    trail.clear();\n    return false;\n  }\n\n private:\n  struct Edge\
    \ {\n    int dst, rev;\n    explicit Edge(const int dst, const int rev) : dst(dst),\
    \ rev(rev) {}\n  };\n\n  const int n;\n  std::vector<std::vector<bool>> is_visited;\n\
    \  std::vector<std::vector<Edge>> graph;\n\n  void dfs(const int ver) {\n    const\
    \ int deg = graph[ver].size();\n    for (int i = 0; i < deg; ++i) {\n      if\
    \ (!is_visited[ver][i]) {\n        const int dst = graph[ver][i].dst;\n      \
    \  is_visited[ver][i] = true;\n        is_visited[dst][graph[ver][i].rev] = true;\n\
    \        dfs(dst);\n      }\n    }\n    trail.emplace_back(ver);\n  }\n};\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EULERIAN_TRAIL_IN_UNDIRECTED_GRAPH_HPP_\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\
    \u7248\n * @docs docs/graph/eulerian_trail.md\n */\n\n#ifndef EMTHRM_GRAPH_EULERIAN_TRAIL_IN_UNDIRECTED_GRAPH_HPP_\n\
    #define EMTHRM_GRAPH_EULERIAN_TRAIL_IN_UNDIRECTED_GRAPH_HPP_\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iterator>\n#include <utility>\n#include <vector>\n\
    \nnamespace emthrm {\n\nstruct EulerianTrailInUndirectedGraph {\n  std::vector<int>\
    \ trail;\n\n  explicit EulerianTrailInUndirectedGraph(const int n)\n      : n(n),\
    \ is_visited(n), graph(n) {}\n\n  void add_edge(const int u, const int v) {\n\
    \    graph[u].emplace_back(v, graph[v].size());\n    graph[v].emplace_back(u,\
    \ graph[u].size() - 1);\n  }\n\n  bool build(int s = -1) {\n    trail.clear();\n\
    \    int odd_deg = 0, edge_num = 0;\n    for (int i = 0; i < n; ++i) {\n     \
    \ if (graph[i].size() & 1) {\n        ++odd_deg;\n        if (s == -1) s = i;\n\
    \      }\n      edge_num += graph[i].size();\n    }\n    edge_num >>= 1;\n   \
    \ if (edge_num == 0) {\n      trail = {s == -1 ? 0 : s};\n      return true;\n\
    \    }\n    if (odd_deg == 0) {\n      if (s == -1) {\n        s = std::distance(\n\
    \            graph.begin(),\n            std::find_if_not(graph.begin(), graph.end(),\n\
    \                             [](const std::vector<Edge>& edges) -> bool {\n \
    \                              return edges.empty();\n                       \
    \      }));\n      }\n    } else if (odd_deg != 2) {\n      return false;\n  \
    \  }\n    for (int i = 0; i < n; ++i) {\n      is_visited[i].assign(graph[i].size(),\
    \ false);\n    }\n    dfs(s);\n    if (std::cmp_equal(trail.size(), edge_num +\
    \ 1)) {\n      std::reverse(trail.begin(), trail.end());\n      return true;\n\
    \    }\n    trail.clear();\n    return false;\n  }\n\n private:\n  struct Edge\
    \ {\n    int dst, rev;\n    explicit Edge(const int dst, const int rev) : dst(dst),\
    \ rev(rev) {}\n  };\n\n  const int n;\n  std::vector<std::vector<bool>> is_visited;\n\
    \  std::vector<std::vector<Edge>> graph;\n\n  void dfs(const int ver) {\n    const\
    \ int deg = graph[ver].size();\n    for (int i = 0; i < deg; ++i) {\n      if\
    \ (!is_visited[ver][i]) {\n        const int dst = graph[ver][i].dst;\n      \
    \  is_visited[ver][i] = true;\n        is_visited[dst][graph[ver][i].rev] = true;\n\
    \        dfs(dst);\n      }\n    }\n    trail.emplace_back(ver);\n  }\n};\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EULERIAN_TRAIL_IN_UNDIRECTED_GRAPH_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/eulerian_trail_in_undirected_graph.test.cpp
documentation_of: include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp
- /library/include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\u7248"
---
## オイラー路 (Eulerian trail)

グラフのすべての辺を一度だけ通る路である。


## 準オイラーグラフ (semi-Eulerian graph)

閉路でないオイラー路が存在するグラフである。

連結グラフ $G$ が準オイラーグラフである必要十分条件は
- $G$ が無向グラフのとき、奇数次数の頂点がちょうど $2$ 個存在することであり、
- $G$ が有向グラフのとき、相対出次数 $1$、相対入次数 $1$ の頂点が一つずつ存在し、他の頂点の相対次数が $0$ であることである。


## オイラーグラフ (Eulerian graph)

オイラー閉路 (Euler circuit) が存在するグラフである。

連結グラフ $G$ がオイラーグラフである必要十分条件は
- $G$ が無向グラフのとき、任意の頂点の次数が偶数であることであり、
- $G$ が有向グラフのとき、任意の頂点の相対次数が $0$ であることである。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

### オイラー路 有向グラフ版

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<Edge<CostType>> eulerian_trail_in_directed_graph(std::vector<std::vector<Edge<CostType>>> graph, int s = -1);`|有向グラフ $\mathrm{graph}$ における始点 $s$ のオイラー路。ただし存在しないときは空配列を返す。|


### オイラー路 無向グラフ版

```cpp
struct EulerianTrailInUndirectedGraph;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> trail`|オイラー路。ただし存在しないときは空配列となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit EulerianTrailInUndirectedGraph(const int n);`|頂点数 $N$ の無向グラフのオブジェクトを構築する。|
|`void add_edge(const int u, const int v);`|辺 $(u, v)$ を加える。|
|`bool build(int s = -1);`|始点 $s$ のオイラー路を構築できたか。|


## 参考文献

- https://kokiymgch.hatenablog.com/entry/2017/12/07/193238

オイラー路 有向グラフ版
- http://www.prefield.com/algorithm/graph/directed_euler_path.html

オイラー路 無向グラフ版
- https://github.com/spaghetti-source/algorithm/blob/2c70d7af4d132513fa699a5de5b2aaf21aaf7890/graph/eulerian_path_undirected.cc


## Submissons

- [オイラー路 有向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0225/review/4082901/emthrm/C++14)
- [オイラー路 無向グラフ版](https://yukicoder.me/submissions/701541)
