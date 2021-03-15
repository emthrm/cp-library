---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/noshi_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"edge.hpp\"\r\n\r\ntemplate\
    \ <typename CostType>\r\nstruct NoshiGraph {\r\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\r\n\r\n  NoshiGraph(int n) {\r\n    while (p2 < n) p2 <<= 1;\r\n    int\
    \ doub = p2 << 1, half = p2 >> 1;\r\n    graph.resize(doub + p2);\r\n    for (int\
    \ i = 1; i < half; ++i) {\r\n      graph[i + p2].emplace_back(i + p2, (i << 1)\
    \ + p2, 0);\r\n      graph[i + p2].emplace_back(i + p2, (i << 1) + p2 + 1, 0);\r\
    \n      graph[(i << 1) + doub].emplace_back((i << 1) + doub, i + doub, 0);\r\n\
    \      graph[(i << 1) + doub + 1].emplace_back((i << 1) + doub + 1, i + doub,\
    \ 0);\r\n    }\r\n    for (int src = p2 + half, dst = 0; dst < p2; ++src, dst\
    \ += 2) {\r\n      graph[src].emplace_back(src, dst, 0);\r\n      graph[src].emplace_back(src,\
    \ dst + 1, 0);\r\n    }\r\n    for (int src = doub + half, dst = 0; dst < p2;\
    \ ++src, dst += 2) {\r\n      graph[dst].emplace_back(dst, src, 0);\r\n      graph[dst\
    \ + 1].emplace_back(dst + 1, src, 0);\r\n    }\r\n  }\r\n\r\n  void add_edge(int\
    \ src, int dst, CostType cost) {\r\n    graph[src].emplace_back(src, dst, cost);\r\
    \n  }\r\n\r\n  void add_edge(int src_l, int src_r, int dst_l, int dst_r, CostType\
    \ cost) {\r\n    if (src_r <= src_l || dst_r <= dst_l) return;\r\n    int src_id\
    \ = graph.size(), dst_id = src_id + 1;\r\n    graph.resize(graph.size() + 2);\r\
    \n    if ((dst_l += p2) & 1) graph[dst_id].emplace_back(dst_id, dst_l++ - p2,\
    \ 0);\r\n    if ((dst_r += p2) & 1) graph[dst_id].emplace_back(dst_id, --dst_r\
    \ - p2, 0);\r\n    for (dst_l >>= 1, dst_r >>= 1; dst_l < dst_r; dst_l >>= 1,\
    \ dst_r >>= 1) {\r\n      if (dst_l & 1) graph[dst_id].emplace_back(dst_id, dst_l++\
    \ + p2, 0);\r\n      if (dst_r & 1) graph[dst_id].emplace_back(dst_id, --dst_r\
    \ + p2, 0);\r\n    }\r\n    graph[src_id].emplace_back(src_id, dst_id, cost);\r\
    \n    if ((src_l += p2) & 1) {\r\n      int src = src_l++ - p2;\r\n      graph[src].emplace_back(src,\
    \ src_id, 0);\r\n    }\r\n    if ((src_r += p2) & 1) {\r\n      int src = --src_r\
    \ - p2;\r\n      graph[src].emplace_back(src, src_id, 0);\r\n    }\r\n    for\
    \ (src_l >>= 1, src_r >>= 1; src_l < src_r; src_l >>= 1, src_r >>= 1) {\r\n  \
    \    if (src_l & 1) {\r\n        int src = src_l++ + (p2 << 1);\r\n        graph[src].emplace_back(src,\
    \ src_id, 0);\r\n      }\r\n      if (src_r & 1) {\r\n        int src = --src_r\
    \ + (p2 << 1);\r\n        graph[src].emplace_back(src, src_id, 0);\r\n      }\r\
    \n    }\r\n  }\r\n\r\nprivate:\r\n  int p2 = 1;\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/noshi_graph.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/noshi_graph.test.cpp
documentation_of: graph/noshi_graph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---


## 時間計算量

$O(\log{\lvert V \rvert})$


## 使用法

||説明|
|:--:|:--:|
|`NoshiGraph<CostType>(n)`|頂点数 $n$ のグラフを考える．|
|`add_edge(src, dst, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, コスト $\mathrm{cost}$ の辺を張る．|
|`add_edge(src_l, src_r, dst_l, dst_r, cost)`|始点 $s \in \lbrack \mathrm{src\_l}, \mathrm{src\_r})$, 終点 $t \in \lbrack \mathrm{dst\_l}, \mathrm{dst\_r})$, コスト $\mathrm{cost}$ の辺を張る．|


## 参考

- https://twitter.com/noshi91/status/1193177214453338113
- https://twitter.com/noshi91/status/1272380264396648448
- https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656


## Verified

https://codeforces.com/contest/786/submission/100222769
