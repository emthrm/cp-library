---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product_mod_2
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
    links:
    - https://judge.yosupo.jp/problem/matrix_product_mod_2
  bundledCode: "#line 1 \"test/math/matrix/binary_matrix/binary_matrix.test.cpp\"\n\
    /*\n * @title \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30D0\
    \u30A4\u30CA\u30EA\u884C\u5217\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_product_mod_2\n\
    \ */\n\n#include <algorithm>\n#include <bitset>\n#include <iostream>\n#include\
    \ <ranges>\n#include <string>\n\n#line 1 \"include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
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
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 14 \"test/math/matrix/binary_matrix/binary_matrix.test.cpp\"\
    \n\nint main() {\n  constexpr int N = 4096;\n  int n, m, k;\n  std::cin >> n >>\
    \ m >> k;\n  emthrm::BinaryMatrix<N> a(n, m), b(m, k);\n  for (const int i : std::views::iota(0,\
    \ n)) {\n    std::string s;\n    std::cin >> s;\n    std::ranges::reverse(s);\n\
    \    a[i] = std::bitset<N>(s);\n  }\n  for (const int i : std::views::iota(0,\
    \ m)) {\n    std::string s;\n    std::cin >> s;\n    std::ranges::reverse(s);\n\
    \    b[i] = std::bitset<N>(s);\n  }\n  const emthrm::BinaryMatrix<N> c = a * b;\n\
    \  for (const int i : std::views::iota(0, n)) {\n    for (const int j : std::views::iota(0,\
    \ k)) {\n      std::cout << (c[i].test(j) ? '1' : '0');\n    }\n    std::cout\
    \ << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u30D0\u30A4\u30CA\u30EA\u884C\u5217\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/matrix_product_mod_2\n\
    \ */\n\n#include <algorithm>\n#include <bitset>\n#include <iostream>\n#include\
    \ <ranges>\n#include <string>\n\n#include \"emthrm/math/matrix/binary_matrix/binary_matrix.hpp\"\
    \n\nint main() {\n  constexpr int N = 4096;\n  int n, m, k;\n  std::cin >> n >>\
    \ m >> k;\n  emthrm::BinaryMatrix<N> a(n, m), b(m, k);\n  for (const int i : std::views::iota(0,\
    \ n)) {\n    std::string s;\n    std::cin >> s;\n    std::ranges::reverse(s);\n\
    \    a[i] = std::bitset<N>(s);\n  }\n  for (const int i : std::views::iota(0,\
    \ m)) {\n    std::string s;\n    std::cin >> s;\n    std::ranges::reverse(s);\n\
    \    b[i] = std::bitset<N>(s);\n  }\n  const emthrm::BinaryMatrix<N> c = a * b;\n\
    \  for (const int i : std::views::iota(0, n)) {\n    for (const int j : std::views::iota(0,\
    \ k)) {\n      std::cout << (c[i].test(j) ? '1' : '0');\n    }\n    std::cout\
    \ << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/matrix/binary_matrix/binary_matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/binary_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-02-22 15:34:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/binary_matrix/binary_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/binary_matrix/binary_matrix.test.cpp
- /verify/test/math/matrix/binary_matrix/binary_matrix.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30D0\u30A4\
  \u30CA\u30EA\u884C\u5217"
---
