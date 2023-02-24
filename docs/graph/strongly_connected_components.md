---
title: 強連結成分 (strongly connected components) 分解
documentation_of: //include/emthrm/graph/strongly_connected_components.hpp
---

有向グラフを共通部分の存在しない強連結成分に分解することである。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

### Kosaraju's algorithm

```cpp
template <typename CostType, bool IS_FULL_VER = false>
struct StronglyConnectedComponents;
```

- `CostType`：辺のコストを表す型
- `IS_FULL_VER`：完全版かを表す型

#### メンバ変数

|名前|説明|要件|
|:--|:--|:--|
|`std::vector<int> id`|`id[i]` は元のグラフの頂点 $i$ を含む頂点を表す。||
|`std::vector<std::vector<int>> vertices`|`vertices[i]` は縮約後のグラフの頂点 $i$ に含まれる頂点を表す。|完全版|
|`std::vector<std::vector<Edge<CostType>>> g`|強連結成分を一つの頂点に縮約したグラフ||

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit StronglyConnectedComponents(const std::vector<std::vector<Edge<CostType>>>& graph);`|有向グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 備考

無向グラフの辺に向きをつけることで強連結成分分解できる $\Leftrightarrow$ グラフが2辺連結である

構築方法としては深さ優先探索木で後退辺を逆辺とすればよい。


## 参考文献

Kosaraju's algorithm
- https://github.com/beet-aizu/library/blob/346558ee0881bd18b10c0d32d7678b033d6b0326/graph/stronglyconnectedcomponent.cpp

備考
- https://twitter.com/noshi91/status/1172798654450520064


## TODO

- Tarjan's algorithm
  - http://www.prefield.com/algorithm/graph/strongly_connected_components.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/strongly_connected_component_tarjan.cc
  - https://tubo28.me/compprog/algorithm/tarjan-scc/
- Gabow's algorithm
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/strongly_connected_component_gabow.cc


## Submissons

- [Kosaraju's algorithm](https://judge.yosupo.jp/submission/4441)
