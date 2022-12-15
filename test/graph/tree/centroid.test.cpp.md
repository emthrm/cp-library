---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':x:'
    path: include/emthrm/graph/tree/centroid.hpp
    title: "\u91CD\u5FC3 (centroid)"
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc087/tasks/arc087_f
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3"
    links:
    - https://atcoder.jp/contests/arc087/tasks/arc087_d
    - https://atcoder.jp/contests/arc087/tasks/arc087_f
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc087/tasks/arc087_f\"\n// #define PROBLEM \"\
    https://atcoder.jp/contests/arc087/tasks/arc087_d\"\n\n#include <functional>\n\
    #include <iostream>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\
    #include \"emthrm/graph/tree/centroid.hpp\"\n#include \"emthrm/math/modint.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<0>;\n  ModInt::set_mod(1000000007);\n\
    \  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<bool>>> graph(n);\n\
    \  for (int i = 0; i < n - 1; ++i) {\n    int x, y;\n    std::cin >> x >> y;\n\
    \    --x; --y;\n    graph[x].emplace_back(x, y);\n    graph[y].emplace_back(y,\
    \ x);\n  }\n  const std::vector<int> centroids = emthrm::centroid(graph);\n  if\
    \ (centroids.size() == 2) {\n    std::cout << ModInt::fact(n / 2) * ModInt::fact(n\
    \ / 2) << '\\n';\n  } else {\n    std::vector<int> subtree(n, 1);\n    const std::function<void(int,\
    \ int)> dfs =\n        [&graph, &subtree, &dfs](const int par, const int ver)\
    \ -> void {\n          for (const emthrm::Edge<bool>& e : graph[ver]) {\n    \
    \        if (e.dst != par) {\n              dfs(ver, e.dst);\n              subtree[ver]\
    \ += subtree[e.dst];\n            }\n          }\n        };\n    dfs(-1, centroids.front());\n\
    \    std::vector<int> nums;\n    for (const emthrm::Edge<bool>& e : graph[centroids.front()])\
    \ {\n      nums.emplace_back(subtree[e.dst]);\n    }\n    const int m = nums.size();\n\
    \    std::vector<std::vector<ModInt>> dp(m + 1, std::vector<ModInt>(n + 1, 0));\n\
    \    dp[0][0] = 1;\n    for (int i = 0; i < m; ++i) {\n      for (int j = 0; j\
    \ <= n; ++j) {\n        for (int k = 0; k <= nums[i] && j + k <= n; ++k) {\n \
    \         dp[i + 1][j + k] += dp[i][j] * ModInt::nCk(nums[i], k)\n           \
    \                   * ModInt::nCk(nums[i], k) * ModInt::fact(k);\n        }\n\
    \      }\n    }\n    ModInt ans = 0;\n    for (int j = 0; j <= n; ++j) {\n   \
    \   ans += (j & 1 ? -dp[m][j] : dp[m][j]) * ModInt::fact(n - j);\n    }\n    std::cout\
    \ << ans << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/centroid.hpp
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/graph/tree/centroid.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/tree/centroid.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/centroid.test.cpp
- /verify/test/graph/tree/centroid.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3"
---
