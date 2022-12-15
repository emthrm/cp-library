---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/dinic.hpp
    title: "Dinic \u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/flow/maximum_flow/project_selection_problem.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/flow/maximum_flow/dinic.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/project\
    \ selection problem\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"emthrm/graph/flow/maximum_flow/dinic.hpp\"\
    \n#include \"emthrm/graph/flow/maximum_flow/project_selection_problem.hpp\"\n\n\
    int main() {\n  int r, c;\n  std::cin >> r >> c;\n  std::vector<std::string> s(r);\n\
    \  for (int i = 0; i < r; ++i) {\n    std::cin >> s[i];\n  }\n  std::vector<std::vector<int>>\
    \ id(r, std::vector<int>(c, -1));\n  int n = 0;\n  for (int i = 0; i < r; ++i)\
    \ {\n    for (int j = 0; j < c; ++j) {\n      if (s[i][j] == '#') id[i][j] = n++;\n\
    \    }\n  }\n  emthrm::ProjectSelectionProblem<emthrm::Dinic, int>\n      project_selection_problem(n);\n\
    \  for (int i = 0; i < r; ++i) {\n    for (int j = 0; j < c; ++j) {\n      if\
    \ (id[i][j] == -1) continue;\n      if (i + 1 < r && id[i + 1][j] != -1) {\n \
    \       project_selection_problem.add_eq(id[i][j], id[i + 1][j], 0, -1);\n   \
    \   }\n      if (j + 1 < c && id[i][j + 1] != -1) {\n        project_selection_problem.add_eq(id[i][j],\
    \ id[i][j + 1], 1, -1);\n      }\n    }\n  }\n  std::cout << n + project_selection_problem.solve()\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/maximum_flow/dinic.hpp
  - include/emthrm/graph/flow/maximum_flow/project_selection_problem.hpp
  isVerificationFile: true
  path: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
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
