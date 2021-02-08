---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/noshi_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path/dijkstra.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/graph/shortest_path/sssp.md
    document_title: "Dijkstra \u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/shortest_path/dijkstra.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Dijkstra \u6CD5\n * @docs docs/graph/shortest_path/sssp.md\n\
    \ */\n\n#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <queue>\n#include <tuple>\n#include <utility>\n#include <vector>\n#include\
    \ \"../edge.hpp\"\n\ntemplate <typename CostType>\nstruct Dijkstra {\n  Dijkstra(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph, const CostType CINF) : graph(graph),\
    \ CINF(CINF) {}\n\n  std::vector<CostType> build(int s) {\n    is_built = true;\n\
    \    int n = graph.size();\n    std::vector<CostType> dist(n, CINF);\n    dist[s]\
    \ = 0;\n    prev.assign(n, -1);\n    using Pci = std::pair<CostType, int>;\n \
    \   std::priority_queue<Pci, std::vector<Pci>, std::greater<Pci>> que;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      CostType cost; int ver; std::tie(cost,\
    \ ver) = que.top(); que.pop();\n      if (dist[ver] < cost) continue;\n      for\
    \ (const Edge<CostType> &e : graph[ver]) {\n        if (dist[e.dst] > dist[ver]\
    \ + e.cost) {\n          dist[e.dst] = dist[ver] + e.cost;\n          prev[e.dst]\
    \ = ver;\n          que.emplace(dist[e.dst], e.dst);\n        }\n      }\n   \
    \ }\n    return dist;\n  }\n\n  std::vector<int> build_path(int t) const {\n \
    \   assert(is_built);\n    std::vector<int> res;\n    for (; t != -1; t = prev[t])\
    \ res.emplace_back(t);\n    std::reverse(res.begin(), res.end());\n    return\
    \ res;\n  }\n\nprivate:\n  bool is_built = false;\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n  const CostType CINF;\n  std::vector<int> prev;\n};\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/shortest_path/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/noshi_graph.test.cpp
  - test/graph/shortest_path/dijkstra.test.cpp
documentation_of: graph/shortest_path/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/dijkstra.hpp
- /library/graph/shortest_path/dijkstra.hpp.html
title: "Dijkstra \u6CD5"
---
# 単一始点最短路問題 (single-source shortest path)

ある始点から他の任意の頂点までの最短路を求める問題である．

|アルゴリズム|注意|
|:--:|:--:|
|Bellman-Ford 法|負の重みをもつ辺が存在していてもよい．|
|Dijkstra 法|負の重みをもつ辺が存在してはいけない．|


## 時間計算量

|アルゴリズム|時間計算量|
|:--:|:--:|
|Bellman-Ford 法|$O(\lvert V \rvert \lvert E \rvert)$|
|Dijkstra 法|$O(\lvert E \rvert \log{\lvert V \rvert})$|


## 使用法

- Bellman-Ford 法

||説明|備考|
|:--:|:--:|:--:|
|`BellmanFord<CostType>(graph, ∞)`|グラフ $\mathrm{graph}$ の単一始点最短路を考える．||
|`has_negative_cycle(s)`|始点 $s$ の単一始点最短路を構築する．|返り値はグラフが負の閉路をもつか．|
|`dist[ver]`|始点から頂点 $\mathrm{ver}$ までの最短距離|到達不可能ならば $\infty$ となる．|
|`build_path(t)`|終点 $t$ の最短路|到達不可能ならば空配列となる．|

- Dijkstra 法

||説明|備考|
|:--:|:--:|:--:|
|`Dijkstra<CostType>(graph, ∞)`|グラフ $\mathrm{graph}$ の単一始点最短路を考える．||
|`build(s)`|始点 $s$ の単一始点最短路||
|`build_path(t)`|終点 $t$ の最短路|到達不可能ならば空配列となる．|


## 参考

Bellman-Ford 法
- http://www.prefield.com/algorithm/graph/bellman_ford.html

Dijkstra 法
- https://github.com/spaghetti-source/algorithm/blob/master/graph/dijkstra.cc


## ToDo

- Shortest Path Faster Algorithm
  - https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
  - http://hogloid.hatenablog.com/entry/20120409/1333973448
  - https://ei1333.github.io/algorithm/shortest-path-faster-algorithm.html
  - https://ei1333.github.io/luzhiled/snippets/graph/shortest-path-faster-algorithm.html
  - https://tubo28.me/compprog/algorithm/spfa/
  - https://tjkendev.github.io/procon-library/python/graph/spfa.html
  - https://hamukichi.hatenablog.jp/entry/2016/03/03/191304
- Dijkstra 法の高速化
  - skew heap
    - https://github.com/primenumber/ProconLib/blob/master/Structure/SkewHeapDijkstra.cpps
  - Fibonacchi heap
    - https://github.com/ei1333/library/blob/master/graph/dijkstra-fibonacchi-heap.cpp
  - radix heap
    - https://github.com/ei1333/library/blob/master/graph/dijkstra-radix-heap.cpp
- 双方向 Dijkstra
  - http://tatanaideyo.hatenablog.com/entry/2015/11/01/031713
  - https://tubo28.me/compprog/algorithm/bidirectional-dijkstra/
  - https://togetter.com/li/893481
- k shortest path routing (Yen's algorithm)
  - https://en.wikipedia.org/wiki/K_shortest_path_routing
  - https://en.wikipedia.org/wiki/Yen%27s_algorithm
  - http://inarizuuuushi.hatenablog.com/entry/2018/08/30/222605
  - https://yukicoder.me/problems/no/1069
- k shortest walk (Eppstein's algorithm)
  - https://en.wikipedia.org/wiki/K_shortest_path_routing#Variations
  - https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e
  - http://www.prefield.com/algorithm/graph/k_shortest_paths.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/k_shortest_walks.cc
  - https://judge.yosupo.jp/problem/k_shortest_walk


## Verified

- [Bellman-Ford 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_1_B/review/4082583/emthrm/C++14)
- [Dijkstra 法](https://judge.yosupo.jp/submission/8211)
