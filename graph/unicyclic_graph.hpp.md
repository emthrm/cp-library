---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/unicyclic_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/unicyclic graph"
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
  code: "#pragma once\r\n#include <cassert>\r\n#include <iterator>\r\n#include <queue>\r\
    \n#include <vector>\r\n\r\n#include \"edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\
    \nstruct UnicyclicGraph {\r\n  std::vector<bool> is_in_loop;\r\n  std::vector<int>\
    \ belong, mapping;\r\n  std::vector<Edge<CostType>> loop;\r\n  std::vector<std::vector<int>>\
    \ invs;\r\n  std::vector<std::vector<std::vector<Edge<CostType>>>> forest;\r\n\
    \r\n  explicit UnicyclicGraph(const int n)\r\n      : n(n), is_in_loop(n, false),\
    \ belong(n, -1), mapping(n, -1), graph(n) {}\r\n\r\n  void add_edge(const int\
    \ src, const int dst, const CostType cost = 0) {\r\n    const int id = srcs.size();\r\
    \n    srcs.emplace_back(src);\r\n    dsts.emplace_back(dst);\r\n    costs.emplace_back(cost);\r\
    \n    graph[src].emplace_back(id);\r\n    if (dst != src) graph[dst].emplace_back(id);\r\
    \n  }\r\n\r\n  void build() {\r\n    dfs(-1, 0);\r\n    std::queue<int> que;\r\
    \n    for (const Edge<CostType>& e : loop) {\r\n      const int root = e.src,\
    \ forest_id = forest.size();\r\n      belong[root] = forest_id;\r\n      mapping[root]\
    \ = 0;\r\n      std::vector<int> inv{root};\r\n      std::vector<std::vector<Edge<CostType>>>\
    \ tree(1);\r\n      que.emplace(root);\r\n      while (!que.empty()) {\r\n   \
    \     const int ver = que.front();\r\n        que.pop();\r\n        for (const\
    \ int id : graph[ver]) {\r\n          const int dst = destination(id, ver);\r\n\
    \          if (belong[dst] == -1 && !is_in_loop[dst]) {\r\n            const int\
    \ idx = tree.size();\r\n            belong[dst] = forest_id;\r\n            mapping[dst]\
    \ = idx;\r\n            inv.emplace_back(dst);\r\n            tree[mapping[ver]].emplace_back(mapping[ver],\
    \ idx, costs[id]);\r\n            tree.emplace_back(std::vector<Edge<CostType>>{\r\
    \n                Edge<CostType>(idx, mapping[ver], costs[id])});\r\n        \
    \    que.emplace(dst);\r\n          }\r\n        }\r\n      }\r\n      if (inv.size()\
    \ == 1) {\r\n        belong[root] = mapping[root] = -1;\r\n      } else {\r\n\
    \        invs.emplace_back(inv);\r\n        forest.emplace_back(tree);\r\n   \
    \   }\r\n    }\r\n  }\r\n\r\n private:\r\n  const int n;\r\n  std::vector<int>\
    \ srcs, dsts;\r\n  std::vector<CostType> costs;\r\n  std::vector<std::vector<int>>\
    \ graph;\r\n\r\n  int destination(const int id, const int s) const {\r\n    return\
    \ (srcs[id] == s ? dsts : srcs)[id];\r\n  }\r\n\r\n  bool dfs(const int prev_id,\
    \ const int ver) {\r\n    is_in_loop[ver] = true;\r\n    for (const int id : graph[ver])\
    \ {\r\n      if (id == prev_id) continue;\r\n      const int dst = destination(id,\
    \ ver);\r\n      loop.emplace_back(ver, dst, costs[id]);\r\n      if (is_in_loop[dst])\
    \ {\r\n        for (int i = loop.size() - 1; i >= 0; --i) {\r\n          if (loop[i].src\
    \ == dst) {\r\n            for (int j = 0; j < i; ++j) {\r\n              is_in_loop[loop[j].src]\
    \ = false;\r\n            }\r\n            loop.erase(loop.begin(), std::next(loop.begin(),\
    \ i));\r\n            return true;\r\n          }\r\n        }\r\n        assert(false);\r\
    \n      }\r\n      if (dfs(id, dst)) return true;\r\n      loop.pop_back();\r\n\
    \    }\r\n    is_in_loop[ver] = false;\r\n    return false;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/unicyclic_graph.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/unicyclic_graph.test.cpp
documentation_of: graph/unicyclic_graph.hpp
layout: document
title: unicyclic graph (1-tree)
---

閉路をただ一つだけ含む単純連結無向グラフである．俗に[ある漫画家の名前を用いて表現される](https://twitter.com/chokudai/status/772440823170379776)．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`UnicyclicGraph<CostType>(n)`|頂点数 $N$ の unicyclic graph を考える．||
|`is_in_loop[i]`|頂点 $i$ は閉路に含まれるか．||
|`belong[i]`|頂点 $i$ を含む木の番号|存在しないときは $-1$ となる．|
|`mapping[i]`|頂点 $i$ に対応する木の頂点番号|存在しないときは $-1$ となる．|
|`loop`|閉路||
|`invs[i][j]`|木 $i$ の頂点 $j$ に対応する元のグラフの頂点番号||
|`forests`|閉路を除いた森||
|`add_edge(src, dst, cost = 0)`|始点 $\mathrm{src}$，終点 $\mathrm{dst}$，コスト $\mathrm{cost}$ の辺を加える．|||
|`build()`|構築する．||


## 参考

- https://en.wikipedia.org/wiki/Pseudoforest


## Verified

https://yukicoder.me/submissions/649654
