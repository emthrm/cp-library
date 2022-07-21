---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tree/rerooting_dp.hpp
    title: "\u5168\u65B9\u4F4D\u6728 DP"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP\n */\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#include <algorithm>\n#include <functional>\n#include <iostream>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"../../../graph/edge.hpp\"\n#include\
    \ \"../../../graph/tree/rerooting_dp.hpp\"\n\nint main() {\n  int n;\n  std::cin\
    \ >> n;\n  std::vector<std::vector<Edge<int>>> graph(n);\n  for (int i = 0; i\
    \ < n - 1; ++i) {\n    int s, t, w;\n    std::cin >> s >> t >> w;\n    graph[s].emplace_back(s,\
    \ t, w);\n    graph[t].emplace_back(t, s, w);\n  }\n  const std::vector<std::pair<int,\
    \ int>> ans = rerooting_dp(\n      graph, std::vector<std::pair<int, int>>(n,\
    \ {0, 0}),\n      [](const std::pair<int, int>& x, const std::pair<int, int>&\
    \ y)\n          -> std::pair<int, int> {\n        int tmp[]{x.first, x.second,\
    \ y.first, y.second};\n        std::sort(tmp, tmp + 4, std::greater<int>());\n\
    \        return {tmp[0], tmp[1]};\n      },\n      [](const std::pair<int, int>&\
    \ x, const Edge<int>& e)\n          -> std::pair<int, int> { return {x.first +\
    \ e.cost, 0}; },\n      [](const std::pair<int, int>& x, const int ver) -> std::pair<int,\
    \ int> {\n        return x;\n      });\n  int diameter = 0;\n  for (int i = 0;\
    \ i < n; ++i) {\n    diameter = std::max(diameter, ans[i].first + ans[i].second);\n\
    \  }\n  std::cout << diameter << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/tree/rerooting_dp.hpp
  isVerificationFile: true
  path: test/graph/tree/rerooting_dp.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/rerooting_dp.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/rerooting_dp.test.cpp
- /verify/test/graph/tree/rerooting_dp.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP"
---
