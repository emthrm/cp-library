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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
      \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\
      \u53CD\u5FA9\u6CD5\u7248 (solve(s, t))"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp: line 6: #pragma once\
    \ found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
    \u5FA9\u6CD5\u7248 (solve(s, t))\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <iterator>\n#include <vector>\n\
    \n#include \"../../../../graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n), b(n), v;\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i] >> b[i];\n    v.emplace_back(a[i]);\n\
    \    v.emplace_back(b[i]);\n  }\n  std::sort(v.begin(), v.end());\n  v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n  const int m = v.size();\n  for (int i = 0; i < n; ++i)\
    \ {\n    a[i] = std::distance(v.begin(), std::lower_bound(v.begin(), v.end(),\
    \ a[i]));\n    b[i] = std::distance(v.begin(), std::lower_bound(v.begin(), v.end(),\
    \ b[i]));\n  }\n  MinimumCostSTFlow<int, long long> minimum_cost_flow(n + m +\
    \ 2);\n  const int s = n + m, t = n + m + 1;\n  for (int i = 0; i < n; ++i) {\n\
    \    minimum_cost_flow.add_edge(s, i, 1, 0);\n    minimum_cost_flow.add_edge(i,\
    \ n + a[i], 1, -v[b[i]]);\n    minimum_cost_flow.add_edge(i, n + b[i], 1, -v[a[i]]);\n\
    \  }\n  for (int i = 0; i < m; ++i) {\n    minimum_cost_flow.add_edge(n + i, t,\
    \ 1, 0);\n  }\n  std::cout << -minimum_cost_flow.solve(s, t) << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.2.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.2.test.cpp
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.2.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
  \u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5\
  \u7248 (solve(s, t))"
---
