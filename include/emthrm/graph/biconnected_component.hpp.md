---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/biconnected_component.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
      \u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/biconnected_component.hpp\"\n\n\n\n\
    // #include <algorithm>\n#include <set>\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/lowlink.hpp\"\n\n\n\n#include <algorithm>\n#line\
    \ 6 \"include/emthrm/graph/lowlink.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/lowlink.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Lowlink {\n  std::vector<int>\
    \ order, lowlink, articulation_points;\n  std::vector<Edge<CostType>> bridges;\n\
    \  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  explicit Lowlink(const\
    \ std::vector<std::vector<Edge<CostType>>>& graph)\n      : graph(graph) {\n \
    \   const int n = graph.size();\n    order.assign(n, -1);\n    lowlink.resize(n);\n\
    \    int t = 0;\n    for (int i = 0; i < n; ++i) {\n      if (order[i] == -1)\
    \ dfs(-1, i, &t);\n    }\n  }\n\n private:\n  void dfs(const int par, const int\
    \ ver, int* t) {\n    order[ver] = lowlink[ver] = (*t)++;\n    int num = 0;\n\
    \    bool is_articulation_point = false;\n    for (const Edge<CostType>& e : graph[ver])\
    \ {\n      if (order[e.dst] == -1) {\n        ++num;\n        dfs(ver, e.dst,\
    \ t);\n        lowlink[ver] = std::min(lowlink[ver], lowlink[e.dst]);\n      \
    \  if (order[ver] <= lowlink[e.dst]) {\n          is_articulation_point = true;\n\
    \          if (order[ver] < lowlink[e.dst]) {\n            bridges.emplace_back(std::min(ver,\
    \ e.dst), std::max(ver, e.dst),\n                                 e.cost);\n \
    \         }\n        }\n      } else if (e.dst != par) {\n        lowlink[ver]\
    \ = std::min(lowlink[ver], order[e.dst]);\n      }\n    }\n    if ((par == -1\
    \ && num >= 2) || (par != -1 && is_articulation_point)) {\n      articulation_points.emplace_back(ver);\n\
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 11 \"include/emthrm/graph/biconnected_component.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\n\
    struct BiconnectedComponent : Lowlink<CostType> {\n  std::vector<int> id;\n  std::vector<std::vector<int>>\
    \ vertices, cutpoint;\n  std::vector<std::vector<Edge<CostType>>> block;\n\n \
    \ explicit BiconnectedComponent(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : Lowlink<CostType>(graph) {\n    const int n = graph.size();\n\
    \    id.assign(n, -2);\n    if constexpr (IS_FULL_VER) {\n      cutpoint.resize(n);\n\
    \      is_articulation_point.assign(n, false);\n      for (const int articulation_point\
    \ : this->articulation_points) {\n        is_articulation_point[articulation_point]\
    \ = true;\n      }\n    }\n    for (int i = 0; i < n; ++i) {\n      if (id[i]\
    \ == -2) dfs(-1, i);\n    }\n    // const int m = vertices.size();\n    // for\
    \ (int i = 0; i < m; ++i) {\n    //   std::sort(block[i].begin(), block[i].end());\n\
    \    // }\n    // if constexpr (IS_FULL_VER) {\n    //   for (int i = 0; i < m;\
    \ ++i) {\n    //     std::sort(vertices[i].begin(), vertices[i].end());\n    //\
    \   }\n    //   for (int i = 0; i < n; ++i) {\n    //     std::sort(cutpoint[i].begin(),\
    \ cutpoint[i].end());\n    //   }\n    // }\n  }\n\n private:\n  std::vector<bool>\
    \ is_articulation_point;\n  std::vector<Edge<CostType>> tmp;\n\n  void dfs(const\
    \ int par, const int ver) {\n    id[ver] = -1;\n    for (const Edge<CostType>&\
    \ e : this->graph[ver]) {\n      if (e.dst == par) continue;\n      int src =\
    \ ver, dst = e.dst;\n      if (src > dst) std::swap(src, dst);\n      if (id[e.dst]\
    \ == -2 || this->order[e.dst] < this->order[ver]) {\n        tmp.emplace_back(src,\
    \ dst, e.cost);\n      }\n      if (id[e.dst] == -2) {\n        dfs(ver, e.dst);\n\
    \        if (this->lowlink[e.dst] >= this->order[ver]) {\n          const int\
    \ idx = block.size();\n          block.emplace_back();\n          std::set<int>\
    \ st;\n          while (true) {\n            const Edge<CostType> edge = tmp.back();\n\
    \            tmp.pop_back();\n            block.back().emplace_back(edge);\n \
    \           if constexpr (IS_FULL_VER) {\n              st.emplace(edge.src);\n\
    \              st.emplace(edge.dst);\n            }\n            if (edge.src\
    \ == src && edge.dst == dst) break;\n          }\n          if constexpr (IS_FULL_VER)\
    \ {\n            vertices.emplace_back();\n            for (const int el : st)\
    \ {\n              vertices.back().emplace_back(el);\n              if (is_articulation_point[el])\
    \ {\n                cutpoint[el].emplace_back(idx);\n              } else {\n\
    \                id[el] = idx;\n              }\n            }\n          }\n\
    \        }\n      }\n    }\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_BICONNECTED_COMPONENT_HPP_\n#define EMTHRM_GRAPH_BICONNECTED_COMPONENT_HPP_\n\
    \n// #include <algorithm>\n#include <set>\n#include <utility>\n#include <vector>\n\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/lowlink.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <typename CostType, bool IS_FULL_VER = false>\n\
    struct BiconnectedComponent : Lowlink<CostType> {\n  std::vector<int> id;\n  std::vector<std::vector<int>>\
    \ vertices, cutpoint;\n  std::vector<std::vector<Edge<CostType>>> block;\n\n \
    \ explicit BiconnectedComponent(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : Lowlink<CostType>(graph) {\n    const int n = graph.size();\n\
    \    id.assign(n, -2);\n    if constexpr (IS_FULL_VER) {\n      cutpoint.resize(n);\n\
    \      is_articulation_point.assign(n, false);\n      for (const int articulation_point\
    \ : this->articulation_points) {\n        is_articulation_point[articulation_point]\
    \ = true;\n      }\n    }\n    for (int i = 0; i < n; ++i) {\n      if (id[i]\
    \ == -2) dfs(-1, i);\n    }\n    // const int m = vertices.size();\n    // for\
    \ (int i = 0; i < m; ++i) {\n    //   std::sort(block[i].begin(), block[i].end());\n\
    \    // }\n    // if constexpr (IS_FULL_VER) {\n    //   for (int i = 0; i < m;\
    \ ++i) {\n    //     std::sort(vertices[i].begin(), vertices[i].end());\n    //\
    \   }\n    //   for (int i = 0; i < n; ++i) {\n    //     std::sort(cutpoint[i].begin(),\
    \ cutpoint[i].end());\n    //   }\n    // }\n  }\n\n private:\n  std::vector<bool>\
    \ is_articulation_point;\n  std::vector<Edge<CostType>> tmp;\n\n  void dfs(const\
    \ int par, const int ver) {\n    id[ver] = -1;\n    for (const Edge<CostType>&\
    \ e : this->graph[ver]) {\n      if (e.dst == par) continue;\n      int src =\
    \ ver, dst = e.dst;\n      if (src > dst) std::swap(src, dst);\n      if (id[e.dst]\
    \ == -2 || this->order[e.dst] < this->order[ver]) {\n        tmp.emplace_back(src,\
    \ dst, e.cost);\n      }\n      if (id[e.dst] == -2) {\n        dfs(ver, e.dst);\n\
    \        if (this->lowlink[e.dst] >= this->order[ver]) {\n          const int\
    \ idx = block.size();\n          block.emplace_back();\n          std::set<int>\
    \ st;\n          while (true) {\n            const Edge<CostType> edge = tmp.back();\n\
    \            tmp.pop_back();\n            block.back().emplace_back(edge);\n \
    \           if constexpr (IS_FULL_VER) {\n              st.emplace(edge.src);\n\
    \              st.emplace(edge.dst);\n            }\n            if (edge.src\
    \ == src && edge.dst == dst) break;\n          }\n          if constexpr (IS_FULL_VER)\
    \ {\n            vertices.emplace_back();\n            for (const int el : st)\
    \ {\n              vertices.back().emplace_back(el);\n              if (is_articulation_point[el])\
    \ {\n                cutpoint[el].emplace_back(idx);\n              } else {\n\
    \                id[el] = idx;\n              }\n            }\n          }\n\
    \        }\n      }\n    }\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_BICONNECTED_COMPONENT_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/lowlink.hpp
  isVerificationFile: false
  path: include/emthrm/graph/biconnected_component.hpp
  requiredBy: []
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/biconnected_component.test.cpp
documentation_of: include/emthrm/graph/biconnected_component.hpp
layout: document
title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component) \u5206\
  \u89E3"
---

無向グラフを関節点の存在しない辺集合に分割することである。

それぞれの成分には、任意の相異なる3点を始点・経由点・終点とする単純パスが存在する。


### block-cut tree

二重頂点連結成分を一つの頂点に縮約することで得られる木である。


### カクタスグラフ (cactus)

任意の辺が高々一つの単純閉路に含まれる、すなわち任意の異なる単純閉路が高々一つの共通頂点をもつグラフである。

任意の二重頂点連結成分は橋または単純閉路となる。

e.g. 任意の閉路長が奇数となるグラフ


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$

完全版 $O(\lvert V \rvert \log{\lvert V \rvert} + \lvert E \rvert)$ ?


## 仕様

```cpp
template <typename CostType, bool IS_FULL_VER = false>
struct BiconnectedComponent : Lowlink<CostType>;
```

- `CostType`：辺のコストを表す型
- `IS_FULL_VER`：完全版かを表す変数

#### メンバ変数

|名前|説明|要件|
|:--|:--|:--|
|`std::vector<int> id`|`id[i]` は元のグラフの頂点 $i$ を含むブロックを表す。ただし関節点のときは $-1$ である。|完全版|
|`std::vector<std::vector<int>> vertices`|`vertices[i]` は縮約後のグラフのブロック $i$ に含まれる頂点を表す。|完全版|
|`std::vector<std::vector<int>> cutpoint`|`cutpoint[i]` は元のグラフの関節点 $i$ を含むブロックを表す。|完全版|
|`std::vector<std::vector<Edge<CostType>>> block`|`block[i]` は縮約後のグラフのブロック $i$ に含まれる辺を表す。||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit BiconnectedComponent(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- John Hopcroft and Robert Tarjan: Algorithm 447: efficient algorithms for graph manipulation, *Communications of the ACM*, Vol. 16, No. 6, pp. 372–378 (1973). https://doi.org/10.1145/362248.362272
- ~~https://www.learning-algorithms.com/entry/2018/03/21/152148~~
- https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
- https://codeforces.com/blog/entry/14832

カクタスグラフ
- https://pekempey.hatenablog.com/entry/2017/03/28/203856


## TODO

- https://judge.yosupo.jp/problem/biconnected_components


## Submissons

https://atcoder.jp/contests/nadafes2022_day2/submissions/31595927
