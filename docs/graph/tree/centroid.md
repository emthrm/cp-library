---
title: 重心 (centroid)
documentation_of: //include/emthrm/graph/tree/centroid.hpp
---

根としたときに任意の子の部分木の大きさが木の大きさの半分以下となる頂点である。

任意の木に必ず存在し、高々二つである。二つ存在するとき、木の頂点数は偶数である。


## 時間計算量

$O(\lvert V \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<int> centroid(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ の重心|


## 参考文献

- Camille Jordan: Sur les assemblages de lignes, *Journal für die reine und angewandte Mathematik*, Vol. 70, pp. 185–190 (1869). https://doi.org/10.1515/crll.1869.70.185
- https://qiita.com/drken/items/4b4c3f1824339b090202
- ~~https://lumakernel.github.io/ecasdqina/graph/Centroid~~
- https://img.atcoder.jp/arc087/editorial.pdf


## Submissons

https://atcoder.jp/contests/arc087/submissions/9306188
