---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/is_bipartite.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
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
  code: "#ifndef EMTHRM_GRAPH_IS_BIPARTITE_HPP_\n#define EMTHRM_GRAPH_IS_BIPARTITE_HPP_\n\
    \n#include <functional>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nbool is_bipartite(const\
    \ std::vector<std::vector<Edge<CostType>>>& graph,\n                  std::vector<int>*\
    \ color) {\n  const int n = graph.size();\n  color->assign(n, -1);\n  const std::function<bool(int,\
    \ int)> dfs = [&graph, &color, &dfs](\n      const int ver, const int c) -> bool\
    \ {\n    (*color)[ver] = c;\n    for (const Edge<CostType>& e : graph[ver]) {\n\
    \      if ((*color)[e.dst] == c ||\n          ((*color)[e.dst] == -1 && !dfs(e.dst,\
    \ c ^ 1))) {\n        return false;\n      }\n    }\n    return true;\n  };\n\
    \  for (int i = 0; i < n; ++i) {\n    if ((*color)[i] == -1 && !dfs(i, 0)) {\n\
    \      color->clear();\n      return false;\n    }\n  }\n  return true;\n}\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_IS_BIPARTITE_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/is_bipartite.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/is_bipartite.test.cpp
documentation_of: include/emthrm/graph/is_bipartite.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---


### 二部グラフ (bipartite graph)

- 各部分集合内の頂点間で辺が存在しないように，頂点集合を二つの部分集合に分割できるグラフである．
- [彩色数](chromatic_number.md) $2$ のグラフである．
- 奇数長の閉路を含まないグラフである．

これらはすべて同値である．


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`is_bipartite(graph, &color)`|グラフ $\mathrm{graph}$ は二部グラフであるか．|$\mathrm{color} \in {\lbrace 0, 1 \rbrace}^N$ は各頂点の色を表す．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.93-94，マイナビ出版（2012）


## Verified

https://atcoder.jp/contests/arc099/submissions/26050245
