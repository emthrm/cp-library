---
title: 2次元累積和
documentation_of: dynamic_programming/2d_cumulative_sum.hpp
---


## 時間計算量

$O(HW)$


## 使用法

||説明|
|:--:|:--:|
|`CumulativeSum2D<T>(h, w)`|高さ $H$, 幅 $W$ の2次元累積和を考える．|
|`CumulativeSum2D<T>(a)`|$A$ の2次元累積和を考える．|
|`add(y, x, val)`|$A_{yx} \gets A_{yx} + \mathrm{val}$|
|`build()`|構築する．|
|`query(y1, x1, y2, x2)`|$\sum_{i = y_1}^{y_2} \sum_{j = x_1}^{x_2} A_{ij}$|


## Verified

https://atcoder.jp/contests/abc086/submissions/26008164
