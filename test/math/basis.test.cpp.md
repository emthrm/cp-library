---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/basis.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u57FA\u5E95\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2416\"\
    \n\n#include <bitset>\n#include <functional>\n#include <iostream>\n#include <vector>\n\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/math/basis.hpp\"\n\nint\
    \ main() {\n  constexpr int D = 60;\n  int n, m, q;\n  std::cin >> n >> m >> q;\n\
    \  std::vector<std::vector<emthrm::Edge<long long>>> graph(n);\n  while (m--)\
    \ {\n    int f, t;\n    long long p;\n    std::cin >> f >> t >> p;\n    graph[f].emplace_back(f,\
    \ t, p);\n    graph[t].emplace_back(t, f, p);\n  }\n  std::vector<long long> x(n,\
    \ -1);\n  x[0] = 0;\n  emthrm::Basis<D> basis;\n  const std::function<void(int,\
    \ int)> dfs = [&graph, &x, &basis, &dfs](\n      const int par, const int ver)\
    \ {\n    for (const emthrm::Edge<long long>& e : graph[ver]) {\n      if (e.dst\
    \ != par) {\n        if (x[e.dst] == -1) {\n          x[e.dst] = x[ver] ^ e.cost;\n\
    \          dfs(ver, e.dst);\n        } else {\n          basis.add(x[ver] ^ x[e.dst]\
    \ ^ e.cost);\n        }\n      }\n    }\n  };\n  dfs(-1, 0);\n  while (q--) {\n\
    \    int a, b;\n    std::cin >> a >> b;\n    std::bitset<D> ans(x[a] ^ x[b]);\n\
    \    for (int i = 0; i < basis.rank(); ++i) {\n      if (!ans[basis.msb[i]]) ans\
    \ ^= basis.v[i];\n    }\n    std::cout << ans.to_ulong() << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/math/basis.hpp
  isVerificationFile: true
  path: test/math/basis.test.cpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/basis.test.cpp
layout: document
redirect_from:
- /verify/test/math/basis.test.cpp
- /verify/test/math/basis.test.cpp.html
title: "\u6570\u5B66/\u57FA\u5E95"
---
