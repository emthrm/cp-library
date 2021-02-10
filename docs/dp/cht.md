---
title: convex hull trick
documentation_of: dp/cht.hpp
---

$xy$ 平面上の直線集合 $L$ を考える．

- $L$ に直線 $f(x) = ax + b$ を追加する．
- ある $x$ について $\min \lbrace \,f(x) \mid f \in L \rbrace$ を答える．

上記のクエリを高速に処理できるものである．


## 時間計算量

|処理|時間計算量|
|:--:|:--:|
|追加クエリ|$O(N)$|
|解答クエリ|$O(Q\log{N})$|
|$x$ に単調性のある解答クエリ|$O(Q + N)$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`CHT<T>(is_minimized = true)`|convex hull trick||
|`add(a, b)`|直線 $f(x) = ax + b$ を追加する．|傾きには単調性が必要である．|
|`query(x)`|$\min \text{/} \max \lbrace \,f(x) \mid f \in L \rbrace$||
|`monotone_inc_query(x)`|$x$ が単調増加している場合の `query(x)`||
|`monotone_dec_query(x)`|$x$ が単調減少している場合の `query(x)`||


## 参考

- http://satanic0258.hatenablog.com/entry/2016/08/16/181331
- https://ei1333.github.io/luzhiled/snippets/structure/convex-hull-trick-add-monotone.html


## ToDo

- 直線の削除可能
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/RemovableCHT
  - https://codeforces.com/blog/entry/60514
- 追加する直線の傾きに単調性が不必要である．
  - https://sune2.hatenadiary.org/entry/20140310/1394440369
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/convex-hull-trick/CHT-Ex
- 永続 convex full trick
  - https://codeforces.com/blog/entry/51684


## Verified

- [`query(x)`](https://atcoder.jp/contests/colopl2018-final-open/submissions/9239248)
- [`monotone_inc_query(x)`](https://atcoder.jp/contests/colopl2018-final-open/submissions/9239153)
- [`monotone_dec_query(x)`](https://atcoder.jp/contests/colopl2018-final-open/submissions/9239293)
