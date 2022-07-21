---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/biconnected_component.test.cpp
    title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
      \u89E3"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\n// #include <algorithm>\n#include <set>\n#include <utility>\n\
    #include <vector>\n\n#include \"./edge.hpp\"\n#include \"./lowlink.hpp\"\n\ntemplate\
    \ <typename CostType>\nstruct BiconnectedComponent : Lowlink<CostType> {\n  std::vector<int>\
    \ id;\n  std::vector<std::vector<int>> vertices, cutpoint;\n  std::vector<std::vector<Edge<CostType>>>\
    \ block;\n\n  explicit BiconnectedComponent(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n      const bool is_full_ver = false)\n      : Lowlink<CostType>(graph),\
    \ is_full_ver(is_full_ver) {\n    const int n = graph.size();\n    id.assign(n,\
    \ -2);\n    if (is_full_ver) {\n      cutpoint.resize(n);\n      is_articulation_point.assign(n,\
    \ false);\n      for (const int articulation_point : this->articulation_points)\
    \ {\n        is_articulation_point[articulation_point] = true;\n      }\n    }\n\
    \    for (int i = 0; i < n; ++i) {\n      if (id[i] == -2) dfs(-1, i);\n    }\n\
    \    // const int m = vertices.size();\n    // for (int i = 0; i < m; ++i) {\n\
    \    //   std::sort(block[i].begin(), block[i].end());\n    // }\n    // if (is_full_ver)\
    \ {\n    //   for (int i = 0; i < m; ++i) {\n    //     std::sort(vertices[i].begin(),\
    \ vertices[i].end());\n    //   }\n    //   for (int i = 0; i < n; ++i) {\n  \
    \  //     std::sort(cutpoint[i].begin(), cutpoint[i].end());\n    //   }\n   \
    \ // }\n  }\n\n private:\n  const bool is_full_ver;\n  std::vector<bool> is_articulation_point;\n\
    \  std::vector<Edge<CostType>> tmp;\n\n  void dfs(const int par, const int ver)\
    \ {\n    id[ver] = -1;\n    for (const Edge<CostType>& e : this->graph[ver]) {\n\
    \      if (e.dst == par) continue;\n      int src = ver, dst = e.dst;\n      if\
    \ (src > dst) std::swap(src, dst);\n      if (id[e.dst] == -2 || this->order[e.dst]\
    \ < this->order[ver]) {\n        tmp.emplace_back(src, dst, e.cost);\n      }\n\
    \      if (id[e.dst] == -2) {\n        dfs(ver, e.dst);\n        if (this->lowlink[e.dst]\
    \ >= this->order[ver]) {\n          const int idx = block.size();\n          block.emplace_back();\n\
    \          std::set<int> st;\n          while (true) {\n            const Edge<CostType>\
    \ edge = tmp.back();\n            tmp.pop_back();\n            block.back().emplace_back(edge);\n\
    \            if (is_full_ver) {\n              st.emplace(edge.src);\n       \
    \       st.emplace(edge.dst);\n            }\n            if (edge.src == src\
    \ && edge.dst == dst) break;\n          }\n          if (is_full_ver) {\n    \
    \        vertices.emplace_back();\n            for (const int el : st) {\n   \
    \           vertices.back().emplace_back(el);\n              if (is_articulation_point[el])\
    \ {\n                cutpoint[el].emplace_back(idx);\n              } else {\n\
    \                id[el] = idx;\n              }\n            }\n          }\n\
    \        }\n      }\n    }\n  }\n};\n"
  dependsOn:
  - graph/edge.hpp
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/biconnected_component.hpp
  requiredBy: []
  timestamp: '2022-05-23 03:48:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/biconnected_component.test.cpp
documentation_of: graph/biconnected_component.hpp
layout: document
title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component) \u5206\
  \u89E3"
---

無向グラフを関節点の存在しない辺集合に分割することである．

それぞれの成分には，任意の相異なる3点を始点・経由点・終点とする単純パスが存在する．


### block-cut tree

二重頂点連結成分を一つの頂点に縮約することで得られる木である．


### カクタスグラフ (cactus)

任意の辺が高々一つの単純閉路に含まれる，すなわち任意の異なる単純閉路が高々一つの共通頂点をもつグラフである．

任意の二重頂点連結成分は橋または単純閉路となる．

e.g. 任意の閉路長が奇数となるグラフ


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$

完全版 $O(\lvert V \rvert \log{\lvert V \rvert} + \lvert E \rvert)$ ?


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`BiconnectedComponent(graph, 完全版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重頂点連結成分分解を考える．||
|`id[i]`|元のグラフの頂点 $i$ を含むブロック|関節点のときは $-1$ である．<br>完全版のみ|
|`vertices[i]`|縮約後のグラフのブロック $i$ に含まれる頂点|完全版のみ|
|`cutpoint[i]`|元のグラフの関節点 $i$ を含むブロック|完全版のみ|
|`block[i]`|縮約後のグラフのブロック $i$ に含まれる辺||


## 参考

- https://www.learning-algorithms.com/entry/2018/03/21/152148
- https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
- https://codeforces.com/blog/entry/14832

カクタスグラフ
- https://pekempey.hatenablog.com/entry/2017/03/28/203856


## ToDo

- https://judge.yosupo.jp/problem/biconnected_components


## Verified

https://atcoder.jp/contests/nadafes2022_day2/submissions/31595927
