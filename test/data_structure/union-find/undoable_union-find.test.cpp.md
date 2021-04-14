---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/union-find/undoable_union-find.hpp
    title: "undo \u53EF\u80FD union-find \u6728"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/is_bipartite.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
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
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/undo \u53EF\u80FD\
      \ union-find \u6728"
    links:
    - https://codeforces.com/contest/1444/problem/C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/undo \u53EF\
    \u80FD union-find \u6728\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://codeforces.com/contest/1444/problem/C\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n\
    #include <map>\r\n#include <queue>\r\n#include <set>\r\n#include <tuple>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n#include \"../../../graph/edge.hpp\"\r\n#include\
    \ \"../../../graph/is_bipartite.hpp\"\r\n#include \"../../../data_structure/union-find/undoable_union-find.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m, k;\r\n  std::cin >> n >> m >> k;\r\n  std::vector<int>\
    \ c(n);\r\n  std::vector<std::vector<int>> group(k);\r\n  for (int i = 0; i <\
    \ n; ++i) {\r\n    std::cin >> c[i];\r\n    --c[i];\r\n    group[c[i]].emplace_back(i);\r\
    \n  }\r\n  std::vector<std::vector<std::vector<Edge<bool>>>> subgraph(k);\r\n\
    \  for (int i = 0; i < k; ++i) subgraph[i].resize(group[i].size());\r\n  std::vector<int>\
    \ a(m), b(m);\r\n  std::vector<std::vector<int>> graph(n);\r\n  for (int i = 0;\
    \ i < m; ++i) {\r\n    std::cin >> a[i] >> b[i];\r\n    --a[i];\r\n    --b[i];\r\
    \n    graph[a[i]].emplace_back(b[i]);\r\n    graph[b[i]].emplace_back(a[i]);\r\
    \n    if (c[a[i]] == c[b[i]]) {\r\n      int g = c[a[i]];\r\n      int u = std::distance(group[g].begin(),\
    \ std::lower_bound(group[g].begin(), group[g].end(), a[i]));\r\n      int v =\
    \ std::distance(group[g].begin(), std::lower_bound(group[g].begin(), group[g].end(),\
    \ b[i]));\r\n      subgraph[g][u].emplace_back(u, v);\r\n      subgraph[g][v].emplace_back(v,\
    \ u);\r\n    }\r\n  }\r\n  std::set<int> bad_group;\r\n  std::map<std::pair<int,\
    \ int>, std::vector<std::pair<int, int>>> edges;\r\n  std::vector<int> color(n,\
    \ 0);\r\n  for (int i = 0; i < k; ++i) {\r\n    std::vector<int> color_i;\r\n\
    \    if (is_bipartite(subgraph[i], color_i)) {\r\n      for (int j = 0; j < group[i].size();\
    \ ++j) color[group[i][j]] = color_i[j];\r\n    } else {\r\n      bad_group.emplace(i);\r\
    \n    }\r\n  }\r\n  std::vector<int> id(n, -1), new_c;\r\n  std::map<std::tuple<int,\
    \ int, int>, int> mp;\r\n  n = 0;\r\n  for (int i = 0; i < k; ++i) {\r\n    if\
    \ (bad_group.count(i) == 1) continue;\r\n    int cur = 0;\r\n    for (int e :\
    \ group[i]) {\r\n      if (id[e] != -1) continue;\r\n      id[e] = cur;\r\n  \
    \    new_c.emplace_back(i);\r\n      new_c.emplace_back(i);\r\n      mp[{i, cur,\
    \ 0}] = n++;\r\n      mp[{i, cur, 1}] = n++;\r\n      std::queue<int> que({e});\r\
    \n      while (!que.empty()) {\r\n        int ver = que.front(); que.pop();\r\n\
    \        for (int dst : graph[ver]) {\r\n          if (c[dst] == i && id[dst]\
    \ == -1) {\r\n            id[dst] = cur;\r\n            que.emplace(dst);\r\n\
    \          }\r\n        }\r\n      }\r\n      ++cur;\r\n    }\r\n  }\r\n  for\
    \ (int i = 0; i < m; ++i) {\r\n    if (bad_group.count(c[a[i]]) == 1 || bad_group.count(c[b[i]])\
    \ == 1) continue;\r\n    int u = mp[{c[a[i]], id[a[i]], color[a[i]]}], v = mp[{c[b[i]],\
    \ id[b[i]], color[b[i]]}];\r\n    if (u > v) std::swap(u, v);\r\n    int u_group\
    \ = new_c[u], v_group = new_c[v];\r\n    if (u_group > v_group) std::swap(u_group,\
    \ v_group);\r\n    if (u_group < v_group) edges[{u_group, v_group}].emplace_back(u,\
    \ v);\r\n  }\r\n  UndoableUnionFind uf(n * 2);\r\n  for (int i = 0; i < n; i +=\
    \ 2) {\r\n    uf.unite(i * 2, (i + 1) * 2 + 1);\r\n    uf.unite(i * 2 + 1, (i\
    \ + 1) * 2);\r\n  }\r\n  uf.snap();\r\n  long long ans = static_cast<long long>(k\
    \ - bad_group.size()) * (k - bad_group.size() - 1) / 2;\r\n  for (auto it = edges.begin();\
    \ it != edges.end(); ++it) {\r\n    const std::vector<std::pair<int, int>> &edge\
    \ = it->second;\r\n    std::set<int> vers;\r\n    for (const std::pair<int, int>\
    \ &e : edge) {\r\n      int u, v; std::tie(u, v) = e;\r\n      uf.unite(u * 2,\
    \ v * 2 + 1);\r\n      uf.unite(u * 2 + 1, v * 2);\r\n      vers.emplace(u);\r\
    \n      vers.emplace(v);\r\n    }\r\n    bool is_bi = true;\r\n    for (int ver\
    \ : vers) is_bi &= !uf.same(ver * 2, ver * 2 + 1);\r\n    ans -= !is_bi;\r\n \
    \   uf.rollback();\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\
    \n"
  dependsOn:
  - graph/edge.hpp
  - graph/is_bipartite.hpp
  - data_structure/union-find/undoable_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/undoable_union-find.test.cpp
  requiredBy: []
  timestamp: '2021-02-11 04:31:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/union-find/undoable_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/undo \u53EF\u80FD union-find\
  \ \u6728"
---
