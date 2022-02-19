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
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/tree/lowest_common_ancestor.md
    document_title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\
      \u30C4\u30A2\u30FC\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/tree/lowest_common_ancestor_by_euler_tour.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\r\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\
    \u30C4\u30A2\u30FC\u7248\r\n * @docs docs/graph/tree/lowest_common_ancestor.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include\
    \ <vector>\r\n\r\n#include \"../../data_structure/sparse_table.hpp\"\r\n#include\
    \ \"../edge.hpp\"\r\n#include \"euler_tour.hpp\"\r\n\r\ntemplate <typename CostType>\r\
    \nstruct LowestCommonAncestor : EulerTour<CostType> {\r\n  explicit LowestCommonAncestor(\r\
    \n      const std::vector<std::vector<Edge<CostType>>>& graph,\r\n      const\
    \ int root = 0)\r\n      : EulerTour<CostType>(graph, root) {\r\n    const int\
    \ n = this->tour.size();\r\n    std::vector<std::pair<int, int>> nodes(n);\r\n\
    \    for (int i = 0; i < n; ++i) {\r\n      nodes[i] = {this->depth[i], this->tour[i]};\r\
    \n    }\r\n    sparse_table.init(\r\n        nodes,\r\n        [](const std::pair<int,\
    \ int>& a, const std::pair<int, int>& b)\r\n            -> std::pair<int, int>\
    \ {\r\n          return std::min(a, b);\r\n        });\r\n  }\r\n\r\n  int query(int\
    \ u, int v) const {\r\n    u = this->left[u];\r\n    v = this->left[v];\r\n  \
    \  if (u > v) std::swap(u, v);\r\n    return sparse_table.query(u, v + 1).second;\r\
    \n  }\r\n\r\n private:\r\n  SparseTable<std::pair<int, int>> sparse_table;\r\n\
    };\r\n"
  dependsOn:
  - data_structure/sparse_table.hpp
  - graph/edge.hpp
  - graph/tree/euler_tour.hpp
  isVerificationFile: false
  path: graph/tree/lowest_common_ancestor_by_euler_tour.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
documentation_of: graph/tree/lowest_common_ancestor_by_euler_tour.hpp
layout: document
redirect_from:
- /library/graph/tree/lowest_common_ancestor_by_euler_tour.hpp
- /library/graph/tree/lowest_common_ancestor_by_euler_tour.hpp.html
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\
  \u7248"
---
# 最小共通祖先 (lowest common ancestor)

根付き木のある2頂点に対して最も深い共通祖先である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|ダブリング版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\log{\lvert V \rvert}) \rangle$|
|オイラーツアー版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(1) \rangle$|


## 使用法

- ダブリング版

||説明|
|:--:|:--:|
|`LowestCommonAncestorByDoubling<CostType>(graph)`|木 $\mathrm{graph}$ の最小共通祖先を考える．|
|`depth[i]`|頂点 $i$ の深さ|
|`dist[i]`|根と頂点 $i$ の間の距離|
|`build(root = 0)`|根を $\mathrm{root}$ として構築する．|
|`query(u, v)`|頂点 $u, v$ の最小共通祖先|
|`distance(u, v)`|頂点 $u, v$ 間の距離|

- [オイラーツアー](euler_tour.md)版

||説明|
|:--:|:--:|
|`LowestCommonAncestor<CostType>(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ の最小共通祖先を構築する．|
|`query(u, v)`|頂点 $u, v$ の最小共通祖先|

- [HL 分解版](heavy-light_decomposition.md)


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.292-295，マイナビ出版（2012）
- https://yukicoder.me/wiki/lowest_common_ancestor

オイラーツアー版
- https://github.com/drken1215/algorithm/blob/efb8cf052b095e49e70135a6fb628308d06f49b2/DataStructureOnTree/euler_tour_on_nodes.cpp


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
- [HL 分解版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)
