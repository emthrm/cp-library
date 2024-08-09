---
title: 指定された頂点たちの最小共通祖先関係を保って木を圧縮してできる補助的な木
documentation_of: //include/emthrm/graph/tree/auxiliary_tree.hpp
---


## 時間計算量

指定する頂点の数を $K$ とおくと $\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\lvert K \rvert \log{\lvert K \rvert}) \rangle$


## 仕様

```cpp
template <typename CostType>
struct AuxiliaryTree;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`LowestCommonAncestor<CostType> euler_tour`|[Euler tour technique](euler_tour_technique.md)|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit AuxiliaryTree(const std::vector<std::vector<Edge<CostType>>>& graph, const int root = 0);`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`std::pair<std::vector<std::vector<Edge<CostType>>>, std::vector<int>> query(std::vector<int> vertices) const;`|頂点集合 $\mathrm{vertices}$ に対して構築した木|


## 参考文献

- https://noshi91.github.io/algorithm-encyclopedia/auxiliary-tree
- https://www.slideshare.net/iwiwi/2-12188845/7
- https://sotanishy.github.io/cp-library-cpp/tree/auxiliary_tree.cpp


## Submissons

https://atcoder.jp/contests/typical90/submissions/56497303
