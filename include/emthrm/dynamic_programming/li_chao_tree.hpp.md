---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/li_chao_tree.1.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree\uFF08\u6700\u5C0F\u5024\uFF09"
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/li_chao_tree.2.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree\uFF08\u6700\u5927\u5024\uFF09"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/dynamic_programming/li_chao_tree.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <iterator>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T, bool IS_MINIMIZED = true>\nstruct LiChaoTree {\n\
    \  struct Line {\n    T a, b;\n    explicit Line(const T a, const T b) : a(a),\
    \ b(b) {}\n    T f(const T x) const { return a * x + b; }\n  };\n\n  explicit\
    \ LiChaoTree(const std::vector<T>& xs_, const T inf) : n(1), xs(xs_) {\n    std::sort(xs.begin(),\
    \ xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n   \
    \ assert(xs.size() > 0);\n    n = std::bit_ceil(xs.size());\n    const T xs_back\
    \ = xs.back();\n    xs.resize(n, xs_back);\n    dat.assign(n << 1, Line(0, inf));\n\
    \  }\n\n  void add(T a, T b) {\n    if constexpr (!IS_MINIMIZED) {\n      a =\
    \ -a;\n      b = -b;\n    }\n    Line line(a, b);\n    add(&line, 1, 0, n);\n\
    \  }\n\n  void add(T a, T b, T left, T right) {\n    if constexpr (!IS_MINIMIZED)\
    \ {\n      a = -a;\n      b = -b;\n    }\n    for (int len = 1,\n            \
    \ node_l = std::distance(\n                 xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), left)),\n             node_r = std::distance(\n                 xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), right)),\n             l = node_l + n,\
    \ r = node_r + n;\n         l < r;\n         l >>= 1, r >>= 1, len <<= 1) {\n\
    \      if (l & 1) {\n        Line line(a, b);\n        add(&line, l++, node_l,\
    \ node_l + len);\n        node_l += len;\n      }\n      if (r & 1) {\n      \
    \  Line line(a, b);\n        node_r -= len;\n        add(&line, --r, node_r, node_r\
    \ + len);\n      }\n    }\n  }\n\n  T query(const T x) const {\n    int node =\
    \ n + std::distance(xs.begin(),\n                                 std::lower_bound(xs.begin(),\
    \ xs.end(), x));\n    T res = dat[node].f(x);\n    while (node >>= 1) {\n    \
    \  if (dat[node].f(x) < res) res = dat[node].f(x);\n    }\n    return IS_MINIMIZED\
    \ ? res : -res;\n  }\n\n private:\n  int n;\n  std::vector<T> xs;\n  std::vector<Line>\
    \ dat;\n\n  void add(Line* line, int node, int left, int right) {\n    const bool\
    \ flag_l = dat[node].f(xs[left]) <= line->f(xs[left]);\n    const bool flag_r\
    \ = dat[node].f(xs[right - 1]) <= line->f(xs[right - 1]);\n    if (flag_l && flag_r)\
    \ return;\n    if (!flag_l && !flag_r) {\n      std::swap(dat[node], *line);\n\
    \      return;\n    }\n    const int mid = std::midpoint(left, right);\n    if\
    \ (line->f(xs[mid]) < dat[node].f(xs[mid])) std::swap(dat[node], *line);\n   \
    \ if (line->f(xs[left]) <= dat[node].f(xs[left])) {\n      add(line, node << 1,\
    \ left, mid);\n    } else {\n      add(line, (node << 1) + 1, mid, right);\n \
    \   }\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_LI_CHAO_TREE_HPP_\n#define EMTHRM_DYNAMIC_PROGRAMMING_LI_CHAO_TREE_HPP_\n\
    \n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <iterator>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T, bool IS_MINIMIZED = true>\nstruct LiChaoTree {\n\
    \  struct Line {\n    T a, b;\n    explicit Line(const T a, const T b) : a(a),\
    \ b(b) {}\n    T f(const T x) const { return a * x + b; }\n  };\n\n  explicit\
    \ LiChaoTree(const std::vector<T>& xs_, const T inf) : n(1), xs(xs_) {\n    std::sort(xs.begin(),\
    \ xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n   \
    \ assert(xs.size() > 0);\n    n = std::bit_ceil(xs.size());\n    const T xs_back\
    \ = xs.back();\n    xs.resize(n, xs_back);\n    dat.assign(n << 1, Line(0, inf));\n\
    \  }\n\n  void add(T a, T b) {\n    if constexpr (!IS_MINIMIZED) {\n      a =\
    \ -a;\n      b = -b;\n    }\n    Line line(a, b);\n    add(&line, 1, 0, n);\n\
    \  }\n\n  void add(T a, T b, T left, T right) {\n    if constexpr (!IS_MINIMIZED)\
    \ {\n      a = -a;\n      b = -b;\n    }\n    for (int len = 1,\n            \
    \ node_l = std::distance(\n                 xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), left)),\n             node_r = std::distance(\n                 xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), right)),\n             l = node_l + n,\
    \ r = node_r + n;\n         l < r;\n         l >>= 1, r >>= 1, len <<= 1) {\n\
    \      if (l & 1) {\n        Line line(a, b);\n        add(&line, l++, node_l,\
    \ node_l + len);\n        node_l += len;\n      }\n      if (r & 1) {\n      \
    \  Line line(a, b);\n        node_r -= len;\n        add(&line, --r, node_r, node_r\
    \ + len);\n      }\n    }\n  }\n\n  T query(const T x) const {\n    int node =\
    \ n + std::distance(xs.begin(),\n                                 std::lower_bound(xs.begin(),\
    \ xs.end(), x));\n    T res = dat[node].f(x);\n    while (node >>= 1) {\n    \
    \  if (dat[node].f(x) < res) res = dat[node].f(x);\n    }\n    return IS_MINIMIZED\
    \ ? res : -res;\n  }\n\n private:\n  int n;\n  std::vector<T> xs;\n  std::vector<Line>\
    \ dat;\n\n  void add(Line* line, int node, int left, int right) {\n    const bool\
    \ flag_l = dat[node].f(xs[left]) <= line->f(xs[left]);\n    const bool flag_r\
    \ = dat[node].f(xs[right - 1]) <= line->f(xs[right - 1]);\n    if (flag_l && flag_r)\
    \ return;\n    if (!flag_l && !flag_r) {\n      std::swap(dat[node], *line);\n\
    \      return;\n    }\n    const int mid = std::midpoint(left, right);\n    if\
    \ (line->f(xs[mid]) < dat[node].f(xs[mid])) std::swap(dat[node], *line);\n   \
    \ if (line->f(xs[left]) <= dat[node].f(xs[left])) {\n      add(line, node << 1,\
    \ left, mid);\n    } else {\n      add(line, (node << 1) + 1, mid, right);\n \
    \   }\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DYNAMIC_PROGRAMMING_LI_CHAO_TREE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/li_chao_tree.1.test.cpp
  - test/dynamic_programming/li_chao_tree.2.test.cpp
documentation_of: include/emthrm/dynamic_programming/li_chao_tree.hpp
layout: document
title: Li Chao tree
---

[convex hull trick](cht.md) に対して、傾きに単調性のない直線または線分の追加を可能にするセグメント木である。


## 時間計算量

||時間計算量|
|:--|:--|
|初期化|$O(N \log{N})$|
|直線の追加クエリ|$O(\log{N})$|
|線分の追加クエリ|$O((\log{N})^2)$|
|解答クエリ|$O(\log{N})$|


## 仕様

```cpp
template <typename T, bool IS_MINIMIZED = true>
struct LiChaoTree;
```

- `T`
- `IS_MINIMIZED`：最小化するかを表す変数

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit LiChaoTree(const std::vector<T>& xs_, const T inf);`|解答クエリの $x$ 座標の集合を $\mathrm{xs}$ としてオブジェクトを構築する。||
|`void add(T a, T b);`|直線 $f(x) = ax + b$ を追加する。||
|`void add(T a, T b, T left, T right);`|線分 $f(x) = ax + b$ ($\mathrm{left} \leq x < \mathrm{right}$) を追加する。||
|`T query(const T x) const;`|$\min \text{/} \max \lbrace f(x) \mid f \in L \rbrace$|オフライン|

#### メンバ型

|名前|説明|
|:--|:--|
|`Line`|直線を表す構造体|

```cpp
struct Line;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`T a`|傾き|
|`T b`|切片|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit Line(const T a, const T b);`|直線 $f(x) = ax + b$ を表すオブジェクトを構築する。|
|`T f(const T x) const;`|$f(x)$|


## 参考文献

- https://smijake3.hatenablog.com/entry/2018/06/16/144548
- https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/LiChaoTree
- https://ei1333.github.io/luzhiled/snippets/structure/li-chao-tree.html


## TODO

- https://twitter.com/hirakich1310354/status/1186193990841847810
- 線分の追加クエリの高速化
  - https://smijake3.hatenablog.com/entry/2018/06/16/144548
- 削除可能 Li Chao tree
  - https://sotanishy.github.io/cp-library-cpp/data-structure/cht/undoable_li_chao_tree.cpp
- 動的 Li Chao tree
  - http://kazuma8128.hatenablog.com/entry/2018/02/28/102130
  - https://github.com/ei1333/library/blob/master/structure/dynamic-li-chao-tree.cpp
  - https://github.com/beet-aizu/library/blob/master/datastructure/nonmonotonicconvexhulltrick.cpp
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/DynamicLiChaoTree
  - https://github.com/drken1215/algorithm/blob/master/DP/convex_hull_trick.cpp
  - https://atcoder.jp/contests/colopl2018-final-open/submissions/3219122
  - https://github.com/satanic0258/Cpp_snippet/blob/master/src/technique/ConvexHullTrick.cpp
  - https://tjkendev.github.io/procon-library/cpp/convex_hull_trick/li_chao_tree_dynamic.html
- 永続動的 Li Chao tree
  - https://github.com/ei1333/library/blob/master/structure/persistent-dynamic-li-chao-tree.cpp
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/DynamicPersistentLiChaoTree


## Submissons

- [最小値](https://judge.yosupo.jp/submission/3848)
- [最大値](https://judge.yosupo.jp/submission/3849)
