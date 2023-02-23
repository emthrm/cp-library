---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/583
    document_title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\
      \u30B0\u30E9\u30D5\u7248"
    links:
    - https://yukicoder.me/problems/no/583
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/eulerian_trail_in_undirected_graph.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\
    \u30B0\u30E9\u30D5\u7248\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/583\"\
    \n\n#include <iostream>\n\n#include \"emthrm/graph/eulerian_trail_in_undirected_graph.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  emthrm::EulerianTrailInUndirectedGraph\
    \ eulerian_trail(n);\n  while (m--) {\n    int sa, sb;\n    std::cin >> sa >>\
    \ sb;\n    eulerian_trail.add_edge(sa, sb);\n  }\n  std::cout << (eulerian_trail.build()\
    \ ? \"YES\\n\" : \"NO\\n\");\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/eulerian_trail_in_undirected_graph.hpp
  isVerificationFile: true
  path: test/graph/eulerian_trail_in_undirected_graph.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/eulerian_trail_in_undirected_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/eulerian_trail_in_undirected_graph.test.cpp
- /verify/test/graph/eulerian_trail_in_undirected_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\
  \u30D5\u7248"
---
