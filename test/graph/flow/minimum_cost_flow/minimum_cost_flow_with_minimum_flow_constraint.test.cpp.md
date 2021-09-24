---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $\\boldsymbol{b}$-\u30D5\u30ED\u30FC \u6700\u77ED\
      \u8DEF\u53CD\u5FA9\u6CD5\u7248"
  - icon: ':heavy_check_mark:'
    path: graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp
    title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
      \u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
      \u6D41/\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
      \u6D41"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
    \u6D41\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230\"\
    \r\n\r\n#include <iostream>\r\n#include <limits>\r\n#include <vector>\r\n#include\
    \ \"../../../../graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp\"\r\n#include\
    \ \"../../../../graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp\"\
    \r\n#include \"../../../../graph/edge.hpp\"\r\n\r\nint main() {\r\n  constexpr\
    \ int INF = std::numeric_limits<int>::max();\r\n  int n, m;\r\n  std::cin >> n\
    \ >> m;\r\n  MinimumCostFlowWithMinimumFlowConstraint<MinimumCostBFlow, long long,\
    \ long long> pd(n, INF);\r\n  std::vector<std::vector<Edge<int>>> graph(n);\r\n\
    \  while (m--) {\r\n    int x, y, s;\r\n    std::cin >> x >> y >> s;\r\n    pd.add_edge(y,\
    \ x, 1, INF, -s);\r\n    graph[x].emplace_back(x, y, s);\r\n  }\r\n  std::vector<long\
    \ long> dp(n, 0);\r\n  for (int i = n - 2; i >= 0; --i) {\r\n    for (const Edge<int>\
    \ &e : graph[i]) {\r\n      if (dp[e.dst] + e.cost > dp[i]) dp[i] = dp[e.dst]\
    \ + e.cost;\r\n    }\r\n  }\r\n  pd.add_edge(0, n - 1, 0, INF, dp[0]);\r\n  std::cout\
    \ << pd.solve(0, 0, 0) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
  - graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp
  requiredBy: []
  timestamp: '2021-04-20 11:12:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
  \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
---
