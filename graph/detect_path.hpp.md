---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/detect_path.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u9053\u306E\u691C\u51FA\n * @docs docs/graph/detect_walk.md\n\
    \ */\n\n#pragma once\n#include <functional>\n#include <vector>\n\n#include \"\
    ./edge.hpp\"\n\ntemplate <typename CostType>\nstd::vector<Edge<CostType>> detect_path(\n\
    \    const std::vector<std::vector<Edge<CostType>>>& graph,\n    const int s,\
    \ const int t) {\n  std::vector<bool> is_visited(graph.size(), false);\n  std::vector<Edge<CostType>>\
    \ path;\n  const std::function<bool(const int)> dfs =\n      [&graph, t, &is_visited,\
    \ &path, &dfs](const int ver) -> bool {\n        if (ver == t) return true;\n\
    \        is_visited[ver] = true;\n        for (const Edge<CostType>& e : graph[ver])\
    \ {\n          if (!is_visited[e.dst]) {\n            path.emplace_back(e);\n\
    \            if (dfs(e.dst)) return true;\n            path.pop_back();\n    \
    \      }\n        }\n        return false;\n      };\n  dfs(s);\n  return path;\n\
    }\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/detect_path.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/detect_path.test.cpp
documentation_of: graph/detect_path.hpp
layout: document
redirect_from:
- /library/graph/detect_path.hpp
- /library/graph/detect_path.hpp.html
title: "\u9053\u306E\u691C\u51FA"
---
# 歩道 (walk) の検出


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- 道 (path) の検出

||説明|備考|
|:--:|:--:|:--:|
|`detect_path(graph, s, t)`|有向グラフ $\mathrm{graph}$ における始点 $s$，終点 $t$ の道|存在しないときは空配列となる．|

- 有向閉路 (directed cycle) の検出

||説明|備考|
|:--:|:--:|:--:|
|`detect_directed_cycle(graph)`|有向グラフ $\mathrm{graph}$ における閉路|存在しないときは空配列となる．|


## 参考

有向閉路の検出
- https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-6-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA


## ToDo

- 閉路の列挙
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/cycle_enumeration.cc


## Verified

- [道の検出](https://atcoder.jp/contests/past202112-open/submissions/29621513)
- [有向閉路の検出](https://judge.yosupo.jp/submission/15525)
