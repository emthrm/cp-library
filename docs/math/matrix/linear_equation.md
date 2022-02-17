---
title: 連立一次方程式 (linear equation)
documentation_of: math/matrix/linear_equation.hpp
---


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`linear_equation(a, b, ε = 1e-8)`|$A \boldsymbol{x} = \boldsymbol{b}$ を満たす $\boldsymbol{x}$|解なしのときは空配列となる．|


## ToDo

- https://judge.yosupo.jp/problem/system_of_linear_equations
- LU 分解
  - https://ja.wikipedia.org/wiki/LU%E5%88%86%E8%A7%A3
  - https://github.com/satanic0258/Cpp_snippet/blob/master/src/math/LUdecomposition.cpp
  - http://www.prefield.com/algorithm/math/LU.html
- 疎行列の連立一次方程式
  - https://drive.google.com/file/d/1D7sRmUy-0XnZCay8Tr1PldJVFRM2NII5


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2171/review/5899058/emthrm/C++17
