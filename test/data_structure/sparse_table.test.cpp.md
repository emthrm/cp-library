---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/sparse_table.hpp
    title: sparse table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data_structure/sparse_table.test.cpp\"\n/*\n * @brief\
    \ \u30C7\u30FC\u30BF\u69CB\u9020/sparse table\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 3 \"\
    data_structure/sparse_table.hpp\"\n#include <cassert>\n#include <functional>\n\
    #line 6 \"data_structure/sparse_table.hpp\"\n\ntemplate <typename Band>\nstruct\
    \ SparseTable {\n  using Fn = std::function<Band(Band, Band)>;\n\n  SparseTable()\
    \ = default;\n\n  explicit SparseTable(const std::vector<Band>& a, const Fn fn)\
    \ { init(a, fn); }\n\n  void init(const std::vector<Band>& a, const Fn fn_) {\n\
    \    fn = fn_;\n    int n = a.size(), table_h = 0;\n    lg.assign(n + 1, 0);\n\
    \    for (int i = 2; i <= n; ++i) {\n      lg[i] = lg[i >> 1] + 1;\n    }\n  \
    \  while ((1 << table_h) <= n) ++table_h;\n    data.assign(table_h, std::vector<Band>(n));\n\
    \    std::copy(a.begin(), a.end(), data.front().begin());\n    for (int i = 1;\
    \ i < table_h; ++i) {\n      for (int j = 0; j + (1 << i) <= n; ++j) {\n     \
    \   data[i][j] = fn(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);\n      }\n\
    \    }\n  }\n\n  Band query(const int left, const int right) const {\n    assert(left\
    \ < right);\n    const int h = lg[right - left];\n    return fn(data[h][left],\
    \ data[h][right - (1 << h)]);\n  }\n\n private:\n  Fn fn;\n  std::vector<int>\
    \ lg;\n  std::vector<std::vector<Band>> data;\n};\n#line 11 \"test/data_structure/sparse_table.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<int> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  SparseTable<int>\
    \ dst(\n      a, [](const int a, const int b) -> int { return std::min(a, b);\
    \ });\n  while (q--) {\n    int l, r;\n    std::cin >> l >> r;\n    std::cout\
    \ << dst.query(l, r) << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/sparse table\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../data_structure/sparse_table.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<int> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  SparseTable<int>\
    \ dst(\n      a, [](const int a, const int b) -> int { return std::min(a, b);\
    \ });\n  while (q--) {\n    int l, r;\n    std::cin >> l >> r;\n    std::cout\
    \ << dst.query(l, r) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/data_structure/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/sparse_table.test.cpp
- /verify/test/data_structure/sparse_table.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
---
