---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/tree/centroid_decomposition.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/tree/centroid_decomposition.hpp\"\n\
    \n\n\n#include <ranges>\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 8 \"include/emthrm/graph/tree/centroid_decomposition.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct CentroidDecomposition\
    \ {\n  int root;\n  std::vector<int> parent;\n  std::vector<std::vector<int>>\
    \ g;\n\n  explicit CentroidDecomposition(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : graph(graph) {\n    const int n = graph.size();\n    parent.assign(n,\
    \ -1);\n    g.resize(n);\n    is_alive.assign(n, true);\n    subtree.resize(n);\n\
    \    root = build(0);\n  }\n\n private:\n  std::vector<bool> is_alive;\n  std::vector<int>\
    \ subtree;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  int build(const\
    \ int s) {\n    const int centroid = search_centroid(-1, s, calc_subtree(-1, s)\
    \ / 2);\n    is_alive[centroid] = false;\n    for (const int e : graph[centroid]\n\
    \                     | std::views::transform(&Edge<CostType>::dst)) {\n     \
    \ if (is_alive[e]) {\n        const int child = build(e);\n        g[centroid].emplace_back(child);\n\
    \        parent[child] = centroid;\n      }\n    }\n    is_alive[centroid] = true;\n\
    \    return centroid;\n  }\n\n  int calc_subtree(const int par, const int ver)\
    \ {\n    subtree[ver] = 1;\n    for (const int e : graph[ver]\n              \
    \       | std::views::transform(&Edge<CostType>::dst)) {\n      if (e != par &&\
    \ is_alive[e]) {\n        subtree[ver] += calc_subtree(ver, e);\n      }\n   \
    \ }\n    return subtree[ver];\n  }\n\n  int search_centroid(const int par, const\
    \ int ver, const int half) const {\n    for (const int e : graph[ver]\n      \
    \               | std::views::transform(&Edge<CostType>::dst)) {\n      if (e\
    \ != par && is_alive[e] && subtree[e] > half) {\n        return search_centroid(ver,\
    \ e, half);\n      }\n    }\n    return ver;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_\n#define EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_\n\
    \n#include <ranges>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct CentroidDecomposition\
    \ {\n  int root;\n  std::vector<int> parent;\n  std::vector<std::vector<int>>\
    \ g;\n\n  explicit CentroidDecomposition(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : graph(graph) {\n    const int n = graph.size();\n    parent.assign(n,\
    \ -1);\n    g.resize(n);\n    is_alive.assign(n, true);\n    subtree.resize(n);\n\
    \    root = build(0);\n  }\n\n private:\n  std::vector<bool> is_alive;\n  std::vector<int>\
    \ subtree;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  int build(const\
    \ int s) {\n    const int centroid = search_centroid(-1, s, calc_subtree(-1, s)\
    \ / 2);\n    is_alive[centroid] = false;\n    for (const int e : graph[centroid]\n\
    \                     | std::views::transform(&Edge<CostType>::dst)) {\n     \
    \ if (is_alive[e]) {\n        const int child = build(e);\n        g[centroid].emplace_back(child);\n\
    \        parent[child] = centroid;\n      }\n    }\n    is_alive[centroid] = true;\n\
    \    return centroid;\n  }\n\n  int calc_subtree(const int par, const int ver)\
    \ {\n    subtree[ver] = 1;\n    for (const int e : graph[ver]\n              \
    \       | std::views::transform(&Edge<CostType>::dst)) {\n      if (e != par &&\
    \ is_alive[e]) {\n        subtree[ver] += calc_subtree(ver, e);\n      }\n   \
    \ }\n    return subtree[ver];\n  }\n\n  int search_centroid(const int par, const\
    \ int ver, const int half) const {\n    for (const int e : graph[ver]\n      \
    \               | std::views::transform(&Edge<CostType>::dst)) {\n      if (e\
    \ != par && is_alive[e] && subtree[e] > half) {\n        return search_centroid(ver,\
    \ e, half);\n      }\n    }\n    return ver;\n  }\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2023-02-27 17:26:42+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/tree/centroid_decomposition.test.cpp
documentation_of: include/emthrm/graph/tree/centroid_decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
---

重心を基にした木の分解法の一つである。木上で分割統治法を行うときに有用である。


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 仕様

```cpp
template <typename CostType>
struct CentroidDecomposition;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`int root`|重心分解した木の根|
|`std::vector<int> parent`|`parent[i]` は `g` における頂点 $i$ の親を表す。ただし存在しないときは $-1$ となる。|
|`std::vector<std::vector<int>> g`|重心分解を行った木|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit CentroidDecomposition(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- http://compro.tsutajiro.com/archive/190207_divcon.pdf
- ~~https://lumakernel.github.io/ecasdqina/graph/CentroidDecomposition~~


## TODO

- ~~https://twitter.com/beet_aizu/status/1142651943971540992~~
- $1/3$ 重心分解
  - https://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d
  - https://twitter.com/noshi91/status/1549081194859761664
  - https://twitter.com/NachiaVivias/status/1549184577511788544
  - https://twitter.com/SSRS_cp/status/1640566437734653953
  - https://twitter.com/noshi91/status/1640569780100034560
  - https://twitter.com/noshi91/status/1673744350998851584
  - https://twitter.com/noshi91/status/1683485568737345543
  - https://twitter.com/noshi91/status/1720487757238432233
  - https://twitter.com/noshi91/status/1758542680517476658
  - 問題例 "[Paken Land](https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_o)"
    - https://atcoder.jp/contests/pakencamp-2022-day1/submissions/40109596
  - 問題例 "[Tree Distance 3](https://yukicoder.me/problems/no/2634)"


## Submissons

https://atcoder.jp/contests/abc291/submissions/39252522