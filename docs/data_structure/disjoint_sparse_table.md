---
title: disjoint sparse table
documentation_of: data_structure/disjoint_sparse_table.hpp
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
