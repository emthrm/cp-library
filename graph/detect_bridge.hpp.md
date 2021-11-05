---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/2-edge-connected_components_imos.hpp
    title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\u3082\u3059\
      \u6CD5\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/2-edge-connected_components_imos.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
      \ \u3044\u3082\u3059\u6CD5\u7248"
  - icon: ':heavy_check_mark:'
    path: test/graph/detect_bridge.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u691C\u51FA"
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
  code: "#pragma once\r\n#include <algorithm>\r\n#include <functional>\r\n#include\
    \ <vector>\r\n#include \"edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstd::vector<Edge<CostType>>\
    \ detect_bridge(const std::vector<std::vector<Edge<CostType>>> &graph) {\r\n \
    \ int n = graph.size();\r\n  std::vector<Edge<CostType>> res;\r\n  std::vector<int>\
    \ depth(n, -1), imos(n, 0);\r\n  std::function<void(int, int)> dfs = [&graph,\
    \ &res, &depth, &imos, &dfs](int par, int ver) -> void {\r\n    bool multiedge\
    \ = false;\r\n    for (const Edge<CostType> &e : graph[ver]) {\r\n      if (depth[e.dst]\
    \ == -1) {\r\n        depth[e.dst] = depth[ver] + 1;\r\n        dfs(ver, e.dst);\r\
    \n        if (imos[e.dst] == 0) res.emplace_back(std::min(ver, e.dst), std::max(ver,\
    \ e.dst), e.cost);\r\n        imos[ver] += imos[e.dst];\r\n      } else if (!multiedge\
    \ && e.dst == par) {\r\n        multiedge = true;\r\n      } else if (depth[e.dst]\
    \ < depth[ver]) {\r\n        ++imos[ver];\r\n        --imos[e.dst];\r\n      }\r\
    \n    }\r\n  };\r\n  for (int i = 0; i < n; ++i) {\r\n    if (depth[i] == -1)\
    \ {\r\n      depth[i] = 0;\r\n      dfs(-1, i);\r\n    }\r\n  }\r\n  // std::sort(res.begin(),\
    \ res.end(), [](const Edge<CostType> &a, const Edge<CostType> &b) -> bool {\r\n\
    \  //   return a.src != b.src ? a.src < b.src : a.dst != b.dst ? a.dst < b.dst\
    \ : a.cost < b.cost;\r\n  // });\r\n  return res;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/detect_bridge.hpp
  requiredBy:
  - graph/2-edge-connected_components_imos.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/detect_bridge.test.cpp
  - test/graph/2-edge-connected_components_imos.test.cpp
documentation_of: graph/detect_bridge.hpp
layout: document
title: "\u6A4B\u306E\u691C\u51FA"
---


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`detect_bridge(graph)`|無向グラフ $\mathrm{graph}$ の橋|


## 参考

- https://www.slideshare.net/chokudai/arc039


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082847/emthrm/C++14
