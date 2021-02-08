---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\u5C0F\u6D41\
      \u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u71C3\u3084\u3059\
      \u57CB\u3081\u308B"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/flow/maximum_flow/maximum_flow.md
    document_title: "Dinic \u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/maximum_flow/dinic.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief Dinic \u6CD5\r\n * @docs docs/graph/flow/maximum_flow/maximum_flow.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <algorithm>\r\n#include <queue>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nstruct Dinic {\r\n  struct Edge {\r\
    \n    int dst, rev;\r\n    T cap;\r\n    Edge(int dst, T cap, int rev) : dst(dst),\
    \ cap(cap), rev(rev) {}\r\n  };\r\n\r\n  std::vector<std::vector<Edge>> graph;\r\
    \n\r\n  Dinic(int n) : graph(n), level(n), itr(n) {}\r\n\r\n  void add_edge(int\
    \ src, int dst, T cap) {\r\n    graph[src].emplace_back(dst, cap, graph[dst].size());\r\
    \n    graph[dst].emplace_back(src, 0, graph[src].size() - 1);\r\n  }\r\n\r\n \
    \ T maximum_flow(int s, int t, T limit) {\r\n    T res = 0;\r\n    while (true)\
    \ {\r\n      bfs(s);\r\n      if (level[t] == -1) return res;\r\n      std::fill(itr.begin(),\
    \ itr.end(), 0);\r\n      T tmp;\r\n      while ((tmp = dfs(s, t, limit)) > 0)\
    \ res += tmp;\r\n    }\r\n  }\r\n\r\nprivate:\r\n  std::vector<int> level, itr;\r\
    \n\r\n  void bfs(int s) {\r\n    std::fill(level.begin(), level.end(), -1);\r\n\
    \    std::queue<int> que;\r\n    level[s] = 0;\r\n    que.emplace(s);\r\n    while\
    \ (!que.empty()) {\r\n      int ver = que.front(); que.pop();\r\n      for (const\
    \ Edge &e : graph[ver]) {\r\n        if (level[e.dst] == -1 && e.cap > 0) {\r\n\
    \          level[e.dst] = level[ver] + 1;\r\n          que.emplace(e.dst);\r\n\
    \        }\r\n      }\r\n    }\r\n  }\r\n\r\n  T dfs(int ver, int t, T flow) {\r\
    \n    if (ver == t) return flow;\r\n    for (; itr[ver] < graph[ver].size(); ++itr[ver])\
    \ {\r\n      Edge &e = graph[ver][itr[ver]];\r\n      if (level[ver] < level[e.dst]\
    \ && e.cap > 0) {\r\n        T tmp = dfs(e.dst, t, std::min(flow, e.cap));\r\n\
    \        if (tmp > 0) {\r\n          e.cap -= tmp;\r\n          graph[e.dst][e.rev].cap\
    \ += tmp;\r\n          return tmp;\r\n        }\r\n      }\r\n    }\r\n    return\
    \ 0;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/maximum_flow/dinic.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp
  - test/graph/flow/maximum_flow/project_selection_problem.test.cpp
documentation_of: graph/flow/maximum_flow/dinic.hpp
layout: document
redirect_from:
- /library/graph/flow/maximum_flow/dinic.hpp
- /library/graph/flow/maximum_flow/dinic.hpp.html
title: "Dinic \u6CD5"
---
# 最大流 (maximum flow)

ある始点からある終点までのフローの最大値である．

最大フロー最小カット定理より最小カットと一致する．


## 時間計算量

|アルゴリズム|時間計算量|
|:--:|:--:|
|Ford-Fulkerson 法|最大流を $F$ とおくと $O(F \lvert E \rvert)$．|
|Dinic 法|$O(\lvert E \rvert {\lvert V \rvert}^2)$|


## 使用法

- Ford-Fulkerson 法

||説明|備考|
|:--:|:--:|:--:|
|`FordFulkerson<T>(n)`|頂点数 $N$ の Ford-Fulkerson 法を考える．||
|`graph`|残余グラフ||
|`add_edge(src, dst, cap)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$ の辺を張る．||
|`maximum_flow(s, t, limit)`|上限を $\mathrm{limit} (\infty)$ とした始点 $s$ から終点 $t$ までの最大流|容量が整数でないときに停止しない可能性がある．|

- Dinic 法

||説明|
|:--:|:--:|
|`Dinic<T>(n)`|頂点数 $N$ の Dinic 法|
|`graph`|残余グラフ|
|`add_edge(src, dst, cap)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$ の辺を張る．|
|`maximum_flow(s, t, limit)`|上限を $\mathrm{limit} (\infty)$ とした始点 $s$ から終点 $t$ までの最大流|

特殊な場合を考える．

- 複数の source や sink が存在する．

  新たな始点や終点を用意する．その始点から各 source に流出量と等しい容量をもつ辺を，各 sink からその終点に流入量と等しい容量をもつ辺を張ればよい．

- 無向グラフ

  両方向に同容量の有向辺を張ればよい．または逆辺に等しい容量をもたせればよい?

- 頂点にも容量が存在する．

  その頂点を入頂点と出頂点に分割する．入ってくる辺を入頂点，出ていく辺を出頂点につなぎ直し，入頂点から出頂点にその頂点の容量と同容量の辺を張ればよい．

- 辺の容量を増やす．

  残余グラフにおいて容量を増やした後に再び最大流を求め，元の答えに加えればよい．

- 辺 $e = (u, v)$ の容量を $c$ だけ減らす．

  - $e.cap \geq c$ のとき

    $e.cap -= c$ とするだけでよい

  - $e.cap < c$ のとき

    $c -= e.cap,\ e.cap = 0$ とする．残余グラフにおける $u$ から $v$ までの最大流を $c^{\prime}$ とおく．

    - $c^{\prime} \geq c$ のとき

      $u$ から $v$ まで $c$ だけ流せばよい．

    - $c^{\prime} < c$ のとき

      $u$ から $v$ まで $c^{\prime}$ だけ流す．終点から $v$ まで，そして $u$ から始点まで $c - c^{\prime}$ 押し戻す必要があり，最大流は $c - c^{\prime}$ 減る．


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.188-195
- https://twitter.com/kotatsugame_t/status/1192092085479858176

Ford-Fulkerson 法
- https://ei1333.github.io/luzhiled/snippets/graph/ford-fulkerson.html


## ToDo

- エドモンズ・カープのアルゴリズム (Edmonds-Karp algorithm)
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
- 全域最小カット
  - http://www.prefield.com/algorithm/graph/minimum_cut.html
  - https://github.com/primenumber/ProconLib/blob/master/Graph/GlobalMinimumCut.cpp
  - http://monyone.github.io/teihen_library/#MinimumCutStoerWagner
  - https://www.slideshare.net/hcpc_hokudai/flow-cut
  - https://judge.yosupo.jp/problem/global_minimum_cut_of_dynamic_star_augmented_graph
- 最大カット
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximum_cut.cc


## Verified

- [Ford-Fulkerson 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_6_A/review/4085135/emthrm/C++14)
- [Dinic 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1615/review/4085139/emthrm/C++14)
