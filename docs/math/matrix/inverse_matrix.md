---
title: 逆行列 (inverse matrix)
documentation_of: include/emthrm/math/matrix/inverse_matrix.hpp
---


## 時間計算量

$O(M^2 N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T, typename U = double> Matrix<U> inverse_matrix(const Matrix<T>& a, const U eps = 1e-8);`|行列 $A$ の逆行列。ただし存在しないときは空行列を返す。|


## Submissons

https://judge.yosupo.jp/submission/50854
