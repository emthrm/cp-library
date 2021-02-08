---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/mst/prim.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u5C0F\u5168\u57DF\u6728/Prim \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/mst/mst.md
    document_title: "Prim \u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/mst/prim.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief Prim \u6CD5\r\n * @docs docs/graph/mst/mst.md\r\n */\r\n\
    \r\n#pragma once\r\n#include <functional>\r\n#include <queue>\r\n#include <vector>\r\
    \n#include \"../edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nCostType prim(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph, int root = 0) {\r\n  int n\
    \ = graph.size();\r\n  CostType total = 0;\r\n  std::vector<bool> visited(n, false);\r\
    \n  visited[root] = true;\r\n  std::priority_queue<Edge<CostType>, std::vector<Edge<CostType>>,\
    \ std::greater<Edge<CostType>>> que;\r\n  for (const Edge<CostType> &e : graph[root])\
    \ {\r\n    if (e.dst != root) que.emplace(e);\r\n  }\r\n  while (!que.empty())\
    \ {\r\n    Edge<CostType> now = que.top(); que.pop();\r\n    if (visited[now.dst])\
    \ continue;\r\n    visited[now.dst] = true;\r\n    total += now.cost;\r\n    for\
    \ (const Edge<CostType> &e : graph[now.dst]) {\r\n      if (!visited[e.dst]) que.emplace(e);\r\
    \n    }\r\n  }\r\n  return total;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/mst/prim.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/mst/prim.test.cpp
documentation_of: graph/mst/prim.hpp
layout: document
redirect_from:
- /library/graph/mst/prim.hpp
- /library/graph/mst/prim.hpp.html
title: "Prim \u6CD5"
---
# 最小全域木 (minimum spanning tree)

無向グラフにおいて辺の総コストが最小となる全域木である．

|アルゴリズム|特徴|
|:--:|:--:|
|Prim 法|ある頂点から構築を開始する．|
|Kruskal 法|コストの昇順に辺を見る．|


## 時間計算量

$O(\lvert E \rvert \log{\lvert V \rvert})$


## 使用法

- Prim 法

||説明|備考|
|:--:|:--:|:--:|
|`prim(graph, root = 0)`|根を $\mathrm{root}$ とするグラフ $\mathrm{graph}$ の最小全域木のコスト|$graph$ には双方向の辺の情報が必要である．|

- Prim 法 重量版

||説明|備考|
|:--:|:--:|:--:|
|`prim_heavy(graph, root = 0)`|根を $\mathrm{root}$ とするグラフ $\mathrm{graph}$ の最小全域木に含まれる辺|$\mathrm{graph}$ には双方向の辺の情報が必要である．|

- Kruskal 法

||説明|備考|
|:--:|:--:|:--:|
|`kruskal(graph)`|グラフ $\mathrm{graph}$ の最小全域木のコスト|$\mathrm{graph}$ には単方向の辺の情報のみでよい．|

- Kruskal 法 重量版

||説明|備考|
|:--:|:--:|:--:|
|`kruskal_heavy(graph)`|グラフ $\mathrm{graph}$ の最小全域木に含まれる辺|$\mathrm{graph}$ には単方向の辺の情報のみでよい．|


## 参考

Prim 法
- http://www.prefield.com/algorithm/graph/prim.html

Kruskal 法
- https://github.com/spaghetti-source/algorithm/blob/master/graph/kruskal.cc


## ToDo

- ブルーフカ法 (Borůvka's algorithm)
  - https://ja.wikipedia.org/wiki/%E3%83%96%E3%83%AB%E3%83%BC%E3%83%95%E3%82%AB%E6%B3%95
  - http://spinda2.blog48.fc2.com/blog-entry-560.html
  - https://inzkyk.github.io/algorithms/minimum_spanning_trees/boruvka_algorithms/
  - https://twitter.com/yamerarenaku/status/1166349080022462465
  - https://ei1333.github.io/luzhiled/snippets/graph/boruvka.html
  - https://lumakernel.github.io/ecasdqina/graph/boruvka
- Fibonacchi heap を用いた Prim 法の高速化
  - https://github.com/ei1333/library/blob/master/graph/prim-fibonacchi-heap.cpp
- ボロノイ図を用いる．
  - http://tokoharuland.hateblo.jp/entry/2018/04/01/155743
  - https://github.com/beet-aizu/library/blob/master/tree/voronoiminimumspanningtree.cpp
- 最小シュタイナー木
  - https://ja.wikipedia.org/wiki/%E3%82%B7%E3%83%A5%E3%82%BF%E3%82%A4%E3%83%8A%E3%83%BC%E6%9C%A8
  - https://www.slideshare.net/wata_orz/ss-12131479
  - http://www.prefield.com/algorithm/dp/steiner_tree.html
  - http://monyone.github.io/teihen_library/#MinimumSteinerTree
- 最小全域有向木
  - http://joisino.hatenablog.com/entry/2017/01/11/230141
  - https://ark4rk.hatenablog.com/entry/2017/09/15/011937
  - https://twitter.com/nuo_chocorusk/status/1187055311422574593
  - https://twitter.com/yamerarenaku/status/1187065174529691648
  - https://ei1333.github.io/algorithm/chu-liu-edmond.html
  - https://ei1333.github.io/luzhiled/snippets/graph/chu-liu-edmond.html
  - https://github.com/beet-aizu/library/blob/master/graph/arborescence_edmond.cpp
  - https://github.com/beet-aizu/library/blob/master/graph/arborescence_tarjan.cpp
  - https://lumakernel.github.io/ecasdqina/graph/MinimumSpanningArborescence
  - http://www.prefield.com/algorithm/graph/chu_liu_edmonds.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence.cc
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence2.cc
  - https://github.com/primenumber/ProconLib/blob/master/Graph/MinimumArborescence.cpp
  - https://gist.github.com/tjkendev/231897301fde67d4a81f51c3f0873936
  - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B
  - https://judge.yosupo.jp/problem/directedmst
- minimum diameter spanning tree
  - http://www.prefield.com/algorithm/graph/minimum_diameter_spanning_tree.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/kariv_hakimi.cc


## Verified

- [Prim 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_2_A/review/4083632/emthrm/C++14)
- Prim 法 重量版
- [Kruskal 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_2_A/review/4083639/emthrm/C++14)
- Kruskal 法 重量版
