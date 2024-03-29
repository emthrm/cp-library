---
title: [
  オイラー路 (Eulerian trail) 有向グラフ版,
  オイラー路 (Eulerian trail) 無向グラフ版
]
documentation_of: [
  //include/emthrm/graph/eulerian_trail_in_directed_graph.hpp,
  //include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp
]
---

## オイラー路 (Eulerian trail)

グラフのすべての辺を一度だけ通る路である。


## 準オイラーグラフ (semi-Eulerian graph)

閉路でないオイラー路が存在するグラフである。

連結グラフ $G$ が準オイラーグラフである必要十分条件は
- $G$ が無向グラフのとき、奇数次数の頂点がちょうど $2$ 個存在することであり、
- $G$ が有向グラフのとき、相対出次数 $1$、相対入次数 $1$ の頂点が一つずつ存在し、他の頂点の相対次数が $0$ であることである。


## オイラーグラフ (Eulerian graph)

オイラー閉路 (Euler circuit) が存在するグラフである。

連結グラフ $G$ がオイラーグラフである必要十分条件は
- $G$ が無向グラフのとき、任意の頂点の次数が偶数であることであり、
- $G$ が有向グラフのとき、任意の頂点の相対次数が $0$ であることである。


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

### Hierholzer's algorithm 有向グラフ版

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<Edge<CostType>> eulerian_trail_in_directed_graph(std::vector<std::vector<Edge<CostType>>> graph, int s = -1);`|有向グラフ $\mathrm{graph}$ における始点 $s$ のオイラー路。ただし存在しないときは空配列を返す。|


### Hierholzer's algorithm 無向グラフ版

```cpp
struct EulerianTrailInUndirectedGraph;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> trail`|オイラー路。ただし存在しないときは空配列となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit EulerianTrailInUndirectedGraph(const int n);`|頂点数 $N$ の無向グラフのオブジェクトを構築する。|
|`void add_edge(const int u, const int v);`|辺 $(u, v)$ を加える。|
|`bool build(int s = -1);`|始点 $s$ のオイラー路を構築できたか。|


## 参考文献

- Carl Hierholzer: Ueber die Möglichkeit, einen Linienzug ohne Wiederholung und ohne Unterbrechung zu umfahren, *Mathematische Annalen *, Vol. 6, pp. 30–32 (1873). https://doi.org/10.1007/BF01442866
- https://kokiymgch.hatenablog.com/entry/2017/12/07/193238

オイラー路 有向グラフ版
- ~~http://www.prefield.com/algorithm/graph/directed_euler_path.html~~

オイラー路 無向グラフ版
- https://github.com/spaghetti-source/algorithm/blob/2c70d7af4d132513fa699a5de5b2aaf21aaf7890/graph/eulerian_path_undirected.cc


## Submissons

- [オイラー路 有向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0225/review/4082901/emthrm/C++14)
- [オイラー路 無向グラフ版](https://yukicoder.me/submissions/701541)
