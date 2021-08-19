---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/union-find/undoable_union-find.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD union-find"
  - icon: ':x:'
    path: test/graph/is_bipartite.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <functional>\r\n#include <vector>\r\n#include \"\
    edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nbool is_bipartite(const std::vector<std::vector<Edge<CostType>>>\
    \ &graph, std::vector<int> &color) {\r\n  int n = graph.size();\r\n  color.assign(n,\
    \ -1);\r\n  std::function<bool(int, int)> dfs = [&graph, &color, &dfs](int ver,\
    \ int now) -> bool {\r\n    color[ver] = now;\r\n    for (const Edge<CostType>\
    \ &e : graph[ver]) {\r\n      if (color[e.dst] == now || (color[e.dst] == -1 &&\
    \ !dfs(e.dst, now ^ 1))) return false;\r\n    }\r\n    return true;\r\n  };\r\n\
    \  for (int i = 0; i < n; ++i) {\r\n    if (color[i] == -1 && !dfs(i, 0)) return\
    \ false;\r\n  }\r\n  return true;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/is_bipartite.hpp
  requiredBy: []
  timestamp: '2021-02-11 00:27:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/is_bipartite.test.cpp
  - test/data_structure/union-find/undoable_union-find.test.cpp
documentation_of: graph/is_bipartite.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---


### 二部グラフ (bipartite graph)

- 各部分集合内の頂点間で辺が存在しないよう，頂点集合を二つの部分集合に分割できるグラフである．
- [彩色数](chromatic_number.md)$2$のグラフである．
- 奇数長の閉路を含まないグラフである．

これらはすべて同値である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`is_bipartite(graph, color)`|グラフ $\mathrm{graph}$ は二部グラフであるか．|$\mathrm{color} \in {\lbrace 0, 1 \rbrace}^N$ は各頂点の色を表す．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.93-94，マイナビ出版（2012）．


## Verified

https://atcoder.jp/contests/code-festival-2017-qualb/submissions/9246218
