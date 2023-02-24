---
title: 回転 (rotation)
documentation_of: //include/emthrm/misc/rotate.hpp
---

点の回転は

- $45^\circ$ のとき $(x, y) \rightarrow (x - y, x + y)$、
- $90^\circ$ のとき $(x, y) \rightarrow (-y, x)$

と変換すればよい。


## 時間計算量

$O(HW)$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <int ANGLE, typename T>`<br>`std::vector<std::vector<T>> rotate(const std::vector<std::vector<T>>& grid, const T space = ' ');`|グリッド $\mathrm{grid}$ を $\mathrm{ANGLE}$ 度だけ回転させたもの|$\mathrm{ANGLE} \in \lbrace 45, 90 \rbrace$|


## 参考文献

- https://kagamiz.hatenablog.com/entry/2014/12/21/213931


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2953/review/4082725/emthrm/C++14
