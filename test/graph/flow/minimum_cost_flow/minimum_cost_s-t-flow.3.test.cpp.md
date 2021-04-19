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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp: line 6: #pragma once\
    \ found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\
    \u6D41/\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
    \u5FA9\u6CD5\u7248 (minimum_cost_maximum_flow(s, t, flow))\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1088\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n#include <tuple>\r\
    \n#include <vector>\r\n#include \"../../../../graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \r\n\r\nint main() {\r\n  struct Train {\r\n    int x, y, c;\r\n  };\r\n\r\n \
    \ while (true) {\r\n    int n;\r\n    std::cin >> n;\r\n    if (n == 0) break;\r\
    \n    int ver = 0;\r\n    std::vector<std::vector<Train>> m(n - 1);\r\n    std::vector<std::vector<int>>\
    \ arrive(n - 1);\r\n    for (int i = 0; i < n - 1; ++i) {\r\n      int mi;\r\n\
    \      std::cin >> mi;\r\n      while (mi--) {\r\n        int x, y, c;\r\n   \
    \     std::cin >> x >> y >> c;\r\n        m[i].emplace_back(Train{x, y, c});\r\
    \n        arrive[i].emplace_back(y);\r\n        ++ver;\r\n      }\r\n      std::sort(arrive[i].begin(),\
    \ arrive[i].end());\r\n      arrive[i].erase(std::unique(arrive[i].begin(), arrive[i].end()),\
    \ arrive[i].end());\r\n      ver += arrive[i].size() * 2;\r\n    }\r\n    MinimumCostSTFlow<int,\
    \ long long> mcf(ver + 2);\r\n    const int s = ver, t = ver + 1;\r\n    for (int\
    \ i = 0; i < m.front().size(); ++i) mcf.add_edge(s, i, 1, 0);\r\n    int cur =\
    \ 0;\r\n    for (int i = 0; i < n - 1; ++i) {\r\n      int sz = m[i].size();\r\
    \n      for (int j = 0; j < sz; ++j) {\r\n        int idx = std::distance(arrive[i].begin(),\
    \ std::lower_bound(arrive[i].begin(), arrive[i].end(), m[i][j].y));\r\n      \
    \  mcf.add_edge(cur + j, cur + sz + idx, 1, m[i][j].c);\r\n      }\r\n      cur\
    \ += sz;\r\n      sz = arrive[i].size();\r\n      for (int j = 0; j < sz; ++j)\
    \ mcf.add_edge(cur + j, cur + sz + j, 1, 0);\r\n      cur += sz;\r\n      if (i\
    \ + 1 < n - 1) {\r\n        for (int j = 0; j < sz; ++j) for (int k = 0; k < m[i\
    \ + 1].size(); ++k) {\r\n          if (arrive[i][j] <= m[i + 1][k].x) mcf.add_edge(cur\
    \ + j, cur + sz + k, 1, 0);\r\n        }\r\n        cur += sz;\r\n      }\r\n\
    \    }\r\n    for (int i = ver - arrive.back().size(); i < ver; ++i) mcf.add_edge(i,\
    \ ver + 1, 1, 0);\r\n    int g;\r\n    std::cin >> g;\r\n    int ans_class;\r\n\
    \    long long ans_fare;\r\n    std::tie(ans_class, ans_fare) = mcf.minimum_cost_maximum_flow(ver,\
    \ ver + 1, g);\r\n    std::cout << ans_class << ' ' << ans_fare << '\\n';\r\n\
    \  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  isVerificationFile: true
  path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp
  requiredBy: []
  timestamp: '2021-04-20 01:59:26+09:00'
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
