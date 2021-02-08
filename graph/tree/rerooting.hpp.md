---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/rerooting.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6728\u306E\u76F4\u5F84 \u5168\u65B9\u4F4D\u6728\
      \ DP \u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/tree/diameter.md
    document_title: "\u6728\u306E\u76F4\u5F84 \u5168\u65B9\u4F4D\u6728 DP \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/tree/rerooting.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u6728\u306E\u76F4\u5F84 \u5168\u65B9\u4F4D\u6728 DP \u7248\
    \r\n * @docs docs/graph/tree/diameter.md\r\n */\r\n\r\n#pragma once\r\n#include\
    \ <algorithm>\r\n#include <functional>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"../edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nCostType rerooting(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph) {\r\n  int n = graph.size();\r\
    \n  std::vector<CostType> dist(n, 0);\r\n  std::vector<std::vector<std::pair<CostType,\
    \ int>>> children(n);\r\n  std::function<void(int, int)> dfs1 = [&graph, &dist,\
    \ &children, &dfs1](int par, int ver) -> void {\r\n    for (const Edge<CostType>\
    \ &e : graph[ver]) {\r\n      if (e.dst != par) {\r\n        dfs1(ver, e.dst);\r\
    \n        if (dist[e.dst] + e.cost > dist[ver]) dist[ver] = dist[e.dst] + e.cost;\r\
    \n        children[ver].emplace_back(dist[e.dst] + e.cost, e.dst);\r\n      }\r\
    \n    }\r\n  };\r\n  dfs1(-1, 0);\r\n  std::vector<CostType> dp(n);\r\n  std::function<void(int,\
    \ int, CostType)> dfs2 = [&graph, &children, &dp, &dfs2](int par, int ver, CostType\
    \ par_dp) -> void {\r\n    if (par != -1) children[ver].emplace_back(par_dp, par);\r\
    \n    std::sort(children[ver].begin(), children[ver].end(), std::greater<std::pair<CostType,\
    \ int>>());\r\n    if (children[ver].size() == 1) {\r\n      dp[ver] = children[ver].front().first;\r\
    \n      if (par == -1) {\r\n        const Edge<CostType> &e = graph[ver].front();\r\
    \n        dfs2(ver, e.dst, e.cost);\r\n      }\r\n    } else {\r\n      dp[ver]\
    \ = children[ver][0].first + children[ver][1].first;\r\n      for (const Edge<CostType>\
    \ &e : graph[ver]) {\r\n        if (e.dst != par) dfs2(ver, e.dst, children[ver][children[ver][0].second\
    \ == e.dst ? 1 : 0].first + e.cost);\r\n      }\r\n    }\r\n  };\r\n  if (n ==\
    \ 1) {\r\n    dp[0] = 0;\r\n  } else {\r\n    dfs2(-1, 0, 0);\r\n  }\r\n  return\
    \ *std::max_element(dp.begin(), dp.end());\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/rerooting.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/rerooting.test.cpp
documentation_of: graph/tree/rerooting.hpp
layout: document
redirect_from:
- /library/graph/tree/rerooting.hpp
- /library/graph/tree/rerooting.hpp.html
title: "\u6728\u306E\u76F4\u5F84 \u5168\u65B9\u4F4D\u6728 DP \u7248"
---
# 木の直径

木の最遠頂点間の距離である．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

- double sweep

||説明|備考|
|:--:|:--:|:--:|
|`DoubleSweep(graph)`|グラフ $\mathrm{graph}$ の木の直径を構築する．||
|(`s`, `t`)|最遠頂点対||
|`diameter`|木の直径の長さ||
|`path`|直径|`build_path()` を呼び出しておかなければならない．|

- 全方位木 DP 版

||説明|
|:--:|:--:|
|`rerooting(graph)`|グラフ $\mathrm{graph}$ の木の直径の長さ||


## 参考

double sweep
- http://www.prefield.com/algorithm/graph/tree_diameter.html

全方位木 DP 版
- https://ei1333.hateblo.jp/entry/2017/04/10/224413


## ToDo

- 頂点の重みを基にした直径
  - https://github.com/beet-aizu/library/blob/master/tree/diameterforvertex.cpp
- 全方位木 DP の考え方
  - https://twitter.com/snuke_/status/1018052021985792000
- 全方位木 DP の抽象化
  - https://ei1333.hateblo.jp/entry/2018/12/21/004022


## Verified

* [double sweep](https://codeforces.com/contest/1182/submission/67997368)
* [全方位木 DP 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_A/review/4083771/emthrm/C++14)
