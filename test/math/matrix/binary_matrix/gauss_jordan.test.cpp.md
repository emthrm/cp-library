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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/184
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
      \ \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    links:
    - https://yukicoder.me/problems/no/184
  bundledCode: "#line 1 \"test/math/matrix/binary_matrix/gauss_jordan.test.cpp\"\n\
    /*\n * @title \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30AC\
    \u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5 \u30D0\
    \u30A4\u30CA\u30EA\u884C\u5217\u7248\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/184\n\
    \ */\n\n#include <bitset>\n#include <iostream>\n\n#line 1 \"include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
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
    \    ++rank;\n  }\n  return rank;\n}\n\n}  // namespace emthrm\n\n\n#line 12 \"\
    test/math/matrix/binary_matrix/gauss_jordan.test.cpp\"\n\nint main() {\n  constexpr\
    \ int B = 61;\n  int n;\n  std::cin >> n;\n  emthrm::BinaryMatrix<B> matrix(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    long long a;\n    std::cin >> a;\n    matrix[i]\
    \ = std::bitset<B>(a);\n  }\n  std::cout << (1LL << emthrm::gauss_jordan(&matrix))\
    \ << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5\
    \ \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248\n *\n * verification-helper: PROBLEM\
    \ https://yukicoder.me/problems/no/184\n */\n\n#include <bitset>\n#include <iostream>\n\
    \n#include \"emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\n#include \"\
    emthrm/math/matrix/binary_matrix/gauss_jordan.hpp\"\n\nint main() {\n  constexpr\
    \ int B = 61;\n  int n;\n  std::cin >> n;\n  emthrm::BinaryMatrix<B> matrix(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    long long a;\n    std::cin >> a;\n    matrix[i]\
    \ = std::bitset<B>(a);\n  }\n  std::cout << (1LL << emthrm::gauss_jordan(&matrix))\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
  - include/emthrm/math/matrix/binary_matrix/gauss_jordan.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/gauss_jordan.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/binary_matrix/gauss_jordan.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/binary_matrix/gauss_jordan.test.cpp
- /verify/test/math/matrix/binary_matrix/gauss_jordan.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30AC\u30A6\
  \u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5 \u30D0\u30A4\u30CA\
  \u30EA\u884C\u5217\u7248"
---
