## オイラー路 (Eulerian trail)

グラフのすべての辺を一度だけ通る路である．


## 準オイラーグラフ (semi-Eulerian graph)

閉路でないオイラー路が存在するグラフである．

$$\text{準オイラーグラフ} \Leftrightarrow \begin{cases} \text{次数奇数の頂点がちょうど 2 個存在} & (\text{無向グラフ}) \\ \text{始点の相対出次数が 1, 終点の相対入次数が 1, 他の頂点の相対次数が 0} & (\text{有向グラフ}) \text{．} \end{cases}$$


## オイラーグラフ (Eulerian graph)

オイラー閉路 (Euler circuit) が存在するグラフである．

$$\text{オイラーグラフ} \Leftrightarrow \begin{cases} \text{任意の頂点の次数が偶数} & (\text{無向グラフ}) \\ \text{任意の頂点の相対次数が 0} & (\text{有向グラフ}) \text{．} \end{cases}$$


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- オイラー路 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`eulerian_trail_in_directed_graph(graph, s = -1)`|有向グラフ $\mathrm{graph}$，始点 $s$ のオイラー路|存在しない場合は空配列となる．|

- オイラー路 無向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`EulerianTrailInUndirectedGraph(n)`|頂点数 $N$ の無向グラフにおけるオイラー路||
|`trail`|オイラー路|存在しない場合は空配列となる．|
|`add_edge(u, v)`|辺 $(u, v)$ を追加する．||
|`build(s = -1)`|始点 $s$ のオイラー路を構築できたか．|一度のみ．|


## 参考

- https://www.learning-algorithms.com/entry/2017/12/07/193238

オイラー路 有向グラフ版
- http://www.prefield.com/algorithm/graph/directed_euler_path.html

オイラー路 無向グラフ版
- https://github.com/spaghetti-source/algorithm/blob/2c70d7af4d132513fa699a5de5b2aaf21aaf7890/graph/eulerian_path_undirected.cc


## Verified

- [オイラー路 有向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0225/review/4082901/emthrm/C++14)
- [オイラー路 無向グラフ版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0086/review/4579202/emthrm/C++14)
