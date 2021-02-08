---
title: 逆行列 (inverse matrix)
documentation_of: math/matrix/inverse_matrix.hpp
---


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`inverse<T, U = double>(mat, inv, ε = 1e-8)`|行列 $\mathrm{mat}$ の逆行列が存在するか．|$\mathrm{inv}$ に逆行列が格納される．|


## Verified
