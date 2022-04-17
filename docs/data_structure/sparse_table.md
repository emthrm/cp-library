---
title: sparse table
documentation_of: data_structure/sparse_table.hpp
---

[帯](../../.verify-helper/docs/static/algebraic_structure.md)であるデータを含んだ区間に対して高速に演算を行うデータ構造である．


## 時間計算量

$\langle O(N\log{N}), O(1) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`SparseTable<帯>()`|sparse table|
|`SparseTable<帯>(a, 二項演算)`|$A$ の sparse table|
|`init(a, 二項演算)`|$A$ の sparse table を構築する．|
|`query(left, right)`|$[\mathrm{left}, \mathrm{right})$ における演算を行った解|


## 参考

- http://tookunn.hatenablog.com/entry/2016/07/13/211148
- https://github.com/drken1215/algorithm/blob/0db023d94ca9c79a24ef13f5905e6bab056bdafe/DataStructure/sparse_table.cpp


## Verified

https://judge.yosupo.jp/submission/2719
