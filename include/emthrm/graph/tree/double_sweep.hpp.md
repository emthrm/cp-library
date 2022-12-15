---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_\n#define EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_\n\
    \n#include <cassert>\n#include <functional>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename CostType>\nstd::pair<CostType, std::vector<int>> double_sweep(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph) {\n  const std::function<std::pair<CostType,\
    \ int>(int, int)> dfs1 =\n      [&graph, &dfs1](const int par, const int ver)\n\
    \          -> std::pair<CostType, int> {\n        std::pair<CostType, int> res{0,\
    \ ver};\n        for (const Edge<CostType>& e : graph[ver]) {\n          if (e.dst\
    \ != par) {\n            std::pair<CostType, int> child = dfs1(ver, e.dst);\n\
    \            child.first += e.cost;\n            if (child.first > res.first)\
    \ res = child;\n          }\n        }\n        return res;\n      };\n  const\
    \ int s = dfs1(-1, 0).second;\n  CostType diameter;\n  int t;\n  std::tie(diameter,\
    \ t) = dfs1(-1, s);\n  std::vector<int> path{s};\n  const std::function<bool(int,\
    \ int)> dfs2 =\n      [&graph, t, &path, &dfs2](const int par, const int ver)\
    \ -> bool {\n        if (ver == t) return true;\n        for (const Edge<CostType>&\
    \ e : graph[ver]) {\n          if (e.dst != par) {\n            path.emplace_back(e.dst);\n\
    \            if (dfs2(ver, e.dst)) return true;\n            path.pop_back();\n\
    \          }\n        }\n        return false;\n      };\n  assert(dfs2(-1, s));\n\
    \  return {diameter, path};\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_TREE_DOUBLE_SWEEP_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/tree/double_sweep.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/double_sweep.test.cpp
documentation_of: include/emthrm/graph/tree/double_sweep.hpp
layout: document
title: double sweep
---

木の直径を求めるアルゴリズムである．


### 木の直径

木の最遠頂点間距離である．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`double_sweep(graph)`|グラフ $\mathrm{graph}$ の直径とその経路|


## 参考

- http://www.prefield.com/algorithm/graph/tree_diameter.html


## TODO

- 頂点の重みを基にした直径
  - https://github.com/beet-aizu/library/blob/master/tree/diameterforvertex.cpp


## Verified

https://judge.yosupo.jp/submission/40074
