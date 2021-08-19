---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: graph/tree/centroid.hpp
    title: "\u91CD\u5FC3 (centroid)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3"
    links:
    - https://atcoder.jp/contests/arc087/tasks/arc087_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\r\n */\r\n#define\
    \ IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc087/tasks/arc087_d\"\
    \r\n\r\n#include <functional>\r\n#include <iostream>\r\n#include <vector>\r\n\
    #include \"../../../math/modint.hpp\"\r\n#include \"../../../graph/edge.hpp\"\r\
    \n#include \"../../../graph/tree/centroid.hpp\"\r\n\r\nint main() {\r\n  using\
    \ ModInt = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\n  int n;\r\n  std::cin\
    \ >> n;\r\n  ModInt::init(n);\r\n  std::vector<std::vector<Edge<bool>>> graph(n);\r\
    \n  for (int i = 0; i < n - 1; ++i) {\r\n    int x, y;\r\n    std::cin >> x >>\
    \ y;\r\n    --x; --y;\r\n    graph[x].emplace_back(x, y);\r\n    graph[y].emplace_back(y,\
    \ x);\r\n  }\r\n  std::vector<int> centroids = centroid(graph);\r\n  ModInt ans\
    \ = 0;\r\n  if (centroids.size() == 2) {\r\n    ans += ModInt::fact(n / 2) * ModInt::fact(n\
    \ / 2);\r\n  } else {\r\n    int cen = centroids[0];\r\n    std::vector<int> subtree(n,\
    \ 1);\r\n    std::function<void(int, int)> dfs = [&graph, &subtree, &dfs](int\
    \ par, int ver) -> void {\r\n      for (const Edge<bool> &e : graph[ver]) {\r\n\
    \        if (e.dst != par) {\r\n          dfs(ver, e.dst);\r\n          subtree[ver]\
    \ += subtree[e.dst];\r\n        }\r\n      }\r\n    };\r\n    dfs(-1, cen);\r\n\
    \    std::vector<int> cnt;\r\n    for (const Edge<bool> &e : graph[cen]) cnt.emplace_back(subtree[e.dst]);\r\
    \n    int m = cnt.size();\r\n    std::vector<std::vector<ModInt>> dp(m + 1, std::vector<ModInt>(n\
    \ + 1, 0));\r\n    dp[0][0] = 1;\r\n    for (int i = 0; i < m; ++i) for (int j\
    \ = 0; j <= n; ++j) {\r\n      for (int k = 0; k <= cnt[i] && j + k <= n; ++k)\
    \ {\r\n        dp[i + 1][j + k] += dp[i][j] * ModInt::nCk(cnt[i], k) * ModInt::nCk(cnt[i],\
    \ k) * ModInt::fact(k);\r\n      }\r\n    }\r\n    for (int j = 0; j <= n; ++j)\
    \ ans += dp[m][j] * (j & 1 ? -1 : 1) * ModInt::fact(n - j);\r\n  }\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - graph/edge.hpp
  - graph/tree/centroid.hpp
  isVerificationFile: true
  path: test/graph/tree/centroid.test.cpp
  requiredBy: []
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/tree/centroid.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/centroid.test.cpp
- /verify/test/graph/tree/centroid.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3"
---
