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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <functional>\r\n#include\
    \ <vector>\r\n\r\n#include \"./edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\
    \nstd::vector<Edge<CostType>> enumerate_bridges(\r\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\r\n  const int n = graph.size();\r\n  std::vector<Edge<CostType>> res;\r\
    \n  std::vector<int> depth(n, -1), imos(n, 0);\r\n  const std::function<void(int,\
    \ int)> dfs = [&graph, &res, &depth, &imos, &dfs](\r\n      const int par, const\
    \ int ver) -> void {\r\n    bool has_multiple_edges = false;\r\n    for (const\
    \ Edge<CostType>& e : graph[ver]) {\r\n      if (depth[e.dst] == -1) {\r\n   \
    \     depth[e.dst] = depth[ver] + 1;\r\n        dfs(ver, e.dst);\r\n        if\
    \ (imos[e.dst] == 0) {\r\n          res.emplace_back(std::min(ver, e.dst), std::max(ver,\
    \ e.dst), e.cost);\r\n        }\r\n        imos[ver] += imos[e.dst];\r\n     \
    \ } else if (!has_multiple_edges && e.dst == par) {\r\n        has_multiple_edges\
    \ = true;\r\n      } else if (depth[e.dst] < depth[ver]) {\r\n        ++imos[ver];\r\
    \n        --imos[e.dst];\r\n      }\r\n    }\r\n  };\r\n  for (int i = 0; i <\
    \ n; ++i) {\r\n    if (depth[i] == -1) {\r\n      depth[i] = 0;\r\n      dfs(-1,\
    \ i);\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/enumerate_bridges.hpp
  requiredBy:
  - graph/2-edge-connected_components_by_imos.hpp
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/2-edge-connected_components_by_imos.test.cpp
  - test/graph/enumerate_bridges.test.cpp
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
