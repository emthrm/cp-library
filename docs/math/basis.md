---
title: 基底 (basis)
documentation_of: //include/emthrm/math/basis.hpp
---


## 仕様

```cpp
template <int D>
struct Basis;
```

- `D`：ビット幅

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<std::bitset<D>> v`|ベクトル空間|
|`std::vector<int> msb`|$i$ 番目のベクトルの最上位ビット|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`Basis();`|デフォルトコンストラクタ|
|`bool add(std::bitset<D> val);`|ベクトル $\mathrm{val}$ を加えたのち、実際に要素数が増えたかを返す。|
|`int rank() const;`|要素数|
|`inline bool operator<(const Basis& x) const;`||


## 参考文献

- http://www.kupc.jp/static/media/K.290ca2fd.pdf
- https://xuzijian629.hatenablog.com/entry/2019/10/30/013225
- https://atcoder.jp/contests/kupc2012/submissions/7660727


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2416/review/5214392/emthrm/C++17
