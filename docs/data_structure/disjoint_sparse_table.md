---
title: disjoint sparse table
documentation_of: include/emthrm/data_structure/disjoint_sparse_table.hpp
---

[半群](../../.verify-helper/docs/static/algebraic_structure.md)であるデータを含んだ区間に対して高速に演算を行うデータ構造である。


## 時間計算量

$\langle O(N\log{N}), O(1) \rangle$


## 仕様

|名前|効果・戻り値|
|:--|:--|
|`DisjointSparseTable<Semigroup, decltype(二項演算)>(a, 二項演算)`|$A$ の disjoint sparse table|
|`query(left, right)`|$[\mathrm{left}, \mathrm{right})$ における二項演算を行った解|


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
