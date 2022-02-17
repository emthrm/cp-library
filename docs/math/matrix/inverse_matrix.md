---
title: 逆行列 (inverse matrix)
documentation_of: math/matrix/inverse_matrix.hpp
---


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`inverse<T, U = double>(a, ε = 1e-8)`|行列 $A$ の逆行列|存在しないときは空行列となる．|


## Verified

https://judge.yosupo.jp/submission/50854
