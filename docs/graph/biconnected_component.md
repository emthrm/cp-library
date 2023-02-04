---
title: 二重頂点連結成分 (biconnected component) 分解
documentation_of: include/emthrm/graph/biconnected_component.hpp
---

無向グラフを関節点の存在しない辺集合に分割することである。

それぞれの成分には、任意の相異なる3点を始点・経由点・終点とする単純パスが存在する。


### block-cut tree

二重頂点連結成分を一つの頂点に縮約することで得られる木である。


### カクタスグラフ (cactus)

任意の辺が高々一つの単純閉路に含まれる、すなわち任意の異なる単純閉路が高々一つの共通頂点をもつグラフである。

任意の二重頂点連結成分は橋または単純閉路となる。

e.g. 任意の閉路長が奇数となるグラフ


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$

完全版 $O(\lvert V \rvert \log{\lvert V \rvert} + \lvert E \rvert)$ ?


## 仕様

```cpp
template <typename CostType, bool IS_FULL_VER = false>
struct BiconnectedComponent : Lowlink<CostType>;
```

- `CostType`：辺のコストを表す型
- `IS_FULL_VER`：完全版かを表す変数

#### メンバ変数

|名前|説明|要件|
|:--|:--|:--|
|`std::vector<int> id`|`id[i]` は元のグラフの頂点 $i$ を含むブロックを表す。ただし関節点のときは $-1$ である。|完全版|
|`std::vector<std::vector<int>> vertices`|`vertices[i]` は縮約後のグラフのブロック $i$ に含まれる頂点を表す。|完全版|
|`std::vector<std::vector<int>> cutpoint`|`cutpoint[i]` は元のグラフの関節点 $i$ を含むブロックを表す。|完全版|
|`std::vector<std::vector<Edge<CostType>>> block`|`block[i]` は縮約後のグラフのブロック $i$ に含まれる辺を表す。||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit BiconnectedComponent(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- https://www.learning-algorithms.com/entry/2018/03/21/152148
- https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
- https://codeforces.com/blog/entry/14832

カクタスグラフ
- https://pekempey.hatenablog.com/entry/2017/03/28/203856


## TODO

- https://judge.yosupo.jp/problem/biconnected_components


## Submissons

https://atcoder.jp/contests/nadafes2022_day2/submissions/31595927
