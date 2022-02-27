---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination)"
  - icon: ':question:'
    path: math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/linear_equation.hpp\"\n#include <algorithm>\r\
    \n#include <cmath>\r\n#include <vector>\r\n\r\n#line 2 \"math/matrix/gauss_jordan.hpp\"\
    \n#include <utility>\r\n\r\n#line 3 \"math/matrix/matrix.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nstruct Matrix {\r\n  explicit Matrix(const int m, const int n, const T\
    \ def = 0)\r\n      : data(m, std::vector<T>(n, def)) {}\r\n\r\n  int nrow() const\
    \ { return data.size(); }\r\n  int ncol() const { return data.front().size();\
    \ }\r\n\r\n  Matrix pow(long long exponent) const {\r\n    const int n = nrow();\r\
    \n    Matrix<T> res(n, n, 0), tmp = *this;\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n      res[i][i] = 1;\r\n    }\r\n    for (; exponent > 0; exponent >>=\
    \ 1) {\r\n      if (exponent & 1) res *= tmp;\r\n      tmp *= tmp;\r\n    }\r\n\
    \    return res;\r\n  }\r\n\r\n  inline const std::vector<T>& operator[](const\
    \ int i) const { return data[i]; }\r\n  inline std::vector<T>& operator[](const\
    \ int i) { return data[i]; }\r\n\r\n  Matrix& operator=(const Matrix& x) = default;\r\
    \n\r\n  Matrix& operator+=(const Matrix& x) {\r\n    const int m = nrow(), n =\
    \ ncol();\r\n    for (int i = 0; i < m; ++i) {\r\n      for (int j = 0; j < n;\
    \ ++j) {\r\n        data[i][j] += x[i][j];\r\n      }\r\n    }\r\n    return *this;\r\
    \n  }\r\n\r\n  Matrix& operator-=(const Matrix& x) {\r\n    const int m = nrow(),\
    \ n = ncol();\r\n    for (int i = 0; i < m; ++i) {\r\n      for (int j = 0; j\
    \ < n; ++j) {\r\n        data[i][j] -= x[i][j];\r\n      }\r\n    }\r\n    return\
    \ *this;\r\n  }\r\n\r\n  Matrix& operator*=(const Matrix& x) {\r\n    const int\
    \ m = nrow(), l = ncol(), n = x.ncol();\r\n    std::vector<std::vector<T>> res(m,\
    \ std::vector<T>(n, 0));\r\n    for (int i = 0; i < m; ++i) {\r\n      for (int\
    \ k = 0; k < l; ++k) {\r\n        for (int j = 0; j < n; ++j) {\r\n          res[i][j]\
    \ += data[i][k] * x[k][j];\r\n        }\r\n      }\r\n    }\r\n    data.swap(res);\r\
    \n    return *this;\r\n  }\r\n\r\n  Matrix operator+(const Matrix& x) const {\
    \ return Matrix(*this) += x; }\r\n  Matrix operator-(const Matrix& x) const {\
    \ return Matrix(*this) -= x; }\r\n  Matrix operator*(const Matrix& x) const {\
    \ return Matrix(*this) *= x; }\r\n\r\n private:\r\n  std::vector<std::vector<T>>\
    \ data;\r\n};\r\n#line 5 \"math/matrix/gauss_jordan.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nint gauss_jordan(Matrix<T>* a, const T eps = 1e-8,\r\n               \
    \  const bool is_extended = false) {\r\n  const int m = a->nrow(), n = a->ncol();\r\
    \n  int rank = 0;\r\n  for (int col = 0; col < (is_extended ? n - 1 : n); ++col)\
    \ {\r\n    int pivot = -1;\r\n    T mx = eps;\r\n    for (int row = rank; row\
    \ < m; ++row) {\r\n      const T abs = ((*a)[row][col] < 0 ? -(*a)[row][col] :\
    \ (*a)[row][col]);\r\n      if (abs > mx) {\r\n        pivot = row;\r\n      \
    \  mx = abs;\r\n      }\r\n    }\r\n    if (pivot == -1) continue;\r\n    std::swap((*a)[rank],\
    \ (*a)[pivot]);\r\n    T tmp = (*a)[rank][col];\r\n    for (int col2 = 0; col2\
    \ < n; ++col2) {\r\n      (*a)[rank][col2] /= tmp;\r\n    }\r\n    for (int row\
    \ = 0; row < m; ++row) {\r\n      if (row != rank &&\r\n          ((*a)[row][col]\
    \ < 0 ? -(*a)[row][col] : (*a)[row][col]) > eps) {\r\n        tmp = (*a)[row][col];\r\
    \n        for (int col2 = 0; col2 < n; ++col2) {\r\n          (*a)[row][col2]\
    \ -= (*a)[rank][col2] * tmp;\r\n        }\r\n      }\r\n    }\r\n    ++rank;\r\
    \n  }\r\n  return rank;\r\n}\r\n#line 8 \"math/matrix/linear_equation.hpp\"\n\r\
    \ntemplate <typename T, typename U = double>\r\nstd::vector<U> linear_equation(const\
    \ Matrix<T>& a, const std::vector<T>& b,\r\n                               const\
    \ U eps = 1e-8) {\r\n  const int m = a.nrow(), n = a.ncol();\r\n  Matrix<U> c(m,\
    \ n + 1);\r\n  for (int i = 0; i < m; ++i) {\r\n    std::copy(a[i].begin(), a[i].end(),\
    \ c[i].begin());\r\n    c[i].back() = b[i];\r\n  }\r\n  const int rank = gauss_jordan(&c,\
    \ eps, true);\r\n  for (int row = rank; row < m; ++row) {\r\n    if ((c[row].back()\
    \ < 0 ? -c[row].back() : c[row].back()) > eps) {\r\n      return std::vector<U>{};\r\
    \n    }\r\n  }\r\n  std::vector<U> res(n, 0);\r\n  for (int i = 0, j = 0; i <\
    \ rank; ++i) {\r\n    while ((c[i][j] < 0 ? -c[i][j] : c[i][j]) <= eps) ++j;\r\
    \n    res[j++] = c[i].back();\r\n  }\r\n  return res;\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cmath>\r\n#include <vector>\r\
    \n\r\n#include \"./gauss_jordan.hpp\"\r\n#include \"./matrix.hpp\"\r\n\r\ntemplate\
    \ <typename T, typename U = double>\r\nstd::vector<U> linear_equation(const Matrix<T>&\
    \ a, const std::vector<T>& b,\r\n                               const U eps =\
    \ 1e-8) {\r\n  const int m = a.nrow(), n = a.ncol();\r\n  Matrix<U> c(m, n + 1);\r\
    \n  for (int i = 0; i < m; ++i) {\r\n    std::copy(a[i].begin(), a[i].end(), c[i].begin());\r\
    \n    c[i].back() = b[i];\r\n  }\r\n  const int rank = gauss_jordan(&c, eps, true);\r\
    \n  for (int row = rank; row < m; ++row) {\r\n    if ((c[row].back() < 0 ? -c[row].back()\
    \ : c[row].back()) > eps) {\r\n      return std::vector<U>{};\r\n    }\r\n  }\r\
    \n  std::vector<U> res(n, 0);\r\n  for (int i = 0, j = 0; i < rank; ++i) {\r\n\
    \    while ((c[i][j] < 0 ? -c[i][j] : c[i][j]) <= eps) ++j;\r\n    res[j++] =\
    \ c[i].back();\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn:
  - math/matrix/gauss_jordan.hpp
  - math/matrix/matrix.hpp
  isVerificationFile: false
  path: math/matrix/linear_equation.hpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
|`linear_equation(a, b, ε = 1e-8)`|$A \boldsymbol{x} = \boldsymbol{b}$ を満たす $\boldsymbol{x}$|解なしのときは空配列となる．|


## ToDo

- https://judge.yosupo.jp/problem/system_of_linear_equations
- LU 分解
  - https://ja.wikipedia.org/wiki/LU%E5%88%86%E8%A7%A3
  - https://github.com/satanic0258/Cpp_snippet/blob/master/src/math/LUdecomposition.cpp
  - http://www.prefield.com/algorithm/math/LU.html
- 疎行列の連立一次方程式
  - https://drive.google.com/file/d/1D7sRmUy-0XnZCay8Tr1PldJVFRM2NII5


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2171/review/5899058/emthrm/C++17
