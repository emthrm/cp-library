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
  bundledCode: "#line 2 \"math/matrix/determinant.hpp\"\n#include <algorithm>\r\n\
    #include <utility>\r\n\r\n#line 2 \"math/matrix/matrix.hpp\"\n#include <vector>\r\
    \n\r\ntemplate <typename T>\r\nstruct Matrix {\r\n  explicit Matrix(const int\
    \ m, const int n, const T def = 0)\r\n      : data(m, std::vector<T>(n, def))\
    \ {}\r\n\r\n  int nrow() const { return data.size(); }\r\n  int ncol() const {\
    \ return data.front().size(); }\r\n\r\n  Matrix pow(long long exponent) const\
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
    \ data;\r\n};\r\n#line 6 \"math/matrix/determinant.hpp\"\n\r\ntemplate <typename\
    \ T, typename U>\r\nU det(const Matrix<T>& a, const U eps) {\r\n  const int n\
    \ = a.nrow();\r\n  Matrix<U> b(n, n);\r\n  for (int i = 0; i < n; ++i) {\r\n \
    \   std::copy(a[i].begin(), a[i].end(), b[i].begin());\r\n  }\r\n  U res = 1;\r\
    \n  for (int j = 0; j < n; ++j) {\r\n    int pivot = -1;\r\n    U mx = eps;\r\n\
    \    for (int i = j; i < n; ++i) {\r\n      const U abs = (b[i][j] < 0 ? -b[i][j]\
    \ : b[i][j]);\r\n      if (abs > mx) {\r\n        pivot = i;\r\n        mx = abs;\r\
    \n      }\r\n    }\r\n    if (pivot == -1) return 0;\r\n    if (pivot != j) {\r\
    \n      std::swap(b[j], b[pivot]);\r\n      res = -res;\r\n    }\r\n    res *=\
    \ b[j][j];\r\n    for (int k = j + 1; k < n; ++k) {\r\n      b[j][k] /= b[j][j];\r\
    \n    }\r\n    for (int i = j + 1; i < n; ++i) {\r\n      for (int k = j + 1;\
    \ k < n; ++k) {\r\n        b[i][k] -= b[i][j] * b[j][k];\r\n      }\r\n    }\r\
    \n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <utility>\r\n\r\n#include\
    \ \"matrix.hpp\"\r\n\r\ntemplate <typename T, typename U>\r\nU det(const Matrix<T>&\
    \ a, const U eps) {\r\n  const int n = a.nrow();\r\n  Matrix<U> b(n, n);\r\n \
    \ for (int i = 0; i < n; ++i) {\r\n    std::copy(a[i].begin(), a[i].end(), b[i].begin());\r\
    \n  }\r\n  U res = 1;\r\n  for (int j = 0; j < n; ++j) {\r\n    int pivot = -1;\r\
    \n    U mx = eps;\r\n    for (int i = j; i < n; ++i) {\r\n      const U abs =\
    \ (b[i][j] < 0 ? -b[i][j] : b[i][j]);\r\n      if (abs > mx) {\r\n        pivot\
    \ = i;\r\n        mx = abs;\r\n      }\r\n    }\r\n    if (pivot == -1) return\
    \ 0;\r\n    if (pivot != j) {\r\n      std::swap(b[j], b[pivot]);\r\n      res\
    \ = -res;\r\n    }\r\n    res *= b[j][j];\r\n    for (int k = j + 1; k < n; ++k)\
    \ {\r\n      b[j][k] /= b[j][j];\r\n    }\r\n    for (int i = j + 1; i < n; ++i)\
    \ {\r\n      for (int k = j + 1; k < n; ++k) {\r\n        b[i][k] -= b[i][j] *\
    \ b[j][k];\r\n      }\r\n    }\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - math/matrix/matrix.hpp
  isVerificationFile: false
  path: math/matrix/determinant.hpp
  requiredBy:
  - graph/matrix_tree_theorem.hpp
  timestamp: '2022-02-17 20:33:52+09:00'
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
|`det(a, ε)`|$\lvert A \rvert$|


## 参考

- https://github.com/beet-aizu/library/blob/ebcad58b8480962339b18e316b826e56752b90c8/matrix/matrix.cpp


## ToDo

- 固有多項式 (characteristic polynomial)
  - https://ja.wikipedia.org/wiki/%E5%9B%BA%E6%9C%89%E5%A4%9A%E9%A0%85%E5%BC%8F
  - https://github.com/yosupo06/library-checker-problems/issues/665
  - https://judge.yosupo.jp/problem/characteristic_polynomial


## Verified

https://judge.yosupo.jp/submission/2714
