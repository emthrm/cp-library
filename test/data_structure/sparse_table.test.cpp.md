---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data_structure/sparse_table.test.cpp\"\n/*\n * @title\
    \ \u30C7\u30FC\u30BF\u69CB\u9020/sparse table\n *\n * verification-helper: PROBLEM\
    \ https://judge.yosupo.jp/problem/staticrmq\n */\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/data_structure/sparse_table.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/data_structure/sparse_table.hpp\"\n#include <bit>\n\
    #include <cassert>\n#include <functional>\n#line 9 \"include/emthrm/data_structure/sparse_table.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Band>\nstruct SparseTable {\n  using\
    \ BinOp = std::function<Band(Band, Band)>;\n\n  SparseTable() = default;\n\n \
    \ explicit SparseTable(const std::vector<Band>& a, const BinOp bin_op) {\n   \
    \ init(a, bin_op);\n  }\n\n  void init(const std::vector<Band>& a, const BinOp\
    \ bin_op_) {\n    bin_op = bin_op_;\n    const int n = a.size();\n    assert(n\
    \ > 0);\n    lg.assign(n + 1, 0);\n    for (int i = 2; i <= n; ++i) {\n      lg[i]\
    \ = lg[i >> 1] + 1;\n    }\n    const int table_h = std::countr_zero(std::bit_floor(a.size()))\
    \ + 1;\n    data.assign(table_h, std::vector<Band>(n));\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\n    for (int i = 1; i < table_h; ++i) {\n \
    \     for (int j = 0; j + (1 << i) <= n; ++j) {\n        data[i][j] = bin_op(data[i\
    \ - 1][j], data[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\n  Band query(const\
    \ int left, const int right) const {\n    assert(left < right);\n    const int\
    \ h = lg[right - left];\n    return bin_op(data[h][left], data[h][right - (1 <<\
    \ h)]);\n  }\n\n private:\n  BinOp bin_op;\n  std::vector<int> lg;\n  std::vector<std::vector<Band>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 12 \"test/data_structure/sparse_table.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<int> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  emthrm::SparseTable<int>\
    \ dst(\n      a, [](const int a, const int b) -> int { return std::min(a, b);\
    \ });\n  while (q--) {\n    int l, r;\n    std::cin >> l >> r;\n    std::cout\
    \ << dst.query(l, r) << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/sparse table\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/staticrmq\n */\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/sparse_table.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<int> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  emthrm::SparseTable<int>\
    \ dst(\n      a, [](const int a, const int b) -> int { return std::min(a, b);\
    \ });\n  while (q--) {\n    int l, r;\n    std::cin >> l >> r;\n    std::cout\
    \ << dst.query(l, r) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/data_structure/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/sparse_table.test.cpp
- /verify/test/data_structure/sparse_table.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
---
