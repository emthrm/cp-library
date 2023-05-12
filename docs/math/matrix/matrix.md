---
title: 行列 (matrix)
documentation_of: //include/emthrm/math/matrix/matrix.hpp
---


## 時間計算量

||時間計算量|
|:--|:--|
|加算|$O(MN)$|
|減算|$O(MN)$|
|乗算|$O(N^3)$|
|行列累乗|$O(N^3 \log{E})$|


## 仕様

```cpp
template <typename T>
struct Matrix;
```

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit Matrix(const int m, const int n, const T def = 0);`|初期値 $\mathrm{def}$ の $M \times N$ 型行列を表すオブジェクトを構築する。||
|`int nrow() const;`|$M$||
|`int ncol() const;`|$N$||
|`Matrix pow(long long exponent) const;`|$A^\mathrm{exponent}$|半環上で成立する。|
|`inline const std::vector<T>& operator[](const int i) const;`<br>`inline std::vector<T>& operator[](const int i);`|$A$ の $i$ 行目||
|`Matrix& operator=(const Matrix& x);`|代入演算子||
|`Matrix& operator+=(const Matrix& x);`<br>`Matrix operator+(const Matrix& x) const;`|加算||
|``Matrix& operator-=(const Matrix& x);``<br>`Matrix operator-(const Matrix& x) const;`|減算||
|`Matrix& operator*=(const Matrix& x);`<br>`Matrix operator*(const Matrix& x) const;`|乗算|半環上で成立する。|


## 参考文献

- https://ei1333.github.io/luzhiled/snippets/math/matrix.html


## TODO

- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!Matrix.cpp~~
- 疎行列 (sparse matrix)
  - https://ja.wikipedia.org/wiki/%E7%96%8E%E8%A1%8C%E5%88%97
  - https://github.com/ei1333/library/blob/master/math/sparse-matrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SparseMatrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SparseSquareMatrix.cpp
  - https://judge.yosupo.jp/problem/sparse_matrix_det
  - https://atcoder.jp/contests/indeednow-finala-open/tasks/indeednow_2015_finala_e
- 正方行列 (square matrix)
  - https://ja.wikipedia.org/wiki/%E6%AD%A3%E6%96%B9%E8%A1%8C%E5%88%97
  - https://github.com/beet-aizu/library/blob/master/matrix/squarematrix.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Math/SquareMatrix.cpp
- 固有値, 固有ベクトル
  - https://ja.wikipedia.org/wiki/%E5%9B%BA%E6%9C%89%E5%80%A4
  - ~~http://www.prefield.com/algorithm/math/eigensystem.html~~
- ハフニアン (hafnian)
  - https://mathtrain.jp/pfaffian
  - https://en.wikipedia.org/wiki/Hafnian
  - https://github.com/yosupo06/library-checker-problems/issues/467
  - https://judge.yosupo.jp/problem/hafnian_of_matrix


## Submissons

https://judge.yosupo.jp/submission/45071
