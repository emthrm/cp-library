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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <queue>\r\n#include <vector>\r\n#include \"edge.hpp\"\
    \r\n\r\ntemplate <typename CostType>\r\nstruct UnicyclicGraph {\r\n  std::vector<Edge<CostType>>\
    \ loop;\r\n  std::vector<bool> is_in_loop;\r\n  std::vector<std::vector<std::vector<Edge<CostType>>>>\
    \ forest;\r\n  std::vector<int> belong, mp;\r\n  std::vector<std::vector<int>>\
    \ inv;\r\n\r\n  UnicyclicGraph(int n) : n(n), is_in_loop(n, false), belong(n,\
    \ -1), mp(n, -1), graph(n) {}\r\n\r\n  void add_edge(int src_i, int dst_i, CostType\
    \ cost_i) {\r\n    int id = src.size();\r\n    graph[src_i].emplace_back(id);\r\
    \n    graph[dst_i].emplace_back(id);\r\n    src.emplace_back(src_i);\r\n    dst.emplace_back(dst_i);\r\
    \n    cost.emplace_back(cost_i);\r\n  }\r\n\r\n  void build() {\r\n    dfs(-1,\
    \ 0);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (is_in_loop[i] && graph[i].size()\
    \ > 2) {\r\n        int idx = forest.size();\r\n        forest.emplace_back(std::vector<std::vector<Edge<CostType>>>(1));\r\
    \n        belong[i] = idx;\r\n        mp[i] = 0;\r\n        inv.emplace_back(std::vector<int>{i});\r\
    \n        std::queue<int> que({i});\r\n        while (!que.empty()) {\r\n    \
    \      int ver = que.front();\r\n          que.pop();\r\n          for (int id\
    \ : graph[ver]) {\r\n            int to = destination(id, ver);\r\n          \
    \  if (belong[to] == -1 && !is_in_loop[to]) {\r\n              int nx = forest[idx].size();\r\
    \n              forest[idx].emplace_back();\r\n              forest[idx][mp[ver]].emplace_back(mp[ver],\
    \ nx, cost[id]);\r\n              forest[idx][nx].emplace_back(nx, mp[ver], cost[id]);\r\
    \n              belong[to] = idx;\r\n              mp[to] = nx;\r\n          \
    \    inv[idx].emplace_back(to);\r\n              que.emplace(to);\r\n        \
    \    }\r\n          }\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\nprivate:\r\
    \n  int n;\r\n  std::vector<std::vector<int>> graph;\r\n  std::vector<int> src,\
    \ dst;\r\n  std::vector<CostType> cost;\r\n\r\n  int destination(int id, int s)\
    \ const {\r\n    return src[id] == s ? dst[id] : src[id];\r\n  }\r\n\r\n  bool\
    \ dfs(int prev_id, int ver) {\r\n    is_in_loop[ver] = true;\r\n    for (int id\
    \ : graph[ver]) {\r\n      if (id != prev_id) {\r\n        int to = destination(id,\
    \ ver);\r\n        loop.emplace_back(ver, to, cost[id]);\r\n        if (is_in_loop[to])\
    \ {\r\n          for (int i = static_cast<int>(loop.size()) - 2; i >= 0; --i)\
    \ {\r\n            if (loop[i].src == to) {\r\n              for (int j = 0; j\
    \ < i; ++j) is_in_loop[loop[j].src] = false;\r\n              loop.erase(loop.begin(),\
    \ loop.begin() + i);\r\n              break;\r\n            }\r\n          }\r\
    \n          return true;\r\n        }\r\n        if (dfs(id, to)) return true;\r\
    \n        loop.pop_back();\r\n      }\r\n    }\r\n    is_in_loop[ver] = false;\r\
    \n    return false;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/unicyclic_graph.hpp
  requiredBy: []
  timestamp: '2021-04-19 05:48:55+09:00'
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
|`UnicyclicGraph<CostType>(n)`|頂点数 $n$ の unicyclic graph を考える．||
|`loop`|閉路||
|`is_in_loop[i]`|頂点 $i$ は閉路に含まれるか．||
|`forest`|閉路を除いた森||
|`belong[i]`|頂点 $i$ を含む木の番号|存在しない場合は $-1$ となる．|
|`mp[i]`|頂点 $i$ に対応する木の頂点番号|存在しない場合は $-1$ となる．|
|`inv[i][j]`|木 $i$ の頂点 $j$ に対応する元のグラフの頂点番号||


## 参考

- https://en.wikipedia.org/wiki/Pseudoforest


## Verified

https://yukicoder.me/submissions/649654
