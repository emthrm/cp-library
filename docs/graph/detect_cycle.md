# 閉路の検出


## 時間計算量

有向グラフ版 $O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`detect_directed_cycle(graph)`|有向グラフ $\mathrm{graph}$ の閉路|存在しない場合は空配列となる．|


## 参考

有向グラフ版
- https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-6-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA


## ToDo

- 閉路の列挙
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/cycle_enumeration.cc


## Verified

- [有向グラフ版](https://judge.yosupo.jp/submission/15525)
