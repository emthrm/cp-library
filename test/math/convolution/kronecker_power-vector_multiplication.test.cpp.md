---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
    title: "\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\u51AA (Kronecker power) \u3068\u30D9\
      \u30AF\u30C8\u30EB\u306E\u7A4D"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/abc288/tasks/abc288_g
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\
      \u30AB\u30FC\u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D"
    links:
    - https://atcoder.jp/contests/abc288/tasks/abc288_g
  bundledCode: "#line 1 \"test/math/convolution/kronecker_power-vector_multiplication.test.cpp\"\
    \n/*\n * @title \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\
    \u30AB\u30FC\u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc288/tasks/abc288_g\n\
    \ */\n\n#include <cmath>\n#include <iostream>\n#include <vector>\n\n#line 1 \"\
    include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp\"\n\n\
    \n\n#include <cassert>\n#line 7 \"include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp\"\
    \n\n#line 1 \"include/emthrm/math/matrix/matrix.hpp\"\n\n\n\n#line 5 \"include/emthrm/math/matrix/matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct Matrix {\n  explicit Matrix(const\
    \ int m, const int n, const T def = 0)\n      : data(m, std::vector<T>(n, def))\
    \ {}\n\n  int nrow() const { return data.size(); }\n  int ncol() const { return\
    \ data.front().size(); }\n\n  Matrix pow(long long exponent) const {\n    const\
    \ int n = nrow();\n    Matrix<T> res(n, n, 0), tmp = *this;\n    for (int i =\
    \ 0; i < n; ++i) {\n      res[i][i] = 1;\n    }\n    for (; exponent > 0; exponent\
    \ >>= 1) {\n      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n  \
    \  return res;\n  }\n\n  inline const std::vector<T>& operator[](const int i)\
    \ const { return data[i]; }\n  inline std::vector<T>& operator[](const int i)\
    \ { return data[i]; }\n\n  Matrix& operator=(const Matrix& x) = default;\n\n \
    \ Matrix& operator+=(const Matrix& x) {\n    const int m = nrow(), n = ncol();\n\
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
    \ emthrm\n\n\n#line 14 \"test/math/convolution/kronecker_power-vector_multiplication.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  const int m = std::llround(std::pow(3,\
    \ n));\n  std::vector<int> a(m);\n  for (int i = 0; i < m; ++i) {\n    std::cin\
    \ >> a[i];\n  }\n  emthrm::Matrix<int> inv(3, 3);\n  inv[0][1] = inv[1][0] = inv[1][2]\
    \ = inv[2][1] = 1;\n  inv[0][2] = inv[1][1] = inv[2][0] = -1;\n  const std::vector<int>\
    \ b =\n      emthrm::kronecker_power_vector_multiplication(inv, a);\n  for (int\
    \ i = 0; i < m; ++i) {\n    std::cout << b[i] << \" \\n\"[i + 1 == m];\n  }\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\
    \u30AB\u30FC\u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc288/tasks/abc288_g\n\
    \ */\n\n#include <cmath>\n#include <iostream>\n#include <vector>\n\n#include \"\
    emthrm/math/convolution/kronecker_power-vector_multiplication.hpp\"\n#include\
    \ \"emthrm/math/matrix/matrix.hpp\"\n\nint main() {\n  int n;\n  std::cin >> n;\n\
    \  const int m = std::llround(std::pow(3, n));\n  std::vector<int> a(m);\n  for\
    \ (int i = 0; i < m; ++i) {\n    std::cin >> a[i];\n  }\n  emthrm::Matrix<int>\
    \ inv(3, 3);\n  inv[0][1] = inv[1][0] = inv[1][2] = inv[2][1] = 1;\n  inv[0][2]\
    \ = inv[1][1] = inv[2][0] = -1;\n  const std::vector<int> b =\n      emthrm::kronecker_power_vector_multiplication(inv,\
    \ a);\n  for (int i = 0; i < m; ++i) {\n    std::cout << b[i] << \" \\n\"[i +\
    \ 1 == m];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/kronecker_power-vector_multiplication.hpp
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/math/convolution/kronecker_power-vector_multiplication.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/math/convolution/kronecker_power-vector_multiplication.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/kronecker_power-vector_multiplication.test.cpp
- /verify/test/math/convolution/kronecker_power-vector_multiplication.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u30AF\u30ED\u30CD\u30C3\u30AB\u30FC\
  \u51AA\u3068\u30D9\u30AF\u30C8\u30EB\u306E\u7A4D"
---
