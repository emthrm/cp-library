---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination) \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624
  bundledCode: "#line 1 \"test/math/matrix/binary_matrix/inverse_matrix.test.cpp\"\
    \n/*\n * @title \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624\n */\n\
    \n#include <bitset>\n#include <iostream>\n\n#line 1 \"include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n#include <string>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <int\
    \ N>\nstruct BinaryMatrix {\n  explicit BinaryMatrix(const int m, const int n\
    \ = N, const bool def = false)\n      : n(n), data(m, std::bitset<N>(std::string(n,\
    \ def ? '1' : '0'))) {}\n\n  int nrow() const { return data.size(); }\n  int ncol()\
    \ const { return n; }\n\n  BinaryMatrix pow(long long exponent) const {\n    BinaryMatrix\
    \ res(n, n), tmp = *this;\n    for (int i = 0; i < n; ++i) {\n      res[i].set(i);\n\
    \    }\n    for (; exponent > 0; exponent >>= 1) {\n      if (exponent & 1) res\
    \ *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  inline const std::bitset<N>&\
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
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/matrix/binary_matrix/gauss_jordan.hpp\"\
    \n\n\n\n#include <utility>\n\n#line 7 \"include/emthrm/math/matrix/binary_matrix/gauss_jordan.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <bool IS_EXTENDED = false, int N>\nint gauss_jordan(BinaryMatrix<N>*\
    \ a) {\n  const int m = a->nrow(), n = a->ncol();\n  int rank = 0;\n  for (int\
    \ col = 0; col < (IS_EXTENDED ? n - 1 : n); ++col) {\n    int pivot = -1;\n  \
    \  for (int row = rank; row < m; ++row) {\n      if ((*a)[row][col]) {\n     \
    \   pivot = row;\n        break;\n      }\n    }\n    if (pivot == -1) continue;\n\
    \    std::swap((*a)[rank], (*a)[pivot]);\n    for (int row = 0; row < m; ++row)\
    \ {\n      if (row != rank && (*a)[row][col]) (*a)[row] ^= (*a)[rank];\n    }\n\
    \    ++rank;\n  }\n  return rank;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"\
    include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp\"\n\n\n\n#include\
    \ <cassert>\n#line 6 \"include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp\"\
    \n\n#line 8 \"include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <int N>\nBinaryMatrix<N> inverse_matrix(const BinaryMatrix<N>&\
    \ a) {\n  const int n = a.nrow();\n  BinaryMatrix<N> b(n, n << 1, 0);\n  for (int\
    \ i = 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      b[i][j] = a[i][j];\n\
    \    }\n    b[i][n + i] = 1;\n  }\n  for (int col = 0; col < n; ++col) {\n   \
    \ int pivot = -1;\n    for (int row = col; row < n; ++row) {\n      if (b[row][col])\
    \ {\n        pivot = row;\n        break;\n      }\n    }\n    if (pivot == -1)\
    \ return BinaryMatrix<N>(0, 0);\n    std::swap(b[col], b[pivot]);\n    for (int\
    \ row = 0; row < n; ++row) {\n      if (row != col && b[row][col]) b[row] ^= b[col];\n\
    \    }\n  }\n  BinaryMatrix<N> inv(n, n);\n  for (int i = 0; i < n; ++i) {\n \
    \   for (int j = 0; j < n; ++j) {\n      inv[i][j] = b[i][n + j];\n    }\n  }\n\
    \  return inv;\n}\n\n}  // namespace emthrm\n\n\n#line 13 \"test/math/matrix/binary_matrix/inverse_matrix.test.cpp\"\
    \n\nint main() {\n  constexpr int N = 600;\n  using binary_matrix = emthrm::BinaryMatrix<N>;\n\
    \  int n;\n  std::cin >> n;\n  binary_matrix a(n, n), v(n, 1);\n  for (int i =\
    \ 0; i < n; ++i) {\n    for (int j = 0; j < n; ++j) {\n      int a_ij;\n     \
    \ std::cin >> a_ij;\n      a[i][j] = a_ij;\n    }\n  }\n  for (int i = 0; i <\
    \ n; ++i) {\n    int v_i;\n    std::cin >> v_i;\n    v[i][0] = v_i;\n  }\n  int\
    \ t;\n  std::cin >> t;\n  binary_matrix inv = emthrm::inverse_matrix(a);\n  if\
    \ (inv.nrow() == 0) {\n    a = a.pow(t);\n    binary_matrix av(n, n + 1);\n  \
    \  for (int i = 0; i < n; ++i) {\n      for (int j = 0; j < n; ++j) {\n      \
    \  av[i][j] = a[i][j];\n      }\n      av[i][n] = v[i][0];\n    }\n    std::cout\
    \ << (emthrm::gauss_jordan(&a) == emthrm::gauss_jordan(&av) ?\n              \
    \    \"ambiguous\\n\" : \"none\\n\");\n  } else {\n    inv = inv.pow(t) * v;\n\
    \    for (int i = 0; i < n; ++i) {\n      std::cout << inv[i][0] << \" \\n\"[i\
    \ + 1 == n];\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624\n */\n\
    \n#include <bitset>\n#include <iostream>\n\n#include \"emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n#include \"emthrm/math/matrix/binary_matrix/gauss_jordan.hpp\"\n#include \"\
    emthrm/math/matrix/binary_matrix/inverse_matrix.hpp\"\n\nint main() {\n  constexpr\
    \ int N = 600;\n  using binary_matrix = emthrm::BinaryMatrix<N>;\n  int n;\n \
    \ std::cin >> n;\n  binary_matrix a(n, n), v(n, 1);\n  for (int i = 0; i < n;\
    \ ++i) {\n    for (int j = 0; j < n; ++j) {\n      int a_ij;\n      std::cin >>\
    \ a_ij;\n      a[i][j] = a_ij;\n    }\n  }\n  for (int i = 0; i < n; ++i) {\n\
    \    int v_i;\n    std::cin >> v_i;\n    v[i][0] = v_i;\n  }\n  int t;\n  std::cin\
    \ >> t;\n  binary_matrix inv = emthrm::inverse_matrix(a);\n  if (inv.nrow() ==\
    \ 0) {\n    a = a.pow(t);\n    binary_matrix av(n, n + 1);\n    for (int i = 0;\
    \ i < n; ++i) {\n      for (int j = 0; j < n; ++j) {\n        av[i][j] = a[i][j];\n\
    \      }\n      av[i][n] = v[i][0];\n    }\n    std::cout << (emthrm::gauss_jordan(&a)\
    \ == emthrm::gauss_jordan(&av) ?\n                  \"ambiguous\\n\" : \"none\\\
    n\");\n  } else {\n    inv = inv.pow(t) * v;\n    for (int i = 0; i < n; ++i)\
    \ {\n      std::cout << inv[i][0] << \" \\n\"[i + 1 == n];\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
  - include/emthrm/math/matrix/binary_matrix/gauss_jordan.hpp
  - include/emthrm/math/matrix/binary_matrix/inverse_matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
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
