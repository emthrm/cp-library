---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/2-sat.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    document_title: "\u305D\u306E\u4ED6/2-SAT"
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/misc/2-sat.test.cpp\"\n/*\r\n * @brief \u305D\u306E\
    \u4ED6/2-SAT\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n\
    #line 2 \"misc/2-sat.hpp\"\n#include <algorithm>\r\n#line 4 \"misc/2-sat.hpp\"\
    \n\r\nstruct TwoSat {\r\n  explicit TwoSat(const int n)\r\n      : n(n), graph(n\
    \ << 1), rgraph(n << 1), is_visited(n << 1), ids(n << 1) {\r\n    order.reserve(n\
    \ << 1);\r\n  }\r\n\r\n  int negate(const int x) const { return (n + x) % (n <<\
    \ 1); }\r\n\r\n  void add_or(const int x, const int y) {\r\n    graph[negate(x)].emplace_back(y);\r\
    \n    graph[negate(y)].emplace_back(x);\r\n    rgraph[y].emplace_back(negate(x));\r\
    \n    rgraph[x].emplace_back(negate(y));\r\n  }\r\n\r\n  void add_if(const int\
    \ x, const int y) { add_or(negate(x), y); }\r\n\r\n  void add_nand(const int x,\
    \ const int y) { add_or(negate(x), negate(y)); }\r\n\r\n  void set_true(const\
    \ int x) { add_or(x, x); }\r\n\r\n  void set_false(const int x) { set_true(negate(x));\
    \ }\r\n\r\n  std::vector<bool> build() {\r\n    std::fill(is_visited.begin(),\
    \ is_visited.end(), false);\r\n    std::fill(ids.begin(), ids.end(), -1);\r\n\
    \    order.clear();\r\n    for (int i = 0; i < (n << 1); ++i) {\r\n      if (!is_visited[i])\
    \ dfs(i);\r\n    }\r\n    for (int i = (n << 1) - 1, id = 0; i >= 0; --i) {\r\n\
    \      if (ids[order[i]] == -1) rdfs(order[i], id++);\r\n    }\r\n    std::vector<bool>\
    \ res(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (ids[i] == ids[negate(i)])\
    \ return {};\r\n      res[i] = ids[negate(i)] < ids[i];\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n private:\r\n  const int n;\r\n  std::vector<std::vector<int>>\
    \ graph, rgraph;\r\n  std::vector<bool> is_visited;\r\n  std::vector<int> ids,\
    \ order;\r\n\r\n  void dfs(const int ver) {\r\n    is_visited[ver] = true;\r\n\
    \    for (const int dst : graph[ver]) {\r\n      if (!is_visited[dst]) dfs(dst);\r\
    \n    }\r\n    order.emplace_back(ver);\r\n  }\r\n\r\n  void rdfs(const int ver,\
    \ const int cur_id) {\r\n    ids[ver] = cur_id;\r\n    for (const int dst : rgraph[ver])\
    \ {\r\n      if (ids[dst] == -1) rdfs(dst, cur_id);\r\n    }\r\n  }\r\n};\r\n\
    #line 11 \"test/misc/2-sat.test.cpp\"\n\r\nint main() {\r\n  std::string p, cnf;\r\
    \n  int n, m;\r\n  std::cin >> p >> cnf >> n >> m;\r\n  TwoSat two_sat(n);\r\n\
    \  while (m--) {\r\n    int a, b, zero;\r\n    std::cin >> a >> b >> zero;\r\n\
    \    if (a < 0) {\r\n      a = two_sat.negate(-a - 1);\r\n    } else {\r\n   \
    \   --a;\r\n    }\r\n    if (b < 0) {\r\n      b = two_sat.negate(-b - 1);\r\n\
    \    } else {\r\n      --b;\r\n    }\r\n    two_sat.add_or(a, b);\r\n  }\r\n \
    \ const std::vector<bool> ans = two_sat.build();\r\n  std::cout << \"s \";\r\n\
    \  if (ans.empty()) {\r\n    std::cout << \"UNSATISFIABLE\\n\";\r\n    return\
    \ 0;\r\n  }\r\n  std::cout << \"SATISFIABLE\\nv \";\r\n  for (int i = 0; i < n;\
    \ ++i) {\r\n    std::cout << (i + 1) * (ans[i] ? 1 : -1) << ' ';\r\n  }\r\n  std::cout\
    \ << \"0\\n\";\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/2-SAT\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n\r\n\
    #include \"../../misc/2-sat.hpp\"\r\n\r\nint main() {\r\n  std::string p, cnf;\r\
    \n  int n, m;\r\n  std::cin >> p >> cnf >> n >> m;\r\n  TwoSat two_sat(n);\r\n\
    \  while (m--) {\r\n    int a, b, zero;\r\n    std::cin >> a >> b >> zero;\r\n\
    \    if (a < 0) {\r\n      a = two_sat.negate(-a - 1);\r\n    } else {\r\n   \
    \   --a;\r\n    }\r\n    if (b < 0) {\r\n      b = two_sat.negate(-b - 1);\r\n\
    \    } else {\r\n      --b;\r\n    }\r\n    two_sat.add_or(a, b);\r\n  }\r\n \
    \ const std::vector<bool> ans = two_sat.build();\r\n  std::cout << \"s \";\r\n\
    \  if (ans.empty()) {\r\n    std::cout << \"UNSATISFIABLE\\n\";\r\n    return\
    \ 0;\r\n  }\r\n  std::cout << \"SATISFIABLE\\nv \";\r\n  for (int i = 0; i < n;\
    \ ++i) {\r\n    std::cout << (i + 1) * (ans[i] ? 1 : -1) << ' ';\r\n  }\r\n  std::cout\
    \ << \"0\\n\";\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - misc/2-sat.hpp
  isVerificationFile: true
  path: test/misc/2-sat.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/2-sat.test.cpp
layout: document
redirect_from:
- /verify/test/misc/2-sat.test.cpp
- /verify/test/misc/2-sat.test.cpp.html
title: "\u305D\u306E\u4ED6/2-SAT"
---
