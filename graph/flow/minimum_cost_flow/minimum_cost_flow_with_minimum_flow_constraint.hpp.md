---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
      \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp\"\
    \n#include <limits>\r\n\r\ntemplate <template <typename, typename> class C, typename\
    \ T, typename U>\r\nstruct MinimumCostFlowWithMinimumFlowConstraint {\r\n  const\
    \ U uinf;\r\n\r\n  MinimumCostFlowWithMinimumFlowConstraint(int n, const U M,\
    \ const U uinf = std::numeric_limits<U>::max())\r\n  : M(M), uinf(uinf), mcf(n,\
    \ uinf) {}\r\n\r\n  void add_edge(int src, int dst, T lb, T ub, U cost) {\r\n\
    \    mcf.add_edge(src, dst, ub - lb, cost);\r\n    mcf.add_edge(src, dst, lb,\
    \ cost - M);\r\n    lb_sum += lb;\r\n  }\r\n\r\n  U solve(int s, int t, T flow)\
    \ {\r\n    U tmp = mcf.solve(s, t, flow);\r\n    return tmp == uinf ? uinf : tmp\
    \ + M * lb_sum;\r\n  }\r\n\r\nprivate:\r\n  const U M;\r\n  T lb_sum = 0;\r\n\
    \  C<T, U> mcf;\r\n};\r\n"
  code: "#pragma once\r\n#include <limits>\r\n\r\ntemplate <template <typename, typename>\
    \ class C, typename T, typename U>\r\nstruct MinimumCostFlowWithMinimumFlowConstraint\
    \ {\r\n  const U uinf;\r\n\r\n  MinimumCostFlowWithMinimumFlowConstraint(int n,\
    \ const U M, const U uinf = std::numeric_limits<U>::max())\r\n  : M(M), uinf(uinf),\
    \ mcf(n, uinf) {}\r\n\r\n  void add_edge(int src, int dst, T lb, T ub, U cost)\
    \ {\r\n    mcf.add_edge(src, dst, ub - lb, cost);\r\n    mcf.add_edge(src, dst,\
    \ lb, cost - M);\r\n    lb_sum += lb;\r\n  }\r\n\r\n  U solve(int s, int t, T\
    \ flow) {\r\n    U tmp = mcf.solve(s, t, flow);\r\n    return tmp == uinf ? uinf\
    \ : tmp + M * lb_sum;\r\n  }\r\n\r\nprivate:\r\n  const U M;\r\n  T lb_sum = 0;\r\
    \n  C<T, U> mcf;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp
  requiredBy: []
  timestamp: '2021-04-20 01:59:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp
documentation_of: graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp
layout: document
title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
---


## 計算量

[最小費用流](minimum_cost_flow.md)に同じ．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`MinimumCostFlowWithMinimumFlowConstraint<最小費用流, フロー, コスト>(n, 十分大きな定数, ∞)`|頂点数 $N$ の最小流量制約付き最小費用流を考える．||
|`uinf`|$\infty$|型はコストと等しい．|
|`add_edge(src, dst, lb, ub, cost)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 流量の下限 $\mathrm{lb}$, 上限 $\mathrm{ub}$, コスト $\mathrm{cost}$ の辺を張る．||
|`solve(s, t, flow)`|始点 $s$ から終点 $t$ まで流量 $\mathrm{flow}$ のフローを流すときのコストの最小値|流せない場合は $\infty$ となる．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] p.204


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2230/review/4224563/emthrm/C++14

