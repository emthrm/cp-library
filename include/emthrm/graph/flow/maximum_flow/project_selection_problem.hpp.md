---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
    title: "\u6700\u5927\u6D41\u30B3\u30F3\u30BB\u30D7\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
    title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/project selection\
      \ problem"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/flow/maximum_flow/maximum_flow.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_PROJECT_SELECTION_PROBLEM_HPP_\n#define\
    \ EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_PROJECT_SELECTION_PROBLEM_HPP_\n\n#include <cassert>\n\
    #include <limits>\n#include <vector>\n\n#include \"emthrm/graph/flow/maximum_flow/maximum_flow.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <template <typename> class C, typename T>\n\
    requires MaximumFlow<C, T>\nstruct ProjectSelectionProblem {\n  explicit ProjectSelectionProblem(const\
    \ int n)\n      : inf(std::numeric_limits<T>::max()), n(n), res(0) {}\n\n  void\
    \ add_neq(const int u, const int v, const T cost) {\n    assert(cost >= 0);\n\
    \    us.emplace_back(u);\n    vs.emplace_back(v);\n    costs.emplace_back(cost);\n\
    \  }\n\n  void add(const int v, bool group, T cost) {\n    if (cost < 0) {\n \
    \     cost = -cost;\n      res += cost;\n      group = !group;\n    }\n    if\
    \ (group) {\n      add_neq(-2, v, cost);  // -2 represents S.\n    } else {\n\
    \      add_neq(v, -1, cost);  // -1 represents T.\n    }\n  }\n\n  void add_or(const\
    \ std::vector<int>& v, const bool group, const T cost) {\n    assert(cost >= 0);\n\
    \    add(n, group, cost);\n    if (group) {\n      for (const int e : v) add_neq(n,\
    \ e, inf);\n    } else {\n      for (const int e : v) add_neq(e, n, inf);\n  \
    \  }\n    ++n;\n  }\n\n  void add_or(const int u, const int v, const bool group,\
    \ const T cost) {\n    add_or({u, v}, group, cost);\n  }\n\n  void add_eq(const\
    \ std::vector<int>& v, const bool group, T cost) {\n    assert(cost <= 0);\n \
    \   cost = -cost;\n    res += cost;\n    add_or(v, !group, cost);\n  }\n\n  void\
    \ add_eq(const int u, const int v, const bool group, const T cost) {\n    add_eq({u,\
    \ v}, group, cost);\n  }\n\n  T solve() {\n    C<T> mf(n + 2);\n    const int\
    \ neq_size = costs.size();\n    for (int i = 0; i < neq_size; ++i) {\n      mf.add_edge(us[i]\
    \ < 0 ? us[i] + n + 2 : us[i],\n                  vs[i] < 0 ? vs[i] + n + 2 :\
    \ vs[i], costs[i]);\n    }\n    return mf.maximum_flow(n, n + 1, inf) - res;\n\
    \  }\n\n private:\n  const T inf;\n  int n;\n  T res;\n  std::vector<int> us,\
    \ vs;\n  std::vector<T> costs;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_PROJECT_SELECTION_PROBLEM_HPP_\n"
  dependsOn:
  - include/emthrm/graph/flow/maximum_flow/maximum_flow.hpp
  isVerificationFile: false
  path: include/emthrm/graph/flow/maximum_flow/project_selection_problem.hpp
  requiredBy: []
  timestamp: '2023-02-24 00:16:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/flow/maximum_flow/project_selection_problem.test.cpp
documentation_of: include/emthrm/graph/flow/maximum_flow/project_selection_problem.hpp
layout: document
title: project selection problem
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

- https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/
- https://ei1333.github.io/algorithm/dinic.html
- https://koyumeishi.hatenablog.com/entry/2021/01/14/052223


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2903/review/5292569/emthrm/C++17
