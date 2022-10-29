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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include <vector>\n\n#include \"../edge.hpp\"\n\ntemplate <typename\
    \ CostType>\nstruct CentroidDecomposition {\n  int root;\n  std::vector<int> parent;\n\
    \  std::vector<std::vector<int>> g;\n\n  explicit CentroidDecomposition(\n   \
    \   const std::vector<std::vector<Edge<CostType>>>& graph)\n      : graph(graph)\
    \ {\n    const int n = graph.size();\n    parent.assign(n, -1);\n    g.resize(n);\n\
    \    is_alive.assign(n, true);\n    subtree.resize(n);\n    root = build(0);\n\
    \  }\n\n private:\n  std::vector<bool> is_alive;\n  std::vector<int> subtree;\n\
    \  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  int build(const\
    \ int s) {\n    const int centroid = search_centroid(-1, s, calc_subtree(-1, s)\
    \ / 2);\n    is_alive[centroid] = false;\n    for (const Edge<CostType>& e : graph[centroid])\
    \ {\n      if (is_alive[e.dst]) {\n        g[centroid].emplace_back(build(e.dst));\n\
    \        parent[e.dst] = centroid;\n      }\n    }\n    is_alive[centroid] = true;\n\
    \    return centroid;\n  }\n\n  int calc_subtree(const int par, const int ver)\
    \ {\n    subtree[ver] = 1;\n    for (const Edge<CostType>& e : graph[ver]) {\n\
    \      if (e.dst != par && is_alive[e.dst]) {\n        subtree[ver] += calc_subtree(ver,\
    \ e.dst);\n      }\n    }\n    return subtree[ver];\n  }\n\n  int search_centroid(const\
    \ int par, const int ver, const int half) const {\n    for (const Edge<CostType>&\
    \ e : graph[ver]) {\n      if (e.dst != par && is_alive[e.dst] && subtree[e.dst]\
    \ > half) {\n        return search_centroid(ver, e.dst, half);\n      }\n    }\n\
    \    return ver;\n  }\n};\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/centroid_decomposition.test.cpp
documentation_of: graph/tree/centroid_decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
---

重心を基にした木の分解法の一つである．木上で分割統治法を行うときに有用である．


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`CentroidDecomposition<CostType>(graph)`|木 $\mathrm{graph}$ の重心分解を考える．||
|`root`|重心分解した木の根||
|`parent[i]`|`g` における頂点 $i$ の親|存在しないときは $-1$ となる．|
|`g`|重心分解を行った木||


## 参考

- http://compro.tsutajiro.com/archive/190207_divcon.pdf
- https://lumakernel.github.io/ecasdqina/graph/CentroidDecomposition


## ToDo

- https://twitter.com/beet_aizu/status/1142651943971540992


## Verified

https://judge.yosupo.jp/submission/12355
