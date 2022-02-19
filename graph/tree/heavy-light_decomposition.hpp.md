---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/heavy-light_decomposition.1.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/heavy-light_decomposition.2.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\u901A\u7956\
      \u5148)"
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
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n\r\n#include \"../edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstruct HeavyLightDecomposition\
    \ {\r\n  std::vector<int> parent, subtree, id, inv, head;\r\n  std::vector<CostType>\
    \ cost;\r\n\r\n  explicit HeavyLightDecomposition(\r\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\r\n      const int root = 0)\r\n      : graph(graph) {\r\n    const int\
    \ n = graph.size();\r\n    parent.assign(n, -1);\r\n    subtree.assign(n, 1);\r\
    \n    dfs1(root);\r\n    id.resize(n);\r\n    inv.resize(n);\r\n    head.assign(n,\
    \ root);\r\n    int cur_id = 0;\r\n    dfs2(root, &cur_id);\r\n  }\r\n\r\n  template\
    \ <typename Fn>\r\n  void update_v(int u, int v, const Fn f) const {\r\n    while\
    \ (true) {\r\n      if (id[u] > id[v]) std::swap(u, v);\r\n      f(std::max(id[head[v]],\
    \ id[u]), id[v] + 1);\r\n      if (head[u] == head[v]) break;\r\n      v = parent[head[v]];\r\
    \n    }\r\n  }\r\n\r\n  template <typename F, typename G, typename T>\r\n  T query_v(int\
    \ u, int v, const F f, const G g, const T id_t) const {\r\n    T left = id_t,\
    \ right = id_t;\r\n    while (true) {\r\n      if (id_t[u] > id_t[v]) {\r\n  \
    \      std::swap(u, v);\r\n        std::swap(left, right);\r\n      }\r\n    \
    \  left = g(left, f(std::max(id_t[head[v]], id_t[u]), id_t[v] + 1));\r\n     \
    \ if (head[u] == head[v]) break;\r\n      v = parent[head[v]];\r\n    }\r\n  \
    \  return g(left, right);\r\n  }\r\n\r\n  template <typename Fn>\r\n  void update_subtree_v(const\
    \ int ver, const Fn f) const {\r\n    f(id[ver], id[ver] + subtree[ver]);\r\n\
    \  }\r\n\r\n  template <typename T, typename Fn>\r\n  T query_subtree_v(const\
    \ int ver, const Fn f) const {\r\n    return f(id[ver], id[ver] + subtree[ver]);\r\
    \n  }\r\n\r\n  template <typename Fn>\r\n  void update_e(int u, int v, const Fn\
    \ f) const {\r\n    while (true) {\r\n      if (id[u] > id[v]) std::swap(u, v);\r\
    \n      if (head[u] == head[v]) {\r\n        f(id[u], id[v]);\r\n        break;\r\
    \n      } else {\r\n        f(id[head[v]] - 1, id[v]);\r\n        v = parent[head[v]];\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  template <typename F, typename G, typename\
    \ T>\r\n  T query_e(int u, int v, const F f, const G g, const T id_t) const {\r\
    \n    T left = id_t, right = id_t;\r\n    while (true) {\r\n      if (id[u] >\
    \ id[v]) {\r\n        std::swap(u, v);\r\n        std::swap(left, right);\r\n\
    \      }\r\n      if (head[u] == head[v]) {\r\n        left = g(left, f(id[u],\
    \ id[v]));\r\n        break;\r\n      } else {\r\n        left = g(left, f(id[head[v]]\
    \ - 1, id[v]));\r\n        v = parent[head[v]];\r\n      }\r\n    }\r\n    return\
    \ g(left, right);\r\n  }\r\n\r\n  template <typename Fn>\r\n  void update_subtree_e(const\
    \ int ver, const Fn f) const {\r\n    f(id[ver], id[ver] + subtree[ver] - 1);\r\
    \n  }\r\n\r\n  template <typename T, typename Fn>\r\n  T query_subtree_e(const\
    \ int ver, const Fn f) const {\r\n    return f(id[ver], id[ver] + subtree[ver]\
    \ - 1);\r\n  }\r\n\r\n  int lowest_common_ancestor(int u, int v) const {\r\n \
    \   while (true) {\r\n      if (id[u] > id[v]) std::swap(u, v);\r\n      if (head[u]\
    \ == head[v]) break;\r\n      v = parent[head[v]];\r\n    }\r\n    return u;\r\
    \n  }\r\n\r\n private:\r\n  std::vector<std::vector<Edge<CostType>>> graph;\r\n\
    \r\n  void dfs1(const int ver) {\r\n    for (int i = 0; i < graph[ver].size();\
    \ ++i) {\r\n      Edge<CostType>& e = graph[ver][i];\r\n      if (e.dst != parent[ver])\
    \ {\r\n        parent[e.dst] = ver;\r\n        dfs1(e.dst);\r\n        subtree[ver]\
    \ += subtree[e.dst];\r\n        if (subtree[e.dst] > subtree[graph[ver].front().dst])\
    \ {\r\n          std::swap(e, graph[ver].front());\r\n        }\r\n      }\r\n\
    \    }\r\n  }\r\n\r\n  void dfs2(const int ver, int* cur_id) {\r\n    id[ver]\
    \ = (*cur_id)++;\r\n    inv[id[ver]] = ver;\r\n    for (const Edge<CostType>&\
    \ e : graph[ver]) {\r\n      if (e.dst != parent[ver]) {\r\n        head[e.dst]\
    \ = (e.dst == graph[ver].front().dst ? head[ver] : e.dst);\r\n        cost.emplace_back(e.cost);\r\
    \n        dfs2(e.dst, cur_id);\r\n      }\r\n    }\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/heavy-light_decomposition.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/heavy-light_decomposition.1.test.cpp
  - test/graph/tree/heavy-light_decomposition.2.test.cpp
documentation_of: graph/tree/heavy-light_decomposition.hpp
layout: document
title: "HL \u5206\u89E3 (heavy-light decomposition)"
---

heavy edge と light edge に分類された辺を基にして，木を分解する方法である．


## 時間計算量

$\langle O(\lvert V \rvert), O(\log{\lvert V \rvert}) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`HeavyLightDecomposition<CostType>(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ の HL 分解を考える．|
|`parent[i]`|頂点 $i$ の親の頂点番号|
|`subtree[i]`|頂点 $i$ の部分木の大きさ|
|`id[i]`|頂点 $i$ の ID|
|`inv[i]`|ID $i$ の頂点番号|
|`head[i]`|頂点 $i$ を含む heavy path の先頭の頂点番号|
|`cost[i]`|辺 (`inv[i]`, `inv[i + 1]`) の重み|
|`update_v(u, v, f)`|頂点 $u, v$ 間の頂点に対して $f$ を基に更新する．|
|`query_v(u, v, f, g, 単位元)`|頂点 $u, v$ 間の頂点に対する $f$ を基に $g$ でまとめたクエリの解|
|`update_subtree_v(ver, f)`|頂点 $ver$ の部分木の頂点に対して $f$ を基に更新する．|
|`query_subtree_v<T>(ver, f)`|頂点 $ver$ の部分木の頂点に対する $f$ を基にしたクエリの解|
|`update_e(u, v, f)`|頂点 $u, v$ 間の辺に対して $f$ を基に更新する．|
|`query_e(u, v, f, g, 単位元)`|頂点 $u, v$ 間の辺に対する $f$ を基に $g$ でまとめたクエリの解|
|`update_subtree_e(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する．|
|`query_subtree_e<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対する $f$ を基にしたクエリの解|
|`lowest_common_ancestor(u, v)`|頂点 $u, v$ の[最小共通祖先](lowest_common_ancestor.md)|


## 参考

- https://www.slideshare.net/hcpc_hokudai/study-20150107
- http://beet-aizu.hatenablog.com/entry/2017/12/12/235950
- https://github.com/beet-aizu/library/blob/627950ae389af108b3c3f431f057c58891b0ba72/tree/heavylightdecomposition.cpp
- https://codeforces.com/blog/entry/53170


## ToDo

- 高速化
  - http://yosupo.hatenablog.com/entry/2015/10/02/233244


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084766/emthrm/C++14
