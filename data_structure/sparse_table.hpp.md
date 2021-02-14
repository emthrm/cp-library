---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca_euler_tour.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
      \u30FC\u7248"
  - icon: ':heavy_check_mark:'
    path: string/lcp.hpp
    title: longest common prefix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/sparse_table.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lca_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  - icon: ':heavy_check_mark:'
    path: test/string/lcp.test.cpp
    title: "\u6587\u5B57\u5217/longest common prefix"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/sparse_table.hpp\"\n#include <cassert>\r\n\
    #include <functional>\r\n#include <vector>\r\n\r\ntemplate <typename MeetSemilattice>\r\
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
    \ lg;\r\n  std::vector<std::vector<MeetSemilattice>> dat;\r\n};\r\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <functional>\r\n#include <vector>\r\
    \n\r\ntemplate <typename MeetSemilattice>\r\nstruct SparseTable {\r\n  using Fn\
    \ = std::function<MeetSemilattice(MeetSemilattice, MeetSemilattice)>;\r\n\r\n\
    \  SparseTable() {}\r\n\r\n  SparseTable(const std::vector<MeetSemilattice> &a,\
    \ Fn fn) { init(a, fn); }\r\n\r\n  void init(const std::vector<MeetSemilattice>\
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
    \ lg;\r\n  std::vector<std::vector<MeetSemilattice>> dat;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/sparse_table.hpp
  requiredBy:
  - string/lcp.hpp
  - graph/tree/lca_euler_tour.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/sparse_table.test.cpp
  - test/string/lcp.test.cpp
  - test/graph/tree/lca_euler_tour.test.cpp
documentation_of: data_structure/sparse_table.hpp
layout: document
title: sparse table
---

[meet-semilattice](../../.verify-helper/docs/static/algebraic_structure.md) であるデータを含んだ区間に対して高速に演算を行うデータ構造である．


## 時間計算量

$\langle O(N\log{N}), O(1) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`SparseTable<MeetSemilattice>()`|sparse table|
|`SparseTable<MeetSemilattice>(a, 二項演算)`|$A$ の sparse table|
|`init(a, 二項演算)`|$A$ の sparse table を構築する．|
|`query(left, right)`|$[\mathrm{left}, \mathrm{right})$ における演算を行った解|


## 参考

- http://tookunn.hatenablog.com/entry/2016/07/13/211148
- https://github.com/drken1215/algorithm/blob/master/DataStructure/sparse_table.cpp


## Verified

https://judge.yosupo.jp/submission/2719
