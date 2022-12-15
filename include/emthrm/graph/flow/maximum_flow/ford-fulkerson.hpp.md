---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford\u2013Fulkerson\
      \ \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/flow/maximum_flow/maximum_flow.md
    document_title: "Ford\u2013Fulkerson \u6CD5"
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp\"\
    \n/**\n * @brief Ford\u2013Fulkerson \u6CD5\n * @docs docs/graph/flow/maximum_flow/maximum_flow.md\n\
    \ */\n\n#ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_FORD_FULKERSON_HPP_\n#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_FORD_FULKERSON_HPP_\n\
    \n#include <algorithm>\n#include <limits>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstruct FordFulkerson {\n  struct Edge {\n    int\
    \ dst, rev;\n    T cap;\n    explicit Edge(const int dst, const T cap, const int\
    \ rev)\n        : dst(dst), rev(rev), cap(cap) {}\n  };\n\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit FordFulkerson(const int n)\n      : graph(n), timestamp(0),\
    \ is_used(n, -1) {}\n\n  void add_edge(const int src, const int dst, const T cap)\
    \ {\n    graph[src].emplace_back(dst, cap, graph[dst].size());\n    graph[dst].emplace_back(src,\
    \ 0, graph[src].size() - 1);\n  }\n\n  T maximum_flow(const int s, const int t,\n\
    \                 T limit = std::numeric_limits<T>::max()) {\n    T res = 0;\n\
    \    while (limit > 0) {\n      const T tmp = dfs(s, t, limit);\n      ++timestamp;\n\
    \      if (tmp == 0) break;\n      limit -= tmp;\n      res += tmp;\n    }\n \
    \   return res;\n  }\n\n private:\n  int timestamp;\n  std::vector<int> is_used;\n\
    \n  T dfs(const int ver, const int t, const T flow) {\n    if (ver == t) return\
    \ flow;\n    is_used[ver] = timestamp;\n    for (Edge& e : graph[ver]) {\n   \
    \   if (is_used[e.dst] < timestamp && e.cap > 0) {\n        const T tmp = dfs(e.dst,\
    \ t, std::min(flow, e.cap));\n        if (tmp > 0) {\n          e.cap -= tmp;\n\
    \          graph[e.dst][e.rev].cap += tmp;\n          return tmp;\n        }\n\
    \      }\n    }\n    return 0;\n  }\n};\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_FORD_FULKERSON_HPP_\n"
  code: "/**\n * @brief Ford\u2013Fulkerson \u6CD5\n * @docs docs/graph/flow/maximum_flow/maximum_flow.md\n\
    \ */\n\n#ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_FORD_FULKERSON_HPP_\n#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_FORD_FULKERSON_HPP_\n\
    \n#include <algorithm>\n#include <limits>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstruct FordFulkerson {\n  struct Edge {\n    int\
    \ dst, rev;\n    T cap;\n    explicit Edge(const int dst, const T cap, const int\
    \ rev)\n        : dst(dst), rev(rev), cap(cap) {}\n  };\n\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit FordFulkerson(const int n)\n      : graph(n), timestamp(0),\
    \ is_used(n, -1) {}\n\n  void add_edge(const int src, const int dst, const T cap)\
    \ {\n    graph[src].emplace_back(dst, cap, graph[dst].size());\n    graph[dst].emplace_back(src,\
    \ 0, graph[src].size() - 1);\n  }\n\n  T maximum_flow(const int s, const int t,\n\
    \                 T limit = std::numeric_limits<T>::max()) {\n    T res = 0;\n\
    \    while (limit > 0) {\n      const T tmp = dfs(s, t, limit);\n      ++timestamp;\n\
    \      if (tmp == 0) break;\n      limit -= tmp;\n      res += tmp;\n    }\n \
    \   return res;\n  }\n\n private:\n  int timestamp;\n  std::vector<int> is_used;\n\
    \n  T dfs(const int ver, const int t, const T flow) {\n    if (ver == t) return\
    \ flow;\n    is_used[ver] = timestamp;\n    for (Edge& e : graph[ver]) {\n   \
    \   if (is_used[e.dst] < timestamp && e.cap > 0) {\n        const T tmp = dfs(e.dst,\
    \ t, std::min(flow, e.cap));\n        if (tmp > 0) {\n          e.cap -= tmp;\n\
    \          graph[e.dst][e.rev].cap += tmp;\n          return tmp;\n        }\n\
    \      }\n    }\n    return 0;\n  }\n};\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_FORD_FULKERSON_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
documentation_of: include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp
- /library/include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp.html
title: "Ford\u2013Fulkerson \u6CD5"
---
# 最大流 (maximum flow)

ある始点からある終点までのフローの最大値である．

最大フロー最小カット定理より最小カットと一致する．


## 時間計算量

|アルゴリズム|時間計算量|
|:--:|:--:|
|Ford–Fulkerson 法|最大流を $F$ とおくと $O(F \lvert E \rvert)$．|
|Dinic 法|最大流を $F$ とおくと $O\left(\min \left\lbrace {\lvert V \rvert}^2 \lvert E \rvert,\ F \lvert E \rvert,\ {\lvert E \rvert}^{3/2} \max_{e \in E} C_e,\ \sqrt{\lvert V \rvert} \lvert E \rvert \max_{v \in V} \min \left\lbrace \sum_{e \in \delta^-(v) \subset E} C_e, \sum_{e \in \delta^+(v) \subset E} C_e \right\rbrace \right\rbrace\right)$．|


## 使用法

- Ford–Fulkerson 法

||説明|備考|
|:--:|:--:|:--:|
|`FordFulkerson<T>(n)`|頂点数 $N$ の Ford–Fulkerson 法を考える．||
|`graph`|残余グラフ||
|`add_edge(src, dst, cap)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$ の辺を追加する．||
|`maximum_flow(s, t, limit = ∞)`|上限を $\mathrm{limit}$ とした始点 $s$ から終点 $t$ までの最大流|容量が整数でなければ，停止しないときがある．|

- Dinic 法

||説明|
|:--:|:--:|
|`Dinic<T>(n)`|頂点数 $N$ の Dinic 法|
|`graph`|残余グラフ|
|`add_edge(src, dst, cap)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$ の辺を追加する．|
|`maximum_flow(s, t, limit = ∞)`|上限を $\mathrm{limit}$ とした始点 $s$ から終点 $t$ までの最大流|

特殊な場合を考える．

- 複数の source や sink が存在する．

  新たな始点や終点を用意する．その始点から各 source に流出量と等しい容量をもつ辺を，各 sink からその終点に流入量と等しい容量をもつ辺を追加すればよい．

- 無向グラフ

  両方向に同容量の有向辺を追加すればよい．または逆辺に等しい容量をもたせればよい?

- 頂点にも容量が存在する．

  頂点を入頂点と出頂点に分割する．入ってくる辺を入頂点，出ていく辺を出頂点につなぎ直し，入頂点から出頂点に頂点の容量と同容量の辺を追加すればよい．

- 辺の容量を増やす．

  残余グラフに対して，容量を増やした後に再び最大流を求め，元の答えに加えればよい．

- 辺 $e = (u, v)$ の容量を $c$ だけ減らす．

  - $e.\mathrm{cap} \geq c$ のとき

    $e.\mathrm{cap} \gets e.\mathrm{cap} - c$ とすればよい．

  - $e.\mathrm{cap} < c$ のとき

    $c \gets c - e.\mathrm{cap},\ e.\mathrm{cap} \gets 0$ とする．残余グラフにおける $u$ から $v$ までの最大流を $c^{\prime}$ とおく．

    - $c^{\prime} \geq c$ のとき

      $u$ から $v$ まで $c$ だけ流せばよい．

    - $c^{\prime} < c$ のとき

      $u$ から $v$ まで $c^{\prime}$ だけ流す．終点から $v$ まで，そして $u$ から始点まで $c - c^{\prime}$ 押し戻す必要があり，最大流は $c - c^{\prime}$ 減る．


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.188-195，マイナビ出版（2012）
- https://twitter.com/kotatsugame_t/status/1192092085479858176

Ford–Fulkerson 法
- https://ei1333.github.io/luzhiled/snippets/graph/ford-fulkerson.html

Dinic 法
- https://misawa.github.io/others/flow/dinic_time_complexity.html


## TODO

- エドモンズ・カープのアルゴリズム (Edmonds–Karp algorithm)
  - https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%89%E3%83%A2%E3%83%B3%E3%82%BA%E3%83%BB%E3%82%AB%E3%83%BC%E3%83%97%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
  - http://www.prefield.com/algorithm/graph/edmonds_karp.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximum_flow_edmonds_karp.cc
  - https://inzkyk.github.io/algorithms/maximum_flows_minimum_cuts/edmonds_and_karps_algorithms/
- 容量スケーリング版 Dinic 法
  - https://kopricky.github.io/code/NetworkFlow/dinic.html
  - https://github.com/ei1333/library/blob/master/graph/dinic-capacity-scaling.cpp
- push-relabel algorithm
  - https://kenkoooo.hatenablog.com/entry/2016/12/22/143638
  - https://ei1333.github.io/luzhiled/snippets/graph/push-relabel.html
  - http://www.prefield.com/algorithm/graph/goldberg_tarjan.html
  - https://tubo28.me/compprog/algorithm/edmonds-kerp/
  - https://qiita.com/a-lilas/items/3bf338c7929f6951fa41
  - https://qiita.com/nariaki3551/items/65baee3c6ef0a6ffa136
  - https://kopricky.github.io/code/Academic/max_flow_push_relabel.html
  - https://tjkendev.github.io/procon-library/cpp/max_flow/push-relabel-highest.html
- 動的木を用いた Dinic 法
  - https://misawa.github.io/others/flow/dinic_time_complexity.html
- 全域最小カット
  - http://www.prefield.com/algorithm/graph/minimum_cut.html
  - https://github.com/primenumber/ProconLib/blob/master/Graph/GlobalMinimumCut.cpp
  - http://monyone.github.io/teihen_library/#MinimumCutStoerWagner
  - https://www.slideshare.net/hcpc_hokudai/flow-cut
  - https://judge.yosupo.jp/problem/global_minimum_cut_of_dynamic_star_augmented_graph
- 最大カット
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximum_cut.cc
- 二部グラフの場合の計算量
  - https://twitter.com/Mi_Sawa/status/1391968412184682498


## Verified

- [Ford–Fulkerson 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_6_A/review/4085135/emthrm/C++14)
- [Dinic 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1615/review/4085139/emthrm/C++14)
