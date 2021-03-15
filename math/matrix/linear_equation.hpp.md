---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss-Jordan elimination)"
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/linear_equation.hpp\"\n#include <cmath>\r\n\
    #include <vector>\r\n#line 2 \"math/matrix/matrix.hpp\"\n#include <utility>\r\n\
    #line 4 \"math/matrix/matrix.hpp\"\n\r\ntemplate <typename T>\r\nstruct Matrix\
    \ {\r\n  Matrix(int m, int n, T val = 0) : dat(m, std::vector<T>(n, val)) {}\r\
    \n\r\n  int height() const { return dat.size(); }\r\n\r\n  int width() const {\
    \ return dat.front().size(); }\r\n\r\n  Matrix pow(long long exponent) const {\r\
    \n    int n = height();\r\n    Matrix<T> tmp = *this, res(n, n, 0);\r\n    for\
    \ (int i = 0; i < n; ++i) res[i][i] = 1;\r\n    while (exponent > 0) {\r\n   \
    \   if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n      exponent >>= 1;\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  inline const std::vector<T> &operator[](const\
    \ int idx) const { return dat[idx]; }\r\n  inline std::vector<T> &operator[](const\
    \ int idx) { return dat[idx]; }\r\n\r\n  Matrix &operator=(const Matrix &x) {\r\
    \n    int m = x.height(), n = x.width();\r\n    dat.resize(m, std::vector<T>(n));\r\
    \n    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] = x[i][j];\r\
    \n    return *this;\r\n  }\r\n\r\n  Matrix &operator+=(const Matrix &x) {\r\n\
    \    int m = height(), n = width();\r\n    for (int i = 0; i < m; ++i) for (int\
    \ j = 0; j < n; ++j) dat[i][j] += x[i][j];\r\n    return *this;\r\n  }\r\n\r\n\
    \  Matrix &operator-=(const Matrix &x) {\r\n    int m = height(), n = width();\r\
    \n    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] -= x[i][j];\r\
    \n    return *this;\r\n  }\r\n\r\n  Matrix &operator*=(const Matrix &x) {\r\n\
    \    int m = height(), n = x.width(), l = width();\r\n    std::vector<std::vector<T>>\
    \ res(m, std::vector<T>(n, 0));\r\n    for (int i = 0; i < m; ++i) for (int j\
    \ = 0; j < n; ++j) {\r\n      for (int k = 0; k < l; ++k) res[i][j] += dat[i][k]\
    \ * x[k][j];\r\n    }\r\n    std::swap(dat, res);\r\n    return *this;\r\n  }\r\
    \n\r\n  Matrix operator+(const Matrix &x) const { return Matrix(*this) += x; }\r\
    \n\r\n  Matrix operator-(const Matrix &x) const { return Matrix(*this) -= x; }\r\
    \n\r\n  Matrix operator*(const Matrix &x) const { return Matrix(*this) *= x; }\r\
    \n\r\nprivate:\r\n  std::vector<std::vector<T>> dat;\r\n};\r\n#line 5 \"math/matrix/gauss_jordan.hpp\"\
    \n\r\ntemplate <typename T>\r\nint gauss_jordan(Matrix<T> &mat, const T EPS =\
    \ 1e-8, bool is_extended = false) {\r\n  int m = mat.height(), n = mat.width(),\
    \ rank = 0;\r\n  for (int col = 0; col < n; ++col) {\r\n    if (is_extended &&\
    \ col == n - 1) break;\r\n    int pivot = -1;\r\n    T mx = EPS;\r\n    for (int\
    \ row = rank; row < m; ++row) {\r\n      if (std::abs(mat[row][col]) > mx) {\r\
    \n        pivot = row;\r\n        mx = std::abs(mat[row][col]);\r\n      }\r\n\
    \    }\r\n    if (pivot == -1) continue;\r\n    std::swap(mat[rank], mat[pivot]);\r\
    \n    T tmp = mat[rank][col];\r\n    for (int col2 = 0; col2 < n; ++col2) mat[rank][col2]\
    \ /= tmp;\r\n    for (int row = 0; row < m; ++row) {\r\n      if (row != rank\
    \ && std::abs(mat[row][col]) > EPS) {\r\n        tmp = mat[row][col];\r\n    \
    \    for (int col2 = 0; col2 < n; ++col2) mat[row][col2] -= mat[rank][col2] *\
    \ tmp;\r\n      }\r\n    }\r\n    ++rank;\r\n  }\r\n  return rank;\r\n}\r\n#line\
    \ 6 \"math/matrix/linear_equation.hpp\"\n\r\ntemplate <typename T, typename U\
    \ = double>\r\nstd::vector<U> linear_equation(const Matrix<T> &a, const std::vector<T>\
    \ &b, const U EPS = 1e-8) {\r\n  int m = a.height(), n = a.width();\r\n  Matrix<U>\
    \ matrix(m, n + 1);\r\n  for (int i = 0; i < m; ++i) {\r\n    for (int j = 0;\
    \ j < n; ++j) matrix[i][j] = a[i][j];\r\n    matrix[i][n] = b[i];\r\n  }\r\n \
    \ int rank = gauss_jordan(matrix, EPS, true);\r\n  for (int row = rank; row <\
    \ m; ++row) {\r\n    if (std::abs(matrix[row][n]) > EPS) return std::vector<U>();\r\
    \n  }\r\n  std::vector<U> res(n, 0);\r\n  for (int i = 0, j = 0; i < rank; ++i)\
    \ {\r\n    while (std::abs(matrix[i][j]) < EPS) ++j;\r\n    res[j++] = matrix[i][n];\r\
    \n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <cmath>\r\n#include <vector>\r\n#include \"matrix.hpp\"\
    \r\n#include \"gauss_jordan.hpp\"\r\n\r\ntemplate <typename T, typename U = double>\r\
    \nstd::vector<U> linear_equation(const Matrix<T> &a, const std::vector<T> &b,\
    \ const U EPS = 1e-8) {\r\n  int m = a.height(), n = a.width();\r\n  Matrix<U>\
    \ matrix(m, n + 1);\r\n  for (int i = 0; i < m; ++i) {\r\n    for (int j = 0;\
    \ j < n; ++j) matrix[i][j] = a[i][j];\r\n    matrix[i][n] = b[i];\r\n  }\r\n \
    \ int rank = gauss_jordan(matrix, EPS, true);\r\n  for (int row = rank; row <\
    \ m; ++row) {\r\n    if (std::abs(matrix[row][n]) > EPS) return std::vector<U>();\r\
    \n  }\r\n  std::vector<U> res(n, 0);\r\n  for (int i = 0, j = 0; i < rank; ++i)\
    \ {\r\n    while (std::abs(matrix[i][j]) < EPS) ++j;\r\n    res[j++] = matrix[i][n];\r\
    \n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - math/matrix/matrix.hpp
  - math/matrix/gauss_jordan.hpp
  isVerificationFile: false
  path: math/matrix/linear_equation.hpp
  requiredBy: []
  timestamp: '2021-03-07 03:49:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/matrix/linear_equation.test.cpp
documentation_of: math/matrix/linear_equation.hpp
layout: document
title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
---


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`linear_equation(a, b)`|$\boldsymbol{x} \text{ s.t. } A \boldsymbol{x} = \boldsymbol{b}$|解なしの場合は空配列となる．|


## ToDo

- https://judge.yosupo.jp/problem/system_of_linear_equations
- LU 分解
  - https://ja.wikipedia.org/wiki/LU%E5%88%86%E8%A7%A3
  - https://github.com/satanic0258/Cpp_snippet/blob/master/src/math/LUdecomposition.cpp
  - http://www.prefield.com/algorithm/math/LU.html
- 疎行列の連立一次方程式
  - https://drive.google.com/file/d/1D7sRmUy-0XnZCay8Tr1PldJVFRM2NII5


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0004/review/5272538/emthrm/C++17
