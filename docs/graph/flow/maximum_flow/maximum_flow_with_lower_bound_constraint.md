---
title: 最小流量制約付き最大流
documentation_of: include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
---


## 計算量

[最大流](maximum_flow.md)に同じ。


## 仕様

```cpp
template <template <typename> class C, typename T>
struct MaximumFlowWithLowerBoundConstraint
requires MaximumFlow<C, T>;
```

- `C`：最大流を表す構造体
- `T`：容量を表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit MaximumFlowWithLowerBoundConstraint(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const T lb, const T ub);`|始点 $\mathrm{src}$、終点 $\mathrm{dst}$、容量の下限 $\mathrm{lb}$、上限 $\mathrm{ub}$ の辺を加える。|
|`T solve(const int s, const int t);`|始点 $s$ から終点 $t$ までの最大流。ただし存在しないときは $-1$ を返す。|


## 参考文献

- https://snuke.hatenablog.com/entry/2016/07/10/043918
- https://ei1333.github.io/luzhiled/snippets/graph/maxflow-lower-bound.html


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/1615/review/4085139/emthrm/C++14
