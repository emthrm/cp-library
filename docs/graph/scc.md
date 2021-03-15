---
title: 強連結成分分解 (strongly connected components)
documentation_of: graph/scc.hpp
---

有向グラフを共通部分のない強連結成分に分解することである．

- Kosaraju's algorithm


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`SCC<CostType>(graph, 重量版であるか = false)`|有向グラフ $\mathrm{graph}$ の強連結成分分解を考える．||
|`id[i]`|元のグラフの頂点 $i$ を含む頂点||
|`vertices[i]`|縮約後のグラフの頂点 $i$ に含まれる頂点|重量版のみ|
|`comp`|強連結成分を一つの頂点につぶしたグラフ||


## 備考

無向グラフの辺に向きをつけることで強連結成分分解可能 $\Leftrightarrow$ グラフが2辺連結．

構築方法としては深さ優先探索木において後退辺を逆辺とすればよい．


## 参考

- https://github.com/beet-aizu/library/blob/346558ee0881bd18b10c0d32d7678b033d6b0326/graph/stronglyconnectedcomponent.cpp

備考
- https://twitter.com/noshi91/status/1172798654450520064


## ToDo

- Tarjan's algorithm
  - http://www.prefield.com/algorithm/graph/strongly_connected_components.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/strongly_connected_component_tarjan.cc
  - https://tubo28.me/compprog/algorithm/tarjan-scc/
- Gabow's algorithm
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/strongly_connected_component_gabow.cc


## Verified

https://judge.yosupo.jp/submission/4441
