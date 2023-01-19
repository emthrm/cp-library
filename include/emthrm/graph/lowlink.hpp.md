---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':x:'
    path: include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink \u7248"
  - icon: ':x:'
    path: include/emthrm/graph/biconnected_component.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component)\
      \ \u5206\u89E3"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/2-edge-connected_components_by_lowlink.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ lowlink \u7248"
  - icon: ':x:'
    path: test/graph/biconnected_component.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
      \u89E3"
  - icon: ':heavy_check_mark:'
    path: test/graph/lowlink.1.test.cpp
    title: "\u30B0\u30E9\u30D5/lowlink (\u6A4B)"
  - icon: ':heavy_check_mark:'
    path: test/graph/lowlink.2.test.cpp
    title: "\u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_GRAPH_LOWLINK_HPP_\n#define EMTHRM_GRAPH_LOWLINK_HPP_\n\n\
    #include <algorithm>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Lowlink {\n  std::vector<int>\
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
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_LOWLINK_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/lowlink.hpp
  requiredBy:
  - include/emthrm/graph/biconnected_component.hpp
  - include/emthrm/graph/2-edge-connected_components_by_lowlink.hpp
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/biconnected_component.test.cpp
  - test/graph/lowlink.1.test.cpp
  - test/graph/2-edge-connected_components_by_lowlink.test.cpp
  - test/graph/lowlink.2.test.cpp
documentation_of: include/emthrm/graph/lowlink.hpp
layout: document
title: lowlink
---

深さ優先探索木 (depth-first search tree) で頂点 $i$ の訪問時刻を $\mathrm{order}_i$ とおく。このとき子孫から後退辺 (back edge) を高々一度通ることで到達できる頂点の $\mathrm{order}$ の最小値である。


### 橋 (bridge)

無向グラフ $G = (V, E)$ に対して、グラフ $(V, E \setminus \lbrace e \rbrace)$ が非連結となる辺 $e$ である。


### 関節点 (articulation point)

無向グラフ $G = (V, E)$ に対して、グラフ $(V \setminus \lbrace v \rbrace, E)$ が非連結となる頂点 $v$ である。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

```cpp
template <typename CostType>
struct Lowlink;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> order`|`order[i]` は頂点 $i$ の訪問時刻を表す。||
|`std::vector<int> lowlink`|lowlink||
|`std::vector<int> articulation_points`|関節点の集合||
|`std::vector<Edge<CostType>> bridges`|橋の集合|多重辺に対応していない。|
|`const std::vector<std::vector<Edge<CostType>>> graph`|無向グラフ||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Lowlink(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- http://kagamiz.hatenablog.com/entry/2013/10/05/005213


## Submissons

- [橋](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082818/emthrm/C++14)
- [関節点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_A/review/4082810/emthrm/C++14)
