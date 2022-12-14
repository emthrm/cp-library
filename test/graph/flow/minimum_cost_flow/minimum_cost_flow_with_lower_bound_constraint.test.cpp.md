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
    path: graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
    \u6D41\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <limits>\n#include <vector>\n\
    \n#include \"../../../../graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp\"\
    \n#include \"../../../../graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp\"\
    \n#include \"../../../../graph/edge.hpp\"\n\nint main() {\n  constexpr int INF\
    \ = std::numeric_limits<int>::max();\n  int n, m;\n  std::cin >> n >> m;\n  MinimumCostFlowWithLowerBoundConstraint<\n\
    \      MinimumCostBFlow, long long, long long> lower_bound_constraint(n, INF);\n\
    \  std::vector<std::vector<Edge<int>>> graph(n);\n  while (m--) {\n    int x,\
    \ y, s;\n    std::cin >> x >> y >> s;\n    lower_bound_constraint.add_edge(y,\
    \ x, 1, INF, -s);\n    graph[x].emplace_back(x, y, s);\n  }\n  std::vector<long\
    \ long> dp(n, 0);\n  for (int i = n - 2; i >= 0; --i) {\n    for (const Edge<int>&\
    \ e : graph[i]) {\n      dp[i] = std::max(dp[i], dp[e.dst] + e.cost);\n    }\n\
    \  }\n  lower_bound_constraint.add_edge(0, n - 1, 0, INF, dp[0]);\n  std::cout\
    \ << lower_bound_constraint.solve(0, 0, 0) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
  - graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_lower_bound_constraint.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
  \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
---
