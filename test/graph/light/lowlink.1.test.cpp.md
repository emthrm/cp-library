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
  bundledCode: "#line 1 \"test/graph/light/lowlink.1.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <tuple>\r\n#include <utility>\r\
    \n#include <vector>\r\n#line 5 \"graph/light/lowlink.hpp\"\n\r\nstruct Lowlink\
    \ {\r\n  std::vector<std::vector<int>> graph;\r\n  std::vector<int> ap;\r\n  std::vector<std::pair<int,\
    \ int>> bridge;\r\n\r\n  Lowlink(const std::vector<std::vector<int>> &graph) :\
    \ graph(graph) {\r\n    int n = graph.size();\r\n    order.assign(n, -1);\r\n\
    \    lowlink.resize(n);\r\n    int tm = 0;\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n      if (order[i] == -1) dfs(-1, i, tm);\r\n    }\r\n    // std::sort(ap.begin(),\
    \ ap.end());\r\n    // std::sort(bridge.begin(), bridge.end(), [](const pair<int,\
    \ int> &a, const pair<int, int> &b) -> bool {\r\n    //   int as, ad, bs, bd;\r\
    \n    //   std::tie(as, ad) = a;\r\n    //   std::tie(bs, bd) = b;\r\n    // \
    \  return as != bs ? as < bs : ad < bd;\r\n    // });\r\n  }\r\n\r\n  std::vector<int>\
    \ order, lowlink;\r\nprivate:\r\n  void dfs(int par, int ver, int &tm) {\r\n \
    \   order[ver] = lowlink[ver] = tm++;\r\n    int cnt = 0;\r\n    bool is_ap =\
    \ false;\r\n    for (int e : graph[ver]) {\r\n      if (order[e] == -1) {\r\n\
    \        ++cnt;\r\n        dfs(ver, e, tm);\r\n        if (lowlink[e] < lowlink[ver])\
    \ lowlink[ver] = lowlink[e];\r\n        if (order[ver] <= lowlink[e]) {\r\n  \
    \        is_ap = true;\r\n          if (order[ver] < lowlink[e]) bridge.emplace_back(std::minmax(ver,\
    \ e));\r\n        }\r\n      } else if (e != par) {\r\n        if (order[e] <\
    \ lowlink[ver]) lowlink[ver] = order[e];\r\n      }\r\n    }\r\n    if (par ==\
    \ -1) {\r\n      if (cnt >= 2) ap.emplace_back(ver);\r\n    } else {\r\n     \
    \ if (is_ap) ap.emplace_back(ver);\r\n    }\r\n  }\r\n};\r\n#line 9 \"test/graph/light/lowlink.1.test.cpp\"\
    \n\r\nint main() {\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<int>>\
    \ graph(v);\r\n  while (e--) {\r\n    int s, t;\r\n    std::cin >> s >> t;\r\n\
    \    graph[s].emplace_back(t);\r\n    graph[t].emplace_back(s);\r\n  }\r\n  Lowlink\
    \ low(graph);\r\n  std::sort(low.bridge.begin(), low.bridge.end(), [](const std::pair<int,\
    \ int> &a, const std::pair<int, int> &b) -> bool {\r\n    int as, ad; std::tie(as,\
    \ ad) = a;\r\n    int bs, bd; std::tie(bs, bd) = b;\r\n    return as != bs ? as\
    \ < bs : ad < bd;\r\n  });\r\n  for (const std::pair<int, int> &e : low.bridge)\
    \ std::cout << e.first << ' ' << e.second << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <tuple>\r\n#include\
    \ <utility>\r\n#include <vector>\r\n#include \"../../../graph/light/lowlink.hpp\"\
    \r\n\r\nint main() {\r\n  int v, e;\r\n  std::cin >> v >> e;\r\n  std::vector<std::vector<int>>\
    \ graph(v);\r\n  while (e--) {\r\n    int s, t;\r\n    std::cin >> s >> t;\r\n\
    \    graph[s].emplace_back(t);\r\n    graph[t].emplace_back(s);\r\n  }\r\n  Lowlink\
    \ low(graph);\r\n  std::sort(low.bridge.begin(), low.bridge.end(), [](const std::pair<int,\
    \ int> &a, const std::pair<int, int> &b) -> bool {\r\n    int as, ad; std::tie(as,\
    \ ad) = a;\r\n    int bs, bd; std::tie(bs, bd) = b;\r\n    return as != bs ? as\
    \ < bs : ad < bd;\r\n  });\r\n  for (const std::pair<int, int> &e : low.bridge)\
    \ std::cout << e.first << ' ' << e.second << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/light/lowlink.1.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/light/lowlink.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/lowlink.1.test.cpp
- /verify/test/graph/light/lowlink.1.test.cpp.html
title: test/graph/light/lowlink.1.test.cpp
---
