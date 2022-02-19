---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\u5C0F\u6D41\
      \u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp\"\
    \n\r\ntemplate <template <typename> class C, typename T>\r\nstruct MaximumFlowWithLowerBoundConstraint\
    \ {\r\n  explicit MaximumFlowWithLowerBoundConstraint(const int n)\r\n      :\
    \ n(n), sum_lb(0), mf(n + 2) {}\r\n\r\n  void add_edge(const int src, const int\
    \ dst, const T lb, const T ub) {\r\n    mf.add_edge(src, dst, ub - lb);\r\n  \
    \  mf.add_edge(n, dst, lb);\r\n    mf.add_edge(src, n + 1, lb);\r\n    sum_lb\
    \ += lb;\r\n  }\r\n\r\n  T solve(const int s, const int t) {\r\n    const T a\
    \ = mf.maximum_flow(n, n + 1);\r\n    const T b = mf.maximum_flow(s, n + 1);\r\
    \n    const T c = mf.maximum_flow(n, t);\r\n    const T d = mf.maximum_flow(s,\
    \ t);\r\n    return a + b == sum_lb && b == c ? b + d : -1;\r\n  }\r\n\r\n private:\r\
    \n  const int n;\r\n  T sum_lb;\r\n  C<T> mf;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <template <typename> class C, typename T>\r\n\
    struct MaximumFlowWithLowerBoundConstraint {\r\n  explicit MaximumFlowWithLowerBoundConstraint(const\
    \ int n)\r\n      : n(n), sum_lb(0), mf(n + 2) {}\r\n\r\n  void add_edge(const\
    \ int src, const int dst, const T lb, const T ub) {\r\n    mf.add_edge(src, dst,\
    \ ub - lb);\r\n    mf.add_edge(n, dst, lb);\r\n    mf.add_edge(src, n + 1, lb);\r\
    \n    sum_lb += lb;\r\n  }\r\n\r\n  T solve(const int s, const int t) {\r\n  \
    \  const T a = mf.maximum_flow(n, n + 1);\r\n    const T b = mf.maximum_flow(s,\
    \ n + 1);\r\n    const T c = mf.maximum_flow(n, t);\r\n    const T d = mf.maximum_flow(s,\
    \ t);\r\n    return a + b == sum_lb && b == c ? b + d : -1;\r\n  }\r\n\r\n private:\r\
    \n  const int n;\r\n  T sum_lb;\r\n  C<T> mf;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
documentation_of: graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
layout: document
title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
---


## 計算量

[最大流](maximum_flow.md)に同じ．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`MaximumFlowWithLowerBoundConstraint<最大流, T>(n)`|頂点数 $N$ の最小流量制約付き最大流を考える．||
|`add_edge(src, dst, lb, ub)`|始点 $\mathrm{src}$，終点 $\mathrm{dst}$，容量の下限 $\mathrm{lb}$，上限 $\mathrm{ub}$ の辺を加える．||
|`solve(s, t)`|始点 $s$ から終点 $t$ までの最大流|存在しないときは $-1$ となる．|


## 参考

- https://snuke.hatenablog.com/entry/2016/07/10/043918
- https://ei1333.github.io/luzhiled/snippets/graph/maxflow-lower-bound.html


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/1615/review/4085139/emthrm/C++14
