---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/detect_directed_cycle.test.cpp
    title: "\u30B0\u30E9\u30D5/\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\u30B0\u30E9\
      \u30D5\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/detect_cycle.md
    document_title: "\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\u30B0\u30E9\u30D5\
      \u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/detect_directed_cycle.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\u30B0\u30E9\u30D5\
    \u7248\r\n * @docs docs/graph/detect_cycle.md\r\n */\r\n\r\n#pragma once\r\n#include\
    \ <algorithm>\r\n#include <functional>\r\n#include <vector>\r\n\r\n#include \"\
    edge.hpp\"\r\n\r\ntemplate <typename CostType>\r\nstd::vector<Edge<CostType>>\
    \ detect_directed_cycle(\r\n    const std::vector<std::vector<Edge<CostType>>>&\
    \ graph) {\r\n  const int n = graph.size();\r\n  std::vector<int> is_visited(n,\
    \ 0);\r\n  std::vector<Edge<CostType>> edges, cycle;\r\n  const std::function<bool(int)>\
    \ dfs =\r\n      [&graph, &is_visited, &edges, &cycle, &dfs](const int ver) ->\
    \ bool {\r\n        is_visited[ver] = 1;\r\n        for (const Edge<CostType>&\
    \ e : graph[ver]) {\r\n          if (is_visited[e.dst] == 1) {\r\n           \
    \ cycle.emplace_back(e);\r\n            while (cycle.back().src != e.dst) {\r\n\
    \              cycle.emplace_back(edges.back());\r\n              edges.pop_back();\r\
    \n            }\r\n            std::reverse(cycle.begin(), cycle.end());\r\n \
    \           return true;\r\n          } else if (is_visited[e.dst] == 0) {\r\n\
    \            edges.emplace_back(e);\r\n            if (dfs(e.dst)) return true;\r\
    \n            edges.pop_back();\r\n          }\r\n        }\r\n        is_visited[ver]\
    \ = 2;\r\n        return false;\r\n      };\r\n  for (int i = 0; i < n; ++i) {\r\
    \n    if (is_visited[i] == 0 && dfs(i)) break;\r\n  }\r\n  return cycle;\r\n}\r\
    \n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/detect_directed_cycle.hpp
  requiredBy: []
  timestamp: '2022-02-15 21:43:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/detect_directed_cycle.test.cpp
documentation_of: graph/detect_directed_cycle.hpp
layout: document
redirect_from:
- /library/graph/detect_directed_cycle.hpp
- /library/graph/detect_directed_cycle.hpp.html
title: "\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\u30B0\u30E9\u30D5\u7248"
---
# 閉路の検出


## 時間計算量

有向グラフ版 $O(\lvert V \rvert + \lvert E \rvert)$


## 使用法

- 有向グラフ版

||説明|備考|
|:--:|:--:|:--:|
|`detect_directed_cycle(graph)`|有向グラフ $\mathrm{graph}$ の閉路|存在しない場合は空配列となる．|


## 参考

有向グラフ版
- https://qiita.com/drken/items/a803d4fc4a727e02f7ba#4-6-%E3%82%B5%E3%82%A4%E3%82%AF%E3%83%AB%E6%A4%9C%E5%87%BA


## ToDo

- 閉路の列挙
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/cycle_enumeration.cc


## Verified

- [有向グラフ版](https://judge.yosupo.jp/submission/15525)
