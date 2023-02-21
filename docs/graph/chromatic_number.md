---
title: 彩色数 (chromatic number)
documentation_of: include/emthrm/graph/chromatic_number.hpp
---

隣接頂点間で色が異なるような頂点彩色に必要な最小の色の数である。


## 時間計算量

$O(2^{\lvert V \rvert} \lvert V \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`int chromatic_number(const std::vector<std::vector<Edge<CostType>>>& graph);`|無向グラフ $\mathrm{graph}$ の彩色数|


## 参考文献

- https://www.slideshare.net/wata_orz/ss-12131479
- http://drken1215.hatenablog.com/entry/2019/01/16/030000
- https://www.learning-algorithms.com/entry/2018/01/27/235959
- https://github.com/spaghetti-source/algorithm/blob/b541e0b06aa4145592527b7de8e2caa8720bac22/graph/chromatic_number.cc


## TODO

- 高速化
  - https://www.mathenachia.blog/chromatic-fast/
  - https://atcoder.jp/contests/abc056/editorial/2092
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


## Submissons

https://judge.yosupo.jp/submission/40942
