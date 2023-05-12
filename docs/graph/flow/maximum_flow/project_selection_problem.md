---
title: project selection problem
documentation_of: //include/emthrm/graph/flow/maximum_flow/project_selection_problem.hpp
---


## 計算量

[最大流](maximum_flow.md)に同じ。


## 仕様

```cpp
template <template <typename> class C, typename T>
struct ProjectSelectionProblem
requires MaximumFlow<C, T>;
```

- `C`：最大流を表す構造体
- `T`：コストを表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit ProjectSelectionProblem(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_neq(const int u, const int v, const T cost);`|$u$ が集合 $0$, $v$ が集合 $1$ に属するならばコスト $\mathrm{cost} \geq 0$ かかると定義する。|
|`void add(const int v, bool group, T cost);`|$v$ が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost}$ かかると定義する。|
|`void add_or(const std::vector<int>& v, const bool group, const T cost);`|集合 $\mathrm{group}$ に属する頂点 $v \in V$ が存在するならばコスト $\mathrm{cost} \geq 0$ かかると定義する。|
|`void add_or(const int u, const int v, const bool group, const T cost);`|$u, v$ のいずれかまたは両方が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \geq 0$ かかると定義する。|
|`void add_eq(const std::vector<int>& v, const bool group, T cost);`|$V$ に属する頂点すべてが集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \leq 0$ かかると定義する。|
|`void add_eq(const int u, const int v, const bool group, const T cost);`|$u, v$ 両方が集合 $\mathrm{group}$ に属するならばコスト $\mathrm{cost} \leq 0$ かかると定義する。|
|`T solve();`|最小コスト|


## 参考文献

- ~~https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/~~
- https://ei1333.github.io/algorithm/dinic.html
- https://koyumeishi.hatenablog.com/entry/2021/01/14/052223


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2903/review/5292569/emthrm/C++17
