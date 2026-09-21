---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/tree/euler_tour_technique.hpp
    title: Euler tour technique
  _extendedRequiredBy:
  - icon: ':question:'
    path: include/emthrm/graph/tree/auxiliary_tree.hpp
    title: "\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\u3061\u306E\u6700\u5C0F\
      \u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\u3066\u6728\u3092\u5727\
      \u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\u306A\u6728"
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/graph/tree/auxiliary_tree.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6307\u5B9A\u3055\u308C\u305F\u9802\u70B9\u305F\
      \u3061\u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\u95A2\u4FC2\u3092\u4FDD\u3063\
      \u3066\u6728\u3092\u5727\u7E2E\u3057\u3066\u3067\u304D\u308B\u88DC\u52A9\u7684\
      \u306A\u6728"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 Euler tour\
      \ technique \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <utility>\n#include <vector>\n\n#line 1\
    \ \"include/emthrm/data_structure/sparse_table.hpp\"\n\n\n\n#line 5 \"include/emthrm/data_structure/sparse_table.hpp\"\
    \n#include <bit>\n#include <cassert>\n#include <functional>\n#line 9 \"include/emthrm/data_structure/sparse_table.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Band>\nstruct SparseTable {\n  using\
    \ BinOp = std::function<Band(Band, Band)>;\n\n  SparseTable() = default;\n\n \
    \ explicit SparseTable(const std::vector<Band>& a, const BinOp bin_op) {\n   \
    \ init(a, bin_op);\n  }\n\n  void init(const std::vector<Band>& a, const BinOp\
    \ bin_op_) {\n    bin_op = bin_op_;\n    const int n = a.size();\n    assert(n\
    \ > 0);\n    lg.assign(n + 1, 0);\n    for (int i = 2; i <= n; ++i) {\n      lg[i]\
    \ = lg[i >> 1] + 1;\n    }\n    const int table_h = std::countr_zero(std::bit_floor(a.size()))\
    \ + 1;\n    data.assign(table_h, std::vector<Band>(n));\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\n    for (int i = 1; i < table_h; ++i) {\n \
    \     for (int j = 0; j + (1 << i) <= n; ++j) {\n        data[i][j] = bin_op(data[i\
    \ - 1][j], data[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\n  Band query(const\
    \ int left, const int right) const {\n    assert(left < right);\n    const int\
    \ h = lg[right - left];\n    return bin_op(data[h][left], data[h][right - (1 <<\
    \ h)]);\n  }\n\n private:\n  BinOp bin_op;\n  std::vector<int> lg;\n  std::vector<std::vector<Band>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/euler_tour_technique.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/graph/tree/euler_tour_technique.hpp\"\n\n#line\
    \ 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 7 \"include/emthrm/graph/tree/euler_tour_technique.hpp\"\n\nnamespace emthrm\
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
    \ emthrm\n\n\n#line 11 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct LowestCommonAncestor\
    \ : EulerTourTechnique<CostType> {\n  explicit LowestCommonAncestor(\n      const\
    \ std::vector<std::vector<Edge<CostType>>>& graph,\n      const int root = 0)\n\
    \      : EulerTourTechnique<CostType>(graph, root) {\n    const int n = this->preorder.size();\n\
    \    std::vector<std::pair<int, int>> nodes(n);\n    for (int i = 0; i < n; ++i)\
    \ {\n      nodes[i] = {this->depth[i], this->preorder[i]};\n    }\n    sparse_table.init(\n\
    \        nodes,\n        [](const std::pair<int, int>& a, const std::pair<int,\
    \ int>& b)\n            -> std::pair<int, int> {\n          return std::min(a,\
    \ b);\n        });\n  }\n\n  int query(int u, int v) const {\n    u = this->left[u];\n\
    \    v = this->left[v];\n    if (u > v) std::swap(u, v);\n    return sparse_table.query(u,\
    \ v + 1).second;\n  }\n\n private:\n  SparseTable<std::pair<int, int>> sparse_table;\n\
    };\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_TECHNIQUE_HPP_\n\
    #define EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_TECHNIQUE_HPP_\n\
    \n#include <algorithm>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/data_structure/sparse_table.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/euler_tour_technique.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct LowestCommonAncestor\
    \ : EulerTourTechnique<CostType> {\n  explicit LowestCommonAncestor(\n      const\
    \ std::vector<std::vector<Edge<CostType>>>& graph,\n      const int root = 0)\n\
    \      : EulerTourTechnique<CostType>(graph, root) {\n    const int n = this->preorder.size();\n\
    \    std::vector<std::pair<int, int>> nodes(n);\n    for (int i = 0; i < n; ++i)\
    \ {\n      nodes[i] = {this->depth[i], this->preorder[i]};\n    }\n    sparse_table.init(\n\
    \        nodes,\n        [](const std::pair<int, int>& a, const std::pair<int,\
    \ int>& b)\n            -> std::pair<int, int> {\n          return std::min(a,\
    \ b);\n        });\n  }\n\n  int query(int u, int v) const {\n    u = this->left[u];\n\
    \    v = this->left[v];\n    if (u > v) std::swap(u, v);\n    return sparse_table.query(u,\
    \ v + 1).second;\n  }\n\n private:\n  SparseTable<std::pair<int, int>> sparse_table;\n\
    };\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_TREE_LOWEST_COMMON_ANCESTOR_BY_EULER_TOUR_TECHNIQUE_HPP_\n"
  dependsOn:
  - include/emthrm/data_structure/sparse_table.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/euler_tour_technique.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp
  requiredBy:
  - include/emthrm/graph/tree/auxiliary_tree.hpp
  timestamp: '2023-05-12 15:57:02+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/graph/tree/auxiliary_tree.test.cpp
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
documentation_of: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp
layout: document
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (lowest common ancestor) Euler tour technique\
  \ \u7248"
---

# 最小共通祖先 (lowest common ancestor)

根付き木のある2頂点に対して最も深い共通祖先である。


## 時間計算量

||時間計算量|
|:--|:--|
|ダブリング版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\log{\lvert V \rvert}) \rangle$|
|Euler tour technique 版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(1) \rangle$|


## 仕様

### ダブリング版

```cpp
template <typename CostType>
struct LowestCommonAncestorByDoubling;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|備考|
|:--|:--|:--|
|`std::vector<int> depth`|`depth[i]` は頂点 $i$ の深さを表す。||
|`std::vector<CostType> dist`|`dist[i]` は根と頂点 $i$ の間の距離を表す。|cost-free 版は `depth` に同じである。|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit LowestCommonAncestorByDoubling(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ に対してオブジェクトを構築する。||
|`void build(const int root = 0);`|根を $\mathrm{root}$ として構築する。||
|`int query(int u, int v) const;`|頂点 $u, v$ の最小共通祖先||
|`CostType distance(const int u, const int v) const;`|頂点 $u, v$ 間の距離||
|`int level_ancestor(int v, const int d) const;`|level ancestor problem $\mathrm{LA}(v, d)$。ただし $d \leq \mathrm{depth}(v)$ でなければ $-1$ を返す。||
|`int jump(const int u, const int v, const int d) const;`|頂点 $u$ から頂点 $v$ まで距離 $d$ だけ進んだときの頂点。ただし $d > \mathrm{dist}(u, v)$ を満たすときは $-1$ を返す。|cost-free 版|


### [Euler tour technique](euler_tour_technique.md)版

```cpp
template <typename CostType>
struct LowestCommonAncestor : EulerTourTechnique<CostType>;
```

- `CostType`：辺のコストを表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit LowestCommonAncestor(const std::vector<std::vector<Edge<CostType>>>& graph, const int root = 0);`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`int query(int u, int v) const;`|頂点 $u, v$ の最小共通祖先|


### [heavy-light decomposition 版](heavy-light_decomposition.md)


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.292-295，マイナビ出版（2012）
- https://yukicoder.me/wiki/lowest_common_ancestor

level ancestor problem
- https://en.wikipedia.org/wiki/Level_ancestor_problem

Euler tour technique 版
- Omer Berkman and Uzi Vishkin: Recursive Star-Tree Parallel Data Structure, *SIAM Journal on Computing*, Vol. 22, No. 2, pp. 221–242 (1993). https://doi.org/10.1137/0222017
- https://github.com/drken1215/algorithm/blob/efb8cf052b095e49e70135a6fb628308d06f49b2/DataStructureOnTree/euler_tour_on_nodes.cpp


## TODO

- Tarjan's off-line lowest common ancestors algorithm
  - ~~http://www.prefield.com/algorithm/graph/least_common_ancestor.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/least_common_ancestor_tarjan.cc
  - http://monyone.github.io/teihen_library/#OfflineLCA
- level ancestor problem $\langle O(\lvert V \rvert), O(1) \rangle$
  - https://www2.compute.dtu.dk/courses/02282/2018/levelancestor/levelancestor1x1.pdf
  - https://37zigen.com/level-ancestor-problem/
  - https://hdbn.hatenadiary.org/entry/20111125/1322194487
  - https://drive.google.com/drive/folders/1atQRO6Y9bHgLDH-YLq3obDwMxIuk7--h
  - https://noshi91.hatenablog.com/entry/2019/09/22/114149
  - https://suisen-kyopro.hatenablog.com/entry/2022/04/04/043452
  - https://twitter.com/GauravML/status/1415073033522319367
  - https://twitter.com/keijak/status/1510953079872663555
  - https://github.com/noshi91/n91lib_rs/blob/c9bd9cf36cbf4637884a049a4fe44f45b06ff71f/src/data_structure/level_ancestor.rs


## Submissons

- [ダブリング版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4084783/emthrm/C++14)
  - [level ancestor problem](https://judge.yosupo.jp/submission/122542)
- [Euler tour technique 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14)
- [heavy-light decomposition 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)
