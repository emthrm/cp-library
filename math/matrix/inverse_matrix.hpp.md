---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/inverse_matrix.hpp\"\n#include <algorithm>\r\
    \n#include <iterator>\r\n#include <utility>\r\n\r\n#line 2 \"math/matrix/matrix.hpp\"\
    \n#include <vector>\r\n\r\ntemplate <typename T>\r\nstruct Matrix {\r\n  explicit\
    \ Matrix(const int m, const int n, const T def = 0)\r\n      : data(m, std::vector<T>(n,\
    \ def)) {}\r\n\r\n  int nrow() const { return data.size(); }\r\n  int ncol() const\
    \ { return data.front().size(); }\r\n\r\n  Matrix pow(long long exponent) const\
    \ {\r\n    const int n = nrow();\r\n    Matrix<T> res(n, n, 0), tmp = *this;\r\
    \n    for (int i = 0; i < n; ++i) {\r\n      res[i][i] = 1;\r\n    }\r\n    for\
    \ (; exponent > 0; exponent >>= 1) {\r\n      if (exponent & 1) res *= tmp;\r\n\
    \      tmp *= tmp;\r\n    }\r\n    return res;\r\n  }\r\n\r\n  inline const std::vector<T>&\
    \ operator[](const int i) const { return data[i]; }\r\n  inline std::vector<T>&\
    \ operator[](const int i) { return data[i]; }\r\n\r\n  Matrix& operator=(const\
    \ Matrix& x) = default;\r\n\r\n  Matrix& operator+=(const Matrix& x) {\r\n   \
    \ const int m = nrow(), n = ncol();\r\n    for (int i = 0; i < m; ++i) {\r\n \
    \     for (int j = 0; j < n; ++j) {\r\n        data[i][j] += x[i][j];\r\n    \
    \  }\r\n    }\r\n    return *this;\r\n  }\r\n\r\n  Matrix& operator-=(const Matrix&\
    \ x) {\r\n    const int m = nrow(), n = ncol();\r\n    for (int i = 0; i < m;\
    \ ++i) {\r\n      for (int j = 0; j < n; ++j) {\r\n        data[i][j] -= x[i][j];\r\
    \n      }\r\n    }\r\n    return *this;\r\n  }\r\n\r\n  Matrix& operator*=(const\
    \ Matrix& x) {\r\n    const int m = nrow(), l = ncol(), n = x.ncol();\r\n    std::vector<std::vector<T>>\
    \ res(m, std::vector<T>(n, 0));\r\n    for (int i = 0; i < m; ++i) {\r\n     \
    \ for (int k = 0; k < l; ++k) {\r\n        for (int j = 0; j < n; ++j) {\r\n \
    \         res[i][j] += data[i][k] * x[k][j];\r\n        }\r\n      }\r\n    }\r\
    \n    data.swap(res);\r\n    return *this;\r\n  }\r\n\r\n  Matrix operator+(const\
    \ Matrix& x) const { return Matrix(*this) += x; }\r\n  Matrix operator-(const\
    \ Matrix& x) const { return Matrix(*this) -= x; }\r\n  Matrix operator*(const\
    \ Matrix& x) const { return Matrix(*this) *= x; }\r\n\r\n private:\r\n  std::vector<std::vector<T>>\
    \ data;\r\n};\r\n#line 7 \"math/matrix/inverse_matrix.hpp\"\n\r\ntemplate <typename\
    \ T, typename U = double>\r\nMatrix<U> inverse_matrix(const Matrix<T>& a, const\
    \ U eps = 1e-8) {\r\n  const int n = a.nrow();\r\n  Matrix<U> b(n, n << 1, 0);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    std::copy(a[i].begin(), a[i].end(), b[i].begin());\r\
    \n    b[i][n + i] = 1;\r\n  }\r\n  for (int col = 0; col < n; ++col) {\r\n   \
    \ int pivot = -1;\r\n    U mx = eps;\r\n    for (int row = col; row < n; ++row)\
    \ {\r\n      const U abs = (b[row][col] < 0 ? -b[row][col] : b[row][col]);\r\n\
    \      if (abs > mx) {\r\n        pivot = row;\r\n        mx = abs;\r\n      }\r\
    \n    }\r\n    if (pivot == -1) return Matrix<U>(0, 0);\r\n    std::swap(b[col],\
    \ b[pivot]);\r\n    U tmp = b[col][col];\r\n    for (int col2 = 0; col2 < (n <<\
    \ 1); ++col2) {\r\n      b[col][col2] /= tmp;\r\n    }\r\n    for (int row = 0;\
    \ row < n; ++row) {\r\n      if (row != col && (b[row][col] < 0 ? -b[row][col]\
    \ : b[row][col]) > eps) {\r\n        tmp = b[row][col];\r\n        for (int col2\
    \ = 0; col2 < (n << 1); ++col2) {\r\n          b[row][col2] -= b[col][col2] *\
    \ tmp;\r\n        }\r\n      }\r\n    }\r\n  }\r\n  Matrix<U> inv(n, n);\r\n \
    \ for (int i = 0; i < n; ++i) {\r\n    std::copy(std::next(b[i].begin(), n), b[i].end(),\
    \ inv[i].begin());\r\n  }\r\n  return inv;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <iterator>\r\n#include <utility>\r\
    \n\r\n#include \"matrix.hpp\"\r\n\r\ntemplate <typename T, typename U = double>\r\
    \nMatrix<U> inverse_matrix(const Matrix<T>& a, const U eps = 1e-8) {\r\n  const\
    \ int n = a.nrow();\r\n  Matrix<U> b(n, n << 1, 0);\r\n  for (int i = 0; i < n;\
    \ ++i) {\r\n    std::copy(a[i].begin(), a[i].end(), b[i].begin());\r\n    b[i][n\
    \ + i] = 1;\r\n  }\r\n  for (int col = 0; col < n; ++col) {\r\n    int pivot =\
    \ -1;\r\n    U mx = eps;\r\n    for (int row = col; row < n; ++row) {\r\n    \
    \  const U abs = (b[row][col] < 0 ? -b[row][col] : b[row][col]);\r\n      if (abs\
    \ > mx) {\r\n        pivot = row;\r\n        mx = abs;\r\n      }\r\n    }\r\n\
    \    if (pivot == -1) return Matrix<U>(0, 0);\r\n    std::swap(b[col], b[pivot]);\r\
    \n    U tmp = b[col][col];\r\n    for (int col2 = 0; col2 < (n << 1); ++col2)\
    \ {\r\n      b[col][col2] /= tmp;\r\n    }\r\n    for (int row = 0; row < n; ++row)\
    \ {\r\n      if (row != col && (b[row][col] < 0 ? -b[row][col] : b[row][col])\
    \ > eps) {\r\n        tmp = b[row][col];\r\n        for (int col2 = 0; col2 <\
    \ (n << 1); ++col2) {\r\n          b[row][col2] -= b[col][col2] * tmp;\r\n   \
    \     }\r\n      }\r\n    }\r\n  }\r\n  Matrix<U> inv(n, n);\r\n  for (int i =\
    \ 0; i < n; ++i) {\r\n    std::copy(std::next(b[i].begin(), n), b[i].end(), inv[i].begin());\r\
    \n  }\r\n  return inv;\r\n}\r\n"
  dependsOn:
  - math/matrix/matrix.hpp
  isVerificationFile: false
  path: math/matrix/inverse_matrix.hpp
  requiredBy: []
  timestamp: '2022-02-17 20:33:52+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/matrix/inverse_matrix.test.cpp
documentation_of: math/matrix/inverse_matrix.hpp
layout: document
title: "\u9006\u884C\u5217 (inverse matrix)"
---


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`inverse<T, U = double>(a, ε = 1e-8)`|行列 $A$ の逆行列|存在しないときは空行列となる．|


## Verified

https://judge.yosupo.jp/submission/50854
