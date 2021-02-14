---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.1.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/hld.2.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\u901A\u7956\
      \u5148)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n#include <vector>\r\
    \n#include \"../edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstruct HLD {\r\
    \n  std::vector<int> parent, subtree, id, inv, head;\r\n  std::vector<CostType>\
    \ cost;\r\n\r\n  HLD(const std::vector<std::vector<Edge<CostType>>> &graph, int\
    \ root = 0) : graph(graph) {\r\n    int n = graph.size();\r\n    parent.assign(n,\
    \ -1);\r\n    subtree.assign(n, 1);\r\n    id.resize(n);\r\n    inv.resize(n);\r\
    \n    head.resize(n);\r\n    dfs1(root);\r\n    head[root] = root;\r\n    int\
    \ now_id = 0;\r\n    dfs2(root, now_id);\r\n  }\r\n\r\n  template <typename Fn>\r\
    \n  void v_update(int u, int v, Fn f) const {\r\n    while (true) {\r\n      if\
    \ (id[u] > id[v]) std::swap(u, v);\r\n      f(std::max(id[head[v]], id[u]), id[v]\
    \ + 1);\r\n      if (head[u] == head[v]) return;\r\n      v = parent[head[v]];\r\
    \n    }\r\n  }\r\n\r\n  template <typename T, typename F, typename G>\r\n  T v_query(int\
    \ u, int v, F f, G g, const T ID) const {\r\n    T left = ID, right = ID;\r\n\
    \    while (true) {\r\n      if (id[u] > id[v]) {\r\n        std::swap(u, v);\r\
    \n        std::swap(left, right);\r\n      }\r\n      left = g(left, f(std::max(id[head[v]],\
    \ id[u]), id[v] + 1));\r\n      if (head[u] == head[v]) break;\r\n      v = parent[head[v]];\r\
    \n    }\r\n    return g(left, right);\r\n  }\r\n\r\n  template <typename Fn>\r\
    \n  void subtree_v_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver]);\
    \ }\r\n\r\n  template <typename T, typename Fn>\r\n  T subtree_v_query(int ver,\
    \ Fn f) const { return f(id[ver], id[ver] + subtree[ver]); }\r\n\r\n  template\
    \ <typename Fn>\r\n  void e_update(int u, int v, Fn f) const {\r\n    while (true)\
    \ {\r\n      if (id[u] > id[v]) std::swap(u, v);\r\n      if (head[u] == head[v])\
    \ {\r\n        f(id[u], id[v]);\r\n        break;\r\n      } else {\r\n      \
    \  f(id[head[v]] - 1, id[v]);\r\n        v = parent[head[v]];\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  template <typename T, typename F, typename G>\r\n  T e_query(int\
    \ u, int v, F f, G g, const T ID) const {\r\n    T left = ID, right = ID;\r\n\
    \    while (true) {\r\n      if (id[u] > id[v]) {\r\n        std::swap(u, v);\r\
    \n        std::swap(left, right);\r\n      }\r\n      if (head[u] == head[v])\
    \ {\r\n        left = g(left, f(id[u], id[v]));\r\n        break;\r\n      } else\
    \ {\r\n        left = g(left, f(id[head[v]] - 1, id[v]));\r\n        v = parent[head[v]];\r\
    \n      }\r\n    }\r\n    return g(left, right);\r\n  }\r\n\r\n  template <typename\
    \ Fn>\r\n  void subtree_e_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver]\
    \ - 1); }\r\n\r\n  template <typename T, typename Fn>\r\n  T subtree_e_query(int\
    \ ver, Fn f) const { return f(id[ver], id[ver] + subtree[ver] - 1); }\r\n\r\n\
    \  int lca(int u, int v) const {\r\n    while (true) {\r\n      if (id[u] > id[v])\
    \ std::swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n      v = parent[head[v]];\r\
    \n    }\r\n  }\r\n\r\nprivate:\r\n  std::vector<std::vector<Edge<CostType>>> graph;\r\
    \n\r\n  void dfs1(int ver) {\r\n    for (Edge<CostType> &e : graph[ver]) {\r\n\
    \      if (e.dst != parent[ver]) {\r\n        parent[e.dst] = ver;\r\n       \
    \ dfs1(e.dst);\r\n        subtree[ver] += subtree[e.dst];\r\n        if (subtree[e.dst]\
    \ > subtree[graph[ver].front().dst]) std::swap(e, graph[ver].front());\r\n   \
    \   }\r\n    }\r\n  }\r\n\r\n  void dfs2(int ver, int &now_id) {\r\n    id[ver]\
    \ = now_id++;\r\n    inv[id[ver]] = ver;\r\n    for (const Edge<CostType> &e :\
    \ graph[ver]) {\r\n      if (e.dst != parent[ver]) {\r\n        head[e.dst] =\
    \ (e.dst == graph[ver].front().dst ? head[ver] : e.dst);\r\n        cost.emplace_back(e.cost);\r\
    \n        dfs2(e.dst, now_id);\r\n      }\r\n    }\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/hld.hpp
  requiredBy: []
  timestamp: '2021-02-13 04:45:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/hld.1.test.cpp
  - test/graph/tree/hld.2.test.cpp
documentation_of: graph/tree/hld.hpp
layout: document
title: "HL \u5206\u89E3 (heavy-light decomposition)"
---

heavy edge と light edge に分類された辺を基に木を分解する手法である．


## 時間計算量

$\langle O(\lvert V \rvert), O(\log{\lvert V \rvert}) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`HLD<CostType>(graph, root = 0)`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ の HL 分解を考える．|
|`parent[i]`|頂点 $i$ の親の頂点番号|
|`subtree[i]`|頂点 $i$ の部分木の大きさ|
|`id[i]`|HL 分解後の頂点 $i$ の ID|
|`inv[i]`|HL 分解前の ID $i$ の頂点番号|
|`head[i]`|頂点 $i$ を含む heavy path の先頭の頂点番号|
|`cost[i]`|辺 (`inv[i]`, `inv[i + 1]`) の重み|
|`v_update(u, v, f)`|頂点 $u, v$ 間の頂点に対して $f$ を基に更新する．|
|`v_query(u, v, f, g, 単位元)`|頂点 $u, v$ 間の頂点における $f$ を基に $g$ でまとめたクエリの解|
|`subtree_v_update(ver, f)`|頂点 $ver$ の部分木の頂点に対して $f$ を基に更新する．|
|`subtree_v_query<T>(ver, f)`|頂点 $ver$ の部分木の頂点における $f$ を基にしたクエリの解|
|`e_update(u, v, f)`|頂点 $u, v$ 間の辺に対して $f$ を基に更新する．|
|`e_query(u, v, f, g, 単位元)`|頂点 $u, v$ 間の辺における $f$ を基に $g$ でまとめたクエリの解|
|`subtree_e_update(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する．|
|`subtree_e_query<T>(ver, f)`|頂点 $\mathrm{ver}$ の部分木の辺における $f$ を基にしたクエリの解|
|`lca(u, v)`|頂点 $u, v$ の[最小共通祖先](lca.md)|


## 参考

- https://www.slideshare.net/hcpc_hokudai/study-20150107
- http://beet-aizu.hatenablog.com/entry/2017/12/12/235950
- https://github.com/beet-aizu/library/blob/master/tree/heavylightdecomposition.cpp
- https://codeforces.com/blog/entry/53170


## ToDo

- 高速化
  - http://yosupo.hatenablog.com/entry/2015/10/02/233244


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084766/emthrm/C++14
