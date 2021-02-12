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
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n#line\
    \ 3 \"misc/2-sat.hpp\"\n\r\nstruct TwoSat {\r\n  TwoSat(int n) : n(n), graph(n\
    \ << 1), rev_graph(n << 1) {}\r\n\r\n  int negate(int x) const { return (n + x)\
    \ % (n << 1); }\r\n\r\n  void add_or(int x, int y) {\r\n    graph[negate(x)].emplace_back(y);\r\
    \n    graph[negate(y)].emplace_back(x);\r\n    rev_graph[y].emplace_back(negate(x));\r\
    \n    rev_graph[x].emplace_back(negate(y));\r\n  }\r\n\r\n  void add_if(int x,\
    \ int y) { add_or(negate(x), y); }\r\n\r\n  void add_nand(int x, int y) { add_or(negate(x),\
    \ negate(y)); }\r\n\r\n  void set_true(int x) { add_or(x, x); }\r\n\r\n  void\
    \ set_false(int x) { set_true(negate(x)); }\r\n\r\n  std::vector<bool> build()\
    \ {\r\n    used.assign(n << 1, false);\r\n    id.assign(n << 1, -1);\r\n    order.clear();\r\
    \n    for (int i = 0; i < (n << 1); ++i) {\r\n      if (!used[i]) dfs(i);\r\n\
    \    }\r\n    int now = 0;\r\n    for (int i = (n << 1) - 1; i >= 0; --i) {\r\n\
    \      if (id[order[i]] == -1) rev_dfs(order[i], now++);\r\n    }\r\n    std::vector<bool>\
    \ res(n);\r\n    for (int i = 0; i < n; ++i) {\r\n      if (id[i] == id[negate(i)])\
    \ return {};\r\n      res[i] = id[negate(i)] < id[i];\r\n    }\r\n    return res;\r\
    \n  }\r\n\r\nprivate:\r\n  int n;\r\n  std::vector<std::vector<int>> graph, rev_graph;\r\
    \n  std::vector<bool> used;\r\n  std::vector<int> id, order;\r\n\r\n  void dfs(int\
    \ ver) {\r\n    used[ver] = true;\r\n    for (int e : graph[ver]) {\r\n      if\
    \ (!used[e]) dfs(e);\r\n    }\r\n    order.emplace_back(ver);\r\n  }\r\n\r\n \
    \ void rev_dfs(int ver, int now) {\r\n    id[ver] = now;\r\n    for (int e : rev_graph[ver])\
    \ {\r\n      if (id[e] == -1) rev_dfs(e, now);\r\n    }\r\n  }\r\n};\r\n#line\
    \ 10 \"test/misc/2-sat.test.cpp\"\n\r\nint main() {\r\n  std::string p, cnf;\r\
    \n  int n, m;\r\n  std::cin >> p >> cnf >> n >> m;\r\n  TwoSat ts(n);\r\n  while\
    \ (m--) {\r\n    int a, b, zero;\r\n    std::cin >> a >> b >> zero;\r\n    if\
    \ (a < 0) {\r\n      a = ts.negate(-a - 1);\r\n    } else {\r\n      --a;\r\n\
    \    }\r\n    if (b < 0) {\r\n      b = ts.negate(-b - 1);\r\n    } else {\r\n\
    \      --b;\r\n    }\r\n    ts.add_or(a, b);\r\n  }\r\n  std::vector<bool> ans\
    \ = ts.build();\r\n  std::cout << \"s \";\r\n  if (ans.empty()) {\r\n    std::cout\
    \ << \"UNSATISFIABLE\\n\";\r\n    return 0;\r\n  }\r\n  std::cout << \"SATISFIABLE\\\
    nv \";\r\n  for (int i = 0; i < n; ++i) std::cout << (i + 1) * (ans[i] ? 1 : -1)\
    \ << ' ';\r\n  std::cout << \"0\\n\";\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/2-SAT\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n#include\
    \ \"../../misc/2-sat.hpp\"\r\n\r\nint main() {\r\n  std::string p, cnf;\r\n  int\
    \ n, m;\r\n  std::cin >> p >> cnf >> n >> m;\r\n  TwoSat ts(n);\r\n  while (m--)\
    \ {\r\n    int a, b, zero;\r\n    std::cin >> a >> b >> zero;\r\n    if (a < 0)\
    \ {\r\n      a = ts.negate(-a - 1);\r\n    } else {\r\n      --a;\r\n    }\r\n\
    \    if (b < 0) {\r\n      b = ts.negate(-b - 1);\r\n    } else {\r\n      --b;\r\
    \n    }\r\n    ts.add_or(a, b);\r\n  }\r\n  std::vector<bool> ans = ts.build();\r\
    \n  std::cout << \"s \";\r\n  if (ans.empty()) {\r\n    std::cout << \"UNSATISFIABLE\\\
    n\";\r\n    return 0;\r\n  }\r\n  std::cout << \"SATISFIABLE\\nv \";\r\n  for\
    \ (int i = 0; i < n; ++i) std::cout << (i + 1) * (ans[i] ? 1 : -1) << ' ';\r\n\
    \  std::cout << \"0\\n\";\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - misc/2-sat.hpp
  isVerificationFile: true
  path: test/misc/2-sat.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 21:17:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/2-sat.test.cpp
layout: document
redirect_from:
- /verify/test/misc/2-sat.test.cpp
- /verify/test/misc/2-sat.test.cpp.html
title: "\u305D\u306E\u4ED6/2-SAT"
---
