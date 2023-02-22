---
title: クロネッカー冪 (Kronecker power) とベクトルの積
documentation_of: include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
---

$G \in K^{d \times d},\ \boldsymbol{v} \in K^{d^n}$ に対して $G^{\otimes n} \boldsymbol{v}$ を求める。ここで
$$
A \otimes B \mathrel{:=}
\begin{pmatrix}
  a_{11} B & \cdots & a_{1n} B \\
  \vdots   & \ddots & \vdots   \\
  a_{m1} B & \cdots & a_{mn} B
\end{pmatrix}
\quad (A \in K^{m \times n})
$$
はクロネッカー積である。


## 時間計算量

$O(N D^{N + 1})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> kronecker_power_vector_multiplication(const Matrix<T>& g, std::vector<T> v);`|$G^{\otimes n} \boldsymbol{v}$|


## 参考文献

- http://q.c.titech.ac.jp/docs/progs/kronecker.html
- https://suisen-cp.github.io/cp-library-cpp/library/transform/kronecker_power.hpp


## Submissons

https://atcoder.jp/contests/abc288/submissions/39117221
