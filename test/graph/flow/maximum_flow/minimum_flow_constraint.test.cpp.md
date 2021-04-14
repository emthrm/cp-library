---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/flow/maximum_flow/dinic.hpp
    title: "Dinic \u6CD5"
  - icon: ':heavy_check_mark:'
    path: graph/flow/maximum_flow/maximum_flow_with_minimum_flow_constraint.hpp
    title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\
      \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/maximum_flow/dinic.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41\
    /\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41\r\n */\r\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../../graph/flow/maximum_flow/dinic.hpp\"\
    \r\n#include \"../../../../graph/flow/maximum_flow/maximum_flow_with_minimum_flow_constraint.hpp\"\
    \r\n\r\nint main() {\r\n  while (true) {\r\n    int n, m;\r\n    std::cin >> n\
    \ >> m;\r\n    if (n == 0 && m == 0) break;\r\n    std::vector<int> u(m), v(m);\r\
    \n    for (int i = 0; i < m; ++i) {\r\n      std::cin >> u[i] >> v[i];\r\n   \
    \   --u[i]; --v[i];\r\n    }\r\n    const int s = m + n, t = m + n + 1;\r\n  \
    \  auto solve = [&](int lb, int ub) -> bool {\r\n      MaximumFlowWithMinimumFlowConstraint<Dinic,\
    \ int> mfmfc(m + n + 2);\r\n      for (int i = 0; i < m; ++i) mfmfc.add_edge(s,\
    \ i, 1, 1);\r\n      for (int i = 0; i < n; ++i) mfmfc.add_edge(m + i, t, lb,\
    \ ub);\r\n      for (int i = 0; i < m; ++i) {\r\n        mfmfc.add_edge(i, m +\
    \ u[i], 0, 1);\r\n        mfmfc.add_edge(i, m + v[i], 0, 1);\r\n      }\r\n  \
    \    return mfmfc.solve(s, t, m) != -1;\r\n    };\r\n    int lb = 0, ub = n, j\
    \ = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      while (j <= n && !solve(i,\
    \ j)) ++j;\r\n      if (j > n) break;\r\n      if (ub - lb >= j - i) {\r\n   \
    \     lb = i;\r\n        ub = j;\r\n      }\r\n      if (i == j) ++j;\r\n    }\r\
    \n    std::cout << lb << ' ' << ub << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/maximum_flow/dinic.hpp
  - graph/flow/maximum_flow/maximum_flow_with_minimum_flow_constraint.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp
  requiredBy: []
  timestamp: '2021-03-15 22:46:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp
- /verify/test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\u5C0F\u6D41\
  \u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
---
