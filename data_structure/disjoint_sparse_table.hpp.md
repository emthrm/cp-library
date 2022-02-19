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
    \ typename Fn>\r\nstruct DisjointSparseTable {\r\n  explicit DisjointSparseTable(const\
    \ std::vector<Semigroup>& a, const Fn fn)\r\n      : fn(fn) {\r\n    const int\
    \ n = a.size();\r\n    int table_h = 1;\r\n    while ((1 << table_h) < n) ++table_h;\r\
    \n    lg.assign(1 << table_h, 0);\r\n    for (int i = 2; i < (1 << table_h); ++i)\
    \ {\r\n      lg[i] = lg[i >> 1] + 1;\r\n    }\r\n    data.assign(table_h, std::vector<Semigroup>(n));\r\
    \n    std::copy(a.begin(), a.end(), data.front().begin());\r\n    for (int i =\
    \ 1; i < table_h; ++i) {\r\n      const int shift = 1 << i;\r\n      for (int\
    \ left = 0; left < n; left += shift << 1) {\r\n        const int mid = std::min(left\
    \ + shift, n);\r\n        data[i][mid - 1] = a[mid - 1];\r\n        for (int j\
    \ = mid - 2; j >= left; --j) {\r\n          data[i][j] = fn(a[j], data[i][j +\
    \ 1]);\r\n        }\r\n        if (n <= mid) break;\r\n        const int right\
    \ = std::min(mid + shift, n);\r\n        data[i][mid] = a[mid];\r\n        for\
    \ (int j = mid + 1; j < right; ++j) {\r\n          data[i][j] = fn(data[i][j -\
    \ 1], a[j]);\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  Semigroup query(const\
    \ int left, int right) const {\r\n    assert(left < right);\r\n    if (left ==\
    \ --right) return data[0][left];\r\n    const int h = lg[left ^ right];\r\n  \
    \  return fn(data[h][left], data[h][right]);\r\n  }\r\n\r\n private:\r\n  const\
    \ Fn fn;\r\n  std::vector<int> lg;\r\n  std::vector<std::vector<Semigroup>> data;\r\
    \n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <cassert>\r\n#include <vector>\r\
    \n\r\ntemplate <typename Semigroup, typename Fn>\r\nstruct DisjointSparseTable\
    \ {\r\n  explicit DisjointSparseTable(const std::vector<Semigroup>& a, const Fn\
    \ fn)\r\n      : fn(fn) {\r\n    const int n = a.size();\r\n    int table_h =\
    \ 1;\r\n    while ((1 << table_h) < n) ++table_h;\r\n    lg.assign(1 << table_h,\
    \ 0);\r\n    for (int i = 2; i < (1 << table_h); ++i) {\r\n      lg[i] = lg[i\
    \ >> 1] + 1;\r\n    }\r\n    data.assign(table_h, std::vector<Semigroup>(n));\r\
    \n    std::copy(a.begin(), a.end(), data.front().begin());\r\n    for (int i =\
    \ 1; i < table_h; ++i) {\r\n      const int shift = 1 << i;\r\n      for (int\
    \ left = 0; left < n; left += shift << 1) {\r\n        const int mid = std::min(left\
    \ + shift, n);\r\n        data[i][mid - 1] = a[mid - 1];\r\n        for (int j\
    \ = mid - 2; j >= left; --j) {\r\n          data[i][j] = fn(a[j], data[i][j +\
    \ 1]);\r\n        }\r\n        if (n <= mid) break;\r\n        const int right\
    \ = std::min(mid + shift, n);\r\n        data[i][mid] = a[mid];\r\n        for\
    \ (int j = mid + 1; j < right; ++j) {\r\n          data[i][j] = fn(data[i][j -\
    \ 1], a[j]);\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  Semigroup query(const\
    \ int left, int right) const {\r\n    assert(left < right);\r\n    if (left ==\
    \ --right) return data[0][left];\r\n    const int h = lg[left ^ right];\r\n  \
    \  return fn(data[h][left], data[h][right]);\r\n  }\r\n\r\n private:\r\n  const\
    \ Fn fn;\r\n  std::vector<int> lg;\r\n  std::vector<std::vector<Semigroup>> data;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
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
- https://github.com/drken1215/algorithm/blob/f65b8a3b2603f5efb10a8a912c2403b404c29813/DataStructure/disjoint_sparse_table.cpp


## Verified

https://judge.yosupo.jp/submission/2718
