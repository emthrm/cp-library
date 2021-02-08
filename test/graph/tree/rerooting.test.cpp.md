---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tree/rerooting.hpp
    title: "\u6728\u306E\u76F4\u5F84 \u5168\u65B9\u4F4D\u6728 DP \u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u6728\u306E\u76F4\u5F84 \u5168\u65B9\
      \u4F4D\u6728 DP \u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/\u6728\u306E\u76F4\u5F84 \u5168\
    \u65B9\u4F4D\u6728 DP \u7248\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../graph/edge.hpp\"\
    \r\n#include \"../../../graph/tree/rerooting.hpp\"\r\n\r\nint main() {\r\n  int\
    \ n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<Edge<long long>>> graph(n);\r\
    \n  for (int i = 0; i < n - 1; ++i) {\r\n    int s, t, w;\r\n    std::cin >> s\
    \ >> t >> w;\r\n    graph[s].emplace_back(s, t, w);\r\n    graph[t].emplace_back(t,\
    \ s, w);\r\n  }\r\n  std::cout << rerooting(graph) << '\\n';\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/tree/rerooting.hpp
  isVerificationFile: true
  path: test/graph/tree/rerooting.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/rerooting.test.cpp
- /verify/test/graph/tree/rerooting.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u6728\u306E\u76F4\u5F84 \u5168\u65B9\u4F4D\u6728\
  \ DP \u7248"
---
