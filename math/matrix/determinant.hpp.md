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
  - icon: ':x:'
    path: test/math/matrix/determinant.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/determinant.hpp\"\n#include <algorithm>\n#include\
    \ <utility>\n\n#line 2 \"math/matrix/matrix.hpp\"\n#include <vector>\n\ntemplate\
    \ <typename T>\nstruct Matrix {\n  explicit Matrix(const int m, const int n, const\
    \ T def = 0)\n      : data(m, std::vector<T>(n, def)) {}\n\n  int nrow() const\
    \ { return data.size(); }\n  int ncol() const { return data.front().size(); }\n\
    \n  Matrix pow(long long exponent) const {\n    const int n = nrow();\n    Matrix<T>\
    \ res(n, n, 0), tmp = *this;\n    for (int i = 0; i < n; ++i) {\n      res[i][i]\
    \ = 1;\n    }\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent\
    \ & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  inline\
    \ const std::vector<T>& operator[](const int i) const { return data[i]; }\n  inline\
    \ std::vector<T>& operator[](const int i) { return data[i]; }\n\n  Matrix& operator=(const\
    \ Matrix& x) = default;\n\n  Matrix& operator+=(const Matrix& x) {\n    const\
    \ int m = nrow(), n = ncol();\n    for (int i = 0; i < m; ++i) {\n      for (int\
    \ j = 0; j < n; ++j) {\n        data[i][j] += x[i][j];\n      }\n    }\n    return\
    \ *this;\n  }\n\n  Matrix& operator-=(const Matrix& x) {\n    const int m = nrow(),\
    \ n = ncol();\n    for (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n;\
    \ ++j) {\n        data[i][j] -= x[i][j];\n      }\n    }\n    return *this;\n\
    \  }\n\n  Matrix& operator*=(const Matrix& x) {\n    const int m = nrow(), l =\
    \ ncol(), n = x.ncol();\n    std::vector<std::vector<T>> res(m, std::vector<T>(n,\
    \ 0));\n    for (int i = 0; i < m; ++i) {\n      for (int k = 0; k < l; ++k) {\n\
    \        for (int j = 0; j < n; ++j) {\n          res[i][j] += data[i][k] * x[k][j];\n\
    \        }\n      }\n    }\n    data.swap(res);\n    return *this;\n  }\n\n  Matrix\
    \ operator+(const Matrix& x) const { return Matrix(*this) += x; }\n  Matrix operator-(const\
    \ Matrix& x) const { return Matrix(*this) -= x; }\n  Matrix operator*(const Matrix&\
    \ x) const { return Matrix(*this) *= x; }\n\n private:\n  std::vector<std::vector<T>>\
    \ data;\n};\n#line 6 \"math/matrix/determinant.hpp\"\n\ntemplate <typename T,\
    \ typename U>\nU det(const Matrix<T>& a, const U eps) {\n  const int n = a.nrow();\n\
    \  Matrix<U> b(n, n);\n  for (int i = 0; i < n; ++i) {\n    std::copy(a[i].begin(),\
    \ a[i].end(), b[i].begin());\n  }\n  U res = 1;\n  for (int j = 0; j < n; ++j)\
    \ {\n    int pivot = -1;\n    U mx = eps;\n    for (int i = j; i < n; ++i) {\n\
    \      const U abs = (b[i][j] < 0 ? -b[i][j] : b[i][j]);\n      if (abs > mx)\
    \ {\n        pivot = i;\n        mx = abs;\n      }\n    }\n    if (pivot == -1)\
    \ return 0;\n    if (pivot != j) {\n      std::swap(b[j], b[pivot]);\n      res\
    \ = -res;\n    }\n    res *= b[j][j];\n    for (int k = j + 1; k < n; ++k) {\n\
    \      b[j][k] /= b[j][j];\n    }\n    for (int i = j + 1; i < n; ++i) {\n   \
    \   for (int k = j + 1; k < n; ++k) {\n        b[i][k] -= b[i][j] * b[j][k];\n\
    \      }\n    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n\n#include \"./matrix.hpp\"\
    \n\ntemplate <typename T, typename U>\nU det(const Matrix<T>& a, const U eps)\
    \ {\n  const int n = a.nrow();\n  Matrix<U> b(n, n);\n  for (int i = 0; i < n;\
    \ ++i) {\n    std::copy(a[i].begin(), a[i].end(), b[i].begin());\n  }\n  U res\
    \ = 1;\n  for (int j = 0; j < n; ++j) {\n    int pivot = -1;\n    U mx = eps;\n\
    \    for (int i = j; i < n; ++i) {\n      const U abs = (b[i][j] < 0 ? -b[i][j]\
    \ : b[i][j]);\n      if (abs > mx) {\n        pivot = i;\n        mx = abs;\n\
    \      }\n    }\n    if (pivot == -1) return 0;\n    if (pivot != j) {\n     \
    \ std::swap(b[j], b[pivot]);\n      res = -res;\n    }\n    res *= b[j][j];\n\
    \    for (int k = j + 1; k < n; ++k) {\n      b[j][k] /= b[j][j];\n    }\n   \
    \ for (int i = j + 1; i < n; ++i) {\n      for (int k = j + 1; k < n; ++k) {\n\
    \        b[i][k] -= b[i][j] * b[j][k];\n      }\n    }\n  }\n  return res;\n}\n"
  dependsOn:
  - math/matrix/matrix.hpp
  isVerificationFile: false
  path: math/matrix/determinant.hpp
  requiredBy:
  - graph/matrix_tree_theorem.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
  - https://yukicoder.me/problems/no/1907
- 任意の法の下での行列式
  - https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod
  - https://github.com/yosupo06/library-checker-problems/issues/750


## Verified

https://judge.yosupo.jp/submission/2714
