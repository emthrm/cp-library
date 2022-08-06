---
title: Li Chao tree
documentation_of: dynamic_programming/li_chao_tree.hpp
---

[convex hull trick](cht.md) に対して，傾きに単調性のない直線または線分の追加を可能にするセグメント木である．


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
|`LiChaoTree<T, IS_MINIMIZED = true>(xs, ∞)`|解答クエリの $x$ 座標の集合が $\mathrm{xs}$ である Li Chao tree||
|`add(a, b)`|直線 $f(x) = ax + b$ を追加する．||
|`add(a, b, left, right)`|線分 $f(x) = ax + b$ ($\mathrm{left} \leq x < \mathrm{right}$) を追加する．||
|`query(x)`|$\min \text{/} \max \lbrace f(x) \mid f \in L \rbrace$|オフライン|


## 参考

- https://smijake3.hatenablog.com/entry/2018/06/16/144548
- https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/LiChaoTree
- https://ei1333.github.io/luzhiled/snippets/structure/li-chao-tree.html


## ToDo

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


## Verified

- [最小値](https://judge.yosupo.jp/submission/3848)
- [最大値](https://judge.yosupo.jp/submission/3849)
