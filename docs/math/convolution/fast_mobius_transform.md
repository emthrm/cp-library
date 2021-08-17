---
title: 高速メビウス変換 (fast Mobius transform)
documentation_of: math/convolution/fast_mobius_transform.hpp
---

$f(S) = \sum_{S \subseteq T} (-1)^{\lvert T \setminus S \rvert} g(T)$ または $f(S) = \sum_{T \subseteq S} (-1)^{\lvert S \setminus T \rvert} g(T)$ を高速に求める．

[高速ゼータ変換](fast_zeta_transform.md)の逆変換と考えることができる．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`fast_mobius_transform(a, 上位集合に対するメビウス変換か?, 単位元 = 0)`|$A$ に高速メビウス変換を行ったもの|


## 参考

- https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
- https://naoyat.hatenablog.jp/entry/zeta-moebius
- ~~https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform~~


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2446/review/4183902/emthrm/C++14
