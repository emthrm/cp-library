# 木の直径

木の最遠頂点間の距離である．


## 時間計算量

$O(\lvert V \rvert)$


## 使用法

- double sweep

||説明|備考|
|:--:|:--:|:--:|
|`DoubleSweep(graph)`|グラフ $\mathrm{graph}$ の木の直径を構築する．||
|(`s`, `t`)|最遠頂点対||
|`diameter`|木の直径の長さ||
|`path`|直径|`build_path()` を呼び出しておかなければならない．|

- 全方位木 DP 版

||説明|
|:--:|:--:|
|`rerooting(graph)`|グラフ $\mathrm{graph}$ の木の直径の長さ||


## 参考

double sweep
- http://www.prefield.com/algorithm/graph/tree_diameter.html

全方位木 DP 版
- https://ei1333.hateblo.jp/entry/2017/04/10/224413


## ToDo

- 頂点の重みを基にした直径
  - https://github.com/beet-aizu/library/blob/master/tree/diameterforvertex.cpp
- 全方位木 DP の考え方
  - https://twitter.com/snuke_/status/1018052021985792000
- 全方位木 DP の抽象化
  - https://ei1333.hateblo.jp/entry/2018/12/21/004022


## Verified

* [double sweep](https://codeforces.com/contest/1182/submission/67997368)
* [全方位木 DP 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_A/review/4083771/emthrm/C++14)
