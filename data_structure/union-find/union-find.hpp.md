---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/mst/kruskal.hpp
    title: "Kruskal \u6CD5"
  - icon: ':warning:'
    path: graph/mst/kruskal_heavy.hpp
    title: "Kruskal \u6CD5 \u91CD\u91CF\u7248"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union-find/union-find.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/union-find \u6728"
  - icon: ':x:'
    path: test/graph/biconnected_component.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
      \u89E3"
  - icon: ':x:'
    path: test/graph/matrix_tree_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: test/graph/mst/kruskal.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6700\u5C0F\u5168\u57DF\u6728/Kruskal \u6CD5"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/data_structure/union-find/union-find.md
    document_title: "union-find \u6728"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/union-find.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief union-find \u6728\r\n * @docs docs/data_structure/union-find/union-find.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <utility>\r\n#include <vector>\r\n\r\nstruct\
    \ UnionFind {\r\n  UnionFind(int n) : data(n, -1) {}\r\n\r\n  int root(int ver)\
    \ { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }\r\n\r\n  bool\
    \ unite(int u, int v) {\r\n    u = root(u);\r\n    v = root(v);\r\n    if (u ==\
    \ v) return false;\r\n    if (data[u] > data[v]) std::swap(u, v);\r\n    data[u]\
    \ += data[v];\r\n    data[v] = u;\r\n    return true;\r\n  }\r\n\r\n  bool same(int\
    \ u, int v) { return root(u) == root(v); }\r\n\r\n  int size(int ver) { return\
    \ -data[root(ver)]; }\r\n\r\nprivate:\r\n  std::vector<int> data;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union-find/union-find.hpp
  requiredBy:
  - graph/mst/kruskal.hpp
  - graph/mst/kruskal_heavy.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/matrix_tree_theorem.test.cpp
  - test/graph/mst/kruskal.test.cpp
  - test/graph/biconnected_component.test.cpp
  - test/data_structure/union-find/union-find.test.cpp
documentation_of: data_structure/union-find/union-find.hpp
layout: document
redirect_from:
- /library/data_structure/union-find/union-find.hpp
- /library/data_structure/union-find/union-find.hpp.html
title: "union-find \u6728"
---
# union-find 木 (素集合データ構造 / disjoint-set data structure)

|データ構造|説明|
|:--:|:--:|
|union-find 木|グループ分けを管理するデータ構造|
|重みつき union-find 木|[アーベル群](../../../.verify-helper/docs/static/algebraic_structure.md)である重み情報が付加された union-find 木|
|部分永続 union-find 木|最新版のみ変更可能な時刻 $t$ における状態を保存する union-find 木|
|undo 可能 union-find 木|巻き戻し可能な union-find 木|


## 時間計算量

|データ構造|時間計算量|
|:--:|:--:|
|union-find 木|$\langle O(N), \text{amortized } O(\alpha(N)) \rangle$|
|重みつき union-find 木|$\langle O(N), \text{amortized } O(\alpha(N)) \rangle$|
|部分永続 union-find 木|$\langle O(N), O(\log{N}) \rangle$|
|undo 可能 union-find 木|$\langle O(N), O(\log{N}) \rangle$|


## 使用法

- union-find 木

||説明|備考|
|:--:|:--:|:--:|
|`UnionFind(n)`|頂点数 $N$ の union-find 木||
|`root(ver)`|$\mathrm{ver}$ の根||
|`unite(u, v)`|$u$ と $v$ を併合する．|返り値は $u$ と $v$ を併合したか．|
|`same(u, v)`|$u$ と $v$ は連結か．||
|`size(ver)`|$\mathrm{ver}$ を含む連結成分の個数||

- 重みつき union-find 木

||説明|備考|
|:--:|:--:|:--:|
|`WeightedUnionFind<Abelian>(n, 単位元 = 0)`|頂点数 $N$ の 重みつき union-find 木||
|`root(ver)`|$ver$ の根||
|`unite(u, v, wt)`|$w(u) + \mathrm{wt} = w(v)$ の情報を付加する．|返り値は $u$ と $v$ を併合したか．|
|`same(u, v)`|$u$ と $v$ は連結か．||
|`size(ver)`|$\mathrm{ver}$ を含む連結成分の個数||
|`diff(u, v)`|$w(v) - w(u)$||

- 部分永続 union-find 木

||説明|備考|
|:--:|:--:|:--:|
|`PartiallyPersistentUnionFind(n)`|頂点数 $N$ の部分永続 union-find 木||
|`root(t, ver)`|時刻 $t$ における $\mathrm{ver}$ の根||
|`unite(t, u, v)`|時刻 $t$ において $u$ と $v$ を併合する．|返り値は $u$ と $v$ を併合したか．|
|`same(t, u, v)`|時刻 $t$ において $u$ と $v$ は連結か．||
|`size(t, ver)`|時刻 $t$ における $\mathrm{ver}$ を含む連結成分の個数||

- undo 可能 union-find 木

||説明|備考|
|:--:|:--:|:--:|
|`UndoableUnionFind(n)`|頂点数 $N$ の undo 可能 union-find 木||
|`root(ver)`|$\mathrm{ver}$ の根||
|`unite(u, v)`|$u$ と $v$ を併合する．|返り値は $u$ と $v$ を併合したか．|
|`same(u, v)`|$u$ と $v$ は連結か．||
|`size(ver)`|$\mathrm{ver}$ を含む連結成分の個数||
|`undo()`|`unite()` を一度，巻き戻す．||
|`snap()`|スナップショット||
|`rollback()`|`snap()` 時点まで巻き戻す．||


## 参考

- https://ei1333.github.io/algorithm/union-find.html

union-find 木
- https://github.com/spaghetti-source/algorithm/blob/master/data_structure/union_find.cc

重みつき union-find 木
- https://qiita.com/drken/items/cce6fc5c579051e64fab

部分永続 union-find 木
- https://camypaper.bitbucket.io/2016/12/18/adc2016/
- https://github.com/drken1215/algorithm/blob/master/DataStructure/partially_persistent_union_find_tree.cpp

undo 可能 union-find 木
- https://snuke.hatenablog.com/entry/2016/07/01/000000
- https://drken1215.hatenablog.com/entry/2020/11/02/201400


## ToDo

- https://noshi91.hatenablog.com/entry/2018/05/30/191943
- 両端をもつ union-find 木
  - https://ei1333.github.io/algorithm/union-find.html
  - https://yukicoder.me/problems/no/1170/editorial
- 完全永続 union-find 木
  - https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
  - https://github.com/primenumber/ProconLib/blob/master/Structure/UnionFindPersistent.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/persistent_union_find.cc
  - https://atcoder.jp/contests/agc002/tasks/agc002_d
  - https://judge.yosupo.jp/problem/persistent_unionfind
- dynamic connectivity
  - https://en.wikipedia.org/wiki/Dynamic_connectivity
  - https://yukicoder.me/wiki/offline_dsp
  - https://ei1333.hateblo.jp/entry/2017/12/14/000000
  - https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html
  - https://github.com/beet-aizu/library/blob/master/datastructure/dynamicconnectivity.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/union_find_undo.cc
  - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum


## Verified

- [union-find 木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_1_A/review/4083481/emthrm/C++14)
- [重みつき union-find 木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_1_B/review/4083499/emthrm/C++14)
- [部分永続 union-find 木](https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/9253578)
- [undo 可能 union-find 木](https://codeforces.com/contest/1444/submission/97689819)
