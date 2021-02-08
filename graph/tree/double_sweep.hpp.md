---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/double_sweep.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/tree/diameter.md
    document_title: double sweep
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/tree/double_sweep.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief double sweep\r\n * @docs docs/graph/tree/diameter.md\r\n\
    \ */\r\n\r\n#pragma once\r\n#include <cassert>\r\n#include <tuple>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n#include \"../edge.hpp\"\r\n\r\ntemplate <typename\
    \ CostType>\r\nstruct DoubleSweep {\r\n  int s = -1, t;\r\n  CostType diameter;\r\
    \n  std::vector<int> path;\r\n\r\n  DoubleSweep(const std::vector<std::vector<Edge<CostType>>>\
    \ &graph) : graph(graph) {\r\n    s = dfs1(-1, 0).second;\r\n    std::tie(diameter,\
    \ t) = dfs1(-1, s);\r\n  }\r\n\r\n  void build_path() {\r\n    assert(s != -1);\r\
    \n    path.emplace_back(s);\r\n    dfs2(-1, s);\r\n  }\r\n\r\nprivate:\r\n  using\
    \ Pci = std::pair<CostType, int>;\r\n\r\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\r\n\r\n  Pci dfs1(int par, int ver) {\r\n    Pci res = {0, ver};\r\n\
    \    for (const Edge<CostType> &e : graph[ver]) {\r\n      if (e.dst != par) {\r\
    \n        Pci pr = dfs1(ver, e.dst);\r\n        pr.first += e.cost;\r\n      \
    \  if (pr.first > res.first) res = pr;\r\n      }\r\n    }\r\n    return res;\r\
    \n  }\r\n\r\n  bool dfs2(int par, int ver) {\r\n    if (ver == t) return true;\r\
    \n    for (const Edge<CostType> &e : graph[ver]) {\r\n      if (e.dst != par)\
    \ {\r\n        path.emplace_back(e.dst);\r\n        if (dfs2(ver, e.dst)) return\
    \ true;\r\n        path.pop_back();\r\n      }\r\n    }\r\n    return false;\r\
    \n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/double_sweep.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/double_sweep.test.cpp
documentation_of: graph/tree/double_sweep.hpp
layout: document
redirect_from:
- /library/graph/tree/double_sweep.hpp
- /library/graph/tree/double_sweep.hpp.html
title: double sweep
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
