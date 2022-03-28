---
title: convex hull trick
documentation_of: dynamic_programming/convex_hull_trick.hpp
---

$xy$ 平面上の直線集合 $L$ を考える．

- $L$ に直線 $f(x) = ax + b$ を追加する．
- ある $x$ に対して $\min \lbrace f(x) \mid f \in L \rbrace$ を答える．

上のクエリを高速に処理できるテクニックである．


## 時間計算量

|処理|時間計算量|
|:--:|:--:|
|追加クエリ|amortized $O(1)$|
|解答クエリ|$O(\log{N})$|
|$x$ に単調性のある解答クエリ|amortized $O(1)$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`ConvexHullTrick<T, IS_MINIMIZED>()`|convex hull trick||
|`add(a, b)`|直線 $f(x) = ax + b$ を追加する．|傾きには単調性が必要である．|
|`query(x)`|$\min \text{/} \max \lbrace f(x) \mid f \in L \rbrace$||
|`monotonically_increasing_query(x)`|`query(x)`|$x$ は単調増加しなければならない．|
|`monotonically_decreasing_query(x)`|`query(x)`|$x$ は単調減少しなければならない．|


## 参考

- http://satanic0258.hatenablog.com/entry/2016/08/16/181331
- https://ei1333.github.io/luzhiled/snippets/structure/convex-hull-trick-add-monotone.html


## ToDo

- 直線を削除できる．
  - ~~https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/RemovableCHT~~
  - https://codeforces.com/blog/entry/60514
- 追加する直線の傾きに単調性が必要ない．
  - https://sune2.hatenadiary.org/entry/20140310/1394440369
  - ~~https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/CHT-Ex~~
- $x \in \mathbb{Z}$
  - https://noshi91.hatenablog.com/entry/2021/03/23/200810
  - https://judge.yosupo.jp/submission/35152
- 永続 convex full trick
  - https://codeforces.com/blog/entry/51684
- $\min_i \lbrace A_i x + B_i y \rbrace$
  - https://twitter.com/maspy_stars/status/1502589106039123970
  - 第41回TechFUL Coding Battle「最大値はいくつ？」
  - https://atcoder.jp/contests/abc244/tasks/abc244_h


## Verified

- [`query(x)`](https://atcoder.jp/contests/dp/submissions/26064258)
- [`monotonically_increasing_query(x)`](https://atcoder.jp/contests/dp/submissions/26064281)
- [`monotonically_decreasing_query(x)`](https://atcoder.jp/contests/dp/submissions/26064320)
