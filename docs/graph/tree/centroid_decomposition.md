---
title: 重心分解 (centroid decompositon)
documentation_of: include/emthrm/graph/tree/centroid_decomposition.hpp
---

重心を基にした木の分解法の一つである。木上で分割統治法を行うときに有用である。


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 仕様

```cpp
template <typename CostType>
struct CentroidDecomposition;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`int root`|重心分解した木の根|
|`std::vector<int> parent`|`parent[i]` は `g` における頂点 $i$ の親を表す。ただし存在しないときは $-1$ となる。|
|`std::vector<std::vector<int>> g`|重心分解を行った木|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit CentroidDecomposition(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- http://compro.tsutajiro.com/archive/190207_divcon.pdf
- https://lumakernel.github.io/ecasdqina/graph/CentroidDecomposition


## TODO

- https://twitter.com/beet_aizu/status/1142651943971540992


## Submissons

https://judge.yosupo.jp/submission/12355
