---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/noshi_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path/dijkstra.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <cassert>\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 13 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Dijkstra {\n  const\
    \ CostType inf;\n\n  Dijkstra(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n           const CostType inf = std::numeric_limits<CostType>::max())\n\
    \      : inf(inf), is_built(false), graph(graph) {}\n\n  std::vector<CostType>\
    \ build(const int s) {\n    is_built = true;\n    const int n = graph.size();\n\
    \    std::vector<CostType> dist(n, inf);\n    dist[s] = 0;\n    prev.assign(n,\
    \ -1);\n    std::priority_queue<std::pair<CostType, int>,\n                  \
    \      std::vector<std::pair<CostType, int>>,\n                        std::greater<std::pair<CostType,\
    \ int>>> que;\n    que.emplace(0, s);\n    while (!que.empty()) {\n      const\
    \ auto [d, ver] = que.top();\n      que.pop();\n      if (d > dist[ver]) continue;\n\
    \      for (const Edge<CostType>& e : graph[ver]) {\n        if (dist[ver] + e.cost\
    \ < dist[e.dst]) {\n          dist[e.dst] = dist[ver] + e.cost;\n          prev[e.dst]\
    \ = ver;\n          que.emplace(dist[e.dst], e.dst);\n        }\n      }\n   \
    \ }\n    return dist;\n  }\n\n  std::vector<int> build_path(int t) const {\n \
    \   assert(is_built);\n    std::vector<int> res;\n    for (; t != -1; t = prev[t])\
    \ {\n      res.emplace_back(t);\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n  }\n\n private:\n  bool is_built;\n  std::vector<int> prev;\n\
    \  std::vector<std::vector<Edge<CostType>>> graph;\n};\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP_\n#define EMTHRM_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Dijkstra {\n  const\
    \ CostType inf;\n\n  Dijkstra(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n           const CostType inf = std::numeric_limits<CostType>::max())\n\
    \      : inf(inf), is_built(false), graph(graph) {}\n\n  std::vector<CostType>\
    \ build(const int s) {\n    is_built = true;\n    const int n = graph.size();\n\
    \    std::vector<CostType> dist(n, inf);\n    dist[s] = 0;\n    prev.assign(n,\
    \ -1);\n    std::priority_queue<std::pair<CostType, int>,\n                  \
    \      std::vector<std::pair<CostType, int>>,\n                        std::greater<std::pair<CostType,\
    \ int>>> que;\n    que.emplace(0, s);\n    while (!que.empty()) {\n      const\
    \ auto [d, ver] = que.top();\n      que.pop();\n      if (d > dist[ver]) continue;\n\
    \      for (const Edge<CostType>& e : graph[ver]) {\n        if (dist[ver] + e.cost\
    \ < dist[e.dst]) {\n          dist[e.dst] = dist[ver] + e.cost;\n          prev[e.dst]\
    \ = ver;\n          que.emplace(dist[e.dst], e.dst);\n        }\n      }\n   \
    \ }\n    return dist;\n  }\n\n  std::vector<int> build_path(int t) const {\n \
    \   assert(is_built);\n    std::vector<int> res;\n    for (; t != -1; t = prev[t])\
    \ {\n      res.emplace_back(t);\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n  }\n\n private:\n  bool is_built;\n  std::vector<int> prev;\n\
    \  std::vector<std::vector<Edge<CostType>>> graph;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_SHORTEST_PATH_DIJKSTRA_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/shortest_path/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/shortest_path/dijkstra.test.cpp
  - test/graph/noshi_graph.test.cpp
  - test/math/matrix/linear_equation.test.cpp
documentation_of: include/emthrm/graph/shortest_path/dijkstra.hpp
layout: document
title: "Dijkstra \u6CD5"
---

# 単一始点最短路問題 (single-source shortest path problem)

始点から他の任意の頂点までの最短路を求める問題である。


## 時間計算量

|アルゴリズム|時間計算量|
|:--|:--|
|Bellman–Ford 法|$O(\lvert V \rvert \lvert E \rvert)$|
|Dijkstra 法|$O(\lvert E \rvert \log{\lvert V \rvert})$|


## 仕様

### Bellman–Ford 法

```cpp
template <typename CostType>
struct BellmanFord;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const CostType inf`|$\infty$|
|`std::vector<CostType> dist`|`dist[ver]` は始点から頂点 $\mathrm{ver}$ までの最短距離を表す。ただし到達できないときは $\infty$ となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`BellmanFord(const std::vector<std::vector<Edge<CostType>>>& graph, const CostType inf = std::numeric_limits<CostType>::max());`|グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`bool has_negative_cycle(const int s);`|始点 $s$ の単一始点最短路を構築し、グラフが負の閉路をもつかを返す。|
|`std::vector<int> build_path(int t) const;`|終点 $t$ の最短路。ただし到達できないときは空配列を返す。|


### Dijkstra 法

```cpp
template <typename CostType>
struct Dijkstra
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const CostType inf`|$\infty$|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`Dijkstra(const std::vector<std::vector<Edge<CostType>>>& graph, const CostType inf = std::numeric_limits<CostType>::max());`|グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`std::vector<CostType> build(const int s);`|始点 $s$ の単一始点最短路。ただし到達できない頂点には $\infty$ を格納する。|
|`std::vector<int> build_path(int t) const;`|終点 $t$ の最短路。ただし到達できないときは空配列を返す。|


## 参考文献

Bellman–Ford 法
- Richard Bellman: On a routing problem, *Quarterly of Applied Mathematics*, Vol. 16, pp. 87–90 (1958). https://doi.org/10.1090/qam/102435
- L. R. Ford Jr. and D. R. Fulkerson: Flows in Networks, Princeton University Press (1962).
- ~~http://www.prefield.com/algorithm/graph/bellman_ford.html~~

Dijkstra 法
- Edsger W. Dijkstra: A note on two problems in connexion with graphs, *Numerische Mathematik*, Vol. 1, pp. 269–271 (1959). https://doi.org/10.1007/BF01386390
- https://github.com/spaghetti-source/algorithm/blob/af9a22a92953e903c474e98e79107103adbd0a53/graph/dijkstra.cc


## TODO

- shortest path faster algorithm
  - https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
  - https://noshi91.github.io/algorithm-encyclopedia/spfa
  - http://hogloid.hatenablog.com/entry/20120409/1333973448
  - https://ei1333.github.io/algorithm/shortest-path-faster-algorithm.html
  - https://ei1333.github.io/luzhiled/snippets/graph/shortest-path-faster-algorithm.html
  - https://tubo28.me/compprog/algorithm/spfa/
  - https://tjkendev.github.io/procon-library/python/graph/spfa.html
  - https://hamukichi.hatenablog.jp/entry/2016/03/03/191304
- Dijkstra 法の高速化
  - https://www.slideshare.net/yosupo/ss-46612984
  - skew heap
    - https://github.com/primenumber/ProconLib/blob/master/Structure/SkewHeapDijkstra.cpps
  - Fibonacchi heap
    - https://github.com/ei1333/library/blob/master/graph/dijkstra-fibonacchi-heap.cpp
  - radix heap
    - https://github.com/ei1333/library/blob/master/graph/dijkstra-radix-heap.cpp
- 双方向 Dijkstra
  - http://tatanaideyo.hatenablog.com/entry/2015/11/01/031713
  - https://tubo28.me/compprog/algorithm/bidirectional-dijkstra/
  - https://togetter.com/li/893481
- k shortest path routing (Yen's algorithm)
  - https://en.wikipedia.org/wiki/K_shortest_path_routing
  - https://en.wikipedia.org/wiki/Yen%27s_algorithm
  - https://noshi91.github.io/algorithm-encyclopedia/yen-algorithm
  - http://inarizuuuushi.hatenablog.com/entry/2018/08/30/222605
  - https://mugen1337.github.io/procon/Graph2/Yen.cpp
  - https://yukicoder.me/problems/no/1069
- k shortest walk (Eppstein's algorithm)
  - https://en.wikipedia.org/wiki/K_shortest_path_routing#Variations
  - https://noshi91.github.io/algorithm-encyclopedia/eppstein-algorithm
  - https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e
  - https://qiita.com/nariaki3551/items/0ab83541814f98eab322
  - ~~http://www.prefield.com/algorithm/graph/k_shortest_paths.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/k_shortest_walks.cc
  - https://mugen1337.github.io/procon/Graph2/Eppstein.cpp
  - https://judge.yosupo.jp/problem/k_shortest_walk
- $O(\sqrt{N}M\log{C})$
  - https://misawa.github.io/others/flow/cost_scaling_shortest_path.html
- Dial's algorithm
  - https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Specialized_variants
  - https://noshi91.github.io/algorithm-encyclopedia/dial
  - http://bin.t.u-tokyo.ac.jp/startup16/file/6-1.pdf
  - https://tjkendev.github.io/procon-library/python/graph/dial.html
- shortest non-zero path in group-labeled graphs
  - https://ygussany.hatenablog.com/entry/2019/12/04/000000
  - https://gist.github.com/wata-orz/d3037bd0b919c76dd9ddc0379e1e3192
  - https://yukicoder.me/problems/no/1602


## Submissons

- [Bellman–Ford 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_1_B/review/4082583/emthrm/C++14)
- [Dijkstra 法](https://judge.yosupo.jp/submission/8211)
