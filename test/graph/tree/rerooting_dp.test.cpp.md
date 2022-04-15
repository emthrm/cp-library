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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP\r\n\
    \ */\r\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \r\n\r\n#include <algorithm>\r\n#include <functional>\r\n#include <iostream>\r\
    \n#include <utility>\r\n#include <vector>\r\n\r\n#include \"../../../graph/edge.hpp\"\
    \r\n#include \"../../../graph/tree/rerooting_dp.hpp\"\r\n\r\nint main() {\r\n\
    \  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<Edge<int>>> graph(n);\r\
    \n  for (int i = 0; i < n - 1; ++i) {\r\n    int s, t, w;\r\n    std::cin >> s\
    \ >> t >> w;\r\n    graph[s].emplace_back(s, t, w);\r\n    graph[t].emplace_back(t,\
    \ s, w);\r\n  }\r\n  const std::vector<std::pair<int, int>> ans = rerooting_dp(\r\
    \n      graph, std::vector<std::pair<int, int>>(n, {0, 0}),\r\n      [](const\
    \ std::pair<int, int>& x, const std::pair<int, int>& y)\r\n          -> std::pair<int,\
    \ int> {\r\n        int tmp[]{x.first, x.second, y.first, y.second};\r\n     \
    \   std::sort(tmp, tmp + 4, std::greater<int>());\r\n        return {tmp[0], tmp[1]};\r\
    \n      },\r\n      [](const std::pair<int, int>& x, const Edge<int>& e)\r\n \
    \         -> std::pair<int, int> { return {x.first + e.cost, 0}; },\r\n      [](const\
    \ std::pair<int, int>& x, const int ver) -> std::pair<int, int> {\r\n        return\
    \ x;\r\n      });\r\n  int diameter = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n\
    \    diameter = std::max(diameter, ans[i].first + ans[i].second);\r\n  }\r\n \
    \ std::cout << diameter << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/tree/rerooting_dp.hpp
  isVerificationFile: true
  path: test/graph/tree/rerooting_dp.test.cpp
  requiredBy: []
  timestamp: '2022-03-10 23:14:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/rerooting_dp.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/rerooting_dp.test.cpp
- /verify/test/graph/tree/rerooting_dp.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP"
---
