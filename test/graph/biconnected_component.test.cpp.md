---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: "union-find \u6728"
  - icon: ':x:'
    path: graph/biconnected_component.hpp
    title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3 (biconnected\
      \ component)"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
      \u5206\u5206\u89E3"
    links:
    - https://atcoder.jp/contests/arc045/tasks/arc045_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/union-find.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc045/tasks/arc045_d\"\
    \r\n\r\n#include <functional>\r\n#include <iostream>\r\n#include <map>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n#include \"../../data_structure/union-find/union-find.hpp\"\
    \r\n#include \"../../graph/edge.hpp\"\r\n#include \"../../graph/biconnected_component.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  n = 2 * n + 1;\r\n \
    \ std::vector<std::vector<int>> x(n), y(n);\r\n  for (int i = 0; i < n; ++i) {\r\
    \n    int xi, yi;\r\n    std::cin >> xi >> yi;\r\n    --xi; --yi;\r\n    x[xi].emplace_back(i);\r\
    \n    y[yi].emplace_back(i);\r\n  }\r\n  UnionFind uf(n);\r\n  for (int i = 0;\
    \ i < n; ++i) {\r\n    for (int j = 0; j + 1 < x[i].size(); ++j) uf.unite(x[i][j],\
    \ x[i][j + 1]);\r\n    for (int j = 0; j + 1 < y[i].size(); ++j) uf.unite(y[i][j],\
    \ y[i][j + 1]);\r\n  }\r\n  std::map<int, std::vector<int>> mp;\r\n  for (int\
    \ i = 0; i < n; ++i) mp[uf.root(i)].emplace_back(i);\r\n  int odd = 0;\r\n  for\
    \ (const std::pair<int, std::vector<int>> &pr : mp) odd += pr.second.size() &\
    \ 1;\r\n  std::vector<bool> ans(n, false);\r\n  if (odd == 1) {\r\n    for (const\
    \ std::pair<int, std::vector<int>> &pr : mp) {\r\n      const std::vector<int>\
    \ &vers = pr.second;\r\n      if (vers.size() % 2 == 0) continue;\r\n      if\
    \ (vers.size() == 1) {\r\n        ans[vers[0]] = true;\r\n        continue;\r\n\
    \      }\r\n      std::map<int, int> idx;\r\n      for (int i = 0; i < vers.size();\
    \ ++i) idx[vers[i]] = i;\r\n      std::vector<std::vector<Edge<bool>>> graph(vers.size());\r\
    \n      for (int i = 0; i < n; ++i) {\r\n        std::vector<int> tmp;\r\n   \
    \     for (int j = 0; j < x[i].size(); ++j) {\r\n          if (idx.count(x[i][j])\
    \ == 1) tmp.emplace_back(idx[x[i][j]]);\r\n        }\r\n        for (int j = 0;\
    \ j + 1 < tmp.size(); ++j) {\r\n          graph[tmp[j]].emplace_back(tmp[j], tmp[j\
    \ + 1]);\r\n          graph[tmp[j + 1]].emplace_back(tmp[j + 1], tmp[j]);\r\n\
    \        }\r\n        if (tmp.size() >= 3) {\r\n          graph[tmp.front()].emplace_back(tmp.front(),\
    \ tmp.back());\r\n          graph[tmp.back()].emplace_back(tmp.back(), tmp.front());\r\
    \n        }\r\n        tmp.clear();\r\n        for (int j = 0; j < y[i].size();\
    \ ++j) {\r\n          if (idx.count(y[i][j]) == 1) tmp.emplace_back(idx[y[i][j]]);\r\
    \n        }\r\n        for (int j = 0; j + 1 < tmp.size(); ++j) {\r\n        \
    \  graph[tmp[j]].emplace_back(tmp[j], tmp[j + 1]);\r\n          graph[tmp[j +\
    \ 1]].emplace_back(tmp[j + 1], tmp[j]);\r\n        }\r\n        if (tmp.size()\
    \ >= 3) {\r\n          graph[tmp.front()].emplace_back(tmp.front(), tmp.back());\r\
    \n          graph[tmp.back()].emplace_back(tmp.back(), tmp.front());\r\n     \
    \   }\r\n      }\r\n      BiconnectedComponent<bool> bc(graph, true);\r\n    \
    \  std::map<int, int> ap_idx;\r\n      for (int i = 0; i < bc.ap.size(); ++i)\
    \ ap_idx[bc.ap[i]] = i;\r\n      for (int i = 0; i < vers.size(); ++i) {\r\n \
    \       if (ap_idx.count(i) == 0) ans[vers[i]] = true;\r\n      }\r\n      int\
    \ sz = bc.vertices.size(), m = sz + bc.ap.size();\r\n      std::vector<std::vector<int>>\
    \ bctree(m);\r\n      std::vector<int> cnt(m);\r\n      for (int i = 0; i < sz;\
    \ ++i) cnt[i] = bc.vertices[i].size();\r\n      for (int i = 0; i < vers.size();\
    \ ++i) {\r\n        if (ap_idx.count(i) == 1) {\r\n          for (int e : bc.cutpoint[i])\
    \ {\r\n            --cnt[e];\r\n            bctree[e].emplace_back(sz + ap_idx[i]);\r\
    \n            bctree[sz + ap_idx[i]].emplace_back(e);\r\n          }\r\n     \
    \     cnt[sz + ap_idx[i]] = 1;\r\n        }\r\n      }\r\n      std::vector<int>\
    \ subtree(m), odd_child(m, 0);\r\n      std::function<void(int, int)> dfs1 = [&bctree,\
    \ &cnt, &subtree, &odd_child, &dfs1](int par, int ver) -> void {\r\n        subtree[ver]\
    \ = cnt[ver];\r\n        for (int e : bctree[ver]) {\r\n          if (e != par)\
    \ {\r\n            dfs1(ver, e);\r\n            odd_child[ver] += subtree[e] %\
    \ 2;\r\n            subtree[ver] += subtree[e];\r\n          }\r\n        }\r\n\
    \      };\r\n      dfs1(-1, 0);\r\n      std::function<void(int, int, int)> dfs2\
    \ = [&ans, &vers, &bc, sz, &bctree, &subtree, &odd_child, &dfs2](int par, int\
    \ ver, int tmp) -> void {\r\n        if (ver >= sz && odd_child[ver] == 0 && tmp\
    \ % 2 == 0) ans[vers[bc.ap[ver - sz]]] = true;\r\n        for (int e : bctree[ver])\
    \ {\r\n          if (e != par) dfs2(ver, e, tmp + subtree[ver] - subtree[e]);\r\
    \n        }\r\n      };\r\n      dfs2(-1, 0, 0);\r\n    }\r\n  }\r\n  for (bool\
    \ e : ans) std::cout << (e ? \"OK\\n\" : \"NG\\n\");\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/union-find/union-find.hpp
  - graph/edge.hpp
  - graph/biconnected_component.hpp
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/graph/biconnected_component.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/biconnected_component.test.cpp
layout: document
redirect_from:
- /verify/test/graph/biconnected_component.test.cpp
- /verify/test/graph/biconnected_component.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
