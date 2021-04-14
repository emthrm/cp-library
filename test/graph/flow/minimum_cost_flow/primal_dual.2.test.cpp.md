---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/flow/minimum_cost_flow/primal_dual.hpp
    title: "\u4E3B\u53CC\u5BFE\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
      \u6D41/\u4E3B\u53CC\u5BFE\u6CD5 (minimum_cost_flow(s, t))"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/primal_dual.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u4E3B\u53CC\u5BFE\u6CD5 (minimum_cost_flow(s, t))\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2293\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n#include <vector>\r\
    \n#include \"../../../../graph/flow/minimum_cost_flow/primal_dual.hpp\"\r\n\r\n\
    int main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n), b(n),\
    \ v;\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> a[i] >> b[i];\r\n \
    \   v.emplace_back(a[i]);\r\n    v.emplace_back(b[i]);\r\n  }\r\n  std::sort(v.begin(),\
    \ v.end());\r\n  v.erase(std::unique(v.begin(), v.end()), v.end());\r\n  int m\
    \ = v.size();\r\n  PrimalDual<int, long long> pd(n + m + 2);\r\n  const int s\
    \ = n + m, t = n + m + 1;\r\n  for (int i = 0; i < n; ++i) {\r\n    pd.add_edge(s,\
    \ i, 1, 0);\r\n    pd.add_edge(i, n + std::distance(v.begin(), std::lower_bound(v.begin(),\
    \ v.end(), a[i])), 1, -b[i]);\r\n    pd.add_edge(i, n + std::distance(v.begin(),\
    \ std::lower_bound(v.begin(), v.end(), b[i])), 1, -a[i]);\r\n  }\r\n  for (int\
    \ i = 0; i < m; ++i) pd.add_edge(n + i, t, 1, 0);\r\n  std::cout << -pd.minimum_cost_flow(s,\
    \ t) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/minimum_cost_flow/primal_dual.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/primal_dual.2.test.cpp
  requiredBy: []
  timestamp: '2021-03-15 23:38:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/minimum_cost_flow/primal_dual.2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/minimum_cost_flow/primal_dual.2.test.cpp
- /verify/test/graph/flow/minimum_cost_flow/primal_dual.2.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u4E3B\
  \u53CC\u5BFE\u6CD5 (minimum_cost_flow(s, t))"
---
