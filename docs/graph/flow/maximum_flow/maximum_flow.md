---
title: [
  Ford–Fulkerson 法,
  Dinic 法
]
documentation_of: [
  //include/emthrm/graph/flow/maximum_flow/ford-fulkerson.hpp,
  //include/emthrm/graph/flow/maximum_flow/dinic.hpp
]
---

# 最大流 (maximum flow)

ある始点からある終点までのフローの最大値である。

最大フロー最小カット定理より最小カットと一致する。


## 時間計算量

|アルゴリズム|時間計算量|
|:--|:--|
|Ford–Fulkerson 法|最大流を $F$ とおくと $O(F \lvert E \rvert)$|
|Dinic 法|最大流を $F$ とおくと $O\left(\min \left\lbrace {\lvert V \rvert}^2 \lvert E \rvert,\ F \lvert E \rvert,\ {\lvert E \rvert}^{3/2} \max_{e \in E} C_e,\ \sqrt{\lvert V \rvert} \lvert E \rvert \max_{v \in V} \min \left\lbrace \sum_{e \in \delta^-(v) \subset E} C_e, \sum_{e \in \delta^+(v) \subset E} C_e \right\rbrace \right\rbrace\right)$|


## 仕様

### Ford–Fulkerson 法

```cpp
template <typename T>
struct FordFulkerson;
```

- `T`：容量を表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<std::vector<Edge>> graph`|残余グラフ|

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit FordFulkerson(const int n);`|頂点数 $N$ のオブジェクトを構築する。||
|`void add_edge(const int src, const int dst, const T cap);`|容量 $\mathrm{cap}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を追加する。||
|`T maximum_flow(const int s, const int t, T limit = std::numeric_limits<T>::max());`|上限を $\mathrm{limit}$ とした始点 $s$ から終点 $t$ までの最大流|容量が整数でなければ、停止しないときがある。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Edge`|辺を表す構造体|

```cpp
struct Edge;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`int dst`|終点|
|`int rev`|頂点 $\mathrm{dst}$ における逆辺のインデックス|
|`T cap`|残りの容量|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Edge(const int dst, const T cap, const int rev);`|コンストラクタ|


### Dinic 法

```cpp
template <typename T>
struct Dinic;
```

- `T`：容量を表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<std::vector<Edge>> graph`|残余グラフ|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit Dinic(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const T cap);`|容量 $\mathrm{cap}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を追加する。|
|`T maximum_flow(const int s, const int t, T limit = std::numeric_limits<T>::max());`|上限を $\mathrm{limit}$ とした始点 $s$ から終点 $t$ までの最大流|

#### メンバ型

|名前|説明|
|:--|:--|
|`Edge`|辺を表す構造体|

```cpp
struct Edge;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`int dst`|終点|
|`int rev`|頂点 $\mathrm{dst}$ における逆辺のインデックス|
|`T cap`|残りの容量|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Edge(const int dst, const T cap, const int rev);`|コンストラクタ|


## 特殊ケース

- 複数の source や sink が存在する。

  新たな始点や終点を用意する。その始点から各 source に流出量と等しい容量をもつ辺を、各 sink からその終点に流入量と等しい容量をもつ辺を追加すればよい。

- 無向グラフ

  両方向に同容量の有向辺を追加すればよい。または逆辺に等しい容量をもたせればよい?

- 頂点にも容量が存在する。

  頂点を入頂点と出頂点に分割する。入ってくる辺を入頂点、出ていく辺を出頂点につなぎ直し、入頂点から出頂点に頂点の容量と同容量の辺を追加すればよい。

- 辺の容量を増やす。

  残余グラフに対して、容量を増やした後に再び最大流を求め、元の答えに加えればよい。

- 辺 $e = (u, v)$ の容量を $c$ だけ減らす。

  - $e.\mathrm{cap} \geq c$ のとき

    $e.\mathrm{cap} \gets e.\mathrm{cap} - c$ とすればよい。

  - $e.\mathrm{cap} < c$ のとき

    $c \gets c - e.\mathrm{cap},\ e.\mathrm{cap} \gets 0$ とする。残余グラフにおける $u$ から $v$ までの最大流を $c^{\prime}$ とおく。

    - $c^{\prime} \geq c$ のとき

      $u$ から $v$ まで $c$ だけ流せばよい。

    - $c^{\prime} < c$ のとき

      $u$ から $v$ まで $c^{\prime}$ だけ流す。終点から $v$ まで、そして $u$ から始点まで $c - c^{\prime}$ 押し戻す必要があり、最大流は $c - c^{\prime}$ 減る。


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.188-195，マイナビ出版（2012）
- https://twitter.com/kotatsugame_t/status/1192092085479858176

Ford–Fulkerson 法
- L. R. Ford Jr. and D. R. Fulkerson: Maximal Flow Through a Network, *Canadian Journal of Mathematics*, Vol. 8, pp. 399–404 (1956). https://doi.org/10.4153/CJM-1956-045-5
- https://ei1333.github.io/luzhiled/snippets/graph/ford-fulkerson.html

Dinic 法
- Yefim Dinitz: Algorithm for Solution of a Problem of Maximum Flow in a Network with Power Estimation, *Soviet Math Doklady*, Vol. 11, pp. 1277–1280 (1970).
- https://misawa.github.io/others/flow/dinic_time_complexity.html


## TODO

- エドモンズ・カープのアルゴリズム (Edmonds–Karp algorithm)
  - https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%89%E3%83%A2%E3%83%B3%E3%82%BA%E3%83%BB%E3%82%AB%E3%83%BC%E3%83%97%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
  - ~~http://www.prefield.com/algorithm/graph/edmonds_karp.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximum_flow_edmonds_karp.cc
  - https://inzkyk.github.io/algorithms/maximum_flows_minimum_cuts/edmonds_and_karps_algorithms/
- 容量スケーリング版 Dinic 法
  - https://kopricky.github.io/code/NetworkFlow/dinic.html
  - https://github.com/ei1333/library/blob/master/graph/dinic-capacity-scaling.cpp
- push-relabel algorithm
  - https://kenkoooo.hatenablog.com/entry/2016/12/22/143638
  - https://ei1333.github.io/luzhiled/snippets/graph/push-relabel.html
  - ~~http://www.prefield.com/algorithm/graph/goldberg_tarjan.html~~
  - https://tubo28.me/compprog/algorithm/edmonds-kerp/
  - https://qiita.com/a-lilas/items/3bf338c7929f6951fa41
  - https://qiita.com/nariaki3551/items/65baee3c6ef0a6ffa136
  - https://kopricky.github.io/code/Academic/max_flow_push_relabel.html
  - https://tjkendev.github.io/procon-library/cpp/max_flow/push-relabel-highest.html
- 動的木を用いた Dinic 法
  - https://misawa.github.io/others/flow/dinic_time_complexity.html
- 全域最小カット
  - ~~http://www.prefield.com/algorithm/graph/minimum_cut.html~~
  - https://github.com/primenumber/ProconLib/blob/master/Graph/GlobalMinimumCut.cpp
  - http://monyone.github.io/teihen_library/#MinimumCutStoerWagner
  - https://www.slideshare.net/hcpc_hokudai/flow-cut
  - https://judge.yosupo.jp/problem/global_minimum_cut_of_dynamic_star_augmented_graph
- 最大カット
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximum_cut.cc
- 二部グラフの場合の計算量
  - https://twitter.com/Mi_Sawa/status/1391968412184682498


## Submissons

- [Ford–Fulkerson 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_6_A/review/4085135/emthrm/C++14)
- [Dinic 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1615/review/4085139/emthrm/C++14)
