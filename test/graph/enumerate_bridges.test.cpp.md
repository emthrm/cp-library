---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/enumerate_bridges.hpp
    title: "\u6A4B\u306E\u691C\u51FA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    document_title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u5217\u6319"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6A4B\u306E\u5217\u6319\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/enumerate_bridges.hpp\"\n\nint main() {\n  int v, e;\n\
    \  std::cin >> v >> e;\n  std::vector<std::vector<emthrm::Edge<bool>>> graph(v);\n\
    \  while (e--) {\n    int s, t;\n    std::cin >> s >> t;\n    graph[s].emplace_back(s,\
    \ t);\n    graph[t].emplace_back(t, s);\n  }\n  std::vector<emthrm::Edge<bool>>\
    \ bridges = emthrm::enumerate_bridges(graph);\n  std::sort(bridges.begin(), bridges.end(),\n\
    \            [](const emthrm::Edge<bool>& a,\n               const emthrm::Edge<bool>&\
    \ b) -> bool {\n              return a.src != b.src ? a.src < b.src : a.dst <\
    \ b.dst;\n            });\n  for (const emthrm::Edge<bool>& bridge : bridges)\
    \ {\n    std::cout << bridge.src << ' ' << bridge.dst << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/enumerate_bridges.hpp
  isVerificationFile: true
  path: test/graph/enumerate_bridges.test.cpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/enumerate_bridges.test.cpp
layout: document
redirect_from:
- /verify/test/graph/enumerate_bridges.test.cpp
- /verify/test/graph/enumerate_bridges.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u5217\u6319"
---
