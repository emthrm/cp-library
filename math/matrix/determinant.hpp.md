---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/matrix_tree_theorem.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/matrix_tree_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/determinant.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/determinant.hpp\"\n#include <cmath>\r\n#include\
    \ <utility>\r\n#line 3 \"math/matrix/matrix.hpp\"\n#include <vector>\r\n\r\ntemplate\
    \ <typename T>\r\nstruct Matrix {\r\n  Matrix(int m, int n, T val = 0) : dat(m,\
    \ std::vector<T>(n, val)) {}\r\n\r\n  int height() const { return dat.size();\
    \ }\r\n\r\n  int width() const { return dat.front().size(); }\r\n\r\n  Matrix\
    \ pow(long long exponent) const {\r\n    int n = height();\r\n    Matrix<T> tmp\
    \ = *this, res(n, n, 0);\r\n    for (int i = 0; i < n; ++i) res[i][i] = 1;\r\n\
    \    while (exponent > 0) {\r\n      if (exponent & 1) res *= tmp;\r\n      tmp\
    \ *= tmp;\r\n      exponent >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n\r\n\
    \  inline const std::vector<T> &operator[](const int idx) const { return dat[idx];\
    \ }\r\n  inline std::vector<T> &operator[](const int idx) { return dat[idx]; }\r\
    \n\r\n  Matrix &operator=(const Matrix &x) {\r\n    int m = x.height(), n = x.width();\r\
    \n    dat.resize(m, std::vector<T>(n));\r\n    for (int i = 0; i < m; ++i) for\
    \ (int j = 0; j < n; ++j) dat[i][j] = x[i][j];\r\n    return *this;\r\n  }\r\n\
    \r\n  Matrix &operator+=(const Matrix &x) {\r\n    int m = height(), n = width();\r\
    \n    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) dat[i][j] += x[i][j];\r\
    \n    return *this;\r\n  }\r\n\r\n  Matrix &operator-=(const Matrix &x) {\r\n\
    \    int m = height(), n = width();\r\n    for (int i = 0; i < m; ++i) for (int\
    \ j = 0; j < n; ++j) dat[i][j] -= x[i][j];\r\n    return *this;\r\n  }\r\n\r\n\
    \  Matrix &operator*=(const Matrix &x) {\r\n    int m = height(), n = x.width(),\
    \ l = width();\r\n    std::vector<std::vector<T>> res(m, std::vector<T>(n, 0));\r\
    \n    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {\r\n      for (int\
    \ k = 0; k < l; ++k) res[i][j] += dat[i][k] * x[k][j];\r\n    }\r\n    std::swap(dat,\
    \ res);\r\n    return *this;\r\n  }\r\n\r\n  Matrix operator+(const Matrix &x)\
    \ const { return Matrix(*this) += x; }\r\n\r\n  Matrix operator-(const Matrix\
    \ &x) const { return Matrix(*this) -= x; }\r\n\r\n  Matrix operator*(const Matrix\
    \ &x) const { return Matrix(*this) *= x; }\r\n\r\nprivate:\r\n  std::vector<std::vector<T>>\
    \ dat;\r\n};\r\n#line 5 \"math/matrix/determinant.hpp\"\n\r\ntemplate <typename\
    \ T, typename U>\r\nU det(const Matrix<T> &mat, const U EPS) {\r\n  int n = mat.height();\r\
    \n  Matrix<U> tmp(n, n);\r\n  for (int i = 0; i < n; ++i) for (int j = 0; j <\
    \ n; ++j) tmp[i][j] = mat[i][j];\r\n  U res = 1;\r\n  for (int j = 0; j < n; ++j)\
    \ {\r\n    int pivot = -1;\r\n    U mx = EPS;\r\n    for (int i = j; i < n; ++i)\
    \ {\r\n      if (std::abs(tmp[i][j]) > mx) {\r\n        pivot = i;\r\n       \
    \ mx = std::abs(tmp[i][j]);\r\n      }\r\n    }\r\n    if (pivot == -1) return\
    \ 0;\r\n    if (pivot != j) {\r\n      std::swap(tmp[j], tmp[pivot]);\r\n    \
    \  res = -res;\r\n    }\r\n    res *= tmp[j][j];\r\n    for (int k = j + 1; k\
    \ < n; ++k) tmp[j][k] /= tmp[j][j];\r\n    for (int i = j + 1; i < n; ++i) for\
    \ (int k = j + 1; k < n; ++k) {\r\n      tmp[i][k] -= tmp[i][j] * tmp[j][k];\r\
    \n    }\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <cmath>\r\n#include <utility>\r\n#include \"matrix.hpp\"\
    \r\n\r\ntemplate <typename T, typename U>\r\nU det(const Matrix<T> &mat, const\
    \ U EPS) {\r\n  int n = mat.height();\r\n  Matrix<U> tmp(n, n);\r\n  for (int\
    \ i = 0; i < n; ++i) for (int j = 0; j < n; ++j) tmp[i][j] = mat[i][j];\r\n  U\
    \ res = 1;\r\n  for (int j = 0; j < n; ++j) {\r\n    int pivot = -1;\r\n    U\
    \ mx = EPS;\r\n    for (int i = j; i < n; ++i) {\r\n      if (std::abs(tmp[i][j])\
    \ > mx) {\r\n        pivot = i;\r\n        mx = std::abs(tmp[i][j]);\r\n     \
    \ }\r\n    }\r\n    if (pivot == -1) return 0;\r\n    if (pivot != j) {\r\n  \
    \    std::swap(tmp[j], tmp[pivot]);\r\n      res = -res;\r\n    }\r\n    res *=\
    \ tmp[j][j];\r\n    for (int k = j + 1; k < n; ++k) tmp[j][k] /= tmp[j][j];\r\n\
    \    for (int i = j + 1; i < n; ++i) for (int k = j + 1; k < n; ++k) {\r\n   \
    \   tmp[i][k] -= tmp[i][j] * tmp[j][k];\r\n    }\r\n  }\r\n  return res;\r\n}\r\
    \n"
  dependsOn:
  - math/matrix/matrix.hpp
  isVerificationFile: false
  path: math/matrix/determinant.hpp
  requiredBy:
  - graph/matrix_tree_theorem.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/matrix/determinant.test.cpp
  - test/graph/matrix_tree_theorem.test.cpp
documentation_of: math/matrix/determinant.hpp
layout: document
title: "\u884C\u5217\u5F0F (determinant)"
---


## 時間計算量

$O(N^3)$


## 使用法

||説明|
|:--:|:--:|
|`det(mat, ε)`|$\lvert \mathrm{mat} \rvert$|


## 参考

- https://github.com/beet-aizu/library/blob/ebcad58b8480962339b18e316b826e56752b90c8/matrix/matrix.cpp


## ToDo

- 固有多項式 (characteristic polynomial)
  - https://ja.wikipedia.org/wiki/%E5%9B%BA%E6%9C%89%E5%A4%9A%E9%A0%85%E5%BC%8F
  - https://github.com/yosupo06/library-checker-problems/issues/665
  - https://judge.yosupo.jp/problem/characteristic_polynomial


## Verified

https://judge.yosupo.jp/submission/2714
