# 歩道 (walk) の検出


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

### 道 (path) の検出

|名前|戻り値|
|:--|:--|
|`template <typename CostType> std::vector<Edge<CostType>> detect_path(const std::vector<std::vector<Edge<CostType>>>& graph, const int s, const int t);`|有向グラフ $\mathrm{graph}$ における始点 $s$、終点 $t$ の道。ただし存在しないときは空配列を返す。|


### 有向閉路 (directed cycle) の検出

|名前|戻り値|
|:--|:--|
|`template <typename CostType> std::vector<Edge<CostType>> detect_directed_cycle(const std::vector<std::vector<Edge<CostType>>>& graph);`|有向グラフ $\mathrm{graph}$ における閉路。ただし存在しないときは空配列を返す。|


## 参考文献

有向閉路の検出
- https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-6-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA


## TODO

- 無向閉路の検出
  - https://judge.yosupo.jp/problem/cycle_detection_undirected
- 閉路の列挙
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/cycle_enumeration.cc


## Submissons

- [道の検出](https://atcoder.jp/contests/past202112-open/submissions/29621513)
- [有向閉路の検出](https://judge.yosupo.jp/submission/15525)
