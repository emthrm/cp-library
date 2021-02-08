---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\u5C0F\u6D41\
      \u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/flow/maximum_flow/maximum_flow_with_minimum_flow_constraint.hpp\"\
    \n\r\ntemplate <template <typename> class C, typename T>\r\nstruct MaximumFlowWithMinimumFlowConstraint\
    \ {\r\n  MaximumFlowWithMinimumFlowConstraint(int n) : n(n), flow(n + 2) {}\r\n\
    \r\n  void add_edge(int src, int dst, T lb, T ub) {\r\n    flow.add_edge(src,\
    \ dst, ub - lb);\r\n    flow.add_edge(n, dst, lb);\r\n    flow.add_edge(src, n\
    \ + 1, lb);\r\n    lb_sum += lb;\r\n  }\r\n\r\n  T solve(int s, int t, T limit)\
    \ {\r\n    T a = flow.maximum_flow(n, n + 1, limit);\r\n    T b = flow.maximum_flow(s,\
    \ n + 1, limit);\r\n    T c = flow.maximum_flow(n, t, limit);\r\n    T d = flow.maximum_flow(s,\
    \ t, limit);\r\n    return a + b == lb_sum && b == c ? b + d : T(-1);\r\n  }\r\
    \n\r\nprivate:\r\n  int n;\r\n  C<T> flow;\r\n  T lb_sum = 0;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <template <typename> class C, typename T>\r\n\
    struct MaximumFlowWithMinimumFlowConstraint {\r\n  MaximumFlowWithMinimumFlowConstraint(int\
    \ n) : n(n), flow(n + 2) {}\r\n\r\n  void add_edge(int src, int dst, T lb, T ub)\
    \ {\r\n    flow.add_edge(src, dst, ub - lb);\r\n    flow.add_edge(n, dst, lb);\r\
    \n    flow.add_edge(src, n + 1, lb);\r\n    lb_sum += lb;\r\n  }\r\n\r\n  T solve(int\
    \ s, int t, T limit) {\r\n    T a = flow.maximum_flow(n, n + 1, limit);\r\n  \
    \  T b = flow.maximum_flow(s, n + 1, limit);\r\n    T c = flow.maximum_flow(n,\
    \ t, limit);\r\n    T d = flow.maximum_flow(s, t, limit);\r\n    return a + b\
    \ == lb_sum && b == c ? b + d : T(-1);\r\n  }\r\n\r\nprivate:\r\n  int n;\r\n\
    \  C<T> flow;\r\n  T lb_sum = 0;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/maximum_flow/maximum_flow_with_minimum_flow_constraint.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp
documentation_of: graph/flow/maximum_flow/maximum_flow_with_minimum_flow_constraint.hpp
layout: document
title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
---


## 計算量

[最大流](maximum_flow.md)に同じ．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`MaximumFlowWithMinimumFlowConstraint<最大流, T>(n)`|頂点数 $N$ の最小流量制約付き最大流を考える．||
|`add_edge(src, dst, lb, ub)`|始点 $\mathrm{src}$, 終点 $\mathrm{dst}$, 容量の下限 $\mathrm{lb}$, 上限 $\mathrm{ub}$ の辺を張る．||
|`solve(s, t, limit)`|上限を $\mathrm{limit} (\infty)$ とした始点 $s$ から終点 $t$ までの最大流|存在しない場合は $-1$ となる．|


## 参考

- https://snuke.hatenablog.com/entry/2016/07/10/043918
- https://ei1333.github.io/luzhiled/snippets/graph/maxflow-lower-bound.html


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/1615/review/4085139/emthrm/C++14
