# 内周 (girth)

グラフに対する最小閉路長である。


## 時間計算量

$O(\lvert V \rvert (\lvert V \rvert + \lvert E \rvert) \log{\lvert V \rvert})$


## 仕様

### 有向グラフ版

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename CostType> CostType girth_in_directed_graph(const std::vector<std::vector<Edge<CostType>>>& graph, const CostType inf = std::numeric_limits<CostType>::max());`|有向グラフ $\mathrm{graph}$ の内周。ただし存在しないときは $\infty$ を返す。|辺の重みは自然数である。|


### 無向グラフ版

|名前|戻り値|要件|
|:--|:--|:--|
|`template <typename CostType> CostType girth_in_undirected_graph(const int n, const std::vector<Edge<CostType>>& edges, const CostType inf = std::numeric_limits<CostType>::max());`|頂点数 $n$、辺集合 $\mathrm{edges}$ である無向グラフの内周。ただし存在しないときは $\infty$ を返す。|辺の重みは自然数である。|


## 参考文献

- https://yukicoder.me/problems/no/1320/editorial
- https://algo-logic.info/minimum-weight-cycle/


## TODO

- minimum mean-weight cycle
  - https://37zigen.com/%E6%9C%80%E5%B0%8F%E5%B9%B3%E5%9D%87%E9%95%B7%E9%96%89%E8%B7%AF%E5%95%8F%E9%A1%8C/
  - https://kopricky.github.io/code/Graph/directed_minimum_mean_weight_cycle_memo.html


## Submissons

https://yukicoder.me/submissions/595363
