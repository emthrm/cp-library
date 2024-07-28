---
title: 最小シュタイナー木 (minimum Steiner tree)
documentation_of: //include/emthrm/graph/minimum_steiner_tree.hpp
---


## 時間計算量

ターミナルの数を $T$ とおくと $O(3^T \lvert V \rvert + 2^T \lvert E \rvert \log{\lvert E \rvert})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`CostType minimum_steiner_tree(const std::vector<std::vector<Edge<CostType>>>& graph, std::vector<int> terminals);`|無向グラフ $\mathrm{graph}$ の最小シュタイナー木におけるコスト|


## 参考文献

- https://www.slideshare.net/wata_orz/ss-12131479


## Submissons

https://atcoder.jp/contests/abc364/submissions/56083584
