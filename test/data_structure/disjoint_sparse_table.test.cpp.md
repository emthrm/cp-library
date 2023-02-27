---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/disjoint_sparse_table.hpp
    title: disjoint sparse table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table"
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data_structure/disjoint_sparse_table.test.cpp\"\n/*\n\
    \ * @title \u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/staticrmq\n */\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/data_structure/disjoint_sparse_table.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/data_structure/disjoint_sparse_table.hpp\"\n\
    #include <bit>\n#include <cassert>\n#line 8 \"include/emthrm/data_structure/disjoint_sparse_table.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Semigroup, typename BinOp>\nstruct\
    \ DisjointSparseTable {\n  explicit DisjointSparseTable(const std::vector<Semigroup>&\
    \ a,\n                               const BinOp bin_op = BinOp())\n      : bin_op(bin_op)\
    \ {\n    const int table_h = std::max(std::countr_zero(std::bit_ceil(a.size())),\
    \ 1);\n    lg.assign(1 << table_h, 0);\n    for (int i = 2; i < (1 << table_h);\
    \ ++i) {\n      lg[i] = lg[i >> 1] + 1;\n    }\n    const int n = a.size();\n\
    \    data.assign(table_h, std::vector<Semigroup>(n));\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\n    for (int i = 1; i < table_h; ++i) {\n \
    \     const int shift = 1 << i;\n      for (int left = 0; left < n; left += shift\
    \ << 1) {\n        const int mid = std::min(left + shift, n);\n        data[i][mid\
    \ - 1] = a[mid - 1];\n        for (int j = mid - 2; j >= left; --j) {\n      \
    \    data[i][j] = bin_op(a[j], data[i][j + 1]);\n        }\n        if (n <= mid)\
    \ break;\n        const int right = std::min(mid + shift, n);\n        data[i][mid]\
    \ = a[mid];\n        for (int j = mid + 1; j < right; ++j) {\n          data[i][j]\
    \ = bin_op(data[i][j - 1], a[j]);\n        }\n      }\n    }\n  }\n\n  Semigroup\
    \ query(const int left, int right) const {\n    assert(left < right);\n    if\
    \ (left == --right) return data[0][left];\n    const int h = lg[left ^ right];\n\
    \    return bin_op(data[h][left], data[h][right]);\n  }\n\n private:\n  const\
    \ BinOp bin_op;\n  std::vector<int> lg;\n  std::vector<std::vector<Semigroup>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 12 \"test/data_structure/disjoint_sparse_table.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<int> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  emthrm::DisjointSparseTable\
    \ disjoint_sparse_table(\n      a, [](const int a, const int b) -> int { return\
    \ std::min(a, b); });\n  while (q--) {\n    int l, r;\n    std::cin >> l >> r;\n\
    \    std::cout << disjoint_sparse_table.query(l, r) << '\\n';\n  }\n  return 0;\n\
    }\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table\n *\n\
    \ * verification-helper: PROBLEM https://judge.yosupo.jp/problem/staticrmq\n */\n\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    emthrm/data_structure/disjoint_sparse_table.hpp\"\n\nint main() {\n  int n, q;\n\
    \  std::cin >> n >> q;\n  std::vector<int> a(n);\n  for (int i = 0; i < n; ++i)\
    \ {\n    std::cin >> a[i];\n  }\n  emthrm::DisjointSparseTable disjoint_sparse_table(\n\
    \      a, [](const int a, const int b) -> int { return std::min(a, b); });\n \
    \ while (q--) {\n    int l, r;\n    std::cin >> l >> r;\n    std::cout << disjoint_sparse_table.query(l,\
    \ r) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/data_structure/disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/disjoint_sparse_table.test.cpp
- /verify/test/data_structure/disjoint_sparse_table.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table"
---
