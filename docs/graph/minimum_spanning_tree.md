# 最小全域木 (minimum spanning tree)


## 時間計算量

$O(\lvert E \rvert \log{\lvert V \rvert})$


## 使用法

- Prim 法

||説明|備考|
|:--:|:--:|:--:|
|`prim(graph, root = 0)`|根を $\mathrm{root}$ とするグラフ $\mathrm{graph}$ の最小全域木のコスト|$\mathrm{graph}$ には双方向の辺の情報が必要である．|

- Kruskal 法

||説明|備考|
|:--:|:--:|:--:|
|`kruskal(graph)`|グラフ $\mathrm{graph}$ の最小全域木のコスト|$\mathrm{graph}$ には単方向の辺の情報のみでよい．|


## 参考

Prim 法
- http://www.prefield.com/algorithm/graph/prim.html

Kruskal 法
- https://github.com/spaghetti-source/algorithm/blob/64d34fb9b940a3e933cf36c4dd26b7457b42f50b/graph/kruskal.cc


## ToDo

- https://www.slideshare.net/tmaehara/ss-17402143
- https://twitter.com/noshi91/status/1482583425421029376
- ブルーフカ法 (Borůvka's algorithm)
  - https://ja.wikipedia.org/wiki/%E3%83%96%E3%83%AB%E3%83%BC%E3%83%95%E3%82%AB%E6%B3%95
  - http://spinda2.blog48.fc2.com/blog-entry-560.html
  - https://inzkyk.github.io/algorithms/minimum_spanning_trees/boruvka_algorithms/
  - https://twitter.com/yamerarenaku/status/1166349080022462465
  - https://ei1333.github.io/luzhiled/snippets/graph/boruvka.html
  - https://lumakernel.github.io/ecasdqina/graph/boruvka
- Fibonacchi heap を用いた Prim 法の高速化
  - https://github.com/ei1333/library/blob/master/graph/prim-fibonacchi-heap.cpp
- Euclidean minimum spanning tree
  - https://en.wikipedia.org/wiki/Euclidean_minimum_spanning_tree
  - https://www.slideshare.net/maroonrk/ss-65378126
  - http://tokoharuland.hateblo.jp/entry/2018/04/01/155743
  - https://github.com/beet-aizu/library/blob/master/graph/voronoiminimumspanningtree.cpp
- 最小シュタイナー木
  - https://ja.wikipedia.org/wiki/%E3%82%B7%E3%83%A5%E3%82%BF%E3%82%A4%E3%83%8A%E3%83%BC%E6%9C%A8
  - https://www.slideshare.net/wata_orz/ss-12131479
  - http://www.prefield.com/algorithm/dp/steiner_tree.html
  - http://monyone.github.io/teihen_library/#MinimumSteinerTree
  - https://sotanishy.github.io/cp-library-cpp/graph/minimum_steiner_tree.hpp
- 最小全域有向木
  - https://37zigen.com/gabow-galil-spencer-tarjan/
  - https://dic.kimiyuki.net/chu-liu-edmonds
  - http://joisino.hatenablog.com/entry/2017/01/11/230141
  - https://ark4rk.hatenablog.com/entry/2017/09/15/011937
  - https://twitter.com/nuo_chocorusk/status/1187055311422574593
  - https://twitter.com/yamerarenaku/status/1187065174529691648
  - https://ei1333.github.io/algorithm/chu-liu-edmond.html
  - https://ei1333.github.io/luzhiled/snippets/graph/chu-liu-edmond.html
  - https://github.com/beet-aizu/library/blob/master/graph/arborescence_edmond.cpp
  - https://github.com/beet-aizu/library/blob/master/graph/arborescence_tarjan.cpp
  - https://lumakernel.github.io/ecasdqina/graph/MinimumSpanningArborescence
  - http://www.prefield.com/algorithm/graph/chu_liu_edmonds.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence.cc
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence2.cc
  - https://github.com/primenumber/ProconLib/blob/master/Graph/MinimumArborescence.cpp
  - https://gist.github.com/tjkendev/231897301fde67d4a81f51c3f0873936
  - https://sotanishy.github.io/cp-library-cpp/graph/minimum_spanning_arborescence.cpp
  - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B
  - https://judge.yosupo.jp/problem/directedmst
- minimum diameter spanning tree
  - http://www.prefield.com/algorithm/graph/minimum_diameter_spanning_tree.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/kariv_hakimi.cc


## Verified

- [Prim 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_2_A/review/4083632/emthrm/C++14)
- [Kruskal 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_2_A/review/4083639/emthrm/C++14)
