---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/detect_path.test.cpp
    title: "\u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/detect_walk.md
    document_title: "\u9053\u306E\u691C\u51FA"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/emthrm/graph/detect_path.hpp: line 12: unable to process #include in\
    \ #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief \u9053\u306E\u691C\u51FA\n * @docs docs/graph/detect_walk.md\n\
    \ */\n\n#ifndef EMTHRM_GRAPH_DETECT_PATH_HPP_\n#define EMTHRM_GRAPH_DETECT_PATH_HPP_\n\
    \n#include <functional>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>>\
    \ detect_path(\n    const std::vector<std::vector<Edge<CostType>>>& graph,\n \
    \   const int s, const int t) {\n  std::vector<bool> is_visited(graph.size(),\
    \ false);\n  std::vector<Edge<CostType>> path;\n  const std::function<bool(const\
    \ int)> dfs =\n      [&graph, t, &is_visited, &path, &dfs](const int ver) -> bool\
    \ {\n        if (ver == t) return true;\n        is_visited[ver] = true;\n   \
    \     for (const Edge<CostType>& e : graph[ver]) {\n          if (!is_visited[e.dst])\
    \ {\n            path.emplace_back(e);\n            if (dfs(e.dst)) return true;\n\
    \            path.pop_back();\n          }\n        }\n        return false;\n\
    \      };\n  dfs(s);\n  return path;\n}\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_GRAPH_DETECT_PATH_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/detect_path.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/detect_path.test.cpp
documentation_of: include/emthrm/graph/detect_path.hpp
layout: document
redirect_from:
- /library/include/emthrm/graph/detect_path.hpp
- /library/include/emthrm/graph/detect_path.hpp.html
title: "\u9053\u306E\u691C\u51FA"
---
# 歩道 (walk) の検出


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 仕様

### 道 (path) の検出

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<Edge<CostType>> detect_path(const std::vector<std::vector<Edge<CostType>>>& graph, const int s, const int t);`|有向グラフ $\mathrm{graph}$ における始点 $s$、終点 $t$ の道。ただし存在しないときは空配列を返す。|


### 有向閉路 (directed cycle) の検出

|名前|戻り値|
|:--|:--|
|`template <typename CostType>`<br>`std::vector<Edge<CostType>> detect_directed_cycle(const std::vector<std::vector<Edge<CostType>>>& graph);`|有向グラフ $\mathrm{graph}$ における閉路。ただし存在しないときは空配列を返す。|


## 参考文献

有向閉路の検出
- https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-6-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA


## TODO

- 無向閉路の検出
  - https://judge.yosupo.jp/problem/cycle_detection_undirected
- 閉路の列挙
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/cycle_enumeration.cc


## Submissons

- [道の検出](https://atcoder.jp/contests/past202112-open/submissions/29621513)
- [有向閉路の検出](https://judge.yosupo.jp/submission/15525)
