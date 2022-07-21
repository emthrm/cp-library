# 単一始点最短路問題 (single-source shortest path problem)

始点から他の任意の頂点までの最短路を求める問題である．


## 時間計算量

|アルゴリズム|時間計算量|
|:--:|:--:|
|Bellman–Ford 法|$O(\lvert V \rvert \lvert E \rvert)$|
|Dijkstra 法|$O(\lvert E \rvert \log{\lvert V \rvert})$|


## 使用法

- Bellman–Ford 法

||説明|備考|
|:--:|:--:|:--:|
|`BellmanFord<CostType>(graph, ∞)`|グラフ $\mathrm{graph}$ の単一始点最短路を考える．||
|`inf`|$\infty$||
|`dist[ver]`|始点から頂点 $\mathrm{ver}$ までの最短距離|到達できなければ $\infty$ となる．|
|`has_negative_cycle(s)`|始点 $s$ の単一始点最短路を構築する．|返り値はグラフが負の閉路をもつか．|
|`build_path(t)`|終点 $t$ の最短路|到達できなければ空配列となる．|

- Dijkstra 法

||説明|備考|
|:--:|:--:|:--:|
|`Dijkstra<CostType>(graph, ∞)`|グラフ $\mathrm{graph}$ の単一始点最短路を考える．||
|`inf`|$\infty$||
|`build(s)`|始点 $s$ の単一始点最短路|到達できなければ $\infty$ となる．|
|`build_path(t)`|終点 $t$ の最短路|到達できならば空配列となる．|


## 参考

Bellman–Ford 法
- http://www.prefield.com/algorithm/graph/bellman_ford.html

Dijkstra 法
- https://github.com/spaghetti-source/algorithm/blob/af9a22a92953e903c474e98e79107103adbd0a53/graph/dijkstra.cc


## ToDo

- shortest path faster algorithm
  - https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
  - https://dic.kimiyuki.net/spfa
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
  - https://dic.kimiyuki.net/yen-algorithm
  - http://inarizuuuushi.hatenablog.com/entry/2018/08/30/222605
  - https://yukicoder.me/problems/no/1069
- k shortest walk (Eppstein's algorithm)
  - https://en.wikipedia.org/wiki/K_shortest_path_routing#Variations
  - https://dic.kimiyuki.net/eppstein-algorithm
  - https://qiita.com/hotman78/items/42534a01c4bd05ed5e1e
  - https://qiita.com/nariaki3551/items/0ab83541814f98eab322
  - http://www.prefield.com/algorithm/graph/k_shortest_paths.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/k_shortest_walks.cc
  - https://judge.yosupo.jp/problem/k_shortest_walk
- $O(\sqrt{N}M\log{C})$
  - https://misawa.github.io/others/flow/cost_scaling_shortest_path.html
- Dial's algorithm
  - https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Specialized_variants
  - https://dic.kimiyuki.net/dial
  - http://bin.t.u-tokyo.ac.jp/startup16/file/6-1.pdf
  - https://tjkendev.github.io/procon-library/python/graph/dial.html
- shortest non-zero path in group-labeled graphs
  - https://ygussany.hatenablog.com/entry/2019/12/04/000000
  - https://gist.github.com/wata-orz/d3037bd0b919c76dd9ddc0379e1e3192
  - https://yukicoder.me/problems/no/1602


## Verified

- [Bellman–Ford 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_1_B/review/4082583/emthrm/C++14)
- [Dijkstra 法](https://judge.yosupo.jp/submission/8211)
