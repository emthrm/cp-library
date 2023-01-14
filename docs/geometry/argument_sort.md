---
title: 偏角ソート
documentation_of: include/emthrm/geometry/argument_sort.hpp
---


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`argument_sort(&ps)`|点集合 $\mathrm{ps}$ に対して偏角ソートを行う。|$\arg(x) = \pi$ ($x < 0$), $\arg(0) = 0$ とする。|


## 参考文献

- https://betrue12.hateblo.jp/entry/2020/01/05/151244
- https://github.com/beet-aizu/library/blob/78fef02c3ce4f982525361a55adbfc78faabfb93/geometry/argsort.cpp


## Submissons

https://judge.yosupo.jp/submission/6794
