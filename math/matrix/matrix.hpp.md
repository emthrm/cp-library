---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/flow/matching/maximum_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
  - icon: ':x:'
    path: graph/matrix_tree_theorem.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':x:'
    path: math/matrix/determinant.hpp
    title: "\u884C\u5217\u5F0F (determinant)"
  - icon: ':question:'
    path: math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination)"
  - icon: ':x:'
    path: math/matrix/inverse_matrix.hpp
    title: "\u9006\u884C\u5217 (inverse matrix)"
  - icon: ':x:'
    path: math/matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/maximum_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E00\
      \u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
  - icon: ':x:'
    path: test/graph/matrix_tree_theorem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
  - icon: ':x:'
    path: test/math/matrix/determinant.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F"
  - icon: ':x:'
    path: test/math/matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217"
  - icon: ':x:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
  - icon: ':x:'
    path: test/math/matrix/matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix/matrix.hpp\"\n#include <vector>\n\ntemplate\
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
    \ data;\n};\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nstruct Matrix {\n\
    \  explicit Matrix(const int m, const int n, const T def = 0)\n      : data(m,\
    \ std::vector<T>(n, def)) {}\n\n  int nrow() const { return data.size(); }\n \
    \ int ncol() const { return data.front().size(); }\n\n  Matrix pow(long long exponent)\
    \ const {\n    const int n = nrow();\n    Matrix<T> res(n, n, 0), tmp = *this;\n\
    \    for (int i = 0; i < n; ++i) {\n      res[i][i] = 1;\n    }\n    for (; exponent\
    \ > 0; exponent >>= 1) {\n      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n\
    \    }\n    return res;\n  }\n\n  inline const std::vector<T>& operator[](const\
    \ int i) const { return data[i]; }\n  inline std::vector<T>& operator[](const\
    \ int i) { return data[i]; }\n\n  Matrix& operator=(const Matrix& x) = default;\n\
    \n  Matrix& operator+=(const Matrix& x) {\n    const int m = nrow(), n = ncol();\n\
    \    for (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n; ++j) {\n    \
    \    data[i][j] += x[i][j];\n      }\n    }\n    return *this;\n  }\n\n  Matrix&\
    \ operator-=(const Matrix& x) {\n    const int m = nrow(), n = ncol();\n    for\
    \ (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n; ++j) {\n        data[i][j]\
    \ -= x[i][j];\n      }\n    }\n    return *this;\n  }\n\n  Matrix& operator*=(const\
    \ Matrix& x) {\n    const int m = nrow(), l = ncol(), n = x.ncol();\n    std::vector<std::vector<T>>\
    \ res(m, std::vector<T>(n, 0));\n    for (int i = 0; i < m; ++i) {\n      for\
    \ (int k = 0; k < l; ++k) {\n        for (int j = 0; j < n; ++j) {\n         \
    \ res[i][j] += data[i][k] * x[k][j];\n        }\n      }\n    }\n    data.swap(res);\n\
    \    return *this;\n  }\n\n  Matrix operator+(const Matrix& x) const { return\
    \ Matrix(*this) += x; }\n  Matrix operator-(const Matrix& x) const { return Matrix(*this)\
    \ -= x; }\n  Matrix operator*(const Matrix& x) const { return Matrix(*this) *=\
    \ x; }\n\n private:\n  std::vector<std::vector<T>> data;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix/matrix.hpp
  requiredBy:
  - math/matrix/inverse_matrix.hpp
  - math/matrix/linear_equation.hpp
  - math/matrix/gauss_jordan.hpp
  - math/matrix/determinant.hpp
  - graph/flow/matching/maximum_matching.hpp
  - graph/matrix_tree_theorem.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/matrix/determinant.test.cpp
  - test/math/matrix/inverse_matrix.test.cpp
  - test/math/matrix/matrix.test.cpp
  - test/math/matrix/linear_equation.test.cpp
  - test/graph/flow/matching/maximum_matching.test.cpp
  - test/graph/matrix_tree_theorem.test.cpp
documentation_of: math/matrix/matrix.hpp
layout: document
title: "\u884C\u5217 (matrix)"
---


## 時間計算量

|処理|時間計算量|
|:--:|:--:|
|加算|$O(MN)$|
|減算|$O(MN)$|
|乗算|$O(N^3)$|
|行列累乗|$O(N^3 \log{E})$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Matrix<T>(m, n, def = 0)`|初期値 $\mathrm{def}$ の $M \times N$ 型行列||
|`nrow()`|$M$||
|`ncol()`|$N$||
|`pow(exponent)`|$A^\mathrm{exponent}$|半環上で成立する．|
|`operator[](i)`|$A$ の $i$ 行目||
|`operator=(x)`|代入||
|`operator+=(x)`<br>`operator+(x)`|加算||
|`operator-=(x)`<br>`operator-(x)`|減算||
|`operator*=(x)`<br>`operator*(x)`|乗算|半環上で成立する．|


## 参考

- https://ei1333.github.io/luzhiled/snippets/math/matrix.html


## ToDo

- https://github.com/eandbsoftware/libraryCPP/blob/master/!Matrix.cpp
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
  - http://www.prefield.com/algorithm/math/eigensystem.html
- ハフニアン (hafnian)
  - https://mathtrain.jp/pfaffian
  - https://en.wikipedia.org/wiki/Hafnian
  - https://github.com/yosupo06/library-checker-problems/issues/467
  - https://judge.yosupo.jp/problem/hafnian_of_matrix


## Verified

https://judge.yosupo.jp/submission/45071
