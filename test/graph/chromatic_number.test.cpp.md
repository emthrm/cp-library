---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  - icon: ':heavy_check_mark:'
    path: graph/chromatic_number.hpp
    title: "\u5F69\u8272\u6570 (chromatic number)"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136
    document_title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u5F69\u8272\u6570\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136\"\r\n\r\n#include\
    \ <iostream>\r\n#include <vector>\r\n#include \"../../geometry/geometry.hpp\"\r\
    \n#include \"../../graph/edge.hpp\"\r\n#include \"../../graph/chromatic_number.hpp\"\
    \r\n\r\nint main() {\r\n  while (true) {\r\n    int n;\r\n    std::cin >> n;\r\
    \n    if (n == 0) break;\r\n    std::vector<std::vector<geometry::Segment>> line(n);\r\
    \n    for (int i = 0; i < n; ++i) {\r\n      int s;\r\n      std::cin >> s;\r\n\
    \      std::vector<int> x(s), y(s);\r\n      for (int j = 0; j < s; ++j) std::cin\
    \ >> x[j] >> y[j];\r\n      for (int j = 1; j < s; ++j) line[i].emplace_back(geometry::Point(x[j\
    \ - 1], y[j - 1]), geometry::Point(x[j], y[j]));\r\n    }\r\n    std::vector<std::vector<Edge<bool>>>\
    \ graph(n);\r\n    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j)\
    \ {\r\n      bool is_crossing = false;\r\n      for (int k = 0; k < line[i].size();\
    \ ++k) for (int l = 0; l < line[j].size(); ++l) {\r\n        is_crossing |= geometry::has_intersected(line[i][k],\
    \ line[j][l]);\r\n      }\r\n      if (is_crossing) {\r\n        graph[i].emplace_back(i,\
    \ j);\r\n        graph[j].emplace_back(j, i);\r\n      }\r\n    }\r\n    std::cout\
    \ << chromatic_number(graph) << '\\n';\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - geometry/geometry.hpp
  - graph/edge.hpp
  - graph/chromatic_number.hpp
  isVerificationFile: true
  path: test/graph/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/graph/chromatic_number.test.cpp
- /verify/test/graph/chromatic_number.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
---
