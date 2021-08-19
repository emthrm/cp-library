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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <set>\r\n#include <utility>\r\
    \n#include <vector>\r\n#include \"lowlink.hpp\"\r\n#include \"edge.hpp\"\r\n\r\
    \ntemplate <typename CostType>\r\nstruct BiconnectedComponent : Lowlink<CostType>\
    \ {\r\n  std::vector<std::vector<std::pair<int, int>>> block;\r\n  std::vector<int>\
    \ id;\r\n  std::vector<std::vector<int>> vertices, cutpoint;\r\n\r\n  BiconnectedComponent(const\
    \ std::vector<std::vector<Edge<CostType>>> &graph, bool heavy = false) : Lowlink<CostType>(graph),\
    \ heavy(heavy) {\r\n    int n = graph.size();\r\n    id.assign(n, -2);\r\n   \
    \ if (heavy) {\r\n      cutpoint.resize(n);\r\n      is_ap.assign(n, false);\r\
    \n      for (int e : this->ap) is_ap[e] = true;\r\n    }\r\n    for (int i = 0;\
    \ i < n; ++i) {\r\n      if (id[i] == -2) {\r\n        id[i] = -1;\r\n       \
    \ dfs(-1, i);\r\n      }\r\n    }\r\n    // if (heavy) {\r\n    //   int sz =\
    \ vertices.size();\r\n    //   for (int i = 0; i < sz; ++i) {\r\n    //     std::sort(block[i].begin(),\
    \ block[i].end());\r\n    //     std::sort(vertices[i].begin(), vertices[i].end());\r\
    \n    //   }\r\n    //   for (int i = 0; i < n; ++i) std::sort(cutpoint[i].begin(),\
    \ cutpoint[i].end());\r\n    // }\r\n  }\r\n\r\nprivate:\r\n  using P = std::pair<int,\
    \ int>;\r\n\r\n  bool heavy;\r\n  std::vector<bool> is_ap;\r\n  std::vector<P>\
    \ tmp;\r\n\r\n  void dfs(int par, int ver) {\r\n    for (const Edge<CostType>\
    \ &e : this->graph[ver]) {\r\n      if (e.dst == par) continue;\r\n      if (id[e.dst]\
    \ == -2 || this->order[ver] > this->order[e.dst]) tmp.emplace_back(std::minmax(ver,\
    \ e.dst));\r\n      if (id[e.dst] == -2) {\r\n        id[e.dst] = -1;\r\n    \
    \    dfs(ver, e.dst);\r\n        if (this->order[ver] <= this->lowlink[e.dst])\
    \ {\r\n          int idx = block.size();\r\n          block.emplace_back();\r\n\
    \          std::set<int> st;\r\n          while (true) {\r\n            P pr =\
    \ tmp.back();\r\n            block[idx].emplace_back(pr);\r\n            if (heavy)\
    \ {\r\n              st.emplace(pr.first);\r\n              st.emplace(pr.second);\r\
    \n            }\r\n            tmp.pop_back();\r\n            if (pr.first ==\
    \ std::min(ver, e.dst) && pr.second == std::max(ver, e.dst)) break;\r\n      \
    \    }\r\n          if (heavy) {\r\n            vertices.emplace_back();\r\n \
    \           for (int el : st) {\r\n              vertices[idx].emplace_back(el);\r\
    \n              if (is_ap[el]) {\r\n                cutpoint[el].emplace_back(idx);\r\
    \n              } else {\r\n                id[el] = idx;\r\n              }\r\
    \n            }\r\n          }\r\n        }\r\n      }\r\n    }\r\n  }\r\n};\r\
    \n"
  dependsOn:
  - graph/lowlink.hpp
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/biconnected_component.hpp
  requiredBy: []
  timestamp: '2021-04-18 15:42:16+09:00'
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

二重頂点連結成分を一つの頂点につぶすことで得られる木である．


### カクタスグラフ (cactus)

任意の辺が高々一つの単純閉路に含まれる，すなわち任意の異なる単純閉路が高々一つの共通頂点をもつグラフである．

任意の二重頂点連結成分は橋または単純閉路となる．

e.g. 任意の閉路長が奇数となるグラフ


## 時間計算量

$O(\lvert V \rvert + \lvert E \rvert)$

重量版 $O(\lvert V \rvert \log{\lvert V \rvert} + \lvert E \rvert)$ ?


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`BiconnectedComponent(graph, 重量版であるか = false)`|無向グラフ $\mathrm{graph}$ の二重頂点連結成分分解を考える．|[lowlink](lowlink.md)|
|`block[i]`|縮約後のグラフのブロック $i$ に含まれる辺||
|`id[i]`|元のグラフの頂点 $i$ を含むブロック|重量版のみ|
|`vertices[i]`|縮約後のグラフのブロック $i$ に含まれる頂点|重量版のみ|
|`cutpoint[i]`|元のグラフの関節点 $i$ を含むブロック|重量版のみ|


## 参考

- https://www.learning-algorithms.com/entry/2018/03/21/152148
- https://ei1333.github.io/luzhiled/snippets/graph/bi-connected-components.html
- https://codeforces.com/blog/entry/14832

カクタスグラフ
- https://pekempey.hatenablog.com/entry/2017/03/28/203856


## Verified

https://atcoder.jp/contests/arc045/submissions/9253901
