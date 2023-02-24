---
title: lowlink
documentation_of: //include/emthrm/graph/lowlink.hpp
---

深さ優先探索木 (depth-first search tree) で頂点 $i$ の訪問時刻を $\mathrm{order}_i$ とおく。このとき子孫から後退辺 (back edge) を高々一度通ることで到達できる頂点の $\mathrm{order}$ の最小値である。


### 橋 (bridge)

無向グラフ $G = (V, E)$ に対して、グラフ $(V, E \setminus \lbrace e \rbrace)$ が非連結となる辺 $e$ である。


### 関節点 (articulation point)

無向グラフ $G = (V, E)$ に対して、グラフ $(V \setminus \lbrace v \rbrace, E)$ が非連結となる頂点 $v$ である。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

```cpp
template <typename CostType>
struct Lowlink;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> order`|`order[i]` は頂点 $i$ の訪問時刻を表す。||
|`std::vector<int> lowlink`|lowlink||
|`std::vector<int> articulation_points`|関節点の集合||
|`std::vector<Edge<CostType>> bridges`|橋の集合|多重辺に対応していない。|
|`const std::vector<std::vector<Edge<CostType>>> graph`|無向グラフ||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Lowlink(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- http://kagamiz.hatenablog.com/entry/2013/10/05/005213


## Submissons

- [橋](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_B/review/4082818/emthrm/C++14)
- [関節点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_3_A/review/4082810/emthrm/C++14)
