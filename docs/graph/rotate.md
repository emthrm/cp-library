---
title: 回転 (rotation)
documentation_of: graph/rotate.hpp
---

点の回転は

- $45^\circ$ の場合，$(x, y) \rightarrow (x - y, x + y)$
- $90^\circ$ の場合，$(x, y) \rightarrow (-y, x)$

と変換すればよい．


## 時間計算量

$O(WH)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`rotate(grid, angle, 基準 = ' ')`|グリッド $\mathrm{grid}$ を $\mathrm{angle}$ 度だけ回転させたもの|$\mathrm{angle} \in \lbrace 45, 90 \rbrace$|


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2953/review/4082725/emthrm/C++14
