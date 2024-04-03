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
  bundledCode: "#line 1 \"include/emthrm/data_structure/disjoint_sparse_table.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename Semigroup, typename BinOp>\nstruct\
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
    \ data;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP_\n#define EMTHRM_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP_\n\
    \n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename Semigroup, typename BinOp>\nstruct\
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
    \ data;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DATA_STRUCTURE_DISJOINT_SPARSE_TABLE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/data_structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/disjoint_sparse_table.test.cpp
documentation_of: include/emthrm/data_structure/disjoint_sparse_table.hpp
layout: document
title: disjoint sparse table
---


## 時間計算量

$\langle O(N\log{N}), O(1) \rangle$


## 仕様

```cpp
template <typename Semigroup, typename BinOp>
struct DisjointSparseTable;
```

- `Semigroup`：[半群](../../.verify-helper/docs/static/algebraic_structure.md)である要素型
- `BinOp`：二項演算を表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit DisjointSparseTable(const std::vector<Semigroup>& a, const BinOp bin_op = BinOp());`|$A$ に対して二項演算 $\mathrm{binOp}$ のオブジェクトを構築する。|
|`Semigroup query(const int left, int right) const;`|$\lbrack \mathrm{left}, \mathrm{right})$ における演算を行った解|


## 参考文献

- http://noshi91.hatenablog.com/entry/2018/05/08/183946
- https://github.com/drken1215/algorithm/blob/f65b8a3b2603f5efb10a8a912c2403b404c29813/DataStructure/disjoint_sparse_table.cpp


## TODO

- sqrt-tree
  - https://codeforces.com/blog/entry/57046
  - https://qiita.com/sotanishy/items/89f4dd452bcddd332f24
  - https://cp-algorithms.com/data_structures/sqrt-tree.html
  - https://qiita.com/sotanishy/items/89f4dd452bcddd332f24
  - https://sotanishy.github.io/cp-library-cpp/data-structure/sqrt_tree.cpp
- 木上の disjoint sparse table
  - https://noshi91.hatenablog.com/entry/2023/12/05/033518


## Submissons

https://judge.yosupo.jp/submission/2718
