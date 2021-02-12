---
data:
  _extendedDependsOn: []
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
    links:
    - https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c
  bundledCode: "#line 1 \"test/graph/light/is_bipartite.test.cpp\"\n#define IGNORE\r\
    \n#define PROBLEM \"https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"graph/light/is_bipartite.hpp\"\
    \n#include <functional>\r\n#line 4 \"graph/light/is_bipartite.hpp\"\n\r\nbool\
    \ is_bipartite(const std::vector<std::vector<int>> &graph, std::vector<int> &color)\
    \ {\r\n  int n = graph.size();\r\n  color.assign(n, -1);\r\n  std::function<bool(int,\
    \ int)> dfs = [&graph, &color, &dfs](int ver, int now) -> bool {\r\n    color[ver]\
    \ = now;\r\n    for (int e : graph[ver]) {\r\n      if (color[e] == now || (color[e]\
    \ == -1 && !dfs(e, now ^ 1))) return false;\r\n    }\r\n    return true;\r\n \
    \ };\r\n  for (int i = 0; i < n; ++i) {\r\n    if (color[i] == -1 && !dfs(i, 0))\
    \ return false;\r\n  }\r\n  return true;\r\n}\r\n#line 7 \"test/graph/light/is_bipartite.test.cpp\"\
    \n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    int a, b;\r\n    std::cin\
    \ >> a >> b;\r\n    --a; --b;\r\n    graph[a].emplace_back(b);\r\n    graph[b].emplace_back(a);\r\
    \n  }\r\n  std::vector<int> color;\r\n  if (is_bipartite(graph, color)) {\r\n\
    \    int black = 0, white = 0;\r\n    for (int i = 0; i < n; ++i) ++(color[i]\
    \ == 1 ? black : white);\r\n    std::cout << static_cast<long long>(black) * white\
    \ - m << '\\n';\r\n  } else {\r\n    std::cout << static_cast<long long>(n) *\
    \ (n - 1) / 2 - m << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../graph/light/is_bipartite.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  for (int i = 0; i < m; ++i) {\r\n    int a, b;\r\n    std::cin\
    \ >> a >> b;\r\n    --a; --b;\r\n    graph[a].emplace_back(b);\r\n    graph[b].emplace_back(a);\r\
    \n  }\r\n  std::vector<int> color;\r\n  if (is_bipartite(graph, color)) {\r\n\
    \    int black = 0, white = 0;\r\n    for (int i = 0; i < n; ++i) ++(color[i]\
    \ == 1 ? black : white);\r\n    std::cout << static_cast<long long>(black) * white\
    \ - m << '\\n';\r\n  } else {\r\n    std::cout << static_cast<long long>(n) *\
    \ (n - 1) / 2 - m << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/light/is_bipartite.test.cpp
  requiredBy: []
  timestamp: '2021-02-11 00:27:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/light/is_bipartite.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/is_bipartite.test.cpp
- /verify/test/graph/light/is_bipartite.test.cpp.html
title: test/graph/light/is_bipartite.test.cpp
---
