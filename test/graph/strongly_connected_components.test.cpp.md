---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206 (strongly connected components) \u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    document_title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"../../graph/edge.hpp\"\n#include \"../../graph/strongly_connected_components.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(n);\n  while (m--) {\n    int a, b;\n    std::cin >> a >> b;\n    graph[a].emplace_back(a,\
    \ b);\n  }\n  const std::vector<std::vector<int>> ans =\n      StronglyConnectedComponents<bool>(graph,\
    \ true).vertices;\n  const int k = ans.size();\n  std::cout << k << '\\n';\n \
    \ for (int i = 0; i < k; ++i) {\n    const int l = ans[i].size();\n    std::cout\
    \ << l << ' ';\n    for (int j = 0; j < l; ++j) {\n      std::cout << ans[i][j]\
    \ << \" \\n\"[j + 1 == l];\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/graph/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/graph/strongly_connected_components.test.cpp
- /verify/test/graph/strongly_connected_components.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
