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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"test/graph/light/detect_bridge.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\r\n\r\n\
    #include <algorithm>\r\n#include <iostream>\r\n#include <tuple>\r\n#include <utility>\r\
    \n#include <vector>\r\n#line 3 \"graph/light/detect_bridge.hpp\"\n#include <functional>\r\
    \n// #include <tuple>\r\n#line 7 \"graph/light/detect_bridge.hpp\"\n\r\nstd::vector<std::pair<int,\
    \ int>> detect_bridge(const std::vector<std::vector<int>> &graph) {\r\n  int n\
    \ = graph.size();\r\n  std::vector<std::pair<int, int>> res;\r\n  std::vector<int>\
    \ depth(n, -1), imos(n, 0);\r\n  std::function<void(int, int)> dfs = [&graph,\
    \ &res, &depth, &imos, &dfs](int par, int ver) -> void {\r\n    bool multiedge\
    \ = false;\r\n    for (int e : graph[ver]) {\r\n      if (depth[e] == -1) {\r\n\
    \        depth[e] = depth[ver] + 1;\r\n        dfs(ver, e);\r\n        if (imos[e]\
    \ == 0) res.emplace_back(std::minmax(ver, e));\r\n        imos[ver] += imos[e];\r\
    \n      } else if (!multiedge && e == par) {\r\n        multiedge = true;\r\n\
    \      } else if (depth[e] < depth[ver]) {\r\n        ++imos[ver];\r\n       \
    \ --imos[e];\r\n      }\r\n    }\r\n  };\r\n  for (int i = 0; i < n; ++i) {\r\n\
    \    if (depth[i] == -1) {\r\n      depth[i] = 0;\r\n      dfs(-1, i);\r\n   \
    \ }\r\n  }\r\n  // std::sort(res.begin(), res.end(), [](const pair<int, int> &a,\
    \ const pair<int, int> &b) -> bool {\r\n  //   int as, ad, bs, bd;\r\n  //   std::tie(as,\
    \ ad) = a;\r\n  //   std::tie(bs, bd) = b;\r\n  //   return as != bs ? as < bs\
    \ : ad < bd;\r\n  // });\r\n  return res;\r\n}\r\n#line 9 \"test/graph/light/detect_bridge.test.cpp\"\
    \n\r\nint main() {\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<int>>\
    \ graph(v);\r\n  while (e--) {\r\n    int s, t;\r\n    std::cin >> s >> t;\r\n\
    \    graph[s].emplace_back(t);\r\n    graph[t].emplace_back(s);\r\n  }\r\n  std::vector<std::pair<int,\
    \ int>> bridges = detect_bridge(graph);\r\n  std::sort(bridges.begin(), bridges.end(),\
    \ [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {\r\n\
    \    int as, ad; std::tie(as, ad) = a;\r\n    int bs, bd; std::tie(bs, bd) = b;\r\
    \n    return as != bs ? as < bs : ad < bd;\r\n  });\r\n  for (const std::pair<int,\
    \ int> &e : bridges) std::cout << e.first << ' ' << e.second << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <tuple>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n#include \"../../../graph/light/detect_bridge.hpp\"\
    \r\n\r\nint main() {\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<int>>\
    \ graph(v);\r\n  while (e--) {\r\n    int s, t;\r\n    std::cin >> s >> t;\r\n\
    \    graph[s].emplace_back(t);\r\n    graph[t].emplace_back(s);\r\n  }\r\n  std::vector<std::pair<int,\
    \ int>> bridges = detect_bridge(graph);\r\n  std::sort(bridges.begin(), bridges.end(),\
    \ [](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool {\r\n\
    \    int as, ad; std::tie(as, ad) = a;\r\n    int bs, bd; std::tie(bs, bd) = b;\r\
    \n    return as != bs ? as < bs : ad < bd;\r\n  });\r\n  for (const std::pair<int,\
    \ int> &e : bridges) std::cout << e.first << ' ' << e.second << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/light/detect_bridge.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/light/detect_bridge.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/detect_bridge.test.cpp
- /verify/test/graph/light/detect_bridge.test.cpp.html
title: test/graph/light/detect_bridge.test.cpp
---
