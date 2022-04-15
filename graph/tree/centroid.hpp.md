---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/centroid.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <functional>\r\n#include\
    \ <vector>\r\n\r\n#include \"../edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\
    \nstd::vector<int> centroid(\r\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\r\n  const int n = graph.size();\r\n  std::vector<int> subtree(n, 1),\
    \ res;\r\n  const std::function<void(int, int)> dfs =\r\n      [&graph, n, &subtree,\
    \ &res, &dfs](const int par, const int ver) -> void {\r\n        bool is_centroid\
    \ = true;\r\n        for (const Edge<CostType>& e : graph[ver]) {\r\n        \
    \  if (e.dst != par) {\r\n            dfs(ver, e.dst);\r\n            subtree[ver]\
    \ += subtree[e.dst];\r\n            is_centroid &= subtree[e.dst] <= n / 2;\r\n\
    \          }\r\n        }\r\n        if (is_centroid && n - subtree[ver] <= n\
    \ / 2) res.emplace_back(ver);\r\n      };\r\n  dfs(-1, 0);\r\n  std::sort(res.begin(),\
    \ res.end());\r\n  return res;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/centroid.hpp
  requiredBy: []
  timestamp: '2022-02-15 13:02:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/centroid.test.cpp
documentation_of: graph/tree/centroid.hpp
layout: document
title: "\u91CD\u5FC3 (centroid)"
---

根としたときに任意の子の部分木の大きさが木の大きさの半分以下となる頂点である．

任意の木に必ず存在し，高々二つである．二つ存在するとき，木の頂点数は偶数である．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`centroid(graph)`|木 $\mathrm{graph}$ の重心|


## 参考

- https://qiita.com/drken/items/4b4c3f1824339b090202
- https://lumakernel.github.io/ecasdqina/graph/Centroid
- https://img.atcoder.jp/arc087/editorial.pdf


## Verified

https://atcoder.jp/contests/arc087/submissions/9306188
