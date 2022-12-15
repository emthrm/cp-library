---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/graph/shortest_path/warshall-floyd.hpp
    title: "Warshall\u2013Floyd \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526
    document_title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013\
      Floyd \u6CD5"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/shortest_path/warshall-floyd.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013\
    Floyd \u6CD5\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0526\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/shortest_path/warshall-floyd.hpp\"\
    \n\nint main() {\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\n  while\
    \ (true) {\n    int n, k;\n    std::cin >> n >> k;\n    if (n == 0 && k == 0)\
    \ break;\n    std::vector<std::vector<long long>> graph(n,\n                 \
    \                             std::vector<long long>(n, LINF));\n    for (int\
    \ i = 0; i < n; ++i) {\n      graph[i][i] = 0;\n    }\n    emthrm::WarshallFloyd<long\
    \ long> warshall_floyd(graph, LINF);\n    while (k--) {\n      int type;\n   \
    \   std::cin >> type;\n      if (type == 0) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n        --a; --b;\n        std::cout << (warshall_floyd.dist[a][b]\
    \ == LINF ?\n                      -1 : warshall_floyd.dist[a][b])\n         \
    \         << '\\n';\n      } else if (type == 1) {\n        int c, d;\n      \
    \  long long e;\n        std::cin >> c >> d >> e;\n        --c; --d;\n       \
    \ warshall_floyd.add(c, d, e);\n        warshall_floyd.add(d, c, e);\n       \
    \ warshall_floyd.calc();\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/shortest_path/warshall-floyd.hpp
  isVerificationFile: true
  path: test/graph/shortest_path/warshall-floyd.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/shortest_path/warshall-floyd.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path/warshall-floyd.test.cpp
- /verify/test/graph/shortest_path/warshall-floyd.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall\u2013Floyd \u6CD5"
---
