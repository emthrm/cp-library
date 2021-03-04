---
title: 彩色数 (chromatic number)
documentation_of: graph/chromatic_number.hpp
---

隣接するもの同士で同じ色にならないよう頂点を彩色するために必要な最小の色数である．


## 時間計算量

$O(2^{\lvert V \rvert} \lvert V \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`chromatic_number(graph)`|無向グラフ $\mathrm{graph}$ の彩色数|


## 参考

- https://www.slideshare.net/wata_orz/ss-12131479
- http://drken1215.hatenablog.com/entry/2019/01/16/030000
- https://www.learning-algorithms.com/entry/2018/01/27/235959
- https://github.com/spaghetti-source/algorithm/blob/master/graph/chromatic_number.cc


## ToDo

- 二部グラフの辺彩色
  - https://ei1333.hateblo.jp/entry/2020/08/25/015955
  - https://37zigen.com/noga-alon-edge-coloring-bipartite/
  - https://github.com/yosupo06/library-checker-problems/issues/393
  - https://twitter.com/snuke_/status/1246630370415538176
  - https://twitter.com/noshi91/status/1247010856040165377
  - https://github.com/ei1333/library/blob/master/structure/union-find/bipartite-graph.cpp
  - http://www.prefield.com/algorithm/graph/bipartite_coloring.html
  - https://judge.yosupo.jp/problem/bipartite_edge_coloring
  - https://yukicoder.me/problems/no/3071
- 彩色多項式
  - https://github.com/eandbsoftware/libraryCPP/blob/master/%23ChromaticPolynomial.cpp


## Verified

https://judge.yosupo.jp/submission/40942
