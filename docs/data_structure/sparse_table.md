---
title: sparse table
documentation_of: //include/emthrm/data_structure/sparse_table.hpp
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
