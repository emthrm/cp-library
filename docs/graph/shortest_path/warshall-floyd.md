---
title: Warshall-Floyd 法
documentation_of: graph/shortest_path/warshall-floyd.hpp
---

任意の2頂点間の最短路を求める全点対最短路問題を解けるアルゴリズムである．


## 時間計算量

$O({\lvert V \rvert}^3)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`WarshallFloyd<T>(graph, ∞)`|グラフ $\mathrm{graph}$ の全点対最短路を考える．|隣接行列は $\infty$ で初期化しておかなければならない．|
|`graph[s][t]`|始点 $s$, 終点 $t$ を結ぶ辺の最小コスト|存在しなければ $\infty$ となる．|
|`dist[s][t]`|始点 $s$ から終点 $t$ までの最短距離|到達できなければ $\infty$ となる．|
|`add(src, dst, cost)`|始点 $\mathrm{src}$，終点 $\mathrm{dst}$，重み $\mathrm{cost}$ の辺をグラフに加える．|
|`calc()`|辺をグラフに追加した後, 全点対最短路を構築する．||
|`has_negative_cycle()`|グラフが負の閉路をもつか．||
|`build_path(s, t)`|始点 $s$ から終点 $t$ までの最短路||


## 参考

- http://www.prefield.com/algorithm/graph/floyd_warshall.html
- https://ei1333.github.io/luzhiled/snippets/graph/warshall-floyd.html


## ToDo

- Johnson's algorithm
  - http://www.prefield.com/algorithm/graph/johnson.html
  - https://inzkyk.github.io/algorithms/all_pairs_shortest_paths/johnsons_algorithm/


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0526/review/4082670/emthrm/C++14
