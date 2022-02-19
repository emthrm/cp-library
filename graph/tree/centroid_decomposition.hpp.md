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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\n#include \"../edge.hpp\"\r\n\r\n\
    template <typename CostType>\r\nstruct CentroidDecomposition {\r\n  int root;\r\
    \n  std::vector<int> parent;\r\n  std::vector<std::vector<int>> g;\r\n\r\n  explicit\
    \ CentroidDecomposition(\r\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\r\n      : graph(graph) {\r\n    const int n = graph.size();\r\n    parent.assign(n,\
    \ -1);\r\n    g.resize(n);\r\n    is_alive.assign(n, true);\r\n    subtree.resize(n);\r\
    \n    root = build(0);\r\n  }\r\n\r\n private:\r\n  std::vector<bool> is_alive;\r\
    \n  std::vector<int> subtree;\r\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\r\n\r\n  int build(const int s) {\r\n    const int centroid = search_centroid(-1,\
    \ s, calc_subtree(-1, s) / 2);\r\n    is_alive[centroid] = false;\r\n    for (const\
    \ Edge<CostType>& e : graph[centroid]) {\r\n      if (is_alive[e.dst]) {\r\n \
    \       g[centroid].emplace_back(build(e.dst));\r\n        parent[e.dst] = centroid;\r\
    \n      }\r\n    }\r\n    is_alive[centroid] = true;\r\n    return centroid;\r\
    \n  }\r\n\r\n  int calc_subtree(const int par, const int ver) {\r\n    subtree[ver]\
    \ = 1;\r\n    for (const Edge<CostType>& e : graph[ver]) {\r\n      if (e.dst\
    \ != par && is_alive[e.dst]) {\r\n        subtree[ver] += calc_subtree(ver, e.dst);\r\
    \n      }\r\n    }\r\n    return subtree[ver];\r\n  }\r\n\r\n  int search_centroid(const\
    \ int par, const int ver, const int half) const {\r\n    for (const Edge<CostType>&\
    \ e : graph[ver]) {\r\n      if (e.dst != par && is_alive[e.dst] && subtree[e.dst]\
    \ > half) {\r\n        return search_centroid(ver, e.dst, half);\r\n      }\r\n\
    \    }\r\n    return ver;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2022-02-19 19:36:06+09:00'
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
