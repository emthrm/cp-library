---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/li_chao_tree.1.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\u5024)"
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/li_chao_tree.2.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024)"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dynamic_programming/li_chao_tree.hpp\"\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <iterator>\r\n#include <utility>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nstruct LiChaoTree {\r\n  struct Line\
    \ {\r\n    T a, b;\r\n    Line(T a, T b) : a(a), b(b) {}\r\n    T f(T x) const\
    \ { return a * x + b; }\r\n  };\r\n\r\n  LiChaoTree(const std::vector<T> &xs_,\
    \ const T inf, bool is_minimized = true) : xs(xs_), is_minimized(is_minimized)\
    \ {\r\n    std::sort(xs.begin(), xs.end());\r\n    xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\r\n    int sz = xs.size();\r\n    assert(sz > 0);\r\n\
    \    while (n < sz) n <<= 1;\r\n    xs.resize(n, xs.back());\r\n    dat.assign(n\
    \ << 1, Line(0, inf));\r\n  }\r\n\r\n  void add(T a, T b) {\r\n    if (!is_minimized)\
    \ {\r\n      a = -a;\r\n      b = -b;\r\n    }\r\n    Line line(a, b);\r\n   \
    \ add(line, 1, 0, n);\r\n  }\r\n\r\n  void add(T a, T b, T left, T right) {\r\n\
    \    if (!is_minimized) {\r\n      a = -a;\r\n      b = -b;\r\n    }\r\n    int\
    \ l = std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), left));\r\
    \n    int r = std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(),\
    \ right));\r\n    int len, node_l = l, node_r = r;\r\n    for (l += n, r += n,\
    \ len = 1; l < r; l >>= 1, r >>= 1, len <<= 1) {\r\n      if (l & 1) {\r\n   \
    \     Line line(a, b);\r\n        add(line, l++, node_l, node_l + len);\r\n  \
    \      node_l += len;\r\n      }\r\n      if (r & 1) {\r\n        Line line(a,\
    \ b);\r\n        node_r -= len;\r\n        add(line, --r, node_r, node_r + len);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  T query(T x) const {\r\n    int node = std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), x));\r\n    node += n;\r\n    T res =\
    \ dat[node].f(x);\r\n    while (node >>= 1) {\r\n      if (dat[node].f(x) < res)\
    \ res = dat[node].f(x);\r\n    }\r\n    return is_minimized ? res : -res;\r\n\
    \  }\r\n\r\nprivate:\r\n  bool is_minimized;\r\n  int n = 1;\r\n  std::vector<T>\
    \ xs;\r\n  std::vector<Line> dat;\r\n\r\n  void add(Line &line, int node, int\
    \ left, int right) {\r\n    bool l = dat[node].f(xs[left]) <= line.f(xs[left]),\
    \ r = dat[node].f(xs[right - 1]) <= line.f(xs[right - 1]);\r\n    if (l && r)\
    \ return;\r\n    if (!l && !r) {\r\n      std::swap(dat[node], line);\r\n    \
    \  return;\r\n    }\r\n    int mid = (left + right) >> 1;\r\n    if (line.f(xs[mid])\
    \ < dat[node].f(xs[mid])) std::swap(dat[node], line);\r\n    if (line.f(xs[left])\
    \ <= dat[node].f(xs[left])) {\r\n      add(line, node << 1, left, mid);\r\n  \
    \  } else {\r\n      add(line, (node << 1) + 1, mid, right);\r\n    }\r\n  }\r\
    \n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <iterator>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct\
    \ LiChaoTree {\r\n  struct Line {\r\n    T a, b;\r\n    Line(T a, T b) : a(a),\
    \ b(b) {}\r\n    T f(T x) const { return a * x + b; }\r\n  };\r\n\r\n  LiChaoTree(const\
    \ std::vector<T> &xs_, const T inf, bool is_minimized = true) : xs(xs_), is_minimized(is_minimized)\
    \ {\r\n    std::sort(xs.begin(), xs.end());\r\n    xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\r\n    int sz = xs.size();\r\n    assert(sz > 0);\r\n\
    \    while (n < sz) n <<= 1;\r\n    xs.resize(n, xs.back());\r\n    dat.assign(n\
    \ << 1, Line(0, inf));\r\n  }\r\n\r\n  void add(T a, T b) {\r\n    if (!is_minimized)\
    \ {\r\n      a = -a;\r\n      b = -b;\r\n    }\r\n    Line line(a, b);\r\n   \
    \ add(line, 1, 0, n);\r\n  }\r\n\r\n  void add(T a, T b, T left, T right) {\r\n\
    \    if (!is_minimized) {\r\n      a = -a;\r\n      b = -b;\r\n    }\r\n    int\
    \ l = std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(), left));\r\
    \n    int r = std::distance(xs.begin(), std::lower_bound(xs.begin(), xs.end(),\
    \ right));\r\n    int len, node_l = l, node_r = r;\r\n    for (l += n, r += n,\
    \ len = 1; l < r; l >>= 1, r >>= 1, len <<= 1) {\r\n      if (l & 1) {\r\n   \
    \     Line line(a, b);\r\n        add(line, l++, node_l, node_l + len);\r\n  \
    \      node_l += len;\r\n      }\r\n      if (r & 1) {\r\n        Line line(a,\
    \ b);\r\n        node_r -= len;\r\n        add(line, --r, node_r, node_r + len);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  T query(T x) const {\r\n    int node = std::distance(xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), x));\r\n    node += n;\r\n    T res =\
    \ dat[node].f(x);\r\n    while (node >>= 1) {\r\n      if (dat[node].f(x) < res)\
    \ res = dat[node].f(x);\r\n    }\r\n    return is_minimized ? res : -res;\r\n\
    \  }\r\n\r\nprivate:\r\n  bool is_minimized;\r\n  int n = 1;\r\n  std::vector<T>\
    \ xs;\r\n  std::vector<Line> dat;\r\n\r\n  void add(Line &line, int node, int\
    \ left, int right) {\r\n    bool l = dat[node].f(xs[left]) <= line.f(xs[left]),\
    \ r = dat[node].f(xs[right - 1]) <= line.f(xs[right - 1]);\r\n    if (l && r)\
    \ return;\r\n    if (!l && !r) {\r\n      std::swap(dat[node], line);\r\n    \
    \  return;\r\n    }\r\n    int mid = (left + right) >> 1;\r\n    if (line.f(xs[mid])\
    \ < dat[node].f(xs[mid])) std::swap(dat[node], line);\r\n    if (line.f(xs[left])\
    \ <= dat[node].f(xs[left])) {\r\n      add(line, node << 1, left, mid);\r\n  \
    \  } else {\r\n      add(line, (node << 1) + 1, mid, right);\r\n    }\r\n  }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_programming/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/li_chao_tree.2.test.cpp
  - test/dynamic_programming/li_chao_tree.1.test.cpp
documentation_of: dynamic_programming/li_chao_tree.hpp
layout: document
title: Li Chao tree
---

[convex hull trick](cht.md) において傾きに単調性のない直線または線分の追加を可能にするセグメント木である．


## 時間計算量

|処理|時間計算量|
|:--:|:--:|
|初期化|$O(N \log{N})$|
|直線の追加クエリ|$O(\log{N})$|
|線分の追加クエリ|$O((\log{N})^2)$|
|解答クエリ|$O(\log{N})$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`LiChaoTree<T>(xs, ∞, is_minimized = true)`|解答クエリの $x$ 座標の集合が $\mathrm{xs}$ である Li Chao tree||
|`add(a, b)`|直線 $f(x) = ax + b$ を追加する．||
|`add(a, b, left, right)`|線分 $f(x) = ax + b \ (\mathrm{left} \leq x < \mathrm{right})$ を追加する．||
|`query(x)`|$\min \text{/} \max \lbrace f(x) \mid f \in L \rbrace$|オフライン|


## 参考

- https://smijake3.hatenablog.com/entry/2018/06/16/144548
- https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/LiChaoTree
- https://ei1333.github.io/luzhiled/snippets/structure/li-chao-tree.html


## ToDo

- https://twitter.com/hirakich1310354/status/1186193990841847810
- 線分の追加クエリの高速化
  - https://smijake3.hatenablog.com/entry/2018/06/16/144548
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


## Verified

- [最小値](https://judge.yosupo.jp/submission/3848)
- [最大値](https://judge.yosupo.jp/submission/3849)
