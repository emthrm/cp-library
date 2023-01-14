---
title: 逆行列 (inverse matrix)
documentation_of: include/emthrm/math/matrix/inverse_matrix.hpp
---


## 時間計算量

$O(M^2 N)$


## 仕様

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`inverse<T, U = double>(a, ε = 1e-8)`|行列 $A$ の逆行列|存在しないときは空行列となる。|


## Submissons

https://judge.yosupo.jp/submission/50854
