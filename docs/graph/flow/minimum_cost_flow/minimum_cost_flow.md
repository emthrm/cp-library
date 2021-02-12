# 最小費用流 (minimum cost flow)

ある始点からある終点まで特定量のフローを流すためにかかるコストの最小値である．

- 主双対法 (primal-dual method)


## 計算量

最大流の流量を $F$ とおく．

||計算量|
|:--:|:--:|
|主双対法|$O(\lvert V \rvert \lvert E \rvert + F \lvert E \rvert \log{\lvert V \rvert})$|
|主双対法2|コスト負の辺の容量の総和を $F^{\prime}$ とおくと $O((F + F^{\prime})\lvert E \rvert \log{\lvert V \rvert})$．|


## 使用法

- 主双対法

||説明|備考|
|:--:|:--:|:--:|
|`PrimalDual<フロー, コスト>(n, ∞)`|頂点数 $N$ の主双対法を考える．||
|`uinf`|$\infty$|型はコストと等しい．|
|`graph`|残余グラフ||
|`add_edge(src, dst, cap, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$, コスト $\mathrm{cost}$ の辺を張る．||
|`minimum_cost_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値|流せない場合は $\infty$ となる．|
|`minimum_cost_flow(s, t)`|始点 $s$ から終点 $t$ まで流量任意のフローを流すときのコストの最小値|流量は $\mathrm{tinf} - \mathrm{tmp}$ である．|
|`min_cost_max_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流したいときの最小費用最大流 (最大流, 最小費用)||

- 主双対法2

||説明|備考|
|:--:|:--:|:--:|
|`PrimalDual2<フロー, コスト>(n, ∞)`|頂点数 $N$ の主双対法2を考える．||
|`uinf`|$\infty$|型はコストと等しい．|
|`graph`|残余グラフ||
|`add_edge(src, dst, cap, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量 $\mathrm{cap}$, コスト $\mathrm{cost}$ の辺を張る．||
|`minimum_cost_flow()`|最小費用循環流|流せない場合は $\infty$ となる．|
|`minimum_cost_flow(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値|流せない場合は $\infty$ となる．|


## 注意

流量正の辺の合計コストの和を最小化する問題を最小費用流で解くことはできない．


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.199-205

主双対法
- http://sigma425.hatenablog.com/entry/2014/10/12/122018

主双対法2
- https://snuke.hatenablog.com/entry/2017/06/07/115821


## ToDo

- グラフにコスト負の閉路が存在する場合
- 容量スケーリング
  - https://misawa.github.io/others/flow/lets_use_capacity_scaling.html
- 最小費用 $b$-フロー
  - https://misawa.github.io/others/flow/library_design.html
  - https://twitter.com/Mi_Sawa/status/1283768916775321601
  - https://judge.yosupo.jp/problem/min_cost_b_flow


## Verified

- 主双対法
  - [`minimum_cost_flow(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_6_B/review/4092721/emthrm/C++14)
  - [`minimum_cost_flow(s, t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2293/review/4085999/emthrm/C++14)
  - [`min_cost_max_flow(s, t, flow)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1088/review/4086009/emthrm/C++14)
- [主双対法2](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14)
