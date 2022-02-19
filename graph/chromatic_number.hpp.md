---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/chromatic_number.test.cpp
    title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
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
  code: "#pragma once\r\n#include <vector>\r\n\r\n#include \"edge.hpp\"\r\n\r\ntemplate\
    \ <typename CostType>\r\nint chromatic_number(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\r\n  const int n = graph.size();\r\n  std::vector<int> adj(n, 0);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    for (const Edge<CostType>& e : graph[i])\
    \ adj[i] |= 1 << e.dst;\r\n  }\r\n  std::vector<int> indep(1 << n);\r\n  indep[0]\
    \ = 1;\r\n  for (int i = 1; i < (1 << n); ++i) {\r\n    const int v = __builtin_ctz(i);\r\
    \n    indep[i] = indep[i ^ (1 << v)] + indep[(i ^ (1 << v)) & ~adj[v]];\r\n  }\r\
    \n  int res = n;\r\n  for (const int mod : std::vector<int>{1000000007, 1000000011})\
    \ {\r\n    std::vector<long long> f(1 << n);\r\n    for (int i = 0; i < (1 <<\
    \ n); ++i) {\r\n      f[i] = ((n - __builtin_popcount(i)) & 1 ? mod - 1 : 1);\r\
    \n    }\r\n    for (int c = 1; c < res; ++c) {\r\n      long long pat = 0;\r\n\
    \      for (int i = 0; i < (1 << n); ++i) {\r\n        f[i] = (f[i] * indep[i])\
    \ % mod;\r\n        pat += f[i];\r\n      }\r\n      if (pat % mod > 0) {\r\n\
    \        res = c;\r\n        break;\r\n      }\r\n    }\r\n  }\r\n  return res;\r\
    \n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2022-02-15 21:43:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/chromatic_number.test.cpp
documentation_of: graph/chromatic_number.hpp
layout: document
title: "\u5F69\u8272\u6570 (chromatic number)"
---

隣接頂点間で色が異なるような頂点彩色に必要な最小の色の数である．


## 時間計算量

$O(2^{\lvert V \rvert} \lvert V \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`chromatic_number(graph)`|無向グラフ $\mathrm{graph}$ の彩色数|


## 参考

- https://www.slideshare.net/wata_orz/ss-12131479
- http://drken1215.hatenablog.com/entry/2019/01/16/030000
- https://www.learning-algorithms.com/entry/2018/01/27/235959
- https://github.com/spaghetti-source/algorithm/blob/b541e0b06aa4145592527b7de8e2caa8720bac22/graph/chromatic_number.cc


## ToDo

- 高速化
  - https://www.mathenachia.blog/chromatic-fast/
  - https://atcoder.jp/contests/abc056/editorial/2092
- 二部グラフの辺彩色
  - https://ei1333.hateblo.jp/entry/2020/08/25/015955
  - https://37zigen.com/noga-alon-edge-coloring-bipartite/
  - https://github.com/yosupo06/library-checker-problems/issues/393
  - https://twitter.com/snuke_/status/1246630370415538176
  - https://twitter.com/noshi91/status/1247010856040165377
  - https://github.com/ei1333/library/blob/master/structure/union-find/bipartite-graph.cpp
  - http://www.prefield.com/algorithm/graph/bipartite_coloring.html
  - https://judge.yosupo.jp/problem/bipartite_edge_coloring
  - https://yukicoder.me/problems/no/3071
- 彩色多項式
  - https://github.com/eandbsoftware/libraryCPP/blob/master/%23ChromaticPolynomial.cpp


## Verified

https://judge.yosupo.jp/submission/40942
