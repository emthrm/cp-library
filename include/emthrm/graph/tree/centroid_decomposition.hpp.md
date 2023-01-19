---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_\n#define EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nstruct CentroidDecomposition {\n  int root;\n\
    \  std::vector<int> parent;\n  std::vector<std::vector<int>> g;\n\n  explicit\
    \ CentroidDecomposition(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : graph(graph) {\n    const int n = graph.size();\n    parent.assign(n,\
    \ -1);\n    g.resize(n);\n    is_alive.assign(n, true);\n    subtree.resize(n);\n\
    \    root = build(0);\n  }\n\n private:\n  std::vector<bool> is_alive;\n  std::vector<int>\
    \ subtree;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  int build(const\
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
    \    return ver;\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_TREE_CENTROID_DECOMPOSITION_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/centroid_decomposition.test.cpp
documentation_of: include/emthrm/graph/tree/centroid_decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
---

重心を基にした木の分解法の一つである。木上で分割統治法を行うときに有用である。


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 仕様

```cpp
template <typename CostType>
struct CentroidDecomposition;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`int root`|重心分解した木の根|
|`std::vector<int> parent`|`parent[i]` は `g` における頂点 $i$ の親を表す。ただし存在しないときは $-1$ となる。|
|`std::vector<std::vector<int>> g`|重心分解を行った木|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit CentroidDecomposition(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- http://compro.tsutajiro.com/archive/190207_divcon.pdf
- https://lumakernel.github.io/ecasdqina/graph/CentroidDecomposition


## TODO

- https://twitter.com/beet_aizu/status/1142651943971540992


## Submissons

https://judge.yosupo.jp/submission/12355
