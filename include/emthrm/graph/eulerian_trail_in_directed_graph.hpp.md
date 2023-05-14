---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/eulerian_trail_in_directed_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\
      \u30D5\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/eulerian_trail_in_directed_graph.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#include <ranges>\n#include\
    \ <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n\
    /**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 11 \"include/emthrm/graph/eulerian_trail_in_directed_graph.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>>\
    \ eulerian_trail_in_directed_graph(\n    std::vector<std::vector<Edge<CostType>>>\
    \ graph, int s = -1) {\n  const int n = graph.size();\n  int edge_num = 0;\n \
    \ std::vector<int> deg(n, 0);\n  for (int i = 0; i < n; ++i) {\n    edge_num +=\
    \ graph[i].size();\n    deg[i] += graph[i].size();\n    for (const int e : graph[i]\
    \ | std::views::transform(&Edge<CostType>::dst)) {\n      --deg[e];\n    }\n \
    \ }\n  if (edge_num == 0) [[unlikely]] return {};\n  const int not0 = n - std::count(deg.begin(),\
    \ deg.end(), 0);\n  if (not0 == 0) {\n    if (s == -1) {\n      s = std::distance(\n\
    \          graph.begin(),\n          std::find_if_not(\n              graph.begin(),\
    \ graph.end(),\n              [](const std::vector<Edge<CostType>>& edges) ->\
    \ bool {\n                return edges.empty();\n              }));\n    }\n \
    \ } else if (not0 == 2) {\n    bool t_exists = false;\n    for (int i = 0; i <\
    \ n; ++i) {\n      if (deg[i] == 0) continue;\n      if (deg[i] == 1) {\n    \
    \    if (s == -1) s = i;\n        if (s != i) return {};\n      } else if (deg[i]\
    \ == -1) {\n        if (t_exists) return {};\n        t_exists = true;\n     \
    \ } else {\n        return {};\n      }\n    }\n  } else {\n    return {};\n \
    \ }\n  std::vector<Edge<CostType>> res;\n  const auto dfs = [&graph, &res](auto\
    \ dfs, const int ver) -> void {\n    while (!graph[ver].empty()) {\n      const\
    \ Edge<CostType> e = graph[ver].back();\n      graph[ver].pop_back();\n      dfs(dfs,\
    \ e.dst);\n      res.emplace_back(e);\n    }\n  };\n  dfs(dfs, s);\n  if (std::cmp_equal(res.size(),\
    \ edge_num)) {\n    std::reverse(res.begin(), res.end());\n    return res;\n \
    \ }\n  return {};\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_\n#define EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_\n\
    \n#include <algorithm>\n#include <iterator>\n#include <ranges>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename CostType>\nstd::vector<Edge<CostType>> eulerian_trail_in_directed_graph(\n\
    \    std::vector<std::vector<Edge<CostType>>> graph, int s = -1) {\n  const int\
    \ n = graph.size();\n  int edge_num = 0;\n  std::vector<int> deg(n, 0);\n  for\
    \ (int i = 0; i < n; ++i) {\n    edge_num += graph[i].size();\n    deg[i] += graph[i].size();\n\
    \    for (const int e : graph[i] | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      --deg[e];\n    }\n  }\n  if (edge_num == 0) [[unlikely]] return {};\n\
    \  const int not0 = n - std::count(deg.begin(), deg.end(), 0);\n  if (not0 ==\
    \ 0) {\n    if (s == -1) {\n      s = std::distance(\n          graph.begin(),\n\
    \          std::find_if_not(\n              graph.begin(), graph.end(),\n    \
    \          [](const std::vector<Edge<CostType>>& edges) -> bool {\n          \
    \      return edges.empty();\n              }));\n    }\n  } else if (not0 ==\
    \ 2) {\n    bool t_exists = false;\n    for (int i = 0; i < n; ++i) {\n      if\
    \ (deg[i] == 0) continue;\n      if (deg[i] == 1) {\n        if (s == -1) s =\
    \ i;\n        if (s != i) return {};\n      } else if (deg[i] == -1) {\n     \
    \   if (t_exists) return {};\n        t_exists = true;\n      } else {\n     \
    \   return {};\n      }\n    }\n  } else {\n    return {};\n  }\n  std::vector<Edge<CostType>>\
    \ res;\n  const auto dfs = [&graph, &res](auto dfs, const int ver) -> void {\n\
    \    while (!graph[ver].empty()) {\n      const Edge<CostType> e = graph[ver].back();\n\
    \      graph[ver].pop_back();\n      dfs(dfs, e.dst);\n      res.emplace_back(e);\n\
    \    }\n  };\n  dfs(dfs, s);\n  if (std::cmp_equal(res.size(), edge_num)) {\n\
    \    std::reverse(res.begin(), res.end());\n    return res;\n  }\n  return {};\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/eulerian_trail_in_directed_graph.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/eulerian_trail_in_directed_graph.test.cpp
documentation_of: include/emthrm/graph/eulerian_trail_in_directed_graph.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u8DEF (Eulerian trail) \u6709\u5411\u30B0\u30E9\u30D5\
  \u7248"
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

### Hierholzer's algorithm 有向グラフ版

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<Edge<CostType>> eulerian_trail_in_directed_graph(std::vector<std::vector<Edge<CostType>>> graph, int s = -1);`|有向グラフ $\mathrm{graph}$ における始点 $s$ のオイラー路。ただし存在しないときは空配列を返す。|


### Hierholzer's algorithm 無向グラフ版

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

- Carl Hierholzer: Ueber die Möglichkeit, einen Linienzug ohne Wiederholung und ohne Unterbrechung zu umfahren, *Mathematische Annalen *, Vol. 6, pp. 30–32 (1873). https://doi.org/10.1007/BF01442866
- https://kokiymgch.hatenablog.com/entry/2017/12/07/193238

オイラー路 有向グラフ版
- ~~http://www.prefield.com/algorithm/graph/directed_euler_path.html~~

オイラー路 無向グラフ版
- https://github.com/spaghetti-source/algorithm/blob/2c70d7af4d132513fa699a5de5b2aaf21aaf7890/graph/eulerian_path_undirected.cc


## Submissons

- [オイラー路 有向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0225/review/4082901/emthrm/C++14)
- [オイラー路 無向グラフ版](https://yukicoder.me/submissions/701541)
