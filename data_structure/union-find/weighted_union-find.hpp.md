---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union-find/weighted_union-find.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u91CD\u307F\u3064\u304D union-find"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/union-find/union-find.md
    document_title: "\u91CD\u307F\u3064\u304D union-find"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/weighted_union-find.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/**\n * @brief \u91CD\u307F\u3064\u304D union-find\n * @docs docs/data_structure/union-find/union-find.md\n\
    \ */\n\n#pragma once\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ Abelian>\nstruct WeightedUnionFind {\n  explicit WeightedUnionFind(const int\
    \ n, const Abelian ID = 0)\n      : ID(ID), parent(n, -1), data(n, ID) {}\n\n\
    \  int root(const int ver) {\n    if (parent[ver] < 0) return ver;\n    const\
    \ int r = root(parent[ver]);\n    data[ver] += data[parent[ver]];\n    return\
    \ parent[ver] = r;\n  }\n\n  bool unite(int u, int v, Abelian wt) {\n    wt +=\
    \ weight(u);\n    wt -= weight(v);\n    u = root(u);\n    v = root(v);\n    if\
    \ (u == v) return false;\n    if (parent[u] > parent[v]) {\n      std::swap(u,\
    \ v);\n      wt = -wt;\n    }\n    parent[u] += parent[v];\n    parent[v] = u;\n\
    \    data[v] = wt;\n    return true;\n  }\n\n  bool is_same(const int u, const\
    \ int v) { return root(u) == root(v); }\n\n  int size(const int ver) { return\
    \ -parent[root(ver)]; }\n\n  Abelian diff(const int u, const int v) { return weight(v)\
    \ - weight(u); }\n\n private:\n  const Abelian ID;\n  std::vector<int> parent;\n\
    \  std::vector<Abelian> data;\n\n  Abelian weight(const int ver) {\n    root(ver);\n\
    \    return data[ver];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union-find/weighted_union-find.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union-find/weighted_union-find.test.cpp
documentation_of: data_structure/union-find/weighted_union-find.hpp
layout: document
redirect_from:
- /library/data_structure/union-find/weighted_union-find.hpp
- /library/data_structure/union-find/weighted_union-find.hpp.html
title: "\u91CD\u307F\u3064\u304D union-find"
---
# 素集合データ構造 (disjoint-set data structure)

|データ構造|説明|
|:--:|:--:|
|union-find|互いに素な集合族を管理するデータ構造|
|重みつき union-find|[アーベル群](../../../.verify-helper/docs/static/algebraic_structure.md)上の重みを考慮した union-find|
|部分永続 union-find|ある時刻における状態を保存する union-find である．最新版のみ変更できる．|
|undo 可能 union-find|巻き戻し可能な union-find|


## 時間計算量

|データ構造|時間計算量|
|:--:|:--:|
|union-find|$\langle O(N), \text{amortized } O(\alpha(N)) \rangle$|
|重みつき union-find|$\langle O(N), \text{amortized } O(\alpha(N)) \rangle$|
|部分永続 union-find|$\langle O(N), O(\log{N}) \rangle$|
|undo 可能 union-find|$\langle O(N), O(\log{N}) \rangle$|


## 使用法

- union-find

||説明|備考|
|:--:|:--:|:--:|
|`UnionFind(n)`|頂点数 $N$ の union-find||
|`root(ver)`|$\mathrm{ver}$ の根||
|`unite(u, v)`|$u$ と $v$ を併合する．|返り値は $u$ と $v$ を併合したか．|
|`is_same(u, v)`|$u$ と $v$ は同じ集合に属しているか．||
|`size(ver)`|$\mathrm{ver}$ を含む集合のサイズ||

- 重みつき union-find

||説明|備考|
|:--:|:--:|:--:|
|`WeightedUnionFind<Abelian>(n, 単位元 = 0)`|頂点数 $N$ の 重みつき union-find||
|`root(ver)`|$\mathrm{ver}$ の根||
|`unite(u, v, wt)`|$w(u) + \mathrm{wt} = w(v)$ の情報を加える．|返り値は $u$ と $v$ を併合したか．|
|`is_same(u, v)`|$u$ と $v$ は同じ集合に属しているか．||
|`size(ver)`|$\mathrm{ver}$ を含む集合のサイズ||
|`diff(u, v)`|$w(v) - w(u)$||

- 部分永続 union-find

||説明|備考|
|:--:|:--:|:--:|
|`PartiallyPersistentUnionFind(n)`|頂点数 $N$ の部分永続 union-find||
|`root(t, ver)`|時刻 $t$ における $\mathrm{ver}$ の根||
|`unite(t, u, v)`|時刻 $t$ に $u$ と $v$ を併合する．|返り値は $u$ と $v$ を併合したか．|
|`is_same(t, u, v)`|時刻 $t$ に $u$ と $v$ は同じ集合に属しているか．||
|`size(t, ver)`|時刻 $t$ における $\mathrm{ver}$ を含む集合のサイズ||

- undo 可能 union-find

||説明|備考|
|:--:|:--:|:--:|
|`UndoableUnionFind(n)`|頂点数 $N$ の undo 可能 union-find||
|`root(ver)`|$\mathrm{ver}$ の根||
|`unite(u, v)`|$u$ と $v$ を併合する．|返り値は $u$ と $v$ を併合したか．|
|`is_same(u, v)`|$u$ と $v$ は同じ集合に属しているか．||
|`size(ver)`|$\mathrm{ver}$ を含む集合のサイズ||
|`undo()`|`unite()` を一度だけ巻き戻す．||
|`snap()`|スナップショット||
|`rollback()`|`snap()` 時点まで巻き戻す．||


## 参考

- https://ei1333.github.io/algorithm/union-find.html

union-find
- https://github.com/spaghetti-source/algorithm/blob/6c4a86dea5a487dbdd5fe96b3589d950e42c370d/data_structure/union_find.cc

重みつき union-find
- https://qiita.com/drken/items/cce6fc5c579051e64fab

部分永続 union-find
- https://camypaper.bitbucket.io/2016/12/18/adc2016/
- https://github.com/drken1215/algorithm/blob/86a29ca7b6c24132e8ba6b002c4ddd2ab201d4e7/DataStructure/partially_persistent_union_find_tree.cpp

undo 可能 union-find
- https://snuke.hatenablog.com/entry/2016/07/01/000000
- https://drken1215.hatenablog.com/entry/2020/11/02/201400


## ToDo

- https://noshi91.hatenablog.com/entry/2018/05/30/191943
- 両端をもつ union-find
  - https://ei1333.github.io/algorithm/union-find.html
  - https://yukicoder.me/problems/no/1170/editorial
- 完全永続 union-find
  - https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
  - https://github.com/primenumber/ProconLib/blob/master/Structure/UnionFindPersistent.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/persistent_union_find.cc
  - https://sotanishy.github.io/cp-library-cpp/data-structure/unionfind/persistent_union_find.cpp
  - https://judge.yosupo.jp/problem/persistent_unionfind
- dynamic connectivity
  - https://en.wikipedia.org/wiki/Dynamic_connectivity
  - https://yukicoder.me/wiki/offline_dsp
  - https://twitter.com/noshi91/status/1420179696965197824
  - https://ei1333.hateblo.jp/entry/2017/12/14/000000
  - https://ei1333.github.io/luzhiled/snippets/other/offline-dynamic-connectivity.html
  - https://github.com/beet-aizu/library/blob/master/graph/dynamicconnectivity.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/union_find_undo.cc
  - https://mugen1337.github.io/procon/UnionFind/DynamicConnectivityOffline.cpp
  - https://sotanishy.github.io/cp-library-cpp/graph/offline_dynamic_connectivity.cpp
  - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum


## Verified

- [union-find](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_1_A/review/4083481/emthrm/C++14)
- [重みつき union-find](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_1_B/review/4083499/emthrm/C++14)
- [部分永続 union-find](https://atcoder.jp/contests/agc002/submissions/26061193)
- [undo 可能 union-find](https://codeforces.com/contest/1444/submission/129693159)
