---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp
    title: "\u9006\u884C\u5217 (inverse matrix) \u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      \u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix_mod_2
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix_mod_2
  bundledCode: "#line 1 \"test/math/matrix/binary_matrix/inverse_matrix.test.cpp\"\
    \n/*\n * @title \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/inverse_matrix_mod_2\n */\n\n#include\
    \ <iostream>\n#include <string>\n\n#line 1 \"include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n\n\n\n#include <bitset>\n#line 6 \"include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n#include <vector>\n\nnamespace emthrm {\n\ntemplate <int N>\nstruct BinaryMatrix\
    \ {\n  explicit BinaryMatrix(const int m, const int n = N, const bool def = false)\n\
    \      : n(n), data(m, std::bitset<N>(std::string(n, def ? '1' : '0'))) {}\n\n\
    \  int nrow() const { return data.size(); }\n  int ncol() const { return n; }\n\
    \n  BinaryMatrix pow(long long exponent) const {\n    BinaryMatrix res(n, n),\
    \ tmp = *this;\n    for (int i = 0; i < n; ++i) {\n      res[i].set(i);\n    }\n\
    \    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1) res *= tmp;\n\
    \      tmp *= tmp;\n    }\n    return res;\n  }\n\n  inline const std::bitset<N>&\
    \ operator[](const int i) const { return data[i]; }\n  inline std::bitset<N>&\
    \ operator[](const int i) { return data[i]; }\n\n  BinaryMatrix& operator=(const\
    \ BinaryMatrix& x) = default;\n\n  BinaryMatrix& operator+=(const BinaryMatrix&\
    \ x) {\n    const int m = nrow();\n    for (int i = 0; i < m; ++i) {\n      data[i]\
    \ ^= x[i];\n    }\n    return *this;\n  }\n\n  BinaryMatrix& operator*=(const\
    \ BinaryMatrix& x) {\n    const int m = nrow(), l = x.ncol();\n    BinaryMatrix\
    \ t_x(l, n), res(m, l);\n    for (int i = 0; i < l; ++i) {\n      for (int j =\
    \ 0; j < n; ++j) {\n        t_x[i][j] = x[j][i];\n      }\n    }\n    for (int\
    \ i = 0; i < m; ++i) {\n      for (int j = 0; j < l; ++j) {\n        if ((data[i]\
    \ & t_x[j]).count() & 1) res[i].set(j);\n      }\n    }\n    return *this = res;\n\
    \  }\n\n  BinaryMatrix operator+(const BinaryMatrix& x) const {\n    return BinaryMatrix(*this)\
    \ += x;\n  }\n  BinaryMatrix operator*(const BinaryMatrix& x) const {\n    return\
    \ BinaryMatrix(*this) *= x;\n  }\n\n private:\n  int n;\n  std::vector<std::bitset<N>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp\"\
    \n\n\n\n#include <cassert>\n#include <utility>\n\n#line 8 \"include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int N>\nBinaryMatrix<N> inverse_matrix(const\
    \ BinaryMatrix<N>& a) {\n  const int n = a.nrow();\n  BinaryMatrix<N> b(n, n <<\
    \ 1, 0);\n  for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n\
    \      b[i][j] = a[i][j];\n    }\n    b[i][n + i] = 1;\n  }\n  for (int col =\
    \ 0; col < n; ++col) {\n    int pivot = -1;\n    for (int row = col; row < n;\
    \ ++row) {\n      if (b[row][col]) {\n        pivot = row;\n        break;\n \
    \     }\n    }\n    if (pivot == -1) return BinaryMatrix<N>(0, 0);\n    std::swap(b[col],\
    \ b[pivot]);\n    for (int row = 0; row < n; ++row) {\n      if (row != col &&\
    \ b[row][col]) b[row] ^= b[col];\n    }\n  }\n  BinaryMatrix<N> inv(n, n);\n \
    \ for (int i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      inv[i][j]\
    \ = b[i][n + j];\n    }\n  }\n  return inv;\n}\n\n}  // namespace emthrm\n\n\n\
    #line 12 \"test/math/matrix/binary_matrix/inverse_matrix.test.cpp\"\n\nint main()\
    \ {\n  constexpr int kMaxN = (1 << 12) * 2;\n  int n;\n  std::cin >> n;\n  emthrm::BinaryMatrix<kMaxN>\
    \ a(n, n);\n  for (int i = 0; i < n; ++i) {\n    std::string a_i;\n    std::cin\
    \ >> a_i;\n    for (int j = 0; j < n; ++j) {\n      if (a_i[j] == '1') a[i].set(j);\n\
    \    }\n  }\n  a = inverse_matrix(a);\n  if (a.nrow() == 0) {\n    std::cout <<\
    \ \"-1\\n\";\n  } else {\n    for (int i = 0; i < n; ++i) {\n      for (int j\
    \ = 0; j < n; ++j) {\n        std::cout << a[i][j];\n      }\n      std::cout\
    \ << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/inverse_matrix_mod_2\n */\n\n#include\
    \ <iostream>\n#include <string>\n\n#include \"emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n#include \"emthrm/math/matrix/binary_matrix/inverse_matrix.hpp\"\n\nint main()\
    \ {\n  constexpr int kMaxN = (1 << 12) * 2;\n  int n;\n  std::cin >> n;\n  emthrm::BinaryMatrix<kMaxN>\
    \ a(n, n);\n  for (int i = 0; i < n; ++i) {\n    std::string a_i;\n    std::cin\
    \ >> a_i;\n    for (int j = 0; j < n; ++j) {\n      if (a_i[j] == '1') a[i].set(j);\n\
    \    }\n  }\n  a = inverse_matrix(a);\n  if (a.nrow() == 0) {\n    std::cout <<\
    \ \"-1\\n\";\n  } else {\n    for (int i = 0; i < n; ++i) {\n      for (int j\
    \ = 0; j < n; ++j) {\n        std::cout << a[i][j];\n      }\n      std::cout\
    \ << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
  - include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-06-22 01:08:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/binary_matrix/inverse_matrix.test.cpp
- /verify/test/math/matrix/binary_matrix/inverse_matrix.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9006\u884C\
  \u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
---
