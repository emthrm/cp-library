---
title: Warshall–Floyd 法
documentation_of: include/emthrm/graph/shortest_path/warshall-floyd.hpp
---

任意の2頂点間の最短路を求める全点対最短路問題を解けるアルゴリズムである。


## 時間計算量

$O({\lvert V \rvert}^3)$


## 仕様

```cpp
template <typename T>
struct WarshallFloyd;
```

- `T`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<std::vector<T>> graph`|`graph[s][t]` は始点 $s$, 終点 $t$ を結ぶ辺の最小コストを表す。ただし辺が存在しないときは $\infty$ となる。|
|`std::vector<std::vector<T>> dist`|`dist[s][t]` は始点 $s$ から終点 $t$ までの最短距離を表す。ただし到達できないときは $\infty$ となる。|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`WarshallFloyd(const std::vector<std::vector<T>>& graph, const T inf);`|隣接行列 $\mathrm{graph}$ に対してオブジェクトを構築する。|隣接行列は $\infty$ で初期化している。|
|`void add(const int src, const int dst, const T cost);`|重み $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ をグラフに加える。||
|`void calc();`|辺をグラフに追加した後、全点対最短路を構築する。||
|`bool has_negative_cycle() const;`|グラフが負の閉路をもつか。||
|`std::vector<int> build_path(const int s, const int t) const;`|始点 $s$ から終点 $t$ までの最短路。ただし到達できないときは空配列を返す。||


## 参考文献

- http://www.prefield.com/algorithm/graph/floyd_warshall.html
- https://ei1333.github.io/luzhiled/snippets/graph/warshall-floyd.html


## TODO

- Johnson's algorithm
  - http://www.prefield.com/algorithm/graph/johnson.html
  - https://inzkyk.github.io/algorithms/all_pairs_shortest_paths/johnsons_algorithm/


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0526/review/4082670/emthrm/C++14
