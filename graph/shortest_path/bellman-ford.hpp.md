---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path/bellman-ford.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman-Ford \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/shortest_path/sssp.md
    document_title: "Bellman-Ford \u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/shortest_path/bellman-ford.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Bellman-Ford \u6CD5\n * @docs docs/graph/shortest_path/sssp.md\n\
    \ */\n\n#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"../edge.hpp\"\n\ntemplate <typename CostType>\nstruct BellmanFord {\n\
    \  std::vector<CostType> dist;\n\n  BellmanFord(const std::vector<std::vector<Edge<CostType>>>\
    \ &graph, const CostType CINF) : graph(graph), CINF(CINF) {}\n\n  bool has_negative_cycle(int\
    \ s) {\n    is_built = true;\n    int n = graph.size();\n    dist.assign(n, CINF);\n\
    \    dist[s] = 0;\n    prev.assign(n, -1);\n    for (int step = 0; step < n; ++step)\
    \ {\n      bool is_updated = false;\n      for (int i = 0; i < n; ++i) {\n   \
    \     if (dist[i] == CINF) continue;\n        for (const Edge<CostType> &e : graph[i])\
    \ {\n          if (dist[e.dst] > dist[i] + e.cost) {\n            dist[e.dst]\
    \ = dist[i] + e.cost;\n            prev[e.dst] = i;\n            is_updated =\
    \ true;\n          }\n        }\n      }\n      if (!is_updated) return false;\n\
    \    }\n    return true;\n  }\n\n  std::vector<int> build_path(int t) const {\n\
    \    assert(is_built);\n    std::vector<int> res;\n    for (; t != -1; t = prev[t])\
    \ res.emplace_back(t);\n    std::reverse(res.begin(), res.end());\n    return\
    \ res;\n  }\n\nprivate:\n  bool is_built = false;\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n  const CostType CINF;\n  std::vector<int> prev;\n};\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/shortest_path/bellman-ford.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/shortest_path/bellman-ford.test.cpp
documentation_of: graph/shortest_path/bellman-ford.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/bellman-ford.hpp
- /library/graph/shortest_path/bellman-ford.hpp.html
title: "Bellman-Ford \u6CD5"
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
