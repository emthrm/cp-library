---
title: 基底 (basis)
documentation_of: include/emthrm/math/basis.hpp
---


## 仕様

|名前|効果・戻り値|
|:--|:--|
|`Basis<D>()`|長さ $D$ の基底を考える。|
|`v`|ベクトル空間|
|`msb[i]`|$i$ 番目のベクトルの最上位ビット|
|`add(val)`|ベクトル $\mathrm{val}$ を加えたのち、要素数が増えたかを返す。|
|`rank()`|要素数|
|`operator<(x)`||


## 参考文献

- http://www.kupc.jp/static/media/K.290ca2fd.pdf
- https://xuzijian629.hatenablog.com/entry/2019/10/30/013225
- https://atcoder.jp/contests/kupc2012/submissions/7660727


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2416/review/5214392/emthrm/C++17
