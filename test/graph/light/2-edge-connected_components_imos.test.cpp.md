---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/graph/light/2-edge-connected_components_imos.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"graph/light/2-edge-connected_components_imos.hpp\"\
    \n// #include <algorithm>\r\n#include <set>\r\n#include <queue>\r\n#include <utility>\r\
    \n#line 2 \"graph/light/detect_bridge.hpp\"\n#include <algorithm>\r\n#include\
    \ <functional>\r\n// #include <tuple>\r\n#line 7 \"graph/light/detect_bridge.hpp\"\
    \n\r\nstd::vector<std::pair<int, int>> detect_bridge(const std::vector<std::vector<int>>\
    \ &graph) {\r\n  int n = graph.size();\r\n  std::vector<std::pair<int, int>> res;\r\
    \n  std::vector<int> depth(n, -1), imos(n, 0);\r\n  std::function<void(int, int)>\
    \ dfs = [&graph, &res, &depth, &imos, &dfs](int par, int ver) -> void {\r\n  \
    \  bool multiedge = false;\r\n    for (int e : graph[ver]) {\r\n      if (depth[e]\
    \ == -1) {\r\n        depth[e] = depth[ver] + 1;\r\n        dfs(ver, e);\r\n \
    \       if (imos[e] == 0) res.emplace_back(std::minmax(ver, e));\r\n        imos[ver]\
    \ += imos[e];\r\n      } else if (!multiedge && e == par) {\r\n        multiedge\
    \ = true;\r\n      } else if (depth[e] < depth[ver]) {\r\n        ++imos[ver];\r\
    \n        --imos[e];\r\n      }\r\n    }\r\n  };\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    if (depth[i] == -1) {\r\n      depth[i] = 0;\r\n      dfs(-1, i);\r\
    \n    }\r\n  }\r\n  // std::sort(res.begin(), res.end(), [](const pair<int, int>\
    \ &a, const pair<int, int> &b) -> bool {\r\n  //   int as, ad, bs, bd;\r\n  //\
    \   std::tie(as, ad) = a;\r\n  //   std::tie(bs, bd) = b;\r\n  //   return as\
    \ != bs ? as < bs : ad < bd;\r\n  // });\r\n  return res;\r\n}\r\n#line 8 \"graph/light/2-edge-connected_components_imos.hpp\"\
    \n\r\nstruct TwoEdgeConnectedComponentsImos {\r\n  std::vector<std::pair<int,\
    \ int>> bridge;\r\n  std::vector<int> id;\r\n  std::vector<std::vector<int>> vertices,\
    \ comp;\r\n\r\n  TwoEdgeConnectedComponentsImos(const std::vector<std::vector<int>>\
    \ &graph, bool heavy = false) : bridge(detect_bridge(graph)) {\r\n    int n =\
    \ graph.size();\r\n    id.assign(n, -1);\r\n    std::set<std::pair<int, int>>\
    \ st;\r\n    for (const std::pair<int, int> &e : bridge) {\r\n      st.emplace(e.first,\
    \ e.second);\r\n      st.emplace(e.second, e.first);\r\n    }\r\n    int now =\
    \ 0;\r\n    std::queue<int> que;\r\n    for (int i = 0; i < n; ++i) {\r\n    \
    \  if (id[i] != -1) continue;\r\n      que.emplace(i);\r\n      id[i] = now++;\r\
    \n      if (heavy) vertices.emplace_back(std::vector<int>{i});\r\n      while\
    \ (!que.empty()) {\r\n        int ver = que.front(); que.pop();\r\n        for\
    \ (int e : graph[ver]) {\r\n          if (id[e] == -1 && st.count({ver, e}) ==\
    \ 0) {\r\n            id[e] = id[i];\r\n            if (heavy) vertices[id[i]].emplace_back(e);\r\
    \n            que.emplace(e);\r\n          }\r\n        }\r\n      }\r\n    }\r\
    \n    comp.resize(now);\r\n    for (const std::pair<int, int> &e : bridge) {\r\
    \n      int u = id[e.first], v = id[e.second];\r\n      comp[u].emplace_back(v);\r\
    \n      comp[v].emplace_back(u);\r\n    }\r\n    // for (int i = 0; i < now; ++i)\
    \ std::sort(vertices[i].begin(), vertices[i].end());\r\n  }\r\n};\r\n#line 6 \"\
    test/graph/light/2-edge-connected_components_imos.test.cpp\"\n\r\nint main() {\r\
    \n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>> graph(n);\r\
    \n  while (m--) {\r\n    int a, b;\r\n    std::cin >> a >> b;\r\n    graph[a].emplace_back(b);\r\
    \n    graph[b].emplace_back(a);\r\n  }\r\n  TwoEdgeConnectedComponentsImos tecc(graph,\
    \ true);\r\n  int k = tecc.vertices.size();\r\n  std::cout << k << '\\n';\r\n\
    \  for (int i = 0; i < k; ++i) {\r\n    int l = tecc.vertices[i].size();\r\n \
    \   std::cout << l << ' ';\r\n    for (int j = 0; j < l; ++j) std::cout << tecc.vertices[i][j]\
    \ << \" \\n\"[j + 1 == l];\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../graph/light/2-edge-connected_components_imos.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  while (m--) {\r\n    int a, b;\r\n    std::cin >> a >> b;\r\n\
    \    graph[a].emplace_back(b);\r\n    graph[b].emplace_back(a);\r\n  }\r\n  TwoEdgeConnectedComponentsImos\
    \ tecc(graph, true);\r\n  int k = tecc.vertices.size();\r\n  std::cout << k <<\
    \ '\\n';\r\n  for (int i = 0; i < k; ++i) {\r\n    int l = tecc.vertices[i].size();\r\
    \n    std::cout << l << ' ';\r\n    for (int j = 0; j < l; ++j) std::cout << tecc.vertices[i][j]\
    \ << \" \\n\"[j + 1 == l];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/light/2-edge-connected_components_imos.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/light/2-edge-connected_components_imos.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/2-edge-connected_components_imos.test.cpp
- /verify/test/graph/light/2-edge-connected_components_imos.test.cpp.html
title: test/graph/light/2-edge-connected_components_imos.test.cpp
---
