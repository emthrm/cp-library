---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: misc/2-sat.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    document_title: "\u305D\u306E\u4ED6/2-SAT"
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/misc/2-sat.test.cpp\"\n/*\n * @brief \u305D\u306E\u4ED6\
    /2-SAT\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n\n#line 2 \"misc/2-sat.hpp\"\
    \n#include <algorithm>\n#line 4 \"misc/2-sat.hpp\"\n\nstruct TwoSat {\n  explicit\
    \ TwoSat(const int n)\n      : n(n), graph(n << 1), rgraph(n << 1), is_visited(n\
    \ << 1), ids(n << 1) {\n    order.reserve(n << 1);\n  }\n\n  int negate(const\
    \ int x) const { return (n + x) % (n << 1); }\n\n  void add_or(const int x, const\
    \ int y) {\n    graph[negate(x)].emplace_back(y);\n    graph[negate(y)].emplace_back(x);\n\
    \    rgraph[y].emplace_back(negate(x));\n    rgraph[x].emplace_back(negate(y));\n\
    \  }\n\n  void add_if(const int x, const int y) { add_or(negate(x), y); }\n\n\
    \  void add_nand(const int x, const int y) { add_or(negate(x), negate(y)); }\n\
    \n  void set_true(const int x) { add_or(x, x); }\n\n  void set_false(const int\
    \ x) { set_true(negate(x)); }\n\n  std::vector<bool> build() {\n    std::fill(is_visited.begin(),\
    \ is_visited.end(), false);\n    std::fill(ids.begin(), ids.end(), -1);\n    order.clear();\n\
    \    for (int i = 0; i < (n << 1); ++i) {\n      if (!is_visited[i]) dfs(i);\n\
    \    }\n    for (int i = (n << 1) - 1, id = 0; i >= 0; --i) {\n      if (ids[order[i]]\
    \ == -1) rdfs(order[i], id++);\n    }\n    std::vector<bool> res(n);\n    for\
    \ (int i = 0; i < n; ++i) {\n      if (ids[i] == ids[negate(i)]) return {};\n\
    \      res[i] = ids[negate(i)] < ids[i];\n    }\n    return res;\n  }\n\n private:\n\
    \  const int n;\n  std::vector<std::vector<int>> graph, rgraph;\n  std::vector<bool>\
    \ is_visited;\n  std::vector<int> ids, order;\n\n  void dfs(const int ver) {\n\
    \    is_visited[ver] = true;\n    for (const int dst : graph[ver]) {\n      if\
    \ (!is_visited[dst]) dfs(dst);\n    }\n    order.emplace_back(ver);\n  }\n\n \
    \ void rdfs(const int ver, const int cur_id) {\n    ids[ver] = cur_id;\n    for\
    \ (const int dst : rgraph[ver]) {\n      if (ids[dst] == -1) rdfs(dst, cur_id);\n\
    \    }\n  }\n};\n#line 11 \"test/misc/2-sat.test.cpp\"\n\nint main() {\n  std::string\
    \ p, cnf;\n  int n, m;\n  std::cin >> p >> cnf >> n >> m;\n  TwoSat two_sat(n);\n\
    \  while (m--) {\n    int a, b, zero;\n    std::cin >> a >> b >> zero;\n    if\
    \ (a < 0) {\n      a = two_sat.negate(-a - 1);\n    } else {\n      --a;\n   \
    \ }\n    if (b < 0) {\n      b = two_sat.negate(-b - 1);\n    } else {\n     \
    \ --b;\n    }\n    two_sat.add_or(a, b);\n  }\n  const std::vector<bool> ans =\
    \ two_sat.build();\n  std::cout << \"s \";\n  if (ans.empty()) {\n    std::cout\
    \ << \"UNSATISFIABLE\\n\";\n    return 0;\n  }\n  std::cout << \"SATISFIABLE\\\
    nv \";\n  for (int i = 0; i < n; ++i) {\n    std::cout << (i + 1) * (ans[i] ?\
    \ 1 : -1) << ' ';\n  }\n  std::cout << \"0\\n\";\n  return 0;\n}\n"
  code: "/*\n * @brief \u305D\u306E\u4ED6/2-SAT\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../misc/2-sat.hpp\"\
    \n\nint main() {\n  std::string p, cnf;\n  int n, m;\n  std::cin >> p >> cnf >>\
    \ n >> m;\n  TwoSat two_sat(n);\n  while (m--) {\n    int a, b, zero;\n    std::cin\
    \ >> a >> b >> zero;\n    if (a < 0) {\n      a = two_sat.negate(-a - 1);\n  \
    \  } else {\n      --a;\n    }\n    if (b < 0) {\n      b = two_sat.negate(-b\
    \ - 1);\n    } else {\n      --b;\n    }\n    two_sat.add_or(a, b);\n  }\n  const\
    \ std::vector<bool> ans = two_sat.build();\n  std::cout << \"s \";\n  if (ans.empty())\
    \ {\n    std::cout << \"UNSATISFIABLE\\n\";\n    return 0;\n  }\n  std::cout <<\
    \ \"SATISFIABLE\\nv \";\n  for (int i = 0; i < n; ++i) {\n    std::cout << (i\
    \ + 1) * (ans[i] ? 1 : -1) << ' ';\n  }\n  std::cout << \"0\\n\";\n  return 0;\n\
    }\n"
  dependsOn:
  - misc/2-sat.hpp
  isVerificationFile: true
  path: test/misc/2-sat.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/2-sat.test.cpp
layout: document
redirect_from:
- /verify/test/misc/2-sat.test.cpp
- /verify/test/misc/2-sat.test.cpp.html
title: "\u305D\u306E\u4ED6/2-SAT"
---
