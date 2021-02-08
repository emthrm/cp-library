---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/centroid_decomposition.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"../edge.hpp\"\r\n\r\ntemplate\
    \ <typename CostType>\r\nstruct CentroidDecomposition {\r\n  int root;\r\n  std::vector<std::vector<int>>\
    \ comp;\r\n  std::vector<int> par;\r\n\r\n  CentroidDecomposition(const std::vector<std::vector<Edge<CostType>>>\
    \ &graph) : graph(graph) {\r\n    int n = graph.size();\r\n    alive.assign(n,\
    \ true);\r\n    subtree.resize(n);\r\n    comp.resize(n);\r\n    par.assign(n,\
    \ -1);\r\n    root = build(0);\r\n  }\r\n\r\nprivate:\r\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\r\n  std::vector<bool> alive;\r\n  std::vector<int> subtree;\r\n\r\n\
    \  int build(int s) {\r\n    int centroid = search_centroid(-1, s, calc_subtree(-1,\
    \ s) / 2);\r\n    alive[centroid] = false;\r\n    for (const Edge<CostType> &e\
    \ : graph[centroid]) {\r\n      if (alive[e.dst]) {\r\n        comp[centroid].emplace_back(build(e.dst));\r\
    \n        par[e.dst] = centroid;\r\n      }\r\n    }\r\n    alive[centroid] =\
    \ true;\r\n    return centroid;\r\n  }\r\n\r\n  int calc_subtree(int par, int\
    \ ver) {\r\n    subtree[ver] = 1;\r\n    for (const Edge<CostType> &e : graph[ver])\
    \ {\r\n      if (e.dst != par && alive[e.dst]) subtree[ver] += calc_subtree(ver,\
    \ e.dst);\r\n    }\r\n    return subtree[ver];\r\n  }\r\n\r\n  int search_centroid(int\
    \ par, int ver, int half) const {\r\n    for (const Edge<CostType> &e : graph[ver])\
    \ {\r\n      if (e.dst != par && alive[e.dst] && subtree[e.dst] > half) return\
    \ search_centroid(ver, e.dst, half);\r\n    }\r\n    return ver;\r\n  }\r\n};\r\
    \n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/centroid_decomposition.test.cpp
documentation_of: graph/tree/centroid_decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
---

木上で分割統治法を行う際に有用な重心を基にした木の分解方法である．


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`CentroidDecomposition<CostType>(graph)`|木 $\mathrm{graph}$ の重心分解を考える．||
|`root`|重心分解した木の根||
|`comp`|重心分解を行った木||
|`par[i]`|`comp` における頂点 $i$ の親|存在しない場合は $-1$ となる．|


## 参考

- http://compro.tsutajiro.com/archive/190207_divcon.pdf
- https://lumakernel.github.io/ecasdqina/graph/CentroidDecomposition


## ToDo

- https://twitter.com/beet_aizu/status/1142651943971540992


## Verified

https://judge.yosupo.jp/submission/12355
