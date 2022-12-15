---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path/bellman-ford.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman\u2013Ford \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/shortest_path/single-source_shortest_path_problem.md
    document_title: "Bellman\u2013Ford \u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/graph/shortest_path/bellman-ford.hpp: line 14: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief Bellman\u2013Ford \u6CD5\n * @docs docs/graph/shortest_path/single-source_shortest_path_problem.md\n\
    \ */\n\n#ifndef EMTHRM_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP_\n#define EMTHRM_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ CostType>\nstruct BellmanFord {\n  const CostType inf;\n  std::vector<CostType>\
    \ dist;\n\n  BellmanFord(const std::vector<std::vector<Edge<CostType>>>& graph,\n\
    \              const CostType inf = std::numeric_limits<CostType>::max())\n  \
    \    : inf(inf), is_built(false), graph(graph) {}\n\n  bool has_negative_cycle(const\
    \ int s) {\n    is_built = true;\n    const int n = graph.size();\n    dist.assign(n,\
    \ inf);\n    dist[s] = 0;\n    prev.assign(n, -1);\n    for (int step = 0; step\
    \ < n; ++step) {\n      bool is_updated = false;\n      for (int i = 0; i < n;\
    \ ++i) {\n        if (dist[i] == inf) continue;\n        for (const Edge<CostType>&\
    \ e : graph[i]) {\n          if (dist[e.dst] > dist[i] + e.cost) {\n         \
    \   dist[e.dst] = dist[i] + e.cost;\n            prev[e.dst] = i;\n          \
    \  is_updated = true;\n          }\n        }\n      }\n      if (!is_updated)\
    \ return false;\n    }\n    return true;\n  }\n\n  std::vector<int> build_path(int\
    \ t) const {\n    assert(is_built);\n    std::vector<int> res;\n    for (; t !=\
    \ -1; t = prev[t]) {\n      res.emplace_back(t);\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n  }\n\n private:\n  bool is_built;\n  std::vector<int>\
    \ prev;\n  std::vector<std::vector<Edge<CostType>>> graph;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_SHORTEST_PATH_BELLMAN_FORD_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/shortest_path/bellman-ford.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/shortest_path/bellman-ford.test.cpp
documentation_of: include/emthrm/graph/shortest_path/bellman-ford.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/shortest_path/bellman-ford.hpp
- /library/include/emthrm/graph/shortest_path/bellman-ford.hpp.html
title: "Bellman\u2013Ford \u6CD5"
---
# 単一始点最短路問題 (single-source shortest path problem)

始点から他の任意の頂点までの最短路を求める問題である．


## 時間計算量

|アルゴリズム|時間計算量|
|:--:|:--:|
|Bellman–Ford 法|$O(\lvert V \rvert \lvert E \rvert)$|
|Dijkstra 法|$O(\lvert E \rvert \log{\lvert V \rvert})$|


## 使用法

- Bellman–Ford 法

||説明|備考|
|:--:|:--:|:--:|
|`BellmanFord<CostType>(graph, ∞)`|グラフ $\mathrm{graph}$ の単一始点最短路を考える．||
|`inf`|$\infty$||
|`dist[ver]`|始点から頂点 $\mathrm{ver}$ までの最短距離|到達できなければ $\infty$ となる．|
|`has_negative_cycle(s)`|始点 $s$ の単一始点最短路を構築する．|返り値はグラフが負の閉路をもつか．|
|`build_path(t)`|終点 $t$ の最短路|到達できなければ空配列となる．|

- Dijkstra 法

||説明|備考|
|:--:|:--:|:--:|
|`Dijkstra<CostType>(graph, ∞)`|グラフ $\mathrm{graph}$ の単一始点最短路を考える．||
|`inf`|$\infty$||
|`build(s)`|始点 $s$ の単一始点最短路|到達できなければ $\infty$ となる．|
|`build_path(t)`|終点 $t$ の最短路|到達できならば空配列となる．|


## 参考

Bellman–Ford 法
- http://www.prefield.com/algorithm/graph/bellman_ford.html

Dijkstra 法
- https://github.com/spaghetti-source/algorithm/blob/af9a22a92953e903c474e98e79107103adbd0a53/graph/dijkstra.cc


## TODO

- shortest path faster algorithm
  - https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
  - https://dic.kimiyuki.net/spfa
  - http://hogloid.hatenablog.com/entry/20120409/1333973448
  - https://ei1333.github.io/algorithm/shortest-path-faster-algorithm.html
  - https://ei1333.github.io/luzhiled/snippets/graph/shortest-path-faster-algorithm.html
  - https://tubo28.me/compprog/algorithm/spfa/
  - https://tjkendev.github.io/procon-library/python/graph/spfa.html
  - https://hamukichi.hatenablog.jp/entry/2016/03/03/191304
- Dijkstra 法の高速化
  - https://www.slideshare.net/yosupo/ss-46612984
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
  - https://dic.kimiyuki.net/yen-algorithm
  - http://inarizuuuushi.hatenablog.com/entry/2018/08/30/222605
  - https://mugen1337.github.io/procon/Graph2/Yen.cpp
  - https://yukicoder.me/problems/no/1069
- k shortest walk (Eppstein's algorithm)
  - https://en.wikipedia.org/wiki/K_shortest_path_routing#Variations
  - https://dic.kimiyuki.net/eppstein-algorithm
  - https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e
  - https://qiita.com/nariaki3551/items/0ab83541814f98eab322
  - http://www.prefield.com/algorithm/graph/k_shortest_paths.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/k_shortest_walks.cc
  - https://mugen1337.github.io/procon/Graph2/Eppstein.cpp
  - https://judge.yosupo.jp/problem/k_shortest_walk
- $O(\sqrt{N}M\log{C})$
  - https://misawa.github.io/others/flow/cost_scaling_shortest_path.html
- Dial's algorithm
  - https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Specialized_variants
  - https://dic.kimiyuki.net/dial
  - http://bin.t.u-tokyo.ac.jp/startup16/file/6-1.pdf
  - https://tjkendev.github.io/procon-library/python/graph/dial.html
- shortest non-zero path in group-labeled graphs
  - https://ygussany.hatenablog.com/entry/2019/12/04/000000
  - https://gist.github.com/wata-orz/d3037bd0b919c76dd9ddc0379e1e3192
  - https://yukicoder.me/problems/no/1602


## Verified

- [Bellman–Ford 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_1_B/review/4082583/emthrm/C++14)
- [Dijkstra 法](https://judge.yosupo.jp/submission/8211)
