---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
      \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp\"\
    \n\n\n\n#include <concepts>\n#include <limits>\n#include <utility>\n\nnamespace\
    \ emthrm {\n\ntemplate <template <typename, typename> class C, typename T, typename\
    \ U>\nrequires requires (C<T, U> mcf) {\n  {mcf.add_edge(std::declval<int>(),\
    \ std::declval<int>(),\n                std::declval<T>(), std::declval<U>())}\n\
    \      -> std::same_as<void>;\n  {mcf.solve(std::declval<int>(), std::declval<int>(),\
    \ std::declval<T>())}\n      -> std::same_as<U>;\n}\nstruct MinimumCostFlowWithLowerBoundConstraint\
    \ {\n  const U uinf;\n\n  explicit MinimumCostFlowWithLowerBoundConstraint(\n\
    \      const int n, const U m, const U uinf = std::numeric_limits<U>::max())\n\
    \      : uinf(uinf), m(m), sum_lb(0), mcf(n, uinf) {}\n\n  void add_edge(const\
    \ int src, const int dst, const T lb, const T ub,\n                const U cost)\
    \ {\n    mcf.add_edge(src, dst, ub - lb, cost);\n    mcf.add_edge(src, dst, lb,\
    \ cost - m);\n    sum_lb += lb;\n  }\n\n  U solve(const int s, const int t, const\
    \ T flow) {\n    const U tmp = mcf.solve(s, t, flow);\n    return tmp == uinf\
    \ ? uinf : tmp + m * sum_lb;\n  }\n\n private:\n  const U m;\n  T sum_lb;\n  C<T,\
    \ U> mcf;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_\n\
    #define EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_\n\
    \n#include <concepts>\n#include <limits>\n#include <utility>\n\nnamespace emthrm\
    \ {\n\ntemplate <template <typename, typename> class C, typename T, typename U>\n\
    requires requires (C<T, U> mcf) {\n  {mcf.add_edge(std::declval<int>(), std::declval<int>(),\n\
    \                std::declval<T>(), std::declval<U>())}\n      -> std::same_as<void>;\n\
    \  {mcf.solve(std::declval<int>(), std::declval<int>(), std::declval<T>())}\n\
    \      -> std::same_as<U>;\n}\nstruct MinimumCostFlowWithLowerBoundConstraint\
    \ {\n  const U uinf;\n\n  explicit MinimumCostFlowWithLowerBoundConstraint(\n\
    \      const int n, const U m, const U uinf = std::numeric_limits<U>::max())\n\
    \      : uinf(uinf), m(m), sum_lb(0), mcf(n, uinf) {}\n\n  void add_edge(const\
    \ int src, const int dst, const T lb, const T ub,\n                const U cost)\
    \ {\n    mcf.add_edge(src, dst, ub - lb, cost);\n    mcf.add_edge(src, dst, lb,\
    \ cost - m);\n    sum_lb += lb;\n  }\n\n  U solve(const int s, const int t, const\
    \ T flow) {\n    const U tmp = mcf.solve(s, t, flow);\n    return tmp == uinf\
    \ ? uinf : tmp + m * sum_lb;\n  }\n\n private:\n  const U m;\n  T sum_lb;\n  C<T,\
    \ U> mcf;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_FLOW_MINIMUM_COST_FLOW_MINIMUM_COST_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
documentation_of: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp
layout: document
title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
---


## 計算量

[最小費用流](minimum_cost_flow.md)に同じ。


## 仕様

```cpp
template <template <typename, typename> class C, typename T, typename U>
requires requires (C<T, U> mcf) {
  {mcf.add_edge(std::declval<int>(), std::declval<int>(),
                std::declval<T>(), std::declval<U>())}
      -> std::same_as<void>;
  {mcf.solve(std::declval<int>(), std::declval<int>(), std::declval<T>())}
      -> std::same_as<U>;
}
struct MinimumCostFlowWithLowerBoundConstraint;
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

