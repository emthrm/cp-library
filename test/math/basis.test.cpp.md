---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: math/basis.hpp
    title: "\u57FA\u5E95 (basis)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416
    document_title: "\u6570\u5B66/\u57FA\u5E95"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u57FA\u5E95\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416\"\
    \r\n\r\n#include <bitset>\r\n#include <functional>\r\n#include <iostream>\r\n\
    #include <vector>\r\n#include \"../../graph/edge.hpp\"\r\n#include \"../../math/basis.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr int D = 60;\r\n  int n, m, q;\r\n  std::cin\
    \ >> n >> m >> q;\r\n  std::vector<std::vector<Edge<long long>>> graph(n);\r\n\
    \  while (m--) {\r\n    int f, t;\r\n    long long p;\r\n    std::cin >> f >>\
    \ t >> p;\r\n    graph[f].emplace_back(f, t, p);\r\n    graph[t].emplace_back(t,\
    \ f, p);\r\n  }\r\n  std::vector<long long> x(n, -1);\r\n  x[0] = 0;\r\n  Basis<D>\
    \ basis;\r\n  std::function<void(int, int)> dfs = [&graph, &x, &basis, &dfs](int\
    \ par, int ver) {\r\n    for (const Edge<long long> &e : graph[ver]) {\r\n   \
    \   if (e.dst != par) {\r\n        if (x[e.dst] == -1) {\r\n          x[e.dst]\
    \ = x[ver] ^ e.cost;\r\n          dfs(ver, e.dst);\r\n        } else {\r\n   \
    \       basis.add(x[ver] ^ x[e.dst] ^ e.cost);\r\n        }\r\n      }\r\n   \
    \ }\r\n  };\r\n  dfs(-1, 0);\r\n  while (q--) {\r\n    int a, b;\r\n    std::cin\
    \ >> a >> b;\r\n    std::bitset<D> ans(x[a] ^ x[b]);\r\n    for (int i = 0; i\
    \ < basis.v.size(); ++i) {\r\n      if (!ans[basis.msb[i]]) ans ^= basis.v[i];\r\
    \n    }\r\n    std::cout << ans.to_ulong() << '\\n';\r\n  }\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - graph/edge.hpp
  - math/basis.hpp
  isVerificationFile: true
  path: test/math/basis.test.cpp
  requiredBy: []
  timestamp: '2021-02-11 02:56:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/basis.test.cpp
layout: document
redirect_from:
- /verify/test/math/basis.test.cpp
- /verify/test/math/basis.test.cpp.html
title: "\u6570\u5B66/\u57FA\u5E95"
---
