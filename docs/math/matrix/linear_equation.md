---
title: 連立一次方程式 (linear equation)
documentation_of: include/emthrm/math/matrix/linear_equation.hpp
---


## 時間計算量

$O(M^2 N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T, typename U = double> std::vector<U> linear_equation(const Matrix<T>& a, const std::vector<T>& b, const U eps = 1e-8);`|$A \boldsymbol{x} = \boldsymbol{b}$ を満たす $\boldsymbol{x}$。ただし解なしのときは空配列を返す。|


## TODO

- https://sotanishy.github.io/cp-library-cpp/math/system_of_linear_equations.cpp
- https://judge.yosupo.jp/problem/system_of_linear_equations
- LU 分解
  - https://ja.wikipedia.org/wiki/LU%E5%88%86%E8%A7%A3
  - https://github.com/satanic0258/Cpp_snippet/blob/master/src/math/LUdecomposition.cpp
  - http://www.prefield.com/algorithm/math/LU.html
- 疎行列の連立一次方程式
  - https://drive.google.com/file/d/1D7sRmUy-0XnZCay8Tr1PldJVFRM2NII5


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2171/review/5899058/emthrm/C++17
