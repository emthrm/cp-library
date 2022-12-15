---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/dinic.hpp
    title: "Dinic \u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/flow/maximum_flow/dinic.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\
    \u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/graph/flow/maximum_flow/dinic.hpp\"\
    \n#include \"emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp\"\
    \n\nint main() {\n  while (true) {\n    int n, m;\n    std::cin >> n >> m;\n \
    \   if (n == 0 && m == 0) break;\n    std::vector<int> u(m), v(m);\n    for (int\
    \ i = 0; i < m; ++i) {\n      std::cin >> u[i] >> v[i];\n      --u[i]; --v[i];\n\
    \    }\n    const int s = m + n, t = m + n + 1;\n    const auto solve =\n    \
    \    [m, n, s, t, &u, &v](const int lb, const int ub) -> bool {\n          emthrm::MaximumFlowWithLowerBoundConstraint<emthrm::Dinic,\
    \ int>\n              lower_bound_constraint(m + n + 2);\n          for (int i\
    \ = 0; i < m; ++i) {\n            lower_bound_constraint.add_edge(s, i, 1, 1);\n\
    \          }\n          for (int i = 0; i < n; ++i) {\n            lower_bound_constraint.add_edge(m\
    \ + i, t, lb, ub);\n          }\n          for (int i = 0; i < m; ++i) {\n   \
    \         lower_bound_constraint.add_edge(i, m + u[i], 0, 1);\n            lower_bound_constraint.add_edge(i,\
    \ m + v[i], 0, 1);\n          }\n          return lower_bound_constraint.solve(s,\
    \ t) != -1;\n        };\n    int lb = 0, ub = n;\n    for (int i = 0, j = 1; i\
    \ < n; ++i) {\n      while (j <= n && !solve(i, j)) ++j;\n      if (j > n) break;\n\
    \      if (ub - lb >= j - i) {\n        lb = i;\n        ub = j;\n      }\n  \
    \    if (i == j) ++j;\n    }\n    std::cout << lb << ' ' << ub << '\\n';\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/maximum_flow/dinic.hpp
  - include/emthrm/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp
- /verify/test/graph/flow/maximum_flow/maximum_flow_with_lower_bound_constraint.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\u5C0F\u6D41\
  \u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
---
