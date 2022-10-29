# 歩道 (walk) の検出


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- 道 (path) の検出

||説明|備考|
|:--:|:--:|:--:|
|`detect_path(graph, s, t)`|有向グラフ $\mathrm{graph}$ における始点 $s$，終点 $t$ の道|存在しないときは空配列となる．|

- 有向閉路 (directed cycle) の検出

||説明|備考|
|:--:|:--:|:--:|
|`detect_directed_cycle(graph)`|有向グラフ $\mathrm{graph}$ における閉路|存在しないときは空配列となる．|


## 参考

有向閉路の検出
- https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-6-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA


## ToDo

- 無向閉路の検出
  - https://judge.yosupo.jp/problem/cycle_detection_undirected
- 閉路の列挙
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/cycle_enumeration.cc


## Verified

- [道の検出](https://atcoder.jp/contests/past202112-open/submissions/29621513)
- [有向閉路の検出](https://judge.yosupo.jp/submission/15525)
