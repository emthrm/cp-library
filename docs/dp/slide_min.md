---
title: スライド最小値
documentation_of: dp/slide_min.hpp
---


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`slide_min(a, len)`|$A$ における長さ $\mathrm{len}$ のスライド最小値|


## 備考

スライド最大値を求める場合，16行目の `a[deq.back()] >= a[i]` を `a[deq.back()] <= a[i]` とすればよい．


## 参考

- https://satanic0258.github.io/snippets/data-structure/SlideMinimum.html
- https://ei1333.github.io/luzhiled/snippets/dp/slide-min.html


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_D/review/4967096/emthrm/C++17
