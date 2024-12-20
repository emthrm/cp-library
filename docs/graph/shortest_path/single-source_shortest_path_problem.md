---
title: [
  Bellman–Ford 法,
  Dijkstra 法
]
documentation_of: [
  //include/emthrm/graph/shortest_path/bellman-ford.hpp,
  //include/emthrm/graph/shortest_path/dijkstra.hpp
]
---

# 単一始点最短路問題 (single-source shortest path problem)

始点から他の任意の頂点までの最短路を求める問題である。


## 時間計算量

|アルゴリズム|時間計算量|
|:--|:--|
|Bellman–Ford 法|$O(\lvert V \rvert \lvert E \rvert)$|
|Dijkstra 法|$O(\lvert E \rvert \log{\lvert V \rvert})$|


## 仕様

### Bellman–Ford 法

```cpp
template <typename CostType>
struct BellmanFord;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const CostType inf`|$\infty$|
|`std::vector<CostType> dist`|`dist[ver]` は始点から頂点 $\mathrm{ver}$ までの最短距離を表す。ただし到達できないときは $\infty$ となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`BellmanFord(const std::vector<std::vector<Edge<CostType>>>& graph, const CostType inf = std::numeric_limits<CostType>::max());`|グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`bool has_negative_cycle(const int s);`|始点 $s$ の単一始点最短路を構築し、グラフが負の閉路をもつかを返す。|
|`std::vector<int> build_path(int t) const;`|終点 $t$ の最短路。ただし到達できないときは空配列を返す。|


### Dijkstra 法

```cpp
template <typename CostType>
struct Dijkstra
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const CostType inf`|$\infty$|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`Dijkstra(const std::vector<std::vector<Edge<CostType>>>& graph, const CostType inf = std::numeric_limits<CostType>::max());`|グラフ $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`std::vector<CostType> build(const int s);`|始点 $s$ の単一始点最短路。ただし到達できない頂点には $\infty$ を格納する。|
|`std::vector<int> build_path(int t) const;`|終点 $t$ の最短路。ただし到達できないときは空配列を返す。|


## 参考文献

Bellman–Ford 法
- Richard Bellman: On a routing problem, *Quarterly of Applied Mathematics*, Vol. 16, pp. 87–90 (1958). https://doi.org/10.1090/qam/102435
- L. R. Ford Jr. and D. R. Fulkerson: Flows in Networks, Princeton University Press (1962).
- ~~http://www.prefield.com/algorithm/graph/bellman_ford.html~~

Dijkstra 法
- Edsger W. Dijkstra: A note on two problems in connexion with graphs, *Numerische Mathematik*, Vol. 1, pp. 269–271 (1959). https://doi.org/10.1007/BF01386390
- https://github.com/spaghetti-source/algorithm/blob/af9a22a92953e903c474e98e79107103adbd0a53/graph/dijkstra.cc


## TODO

- shortest path faster algorithm
  - https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
  - https://noshi91.github.io/algorithm-encyclopedia/spfa
  - http://hogloid.hatenablog.com/entry/20120409/1333973448
  - https://ei1333.github.io/algorithm/shortest-path-faster-algorithm.html
  - https://ei1333.github.io/luzhiled/snippets/graph/shortest-path-faster-algorithm.html
  - https://tubo28.me/compprog/algorithm/spfa/
  - https://tjkendev.github.io/procon-library/python/graph/spfa.html
  - https://hamukichi.hatenablog.jp/entry/2016/03/03/191304
- Dijkstra 法の高速化
  - https://www.slideshare.net/yosupo/ss-46612984
  - skew heap
    - https://github.com/primenumber/ProconLib/blob/master/Structure/SkewHeapDijkstra.cpps
  - Fibonacchi heap
    - https://github.com/ei1333/library/blob/master/graph/dijkstra-fibonacchi-heap.cpp
  - radix heap
    - https://github.com/ei1333/library/blob/master/graph/dijkstra-radix-heap.cpp
- 双方向 Dijkstra
  - http://tatanaideyo.hatenablog.com/entry/2015/11/01/031713
  - https://tubo28.me/compprog/algorithm/bidirectional-dijkstra/
  - https://togetter.com/li/893481
- k shortest path routing (Yen's algorithm)
  - https://en.wikipedia.org/wiki/K_shortest_path_routing
  - https://en.wikipedia.org/wiki/Yen%27s_algorithm
  - https://noshi91.github.io/algorithm-encyclopedia/yen-algorithm
  - http://inarizuuuushi.hatenablog.com/entry/2018/08/30/222605
  - https://frosted-english-119.notion.site/Undirected-K-Shortest-Paths-86a6c9a076d942c9b6e1058859ccf566
  - https://mugen1337.github.io/procon/Graph2/Yen.hpp
  - 問題例「[電柱 / Pole (Hard)](https://yukicoder.me/problems/no/1069)」
- k shortest walk (Eppstein's algorithm)
  - https://en.wikipedia.org/wiki/K_shortest_path_routing#Variations
  - https://noshi91.github.io/algorithm-encyclopedia/eppstein-algorithm
  - https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e
  - https://qiita.com/nariaki3551/items/0ab83541814f98eab322
  - ~~http://www.prefield.com/algorithm/graph/k_shortest_paths.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/k_shortest_walks.cc
  - https://mugen1337.github.io/procon/Graph2/Eppstein.cpp
  - https://judge.yosupo.jp/problem/k_shortest_walk
- $O(\sqrt{N}M\log{C})$
  - https://misawa.github.io/others/flow/cost_scaling_shortest_path.html
- Dial's algorithm
  - https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Specialized_variants
  - https://noshi91.github.io/algorithm-encyclopedia/dial
  - http://bin.t.u-tokyo.ac.jp/startup16/file/6-1.pdf
  - https://tjkendev.github.io/procon-library/python/graph/dial.html
- shortest non-zero path in group-labeled graphs
  - https://ygussany.hatenablog.com/entry/2019/12/04/000000
  - https://gist.github.com/wata-orz/d3037bd0b919c76dd9ddc0379e1e3192
  - 問題例 "[With Animals into Institute 2](https://yukicoder.me/problems/no/1602)"


## Submissons

- [Bellman–Ford 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_1_B/review/4082583/emthrm/C++14)
- [Dijkstra 法](https://judge.yosupo.jp/submission/8211)
