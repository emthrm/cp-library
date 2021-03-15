---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/eulerian_trail_in_directed_graph.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/**\r\n * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\u30D5\
    \u7248\r\n * @docs docs/graph/eulerian_trail.md\r\n */\r\n\r\n#pragma once\r\n\
    #include <algorithm>\r\n#include <functional>\r\n#include <vector>\r\n#include\
    \ \"edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstd::vector<int> eulerian_trail_in_directed_graph(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph, int s = -1) {\r\n  int n =\
    \ graph.size(), edges = 0;\r\n  std::vector<std::vector<Edge<CostType>>> tmp(graph);\r\
    \n  std::vector<int> deg(n, 0);\r\n  for (int i = 0; i < n; ++i) {\r\n    deg[i]\
    \ += tmp[i].size();\r\n    for (const Edge<CostType> &e : tmp[i]) --deg[e.dst];\r\
    \n    edges += tmp[i].size();\r\n  }\r\n  int not0 = n - std::count(deg.begin(),\
    \ deg.end(), 0);\r\n  if (s == -1) {\r\n    for (int i = 0; i < n; ++i) {\r\n\
    \      if (not0 == 0) {\r\n        if (!tmp[i].empty()) {\r\n          s = i;\r\
    \n          break;\r\n        }\r\n      } else if (not0 == 2) {\r\n        if\
    \ (deg[i] == 1) {\r\n          s = i;\r\n          break;\r\n        }\r\n   \
    \   }\r\n    }\r\n    if (s == -1) return {};\r\n  }\r\n  if (not0 == 0 || (not0\
    \ == 2 && deg[s] == 1)) {\r\n    std::vector<int> res;\r\n    std::function<void(int)>\
    \ dfs = [&tmp, &res, &dfs](int ver) {\r\n      while (!tmp[ver].empty()) {\r\n\
    \        int nx = tmp[ver].back().dst;\r\n        tmp[ver].pop_back();\r\n   \
    \     dfs(nx);\r\n      }\r\n      res.emplace_back(ver);\r\n    };\r\n    dfs(s);\r\
    \n    if (res.size() == edges + 1) {\r\n      std::reverse(res.begin(), res.end());\r\
    \n      return res;\r\n    }\r\n  }\r\n  return {};\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/eulerian_trail_in_directed_graph.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/eulerian_trail_in_directed_graph.test.cpp
documentation_of: graph/eulerian_trail_in_directed_graph.hpp
layout: document
redirect_from:
- /library/graph/eulerian_trail_in_directed_graph.hpp
- /library/graph/eulerian_trail_in_directed_graph.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\u30D5\u7248"
---
## オイラー路 (Eulerian trail)

グラフのすべての辺を一度だけ通る路である．


## 準オイラーグラフ (semi-Eulerian graph)

閉路でないオイラー路が存在するグラフである．

$$\text{準オイラーグラフ} \Leftrightarrow \begin{cases} \text{次数奇数の頂点がちょうど 2 個存在} & (\text{無向グラフ}) \\ \text{始点の相対出次数が 1, 終点の相対入次数が 1, 他の頂点の相対次数が 0} & (\text{有向グラフ}) \text{．} \end{cases}$$


## オイラーグラフ (Eulerian graph)

オイラー閉路 (Euler circuit) が存在するグラフである．

$$\text{オイラーグラフ} \Leftrightarrow \begin{cases} \text{任意の頂点の次数が偶数} & (\text{無向グラフ}) \\ \text{任意の頂点の相対次数が 0} & (\text{有向グラフ}) \text{．} \end{cases}$$


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- オイラー路 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`eulerian_trail_in_directed_graph(graph, s = -1)`|有向グラフ $\mathrm{graph}$，始点 $s$ のオイラー路|存在しない場合は空配列となる．|

- オイラー路 無向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`EulerianTrailInUndirectedGraph(n)`|頂点数 $N$ の無向グラフにおけるオイラー路||
|`trail`|オイラー路|存在しない場合は空配列となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を追加する．||
|`build(s = -1)`|始点 $s$ のオイラー路を構築できたか．|一度のみ．|


## 参考

- https://www.learning-algorithms.com/entry/2017/12/07/193238

オイラー路 有向グラフ版
- http://www.prefield.com/algorithm/graph/directed_euler_path.html

オイラー路 無向グラフ版
- https://github.com/spaghetti-source/algorithm/blob/2c70d7af4d132513fa699a5de5b2aaf21aaf7890/graph/eulerian_path_undirected.cc


## Verified

- [オイラー路 有向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0225/review/4082901/emthrm/C++14)
- [オイラー路 無向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0086/review/4579202/emthrm/C++14)
