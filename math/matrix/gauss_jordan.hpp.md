---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/flow/matching/tutte_theorem.hpp
    title: "\u30BF\u30C3\u30C8\u306E\u5B9A\u7406"
  - icon: ':x:'
    path: math/matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/tutte_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u30BF\
      \u30C3\u30C8\u306E\u5B9A\u7406"
  - icon: ':x:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/gauss_jordan.hpp\"\n#include <cmath>\r\n#include\
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
    \ dat;\r\n};\r\n#line 5 \"math/matrix/gauss_jordan.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nint gauss_jordan(Matrix<T> &mat, const T EPS = 1e-8, bool is_extended\
    \ = false) {\r\n  int m = mat.height(), n = mat.width(), rank = 0;\r\n  for (int\
    \ col = 0; col < n; ++col) {\r\n    if (is_extended && col == n - 1) break;\r\n\
    \    int pivot = -1;\r\n    T mx = EPS;\r\n    for (int row = rank; row < m; ++row)\
    \ {\r\n      if (std::abs(mat[row][col]) > mx) {\r\n        pivot = row;\r\n \
    \       mx = std::abs(mat[row][col]);\r\n      }\r\n    }\r\n    if (pivot ==\
    \ -1) continue;\r\n    std::swap(mat[rank], mat[pivot]);\r\n    T tmp = mat[rank][col];\r\
    \n    for (int col2 = 0; col2 < n; ++col2) mat[rank][col2] /= tmp;\r\n    for\
    \ (int row = 0; row < m; ++row) {\r\n      if (row != rank && std::abs(mat[row][col])\
    \ > EPS) {\r\n        tmp = mat[row][col];\r\n        for (int col2 = 0; col2\
    \ < n; ++col2) mat[row][col2] -= mat[rank][col2] * tmp;\r\n      }\r\n    }\r\n\
    \    ++rank;\r\n  }\r\n  return rank;\r\n}\r\n"
  code: "#pragma once\r\n#include <cmath>\r\n#include <utility>\r\n#include \"matrix.hpp\"\
    \r\n\r\ntemplate <typename T>\r\nint gauss_jordan(Matrix<T> &mat, const T EPS\
    \ = 1e-8, bool is_extended = false) {\r\n  int m = mat.height(), n = mat.width(),\
    \ rank = 0;\r\n  for (int col = 0; col < n; ++col) {\r\n    if (is_extended &&\
    \ col == n - 1) break;\r\n    int pivot = -1;\r\n    T mx = EPS;\r\n    for (int\
    \ row = rank; row < m; ++row) {\r\n      if (std::abs(mat[row][col]) > mx) {\r\
    \n        pivot = row;\r\n        mx = std::abs(mat[row][col]);\r\n      }\r\n\
    \    }\r\n    if (pivot == -1) continue;\r\n    std::swap(mat[rank], mat[pivot]);\r\
    \n    T tmp = mat[rank][col];\r\n    for (int col2 = 0; col2 < n; ++col2) mat[rank][col2]\
    \ /= tmp;\r\n    for (int row = 0; row < m; ++row) {\r\n      if (row != rank\
    \ && std::abs(mat[row][col]) > EPS) {\r\n        tmp = mat[row][col];\r\n    \
    \    for (int col2 = 0; col2 < n; ++col2) mat[row][col2] -= mat[rank][col2] *\
    \ tmp;\r\n      }\r\n    }\r\n    ++rank;\r\n  }\r\n  return rank;\r\n}\r\n"
  dependsOn:
  - math/matrix/matrix.hpp
  isVerificationFile: false
  path: math/matrix/gauss_jordan.hpp
  requiredBy:
  - graph/flow/matching/tutte_theorem.hpp
  - math/matrix/linear_equation.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/flow/matching/tutte_theorem.test.cpp
  - test/math/matrix/linear_equation.test.cpp
documentation_of: math/matrix/gauss_jordan.hpp
layout: document
title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
  \ (Gauss-Jordan elimination)"
---

行基本変形を用いて行列を行階段形に変形するアルゴリズムである．


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`gauss_jordan(mat, ε = 1e-8, 拡大係数行列か? = false)`|行列 $\mathrm{mat}$ のランク|$\mathrm{mat}$ は行階段形に変形される．<br>要素の型は実数型または `ModInt` である．|


## 参考

- http://drken1215.hatenablog.com/entry/2019/03/20/202800


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0004/review/4088546/emthrm/C++14
