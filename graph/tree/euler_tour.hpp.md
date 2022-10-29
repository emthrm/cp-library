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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include <vector>\n\n#include \"../edge.hpp\"\n\ntemplate <typename\
    \ CostType>\nstruct EulerTour {\n  std::vector<int> tour, depth, left, right,\
    \ down, up;\n  std::vector<CostType> cost;\n\n  explicit EulerTour(const std::vector<std::vector<Edge<CostType>>>\
    \ &graph,\n                     const int root = 0)\n      : graph(graph) {\n\
    \    const int n = graph.size();\n    left.resize(n);\n    right.resize(n);\n\
    \    down.assign(n, -1);\n    up.assign(n, (n - 1) << 1);\n    dfs(-1, root, 0);\n\
    \  }\n\n  template <typename Fn>\n  void update_v(const int ver, const Fn f) const\
    \ {\n    f(left[ver], right[ver] + 1);\n  }\n\n  template <typename T, typename\
    \ Fn>\n  T query_v(const int ver, const Fn f) const {\n    return f(left[ver],\
    \ right[ver] + 1);\n  }\n\n  template <typename T, typename Fn>\n  T query_e(const\
    \ int u, const int v, const Fn f) const {\n    return f(down[u] + 1, down[v] +\
    \ 1);\n  }\n\n  template <typename Fn>\n  void update_subtree_e(const int ver,\
    \ const Fn f) const {\n    f(down[ver] + 1, up[ver]);\n  }\n\n  template <typename\
    \ T, typename Fn>\n  T query_subtree_e(const int ver, const Fn f) const {\n  \
    \  return f(down[ver] + 1, up[ver]);\n  }\n\n private:\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n\n  void dfs(const int par, const int ver, const int cur_depth) {\n\
    \    left[ver] = tour.size();\n    tour.emplace_back(ver);\n    depth.emplace_back(cur_depth);\n\
    \    for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst != par) {\n\
    \        down[e.dst] = cost.size();\n        cost.emplace_back(e.cost);\n    \
    \    dfs(ver, e.dst, cur_depth + 1);\n        tour.emplace_back(ver);\n      \
    \  depth.emplace_back(cur_depth);\n        up[e.dst] = cost.size();\n        cost.emplace_back(-e.cost);\n\
    \      }\n    }\n    right[ver] = tour.size() - 1;\n  }\n};\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/euler_tour.hpp
  requiredBy:
  - graph/tree/lowest_common_ancestor_by_euler_tour.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
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
|`depth[i]`|頂点 `tour[i]` の深さ|
|`left[i]`|`tour` に頂点 $i$ が現れるインデックスの最小値|
|`right[i]`|`tour` に頂点 $i$ が現れるインデックスの最大値|
|`down[i]`|`cost` に頂点 $i$ へ下る辺が現れるインデックス|
|`up[i]`|`cost` に頂点 $i$ から上る辺が現れるインデックス|
|`cost`|辺属性のオイラーツアー|
|`update_v(ver, f)`|頂点 $\mathrm{ver}$ の部分木の頂点に対して $f$ を基に更新する．|
|`query_v<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の頂点に対する $f$ を基にしたクエリの解|
|`query_e<T>(u, v, f)`|頂点 $u$ から $v$ へ下る辺に対する $f$ を基にしたクエリの解|
|`update_subtree_e(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する．|
|`query_subtree_e<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対する $f$ を基にしたクエリの解|


## 参考

- http://beet-aizu.hatenablog.com/entry/2019/07/08/174727
- https://github.com/spaghetti-source/algorithm/blob/41bc0bbb1767692eb9bdeeceb332b2b8cc17329a/graph/least_common_ancestor_sparsetable.cc


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14
