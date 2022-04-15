---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\
      \u53CD\u5FA9\u6CD5\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1088
    document_title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
      \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\
      \u53CD\u5FA9\u6CD5\u7248 (minimum_cost_maximum_flow(s, t, flow))"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1088
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp: line 6: #pragma once\
    \ found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
    \u5FA9\u6CD5\u7248 (minimum_cost_maximum_flow(s, t, flow))\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1088\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n#include <tuple>\r\
    \n#include <vector>\r\n\r\n#include \"../../../../graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \r\n\r\nint main() {\r\n  struct Train { int x, y, c; };\r\n  while (true) {\r\
    \n    int n;\r\n    std::cin >> n;\r\n    if (n == 0) break;\r\n    int num =\
    \ 0;\r\n    std::vector<std::vector<Train>> trains(n - 1);\r\n    std::vector<std::vector<int>>\
    \ times(n - 1);\r\n    for (int i = 0; i < n - 1; ++i) {\r\n      int m;\r\n \
    \     std::cin >> m;\r\n      num += m;\r\n      while (m--) {\r\n        int\
    \ x, y, c;\r\n        std::cin >> x >> y >> c;\r\n        trains[i].emplace_back(Train{x,\
    \ y, c});\r\n        times[i].emplace_back(y);\r\n      }\r\n      std::sort(times[i].begin(),\
    \ times[i].end());\r\n      times[i].erase(std::unique(times[i].begin(), times[i].end()),\r\
    \n                     times[i].end());\r\n      num += times[i].size() * 2;\r\
    \n    }\r\n    MinimumCostSTFlow<int, long long> minimum_cost_flow(num + 2);\r\
    \n    const int s = num, t = num + 1;\r\n    for (int i = 0; i < trains.front().size();\
    \ ++i) {\r\n      minimum_cost_flow.add_edge(s, i, 1, 0);\r\n    }\r\n    int\
    \ w = 0;\r\n    for (int i = 0; i < n - 1; ++i) {\r\n      int m = trains[i].size();\r\
    \n      for (int j = 0; j < m; ++j) {\r\n        const int idx = std::distance(\r\
    \n            times[i].begin(),\r\n            std::lower_bound(times[i].begin(),\
    \ times[i].end(), trains[i][j].y));\r\n        minimum_cost_flow.add_edge(j +\
    \ w, idx + w + m, 1, trains[i][j].c);\r\n      }\r\n      w += m;\r\n      m =\
    \ times[i].size();\r\n      for (int j = 0; j < m; ++j) {\r\n        minimum_cost_flow.add_edge(j\
    \ + w, j + w + m, 1, 0);\r\n      }\r\n      w += m;\r\n      if (i + 1 < n -\
    \ 1) {\r\n        for (int j = 0; j < m; ++j) {\r\n          for (int k = 0; k\
    \ < trains[i + 1].size(); ++k) {\r\n            if (times[i][j] <= trains[i +\
    \ 1][k].x) {\r\n              minimum_cost_flow.add_edge(j + w, k + w + m, 1,\
    \ 0);\r\n            }\r\n          }\r\n        }\r\n        w += m;\r\n    \
    \  }\r\n    }\r\n    for (int i = num - times.back().size(); i < num; ++i) {\r\
    \n      minimum_cost_flow.add_edge(i, t, 1, 0);\r\n    }\r\n    int g;\r\n   \
    \ std::cin >> g;\r\n    int ans_class;\r\n    long long ans_fare;\r\n    std::tie(ans_class,\
    \ ans_fare) =\r\n        minimum_cost_flow.minimum_cost_maximum_flow(s, t, g);\r\
    \n    std::cout << ans_class << ' ' << ans_fare << '\\n';\r\n  }\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp
layout: document
redirect_from:
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp
- /verify/test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41/\u6700\
  \u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5\
  \u7248 (minimum_cost_maximum_flow(s, t, flow))"
---
