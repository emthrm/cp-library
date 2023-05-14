---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/unicyclic_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/unicyclic graph"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/unicyclic_graph.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <iterator>\n#include <queue>\n#include <vector>\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/unicyclic_graph.hpp\"\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct UnicyclicGraph {\n  std::vector<bool> is_in_loop;\n\
    \  std::vector<int> belong, mapping;\n  std::vector<Edge<CostType>> loop;\n  std::vector<std::vector<int>>\
    \ invs;\n  std::vector<std::vector<std::vector<Edge<CostType>>>> forest;\n\n \
    \ explicit UnicyclicGraph(const int n)\n      : is_in_loop(n, false), belong(n,\
    \ -1), mapping(n, -1), n(n), graph(n) {}\n\n  void add_edge(const int src, const\
    \ int dst, const CostType cost = 0) {\n    const int id = srcs.size();\n    srcs.emplace_back(src);\n\
    \    dsts.emplace_back(dst);\n    costs.emplace_back(cost);\n    graph[src].emplace_back(id);\n\
    \    if (dst != src) [[likely]] graph[dst].emplace_back(id);\n  }\n\n  void build()\
    \ {\n    dfs(-1, 0);\n    std::queue<int> que;\n    for (const Edge<CostType>&\
    \ e : loop) {\n      const int root = e.src, forest_id = forest.size();\n    \
    \  belong[root] = forest_id;\n      mapping[root] = 0;\n      std::vector<int>\
    \ inv{root};\n      std::vector<std::vector<Edge<CostType>>> tree(1);\n      que.emplace(root);\n\
    \      while (!que.empty()) {\n        const int ver = que.front();\n        que.pop();\n\
    \        for (const int id : graph[ver]) {\n          const int dst = destination(id,\
    \ ver);\n          if (belong[dst] == -1 && !is_in_loop[dst]) {\n            const\
    \ int idx = tree.size();\n            belong[dst] = forest_id;\n            mapping[dst]\
    \ = idx;\n            inv.emplace_back(dst);\n            tree[mapping[ver]].emplace_back(mapping[ver],\
    \ idx, costs[id]);\n            tree.emplace_back(std::vector<Edge<CostType>>{\n\
    \                Edge<CostType>(idx, mapping[ver], costs[id])});\n           \
    \ que.emplace(dst);\n          }\n        }\n      }\n      if (inv.size() ==\
    \ 1) {\n        belong[root] = mapping[root] = -1;\n      } else {\n        invs.emplace_back(inv);\n\
    \        forest.emplace_back(tree);\n      }\n    }\n  }\n\n private:\n  const\
    \ int n;\n  std::vector<int> srcs, dsts;\n  std::vector<CostType> costs;\n  std::vector<std::vector<int>>\
    \ graph;\n\n  int destination(const int id, const int s) const {\n    return (srcs[id]\
    \ == s ? dsts : srcs)[id];\n  }\n\n  bool dfs(const int prev_id, const int ver)\
    \ {\n    is_in_loop[ver] = true;\n    for (const int id : graph[ver]) {\n    \
    \  if (id == prev_id) continue;\n      const int dst = destination(id, ver);\n\
    \      loop.emplace_back(ver, dst, costs[id]);\n      if (is_in_loop[dst]) {\n\
    \        for (int i = loop.size() - 1; i >= 0; --i) {\n          if (loop[i].src\
    \ == dst) {\n            for (int j = 0; j < i; ++j) {\n              is_in_loop[loop[j].src]\
    \ = false;\n            }\n            loop.erase(loop.begin(), std::next(loop.begin(),\
    \ i));\n            return true;\n          }\n        }\n        assert(false);\n\
    \      }\n      if (dfs(id, dst)) return true;\n      loop.pop_back();\n    }\n\
    \    is_in_loop[ver] = false;\n    return false;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_GRAPH_UNICYCLIC_GRAPH_HPP_\n#define EMTHRM_GRAPH_UNICYCLIC_GRAPH_HPP_\n\
    \n#include <cassert>\n#include <iterator>\n#include <queue>\n#include <vector>\n\
    \n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ CostType>\nstruct UnicyclicGraph {\n  std::vector<bool> is_in_loop;\n  std::vector<int>\
    \ belong, mapping;\n  std::vector<Edge<CostType>> loop;\n  std::vector<std::vector<int>>\
    \ invs;\n  std::vector<std::vector<std::vector<Edge<CostType>>>> forest;\n\n \
    \ explicit UnicyclicGraph(const int n)\n      : is_in_loop(n, false), belong(n,\
    \ -1), mapping(n, -1), n(n), graph(n) {}\n\n  void add_edge(const int src, const\
    \ int dst, const CostType cost = 0) {\n    const int id = srcs.size();\n    srcs.emplace_back(src);\n\
    \    dsts.emplace_back(dst);\n    costs.emplace_back(cost);\n    graph[src].emplace_back(id);\n\
    \    if (dst != src) [[likely]] graph[dst].emplace_back(id);\n  }\n\n  void build()\
    \ {\n    dfs(-1, 0);\n    std::queue<int> que;\n    for (const Edge<CostType>&\
    \ e : loop) {\n      const int root = e.src, forest_id = forest.size();\n    \
    \  belong[root] = forest_id;\n      mapping[root] = 0;\n      std::vector<int>\
    \ inv{root};\n      std::vector<std::vector<Edge<CostType>>> tree(1);\n      que.emplace(root);\n\
    \      while (!que.empty()) {\n        const int ver = que.front();\n        que.pop();\n\
    \        for (const int id : graph[ver]) {\n          const int dst = destination(id,\
    \ ver);\n          if (belong[dst] == -1 && !is_in_loop[dst]) {\n            const\
    \ int idx = tree.size();\n            belong[dst] = forest_id;\n            mapping[dst]\
    \ = idx;\n            inv.emplace_back(dst);\n            tree[mapping[ver]].emplace_back(mapping[ver],\
    \ idx, costs[id]);\n            tree.emplace_back(std::vector<Edge<CostType>>{\n\
    \                Edge<CostType>(idx, mapping[ver], costs[id])});\n           \
    \ que.emplace(dst);\n          }\n        }\n      }\n      if (inv.size() ==\
    \ 1) {\n        belong[root] = mapping[root] = -1;\n      } else {\n        invs.emplace_back(inv);\n\
    \        forest.emplace_back(tree);\n      }\n    }\n  }\n\n private:\n  const\
    \ int n;\n  std::vector<int> srcs, dsts;\n  std::vector<CostType> costs;\n  std::vector<std::vector<int>>\
    \ graph;\n\n  int destination(const int id, const int s) const {\n    return (srcs[id]\
    \ == s ? dsts : srcs)[id];\n  }\n\n  bool dfs(const int prev_id, const int ver)\
    \ {\n    is_in_loop[ver] = true;\n    for (const int id : graph[ver]) {\n    \
    \  if (id == prev_id) continue;\n      const int dst = destination(id, ver);\n\
    \      loop.emplace_back(ver, dst, costs[id]);\n      if (is_in_loop[dst]) {\n\
    \        for (int i = loop.size() - 1; i >= 0; --i) {\n          if (loop[i].src\
    \ == dst) {\n            for (int j = 0; j < i; ++j) {\n              is_in_loop[loop[j].src]\
    \ = false;\n            }\n            loop.erase(loop.begin(), std::next(loop.begin(),\
    \ i));\n            return true;\n          }\n        }\n        assert(false);\n\
    \      }\n      if (dfs(id, dst)) return true;\n      loop.pop_back();\n    }\n\
    \    is_in_loop[ver] = false;\n    return false;\n  }\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_UNICYCLIC_GRAPH_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/unicyclic_graph.hpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/unicyclic_graph.test.cpp
documentation_of: include/emthrm/graph/unicyclic_graph.hpp
layout: document
title: unicyclic graph / 1-tree
---

閉路をただ一つだけ含む単純連結無向グラフである。俗に[ある漫画家の名前を用いて表現される](https://twitter.com/chokudai/status/772440823170379776)。


## 時間計算量

$O(\lvert V \rvert)$


## 仕様

```cpp
template <typename CostType>
struct UnicyclicGraph;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<bool> is_in_loop`|`is_in_loop[i]` は頂点 $i$ が閉路に含まれるかを表す。|
|`std::vector<int> belong`|`belong[i]` は頂点 $i$ を含む木の番号。ただし存在しないときは $-1$ となる。|
|`std::vector<int> mapping`|`mapping[i]` は頂点 $i$ に対応する木の頂点番号。ただし存在しないときは $-1$ となる。|
|`std::vector<Edge<CostType>> loop`|閉路|
|`std::vector<std::vector<int>> invs`|`invs[i][j]` は木 $i$ の頂点 $j$ に対応する元のグラフの頂点番号を表す。|
|`std::vector<std::vector<std::vector<Edge<CostType>>>> forest`|閉路を除いた森|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit UnicyclicGraph(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const CostType cost = 0);`|コスト $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を加える。|
|`void build();`|構築する。|


## 参考文献

- "Harold N. Gabow and Robert E. Tarjan: A linear-time algorithm for finding a minimum spanning pseudoforest, *Information Processing Letters*, Vol. 27, No. 5, pp. 259–263 (1988). https://doi.org/10.1016/0020-0190(88)90089-0" の Introduction
- https://en.wikipedia.org/wiki/Pseudoforest


## Submissons

https://yukicoder.me/submissions/649654
