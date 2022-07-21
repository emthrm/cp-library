---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\
      \u53CD\u5FA9\u6CD5\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
      \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\
      \u53CD\u5FA9\u6CD5\u7248 (solve(s, t, flow))"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp: line 6: #pragma once\
    \ found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
    \u5FA9\u6CD5\u7248 (solve(s, t, flow))\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include <iostream>\n\n#include \"../../../../graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\nint main() {\n  int v, e, f;\n  std::cin >> v >> e >> f;\n  MinimumCostSTFlow<int,\
    \ int> minimum_cost_flow(v);\n  while (e--) {\n    int u, v, c, d;\n    std::cin\
    \ >> u >> v >> c >> d;\n    minimum_cost_flow.add_edge(u, v, c, d);\n  }\n  const\
    \ int ans = minimum_cost_flow.solve(0, v - 1, f);\n  std::cout << (ans == minimum_cost_flow.uinf\
    \ ? -1 : ans) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
  \u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5\
  \u7248 (solve(s, t, flow))"
---
