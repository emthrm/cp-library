---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':warning:'
    path: test/math/convolution/kronecker_power-vector_multiplication.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\
      \u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp\"\
    \n\n\n\n#include <cassert>\n#include <cmath>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/math/matrix/matrix.hpp\"\n\n\n\n#line 5 \"include/emthrm/math/matrix/matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct Matrix {\n  explicit Matrix(const\
    \ int m, const int n, const T def = 0)\n      : data(m, std::vector<T>(n, def))\
    \ {}\n\n  int nrow() const { return data.size(); }\n  int ncol() const { return\
    \ data.empty() ? 0 : data.front().size(); }\n\n  Matrix pow(long long exponent)\
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
    \ emthrm\n\n\n#line 9 \"include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> kronecker_power_vector_multiplication(const\
    \ Matrix<T>& g,\n                                                     std::vector<T>\
    \ v) {\n  const int d = g.nrow(), n = v.size();\n  assert(std::llround(std::pow(d,\
    \ std::log(n) / std::log(d))) == n);\n  Matrix<T> tmp(d, 1);\n  for (int block\
    \ = 1; block < n; block *= d) {\n    for (int i = 0; i < n; i += block * d) {\n\
    \      for (int j = 0; j < block; ++j) {\n        for (int x = 0; x < d; ++x)\
    \ {\n          tmp[x][0] = v[i + j + block * x];\n        }\n        tmp = g *\
    \ tmp;\n        for (int x = 0; x < d; ++x) {\n          v[i + j + block * x]\
    \ = tmp[x][0];\n        }\n      }\n    }\n  }\n  return v;\n}\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_\n\
    #define EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_\n\n\
    #include <cassert>\n#include <cmath>\n#include <vector>\n\n#include \"emthrm/math/matrix/matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> kronecker_power_vector_multiplication(const\
    \ Matrix<T>& g,\n                                                     std::vector<T>\
    \ v) {\n  const int d = g.nrow(), n = v.size();\n  assert(std::llround(std::pow(d,\
    \ std::log(n) / std::log(d))) == n);\n  Matrix<T> tmp(d, 1);\n  for (int block\
    \ = 1; block < n; block *= d) {\n    for (int i = 0; i < n; i += block * d) {\n\
    \      for (int j = 0; j < block; ++j) {\n        for (int x = 0; x < d; ++x)\
    \ {\n          tmp[x][0] = v[i + j + block * x];\n        }\n        tmp = g *\
    \ tmp;\n        for (int x = 0; x < d; ++x) {\n          v[i + j + block * x]\
    \ = tmp[x][0];\n        }\n      }\n    }\n  }\n  return v;\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_MATH_CONVOLUTION_KRONECKER_POWER_VECTOR_MULTIPLICATION_HPP_\n"
  dependsOn:
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: false
  path: include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
  requiredBy: []
  timestamp: '2023-12-25 04:31:42+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/math/convolution/kronecker_power-vector_multiplication.test.cpp
documentation_of: include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
layout: document
title: "\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\u51AA (Kronecker power) \u3068\u30D9\u30AF\
  \u30C8\u30EB\u306E\u7A4D"
---

$G \in K^{d \times d},\ \boldsymbol{v} \in K^{d^n}$ に対して $G^{\otimes n} \boldsymbol{v}$ を求める。ここで

$$
A \otimes B \mathrel{:=}
\begin{pmatrix}
  a_{11} B & \cdots & a_{1n} B \\
  \vdots   & \ddots & \vdots   \\
  a_{m1} B & \cdots & a_{mn} B
\end{pmatrix}
\quad (A \in K^{m \times n})
$$

はクロネッカー積である。


## 時間計算量

$O(N D^{N + 1})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> kronecker_power_vector_multiplication(const Matrix<T>& g, std::vector<T> v);`|$G^{\otimes n} \boldsymbol{v}$|


## 参考文献

- http://q.c.titech.ac.jp/docs/progs/kronecker.html
- https://suisen-cp.github.io/cp-library-cpp/library/transform/kronecker_power.hpp


## Submissons

https://atcoder.jp/contests/abc288/submissions/39117221
