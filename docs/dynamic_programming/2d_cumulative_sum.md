---
title: 2次元累積和
documentation_of: include/emthrm/dynamic_programming/2d_cumulative_sum.hpp
---


## 時間計算量

$O(HW)$


## 仕様

```cpp
template <typename T>
struct CumulativeSum2D;
```

- `T`：要素型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit CumulativeSum2D(const int h, const int w);`|高さ $H$、幅 $W$ のオブジェクトを構築する。|
|`template <typename U>`<br>`explicit CumulativeSum2D(const std::vector<std::vector<U>>& a);`|$A$ に対してオブジェクトを構築する。|
|`void add(const int y, const int x, const T val);`|$A_{yx} \gets A_{yx} + \mathrm{val}$|
|`void build();`|構築する。|
|`T query(const int y1, const int x1, const int y2, const int x2) const;`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|


## Submissons

https://atcoder.jp/contests/abc086/submissions/26008164
