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
  bundledCode: "#line 1 \"test/data_structure/sparse_table.test.cpp\"\n/*\r\n * @brief\
    \ \u30C7\u30FC\u30BF\u69CB\u9020/sparse table\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#line\
    \ 2 \"data_structure/sparse_table.hpp\"\n#include <cassert>\r\n#include <functional>\r\
    \n#line 5 \"data_structure/sparse_table.hpp\"\n\r\ntemplate <typename MeetSemilattice>\r\
    \nstruct SparseTable {\r\n  using Fn = std::function<MeetSemilattice(MeetSemilattice,\
    \ MeetSemilattice)>;\r\n\r\n  SparseTable() {}\r\n\r\n  SparseTable(const std::vector<MeetSemilattice>\
    \ &a, Fn fn) { init(a, fn); }\r\n\r\n  void init(const std::vector<MeetSemilattice>\
    \ &a, Fn fn_) {\r\n    is_built = true;\r\n    fn = fn_;\r\n    int n = a.size(),\
    \ table_h = 0;\r\n    lg.assign(n + 1, 0);\r\n    for (int i = 2; i <= n; ++i)\
    \ lg[i] = lg[i >> 1] + 1;\r\n    while ((1 << table_h) <= n) ++table_h;\r\n  \
    \  dat.assign(table_h, std::vector<MeetSemilattice>(n));\r\n    for (int j = 0;\
    \ j < n; ++j) dat[0][j] = a[j];\r\n    for (int i = 1; i < table_h; ++i) for (int\
    \ j = 0; j + (1 << i) <= n; ++j) {\r\n      dat[i][j] = fn(dat[i - 1][j], dat[i\
    \ - 1][j + (1 << (i - 1))]);\r\n    }\r\n  }\r\n\r\n  MeetSemilattice query(int\
    \ left, int right) const {\r\n    assert(is_built && left < right);\r\n    int\
    \ h = lg[right - left];\r\n    return fn(dat[h][left], dat[h][right - (1 << h)]);\r\
    \n  }\r\n\r\nprivate:\r\n  bool is_built = false;\r\n  Fn fn;\r\n  std::vector<int>\
    \ lg;\r\n  std::vector<std::vector<MeetSemilattice>> dat;\r\n};\r\n#line 10 \"\
    test/data_structure/sparse_table.test.cpp\"\n\r\nint main() {\r\n  int n, q;\r\
    \n  std::cin >> n >> q;\r\n  std::vector<int> a(n);\r\n  for (int i = 0; i < n;\
    \ ++i) std::cin >> a[i];\r\n  SparseTable<int> dst(a, [](int a, int b) -> int\
    \ { return std::min(a, b); });\r\n  while (q--) {\r\n    int l, r;\r\n    std::cin\
    \ >> l >> r;\r\n    std::cout << dst.query(l, r) << '\\n';\r\n  }\r\n  return\
    \ 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/sparse table\r\n */\r\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include \"../../data_structure/sparse_table.hpp\"\
    \r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<int>\
    \ a(n);\r\n  for (int i = 0; i < n; ++i) std::cin >> a[i];\r\n  SparseTable<int>\
    \ dst(a, [](int a, int b) -> int { return std::min(a, b); });\r\n  while (q--)\
    \ {\r\n    int l, r;\r\n    std::cin >> l >> r;\r\n    std::cout << dst.query(l,\
    \ r) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/data_structure/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/sparse_table.test.cpp
- /verify/test/data_structure/sparse_table.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
---
