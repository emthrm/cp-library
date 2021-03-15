---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/inverse_matrix.hpp\"\n#include <cassert>\r\n\
    #include <cmath>\r\n#include <utility>\r\n#line 3 \"math/matrix/matrix.hpp\"\n\
    #include <vector>\r\n\r\ntemplate <typename T>\r\nstruct Matrix {\r\n  Matrix(int\
    \ m, int n, T val = 0) : dat(m, std::vector<T>(n, val)) {}\r\n\r\n  int height()\
    \ const { return dat.size(); }\r\n\r\n  int width() const { return dat.front().size();\
    \ }\r\n\r\n  Matrix pow(long long exponent) const {\r\n    int n = height();\r\
    \n    Matrix<T> tmp = *this, res(n, n, 0);\r\n    for (int i = 0; i < n; ++i)\
    \ res[i][i] = 1;\r\n    while (exponent > 0) {\r\n      if (exponent & 1) res\
    \ *= tmp;\r\n      tmp *= tmp;\r\n      exponent >>= 1;\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  inline const std::vector<T> &operator[](const int idx)\
    \ const { return dat[idx]; }\r\n  inline std::vector<T> &operator[](const int\
    \ idx) { return dat[idx]; }\r\n\r\n  Matrix &operator=(const Matrix &x) {\r\n\
    \    int m = x.height(), n = x.width();\r\n    dat.resize(m, std::vector<T>(n));\r\
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
    \n\r\nprivate:\r\n  std::vector<std::vector<T>> dat;\r\n};\r\n#line 6 \"math/matrix/inverse_matrix.hpp\"\
    \n\r\ntemplate <typename T, typename U = double>\r\nMatrix<U> inverse_matrix(const\
    \ Matrix<T> &mat, const U EPS = 1e-8) {\r\n  int n = mat.height();\r\n  Matrix<U>\
    \ gauss_jordan(n, n << 1, 0);\r\n  for (int i = 0; i < n; ++i) {\r\n    for (int\
    \ j = 0; j < n; ++j) gauss_jordan[i][j] = mat[i][j];\r\n    gauss_jordan[i][n\
    \ + i] = 1;\r\n  }\r\n  for (int col = 0; col < n; ++col) {\r\n    int pivot =\
    \ -1;\r\n    U mx = EPS;\r\n    for (int row = col; row < n; ++row) {\r\n    \
    \  if (std::abs(gauss_jordan[row][col]) > mx) {\r\n        pivot = row;\r\n  \
    \      mx = std::abs(gauss_jordan[row][col]);\r\n      }\r\n    }\r\n    if (pivot\
    \ == -1) return Matrix<U>(0, 0);\r\n    std::swap(gauss_jordan[col], gauss_jordan[pivot]);\r\
    \n    U tmp = gauss_jordan[col][col];\r\n    for (int col2 = 0; col2 < (n << 1);\
    \ ++col2) gauss_jordan[col][col2] /= tmp;\r\n    for (int row = 0; row < n; ++row)\
    \ {\r\n      if (row != col && std::abs(gauss_jordan[row][col]) > EPS) {\r\n \
    \       tmp = gauss_jordan[row][col];\r\n        for (int col2 = 0; col2 < (n\
    \ << 1); ++col2) gauss_jordan[row][col2] -= gauss_jordan[col][col2] * tmp;\r\n\
    \      }\r\n    }\r\n  }\r\n  Matrix<U> inv(n, n);\r\n  for (int i = 0; i < n;\
    \ ++i) for (int j = 0; j < n; ++j) inv[i][j] = gauss_jordan[i][n + j];\r\n  return\
    \ inv;\r\n}\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <cmath>\r\n#include <utility>\r\
    \n#include \"matrix.hpp\"\r\n\r\ntemplate <typename T, typename U = double>\r\n\
    Matrix<U> inverse_matrix(const Matrix<T> &mat, const U EPS = 1e-8) {\r\n  int\
    \ n = mat.height();\r\n  Matrix<U> gauss_jordan(n, n << 1, 0);\r\n  for (int i\
    \ = 0; i < n; ++i) {\r\n    for (int j = 0; j < n; ++j) gauss_jordan[i][j] = mat[i][j];\r\
    \n    gauss_jordan[i][n + i] = 1;\r\n  }\r\n  for (int col = 0; col < n; ++col)\
    \ {\r\n    int pivot = -1;\r\n    U mx = EPS;\r\n    for (int row = col; row <\
    \ n; ++row) {\r\n      if (std::abs(gauss_jordan[row][col]) > mx) {\r\n      \
    \  pivot = row;\r\n        mx = std::abs(gauss_jordan[row][col]);\r\n      }\r\
    \n    }\r\n    if (pivot == -1) return Matrix<U>(0, 0);\r\n    std::swap(gauss_jordan[col],\
    \ gauss_jordan[pivot]);\r\n    U tmp = gauss_jordan[col][col];\r\n    for (int\
    \ col2 = 0; col2 < (n << 1); ++col2) gauss_jordan[col][col2] /= tmp;\r\n    for\
    \ (int row = 0; row < n; ++row) {\r\n      if (row != col && std::abs(gauss_jordan[row][col])\
    \ > EPS) {\r\n        tmp = gauss_jordan[row][col];\r\n        for (int col2 =\
    \ 0; col2 < (n << 1); ++col2) gauss_jordan[row][col2] -= gauss_jordan[col][col2]\
    \ * tmp;\r\n      }\r\n    }\r\n  }\r\n  Matrix<U> inv(n, n);\r\n  for (int i\
    \ = 0; i < n; ++i) for (int j = 0; j < n; ++j) inv[i][j] = gauss_jordan[i][n +\
    \ j];\r\n  return inv;\r\n}\r\n"
  dependsOn:
  - math/matrix/matrix.hpp
  isVerificationFile: false
  path: math/matrix/inverse_matrix.hpp
  requiredBy: []
  timestamp: '2021-03-04 20:20:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix/inverse_matrix.hpp
layout: document
title: "\u9006\u884C\u5217 (inverse matrix)"
---


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`inverse<T, U = double>(mat, ε = 1e-8)`|行列 $\mathrm{mat}$ の逆行列|存在しない場合は空行列となる．|
