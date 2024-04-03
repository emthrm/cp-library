---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (lowest common ancestor) Euler tour\
      \ technique \u7248"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/longest_common_prefix.hpp
    title: longest common prefix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/sparse_table.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 Euler tour\
      \ technique \u7248"
  - icon: ':heavy_check_mark:'
    path: test/string/longest_common_prefix.test.cpp
    title: "\u6587\u5B57\u5217/longest common prefix"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/data_structure/sparse_table.hpp\"\n\n\n\n\
    #include <algorithm>\n#include <bit>\n#include <cassert>\n#include <functional>\n\
    #include <vector>\n\nnamespace emthrm {\n\ntemplate <typename Band>\nstruct SparseTable\
    \ {\n  using BinOp = std::function<Band(Band, Band)>;\n\n  SparseTable() = default;\n\
    \n  explicit SparseTable(const std::vector<Band>& a, const BinOp bin_op) {\n \
    \   init(a, bin_op);\n  }\n\n  void init(const std::vector<Band>& a, const BinOp\
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
    \ data;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_\n#define EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_\n\
    \n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <functional>\n\
    #include <vector>\n\nnamespace emthrm {\n\ntemplate <typename Band>\nstruct SparseTable\
    \ {\n  using BinOp = std::function<Band(Band, Band)>;\n\n  SparseTable() = default;\n\
    \n  explicit SparseTable(const std::vector<Band>& a, const BinOp bin_op) {\n \
    \   init(a, bin_op);\n  }\n\n  void init(const std::vector<Band>& a, const BinOp\
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
    \ data;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DATA_STRUCTURE_SPARSE_TABLE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/data_structure/sparse_table.hpp
  requiredBy:
  - include/emthrm/string/longest_common_prefix.hpp
  - include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour_technique.hpp
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/longest_common_prefix.test.cpp
  - test/data_structure/sparse_table.test.cpp
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
documentation_of: include/emthrm/data_structure/sparse_table.hpp
layout: document
title: sparse table
---


## 時間計算量

$\langle O(N\log{N}), O(1) \rangle$


## 仕様

```cpp
template <typename Band>
struct SparseTable;
```

- `Band`：[帯](../../.verify-helper/docs/static/algebraic_structure.md)である要素型

#### メンバ変数

|名前|効果・戻り値|
|:--|:--|
|`SparseTable();`|デフォルトコンストラクタ|
|`explicit SparseTable(const std::vector<Band>& a, const BinOp bin_op);`|$A$ に対して二項演算 $\mathrm{binOp}$ のオブジェクトを構築する。|
|`void init(const std::vector<Band>& a, const BinOp bin_op_);`|$A$ によって初期化する。|
|`Band query(const int left, const int right) const;`|$[\mathrm{left}, \mathrm{right})$ における演算を行った解|

#### メンバ型

|名前|効果・戻り値|
|:--|:--|
|`BinOp`|`std::function<Band(Band, Band)>`|


## 参考文献

- Michael A. Bender and Martín Farach-Colton: The LCA Problem Revisited, *LATIN 2000: Theoretical Informatics*, pp. 88–94 (2000). https://doi.org/10.1007/10719839_9
- http://tookunn.hatenablog.com/entry/2016/07/13/211148
- https://github.com/drken1215/algorithm/blob/0db023d94ca9c79a24ef13f5905e6bab056bdafe/DataStructure/sparse_table.cpp


## Submissons

https://judge.yosupo.jp/submission/2719
