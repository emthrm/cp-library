---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
    \u5FA9\u6CD5\u7248 (minimum_cost_maximum_flow(s, t, flow))\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1088\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <iterator>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\nint main() {\n  struct Train { int x, y, c; };\n  while (true) {\n    int\
    \ n;\n    std::cin >> n;\n    if (n == 0) break;\n    int num = 0;\n    std::vector<std::vector<Train>>\
    \ trains(n - 1);\n    std::vector<std::vector<int>> times(n - 1);\n    for (int\
    \ i = 0; i < n - 1; ++i) {\n      int m;\n      std::cin >> m;\n      num += m;\n\
    \      while (m--) {\n        int x, y, c;\n        std::cin >> x >> y >> c;\n\
    \        trains[i].emplace_back(Train{x, y, c});\n        times[i].emplace_back(y);\n\
    \      }\n      std::sort(times[i].begin(), times[i].end());\n      times[i].erase(std::unique(times[i].begin(),\
    \ times[i].end()),\n                     times[i].end());\n      num += times[i].size()\
    \ * 2;\n    }\n    emthrm::MinimumCostSTFlow<int, long long> minimum_cost_flow(num\
    \ + 2);\n    const int s = num, t = num + 1;\n    for (int i = 0; std::cmp_less(i,\
    \ trains.front().size()); ++i) {\n      minimum_cost_flow.add_edge(s, i, 1, 0);\n\
    \    }\n    int w = 0;\n    for (int i = 0; i < n - 1; ++i) {\n      int m = trains[i].size();\n\
    \      for (int j = 0; j < m; ++j) {\n        const int idx = std::distance(\n\
    \            times[i].begin(),\n            std::lower_bound(times[i].begin(),\
    \ times[i].end(), trains[i][j].y));\n        minimum_cost_flow.add_edge(j + w,\
    \ idx + w + m, 1, trains[i][j].c);\n      }\n      w += m;\n      m = times[i].size();\n\
    \      for (int j = 0; j < m; ++j) {\n        minimum_cost_flow.add_edge(j + w,\
    \ j + w + m, 1, 0);\n      }\n      w += m;\n      if (i + 1 < n - 1) {\n    \
    \    for (int j = 0; j < m; ++j) {\n          for (int k = 0; std::cmp_less(k,\
    \ trains[i + 1].size()); ++k) {\n            if (times[i][j] <= trains[i + 1][k].x)\
    \ {\n              minimum_cost_flow.add_edge(j + w, k + w + m, 1, 0);\n     \
    \       }\n          }\n        }\n        w += m;\n      }\n    }\n    for (int\
    \ i = num - times.back().size(); i < num; ++i) {\n      minimum_cost_flow.add_edge(i,\
    \ t, 1, 0);\n    }\n    int g;\n    std::cin >> g;\n    const auto [ans_class,\
    \ ans_fare] =\n        minimum_cost_flow.minimum_cost_maximum_flow(s, t, g);\n\
    \    std::cout << ans_class << ' ' << ans_fare << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
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
