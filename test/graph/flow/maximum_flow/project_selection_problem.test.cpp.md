---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/flow/maximum_flow/dinic.hpp
    title: "Dinic \u6CD5"
  - icon: ':heavy_check_mark:'
    path: graph/flow/maximum_flow/project_selection_problem.hpp
    title: project selection problem
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/project\
      \ selection problem"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/maximum_flow/dinic.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41\
    /project selection problem\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n#include\
    \ \"../../../../graph/flow/maximum_flow/dinic.hpp\"\r\n#include \"../../../../graph/flow/maximum_flow/project_selection_problem.hpp\"\
    \r\n\r\nint main() {\r\n  int r, c;\r\n  std::cin >> r >> c;\r\n  std::vector<std::string>\
    \ s(r);\r\n  for (int i = 0; i < r; ++i) std::cin >> s[i];\r\n  std::vector<std::vector<int>>\
    \ idx(r, std::vector<int>(c, -1));\r\n  int n = 0;\r\n  for (int i = 0; i < r;\
    \ ++i) for (int j = 0; j < c; ++j) {\r\n    if (s[i][j] == '#') idx[i][j] = n++;\r\
    \n  }\r\n  ProjectSelectionProblem<Dinic, int> psp(n);\r\n  for (int i = 0; i\
    \ < r; ++i) for (int j = 0; j < c; ++j) {\r\n    if (idx[i][j] == -1) continue;\r\
    \n    if (i + 1 < r && idx[i + 1][j] != -1) psp.add_eq(idx[i][j], idx[i + 1][j],\
    \ 0, -1);\r\n    if (j + 1 < c && idx[i][j + 1] != -1) psp.add_eq(idx[i][j], idx[i][j\
    \ + 1], 1, -1);\r\n  }\r\n  std::cout << n + psp.solve() << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/maximum_flow/dinic.hpp
  - graph/flow/maximum_flow/project_selection_problem.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
  requiredBy: []
  timestamp: '2021-03-15 22:46:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/maximum_flow/project_selection_problem.test.cpp
- /verify/test/graph/flow/maximum_flow/project_selection_problem.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/project selection\
  \ problem"
---
