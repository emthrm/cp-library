---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/disjoint_sparse_table.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/disjoint_sparse_table.hpp\"\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <vector>\r\n\r\ntemplate <typename Semigroup,\
    \ typename Fn>\r\nstruct DisjointSparseTable {\r\n  DisjointSparseTable(const\
    \ std::vector<Semigroup> &a, Fn fn) : fn(fn) {\r\n    int n = a.size(), table_h\
    \ = 1;\r\n    while ((1 << table_h) < n) ++table_h;\r\n    lg.assign(1 << table_h,\
    \ 0);\r\n    for (int i = 2; i < (1 << table_h); ++i) lg[i] = lg[i >> 1] + 1;\r\
    \n    dat.assign(table_h, std::vector<Semigroup>(n));\r\n    for (int j = 0; j\
    \ < n; ++j) dat[0][j] = a[j];\r\n    for (int i = 1; i < table_h; ++i) {\r\n \
    \     int shift = 1 << i;\r\n      for (int left = 0; left < n; left += shift\
    \ << 1) {\r\n        int mid = std::min(left + shift, n);\r\n        dat[i][mid\
    \ - 1] = a[mid - 1];\r\n        for (int j = mid - 2; j >= left; --j) dat[i][j]\
    \ = fn(a[j], dat[i][j + 1]);\r\n        if (n <= mid) break;\r\n        int right\
    \ = std::min(mid + shift, n);\r\n        dat[i][mid] = a[mid];\r\n        for\
    \ (int j = mid + 1; j < right; ++j) dat[i][j] = fn(dat[i][j - 1], a[j]);\r\n \
    \     }\r\n    }\r\n  }\r\n\r\n  Semigroup query(int left, int right) const {\r\
    \n    assert(left < right);\r\n    if (left == --right) return dat[0][left];\r\
    \n    int h = lg[left ^ right];\r\n    return fn(dat[h][left], dat[h][right]);\r\
    \n  }\r\n\r\nprivate:\r\n  Fn fn;\r\n  std::vector<int> lg;\r\n  std::vector<std::vector<Semigroup>>\
    \ dat;\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <vector>\r\
    \n\r\ntemplate <typename Semigroup, typename Fn>\r\nstruct DisjointSparseTable\
    \ {\r\n  DisjointSparseTable(const std::vector<Semigroup> &a, Fn fn) : fn(fn)\
    \ {\r\n    int n = a.size(), table_h = 1;\r\n    while ((1 << table_h) < n) ++table_h;\r\
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
    \ dat;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/disjoint_sparse_table.test.cpp
documentation_of: data_structure/disjoint_sparse_table.hpp
layout: document
title: disjoint sparse table
---

[半群](../../.verify-helper/docs/static/algebraic_structure.md)であるデータを含んだ区間に対して高速に演算を行うデータ構造である．


## 時間計算量

$\langle O(N\log{N}), O(1) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`DisjointSparseTable<Semigroup, decltype(二項演算)>(a, 二項演算)`|$A$ の disjoint sparse table|
|`query(left, right)`|$[\mathrm{left}, \mathrm{right})$ における二項演算を行った解|


## 参考

- http://noshi91.hatenablog.com/entry/2018/05/08/183946
- https://github.com/drken1215/algorithm/blob/master/DataStructure/disjoint_sparse_table.cpp


## Verified

https://judge.yosupo.jp/submission/2718
