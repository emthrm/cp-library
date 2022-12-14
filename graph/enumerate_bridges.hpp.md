---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/2-edge-connected_components_by_imos.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\u3082\u3059\
      \u6CD5\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/2-edge-connected_components_by_imos.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ \u3044\u3082\u3059\u6CD5\u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/enumerate_bridges.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u5217\u6319"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include <algorithm>\n#include <functional>\n#include <vector>\n\
    \n#include \"./edge.hpp\"\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>>\
    \ enumerate_bridges(\n    const std::vector<std::vector<Edge<CostType>>>& graph)\
    \ {\n  const int n = graph.size();\n  std::vector<Edge<CostType>> res;\n  std::vector<int>\
    \ depth(n, -1), imos(n, 0);\n  const std::function<void(int, int)> dfs = [&graph,\
    \ &res, &depth, &imos, &dfs](\n      const int par, const int ver) -> void {\n\
    \    bool has_multiple_edges = false;\n    for (const Edge<CostType>& e : graph[ver])\
    \ {\n      if (depth[e.dst] == -1) {\n        depth[e.dst] = depth[ver] + 1;\n\
    \        dfs(ver, e.dst);\n        if (imos[e.dst] == 0) {\n          res.emplace_back(std::min(ver,\
    \ e.dst), std::max(ver, e.dst), e.cost);\n        }\n        imos[ver] += imos[e.dst];\n\
    \      } else if (!has_multiple_edges && e.dst == par) {\n        has_multiple_edges\
    \ = true;\n      } else if (depth[e.dst] < depth[ver]) {\n        ++imos[ver];\n\
    \        --imos[e.dst];\n      }\n    }\n  };\n  for (int i = 0; i < n; ++i) {\n\
    \    if (depth[i] == -1) {\n      depth[i] = 0;\n      dfs(-1, i);\n    }\n  }\n\
    \  return res;\n}\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/enumerate_bridges.hpp
  requiredBy:
  - graph/2-edge-connected_components_by_imos.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/enumerate_bridges.test.cpp
  - test/graph/2-edge-connected_components_by_imos.test.cpp
documentation_of: graph/enumerate_bridges.hpp
layout: document
title: "\u6A4B\u306E\u691C\u51FA"
---


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`enumerate_bridges(graph)`|無向グラフ $\mathrm{graph}$ の橋|


## 参考

- https://www.slideshare.net/chokudai/arc039


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082847/emthrm/C++14
