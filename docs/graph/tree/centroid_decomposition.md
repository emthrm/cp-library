---
title: 重心分解 (centroid decompositon)
documentation_of: graph/tree/centroid_decomposition.hpp
---

木上で分割統治法を行う際に有用な重心を基にした木の分解方法である．


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`CentroidDecomposition<CostType>(graph)`|木 $\mathrm{graph}$ の重心分解を考える．||
|`root`|重心分解した木の根||
|`comp`|重心分解を行った木||
|`par[i]`|`comp` における頂点 $i$ の親|存在しない場合は $-1$ となる．|


## 参考

- http://compro.tsutajiro.com/archive/190207_divcon.pdf
- https://lumakernel.github.io/ecasdqina/graph/CentroidDecomposition


## ToDo

- https://twitter.com/beet_aizu/status/1142651943971540992


## Verified

https://judge.yosupo.jp/submission/12355
