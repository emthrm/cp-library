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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <set>\r\n#include <utility>\r\
    \n#include <vector>\r\n\r\n#include \"./edge.hpp\"\r\n#include \"./lowlink.hpp\"\
    \r\n\r\ntemplate <typename CostType>\r\nstruct BiconnectedComponent : Lowlink<CostType>\
    \ {\r\n  std::vector<int> id;\r\n  std::vector<std::vector<int>> vertices, cutpoint;\r\
    \n  std::vector<std::vector<std::pair<int, int>>> block;\r\n\r\n  explicit BiconnectedComponent(\r\
    \n      const std::vector<std::vector<Edge<CostType>>>& graph,\r\n      const\
    \ bool is_full_ver = false)\r\n      : Lowlink<CostType>(graph), is_full_ver(is_full_ver)\
    \ {\r\n    const int n = graph.size();\r\n    id.assign(n, -2);\r\n    if (is_full_ver)\
    \ {\r\n      cutpoint.resize(n);\r\n      is_articulation_point.assign(n, false);\r\
    \n      for (const int articulation_point : this->articulation_points) {\r\n \
    \       is_articulation_point[articulation_point] = true;\r\n      }\r\n    }\r\
    \n    for (int i = 0; i < n; ++i) {\r\n      if (id[i] == -2) {\r\n        id[i]\
    \ = -1;\r\n        dfs(-1, i);\r\n      }\r\n    }\r\n    // const int m = vertices.size();\r\
    \n    // for (int i = 0; i < m; ++i) {\r\n    //   std::sort(block[i].begin(),\
    \ block[i].end());\r\n    // }\r\n    // if (is_full_ver) {\r\n    //   for (int\
    \ i = 0; i < m; ++i) {\r\n    //     std::sort(vertices[i].begin(), vertices[i].end());\r\
    \n    //   }\r\n    //   for (int i = 0; i < n; ++i) {\r\n    //     std::sort(cutpoint[i].begin(),\
    \ cutpoint[i].end());\r\n    //   }\r\n    // }\r\n  }\r\n\r\n private:\r\n  const\
    \ bool is_full_ver;\r\n  std::vector<bool> is_articulation_point;\r\n  std::vector<std::pair<int,\
    \ int>> tmp;\r\n\r\n  void dfs(const int par, const int ver) {\r\n    for (const\
    \ Edge<CostType>& e : this->graph[ver]) {\r\n      if (e.dst == par) continue;\r\
    \n      if (id[e.dst] == -2 || this->order[ver] > this->order[e.dst]) {\r\n  \
    \      tmp.emplace_back(std::minmax(ver, e.dst));\r\n      }\r\n      if (id[e.dst]\
    \ == -2) {\r\n        id[e.dst] = -1;\r\n        dfs(ver, e.dst);\r\n        if\
    \ (this->order[ver] <= this->lowlink[e.dst]) {\r\n          const int idx = block.size();\r\
    \n          block.emplace_back();\r\n          std::set<int> st;\r\n         \
    \ while (true) {\r\n            const std::pair<int, int> pr = tmp.back();\r\n\
    \            tmp.pop_back();\r\n            block.back().emplace_back(pr);\r\n\
    \            if (is_full_ver) {\r\n              st.emplace(pr.first);\r\n   \
    \           st.emplace(pr.second);\r\n            }\r\n            if (pr ==\r\
    \n                static_cast<std::pair<int, int>>(std::minmax(ver, e.dst))) {\r\
    \n              break;\r\n            }\r\n          }\r\n          if (is_full_ver)\
    \ {\r\n            vertices.emplace_back();\r\n            for (const int el :\
    \ st) {\r\n              vertices.back().emplace_back(el);\r\n              if\
    \ (is_articulation_point[el]) {\r\n                cutpoint[el].emplace_back(idx);\r\
    \n              } else {\r\n                id[el] = idx;\r\n              }\r\
    \n            }\r\n          }\r\n        }\r\n      }\r\n    }\r\n  }\r\n};\r\
    \n"
  dependsOn:
  - graph/edge.hpp
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/biconnected_component.hpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/biconnected_component.hpp
layout: document
title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component) \u5206\
  \u89E3"
---

無向グラフを関節点の存在しない辺集合に分割することである．

それぞれの成分には，任意の相異なる3点を始点・経由点・終点とする単純パスが存在する．


### block-cut tree

二重頂点連結成分を一つの頂点につぶすことで得られる木である．


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
|`BiconnectedComponent(graph, 完全版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重頂点連結成分分解を考える．|[lowlink](lowlink.md)|
|`id[i]`|元のグラフの頂点 $i$ を含むブロック|完全版のみ|
|`vertices[i]`|縮約後のグラフのブロック $i$ に含まれる頂点|完全版のみ|
|`cutpoint[i]`|元のグラフの関節点 $i$ を含むブロック|完全版のみ|
|`block[i]`|縮約後のグラフのブロック $i$ に含まれる辺||


## 参考

- https://www.learning-algorithms.com/entry/2018/03/21/152148
- https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
- https://codeforces.com/blog/entry/14832

カクタスグラフ
- https://pekempey.hatenablog.com/entry/2017/03/28/203856


## Verified

https://atcoder.jp/contests/arc045/submissions/9253901
