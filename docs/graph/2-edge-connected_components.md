# 二重辺連結成分 (2-edge-connected component) 分解

無向グラフを橋の存在しない部分グラフに分解することである。

それぞれの成分には、任意の3点を始点・経由点・終点とする辺素パスが存在し、さらに任意の2点を結ぶ2本以上の辺素パスが存在する。


### bridge-block tree

二重辺連結成分を一つの頂点に縮約することで得られる木である。


## 時間計算量

||時間計算量|
|:--|:--|
|[lowlink](lowlink.md) 版|$O(\lvert V \rvert + \lvert E \rvert)$|
|いもす法版|$O(\lvert V \rvert + \lvert E \rvert \log{\lvert E \rvert})$|


## 仕様

### lowlink 版

```cpp
template <typename CostType>
struct TwoEdgeConnectedComponents : Lowlink<CostType>;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|要件|
|:--|:--|:--|
|`std::vector<int> id`|`id[i]` は元のグラフの頂点 $i$ を含む頂点を表す。||
|`std::vector<std::vector<int>> vertices`|`vertices[i]` は縮約後のグラフの頂点 $i$ に含まれる頂点を表す。|完全版|
|`std::vector<std::vector<Edge<CostType>>> g`|二重辺連結成分を一つの頂点に縮約したグラフ||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit TwoEdgeConnectedComponents(const std::vector<std::vector<Edge<CostType>>>& graph, const bool is_full_ver = false);`|無向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


### いもす法版

```cpp
template <typename CostType>
struct TwoEdgeConnectedComponentsByImos;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|要件|
|:--|:--|:--|
|`std::vector<int> id`|`id[i]` は元のグラフの頂点 $i$ を含む頂点を表す。||
|`std::vector<Edge<CostType>> bridge`|橋||
|`std::vector<std::vector<int>> vertices`|`vertices[i]` は縮約後のグラフの頂点 $i$ に含まれる頂点を表す。|完全版|
|`std::vector<std::vector<Edge<CostType>>> g`|二重辺連結成分を一つの頂点に縮約したグラフ||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit TwoEdgeConnectedComponentsByImos(const std::vector<std::vector<Edge<CostType>>>& graph, const bool is_full_ver = false);`|無向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- https://en.wikipedia.org/wiki/Bridge_(graph_theory)
- https://www.slideshare.net/chokudai/arc039

lowlink 版
- https://ei1333.github.io/luzhiled/snippets/graph/two-edge-connected-components.html


## TODO

- 三重辺連結成分分解
  - https://ja.wikipedia.org/wiki/%E9%80%A3%E7%B5%90%E3%82%B0%E3%83%A9%E3%83%95
  - https://judge.yosupo.jp/problem/three_edge_connected_components


## Submissons

- [lowlink 版](https://atcoder.jp/contests/arc039/submissions/9288123)
- [いもす法版](https://judge.yosupo.jp/submission/5729)
