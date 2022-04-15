---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/detect_path.hpp
    title: "\u9053\u306E\u691C\u51FA"
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA"
    links:
    - https://atcoder.jp/contests/past202112-open/tasks/past202112_g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/detect_path.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA\r\n */\r\n#define\
    \ IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/past202112-open/tasks/past202112_g\"\
    \r\n\r\n#include <iostream>\r\n#include <iterator>\r\n#include <vector>\r\n\r\n\
    #include \"../../graph/detect_path.hpp\"\r\n#include \"../../graph/edge.hpp\"\r\
    \n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(n);\r\n  while (q--) {\r\n    int type, u, v;\r\n    std::cin >> type\
    \ >> u >> v;\r\n    --u; --v;\r\n    if (type == 1) {\r\n      bool is_adjacent\
    \ = false;\r\n      for (auto it = graph[u].begin(); it != graph[u].end();\r\n\
    \           it = std::next(it)) {\r\n        if (it->dst == v) {\r\n         \
    \ graph[u].erase(it);\r\n          is_adjacent = true;\r\n          break;\r\n\
    \        }\r\n      }\r\n      if (is_adjacent) {\r\n        for (auto it = graph[v].begin();\
    \ it != graph[v].end();\r\n             it = std::next(it)) {\r\n          if\
    \ (it->dst == u) {\r\n            graph[v].erase(it);\r\n            break;\r\n\
    \          }\r\n        }\r\n      } else {\r\n        graph[u].emplace_back(u,\
    \ v);\r\n        graph[v].emplace_back(v, u);\r\n      }\r\n    } else if (type\
    \ == 2) {\r\n      std::cout << (detect_path(graph, u, v).empty() ? \"No\\n\"\
    \ : \"Yes\\n\");\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/detect_path.hpp
  - graph/edge.hpp
  isVerificationFile: true
  path: test/graph/detect_path.test.cpp
  requiredBy: []
  timestamp: '2022-02-24 19:21:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/detect_path.test.cpp
layout: document
redirect_from:
- /verify/test/graph/detect_path.test.cpp
- /verify/test/graph/detect_path.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA"
---
