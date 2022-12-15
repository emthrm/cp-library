---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/detect_directed_cycle.hpp
    title: "\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    document_title: "\u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/detect_directed_cycle.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA\
    \n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/detect_directed_cycle.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n\nint main() {\n  int n, m;\n  std::cin\
    \ >> n >> m;\n  std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n  for (int\
    \ i = 0; i < m; ++i) {\n    int u, v;\n    std::cin >> u >> v;\n    graph[u].emplace_back(u,\
    \ v, i);\n  }\n  std::vector<int> e;\n  for (const emthrm::Edge<int>& edge : emthrm::detect_directed_cycle(graph))\
    \ {\n    e.emplace_back(edge.cost);\n  }\n  if (e.empty()) {\n    std::cout <<\
    \ \"-1\\n\";\n  } else {\n    std::cout << e.size() << '\\n';\n    for (const\
    \ int ver : e) std::cout << ver << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/detect_directed_cycle.hpp
  - include/emthrm/graph/edge.hpp
  isVerificationFile: true
  path: test/graph/detect_directed_cycle.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/detect_directed_cycle.test.cpp
layout: document
redirect_from:
- /verify/test/graph/detect_directed_cycle.test.cpp
- /verify/test/graph/detect_directed_cycle.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6709\u5411\u9589\u8DEF\u306E\u691C\u51FA"
---
