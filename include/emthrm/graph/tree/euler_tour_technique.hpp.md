---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (lowest common ancestor) Euler tour\
      \ technique \u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 Euler tour\
      \ technique \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/tree/euler_tour_technique.hpp\"\n\n\
    \n\n#include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title\
    \ \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 7 \"include/emthrm/graph/tree/euler_tour_technique.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct EulerTourTechnique\
    \ {\n  std::vector<int> preorder, depth, left, right, down, up;\n  std::vector<CostType>\
    \ tour;\n\n  explicit EulerTourTechnique(\n      const std::vector<std::vector<Edge<CostType>>>\
    \ &graph, const int root = 0)\n      : graph(graph) {\n    const int n = graph.size();\n\
    \    left.resize(n);\n    right.resize(n);\n    down.assign(n, -1);\n    up.assign(n,\
    \ (n - 1) << 1);\n    dfs(-1, root, 0);\n  }\n\n  template <typename Fn>\n  void\
    \ update_v(const int ver, const Fn f) const {\n    f(left[ver], right[ver] + 1);\n\
    \  }\n\n  template <typename T, typename Fn>\n  T query_v(const int ver, const\
    \ Fn f) const {\n    return f(left[ver], right[ver] + 1);\n  }\n\n  template <typename\
    \ T, typename Fn>\n  T query_e(const int u, const int v, const Fn f) const {\n\
    \    return f(down[u] + 1, down[v] + 1);\n  }\n\n  template <typename Fn>\n  void\
    \ update_subtree_e(const int ver, const Fn f) const {\n    f(down[ver] + 1, up[ver]);\n\
    \  }\n\n  template <typename T, typename Fn>\n  T query_subtree_e(const int ver,\
    \ const Fn f) const {\n    return f(down[ver] + 1, up[ver]);\n  }\n\n private:\n\
    \  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  void dfs(const int\
    \ par, const int ver, const int cur_depth) {\n    left[ver] = preorder.size();\n\
    \    preorder.emplace_back(ver);\n    depth.emplace_back(cur_depth);\n    for\
    \ (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst != par) {\n      \
    \  down[e.dst] = tour.size();\n        tour.emplace_back(e.cost);\n        dfs(ver,\
    \ e.dst, cur_depth + 1);\n        preorder.emplace_back(ver);\n        depth.emplace_back(cur_depth);\n\
    \        up[e.dst] = tour.size();\n        tour.emplace_back(-e.cost);\n     \
    \ }\n    }\n    right[ver] = preorder.size() - 1;\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_TREE_EULER_TOUR_TECHNIQUE_HPP_\n#define EMTHRM_GRAPH_TREE_EULER_TOUR_TECHNIQUE_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nstruct EulerTourTechnique {\n  std::vector<int>\
    \ preorder, depth, left, right, down, up;\n  std::vector<CostType> tour;\n\n \
    \ explicit EulerTourTechnique(\n      const std::vector<std::vector<Edge<CostType>>>\
    \ &graph, const int root = 0)\n      : graph(graph) {\n    const int n = graph.size();\n\
    \    left.resize(n);\n    right.resize(n);\n    down.assign(n, -1);\n    up.assign(n,\
    \ (n - 1) << 1);\n    dfs(-1, root, 0);\n  }\n\n  template <typename Fn>\n  void\
    \ update_v(const int ver, const Fn f) const {\n    f(left[ver], right[ver] + 1);\n\
    \  }\n\n  template <typename T, typename Fn>\n  T query_v(const int ver, const\
    \ Fn f) const {\n    return f(left[ver], right[ver] + 1);\n  }\n\n  template <typename\
    \ T, typename Fn>\n  T query_e(const int u, const int v, const Fn f) const {\n\
    \    return f(down[u] + 1, down[v] + 1);\n  }\n\n  template <typename Fn>\n  void\
    \ update_subtree_e(const int ver, const Fn f) const {\n    f(down[ver] + 1, up[ver]);\n\
    \  }\n\n  template <typename T, typename Fn>\n  T query_subtree_e(const int ver,\
    \ const Fn f) const {\n    return f(down[ver] + 1, up[ver]);\n  }\n\n private:\n\
    \  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  void dfs(const int\
    \ par, const int ver, const int cur_depth) {\n    left[ver] = preorder.size();\n\
    \    preorder.emplace_back(ver);\n    depth.emplace_back(cur_depth);\n    for\
    \ (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst != par) {\n      \
    \  down[e.dst] = tour.size();\n        tour.emplace_back(e.cost);\n        dfs(ver,\
    \ e.dst, cur_depth + 1);\n        preorder.emplace_back(ver);\n        depth.emplace_back(cur_depth);\n\
    \        up[e.dst] = tour.size();\n        tour.emplace_back(-e.cost);\n     \
    \ }\n    }\n    right[ver] = preorder.size() - 1;\n  }\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_TREE_EULER_TOUR_TECHNIQUE_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/euler_tour_technique.hpp
  requiredBy:
  - include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
documentation_of: include/emthrm/graph/tree/euler_tour_technique.hpp
layout: document
title: Euler tour technique
---

根付き木を列として表現するデータ構造である。


## 時間計算量

$O(\lvert V \rvert)$


## 仕様

```cpp
template <typename CostType>
struct EulerTourTechnique;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> preorder`|頂点属性の Euler tour|
|`std::vector<int> depth`|`depth[i]` は頂点 `preorder[i]` の深さを表す。|
|`std::vector<int> left`|`left[i]` は `preorder` に頂点 $i$ が現れるインデックスの最小値を表す。|
|`std::vector<int> right`|`right[i]` は `preorder` に頂点 $i$ が現れるインデックスの最大値を表す。|
|`std::vector<int> down`|`down[i]` は `tour` に頂点 $i$ へ下る辺が現れるインデックスを表す。|
|`std::vector<int> up`|`up[i]` は `tour` に頂点 $i$ から上る辺が現れるインデックスを表す。|
|`std::vector<CostType> tour`|Euler tour|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit EulerTourTechnique(const std::vector<std::vector<Edge<CostType>>> &graph, const int root = 0);`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`template <typename Fn>`<br>`void update_v(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の頂点に対して $f$ を基に更新する。|
|`template <typename T, typename Fn>`<br>`T query_v(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の頂点に対する $f$ を基にしたクエリの解|
|`template <typename T, typename Fn>`<br>`T query_e(const int u, const int v, const Fn f) const;`|頂点 $u$ から $v$ へ下る辺に対する $f$ を基にしたクエリの解|
|`template <typename Fn>`<br>`void update_subtree_e(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する。|
|`template <typename T, typename Fn>`<br>`T query_subtree_e(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の辺に対する $f$ を基にしたクエリの解|


## 参考文献

- Robert E. Tarjan and Uzi Vishkin: Finding biconnected componemts and computing tree functions in logarithmic parallel time, *25th Annual Symposium on Foundations of Computer Science, 1984.*, pp. 12–20 (1984). https://doi.org/10.1109/SFCS.1984.715896
- ~~http://beet-aizu.hatenablog.com/entry/2019/07/08/174727~~
- https://twitter.com/3SAT_IS_IN_P/status/1296040678820990982
- https://github.com/spaghetti-source/algorithm/blob/41bc0bbb1767692eb9bdeeceb332b2b8cc17329a/graph/least_common_ancestor_sparsetable.cc


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14
