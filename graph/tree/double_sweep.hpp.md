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
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <functional>\r\n#include <tuple>\r\
    \n#include <utility>\r\n#include <vector>\r\n#include \"../edge.hpp\"\r\n\r\n\
    template <typename CostType>\r\nstd::pair<CostType, std::vector<int>> double_sweep(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph) {\r\n  std::function<std::pair<CostType,\
    \ int>(int, int)> dfs1 = [&graph, &dfs1](int par, int ver) -> std::pair<CostType,\
    \ int> {\r\n    std::pair<CostType, int> res = {0, ver};\r\n    for (const Edge<CostType>\
    \ &e : graph[ver]) {\r\n      if (e.dst != par) {\r\n        std::pair<CostType,\
    \ int> pr = dfs1(ver, e.dst);\r\n        pr.first += e.cost;\r\n        if (pr.first\
    \ > res.first) res = pr;\r\n      }\r\n    }\r\n    return res;\r\n  };\r\n  int\
    \ s = dfs1(-1, 0).second;\r\n  CostType diameter;\r\n  int t;\r\n  std::tie(diameter,\
    \ t) = dfs1(-1, s);\r\n  std::vector<int> path{s};\r\n  std::function<bool(int,\
    \ int)> dfs2 = [&graph, &t, &path, &dfs2](int par, int ver) -> bool {\r\n    if\
    \ (ver == t) return true;\r\n    for (const Edge<CostType> &e : graph[ver]) {\r\
    \n      if (e.dst != par) {\r\n        path.emplace_back(e.dst);\r\n        if\
    \ (dfs2(ver, e.dst)) return true;\r\n        path.pop_back();\r\n      }\r\n \
    \   }\r\n    return false;\r\n  };\r\n  assert(dfs2(-1, s));\r\n  return {diameter,\
    \ path};\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/double_sweep.hpp
  requiredBy: []
  timestamp: '2021-02-24 23:50:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/double_sweep.test.cpp
documentation_of: graph/tree/double_sweep.hpp
layout: document
title: double sweep
---

木の直径を求めるアルゴリズムである．


### 木の直径

木の最遠頂点間の距離である．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`double_sweep(graph)`|グラフ $\mathrm{graph}$ の直径の長さと直径|


## 参考

- http://www.prefield.com/algorithm/graph/tree_diameter.html


## ToDo

- 頂点の重みを基にした直径
  - https://github.com/beet-aizu/library/blob/master/tree/diameterforvertex.cpp


## Verified

https://judge.yosupo.jp/submission/40074
