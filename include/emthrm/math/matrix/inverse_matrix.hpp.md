---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/inverse_matrix.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/matrix/inverse_matrix.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <iterator>\n#include <utility>\n\n#line 1 \"include/emthrm/math/matrix/matrix.hpp\"\
    \n\n\n\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct\
    \ Matrix {\n  explicit Matrix(const int m, const int n, const T def = 0)\n   \
    \   : data(m, std::vector<T>(n, def)) {}\n\n  int nrow() const { return data.size();\
    \ }\n  int ncol() const { return data.front().size(); }\n\n  Matrix pow(long long\
    \ exponent) const {\n    const int n = nrow();\n    Matrix<T> res(n, n, 0), tmp\
    \ = *this;\n    for (int i = 0; i < n; ++i) {\n      res[i][i] = 1;\n    }\n \
    \   for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1) res *= tmp;\n\
    \      tmp *= tmp;\n    }\n    return res;\n  }\n\n  inline const std::vector<T>&\
    \ operator[](const int i) const { return data[i]; }\n  inline std::vector<T>&\
    \ operator[](const int i) { return data[i]; }\n\n  Matrix& operator=(const Matrix&\
    \ x) = default;\n\n  Matrix& operator+=(const Matrix& x) {\n    const int m =\
    \ nrow(), n = ncol();\n    for (int i = 0; i < m; ++i) {\n      for (int j = 0;\
    \ j < n; ++j) {\n        data[i][j] += x[i][j];\n      }\n    }\n    return *this;\n\
    \  }\n\n  Matrix& operator-=(const Matrix& x) {\n    const int m = nrow(), n =\
    \ ncol();\n    for (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n; ++j)\
    \ {\n        data[i][j] -= x[i][j];\n      }\n    }\n    return *this;\n  }\n\n\
    \  Matrix& operator*=(const Matrix& x) {\n    const int m = nrow(), l = ncol(),\
    \ n = x.ncol();\n    std::vector<std::vector<T>> res(m, std::vector<T>(n, 0));\n\
    \    for (int i = 0; i < m; ++i) {\n      for (int k = 0; k < l; ++k) {\n    \
    \    for (int j = 0; j < n; ++j) {\n          res[i][j] += data[i][k] * x[k][j];\n\
    \        }\n      }\n    }\n    data.swap(res);\n    return *this;\n  }\n\n  Matrix\
    \ operator+(const Matrix& x) const { return Matrix(*this) += x; }\n  Matrix operator-(const\
    \ Matrix& x) const { return Matrix(*this) -= x; }\n  Matrix operator*(const Matrix&\
    \ x) const { return Matrix(*this) *= x; }\n\n private:\n  std::vector<std::vector<T>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 9 \"include/emthrm/math/matrix/inverse_matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T, typename U = double>\nMatrix<U>\
    \ inverse_matrix(const Matrix<T>& a, const U eps = 1e-8) {\n  const int n = a.nrow();\n\
    \  Matrix<U> b(n, n << 1, 0);\n  for (int i = 0; i < n; ++i) {\n    std::copy(a[i].begin(),\
    \ a[i].end(), b[i].begin());\n    b[i][n + i] = 1;\n  }\n  for (int col = 0; col\
    \ < n; ++col) {\n    int pivot = -1;\n    U mx = eps;\n    for (int row = col;\
    \ row < n; ++row) {\n      const U abs = (b[row][col] < 0 ? -b[row][col] : b[row][col]);\n\
    \      if (abs > mx) {\n        pivot = row;\n        mx = abs;\n      }\n   \
    \ }\n    if (pivot == -1) return Matrix<U>(0, 0);\n    std::swap(b[col], b[pivot]);\n\
    \    U tmp = b[col][col];\n    for (int col2 = 0; col2 < (n << 1); ++col2) {\n\
    \      b[col][col2] /= tmp;\n    }\n    for (int row = 0; row < n; ++row) {\n\
    \      if (row != col && (b[row][col] < 0 ? -b[row][col] : b[row][col]) > eps)\
    \ {\n        tmp = b[row][col];\n        for (int col2 = 0; col2 < (n << 1); ++col2)\
    \ {\n          b[row][col2] -= b[col][col2] * tmp;\n        }\n      }\n    }\n\
    \  }\n  Matrix<U> inv(n, n);\n  for (int i = 0; i < n; ++i) {\n    std::copy(std::next(b[i].begin(),\
    \ n), b[i].end(), inv[i].begin());\n  }\n  return inv;\n}\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_MATH_MATRIX_INVERSE_MATRIX_HPP_\n#define EMTHRM_MATH_MATRIX_INVERSE_MATRIX_HPP_\n\
    \n#include <algorithm>\n#include <iterator>\n#include <utility>\n\n#include \"\
    emthrm/math/matrix/matrix.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename T,\
    \ typename U = double>\nMatrix<U> inverse_matrix(const Matrix<T>& a, const U eps\
    \ = 1e-8) {\n  const int n = a.nrow();\n  Matrix<U> b(n, n << 1, 0);\n  for (int\
    \ i = 0; i < n; ++i) {\n    std::copy(a[i].begin(), a[i].end(), b[i].begin());\n\
    \    b[i][n + i] = 1;\n  }\n  for (int col = 0; col < n; ++col) {\n    int pivot\
    \ = -1;\n    U mx = eps;\n    for (int row = col; row < n; ++row) {\n      const\
    \ U abs = (b[row][col] < 0 ? -b[row][col] : b[row][col]);\n      if (abs > mx)\
    \ {\n        pivot = row;\n        mx = abs;\n      }\n    }\n    if (pivot ==\
    \ -1) return Matrix<U>(0, 0);\n    std::swap(b[col], b[pivot]);\n    U tmp = b[col][col];\n\
    \    for (int col2 = 0; col2 < (n << 1); ++col2) {\n      b[col][col2] /= tmp;\n\
    \    }\n    for (int row = 0; row < n; ++row) {\n      if (row != col && (b[row][col]\
    \ < 0 ? -b[row][col] : b[row][col]) > eps) {\n        tmp = b[row][col];\n   \
    \     for (int col2 = 0; col2 < (n << 1); ++col2) {\n          b[row][col2] -=\
    \ b[col][col2] * tmp;\n        }\n      }\n    }\n  }\n  Matrix<U> inv(n, n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::copy(std::next(b[i].begin(), n), b[i].end(),\
    \ inv[i].begin());\n  }\n  return inv;\n}\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_MATH_MATRIX_INVERSE_MATRIX_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/matrix/inverse_matrix.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix/inverse_matrix.test.cpp
documentation_of: include/emthrm/math/matrix/inverse_matrix.hpp
layout: document
title: "\u9006\u884C\u5217 (inverse matrix)"
---


## 時間計算量

$O(M^2 N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T, typename U = double>`<br>`Matrix<U> inverse_matrix(const Matrix<T>& a, const U eps = 1e-8);`|行列 $A$ の逆行列。ただし存在しないときは空行列を返す。|


## Submissons

https://judge.yosupo.jp/submission/50854