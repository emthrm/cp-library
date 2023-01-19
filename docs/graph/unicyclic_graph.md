---
title: unicyclic graph / 1-tree
documentation_of: include/emthrm/graph/unicyclic_graph.hpp
---

閉路をただ一つだけ含む単純連結無向グラフである。俗に[ある漫画家の名前を用いて表現される](https://twitter.com/chokudai/status/772440823170379776)。


## 時間計算量

$O(\lvert V \rvert)$


## 仕様

```cpp
template <typename CostType>
struct UnicyclicGraph;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<bool> is_in_loop`|`is_in_loop[i]` は頂点 $i$ が閉路に含まれるかを表す。|
|`std::vector<int> belong`|`belong[i]` は頂点 $i$ を含む木の番号。ただし存在しないときは $-1$ となる。|
|`std::vector<int> mapping`|`mapping[i]` は頂点 $i$ に対応する木の頂点番号。ただし存在しないときは $-1$ となる。|
|`std::vector<Edge<CostType>> loop`|閉路|
|`std::vector<std::vector<int>> invs`|`invs[i][j]` は木 $i$ の頂点 $j$ に対応する元のグラフの頂点番号を表す。|
|`std::vector<std::vector<std::vector<Edge<CostType>>>> forest`|閉路を除いた森|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit UnicyclicGraph(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const CostType cost = 0);`|コスト $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を加える。|
|`void build();`|構築する。|


## 参考文献

- https://en.wikipedia.org/wiki/Pseudoforest


## Submissons

https://yukicoder.me/submissions/649654
