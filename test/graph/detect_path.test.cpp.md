---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/graph/detect_path.hpp
    title: "\u9053\u306E\u691C\u51FA"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA"
    links:
    - https://atcoder.jp/contests/past202112-open/tasks/past202112_g
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/detect_path.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA\n */\n#define IGNORE\n\
    #define PROBLEM \"https://atcoder.jp/contests/past202112-open/tasks/past202112_g\"\
    \n\n#include <iostream>\n#include <iterator>\n#include <vector>\n\n#include \"\
    emthrm/graph/detect_path.hpp\"\n#include \"emthrm/graph/edge.hpp\"\n\nint main()\
    \ {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  while (q--) {\n    int type, u, v;\n    std::cin >> type >> u >>\
    \ v;\n    --u; --v;\n    if (type == 1) {\n      bool is_adjacent = false;\n \
    \     for (auto it = graph[u].begin(); it != graph[u].end();\n           it =\
    \ std::next(it)) {\n        if (it->dst == v) {\n          graph[u].erase(it);\n\
    \          is_adjacent = true;\n          break;\n        }\n      }\n      if\
    \ (is_adjacent) {\n        for (auto it = graph[v].begin(); it != graph[v].end();\n\
    \             it = std::next(it)) {\n          if (it->dst == u) {\n         \
    \   graph[v].erase(it);\n            break;\n          }\n        }\n      } else\
    \ {\n        graph[u].emplace_back(u, v);\n        graph[v].emplace_back(v, u);\n\
    \      }\n    } else if (type == 2) {\n      std::cout << (emthrm::detect_path(graph,\
    \ u, v).empty() ?\n                    \"No\\n\" : \"Yes\\n\");\n    }\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/detect_path.hpp
  - include/emthrm/graph/edge.hpp
  isVerificationFile: true
  path: test/graph/detect_path.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/detect_path.test.cpp
layout: document
redirect_from:
- /verify/test/graph/detect_path.test.cpp
- /verify/test/graph/detect_path.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u9053\u306E\u691C\u51FA"
---
