---
title: 重心分解 (centroid decompositon)
documentation_of: graph/tree/centroid_decomposition.hpp
---

重心を基にした木の分解法の一つである．木上で分割統治法を行うときに有用である．


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`CentroidDecomposition<CostType>(graph)`|木 $\mathrm{graph}$ の重心分解を考える．||
|`root`|重心分解した木の根||
|`parent[i]`|`g` における頂点 $i$ の親|存在しないときは $-1$ となる．|
|`g`|重心分解を行った木||


## 参考

- http://compro.tsutajiro.com/archive/190207_divcon.pdf
- https://lumakernel.github.io/ecasdqina/graph/CentroidDecomposition


## ToDo

- https://twitter.com/beet_aizu/status/1142651943971540992


## Verified

https://judge.yosupo.jp/submission/12355
