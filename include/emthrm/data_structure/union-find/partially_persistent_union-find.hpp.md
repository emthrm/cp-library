---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/data_structure/union-find/partially_persistent_union-find.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\
      \u9020/\u90E8\u5206\u6C38\u7D9A union-find"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/data_structure/union-find/partially_persistent_union-find.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace emthrm {\n\nstruct PartiallyPersistentUnionFind {\n  explicit\
    \ PartiallyPersistentUnionFind(const int n)\n      : data(n, -1), last(n, -1),\
    \ history(n, {{-1, -1}}) {}\n\n  int root(const int t, const int ver) const {\n\
    \    return last[ver] == -1 || t < last[ver] ? ver : root(t, data[ver]);\n  }\n\
    \n  bool unite(const int t, int u, int v) {\n    u = root(t, u);\n    v = root(t,\
    \ v);\n    if (u == v) return false;\n    if (data[u] > data[v]) std::swap(u,\
    \ v);\n    data[u] += data[v];\n    data[v] = u;\n    last[v] = t;\n    history[u].emplace_back(t,\
    \ data[u]);\n    return true;\n  }\n\n  bool is_same(const int t, const int u,\
    \ const int v) const {\n    return root(t, u) == root(t, v);\n  }\n\n  int size(const\
    \ int t, int ver) const {\n    ver = root(t, ver);\n    return -std::prev(std::lower_bound(history[ver].begin(),\n\
    \                                       history[ver].end(),\n                \
    \                       std::make_pair(t, 0)))->second;\n  }\n\n private:\n  std::vector<int>\
    \ data, last;\n  std::vector<std::vector<std::pair<int, int>>> history;\n};\n\n\
    }  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DATA_STRUCTURE_UNION_FIND_PARTIALLY_PERSISTENT_UNION_FIND_HPP_\n\
    #define EMTHRM_DATA_STRUCTURE_UNION_FIND_PARTIALLY_PERSISTENT_UNION_FIND_HPP_\n\
    \n#include <algorithm>\n#include <iterator>\n#include <utility>\n#include <vector>\n\
    \nnamespace emthrm {\n\nstruct PartiallyPersistentUnionFind {\n  explicit PartiallyPersistentUnionFind(const\
    \ int n)\n      : data(n, -1), last(n, -1), history(n, {{-1, -1}}) {}\n\n  int\
    \ root(const int t, const int ver) const {\n    return last[ver] == -1 || t <\
    \ last[ver] ? ver : root(t, data[ver]);\n  }\n\n  bool unite(const int t, int\
    \ u, int v) {\n    u = root(t, u);\n    v = root(t, v);\n    if (u == v) return\
    \ false;\n    if (data[u] > data[v]) std::swap(u, v);\n    data[u] += data[v];\n\
    \    data[v] = u;\n    last[v] = t;\n    history[u].emplace_back(t, data[u]);\n\
    \    return true;\n  }\n\n  bool is_same(const int t, const int u, const int v)\
    \ const {\n    return root(t, u) == root(t, v);\n  }\n\n  int size(const int t,\
    \ int ver) const {\n    ver = root(t, ver);\n    return -std::prev(std::lower_bound(history[ver].begin(),\n\
    \                                       history[ver].end(),\n                \
    \                       std::make_pair(t, 0)))->second;\n  }\n\n private:\n  std::vector<int>\
    \ data, last;\n  std::vector<std::vector<std::pair<int, int>>> history;\n};\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_DATA_STRUCTURE_UNION_FIND_PARTIALLY_PERSISTENT_UNION_FIND_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/data_structure/union-find/partially_persistent_union-find.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/data_structure/union-find/partially_persistent_union-find.test.cpp
documentation_of: include/emthrm/data_structure/union-find/partially_persistent_union-find.hpp
layout: document
title: "\u90E8\u5206\u6C38\u7D9A union-find"
---

# 素集合データ構造 (disjoint-set data structure)

|名前|概要|
|:--|:--|
|union-find|互いに素な集合族を管理するデータ構造|
|重みつき union-find|[アーベル群](../../../.verify-helper/docs/static/algebraic_structure.md)上の重みを考慮した union-find|
|部分永続 union-find|ある時刻における状態を保存する union-find である。最新版のみ変更できる。|
|undo 可能 union-find|巻き戻し可能な union-find|


## 時間計算量

||時間計算量|
|:--|:--|
|union-find|$\langle O(N), \text{amortized } O(\alpha(N)) \rangle$|
|重みつき union-find|$\langle O(N), \text{amortized } O(\alpha(N)) \rangle$|
|部分永続 union-find|$\langle O(N), O(\log{N}) \rangle$|
|undo 可能 union-find|$\langle O(N), O(\log{N}) \rangle$|


## 仕様

### union-find

```cpp
struct UnionFind;
```

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit UnionFind(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`int root(const int ver);`|$\mathrm{ver}$ の根|
|`bool unite(int u, int v);`|$u$ と $v$ を併合したのち、操作前は $u$ と $v$ が異なる集合に属していたかを返す。|
|`bool is_same(const int u, const int v);`|$u$ と $v$ は同じ集合に属しているか。|
|`int size(const int ver);`|$\mathrm{ver}$ を含む集合のサイズ|


### 重みつき union-find

```cpp
template <typename Abelian>
struct WeightedUnionFind;
```

- `Abelian`：アーベル群である要素型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit WeightedUnionFind(const int n, const Abelian ID = 0);`|頂点数 $N$、単位元 $\mathrm{id}$ のオブジェクトを構築する。|
|`int root(const int ver);`|$\mathrm{ver}$ の根|
|`bool unite(int u, int v, Abelian wt);`|$w(u) + \mathrm{wt} = w(v)$ の情報を加えたのち、操作前は $u$ と $v$ が異なる集合に属していたかを返す。|
|`bool is_same(const int u, const int v);`|$u$ と $v$ は同じ集合に属しているか。|
|`int size(const int ver);`|$\mathrm{ver}$ を含む集合のサイズ|
|`Abelian diff(const int u, const int v);`|$w(v) - w(u)$|


### 部分永続 union-find

```cpp
struct PartiallyPersistentUnionFind;
```

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit PartiallyPersistentUnionFind(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`int root(const int t, const int ver) const;`|時刻 $t$ における $\mathrm{ver}$ の根|
|`bool unite(const int t, int u, int v);`|時刻 $t$ に $u$ と $v$ を併合したのち、操作前は $u$ と $v$ が異なる集合に属していたかを返す。|
|`bool is_same(const int t, const int u, const int v) const;`|時刻 $t$ に $u$ と $v$ は同じ集合に属しているか。|
|`int size(const int t, int ver) const;`|時刻 $t$ における $\mathrm{ver}$ を含む集合のサイズ|


### undo 可能 union-find

```cpp
struct UndoableUnionFind;
```

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit UndoableUnionFind(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`int root(const int ver) const;`|$\mathrm{ver}$ の根|
|`bool unite(int u, int v);`|$u$ と $v$ を併合したのち、操作前は $u$ と $v$ が異なる集合に属していたかを返す。|
|`bool is_same(const int u, const int v) const;`|$u$ と $v$ は同じ集合に属しているか。|
|`int size(const int ver) const;`|$\mathrm{ver}$ を含む集合のサイズ|
|`void undo();`|`unite` を一度だけ巻き戻す。|
|`void snapshot();`|スナップショット|
|`void rollback();`|`snapshot` 時点まで巻き戻す。|


## 参考文献

- https://ei1333.github.io/algorithm/union-find.html

union-find
- Bernard A. Galler and Michael J. Fisher: An improved equivalence algorithm, *Communications of the ACM*, Vol. 7, No. 5, pp. 301–303 (1964). https://doi.org/10.1145/364099.364331
- Michael L. Fredman and Michael E. Saks: The cell probe complexity of dynamic data structures, *Proceedings of the twenty-first annual ACM symposium on Theory of computing*, pp. 345–354 (1989). https://doi.org/10.1145/73007.73040
- https://github.com/spaghetti-source/algorithm/blob/6c4a86dea5a487dbdd5fe96b3589d950e42c370d/data_structure/union_find.cc

重みつき union-find
- https://qiita.com/drken/items/cce6fc5c579051e64fab

部分永続 union-find
- https://camypaper.bitbucket.io/2016/12/18/adc2016/
- https://github.com/drken1215/algorithm/blob/86a29ca7b6c24132e8ba6b002c4ddd2ab201d4e7/DataStructure/partially_persistent_union_find_tree.cpp

undo 可能 union-find
- https://snuke.hatenablog.com/entry/2016/07/01/000000
- https://drken1215.hatenablog.com/entry/2020/11/02/201400


## TODO

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


## Submissons

- [union-find](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_1_A/review/4083481/emthrm/C++14)
- [重みつき union-find](https://judge.yosupo.jp/submission/224231)
- [部分永続 union-find](https://atcoder.jp/contests/agc002/submissions/26061193)
- [undo 可能 union-find](https://codeforces.com/contest/1444/submission/129693159)
