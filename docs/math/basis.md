---
title: 基底 (basis)
documentation_of: math/basis.hpp
---


## 時間計算量

$O(ND)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Basis<D>()`|長さ $D$ の基底を考える．||
|`v`|ベクトル空間||
|`msb`|各ベクトルの最上位ビット||
|`add(val)`|ベクトル $\mathrm{val}$ を追加する．|返り値は要素数が増えたか．|
|`rank()`|基底の要素数||
|`<`|||


## 参考

- http://www.kupc.jp/static/media/K.290ca2fd.pdf
- https://xuzijian629.hatenablog.com/entry/2019/10/30/013225
- https://atcoder.jp/contests/kupc2012/submissions/7660727


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2416/review/4235348/emthrm/C++14
