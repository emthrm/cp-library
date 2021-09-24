---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree/lowest_common_ancestor_by_euler_tour.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
      \u30FC\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"../edge.hpp\"\r\n\r\ntemplate\
    \ <typename CostType>\r\nstruct EulerTour {\r\n  std::vector<int> tour, left,\
    \ right, down, up, depth;\r\n  std::vector<CostType> cost;\r\n\r\n  EulerTour(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph, int root = 0) : graph(graph)\
    \ {\r\n    int n = graph.size();\r\n    left.resize(n);\r\n    right.resize(n);\r\
    \n    down.assign(n, -1);\r\n    up.assign(n, (n - 1) << 1);\r\n    dfs(-1, root,\
    \ 0);\r\n  }\r\n\r\n  template <typename Fn>\r\n  void v_update(int ver, Fn f)\
    \ const { f(left[ver], right[ver] + 1); }\r\n\r\n  template <typename T, typename\
    \ Fn>\r\n  T v_query(int ver, Fn f) const { return f(left[ver], right[ver] + 1);\
    \ }\r\n\r\n  template <typename T, typename Fn>\r\n  T e_query(int u, int v, Fn\
    \ f) const { return f(down[u] + 1, down[v] + 1); }\r\n\r\n  template <typename\
    \ Fn>\r\n  void subtree_e_update(int ver, Fn f) const { f(down[ver] + 1, up[ver]);\
    \ }\r\n\r\n  template <typename T, typename Fn>\r\n  T subtree_e_query(int ver,\
    \ Fn f) const { return f(down[ver] + 1, up[ver]); }\r\n\r\nprivate:\r\n  const\
    \ std::vector<std::vector<Edge<CostType>>> graph;\r\n\r\n  void dfs(int par, int\
    \ ver, int now_depth) {\r\n    left[ver] = tour.size();\r\n    tour.emplace_back(ver);\r\
    \n    depth.emplace_back(now_depth);\r\n    for (const Edge<CostType> &e : graph[ver])\
    \ {\r\n      if (e.dst != par) {\r\n        down[e.dst] = cost.size();\r\n   \
    \     cost.emplace_back(e.cost);\r\n        dfs(ver, e.dst, now_depth + 1);\r\n\
    \        tour.emplace_back(ver);\r\n        depth.emplace_back(now_depth);\r\n\
    \        up[e.dst] = cost.size();\r\n        cost.emplace_back(-e.cost);\r\n \
    \     }\r\n    }\r\n    right[ver] = tour.size() - 1;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/euler_tour.hpp
  requiredBy:
  - graph/tree/lowest_common_ancestor_by_euler_tour.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
documentation_of: graph/tree/euler_tour.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC (Euler tour)"
---

根付き木を列として表現するデータ構造である．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`EulerTour(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ のオイラーツアーを考える．|
|`tour`|頂点属性のオイラーツアー|
|`left[i]`|`tour` において頂点 $i$ が登場するインデックスの最小値|
|`right[i]`|`tour` において頂点 $i$ が登場するインデックスの最大値|
|`down[i]`|`cost` において頂点 $i$ に下る辺が登場するインデックス|
|`up[i]`|`cost` において頂点 $i$ から上る辺が登場するインデックス|
|`depth[i]`|頂点 `tour[i]` の深さ|
|`cost`|辺属性のオイラーツアー|
|`v_update(ver, f)`|頂点 $\mathrm{ver}$ の部分木の頂点に対して $f$ を基に更新する．|
|`v_query<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の頂点における $f$ を基にしたクエリの解|
|`e_query<T>(u, v, f)`|頂点 $u$ から $v$ へ下る辺における $f$ を基にしたクエリの解|
|`subtree_e_update(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する．|
|`subtree_e_query<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺における $f$ を基にしたクエリの解|


## 参考

- http://beet-aizu.hatenablog.com/entry/2019/07/08/174727
- https://github.com/spaghetti-source/algorithm/blob/41bc0bbb1767692eb9bdeeceb332b2b8cc17329a/graph/least_common_ancestor_sparsetable.cc


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14
