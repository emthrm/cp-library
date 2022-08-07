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
  bundledCode: "#line 2 \"data_structure/disjoint_sparse_table.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\ntemplate <typename Semigroup, typename\
    \ Fn>\nstruct DisjointSparseTable {\n  explicit DisjointSparseTable(const std::vector<Semigroup>&\
    \ a, const Fn fn)\n      : fn(fn) {\n    const int n = a.size();\n    int table_h\
    \ = 1;\n    while ((1 << table_h) < n) ++table_h;\n    lg.assign(1 << table_h,\
    \ 0);\n    for (int i = 2; i < (1 << table_h); ++i) {\n      lg[i] = lg[i >> 1]\
    \ + 1;\n    }\n    data.assign(table_h, std::vector<Semigroup>(n));\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\n    for (int i = 1; i < table_h; ++i) {\n \
    \     const int shift = 1 << i;\n      for (int left = 0; left < n; left += shift\
    \ << 1) {\n        const int mid = std::min(left + shift, n);\n        data[i][mid\
    \ - 1] = a[mid - 1];\n        for (int j = mid - 2; j >= left; --j) {\n      \
    \    data[i][j] = fn(a[j], data[i][j + 1]);\n        }\n        if (n <= mid)\
    \ break;\n        const int right = std::min(mid + shift, n);\n        data[i][mid]\
    \ = a[mid];\n        for (int j = mid + 1; j < right; ++j) {\n          data[i][j]\
    \ = fn(data[i][j - 1], a[j]);\n        }\n      }\n    }\n  }\n\n  Semigroup query(const\
    \ int left, int right) const {\n    assert(left < right);\n    if (left == --right)\
    \ return data[0][left];\n    const int h = lg[left ^ right];\n    return fn(data[h][left],\
    \ data[h][right]);\n  }\n\n private:\n  const Fn fn;\n  std::vector<int> lg;\n\
    \  std::vector<std::vector<Semigroup>> data;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename Semigroup, typename Fn>\nstruct DisjointSparseTable {\n \
    \ explicit DisjointSparseTable(const std::vector<Semigroup>& a, const Fn fn)\n\
    \      : fn(fn) {\n    const int n = a.size();\n    int table_h = 1;\n    while\
    \ ((1 << table_h) < n) ++table_h;\n    lg.assign(1 << table_h, 0);\n    for (int\
    \ i = 2; i < (1 << table_h); ++i) {\n      lg[i] = lg[i >> 1] + 1;\n    }\n  \
    \  data.assign(table_h, std::vector<Semigroup>(n));\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\n    for (int i = 1; i < table_h; ++i) {\n \
    \     const int shift = 1 << i;\n      for (int left = 0; left < n; left += shift\
    \ << 1) {\n        const int mid = std::min(left + shift, n);\n        data[i][mid\
    \ - 1] = a[mid - 1];\n        for (int j = mid - 2; j >= left; --j) {\n      \
    \    data[i][j] = fn(a[j], data[i][j + 1]);\n        }\n        if (n <= mid)\
    \ break;\n        const int right = std::min(mid + shift, n);\n        data[i][mid]\
    \ = a[mid];\n        for (int j = mid + 1; j < right; ++j) {\n          data[i][j]\
    \ = fn(data[i][j - 1], a[j]);\n        }\n      }\n    }\n  }\n\n  Semigroup query(const\
    \ int left, int right) const {\n    assert(left < right);\n    if (left == --right)\
    \ return data[0][left];\n    const int h = lg[left ^ right];\n    return fn(data[h][left],\
    \ data[h][right]);\n  }\n\n private:\n  const Fn fn;\n  std::vector<int> lg;\n\
    \  std::vector<std::vector<Semigroup>> data;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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


## ToDo

- sqrt-tree
  - https://codeforces.com/blog/entry/57046
  - https://qiita.com/sotanishy/items/89f4dd452bcddd332f24
  - https://cp-algorithms.com/data_structures/sqrt-tree.html
  - https://qiita.com/sotanishy/items/89f4dd452bcddd332f24
  - https://sotanishy.github.io/cp-library-cpp/data-structure/sqrt_tree.cpp


## Verified

https://judge.yosupo.jp/submission/2718
