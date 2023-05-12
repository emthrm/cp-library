---
title: [
  "最小費用 $s$-$t$-フロー (minimum cost $s$-$t$-flow) 最短路反復法 (successive shortest path algorithm) 版",
  "最小費用 $\\boldsymbol{b}$-フロー (minimum cost $\\boldsymbol{b}$-flow) 最短路反復法 (successive shortest path algorithm) 版"
]
documentation_of: [
  //include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp,
  //include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
]
---

# 最小費用流 (minimum cost flow)


## 計算量

最大流の流量を $F$ とおく。

||計算量|
|:--|:--|
|最小費用 $s$-$t$-フロー 最短路反復法版|$O(\lvert V \rvert \lvert E \rvert + F \lvert E \rvert \log{\lvert V \rvert})$|
|最小費用 $\boldsymbol{b}$-フロー 最短路反復法版|コスト負の辺の容量の総和を $F^{\prime}$ とおくと $O((F + F^{\prime})\lvert E \rvert \log{\lvert V \rvert})$。|


## 仕様

### 最小費用 $s$-$t$-フロー 最短路反復法版

```cpp
template <typename T, typename U>
struct MinimumCostSTFlow;
```

- `T`：容量を表す型
- `U`：コストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const U uinf`|$\infty$|
|`std::vector<std::vector<Edge>> graph`|残余グラフ|

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit MinimumCostSTFlow(const int n, const U uinf = std::numeric_limits<U>::max());`|頂点数 $N$ のオブジェクトを構築する。||
|`void add_edge(const int src, const int dst, const T cap, const U cost);`|始点 $\mathrm{src}$、終点 $\mathrm{dst}$、容量 $\mathrm{cap}$、コスト $\mathrm{cost}$ の辺を加える。||
|`U solve(const int s, const int t, T flow);`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときの最小コスト。ただし流せないときは `uinf` を返す。|
|`U solve(const int s, const int t);`|始点 $s$ から終点 $t$ まで流量任意のフローを流すときの最小コスト|流量は $\mathrm{tinf} - \mathrm{flow}$ である。|
|`std::pair<T, U> minimum_cost_maximum_flow(const int s, const int t, const T flow);`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ 以下のフローを流すときの最小費用最大流。最大流と最小費用の組を返す。||

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
|`U cost`|流量 $1$ のフローを流すときのコスト|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Edge(const int dst, const T cap, const U cost, const int rev);`|コンストラクタ|


### 最小費用 $\boldsymbol{b}$-フロー 最短路反復法版

```cpp
template <typename T, typename U>
struct MinimumCostBFlow;
```

- `T`：容量を表す型
- `U`：コストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const U uinf`|$\infty$|
|`std::vector<std::vector<Edge>> graph`|残余グラフ|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit MinimumCostBFlow(const int n, const U uinf = std::numeric_limits<U>::max());`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(int src, int dst, const T cap, U cost);`|始点 $\mathrm{src}$、終点 $\mathrm{dst}$、容量 $\mathrm{cap}$、コスト $\mathrm{cost}$ の辺を加える。|
|`void supply_or_demand(const int ver, const T amount);`|$b_{\mathrm{ver}} \gets b_{\mathrm{ver}} + \mathrm{amount}$|
|`U solve();`|最小費用循環流。ただし流せないときは `uinf` を返す。|
|`U solve(const int s, const int t, const T flow);`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときの最小コスト。ただし流せないときは `uinf` を返す。|

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
|`U cost`|流量 $1$ のフローを流すときのコスト|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Edge(const int dst, const T cap, const U cost, const int rev);`|コンストラクタ|


## 注意

流量正の辺の合計コストの和を最小化する問題を最小費用流で解くことはできない。


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.199-205，マイナビ出版（2012）

最小費用 $s$-$t$-フロー 最短路反復法版
- Jack Edmonds, Richard M. Karp: Theoretical Improvements in Algorithmic Efficiency for Network Flow Problems, *Journal of the ACM*, Vol. 19, No. 2, pp. 248–264 (1972). https://doi.org/10.1145/321694.321699
- http://sigma425.hatenablog.com/entry/2014/10/12/122018

最小費用 $\boldsymbol{b}$-フロー 最短路反復法版
- https://snuke.hatenablog.com/entry/2017/06/07/115821


## TODO

- 容量スケーリング
  - https://misawa.github.io/others/flow/lets_use_capacity_scaling.html
- 最小費用 $\boldsymbol{b}$-フロー
  - https://misawa.github.io/others/flow/library_design.html
  - https://twitter.com/Mi_Sawa/status/1283768916775321601
  - https://noshi91.hatenablog.com/entry/2021/12/15/012019
  - https://judge.yosupo.jp/problem/min_cost_b_flow
- グラフにコスト負の閉路が存在するとき


## Submissons

- 最小費用 $s$-$t$-フロー 最短路反復法版
  - [`solve(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_6_B/review/4092721/emthrm/C++14)
  - [`solve(s, t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2293/review/4085999/emthrm/C++14)
  - [`minimum_cost_maximum_flow(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1088/review/4086009/emthrm/C++14)
- [最小費用 $\boldsymbol{b}$-フロー 最短路反復法版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14)
