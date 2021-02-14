---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tree/euler_tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC (Euler tour)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lca_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/tree/lca.md
    document_title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\
      \u30C4\u30A2\u30FC\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/tree/lca_euler_tour.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\
    \u30C4\u30A2\u30FC\u7248\r\n * @docs docs/graph/tree/lca.md\r\n */\r\n\r\n#pragma\
    \ once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\n\
    #include \"euler_tour.hpp\"\r\n#include \"../edge.hpp\"\r\n#include \"../../data_structure/sparse_table.hpp\"\
    \r\n\r\ntemplate <typename CostType>\r\nstruct LCA : EulerTour<CostType> {\r\n\
    \  LCA(const std::vector<std::vector<Edge<CostType>>> &graph, int root = 0) :\
    \ EulerTour<CostType>(graph, root) {\r\n    int n = this->tour.size();\r\n   \
    \ std::vector<P> nodes(n);\r\n    for (int i = 0; i < n; ++i) nodes[i] = {this->depth[i],\
    \ this->tour[i]};\r\n    st.init(nodes, [](P a, P b) -> P { return std::min(a,\
    \ b); });\r\n  }\r\n\r\n  int query(int u, int v) const {\r\n    u = this->left[u];\r\
    \n    v = this->left[v];\r\n    if (u > v) std::swap(u, v);\r\n    return st.query(u,\
    \ v + 1).second;\r\n  }\r\n\r\nprivate:\r\n  using P = std::pair<int, int>;\r\n\
    \r\n  SparseTable<P> st;\r\n};\r\n"
  dependsOn:
  - graph/tree/euler_tour.hpp
  - graph/edge.hpp
  - data_structure/sparse_table.hpp
  isVerificationFile: false
  path: graph/tree/lca_euler_tour.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/lca_euler_tour.test.cpp
documentation_of: graph/tree/lca_euler_tour.hpp
layout: document
redirect_from:
- /library/graph/tree/lca_euler_tour.hpp
- /library/graph/tree/lca_euler_tour.hpp.html
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
  \u7248"
---
# 最小共通祖先 (lowest common ancestor)

根付き木のある2頂点において最も深い共通祖先である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|ダブリング版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\log{\lvert V \rvert}) \rangle$|
|オイラーツアー版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(1) \rangle$|


## 使用法

- ダブリング版

||説明|
|:--:|:--:|
|`LCADoubling<CostType>(graph)`|木 $\mathrm{graph}$ の最小共通祖先を考える|
|`depth[i]`|頂点 $i$ の深さ|
|`dist[i]`|根と頂点 $i$ の間の距離|
|`build(root = 0)`|根を $\mathrm{root}$ として構築する．|
|`query(u, v)`|頂点 $u, v$ の最小共通祖先|
|`distance(u, v)`|頂点 $u, v$ 間の距離|

- [オイラーツアー](euler_tour.md)版

||説明|
|:--:|:--:|
|`LCA<CostType>(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ の最小共通祖先を構築する．|
|`query(u, v)`|頂点 $u, v$ の最小共通祖先|

- [HL 分解版](hld.md)


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.292-295
- https://yukicoder.me/wiki/lowest_common_ancestor

オイラーツアー
- https://github.com/drken1215/algorithm/blob/master/DataStructureOnTree/euler_tour_on_nodes.cpp#L149


## ToDo

- Tarjan's off-line lowest common ancestors algorithm
  - http://www.prefield.com/algorithm/graph/least_common_ancestor.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/least_common_ancestor_tarjan.cc
  - http://monyone.github.io/teihen_library/#OfflineLCA
- level ancestor problem
  - https://en.wikipedia.org/wiki/Level_ancestor_problem
  - https://37zigen.com/level-ancestor-problem/
  - https://drive.google.com/drive/folders/1atQRO6Y9bHgLDH-YLq3obDwMxIuk7--h
  - https://noshi91.hatenablog.com/entry/2019/09/22/114149


## Verified

- [ダブリング版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4084783/emthrm/C++14)
- [オイラーツアー版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14)
- [HL分解版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)