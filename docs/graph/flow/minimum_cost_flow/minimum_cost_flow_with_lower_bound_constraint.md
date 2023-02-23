---
title: 最小流量制約付き最小費用流
documentation_of: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp
---


## 計算量

[最小費用流](minimum_cost_flow.md)に同じ。


## 仕様

```cpp
template <template <typename, typename> class C, typename T, typename U>
struct MinimumCostFlowWithLowerBoundConstraint
requires requires (C<T, U> mcf) {
  {mcf.add_edge(std::declval<int>(), std::declval<int>(),
                std::declval<T>(), std::declval<U>())}
      -> std::same_as<void>;
  {mcf.solve(std::declval<int>(), std::declval<int>(), std::declval<T>())}
      -> std::same_as<U>;
};
```

- `C`：最小費用流を表す構造体
- `T`：容量を表す型
- `U`：コストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`const U uinf`|$\infty$|

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit MinimumCostFlowWithLowerBoundConstraint(const int n, const U m, const U uinf = std::numeric_limits<U>::max());`|頂点数 $N$ のオブジェクトを構築する。|$m$ は十分大きな定数である。|
|`void add_edge(const int src, const int dst, const T lb, const T ub, const U cost);`|始点 $\mathrm{src}$、終点 $\mathrm{dst}$、流量の下限 $\mathrm{lb}$、上限 $\mathrm{ub}$、コスト $\mathrm{cost}$ の辺を加える。||
|`U solve(const int s, const int t, const T flow);`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値。ただし流せないときは `uinf` を返す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，p.204，マイナビ出版（2012）


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14

