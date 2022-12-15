---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/eulerian_trail_in_directed_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\
      \u30D5\u7248"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/eulerian_trail.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\u30D5\
      \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/graph/eulerian_trail_in_directed_graph.hpp: line 13: unable to\
    \ process #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\u30D5\
    \u7248\n * @docs docs/graph/eulerian_trail.md\n */\n\n#ifndef EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_\n\
    #define EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>>\
    \ eulerian_trail_in_directed_graph(\n    std::vector<std::vector<Edge<CostType>>>\
    \ graph, int s = -1) {\n  const int n = graph.size();\n  int edge_num = 0;\n \
    \ std::vector<int> deg(n, 0);\n  for (int i = 0; i < n; ++i) {\n    edge_num +=\
    \ graph[i].size();\n    deg[i] += graph[i].size();\n    for (const Edge<CostType>&\
    \ e : graph[i]) --deg[e.dst];\n  }\n  if (edge_num == 0) return {};\n  const int\
    \ not0 = n - std::count(deg.begin(), deg.end(), 0);\n  if (not0 == 0) {\n    if\
    \ (s == -1) {\n      for (int i = 0; i < n; ++i) {\n        if (!graph[i].empty())\
    \ {\n          s = i;\n          break;\n        }\n      }\n    }\n  } else if\
    \ (not0 == 2) {\n    bool t_exists = false;\n    for (int i = 0; i < n; ++i) {\n\
    \      if (deg[i] == 0) continue;\n      if (deg[i] == 1) {\n        if (s ==\
    \ -1) s = i;\n        if (s != i) return {};\n      } else if (deg[i] == -1) {\n\
    \        if (t_exists) return {};\n        t_exists = true;\n      } else {\n\
    \        return {};\n      }\n    }\n  } else {\n    return {};\n  }\n  std::vector<Edge<CostType>>\
    \ res;\n  const std::function<void(int)> dfs = [&graph, &res, &dfs](const int\
    \ ver) {\n    while (!graph[ver].empty()) {\n      const Edge<CostType> e = graph[ver].back();\n\
    \      graph[ver].pop_back();\n      dfs(e.dst);\n      res.emplace_back(e);\n\
    \    }\n  };\n  dfs(s);\n  if (static_cast<int>(res.size()) == edge_num) {\n \
    \   std::reverse(res.begin(), res.end());\n    return res;\n  }\n  return {};\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EULERIAN_TRAIL_IN_DIRECTED_GRAPH_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/eulerian_trail_in_directed_graph.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/eulerian_trail_in_directed_graph.test.cpp
documentation_of: include/emthrm/graph/eulerian_trail_in_directed_graph.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/eulerian_trail_in_directed_graph.hpp
- /library/include/emthrm/graph/eulerian_trail_in_directed_graph.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\u30D5\u7248"
---
## オイラー路 (Eulerian trail)

グラフのすべての辺を一度だけ通る路である．


## 準オイラーグラフ (semi-Eulerian graph)

閉路でないオイラー路が存在するグラフである．

連結グラフ $G$ が準オイラーグラフである必要十分条件は
- $G$ が無向グラフのとき，奇数次数の頂点がちょうど $2$ 個存在することであり，
- $G$ が有向グラフのとき，相対出次数 $1$，相対入次数 $1$ の頂点が一つずつ存在し，他の頂点の相対次数が $0$ であることである．


## オイラーグラフ (Eulerian graph)

オイラー閉路 (Euler circuit) が存在するグラフである．

連結グラフ $G$ がオイラーグラフである必要十分条件は
- $G$ が無向グラフのとき，任意の頂点の次数が偶数であることであり，
- $G$ が有向グラフのとき，任意の頂点の相対次数が $0$ であることである．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- オイラー路 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`eulerian_trail_in_directed_graph(graph, s = -1)`|有向グラフ $\mathrm{graph}$ における始点 $s$ のオイラー路|存在しないときは空配列となる．|

- オイラー路 無向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`EulerianTrailInUndirectedGraph(n)`|頂点数 $N$ の無向グラフにおけるオイラー路を考える．||
|`trail`|オイラー路|存在しないときは空配列となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を加える．||
|`build(s = -1)`|始点 $s$ のオイラー路を構築できたか．||


## 参考

- https://kokiymgch.hatenablog.com/entry/2017/12/07/193238

オイラー路 有向グラフ版
- http://www.prefield.com/algorithm/graph/directed_euler_path.html

オイラー路 無向グラフ版
- https://github.com/spaghetti-source/algorithm/blob/2c70d7af4d132513fa699a5de5b2aaf21aaf7890/graph/eulerian_path_undirected.cc


## Verified

- [オイラー路 有向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0225/review/4082901/emthrm/C++14)
- [オイラー路 無向グラフ版](https://yukicoder.me/submissions/701541)
