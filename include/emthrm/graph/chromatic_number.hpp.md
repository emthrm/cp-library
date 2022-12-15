---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_\n#define EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nint chromatic_number(const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\n  const int n = graph.size();\n  std::vector<int> adj(n, 0);\n  for\
    \ (int i = 0; i < n; ++i) {\n    for (const Edge<CostType>& e : graph[i]) adj[i]\
    \ |= 1 << e.dst;\n  }\n  std::vector<int> indep(1 << n);\n  indep[0] = 1;\n  for\
    \ (int i = 1; i < (1 << n); ++i) {\n    const int v = __builtin_ctz(i);\n    indep[i]\
    \ = indep[i ^ (1 << v)] + indep[(i ^ (1 << v)) & ~adj[v]];\n  }\n  int res = n;\n\
    \  for (const int mod : std::vector<int>{1000000007, 1000000011}) {\n    std::vector<long\
    \ long> f(1 << n);\n    for (int i = 0; i < (1 << n); ++i) {\n      f[i] = ((n\
    \ - __builtin_popcount(i)) & 1 ? mod - 1 : 1);\n    }\n    for (int c = 1; c <\
    \ res; ++c) {\n      long long pat = 0;\n      for (int i = 0; i < (1 << n); ++i)\
    \ {\n        f[i] = (f[i] * indep[i]) % mod;\n        pat += f[i];\n      }\n\
    \      if (pat % mod > 0) {\n        res = c;\n        break;\n      }\n    }\n\
    \  }\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_CHROMATIC_NUMBER_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/chromatic_number.test.cpp
documentation_of: include/emthrm/graph/chromatic_number.hpp
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


## TODO

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
