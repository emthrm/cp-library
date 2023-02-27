---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/chromatic_number.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/chromatic_number.hpp\"\n\n\n\n#include\
    \ <bit>\n#include <numeric>\n#include <ranges>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n\
    #define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\nnamespace emthrm {\n\n\
    template <typename CostType>\nstruct Edge {\n  CostType cost;\n  int src, dst;\n\
    \n  explicit Edge(const int src, const int dst, const CostType cost = 0)\n   \
    \   : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const Edge& x) const\
    \ = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 10 \"include/emthrm/graph/chromatic_number.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename CostType>\nint chromatic_number(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  std::vector<int> adj(n, 0);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (const int e : graph[i] | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      adj[i] |= 1 << e;\n    }\n  }\n  std::vector<int> indep(1 << n);\n\
    \  indep[0] = 1;\n  for (unsigned int i = 1; i < (1 << n); ++i) {\n    const int\
    \ v = std::countr_zero(i);\n    indep[i] = indep[i ^ (1 << v)] + indep[(i ^ (1\
    \ << v)) & ~adj[v]];\n  }\n  int res = n;\n  for (const int mod : std::vector<int>{1000000007,\
    \ 1000000011}) {\n    std::vector<long long> f(1 << n);\n    for (unsigned int\
    \ i = 0; i < (1 << n); ++i) {\n      f[i] = ((n - std::popcount(i)) & 1 ? mod\
    \ - 1 : 1);\n    }\n    for (int c = 1; c < res; ++c) {\n      for (int i = 0;\
    \ i < (1 << n); ++i) {\n        f[i] = (f[i] * indep[i]) % mod;\n      }\n   \
    \   if (std::reduce(f.begin(), f.end(), 0LL) % mod > 0) {\n        res = c;\n\
    \        break;\n      }\n    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_\n#define EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_\n\
    \n#include <bit>\n#include <numeric>\n#include <ranges>\n#include <vector>\n\n\
    #include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ CostType>\nint chromatic_number(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  std::vector<int> adj(n, 0);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (const int e : graph[i] | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      adj[i] |= 1 << e;\n    }\n  }\n  std::vector<int> indep(1 << n);\n\
    \  indep[0] = 1;\n  for (unsigned int i = 1; i < (1 << n); ++i) {\n    const int\
    \ v = std::countr_zero(i);\n    indep[i] = indep[i ^ (1 << v)] + indep[(i ^ (1\
    \ << v)) & ~adj[v]];\n  }\n  int res = n;\n  for (const int mod : std::vector<int>{1000000007,\
    \ 1000000011}) {\n    std::vector<long long> f(1 << n);\n    for (unsigned int\
    \ i = 0; i < (1 << n); ++i) {\n      f[i] = ((n - std::popcount(i)) & 1 ? mod\
    \ - 1 : 1);\n    }\n    for (int c = 1; c < res; ++c) {\n      for (int i = 0;\
    \ i < (1 << n); ++i) {\n        f[i] = (f[i] * indep[i]) % mod;\n      }\n   \
    \   if (std::reduce(f.begin(), f.end(), 0LL) % mod > 0) {\n        res = c;\n\
    \        break;\n      }\n    }\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/chromatic_number.test.cpp
documentation_of: include/emthrm/graph/chromatic_number.hpp
layout: document
title: "\u5F69\u8272\u6570 (chromatic number)"
---

隣接頂点間で色が異なるような頂点彩色に必要な最小の色の数である。


## 時間計算量

$O(2^{\lvert V \rvert} \lvert V \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`int chromatic_number(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ の彩色数|


## 参考文献

- https://www.slideshare.net/wata_orz/ss-12131479
- http://drken1215.hatenablog.com/entry/2019/01/16/030000
- https://www.learning-algorithms.com/entry/2018/01/27/235959
- https://github.com/spaghetti-source/algorithm/blob/b541e0b06aa4145592527b7de8e2caa8720bac22/graph/chromatic_number.cc


## TODO

- 高速化
  - https://www.mathenachia.blog/chromatic-fast/
  - https://atcoder.jp/contests/abc056/editorial/2092
- 二部グラフの辺彩色
  - https://ei1333.hateblo.jp/entry/2020/08/25/015955
  - https://37zigen.com/noga-alon-edge-coloring-bipartite/
  - https://github.com/yosupo06/library-checker-problems/issues/393
  - https://twitter.com/snuke_/status/1246630370415538176
  - https://twitter.com/noshi91/status/1247010856040165377
  - https://github.com/ei1333/library/blob/master/structure/union-find/bipartite-graph.cpp
  - http://www.prefield.com/algorithm/graph/bipartite_coloring.html
  - https://judge.yosupo.jp/problem/bipartite_edge_coloring
  - https://yukicoder.me/problems/no/3071
- 彩色多項式
  - https://github.com/eandbsoftware/libraryCPP/blob/master/%23ChromaticPolynomial.cpp


## Submissons

https://judge.yosupo.jp/submission/40942
