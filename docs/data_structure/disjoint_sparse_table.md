---
title: disjoint sparse table
documentation_of: //include/emthrm/data_structure/disjoint_sparse_table.hpp
---

[半群](../../.verify-helper/docs/static/algebraic_structure.md)であるデータを含んだ区間に対して高速に演算を行うデータ構造である。


## 時間計算量

$\langle O(N\log{N}), O(1) \rangle$


## 仕様

```cpp
template <typename Semigroup, typename BinOp>
struct DisjointSparseTable;
```

- `Semigroup`：半群である要素型
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


## Submissons

https://judge.yosupo.jp/submission/2718
