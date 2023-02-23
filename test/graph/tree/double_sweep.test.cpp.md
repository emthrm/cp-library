---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/double_sweep.hpp
    title: double sweep
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    document_title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6728/double sweep\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/double_sweep.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b, c;\n \
    \   std::cin >> a >> b >> c;\n    graph[a].emplace_back(a, b, c);\n    graph[b].emplace_back(b,\
    \ a, c);\n  }\n  const auto [x, u] = emthrm::double_sweep(graph);\n  const int\
    \ y = u.size();\n  std::cout << x << ' ' << y << '\\n';\n  for (int i = 0; i <\
    \ y; ++i) {\n    std::cout << u[i] << \" \\n\"[i + 1 == y];\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/double_sweep.hpp
  isVerificationFile: true
  path: test/graph/tree/double_sweep.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/double_sweep.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/double_sweep.test.cpp
- /verify/test/graph/tree/double_sweep.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
---
