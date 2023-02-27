---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
    title: "\u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8"
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
  bundledCode: "#line 1 \"include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp\"\
    \n\n\n\n#line 1 \"include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp\"\n\
    /**\n * @title \u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n\
    \n#include <concepts>\n#include <utility>\n\nnamespace emthrm {\n\ntemplate <template\
    \ <typename> class C, typename T>\nconcept MaximumFlow = requires (C<T> mf) {\n\
    \  {mf.add_edge(std::declval<int>(), std::declval<int>(), std::declval<T>())}\n\
    \      -> std::same_as<void>;\n  {mf.maximum_flow(std::declval<int>(), std::declval<int>())}\n\
    \      -> std::same_as<T>;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_\n\
    #line 5 \"include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <template <typename> class C, typename T>\n\
    requires MaximumFlow<C, T>\nstruct MaximumFlowWithLowerBoundConstraint {\n  explicit\
    \ MaximumFlowWithLowerBoundConstraint(const int n)\n      : n(n), sum_lb(0), mf(n\
    \ + 2) {}\n\n  void add_edge(const int src, const int dst, const T lb, const T\
    \ ub) {\n    mf.add_edge(src, dst, ub - lb);\n    mf.add_edge(n, dst, lb);\n \
    \   mf.add_edge(src, n + 1, lb);\n    sum_lb += lb;\n  }\n\n  T solve(const int\
    \ s, const int t) {\n    const T a = mf.maximum_flow(n, n + 1);\n    const T b\
    \ = mf.maximum_flow(s, n + 1);\n    const T c = mf.maximum_flow(n, t);\n    const\
    \ T d = mf.maximum_flow(s, t);\n    return a + b == sum_lb && b == c ? b + d :\
    \ -1;\n  }\n\n private:\n  const int n;\n  T sum_lb;\n  C<T> mf;\n};\n\n}  //\
    \ namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_\n\
    #define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_\n\
    \n#include \"emthrm/graph/flow/maximum_flow/maximum_flow.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <template <typename> class C, typename T>\nrequires MaximumFlow<C,\
    \ T>\nstruct MaximumFlowWithLowerBoundConstraint {\n  explicit MaximumFlowWithLowerBoundConstraint(const\
    \ int n)\n      : n(n), sum_lb(0), mf(n + 2) {}\n\n  void add_edge(const int src,\
    \ const int dst, const T lb, const T ub) {\n    mf.add_edge(src, dst, ub - lb);\n\
    \    mf.add_edge(n, dst, lb);\n    mf.add_edge(src, n + 1, lb);\n    sum_lb +=\
    \ lb;\n  }\n\n  T solve(const int s, const int t) {\n    const T a = mf.maximum_flow(n,\
    \ n + 1);\n    const T b = mf.maximum_flow(s, n + 1);\n    const T c = mf.maximum_flow(n,\
    \ t);\n    const T d = mf.maximum_flow(s, t);\n    return a + b == sum_lb && b\
    \ == c ? b + d : -1;\n  }\n\n private:\n  const int n;\n  T sum_lb;\n  C<T> mf;\n\
    };\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_WITH_LOWER_BOUND_CONSTRAINT_HPP_\n"
  dependsOn:
  - include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
  isVerificationFile: false
  path: include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
  requiredBy: []
  timestamp: '2023-02-24 21:17:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
documentation_of: include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
layout: document
title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
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
