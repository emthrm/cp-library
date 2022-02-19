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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n\r\n#include \"../../graph/edge.hpp\"\r\n\
    #include \"../../graph/strongly_connected_components.hpp\"\r\n\r\nint main() {\r\
    \n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(n);\r\n  while (m--) {\r\n    int a, b;\r\n    std::cin >> a >> b;\r\n\
    \    graph[a].emplace_back(a, b);\r\n  }\r\n  const std::vector<std::vector<int>>\
    \ ans =\r\n      StronglyConnectedComponents<bool>(graph, true).vertices;\r\n\
    \  const int k = ans.size();\r\n  std::cout << k << '\\n';\r\n  for (int i = 0;\
    \ i < k; ++i) {\r\n    const int l = ans[i].size();\r\n    std::cout << l << '\
    \ ';\r\n    for (int j = 0; j < l; ++j) {\r\n      std::cout << ans[i][j] << \"\
    \ \\n\"[j + 1 == l];\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/graph/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 23:25:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/graph/strongly_connected_components.test.cpp
- /verify/test/graph/strongly_connected_components.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
