---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/unicyclic_graph.hpp
    title: unicyclic graph / 1-tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1254
    document_title: "\u30B0\u30E9\u30D5/unicyclic graph"
    links:
    - https://yukicoder.me/problems/no/1254
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/unicyclic graph\n */\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1254\"\n\n#include <algorithm>\n#include <iostream>\n\
    #include <map>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\
    \n#include \"emthrm/graph/unicyclic_graph.hpp\"\n\nint main() {\n  int n;\n  std::cin\
    \ >> n;\n  std::map<std::pair<int, int>, int> edges;\n  emthrm::UnicyclicGraph<bool>\
    \ namori(n);\n  for (int i = 0; i < n; ++i) {\n    int a, b;\n    std::cin >>\
    \ a >> b;\n    --a; --b;\n    edges[std::minmax(a, b)] = i;\n    namori.add_edge(a,\
    \ b, false);\n  }\n  namori.build();\n  std::vector<bool> bridge(n, false);\n\
    \  for (const emthrm::Edge<bool>& e : namori.loop) {\n    bridge[edges[std::minmax(e.src,\
    \ e.dst)]] = true;\n  }\n  std::vector<int> p;\n  for (int i = 0; i < n; ++i)\
    \ {\n    if (bridge[i]) p.emplace_back(i);\n  }\n  const int k = p.size();\n \
    \ std::cout << k << '\\n';\n  for (int i = 0; i < k; ++i) {\n    std::cout <<\
    \ p[i] + 1 << \" \\n\"[i + 1 == k];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/unicyclic_graph.hpp
  isVerificationFile: true
  path: test/graph/unicyclic_graph.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/unicyclic_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/unicyclic_graph.test.cpp
- /verify/test/graph/unicyclic_graph.test.cpp.html
title: "\u30B0\u30E9\u30D5/unicyclic graph"
---
