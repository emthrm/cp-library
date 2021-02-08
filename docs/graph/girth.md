# 内周 (girth)

グラフにおける最小閉路長である．


## 時間計算量

$O(\lvert V \rvert (\lvert V \rvert + \lvert E \rvert) \log{\lvert V \rvert})$


## 使用法

- 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`girth_in_directed_graph(graph, ∞)`|有向グラフ $\mathrm{graph}$ の内周|辺の重みは自然数でなければならない．<br>存在しない場合は $\infty$ となる．|

- 無向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`girth_in_undirected_graph(n, edges, ∞)`|頂点数 $n$，辺集合 $\mathrm{edges}$ である無向グラフの内周|辺の重みは自然数でなければならない．<br>存在しない場合は $\infty$ となる．|


## 参考

- https://yukicoder.me/problems/no/1320/editorial
- https://algo-logic.info/minimum-weight-cycle/


## Verified

https://yukicoder.me/submissions/595363
