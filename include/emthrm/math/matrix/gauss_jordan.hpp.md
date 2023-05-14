---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/matching/maximum_matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0 (maximum matching)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/matching/maximum_matching.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0/\u4E00\
      \u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
  - icon: ':heavy_check_mark:'
    path: test/math/matrix/linear_equation.test.cpp
    title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/matrix/gauss_jordan.hpp\"\n\n\n\n#include\
    \ <utility>\n\n#line 1 \"include/emthrm/math/matrix/matrix.hpp\"\n\n\n\n#include\
    \ <vector>\n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct Matrix {\n \
    \ explicit Matrix(const int m, const int n, const T def = 0)\n      : data(m,\
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
    \ x; }\n\n private:\n  std::vector<std::vector<T>> data;\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 7 \"include/emthrm/math/matrix/gauss_jordan.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <bool IS_EXTENDED = false, typename T>\nint gauss_jordan(Matrix<T>*\
    \ a, const T eps = 1e-8) {\n  const int m = a->nrow(), n = a->ncol();\n  int rank\
    \ = 0;\n  for (int col = 0; col < (IS_EXTENDED ? n - 1 : n); ++col) {\n    int\
    \ pivot = -1;\n    T mx = eps;\n    for (int row = rank; row < m; ++row) {\n \
    \     const T abs = ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col]);\n\
    \      if (abs > mx) {\n        pivot = row;\n        mx = abs;\n      }\n   \
    \ }\n    if (pivot == -1) continue;\n    std::swap((*a)[rank], (*a)[pivot]);\n\
    \    T tmp = (*a)[rank][col];\n    for (int col2 = 0; col2 < n; ++col2) {\n  \
    \    (*a)[rank][col2] /= tmp;\n    }\n    for (int row = 0; row < m; ++row) {\n\
    \      if (row != rank &&\n          ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col])\
    \ > eps) {\n        tmp = (*a)[row][col];\n        for (int col2 = 0; col2 < n;\
    \ ++col2) {\n          (*a)[row][col2] -= (*a)[rank][col2] * tmp;\n        }\n\
    \      }\n    }\n    ++rank;\n  }\n  return rank;\n}\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_\n#define EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_\n\
    \n#include <utility>\n\n#include \"emthrm/math/matrix/matrix.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <bool IS_EXTENDED = false, typename T>\nint gauss_jordan(Matrix<T>*\
    \ a, const T eps = 1e-8) {\n  const int m = a->nrow(), n = a->ncol();\n  int rank\
    \ = 0;\n  for (int col = 0; col < (IS_EXTENDED ? n - 1 : n); ++col) {\n    int\
    \ pivot = -1;\n    T mx = eps;\n    for (int row = rank; row < m; ++row) {\n \
    \     const T abs = ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col]);\n\
    \      if (abs > mx) {\n        pivot = row;\n        mx = abs;\n      }\n   \
    \ }\n    if (pivot == -1) continue;\n    std::swap((*a)[rank], (*a)[pivot]);\n\
    \    T tmp = (*a)[rank][col];\n    for (int col2 = 0; col2 < n; ++col2) {\n  \
    \    (*a)[rank][col2] /= tmp;\n    }\n    for (int row = 0; row < m; ++row) {\n\
    \      if (row != rank &&\n          ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col])\
    \ > eps) {\n        tmp = (*a)[row][col];\n        for (int col2 = 0; col2 < n;\
    \ ++col2) {\n          (*a)[row][col2] -= (*a)[rank][col2] * tmp;\n        }\n\
    \      }\n    }\n    ++rank;\n  }\n  return rank;\n}\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_MATH_MATRIX_GAUSS_JORDAN_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/matrix/gauss_jordan.hpp
  requiredBy:
  - include/emthrm/math/matrix/linear_equation.hpp
  - include/emthrm/graph/flow/matching/maximum_matching.hpp
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/matrix/linear_equation.test.cpp
  - test/graph/flow/matching/maximum_matching.test.cpp
documentation_of: include/emthrm/math/matrix/gauss_jordan.hpp
layout: document
title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
  \ (Gauss\u2013Jordan elimination)"
---

行基本変形を用いて行列を行階段形に変形するアルゴリズムである。


## 時間計算量

$O(M^2 N)$


## 仕様

|名前|戻り値|要件|備考|
|:--|:--|:--|:--|
|`template <bool IS_EXTENDED = false, typename T>`<br>`int gauss_jordan(Matrix<T>* a, const T eps = 1e-8);`|行列 $A$ のランク|要素の型は実数型または `ModInt` である。|`IS_EXTENDED` は $A$ が拡大係数行列かを表す。<br>$A$ は行階段形に変形される。|


## 参考文献

- http://drken1215.hatenablog.com/entry/2019/03/20/202800


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0004/review/4088546/emthrm/C++14
