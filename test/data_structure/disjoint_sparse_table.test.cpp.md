---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/disjoint_sparse_table.hpp
    title: disjoint sparse table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table"
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data_structure/disjoint_sparse_table.test.cpp\"\n/*\r\
    \n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table\r\n */\r\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n#include <vector>\r\n#line 3 \"data_structure/disjoint_sparse_table.hpp\"\
    \n#include <cassert>\r\n#line 5 \"data_structure/disjoint_sparse_table.hpp\"\n\
    \r\ntemplate <typename Semigroup, typename Fn>\r\nstruct DisjointSparseTable {\r\
    \n  DisjointSparseTable(const std::vector<Semigroup> &a, Fn fn) : fn(fn) {\r\n\
    \    int n = a.size(), table_h = 1;\r\n    while ((1 << table_h) < n) ++table_h;\r\
    \n    lg.assign(1 << table_h, 0);\r\n    for (int i = 2; i < (1 << table_h); ++i)\
    \ lg[i] = lg[i >> 1] + 1;\r\n    dat.assign(table_h, std::vector<Semigroup>(n));\r\
    \n    for (int j = 0; j < n; ++j) dat[0][j] = a[j];\r\n    for (int i = 1; i <\
    \ table_h; ++i) {\r\n      int shift = 1 << i;\r\n      for (int left = 0; left\
    \ < n; left += shift << 1) {\r\n        int mid = std::min(left + shift, n);\r\
    \n        dat[i][mid - 1] = a[mid - 1];\r\n        for (int j = mid - 2; j >=\
    \ left; --j) dat[i][j] = fn(a[j], dat[i][j + 1]);\r\n        if (n <= mid) break;\r\
    \n        int right = std::min(mid + shift, n);\r\n        dat[i][mid] = a[mid];\r\
    \n        for (int j = mid + 1; j < right; ++j) dat[i][j] = fn(dat[i][j - 1],\
    \ a[j]);\r\n      }\r\n    }\r\n  }\r\n\r\n  Semigroup query(int left, int right)\
    \ const {\r\n    assert(left < right);\r\n    if (left == --right) return dat[0][left];\r\
    \n    int h = lg[left ^ right];\r\n    return fn(dat[h][left], dat[h][right]);\r\
    \n  }\r\n\r\nprivate:\r\n  Fn fn;\r\n  std::vector<int> lg;\r\n  std::vector<std::vector<Semigroup>>\
    \ dat;\r\n};\r\n#line 10 \"test/data_structure/disjoint_sparse_table.test.cpp\"\
    \n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<int>\
    \ a(n);\r\n  for (int i = 0; i < n; ++i) std::cin >> a[i];\r\n  auto fn = [](int\
    \ a, int b) -> int { return std::min(a, b); };\r\n  DisjointSparseTable<int, decltype(fn)>\
    \ dst(a, fn);\r\n  while (q--) {\r\n    int l, r;\r\n    std::cin >> l >> r;\r\
    \n    std::cout << dst.query(l, r) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table\r\n\
    \ */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n\
    #include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#include \"\
    ../../data_structure/disjoint_sparse_table.hpp\"\r\n\r\nint main() {\r\n  int\
    \ n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<int> a(n);\r\n  for (int i =\
    \ 0; i < n; ++i) std::cin >> a[i];\r\n  auto fn = [](int a, int b) -> int { return\
    \ std::min(a, b); };\r\n  DisjointSparseTable<int, decltype(fn)> dst(a, fn);\r\
    \n  while (q--) {\r\n    int l, r;\r\n    std::cin >> l >> r;\r\n    std::cout\
    \ << dst.query(l, r) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/data_structure/disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/disjoint_sparse_table.test.cpp
- /verify/test/data_structure/disjoint_sparse_table.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table"
---
